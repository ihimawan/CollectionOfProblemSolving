bool isCycle(Node* head){
    Node* tortoise;
    Node* hare;
    
    tortoise = hare = head;
    int length = 1;
    
    for (int i = 0; hare!=NULL && hare->next!=NULL; i++)
    {
        tortoise = tortoise ->next;
        hare = hare -> next -> next;
        
        if (tortoise == hare){
            for (hare = hare->next; hare!=tortoise; l++);
            return true;
        }
        
    }
    
    l=0;
    return false;
}