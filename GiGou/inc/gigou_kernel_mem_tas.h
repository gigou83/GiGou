#ifndef GIGOU_KERNEL_MEM_TAS_H
#define GIGOU_KERNEL_MEM_TAS_H

#include "gigou_init.h"

#include "gigou_kernel_mem_pile.h"

typedef struct gigou_MemoryTas gigou_MemoryTas;

__GigouWinAPI struct __GigouUnixAPI gigou_MemoryTas{
    
    UINT32 v_val;
    
    gigou_MemoryPile * p_pile;
    
    gigou_MemoryTas * p_childRight;
    gigou_MemoryTas * p_childLeft;
    
};

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

#endif
