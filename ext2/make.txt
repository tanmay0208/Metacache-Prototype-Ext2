#
# Makefile for the linux ext2-filesystem routines
#

#obj-$(CONFIG_EXT2_FS) += ext2.o
obj-m += ext2.o

ext2-objs := balloc.o dir.o file.o ialloc.o inode.o \
	  ioctl.o namei.o super.o symlink.o linkedlist.o mdata_cache.o \
	xattr.o xattr_user.o xattr_trusted.o acl.o \
	xattr_security.o
#Files not compiled:  xip.o

KERNEL_PATH=/usr/src/linux-3.11.1

all:
		make -C $(KERNEL_PATH) M=$(PWD) modules EXTRA_CFLAGS=-Werror

clean:
		make -C $(KERNEL_PATH) M=$(PWD) clean
