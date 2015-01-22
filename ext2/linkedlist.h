#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER
#include <linux/fs.h>
#include "ext2.h"

struct ext2_mdata_cache
{
	const char *data;
	struct inode *inode_ptr;
	struct ext2_mdata_cache *next;
};	

void ext2_mdata_cache_display(void);
void ext2_mdata_cache_insert(struct ext2_mdata_cache *nn);

 
#endif

