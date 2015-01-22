

#include <linux/kernel.h> /*needed for priority messages in prink*/
#include <linux/init.h> /*needed for macros*/
#include <linux/module.h> /*needed for all modules*/

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vamshi Krishna Gajjela");
MODULE_DESCRIPTION("Test Module Parameters");

static short myshort = 51;
static int myint = 451;
static int dint;
static long int mylong = 45100;
static char *mychar = "Smack Down";
static int myarr[2] = {51,43};
static int arr_argc = 0;
static int hello_world2_data __initdata = 3;

module_param(dint, int, 0);
MODULE_PARM_DESC(dint,"this is the dynamic int variable");

module_param(myshort, short, 0);
MODULE_PARM_DESC(myshort,"this is the short variable");

module_param(myint, int, 0);
MODULE_PARM_DESC(myint,"this is the int variable");


module_param(mylong, long , 0);
MODULE_PARM_DESC(myshort,"this is the long int variable");


module_param(mychar, charp, 0);
MODULE_PARM_DESC(myshort,"this is the characte string variable");


module_param_array(myarr, int,&arr_argc, 0);
MODULE_PARM_DESC(myarr,"this is the array variable");

int __init hello_world2_init(void){
 int i;
 printk(KERN_INFO "Vamshi : Entered2 : data = %d",hello_world2_data);
 printk(KERN_INFO "Value of the the short variable is = %hd",myshort);
 printk(KERN_INFO "Value of the the short variable is = %d",myint);
 printk(KERN_INFO "Value of the the dint variable is = %d",dint);
 printk(KERN_INFO "Value of the the short variable is = %ld",mylong);
 printk(KERN_INFO "Value of the the short variable is = %s",mychar);
 for(i=0;i<sizeof(myarr)/sizeof(int);i++){
  printk(KERN_INFO "arr[%d] = %d\n",i,myarr[i]);
 }
 return 0;
}
void __exit hello_world2_exit(void){
 printk(KERN_INFO "Vamshi : Exited2 ");
}

module_init(hello_world2_init);
module_exit(hello_world2_exit);