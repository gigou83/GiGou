#ifndef GIGOU_KERNEL_THREAD_MUTEX_H
#define GIGOU_KERNEL_THREAD_MUTEX_H

#include "gigou_init.h"

#include "gigou_kernel_thread_uuid.h"
#include "gigou_kernel_thread_cond.h"

#if (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)
#   include <pthread.h>
#elif GIGOU_PLATFORM == GIGOU_PLATFORM_WINDOWS
#   include <windows.h>
#else
#   error "Gigou doesn't support this platform"
#endif

typedef struct gigou_Mutex gigou_Mutex;

__GigouWinAPI struct __GigouUnixAPI gigou_Mutex{
    
    GIGOU_UUID v_uuid;
    
    gigou_Condition ** da_StackCondition;
    
    
    
#if (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)
    pthread_mutex_t v_mutex;
#elif GIGOU_PLATFORM == GIGOU_PLATFORM_WINDOWS
    
#endif
    
};

#endif