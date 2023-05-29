#include "dna_strand.hpp"
#include <stdexcept> 
DNAstrand::~DNAstrand() {
    while (head_ != nullptr) {
        Node *hold = head_->next;
        delete head_;
        head_ = hold;
    }
    head_ = nullptr;
    tail_ = nullptr;
} 
void DNAstrand::AddTest(char input[], int size) {
    head_ = new Node(input[0]);
    Node* current = head_;
    for (int i = 1; i < size; i++) {
        current->next = new Node(input[i]);
        current = current -> next;
    }
    tail_ = current;  
} 
void DNAstrand::SpliceIn(const char* pattern, DNAstrand& to_splice_in) { 
    if (pattern == nullptr || pattern[0] == '\0' || to_splice_in.head_ == nullptr || &to_splice_in == this) {
        return;}
    Node* confirmed = nullptr;Node* start = nullptr; int loop_index = 0; Node* current = head_; Node* previous = head_; 
    while (current != nullptr) {if (loop_index == 0 && pattern[0] == current->data) {start = previous; loop_index++;} else if (pattern[loop_index] == '\0') {confirmed = start;loop_index = 0; if (loop_index == 0 && pattern[0] == current->data) {start = previous; loop_index++;}} else if (pattern[loop_index] == current->data) {loop_index++;} else {loop_index = 0;
            if (loop_index == 0 && pattern[0] == current->data) {
                start = previous; 
                loop_index++;
            }
        }
        previous = current; 
        current = current->next;
    }
    if (pattern[loop_index] == '\0') {
        confirmed = start;
    }
    if(confirmed == nullptr) { 
        throw std::invalid_argument("");
    }
    //deletes all the nodes in the patterns
    if (head_ != confirmed) {
        current = confirmed->next;
    } else {
        current = confirmed;
    }
    loop_index = 0;
    while (pattern[loop_index] != '\0') {
        Node* hold = current->next;
        if (head_ == current) {
            head_ = nullptr;
        }
        delete current;
        current = hold;
        loop_index++;
    }
    if (head_ == nullptr) {head_ = to_splice_in.head_;} else {  confirmed->next = to_splice_in.head_;}to_splice_in.head_ = nullptr;to_splice_in.tail_-> next = current; to_splice_in.tail_ = current;current = head_;while (current->next != nullptr) {current = current->next;}tail_ = current;
}
/*
void DNAstrand::SpliceIn(const char* pattern, DNAstrand& to_splice_in) { 
    if (pattern == nullptr || pattern[0] == '\0' || to_splice_in.head_ == nullptr || &to_splice_in == this) {
        return;
    }
    Node* confirmed = nullptr;//put all previous nodes of matches into start, later on I can just take the last thing in the vector. Did previous nodes so that I can just start from them when replacing.  
    Node* start = nullptr; //holds the start of where the pattern is
    int loop_index = 0; //holds the position in the pattern

    //finds the node right before the last example of the pattern. 
    Node* current = head_;
    Node* previous = head_; 
    while (current != nullptr) {
        if (loop_index == 0 && pattern[0] == current->data) {
            start = previous; 
            loop_index++;
        } else if (pattern[loop_index] == '\0') {
            confirmed = start;
            loop_index = 0; 
            if (loop_index == 0 && pattern[0] == current->data) {
                start = previous; 
                loop_index++;
            }
        } else if (pattern[loop_index] == current->data) {
            loop_index++;
        } else {
            loop_index = 0;
            if (loop_index == 0 && pattern[0] == current->data) {
                start = previous; 
                loop_index++;
            }
        }
        previous = current; 
        current = current->next;
    }
    if (pattern[loop_index] == '\0') {
        confirmed = start;
    }
    if(confirmed == nullptr) { 
        throw std::invalid_argument("");
    }
    //deletes all the nodes in the patterns
    if (head_ != confirmed) {
        current = confirmed->next;
    } else {
        current = confirmed;
    }
    loop_index = 0;
    while (pattern[loop_index] != '\0') {
        Node* hold = current->next;
        if (head_ == current) {
            head_ = nullptr;
        }
        delete current;
        current = hold;
        loop_index++;
    }
    if (head_ == nullptr) {
        head_ = to_splice_in.head_;
    } else {  
        confirmed->next = to_splice_in.head_;
    }
    //splices in the new string
    to_splice_in.head_ = nullptr;
    to_splice_in.tail_-> next = current; 
    to_splice_in.tail_ = current;

    //confirms the tail
    current = head_;
    while (current->next != nullptr) {
        current = current->next;
    }
    tail_ = current;
}
*/