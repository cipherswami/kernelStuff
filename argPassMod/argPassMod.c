#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

// Argument Parameters
char *my_arg = "This is default argument";
module_param(my_arg, charp, S_IRUGO);

// Module Initialization Function
static int __init mod_init(void)
{
    printk(KERN_INFO "%s: Module loaded\n", THIS_MODULE->name);
    printk(KERN_INFO "%s: Passed Argument - %s\n", THIS_MODULE->name, my_arg);
    return 0;
}

// Module Exit Function
static void __exit mod_exit(void)
{
    printk(KERN_INFO "%s: Module exited\n", THIS_MODULE->name);
}

// Register Module Entry and Exit Points
module_init(mod_init);
module_exit(mod_exit); 

// Module Information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aravind Potluri");
MODULE_DESCRIPTION("Example of Kernel Module with Arguments");
MODULE_VERSION("1.0.0");
