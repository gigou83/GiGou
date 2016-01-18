#ifndef GIGOU_KERNEL_H
#define GIGOU_KERNEL_H

#include "gigou_init.h"

#include "gigou_kernel_mem_pool.h"

#include "gigou_kernel_thread.h"

extern __GigouWinAPI gigou_MemoryPool * __GigouUnixAPI gigou_kernel_mem_pool_createPool();

typedef struct gigou_Kernel gigou_Kernel;
typedef struct gigou_InfosKernel gigou_InfosKernel;

/* -----------------------------------------------------------
 struct gigou_Kernel
 -----------------------------------------------------------
 Structure d'un  noyau pour l'initialisation du moteur
 -----------------------------------------------------------
 da_stackPool : liste de tous les pools mémoires disponibles sur
 ce noyau
 
 v_nbrPool : nombre de pool mémoire disponible sur ce noyau
 
 v_maxSizePool : taille max d'une case mémoire qu'on trouvera
 dans le tas exemple : 1024 donc on a 64 cases mémoires de tailles
 16 octets
 
 da_childKernel : les noyaux enfants de celui-la, ça sert par exemple
 pour l'IDE qui instancie un noyau pour fonctionner plus un noyau pour
 le jeu qu'on developpe dessus etc etc ...
 
 v_nbrChildKernel : nombre de noyau enfant
 
 v_indentityKernel : numéro d'identification de ce noyau
 
 */

struct gigou_Kernel{
    
    gigou_MemoryPool ** da_stackPool;
    UINT32 v_nbrPool;
    UINT32 v_maxSizePool;
    
    
    
    gigou_Thread ** da_stackThread;
    UINT32 v_nbrThread;
    
    
    gigou_Kernel ** da_childKernel;
    UINT32 v_nbrChildKernel;
    
    
    
    UINT32 v_indentityKernel;
    
};


struct gigou_InfosKernel{
    
    UINT32 v_nbrPool;
    
    UINT32 v_maxSizePool;
    
    UINT32 v_indentityKernel;
    
};
#endif


/*
 ******************************************************
 ******************* PUBLIC FONCTION ******************
 ******************************************************
 */





/* ---------------------------------------------------------------------
 gigou_kernel_startKernel()
 ---------------------------------------------------------------------
 Créé et initialise et renvoie un kernel
 ---------------------------------------------------------------------
 E : les infos necesaire à l'initialisation du kernel
 S : kernel
 --------------------------------------------------------------------- */
__GigouWinAPI gigou_Kernel * __GigouUnixAPI gigou_kernel_startKernel(gigou_InfosKernel * infos);



/* ---------------------------------------------------------------------
 gigou_kernel_endKernel()
 ---------------------------------------------------------------------
 Détruit et libère le kernel
 ---------------------------------------------------------------------
 E : kernel
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_endKernel(gigou_Kernel * kernel);



/* ---------------------------------------------------------------------
 gigou_kernel_getBasicInfosKernel()
 ---------------------------------------------------------------------
 Initialise les infos du kernel en fonction des préferences de bases
 ---------------------------------------------------------------------
 E : -
 S : les infos necesaire à l'initialisation du kernel
 --------------------------------------------------------------------- */
__GigouWinAPI gigou_InfosKernel * __GigouUnixAPI gigou_kernel_getBasicInfosKernel();



/* ---------------------------------------------------------------------
 gigou_kernel_destroyInfosKernel()
 ---------------------------------------------------------------------
 Supprime l'espace allouée aux infos du kernel
 ---------------------------------------------------------------------
 E : les infos
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_destroyBasicInfosKernel(gigou_InfosKernel * infos);




/* ---------------------------------------------------------------------
 gigou_kernel_alloc()
 ---------------------------------------------------------------------
 Alloue de la mémoire
 ---------------------------------------------------------------------
 E : kernel, size
 S : adresse du bloc mémoire
 --------------------------------------------------------------------- */
__GigouWinAPI void * __GigouUnixAPI gigou_kernel_alloc(gigou_Kernel * kernel,
                                                               size_t size);



/* ---------------------------------------------------------------------
 gigou_kernel_stdAlloc()
 ---------------------------------------------------------------------
 Alloue de la mémoire avec la fonction OS
 ---------------------------------------------------------------------
 E : size
 S : adresse du bloc mémoire
 --------------------------------------------------------------------- */
__GigouWinAPI void * __GigouUnixAPI gigou_kernel_stdAlloc(size_t size);




/* ---------------------------------------------------------------------
 gigou_kernel_allocInPool()
 ---------------------------------------------------------------------
 Alloue de la mémoire dans un pool précis
 ---------------------------------------------------------------------
 E : kernel, identifiant du pool, size
 S : adresse du bloc mémoire
 --------------------------------------------------------------------- */
__GigouWinAPI void * __GigouUnixAPI gigou_kernel_allocInPool(gigou_Kernel * kernel,
                                                                     UINT32 identity,
                                                                     size_t size);




/* ---------------------------------------------------------------------
 gigou_kernel_preAlloc()
 ---------------------------------------------------------------------
 Pré-alloue de la mémoire
 ---------------------------------------------------------------------
 E : kernel, size, nbr de bloc à rajouter
 S : 1 si réussite, O sinon
 --------------------------------------------------------------------- */
__GigouWinAPI UINT32 __GigouUnixAPI gigou_kernel_preAlloc(gigou_Kernel * kernel,
                                                          size_t size,
                                                          UINT32 nbr);




/* ---------------------------------------------------------------------
 gigou_kernel_preAllocInPool()
 ---------------------------------------------------------------------
 Alloue de la mémoire dans un pool précis
 ---------------------------------------------------------------------
 E : kernel, identifiant du pool, size
 S : 1 si réussite, O sinon
 --------------------------------------------------------------------- */
__GigouWinAPI UINT32 __GigouUnixAPI gigou_kernel_preAllocInPool(gigou_Kernel * kernel,
                                                                UINT32 identity,
                                                                size_t size,
                                                                UINT32 nbr);




/* ---------------------------------------------------------------------
 gigou_kernel_free()
 ---------------------------------------------------------------------
 Libère la mémoire allouée
 ---------------------------------------------------------------------
 E : kernel, adresse du bloc mémoire, taille de l'objet
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_free(gigou_Kernel * kernel,
                                                    void * addr,
                                                    size_t size);



/* ---------------------------------------------------------------------
 gigou_kernel_stdFree()
 ---------------------------------------------------------------------
 Libère la mémoire allouée avec la fonction OS
 ---------------------------------------------------------------------
 E : adresse
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_stdFree(void * addr);



/* ---------------------------------------------------------------------
 gigou_kernel_freeInPool()
 ---------------------------------------------------------------------
 Libère la mémoire allouée dans un pool précis
 ---------------------------------------------------------------------
 E : kernel, id du pool ,adresse du bloc mémoire, taille de l'objet
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_freeInPool(gigou_Kernel * kernel,
                                                          UINT32 identity,
                                                          void * addr,
                                                          size_t size);



/*
 *******************************************************
 ******************* PRIVATE FONCTION ******************
 *******************************************************
 */







