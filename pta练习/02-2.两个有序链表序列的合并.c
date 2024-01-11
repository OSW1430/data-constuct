List Merge( List L1, List L2){
    List L,head;
    if(L1->Data >= L2->Data){
        L = L2;
        head = L;
        L2 = L2->Next;
    }
    while(L1 && L2){
        if(L1->Data >= L2->Data){
            L->Next = L2;
            L2 = L2->Next;
        }
        else {
            L->Next = L1;
            L1 = L1->Next;
        }
        L = L->Next;
    }
    if(L1){
        L->Next = L1;
        L = L->Next;
    }
    if(L2){
        L->Next = L2;
        L = L->Next;
    }
    return head;
}
