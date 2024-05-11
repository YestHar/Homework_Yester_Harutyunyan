#include <unordered_set>

bool has_cycle(Node* head) {
    std::unordered_set<Node*> visited; 
    
    while (head != nullptr) {
        if (visited.find(head) != visited.end()) {
            return true; 
        }
        visited.insert(head); 
        head = head->next; 
    }
    
    return false;
}