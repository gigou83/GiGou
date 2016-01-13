#ifndef GIGOU_KERNEL_MEM_PILE_H
#define GIGOU_KERNEL_MEM_PILE_H

#include "gigou_init.h"

typedef struct gigou_MemoryPile gigou_MemoryPile;

__GigouWinAPI struct __GigouUnixAPI gigou_MemoryPile{
    
    UINT32 v_nbrElement;
    void ** da_stackElement;
    void * p_topElement;
    
};

/* ---------------------------------------------------------------------
 gigou_kernel_mem_pile_createPile()
 ---------------------------------------------------------------------
 Retourne un pile memoire initialise a NULL.
 ---------------------------------------------------------------------
 E : -
 S : la pile
 --------------------------------------------------------------------- */
__GigouWinAPI gigou_MemoryPile * __GigouUnixAPI gigou_kernel_mem_pile_createPile();



/* ---------------------------------------------------------------------
 gigou_kernel_mem_pile_AllocPile()
 ---------------------------------------------------------------------
 La pile vient d'etre cree, cette fonction defini donc le nombre
 de cases memoires et les alloues en mettant les donnees de la pile
 a jour
 ---------------------------------------------------------------------
 E : la pile, nbr d'element, taille des elements
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pile_AllocPile(gigou_MemoryPile * pile,
                                                                  UINT32 nbr,
                                                                  UINT32 size);


/* ---------------------------------------------------------------------
 gigou_kernel_mem_pile_DeallocPile()
 ---------------------------------------------------------------------
 On supprime la pile ainsi que toutes les cases memoires allouees
 dedans
 ---------------------------------------------------------------------
 E : la pile
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pile_DeallocPile(gigou_MemoryPile * pile);


                                                                  
/* ---------------------------------------------------------------------
 gigou_kernel_mem_pile_destroyPile()
 ---------------------------------------------------------------------
 Supprime la pile
 ---------------------------------------------------------------------
 E : la pile
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pile_destroyPile(gigou_MemoryPile * pile);

#endif
