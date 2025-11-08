
#
# rough C definition
# void xnuloader_boot_kernel_at_address_with_args(physical_address_t entry, xnu_boot_args_t *)
#

# .globl xnuloader_boot_kernel_at_address_with_args_asm

xnuloader_boot_kernel_at_address_with_args_asm:
    cli              # First, clear the interrupts and prep to disable them.
