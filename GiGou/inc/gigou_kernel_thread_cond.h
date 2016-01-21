#ifndef GIGOU_KERNEL_THREAD_COND_H
#define GIGOU_KERNEL_THREAD_COND_H

#include "gigou_init.h"

#include "gigou_kernel_thread_uuid.h"

#if (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)
#   include <pthread.h>
#elif GIGOU_PLATFORM == GIGOU_PLATFORM_WINDOWS
#   include <windows.h>
#else
#   error "Gigou doesn't support this platform"
#endif

typedef struct gigou_Condition gigou_Condition;

__GigouWinAPI struct __GigouUnixAPI gigou_Condition{
    
    GIGOU_UUID v_uuid;
    
    
#if (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)
    pthread_cond_t v_cond;
#elif GIGOU_PLATFORM == GIGOU_PLATFORM_WINDOWS
    
#endif
    
};

#endif