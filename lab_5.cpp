#include<iostream>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* prev;
    ListNode* next;
    
    ListNode() {
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList{
    public:
    ListNode* first;
    ListNode* last;
    ListNode* PLoc_;
    ListNode* Loc_;
    
    DoublyLinkedList(){
        first = NULL;
        last = NULL;
        PLoc_ = NULL;
        Loc_ = NULL;
    }
    
    bool IsEmpty(){ return first==NULL; }
    
    void PrintList(){
        ListNode* temp = first;
        while (temp != NULL){ 
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    void InsertAtFront(int value) {
        ListNode* newnode = new ListNode();
        newnode->data = value;
        
        if (IsEmpty()){
            first = newnode;
            last = newnode;
        }
        else {
            newnode->next = first;
            first->prev = newnode;
            first = newnode;
        }
    }
    
    void InsertAtEnd(int value){
        ListNode* newnode = new ListNode();
        newnode->data = value;
        
        if (IsEmpty()){
            first = newnode;
            last = newnode;
        }
        else {
            last->next = newnode;
            newnode->prev = last;
            last = newnode;
        }
    }
    
    void Search(int value){
        Loc_ = first;
        PLoc_ = NULL;
        while(Loc_ != NULL && Loc_->data < value){
            PLoc_ = Loc_;
            Loc_ = Loc_->next;
        }
    }
    
    void InsertSorted(int value) {
        Search(value);
        
        if (Loc_ != NULL && Loc_->data == value) {
            cout << "Value " << value << " already exists in the list. No insertion performed." << endl;
            return;
        }
        
        if (PLoc_ == NULL) {
            InsertAtFront(value);
        }
        else if (PLoc_ == last) {
            InsertAtEnd(value);
        }
        else {
            ListNode* newnode = new ListNode();
            newnode->data = value;
            
            newnode->next = PLoc_->next;
            newnode->prev = PLoc_;
            PLoc_->next->prev = newnode;
            PLoc_->next = newnode;
        }
    }
    
    
    int DeleteFront() {
        if (IsEmpty()) {
            cout << "List is empty. Cannot delete front." << endl;
            return -1;
        }
        
        int value = first->data;
        ListNode* temp = first;
        
        if (first == last) {
            first = NULL;
            last = NULL;
        } else {
            first = first->next;
            first->prev = NULL;
        }
        
        delete temp;
        return value;
    }
    
    int DeleteLast() {
        if (IsEmpty()) {
            cout << "List is empty. Cannot delete last." << endl;
            return -1;
        }
        
        int value = last->data;
        ListNode* temp = last;
        
        if (first == last) {
            first = NULL;
            last = NULL;
        } else {
            last = last->prev;
            last->next = NULL;
        }
        
        delete temp;
        return value;
    }
    
    bool Delete(int value) {
        Search(value);
        
        if (Loc_ == NULL || Loc_->data != value) {
            cout << "Value " << value << " not found in the list." << endl;
            return false;
        }
        
        if (Loc_ == first) {
            DeleteFront();
            return true;
        }
        
        if (Loc_ == last) {
            DeleteLast();
            return true;
        }
        
        PLoc_->next = Loc_->next;
        Loc_->next->prev = PLoc_;
        
        delete Loc_;
        return true;
    }
    
    void DestroyList() {
        while (!IsEmpty()) {
            DeleteFront();
        }
        cout << "List destroyed." << endl;
    }
    void ReverseList() {
        if (IsEmpty() || first == last) {
            return;
        }
        ListNode* current = first;
        ListNode* temp = NULL;
        while (current != NULL) {
            temp = current->next;
            
            current->next = current->prev;
            current->prev = temp;
            
            current = temp;
        }
        
        temp = first;
        first = last;
        last = temp;
        
        cout << "List has been reversed." << endl;
    }
    void SwapNodes(int value1, int value2) {
        if (value1 == value2) {
            cout << "Both values are the same, no swap needed." << endl;
            return;
        }
        
        ListNode* node1 = NULL;
        ListNode* node2 = NULL;
        ListNode* current = first;
        
        while (current != NULL && (node1 == NULL || node2 == NULL)) {
            if (current->data == value1) {
                node1 = current;
            } else if (current->data == value2) {
                node2 = current;
            }
            current = current->next;
        }
        
        if (node1 == NULL || node2 == NULL) {
            cout << "One or both values not found in the list. Swap failed." << endl;
            return;
        }
        
        if (node2->prev == node1) {
            ListNode* temp = node1;
            node1 = node2;
            node2 = temp;
        }
        
        if (first == node1) {
            first = node2;
        } else if (first == node2) {
            first = node1;
        }
        
        if (last == node1) {
            last = node2;
        } else if (last == node2) {
            last = node1;
        }
        
        ListNode* node1Prev = node1->prev;
        ListNode* node1Next = node1->next;
        ListNode* node2Prev = node2->prev;
        ListNode* node2Next = node2->next;
        
        if (node1->next == node2) {
            node1->next = node2Next;
            node1->prev = node2;
            
            node2->next = node1;
            node2->prev = node1Prev;
            
            if (node2Next != NULL) {
                node2Next->prev = node1;
            }
            
            if (node1Prev != NULL) {
                node1Prev->next = node2;
            }
        } else {
            node1->next = node2Next;
            node1->prev = node2Prev;
            
            node2->next = node1Next;
            node2->prev = node1Prev;
            
            if (node1Prev != NULL) {
                node1Prev->next = node2;
            }
            
            if (node1Next != NULL) {
                node1Next->prev = node2;
            }
            
            if (node2Prev != NULL) {
                node2Prev->next = node1;
            }
            
            if (node2Next != NULL) {
                node2Next->prev = node1;
            }
        }
    }
};

int main() {
    DoublyLinkedList dll;
    cout << "creating a list: " << endl;
    dll.InsertAtFront(10);
    dll.InsertAtFront(5);
    dll.InsertAtEnd(20);
    dll.InsertAtFront(0);
    dll.PrintList();
    cout << "deleting front: " << endl;
    dll.DeleteFront();
    dll.PrintList();
    cout << "deleting last: " << endl;
    dll.DeleteLast();
    dll.PrintList();
    cout << "deleting 10: " << endl;
    dll.Delete(10);
    dll.PrintList();
    cout << "deleting entire list: " << endl;
    dll.DestroyList();
    dll.PrintList();
    cout << "making a sorted list:" << endl;
    dll.InsertSorted(10);
    dll.InsertSorted(20);
    dll.InsertSorted(30);
    dll.InsertSorted(40);
    dll.InsertSorted(50);
    dll.PrintList();
    cout << "reversing list: " << endl;
    dll.ReverseList();
    dll.PrintList();
    cout << "swapping 20 and 40: " << endl;
    dll.SwapNodes(20,40);
    dll.PrintList();
    return 0;
}