bool has_cycle(Node* head) {
    if(head==NULL) {
        return false;
    }
    struct Node *current=head;
    bool check[1000]={false};
    int i=0;
    while(current!=NULL) {
        if(!check[i]) {
            check[i]=true;
            current=current->next;
        }
        else if(check[i])
            return true;
        i++;
    }
    return false;
    // Complete this function
    // Do not write the main method
}
