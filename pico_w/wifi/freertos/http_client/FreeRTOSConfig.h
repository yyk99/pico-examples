#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

// This example uses a common include to avoid repetition
#include "FreeRTOSConfig_examples_common.h"

// The common config sets configNUMBER_OF_CORES=2, which causes
// async_context_freertos to call vTaskCoreAffinitySet(). That function
// requires an SMP-capable FreeRTOS kernel. Override to single-core here
// so the standard (non-SMP) kernel can be used.
#undef configNUMBER_OF_CORES
#define configNUMBER_OF_CORES 1
#undef configUSE_CORE_AFFINITY

#endif
