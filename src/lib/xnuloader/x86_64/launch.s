
#
# rough C definition
# void xnuloader_launch_asm(physical_address_t entry, xnu_boot_args_t *)
#

.extern _xl_gdt

.globl xnuloader_launch_asm

xnuloader_launch_asm:
    cli                /* Disable/Clear IRQs. */
    leaq rcx, _xl_gdt  /* Get the address of our GDT. */
    lgdt rcx
