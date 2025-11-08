## x86_64

XNU expects the loader to have entered protected mode, with paging disabled and a 32-bit address space.

Further, the code/stack/data segments have a base of zero and a limit of 46.

The boot arguments structure is in the **EAX** register.

## arm

XNU expects the loader to have placed the boot arguments structure in the **R0** register, with **R1** being set to zero.

## arm64

XNU expects the loader to have placed the boot arguments in the **X0** register.
