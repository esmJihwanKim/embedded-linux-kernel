#!/bin/bash

echo "configure build output path"

KERNEL_TOP_PATH="$( cd "$(dirname "$0")" ; pwd -P )"
OUTPUT = "$KERNEL_TOP_PATH/out"
echo "$OUTPUT"

KERNEL=kernel7
BUILD_LOG="$KERNEL_TOP_PATH/rpi_build_log.txt"

echo "move kernel source"
cd linux

echo "make defconfig"
make 0=$OUTPUT bcm2709_defconfig

echo "kernel build"
make 0=$OUTPUT zImage modules dtbs -j4 2>$1 | tee $BUILD_LOG