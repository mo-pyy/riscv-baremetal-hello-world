export CC="riscv64-unknown-elf-gcc"
export CFLAGS="-Wall -Werror -O -fno-omit-frame-pointer -ggdb -Wno-infinite-recursion -MD -mcmodel=medany -ffreestanding -fno-common -nostdlib -mno-relax"
export LD="riscv64-unknown-elf-ld"
export OBJCOPY="riscv64-unknown-elf-objcopy"

./clean.sh

$CC $CFLAGS -c -o main.o main.c
$LD -z max-page-size=4096 -Map=main.map -T link.ld -o main.elf main.o
$OBJCOPY main.elf --strip-all -O binary main.bin