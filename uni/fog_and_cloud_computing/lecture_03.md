# Lecture 08/03/2024

## Layering

layering is a common approach to manage system complexity.

Each subsystem is abstracted.

Subsystems exposes interfaces to be used by upper layer. Subsystems are trated like black boxes

Example:

1. Libraries
2. Operating system
3. Hardware

Remember of ISA, ABI and API

## Definitions

- Host OS
  - Os running on the actual hardware
  - The Hypervisor can reside here
- Virtual Machine
  - Software emulation of a physical machine
- Guest OS
  - Os running inside the VM. Not aware of running in a VM

---

- Hypervisor or VMM(Virtual Machine Monitor)
  - Software in charge of the virtualization process
  - Isolation
  - Managing shared resources

Provides virtual hardware to the VM

If the virtualized cpu has the same ISA of the real one we don't encounter any special problems. If we virtualize a cpu with a different ISA we have to relay on Emulation and not Virtualization. We need to translate the ISA from one architecture to another
Virtual Machine: "A virtual machine is an efficient, isolated duplicate of the real machine"

VMM:

- applications and os can run unmodified
- efficient
  - as much as possible instructions of the virtual processor should be executed by the real processor
- control of the real system resources
  - each VM should be able to access hardware resources only under the authorization fo the VMM

## Types of virtualization

- Full Virtualization
  - Guest OS can run unsupervised in the hypervisor
- Paravirtualization
  - Guest OS need to be modified in order to be excuted
- Hardware assisted virtualization
  - Hypervisor uses hardware features included in the CPU/chipset

## Hardware privilege ring

x86 defines 3 rings of privileges

- 0: most privileged part of the code: Kernel
- 1-3: application and services with different levels of privilege

Modern OSes only use ring 0 and 3

virtualization models:

- 0/1/3: Guest os runs in ring 1/2 and has some memory access. VMM runs in ring 3. In this way the guest OS can get in the way of the VMM. Not very good.
- 0/3/3: Also called ring compression. Everything but the kernel runs in ring 3. In this way we solve the privilege problem but the Guest OS becomes more vulnerable to malicious applications which runes on the same level.

## Privileged Instruction

CPU instruction that needs to be executed in a privileged hardware context. It generates a trap if called when the CPU is running in the wrong context.

Example: user-level application cannot do this things
- HALT instruction
  - a random application cannot halt a computer from running
- I/O instructions
  - no direct interaction is allowed

## Sensitive Instruction

Instruction which leaks information about the internal status of a processor.

To virtualize all sensitive instructions of a CPU must be privileged.

## Traps

When the CPU is running in user mode it happens that something needs to be handled in kernel mode. The CPU jumps to the hardware exception handler vector and executes operations in kernel mode.

When it happens:

- Exception
- System Call
- Hardware Interrupts

### System call implementation
