struct node {
    WHATEVER_TYPE val;
    struct node* next;
};

node* merge(node* a, node* b) {
    node* out;
    node** p = &out;    // Address of the next pointer that needs to be changed

    while (a && b) {
        if (a->val < b->val) {
            *p = a;
            a = a->next;
        } else {
            *p = b;
            b = b->next;
        }

        // Next loop iter should write to final "next" pointer
        p = &(*p)->next;
    }

    // At least one of the input lists has run out.
    if (a) {
        *p = a;
    } else {
        *p = b;        // Works even if b is NULL
    }

    return out;
}