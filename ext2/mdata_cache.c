#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/dcache.h>
#include "mdata_cache.h"

static struct ext2_mdata_cache *node_find;
void ext2_mdata_get_inode(struct inode *inode_orignal_ptr)
{
	//printk(KERN_INFO"%s %d",__func__,(int)inode_orignal_ptr->i_ino);
    node_find->inode_ptr=inode_orignal_ptr;
    ext2_mdata_cache_insert(node_find);
    ext2_mdata_cache_display();
    kfree(node_find);
    
}

void ext2_mdata_get_name(struct qstr *file_ptr)
{
	//printk(KERN_INFO"%s %s",__func__,file_ptr->name);
	node_find=(struct ext2_mdata_cache *)kmalloc(sizeof(struct ext2_mdata_cache),GFP_KERNEL);
	node_find->data=file_ptr->name;
    
}

void ext2_mdata_boot_read(struct inode *inode_orignal_ptr,struct qstr *file_ptr)
{
	node_find=(struct ext2_mdata_cache *)kmalloc(sizeof(struct ext2_mdata_cache),GFP_KERNEL);
	node_find->data=file_ptr->name;
	node_find->inode_ptr=inode_orignal_ptr;
	printk(KERN_INFO"INO--------->  %d---> ",(int)node_find->inode_ptr->i_ino);
    printk(KERN_INFO"File_name--->  %s--->\n",node_find->data);
	ext2_mdata_cache_insert(node_find);
    ext2_mdata_cache_display();
    kfree(node_find);
}
/*
void ext2_store_mdata(void)
{
  // printk(KERN_INFO"%s--->",node_find->data);
   //ext2_add_tolink(node_find);
   //ext2_display_file();
  int k=0;
  printk(KERN_INFO"\nThe Linked List : ");
  while(k<i)
  { 
    printk(KERN_INFO" %s---> %d\n",node_find[k].data,(int)node_find[k].inode_ptr->i_ino);
    //new_node=new_node->next;
    k++;
  }

   //kfree(node_find);
}   */