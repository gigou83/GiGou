#ifndef GIGOU_KERNEL_THREAD_H
#define GIGOU_KERNEL_THREAD_H

#include "gigou_init.h"

#include "gigou_kernel_thread_uuid.h"
#include "gigou_kernel_thread_mutex.h"


#if (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)
#   include <pthread.h>
#elif GIGOU_PLATFORM == GIGOU_PLATFORM_WINDOWS
#   include <windows.h>
#else
#   error "Gigou doesn't support this platform"
#endif

typedef struct gigou_Thread gigou_Thread;


__GigouWinAPI struct __GigouUnixAPI gigou_Thread{
    
    GIGOU_UUID v_uuid;
    
    gigou_Mutex ** da_stackMutex;
    UINT32 v_nbrMutex;
    
    gigou_Thread ** da_stackChildThread;
    UINT32 v_nbrChildThread;
    
    
#if (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)
    
    pthread_t v_thread;
    
    void (*pf_func) (void*);
    
    void * p_arg;
    
#elif GIGOU_PLATFORM == GIGOU_PLATFORM_WINDOWS

#endif
    
};




/*
 ******************************************************
 ******************* PUBLIC FONCTION ******************
 ******************************************************
 */



/* ---------------------------------------------------------------------
gigou_kernel_thread_createThread()
---------------------------------------------------------------------
Créé un nouveau thread en l'initialisant et ajoute ce thread en fils
au parent
---------------------------------------------------------------------
E : parent
S : le thread
--------------------------------------------------------------------- */
__GigouWinAPI gigou_Thread * __GigouUnixAPI gigou_kernel_thread_createThread(gigou_Thread * parent);



/* ---------------------------------------------------------------------
 gigou_kernel_thread_linkThread()
 ---------------------------------------------------------------------
 Initialise les données du thread
 ---------------------------------------------------------------------
 E : le thread, la fonction que le thread va executer, ses arguments
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_thread_linkThread(gigou_Thread * thread,
                                                                           void (*pf_func) (void*),
                                                                           void * arg);



/* ---------------------------------------------------------------------
 gigou_kernel_thread_start()
 ---------------------------------------------------------------------
 Démarre le thread
 ---------------------------------------------------------------------
 E : le thread
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_thread_start(gigou_Thread * thread);




/* ---------------------------------------------------------------------
 gigou_kernel_thread_stop()
 ---------------------------------------------------------------------
 Arrète le thread et celui de tous ses enfants en trade-safe (on attend 
 que tous les thread soient finis)
 ---------------------------------------------------------------------
 E : le thread
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_thread_stop(gigou_Thread * thread);



/* ---------------------------------------------------------------------
 gigou_kernel_thread_destroyThread()
 ---------------------------------------------------------------------
 Supprime le thread, désalloue la mémoire
 ---------------------------------------------------------------------
 E : le thread
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_thread_destroyThread(gigou_Thread * thread);




/*
 *******************************************************
 ******************* PRIVATE FONCTION ******************
 *******************************************************
 */



/* ---------------------------------------------------------------------
 __gigou_kernel_thread_addOneChildAtThread()
 ---------------------------------------------------------------------
 Supprime le thread, désalloue la mémoire
 ---------------------------------------------------------------------
 E : le thread père, le thread fils
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI __gigou_kernel_thread_addOneChildAtThread(gigou_Thread * thread,
                                                                            gigou_Thread * child);



/* ---------------------------------------------------------------------
 __gigou_kernel_thread_unixCreateThread()
 ---------------------------------------------------------------------
 Créé les éléments du thread qui font parties du pthread
 ---------------------------------------------------------------------
 E : le thread
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI __gigou_kernel_thread_unixCreateThread(gigou_Thread * thread);



/* ---------------------------------------------------------------------
 __gigou_kernel_thread_win32CreateThread()
 ---------------------------------------------------------------------
 Créé les éléments du thread qui font parties de windows
 ---------------------------------------------------------------------
 E : le thread
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI __gigou_kernel_thread_win32CreateThread(gigou_Thread * thread);



/* ---------------------------------------------------------------------
 __gigou_kernel_thread_isStopped()
 ---------------------------------------------------------------------
 Créé les éléments du thread qui font parties de windows
 ---------------------------------------------------------------------
 E : le thread
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI UINT32 __GigouUnixAPI __gigou_kernel_thread_isStopped(gigou_Thread * thread);






#endif