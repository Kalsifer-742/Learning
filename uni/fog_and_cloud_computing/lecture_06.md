# Lecture 27/03/24

fatti una nota sulla cosa delle page table. la tlb prima della modalità tagged funziona perchè ogni volta con il context switch la svuoti. quindi ha sempre senso quello che c'è scritto.

## I/O Virtualization

3 ways to do it:

- device emulation
  - multiple vm can be on the same network interface. The VMM emulate stuff in some ways internally.
- para-virtualized device
  - the same as OS system customization
- direct assignment

### Device Emulation

Traps everytime the VM tries to access it

the VMM can expose whatever driver it wants

easy for the user but pretty slow

## para virtualization

memory ballooning, guarda slides

### direct assignment

PCI passthrough

IOMMU to address the problem of hardware device address translation

SR-IOV: pci standard to create virtual devices. useful for network cards. look at the slides

## Hypervisor

- on bare metal

## Lightweight Virtualization

docker

how do we do it ?

Linux cgroups:

limit and isolate or deny resources to a process or a group of processes

- example cpu quota

they also give you accounting. like to see how many resources are used by a specific groups

Linux namespaces:

similar to cgroups. more focused on creating isolation and restrict what a process can see