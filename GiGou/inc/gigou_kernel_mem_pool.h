#ifndef GIGOU_KERNEL_MEM_POOL_H
#define GIGOU_KERNEL_MEM_POOL_H

#include "gigou_init.h"

#include "gigou_kernel_mem_tas.h"

typedef struct gigou_MemoryPool gigou_MemoryPool;


/* -----------------------------------------------------------
 struct gigou_MemoryPool
 -----------------------------------------------------------
 Structure d'un  pool mémoire, il contient un tas principale
 et d'autres structures pour allouer de la mémoire quand le tas
 n'est pas la bonne solution
 -----------------------------------------------------------
 da_tas : liste de tous les éléments du tas, on pourrais y acceder
 en utilisant le système pere fils gauche fils droit, mais la 
 désallocation mémoire sera plus sur de cette manière, au niveau
 de l'allocation on utilisera l'architecture pere fils pour acceder
 au élements du pool plutot que de parcourir ce tableau (ce qui serait
 trop long), en gros il est utile uniquement pour la désalocation
 
 da_maxSizeTas : on donne la valeur des tailles des cases mémoires qu'on
 allouera dans chaque élement du tas
 
 p_tas : le premier élément du tas
 
 v_nbrTas : nombre d'élemnt dans le tas
 
 maxSize : la plus grande taille de case mémoire du pool

*/
__GigouWinAPI struct __GigouUnixAPI gigou_MemoryPool{
    
    
    /*
        Le tas
     */
    
    gigou_MemoryTas ** da_tas;
    
    UINT32 * da_maxSizeTas;
    
    gigou_MemoryTas * p_tas;
    
    UINT32 v_nbrTas;

    UINT32 maxSize;
    
    
    /*
        Mémoire auxiliaire
     */
    
    
    
    /*
        Autres
     */
    
    UINT32 v_identity;
    
};

/*
 ******************************************************
 ******************* PUBLIC FONCTION ******************
 ******************************************************
 */




/* ---------------------------------------------------------------------
 gigou_kernel_mem_pool_createPool()
 ---------------------------------------------------------------------
 Retourne un pool memoire initialise a NULL, il faut initialiser sois
 meme les donnees.
 ---------------------------------------------------------------------
 E : numero d'index du pool dans le kernel
 S : le pool memoire
 --------------------------------------------------------------------- */
__GigouWinAPI gigou_MemoryPool * __GigouUnixAPI gigou_kernel_mem_pool_createPool(UINT32 index);



/* ---------------------------------------------------------------------
 gigou_kernel_mem_pool_setMaxSize()
 ---------------------------------------------------------------------
 Setter pour maxSize
 ---------------------------------------------------------------------
 E : le pool, la plus grande taille de case mémoire à allouer exemple : 1024
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pool_setMaxSize(gigou_MemoryPool * pool,
                                                                   UINT32 size);



/* ---------------------------------------------------------------------
 gigou_kernel_mem_pool_initPool()
 ---------------------------------------------------------------------
 Initialise le pool, attention avant d'appeller cette fonction il faut 
 mettre une valeur à sizeMax => utiliser le setter prédéfinis
 ---------------------------------------------------------------------
 E : pool
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pool_initPool(gigou_MemoryPool*);



/* ---------------------------------------------------------------------
 gigou_kernel_mem_pool_getMemoryUsed()
 ---------------------------------------------------------------------
 Renvoie toute la mémoire utilisé par ce pool
 ---------------------------------------------------------------------
 E : pool
 S : nombre d'octets utilisés
 --------------------------------------------------------------------- */
__GigouWinAPI UINT32 __GigouUnixAPI gigou_kernel_mem_pool_getMemoryUsed(gigou_MemoryPool*pool);



/* ---------------------------------------------------------------------
 gigou_kernel_mem_pool_destroyPool()
 ---------------------------------------------------------------------
 Supprime le pool
 ---------------------------------------------------------------------
 E : pool
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pool_destroyPool(gigou_MemoryPool*);




/*
 *******************************************************
 ******************* PRIVATE FONCTION ******************
 *******************************************************
 */


/* ---------------------------------------------------------------------
 gigou_kernel_mem_pool_initArrayTas()
 ---------------------------------------------------------------------
 Initialise les tas en fonction de leurs tailles
 ---------------------------------------------------------------------
 E : 1) Le pool sur lequel on veut initialiser les tableaux
 2) Un tableau de taille maximale que chaque tas peut recevoir
 3) Le nombre de tas
 S : -
 --------------------------------------------------------------------- */
__GigouWinAPI void __GigouUnixAPI __gigou_kernel_mem_pool_initArrayTas(gigou_MemoryPool*,
                                                                       UINT32*,
                                                                       UINT8);





/* ---------------------------------------------------------------------
 gigou_kernel_mem_pool_generateArrayTasMaxSize()
 ---------------------------------------------------------------------
 Genere le tableau qu'il faut envoyer à initArrayTas en fonction de
 l'alignement memoire choisi
 ---------------------------------------------------------------------
 E : la plus grande taille de case mémoire à allouer exemple : 1024,
     on envoie un pointeur sur le nombre d'élements du tableau du pool
     pour remplire cette donnée
 S : Le tableau à envoyer à initArrayTas
 --------------------------------------------------------------------- */
__GigouWinAPI UINT32 * __GigouUnixAPI __gigou_kernel_mem_pool_generateArrayTasMaxSize(UINT32 size,
                                                                                      UINT32 * nbr);


#endif