#include <linux/init.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>

MODULE_LICENSE("Module license");
MODULE_DESCRIPTION("Module description");
MODULE_AUTHOR("Martin Ferrand");

static int __init my_init(void)
{
  printk(KERN_DEBUG "Hello kernel");
  return (0);
}

static void __exit my_exit(void)
{
  int i;

  for (i = 0; i < n; i++) {
    printk(KERN_DEBUG "Goodbye kernel");
  }
  return;
}

module_init(my_init);
module_exit(my_exit);