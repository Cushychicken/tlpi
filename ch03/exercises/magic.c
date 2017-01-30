#include <stdio.h>
#include <unistd.h>
#include <linux/reboot.h>

int main(int argc, char *argv[])
{
    printf("Magic #1 : %08x\n", LINUX_REBOOT_MAGIC1);
    printf("Magic #2 : %08x\n", LINUX_REBOOT_MAGIC2);

    return 0;
}
