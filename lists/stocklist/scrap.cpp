StockList::Node *StockList::sortByPrice()
{
  while( !isSortedAscending() ) {

    if( length == 0 ) {
      return NULL;

    } else if ( length ==  1 ) {
      return head;

    } else if ( length == 2 ) {

      if  ( head->stock.getValue() > head->succ->stock.getValue() ) 
        head = head->succ;
      return head;

    } else if ( length >= 3 ) {
      Node *pivot = getLast();
      Node *curr = head;

      while(curr->succ) {

        if(curr->stock.getValue() <= pivot->stock.getValue()) { // node's stock value is less than pivot. move it to the left of pivot. 
                                                     //insert between pivot and previous node.
          pivot->prev->succ = curr->succ->prev;
          Node *pvPre = pivot->prev;
          pivot->prev = curr->succ->prev;
          curr->succ->prev->succ = pivot;
          pivot->prev->prev = pvPre->prev->succ;

        } else if ( curr->stock.getValue() >= pivot->stock.getValue() ) { // node's stock value is greater than pivot's. move it to the right of pivot

          if (pivot->succ == NULL) { // there are no nodes after the pivot
            curr->prev = pivot;
            pivot->succ = curr->succ->prev;
            curr = curr->succ;
          } else { // insert the node between the pivot and its successor node
            curr->prev = pivot;
            pivot->succ->prev = curr->succ->prev;
            curr->succ->prev->succ = pivot->succ;
            pivot->succ = curr->succ->prev;
            curr = curr->succ; 
          }
          curr->prev = NULL;

        }  
      }
    }
  }
  return head;
}


StockList::Node *StockList::add( Node *n )
{
  // first handle the case of when the list is empty
  if (isEmpty()) {
    head = n;
    length++;
    return head;
  } else if ( !isSortedAscending() ) {
    StockList::sortByPrice();  
  }
  Node *ptr = head;
  while( ptr ) {
    if (ptr->stock.getValue() <= n->stock.getValue())
      break;
    ptr = ptr->succ;
  }
  // we reached the end of the list or it is the last node in the list
  if ( ptr == NULL || ptr->succ == NULL ) {
    return StockList::insertAtEnd(n);
  } else if ( ptr == head ) {
    return StockList::insertAtFront(n);   
  } else {
    n->succ = ptr->prev->succ;
    n->prev = ptr->prev;
    ptr->prev->succ = n;
    ptr->prev = n;
    ptr->prev->prev->succ = n;
    length++;
  }
  return n;

}
