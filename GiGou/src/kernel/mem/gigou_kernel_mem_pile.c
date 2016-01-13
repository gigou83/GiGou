#include "../../../inc/gigou_kernel_mem_pile.h"

__GigouWinAPI gigou_MemoryPile * __GigouUnixAPI gigou_kernel_mem_pile_createPile(){
    
    __GigouLog("Creation d'une pile de memoire ")
    
    gigou_MemoryPile * buffer = (gigou_MemoryPile*)malloc(sizeof(gigou_MemoryPile));
    
    if(buffer == NULL){
        
        __GigouLog("Impossible d'allouer la memoire pour cette pile")
        exit(EXIT_FAILURE);
        
    }
    
    buffer->v_nbrElement = 0;
    buffer->p_topElement = NULL;
    buffer->da_stackElement = NULL;
    
    return buffer;
    
}

__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pile_AllocPile(gigou_MemoryPile * pile, UINT32 nbr,UINT32 size){
    
    __GigouLog("Allocation du corps de la pile")
    
    int i = 0;
    
    if(nbr > 0){
        
        if(pile->v_nbrElement == 0 && pile->p_topElement == NULL && pile->da_stackElement == NULL){
            
            pile->v_nbrElement = nbr;
            
            pile->da_stackElement = malloc(nbr*sizeof(void*));
            
            if(pile->da_stackElement == NULL){
                
                __GigouLog("Impossible d'allouer la memoire pour ce corps de pile")
                exit(EXIT_FAILURE);
                
            }
            
            for(i=0;i< __GigouCastInt nbr;i++){
                
                *(pile->da_stackElement + i) = malloc(size*sizeof(char));
                
                if(*(pile->da_stackElement + i) == NULL){
                    
                    __GigouLog("Impossible d'allouer la memoire pour cet index de corps")
                    exit(EXIT_FAILURE);
                    
                }
                
            }
            
            pile->p_topElement = *(pile->da_stackElement + i);
            
        }else{
            
            __GigouLog("WARNING : Ne pas allouer une pile deja allouee !")
            
        }
        
    }
    
}

__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pile_DeallocPile(gigou_MemoryPile * pile){
    
    __GigouLog("Liberation memoire du corps de la pile")
    
    int i = 0;
    
    if(pile->v_nbrElement > 0){
        
        if(pile->da_stackElement != NULL && pile->p_topElement != NULL){
            
            for(i=0;i< __GigouCastInt pile->v_nbrElement;i++){
                
                free(*(pile->da_stackElement + i));
                
                *(pile->da_stackElement + i) = NULL;
                
            }
            
            free(pile->da_stackElement);
            
            pile->da_stackElement = NULL;
            
            pile->p_topElement = NULL;
            
            pile->v_nbrElement = 0;
            
        }
        
    }
    
}


__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pile_destroyPile(gigou_MemoryPile * pile){
    
    __GigouLog("Liberation memoire de la pile")
    
    int i = 0;
    
    if(pile->v_nbrElement > 0){
        
        __GigouLog("Liberation memoire de l'array de la pile")
        
        for(i=0;i< __GigouCastInt pile->v_nbrElement;i++){
            
            free(*(pile->da_stackElement + i));
            
            *(pile->da_stackElement + i) = NULL;
            
        }
        
    }
    
    free(pile);
    
    pile = NULL;
    
    __GigouLog("Pile freed !")
    
}