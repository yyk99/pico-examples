# DEBUG Quick start

## Build it
PICO original (RP2040, not Pico W or Pico 2)

	cmake -B build/pico -S . -DPICO_BOARD=pico \
		-DFREERTOS_KERNEL_PATH=/home/yyk/src/raspberrypi-FreeRTOS-Kernel/ \
		-DCMAKE_BUILD_TYPE=Debug
	cmake --build build/pico -t hello_freertos_one_core \
		hello_freertos_static_allocation \
		hello_freertos_two_cores

## Run it (without debug)

	# build/pico/freertos/hello_freertos/hello_freertos_one_core.elf
	# build/pico/freertos/hello_freertos/hello_freertos_static_allocation.elf
	# build/pico/freertos/hello_freertos/hello_freertos_two_cores.elf
	sudo picotool load build/pico/freertos/hello_freertos/hello_freertos_one_core.elf -fx

## DEBUG session

in Terminal 1

	sudo openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000"

in Terminal 2

	gdb-multiarch build/pico/freertos/hello_freertos/hello_freertos_one_core.elf
	(gdb) target extended-remote :3333
	(gdb) monitor halt
	(gdb) load
	(gdb) b main
	(gdb) continue

alternatively nohup can be used to run openocd as bg process

	sudo nohup openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000"
