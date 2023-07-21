void reverse(){
  struct node *prevNode , *currentNode, *nextNode;
  prevNode= 0;
  while(nextNode!=0){
    nextNode=nextNode->next;
    currentNode->next=prevNode;
    prevNod=currentNode;
    currentNode=nextNode;
  }
}
