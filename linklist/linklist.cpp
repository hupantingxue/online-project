// Example program
#include <iostream>
#include <string>
#include <vector>

class LinkNode {
public:
    int data;
    LinkNode *next;
public:
    LinkNode(){}
    ~LinkNode();
    LinkNode* insert(LinkNode* head, int data);
    int travel();
    LinkNode* revert(LinkNode* head);
};

LinkNode* LinkNode::insert(LinkNode* head, int data) {
    LinkNode *pTmp = nullptr;
    pTmp = new LinkNode();
    pTmp->data = data;
    
    if (nullptr == head) {
        head = new LinkNode(); 
        head->next = nullptr;       
    }
    
    pTmp->next = head->next;
    head->next = pTmp;
    return head;
}

int LinkNode::travel() {
    LinkNode *head = this;
    if (nullptr == head || nullptr == head->next) {
        std::cout << "This is a null list" << std::endl;
    }
    
    while(nullptr != head->next) {
        std::cout << head->next->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
    return 0;
}

// revert a linklist
LinkNode* LinkNode::revert(LinkNode* head) {
    LinkNode* rl = new LinkNode();
    std::vector<int> vec;
    LinkNode* pTmp = nullptr;
    
    // travel the list and save data to vector    
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    
    while(nullptr != head->next) {
        vec.push_back(head->next->data);
        head = head->next;
    }
    
    // init head node
    rl->next = nullptr;
    
    for(auto &ii:vec) {
        pTmp = new LinkNode();
        pTmp->data = ii;
        pTmp->next = rl->next;
        rl->next = pTmp;
    }
    
    return rl;
}

int main()
{
  LinkNode* list = new LinkNode();
  for (int ii = 0; ii < 10; ii++) {
      list->insert(list, ii);
  }
  list->travel();
  
  LinkNode *rlist = list->revert(list);
  rlist->travel();
}
