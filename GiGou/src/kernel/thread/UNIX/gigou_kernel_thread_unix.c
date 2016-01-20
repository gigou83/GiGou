#include "../../../../inc/gigou_kernel_thread.h"

#if (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)

__GigouWinAPI void __GigouUnixAPI __gigou_kernel_thread_unixCreateThread(gigou_Thread * thread){
    
    thread->v_thread = 0;
    thread->pf_func = NULL;
    thread->p_arg = NULL;
    
}

#endif