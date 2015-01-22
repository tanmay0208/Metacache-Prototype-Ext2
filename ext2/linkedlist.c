#include <linux/slab.h>
#include <asm-generic/string.h>
#include "linkedlist.h"


static struct ext2_mdata_cache *first=NULL;
static struct ext2_mdata_cache *curr;

void  ext2_mdata_cache_insert(struct ext2_mdata_cache *temp)
{
//struct ext2_mdata_cache *temp;
  struct ext2_mdata_cache *nn=(struct ext2_mdata_cache*)kmalloc(sizeof(struct ext2_mdata_cache),GFP_KERNEL);
  *nn=*temp;
  nn->next=NULL;
  if(first!=NULL){

       curr->next=nn;
       curr=nn;
     //  nn->next=NULL;
     // temp=first;
      //while(temp->next!=first)
      //  temp=temp->next;
      //temp->next=nn;
  }else{
      curr=first=nn;
  }
}


void ext2_mdata_cache_display(void)
{
  struct ext2_mdata_cache *temp;
  temp=first;
  if(temp==NULL)
  {
    printk(KERN_INFO"no elements\n");
    return;
  }
  printk(KERN_INFO"elements in linked list are\n");
  while(temp!=NULL)
  {
    printk(KERN_INFO" %s---> %d\n",temp->data,(int)temp->inode_ptr->i_ino);
    temp=temp->next;
  }
}
/*
void ext2_mdata_cache_deletion()
{
  struct  ext2_mdata_cache  *temp;
  temp=first;
  first=first->next;
  temp->next=NULL;
  kfree(temp);
}
*/
/*int  main()
{
  int  op;  
  do
  {
    printf("1.insertion\n2.deletion\n3.display\n4.exi\n");
    printf("enter option\n");
    scanf("%d",&op);
    switch(op)
    {
      case 1:insert();
             break;
      case 2:deletion();
             break;
      case 3:display(); 
             break;
    }
  }while(op!=6);
}*/