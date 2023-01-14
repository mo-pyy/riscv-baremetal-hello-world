# Baremetal hello world on riscv64


## Build
Before the first time setup build directory like this in project root:</br>
`meson setup --cross-file ./cross/riscv64-elf.ini --cross-file ./cross/cross.ini build_riscv`

Now compile:</br>
`meson compile -C build_riscv`
