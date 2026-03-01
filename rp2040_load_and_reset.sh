#!/bin/bash

if [ -z $1 ]  ; then
    echo Usage: $0 firmware.elf
    exit 1
fi
openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg \
	-c "adapter speed 5000" \
        -c "program $1 verify reset exit"
