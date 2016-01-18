#ifndef GIGOU_KERNEL_MEM_TAS_H
#define GIGOU_KERNEL_MEM_TAS_H

#include "gigou_init.h"

#include "gigou_kernel_mem_pile.h"

typedef struct gigou_MemoryTas gigou_MemoryTas;

__GigouWinAPI struct __GigouUnixAPI gigou_MemoryTas{
    
    UINT32 v_val;
    
    gigou_MemoryPile * p_pile;
    
};



/*
 ******************************************************
 ******************* PUBLIC FONCTION ******************
 ******************************************************
 */




/* ---------------------------------------------------------------------
 gigou_kernel_mem_tas_createTas()
 ---------------------------------------------------------------------
 Retourne un tas memoire initialise a NULL. ---------------------------------------------------------------------
 E : -
 S : le tas memoire
 --------------------------------------------------------------------- */
__GigouWinAPI gigou_MemoryTas * __GigouUnixAPI gigou_kernel_mem_tas_createTas();



/* ---------------------------------------------------------------------
 gigou_kernel_mem_tas_createTas()
 ---------------------------------------------------------------------
 Retourne un tas memoire initialise a NULL. ---------------------------------------------------------------------
 E : -
 S : le tas memoire
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_tas_destroyTas(gigou_MemoryTas * tas);



/*
 *******************************************************
 ******************* PRIVATE FONCTION ******************
 *******************************************************
 */




/* ---------------------------------------------------------------------
 __gigou_kernel_mem_tas_stackMemoryAligned()
 ---------------------------------------------------------------------
 Alloue toutes les cases mémoires alignés sur des multiples de 16
 (normalement ...)
 ---------------------------------------------------------------------
 E : le tas
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI __gigou_kernel_mem_tas_stackMemoryAligned(gigou_MemoryTas * tas);


#endif
