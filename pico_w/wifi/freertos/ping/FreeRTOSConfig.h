#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

// This example uses a common include to avoid repetition
#include "FreeRTOSConfig_examples_common.h"

// The common config sets configNUMBER_OF_CORES=2 and configUSE_CORE_AFFINITY=1.
// SMP support (vTaskCoreAffinitySet) was introduced in FreeRTOS V11.
// When building with a V10 kernel, override to single-core to avoid linker errors.
#if !FREERTOS_SMP_SUPPORT
#undef configNUMBER_OF_CORES
#define configNUMBER_OF_CORES 1
#undef configUSE_CORE_AFFINITY
#define configUSE_CORE_AFFINITY 0
#endif

#endif
