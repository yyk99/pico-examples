# Quick start

pico 2 W

	cmake -B build/pico2_w -S . -DPICO_BOARD=pico2_w -DFREERTOS_KERNEL_PATH=/home/yyk/src/raspberrypi-FreeRTOS-Kernel/
	cmake --build build/pico2_w -t picow_freertos_http_client_sys
	# run it
	sudo picotool load ./build/pico2_w/pico_w/wifi/freertos/http_client/picow_freertos_http_client_sys.elf -fx


pico w (RP2040)

	cmake -B build/pico_w -S . -DPICO_BOARD=pico_w -DFREERTOS_KERNEL_PATH=/home/yyk/src/FreeRTOS-Kernel/
	cmake --build build/pico_w -t picow_freertos_http_client_sys
	# run it
	sudo picotool load ./build/pico_w/pico_w/wifi/freertos/http_client/picow_freertos_http_client_sys.elf -fx

pico w (RP2040) + RP kernel

	cmake -B build/pico_w_rp -S . -DPICO_BOARD=pico_w -DFREERTOS_KERNEL_PATH=/home/yyk/src/raspberrypi-FreeRTOS-Kernel/
	cmake --build build/pico_w_rp -t picow_freertos_http_client_sys
	# run it
	sudo picotool load ./build/pico_w_rp/pico_w/wifi/freertos/http_client/picow_freertos_http_client_sys.elf -fx
