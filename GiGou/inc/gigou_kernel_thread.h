#ifndef GIGOU_KERNEL_THREAD_H
#define GIGOU_KERNEL_THREAD_H

#include "gigou_init.h"

#include "gigou_uuid.h"

#if (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)
#   include <pthread.h>
#elif GIGOU_PLATFORM == GIGOU_PLATFORM_WINDOWS
#   include <windows.h>
#else
#   error "Gigou doesn't support this platform"
#endif

typedef struct gigou_Thread gigou_Thread;
typedef struct gigou_Mutex gigou_Mutex;
typedef struct gigou_Condition gigou_Condition;


__GigouWinAPI struct __GigouUnixAPI gigou_Thread{
    
    GIGOU_UUID v_uuid;
    
    gigou_Mutex ** da_stackMutex;
    
    
    
#if (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)
    pthread_t v_thread;
#elif GIGOU_PLATFORM == GIGOU_PLATFORM_WINDOWS

#endif
    
};


__GigouWinAPI struct __GigouUnixAPI gigou_Mutex{
    
    GIGOU_UUID v_uuid;
    
    gigou_Condition ** da_StackCondition;
    
    
    
#if (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)
    pthread_mutex_t v_mutex;
#elif GIGOU_PLATFORM == GIGOU_PLATFORM_WINDOWS
    
#endif
    
};


__GigouWinAPI struct __GigouUnixAPI gigou_Condition{
    
    GIGOU_UUID v_uuid;
    
    
#if (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)
    pthread_cond_t v_cond;
#elif GIGOU_PLATFORM == GIGOU_PLATFORM_WINDOWS
    
#endif
    
};

#endif