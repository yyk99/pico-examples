if (NOT FREERTOS_KERNEL_PATH AND NOT DEFINED ENV{FREERTOS_KERNEL_PATH})
    message("Skipping Pico W FreeRTOS examples as FREERTOS_KERNEL_PATH not defined")
else()
    include(FreeRTOS_Kernel_import.cmake)

    # Detect SMP support: vTaskCoreAffinitySet was added in FreeRTOS V11.
    # V10.x kernels lack it; building with configNUMBER_OF_CORES>1 causes a
    # linker error. Check task.h and pass the result as a compile definition.
    file(STRINGS "${FREERTOS_KERNEL_PATH}/include/task.h" _smp_check
         REGEX "vTaskCoreAffinitySet")
    if(_smp_check)
        set(FREERTOS_SMP_SUPPORT 1)
        message(STATUS "FreeRTOS kernel: SMP supported (vTaskCoreAffinitySet found)")
    else()
        set(FREERTOS_SMP_SUPPORT 0)
        message(STATUS "FreeRTOS kernel: SMP not supported (pre-V11), using single-core")
    endif()

    add_subdirectory_exclude_platforms(httpd)
    add_subdirectory_exclude_platforms(iperf)
    add_subdirectory_exclude_platforms(ntp_client_socket)
    add_subdirectory_exclude_platforms(ping)
    add_subdirectory_exclude_platforms(http_client)
endif()
