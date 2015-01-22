#ifndef __MDATA_CACHE_H
#define __MDATA_CACHE_H

#include "linkedlist.h"
#include <linux/module.h>
#include <linux/kernel.h>


void ext2_mdata_get_inode(struct inode *);
void ext2_mdata_get_name(struct qstr*);
void ext2_mdata_boot_read(struct inode *,struct qstr *);
//void ext2_store_mdata(void);


#endif
