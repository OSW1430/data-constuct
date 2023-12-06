Position BinarySearch( List L, ElementType X ){
    Position begin = 1;
    while(begin <= L->Last){
        Position mid = (begin + L->Last) / 2;
        if(X > L->Data[mid])
            begin = mid + 1;
        else if(X < L->Data[mid])
            L->Last = mid - 1;
        else return mid;
    }
    return NotFound;
}
