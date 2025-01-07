#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string name;
    double score;
    node* next;

    node() : next(nullptr) {}  

    void set_data(string n, double s) {
        name = n;
        score = s;
    }
};

class my_list {
private:
    node* head;
    node* tail;

public:
    my_list() : head(nullptr), tail(nullptr) {}  

    void add_to_head(node tmp);
    void add_to_tail(node tmp);
    node delete_from_head();
    int num_nodes();
    double score_sum();
    double get_score(string name);
    int remove_a_node(string name);
};

void my_list::add_to_head(node tmp) {
    node* new_node = new node;
    new_node->set_data(tmp.name, tmp.score);
    new_node->next = head;
    head = new_node;
    if (tail == nullptr) {  
        tail = head;
    }
}

void my_list::add_to_tail(node tmp) {
    node* new_node = new node;
    new_node->set_data(tmp.name, tmp.score);
    if (tail != nullptr) {
        tail->next = new_node;
    }
    tail = new_node;
    if (head == nullptr) {  
        head = tail;
    }
}

node my_list::delete_from_head() {
    node tmp;
    if (head == nullptr) {
        cout << "List is empty.\n";
        return tmp;
    }
    tmp.set_data(head->name, head->score);
    node* del = head;
    head = head->next;
    delete del;
    if (head == nullptr) {  
        tail = nullptr;
    }
    return tmp;
}

int my_list::num_nodes() {
    int count = 0;
    node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

double my_list::score_sum() {
    double total = 0;
    node* current = head;
    while (current != nullptr) {
        total += current->score;
        current = current->next;
    }
    return total;
}

double my_list::get_score(string name) {
    node* current = head;
    while (current != nullptr) {
        if (current->name == name) {
            return current->score;
        }
        current = current->next;
    }
    return -1;  
}

int my_list::remove_a_node(string name) {
    node* current = head;
    node* prev = nullptr;
    while (current != nullptr) {
        if (current->name == name) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current == tail) {
                tail = prev;
            }
            delete current;
            return 1;  
        }
        prev = current;
        current = current->next;
    }
    return 0;  
}

int main() {
    my_list a;
    node tmp;

    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);

    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);  // head 위치로 2개의 원소 추가

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 1단계 점검

    tmp.set_data("Park", 91.3);
    a.add_to_tail(tmp);  // tail 위치로 1개의 원소 추가

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 2단계 점검

    tmp = a.delete_from_head();
    cout << tmp.name << " is deleted.\n";  // 3단계 점검

    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);

    tmp.set_data("Ryu", 94.3);
    a.add_to_head(tmp);  // 2개의 원소 추가

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";

    cout << "Park’s score : " << a.get_score("Park") << "\n";  // 4단계 점검

    if (a.remove_a_node("Kim") == 1) {
        cout << "Kim is deleted from the list. \n";  // 5단계 점검
    }

    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 최종 점검

    return 0;
}
