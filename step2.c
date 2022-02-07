#include <linux/init.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>

MODULE_LICENSE("Module license");
MODULE_DESCRIPTION("Module description");
MODULE_AUTHOR("Martin Ferrand");

static int n;
static char *str;

module_param(n, int, S_IRUSR);
module_param(str, charp, S_IRUSR | S_IWUSR);

static int __init my_init(void)
{
  int i;

  for (i = 0; i < n; i++) {
    printk(KERN_DEBUG "Hello %s\n", str);
  }
  return (0);
}

static void __exit my_exit(void)
{
  int i;

  for (i = 0; i < n; i++) {
    printk(KERN_DEBUG "Goodbye %s\n", str);
  }
  return;
}

module_init(my_init);
module_exit(my_exit);