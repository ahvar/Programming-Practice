/**
  Implementation for stockList
*/
#include "stockList.h"

void StockList::Node::setStock(std::string name, std::string ticker, double price, int quantity)
{
  stock.setName(name);
  stock.setTicker(ticker);
  stock.setPrice(price);
  stock.setQuantity(quantity);

}

StockList::StockList( Stock s, Node *p, Node *sc )
{
  Stock a{};
  head = new Node( s, p, sc );
  head->succ = new Node( a, head, NULL);
  head->prev = new Node( a, NULL, head);
  head = head->prev;
  length = 3;
}


bool StockList::insertAtFront( Stock *s )
{
  Node n{};
  n.setStock(s->getName(), s->getTicker(), s->getValue(), s->getShares());
  Node *ptr = &n;
  if ( head == NULL) {
    head = ptr;
    return true;
  } else {
    ptr->succ = head;
    head->prev = ptr;
    ptr->prev = NULL;
    head = ptr;
    return true;
  }
  return false;
}

bool StockList::insertAtEnd( Stock *s )
{
  Node *ptr = head;
  while (ptr->succ) 
    ptr = ptr->succ;
  ptr->succ = n;
  n->prev = ptr->prev->succ;
  length++;
  return n;

}

Stock *StockList::find( double t, std::string nm )
{
  Node *ptr = head;
  while( ptr->succ ) {
    if( ptr->stock.getValue() == t && ptr->stock.getName() == nm )
      break;
    ptr = ptr->succ;
  }
  return ptr;
}

Stock *StockList::getLast()
{

  Node *ptr = head;
  while(ptr->succ != NULL)
    ptr = ptr->succ;
  return ptr;

}

bool StockList::isSortedAscending()
{

  Node *ptr = head;
  while(ptr->succ != NULL) {
    if( ptr->stock.getValue() > ptr->succ->stock.getValue() )
      return false;
    ptr = ptr->succ;
  }
  return true;

}

bool StockList::isEmpty()
{
  if(length==0)
    return true;
  return false;


}






