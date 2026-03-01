if (NOT FREERTOS_KERNEL_PATH AND NOT DEFINED ENV{FREERTOS_KERNEL_PATH})
    message("Skipping FreeRTOS examples as FREERTOS_KERNEL_PATH not defined")
    return()
endif()

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

add_subdirectory(hello_freertos)
