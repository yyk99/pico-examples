# Quick start

	cmake -B build/pico2_w -S . -DPICO_BOARD=pico2_w -DFREERTOS_KERNEL_PATH=/home/yyk/src/raspberrypi-FreeRTOS-Kernel/
	cmake --build build/pico2_w -t picow_freertos_http_client_sys
	# run it
	sudo picotool load ./build/pico2_w/pico_w/wifi/freertos/http_client/picow_freertos_http_client_sys.elf -fx


in case of pico w (RP2040)

	cmake -B build/pico_w -S . -DPICO_BOARD=pico_w -DFREERTOS_KERNEL_PATH=/home/yyk/src/raspberrypi-FreeRTOS-Kernel/
	cmake --build build/pico_w -t picow_freertos_http_client_sys
	# run it
	sudo picotool load ./build/pico_w/pico_w/wifi/freertos/http_client/picow_freertos_http_client_sys.elf -fx
