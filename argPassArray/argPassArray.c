#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

// Argument Parameters
int my_arg_arr[4];
int argc = 0;
module_param_array(my_arg_arr, int, &argc, S_IRUGO);

// Module Initialization Function
static int __init mod_init(void)
{
    printk(KERN_INFO "%s: Module loaded\n", THIS_MODULE->name);
    for(int i=0; i < sizeof(my_arg_arr)/sizeof(my_arg_arr[0]); i++) {
        printk(KERN_INFO "%s: %d - %d\n", THIS_MODULE->name, i, my_arg_arr[i]);
    }
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
MODULE_DESCRIPTION("Example of Kernel Module with Array Arguments");
MODULE_VERSION("1.0.0");
