#ifndef GIGOU_KERNEL_MEM_PILE_H
#define GIGOU_KERNEL_MEM_PILE_H

#include "gigou_init.h"

typedef struct gigou_MemoryPile gigou_MemoryPile;


/* -----------------------------------------------------------
 struct gigou_MemoryPile
 -----------------------------------------------------------
 Structure d'une pile mémoire, elle contient tous les blocs 
 mémoires que l'on distribue au fil du programme.
 Si a un moment il manque de la mémoire dans la pile, lorsque 
 l'on demande de la place, la pile réalloue GIGOU_MEM_NBR_REALLOC
 nombre d'élément.
 -----------------------------------------------------------
 v_nbrElement : nombre d'élément courant dans la pile
 
 v_nbrElementMax : nombre de place mémoire alloué dans da_stackElement
 
 da_stackElement : la pile
 
 p_topElement : sommet de la pile qu'on renvoie lors d'un appel de pop
 
 */
__GigouWinAPI struct __GigouUnixAPI gigou_MemoryPile{
    
    UINT32 v_nbrElement;
    
    UINT32 v_nbrElementMax;
    
    UINT32 v_val;
    
    void ** da_stackElement;
    
    void * p_topElement;
    
    
};


/*
 ******************************************************
 ******************* PUBLIC FONCTION ******************
 ******************************************************
 */




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



/* ---------------------------------------------------------------------
 gigou_kernel_mem_pile_getSizeMemory()
 ---------------------------------------------------------------------
 Renvoie la taille de la mémoire en octet disponible et utilisé dans la pile
 ---------------------------------------------------------------------
 E : la pile
 S : la taille
 --------------------------------------------------------------------- */
__GigouWinAPI UINT32 __GigouUnixAPI gigou_kernel_mem_pile_getSizeMemory(gigou_MemoryPile * pile);



/* ---------------------------------------------------------------------
 gigou_kernel_mem_pile_getSizeMemoryFree()
 ---------------------------------------------------------------------
 Renvoie la taille de la mémoire en octet disponible dans la pile
 ---------------------------------------------------------------------
 E : la pile
 S : la taille
 --------------------------------------------------------------------- */
__GigouWinAPI UINT32 __GigouUnixAPI gigou_kernel_mem_pile_getSizeMemoryFree(gigou_MemoryPile * pile);



/* ---------------------------------------------------------------------
 gigou_kernel_mem_pile_getSizeMemoryUsed()
 ---------------------------------------------------------------------
 Renvoie la taille de la mémoire en octet utilisé dans la pile
 ---------------------------------------------------------------------
 E : la pile
 S : la taille
 --------------------------------------------------------------------- */
__GigouWinAPI UINT32 __GigouUnixAPI gigou_kernel_mem_pile_getSizeMemoryUsed(gigou_MemoryPile * pile);




/*
 *******************************************************
 ******************* PRIVATE FONCTION ******************
 *******************************************************
 */




/* ---------------------------------------------------------------------
 __gigou_kernel_mem_pile_canPopElement()
 ---------------------------------------------------------------------
 Renvoie 1 si on peut prendre un élément, 0 sinon
 ---------------------------------------------------------------------
 E : la pile
 S : le boolean
 --------------------------------------------------------------------- */
__GigouWinAPI UINT32  __GigouUnixAPI __gigou_kernel_mem_pile_canPopElement(gigou_MemoryPile * pile);



/* ---------------------------------------------------------------------
 __gigou_kernel_mem_pile_canPushElement()
 ---------------------------------------------------------------------
 Renvoie 1 si on peut prendre un élément, 0 sinon
 ---------------------------------------------------------------------
 E : la pile
 S : le boolean
 --------------------------------------------------------------------- */
__GigouWinAPI UINT32  __GigouUnixAPI __gigou_kernel_mem_pile_canPushElement(gigou_MemoryPile * pile);



/* ---------------------------------------------------------------------
 __gigou_kernel_mem_pile_popElement()
 ---------------------------------------------------------------------
 Enelve l'élément au sommet de la pile et le renvoie
 ---------------------------------------------------------------------
 E : la pile
 S : l'élément
 --------------------------------------------------------------------- */
__GigouWinAPI void *  __GigouUnixAPI __gigou_kernel_mem_pile_popElement(gigou_MemoryPile * pile);



/* ---------------------------------------------------------------------
 __gigou_kernel_mem_pile_pushElement()
 ---------------------------------------------------------------------
 Rajoute un élément au sommet de la pile
 ---------------------------------------------------------------------
 E : la pile, l'élément
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void  __GigouUnixAPI __gigou_kernel_mem_pile_pushElement(gigou_MemoryPile * pile,
                                                                       void * element);



/* ---------------------------------------------------------------------
 __gigou_kernel_mem_pile_reallocPile()
 ---------------------------------------------------------------------
 Réalloue de la mémoire si la pile n'a plus de place
 ---------------------------------------------------------------------
 E : la pile
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void  __GigouUnixAPI __gigou_kernel_mem_pile_reallocPile(gigou_MemoryPile * pile);



/* ---------------------------------------------------------------------
 __gigou_kernel_mem_pile_preAlloc()
 ---------------------------------------------------------------------
 Pré-alloue de la mémoire dans la pile
 ---------------------------------------------------------------------
 E : la pile, nbr de place
 S : 1 si réussite, 0 sinon
 --------------------------------------------------------------------- */
__GigouWinAPI UINT32  __GigouUnixAPI __gigou_kernel_mem_pile_preAlloc(gigou_MemoryPile * pile,
                                                                       UINT32 nbr);



/* ---------------------------------------------------------------------
 __gigou_kernel_mem_pile_display()
 ---------------------------------------------------------------------
 Affiche la pile, fonction de dev
 ---------------------------------------------------------------------
 E : la pile
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void  __GigouUnixAPI __gigou_kernel_mem_pile_display(gigou_MemoryPile * pile);




#endif
