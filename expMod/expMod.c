#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

// Importing external module
extern void print_hello_dev(char* dev_name);

// Module Initialization Function
static int __init expMod_init(void)
{
    printk(KERN_INFO "%s: Module loaded\n", THIS_MODULE->name);
    print_hello_dev("Yooo");
    return 0;
}

// Module Exit Function
static void __exit expMod_exit(void)
{
    printk(KERN_INFO "%s: Module exited\n", THIS_MODULE->name);
}

// Register Module Entry and Exit Points
module_init(expMod_init);
module_exit(expMod_exit); 

// Module Information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aravind Potluri");
MODULE_DESCRIPTION("Example of using external modules");
MODULE_VERSION("1.0.0");
