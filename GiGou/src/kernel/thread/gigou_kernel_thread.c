#include "../../../inc/gigou_kernel_thread.h"


/*
 ******************************************************
 ******************* PUBLIC FONCTION ******************
 ******************************************************
 */



__GigouWinAPI gigou_Thread * __GigouUnixAPI gigou_kernel_thread_createThread(gigou_Thread * parent){
    
    gigou_Thread * buffer = (gigou_Thread*)malloc(sizeof(gigou_Thread));
    
    if(buffer == NULL){
        
        __GigouError("Can't allocate memory to create thread")
        
        exit(EXIT_FAILURE);
        
    }
    
    buffer->v_uuid = gigou_getUUID();
    
    
    buffer->da_stackMutex = NULL;
    
    buffer->v_nbrMutex = 0;
    
    
    buffer->da_stackChildThread = NULL;
    
    buffer->v_nbrChildThread = 0;
    

#if (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)
    
    __gigou_kernel_thread_unixCreateThread(buffer);
    
#elif GIGOU_PLATFORM == GIGOU_PLATFORM_WINDOWS
    
    __gigou_kernel_thread_win32CreateThread(buffer);
    
#endif
    
    if(parent != NULL){
        
        __gigou_kernel_thread_addOneChildAtThread(parent,buffer);
        
    }
    
    return buffer;
    
}


__GigouWinAPI void __GigouUnixAPI gigou_kernel_thread_destroyThread(gigou_Thread * thread){
    
    if(thread != NULL){
        
        
    }else{
        
        __GigouError("Invalid argument")
        
    }
    
}




/*
 *******************************************************
 ******************* PRIVATE FONCTION ******************
 *******************************************************
 */




__GigouWinAPI void __GigouUnixAPI __gigou_kernel_thread_addOneChildAtThread(gigou_Thread * thread,
                                                                            gigou_Thread * child){
    
    if(thread != NULL && child != NULL){
        
        /*
         A completer plus tard
         */
        
    }
    
}



__GigouWinAPI UINT32 __GigouUnixAPI __gigou_kernel_thread_isStopped(gigou_Thread * thread){
    
    if(thread != NULL){
        
        if(thread->v_nbrChildThread == 0 && thread->v_nbrMutex == 0){
            
            return 1;
            
        }
        
    }else{
        
        return 1;
        
    }
    
    return 0;
}

