bool MyString::isSSO() const {
    return ssoBuffer[SSO_THRESHOLD] == 0;
}

void MyString::setSSOMode(bool sso) {
    ssoBuffer[SSO_THRESHOLD] = sso ? 0 : 1;
}

void MyString::copyOnWrite() {
    if (!isSSO() && refCount->load() > 1) {
        refCount->fetch_sub(1);

        char* newStr = new char[length + 1];
        std::strcpy(newStr, str);
        
        refCount = new std::atomic<size_t>(1);
        
        str = newStr;
        capacity = length;
    }
}

MyString::MyString(const char* s) {
    size_t len = std::strlen(s);
    if (len <= SSO_THRESHOLD) {
        std::strcpy(ssoBuffer, s);
        setSSOMode(true);
    } else {
        length = len;
        capacity = len;
        str = new char[length + 1];
        std::strcpy(str, s);
        refCount = new std::atomic<size_t>(1);
        setSSOMode(false);
    }
}

MyString::MyString(const MyString& other) {
    if (other.isSSO()) {
        std::strcpy(ssoBuffer, other.ssoBuffer);
        setSSOMode(true);
    } else {
        str = other.str;
        length = other.length;
        capacity = other.capacity;
        refCount = other.refCount;
        refCount->fetch_add(1);
        setSSOMode(false);
    }
}

MyString::MyString(MyString&& other) noexcept
    : str(other.isSSO() ? nullptr : std::exchange(other.str, nullptr))
    , length(other.isSSO() ? 0 : other.length)
    , capacity(other.isSSO() ? 0 : other.capacity)
    , refCount(other.isSSO() ? nullptr : std::exchange(other.refCount, nullptr)) {
    
    if (other.isSSO()) {
        std::strcpy(ssoBuffer, other.ssoBuffer);
        setSSOMode(true);
    } else {
        setSSOMode(false);
    }
}

MyString::~MyString() {
    if (!isSSO() && refCount && refCount->fetch_sub(1) == 1) {
        delete[] str;
        delete refCount;
    }
}

MyString& MyString::operator=(const MyString& other) {
    if (this == &other) {
        return *this;
    }

    if (!isSSO() && refCount && refCount->fetch_sub(1) == 1) {
        delete[] str;
        delete refCount;
    }

    if (other.isSSO()) {
        std::strcpy(ssoBuffer, other.ssoBuffer);
        setSSOMode(true);
    } else {
        str = other.str;
        length = other.length;
        capacity = other.capacity;
        refCount = other.refCount;
        refCount->fetch_add(1);
        setSSOMode(false);
    }

    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    if (!isSSO() && refCount && refCount->fetch_sub(1) == 1) {
        delete[] str;
        delete refCount;
    }

    if (other.isSSO()) {
        std::strcpy(ssoBuffer, other.ssoBuffer);
        setSSOMode(true);
    } else {
        str = std::exchange(other.str, nullptr);
        length = other.length;
        capacity = other.capacity;
        refCount = std::exchange(other.refCount, nullptr);
        setSSOMode(false);
    }

    return *this;
}

size_t MyString::getLength() const {
    return isSSO() ? std::strlen(ssoBuffer) : length;
}

void MyString::append(char c) {
    copyOnWrite();

    if (isSSO()) {
        size_t len = std::strlen(ssoBuffer);
        if (len < SSO_THRESHOLD) {
            ssoBuffer[len] = c;
            ssoBuffer[len + 1] = '\0';
        } else {
            length = SSO_THRESHOLD + 1;
            capacity = length * 2;
            str = new char[capacity + 1];
            std::strcpy(str, ssoBuffer);
            str[SSO_THRESHOLD] = c;
            str[SSO_THRESHOLD + 1] = '\0';
            refCount = new std::atomic<size_t>(1);
            setSSOMode(false);
        }
    } else {
        if (length + 1 > capacity) {
            capacity = (length + 1) * 2;
            char* newStr = new char[capacity + 1];
            std::strcpy(newStr, str);
            delete[] str;
            str = newStr;
        }
        str[length] = c;
        str[length + 1] = '\0';
        length++;
    }
}



