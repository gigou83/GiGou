#include "../../../inc/gigou_kernel_mem_pile.h"



/*
 ******************************************************
 ******************* PUBLIC FONCTION ******************
 ******************************************************
 */




__GigouWinAPI gigou_MemoryPile * __GigouUnixAPI gigou_kernel_mem_pile_createPile(){
    
    gigou_MemoryPile * buffer = (gigou_MemoryPile*)malloc(sizeof(gigou_MemoryPile));
    
    if(buffer == NULL){
        
        __GigouLog("Can't allocate memory for this pile")
        exit(EXIT_FAILURE);
        
    }
    
    
    buffer->v_val = 0;
    buffer->v_nbrElement = 0;
    buffer->v_nbrElementMax = 0;
    buffer->p_topElement = NULL;
    buffer->da_stackElement = NULL;
    
    return buffer;
    
}

__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pile_AllocPile(gigou_MemoryPile * pile, UINT32 nbr,UINT32 size){
    
    int i = 0;
    
    if(nbr > 0){
        
        if(pile->v_nbrElement == 0 && pile->p_topElement == NULL && pile->da_stackElement == NULL){
            
            pile->v_nbrElement = nbr;
            pile->v_nbrElementMax = nbr;
            pile->v_val = size;
            
            pile->da_stackElement = malloc(nbr*sizeof(void*));
            
            if(pile->da_stackElement == NULL){
                
                __GigouError("Can't allocate memory for this pile")
                exit(EXIT_FAILURE);
                
            }
            
            for(i=0;i< __GigouCastInt nbr;i++){
                                
                *(pile->da_stackElement + i) = (void*)malloc(size*sizeof(char));
                
                if(*(pile->da_stackElement + i) == NULL){
                    
                    __GigouError("Can't allocate memory for this pile")
                    exit(EXIT_FAILURE);
                    
                }
                
            }
            
            pile->p_topElement = *(pile->da_stackElement + i - 1);
            
        }else{
            
            __GigouWarning("Don't alloc pile which was yet allocated")
            
        }
        
    }
    
}

__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pile_DeallocPile(gigou_MemoryPile * pile){
    
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
            
        }else{
            
            __GigouErrorArg("Argument error pile %lu",pile->v_val)
            
        }
        
    }
    
}


__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pile_destroyPile(gigou_MemoryPile * pile){
    
    if(pile != NULL){
        
        if(pile->v_nbrElement > 0){
            
            gigou_kernel_mem_pile_DeallocPile(pile);
            
        }
        
        free(pile);
        
        pile = NULL;
        
    }else{
        
        __GigouError("This pile not exist")
        
    }
    
}


__GigouWinAPI UINT32 __GigouUnixAPI gigou_kernel_mem_pile_getSizeMemory(gigou_MemoryPile * pile){
    
    UINT32 size = 0;
    
    if(pile != NULL){
        
        return pile->v_val * pile->v_nbrElementMax;
        
    }else{
        
        __GigouError("This pile doesn't exist")
        
    }
    
    return size;
    
}



__GigouWinAPI UINT32 __GigouUnixAPI gigou_kernel_mem_pile_getSizeMemoryFree(gigou_MemoryPile * pile){
    
    UINT32 size = 0;
    
    if(pile != NULL){
        
        return pile->v_val * pile->v_nbrElement;
        
    }else{
        
        __GigouError("This pile doesn't exist")
        
    }
    
    return size;
    
}


__GigouWinAPI UINT32 __GigouUnixAPI gigou_kernel_mem_pile_getSizeMemoryUsed(gigou_MemoryPile * pile){
   
    return gigou_kernel_mem_pile_getSizeMemory(pile) - gigou_kernel_mem_pile_getSizeMemoryFree(pile);
    
}


/*
 *******************************************************
 ******************* PRIVATE FONCTION ******************
 *******************************************************
 */


__GigouWinAPI UINT32  __GigouUnixAPI __gigou_kernel_mem_pile_canPopElement(gigou_MemoryPile * pile){
    
    if(pile != NULL){
        
        if(pile->v_nbrElement > 0){
            
            return 1;
            
        }else{
            
            return 0;
            
        }
        
    }else{
        
        __GigouError("This pile doesn't exist")
        
        return 0;
        
    }
    
}



__GigouWinAPI UINT32  __GigouUnixAPI __gigou_kernel_mem_pile_canPushElement(gigou_MemoryPile * pile){
    
    if(pile != NULL){
        
        if(pile->v_nbrElement < pile->v_nbrElementMax){
            
            return 1;
            
        }else{
            
            return 0;
            
        }
        
    }else{
        
        __GigouError("This pile doesn't exist")
        
        return 0;
        
    }
    
}



__GigouWinAPI void *  __GigouUnixAPI __gigou_kernel_mem_pile_popElement(gigou_MemoryPile * pile){
    
    void * buffer = NULL;
    
    if(__gigou_kernel_mem_pile_canPopElement(pile)){
        
        buffer = pile->p_topElement;
            
        pile->v_nbrElement = pile->v_nbrElement - 1;
            
        pile->p_topElement = *(pile->da_stackElement + pile->v_nbrElement - 1);
            
    }else{
            
        __gigou_kernel_mem_pile_reallocPile(pile);
            
        return __gigou_kernel_mem_pile_popElement(pile);
        
    }
    
    
    return buffer;
    
}



__GigouWinAPI void  __GigouUnixAPI __gigou_kernel_mem_pile_pushElement(gigou_MemoryPile * pile,
                                                                       void * element){
    
    if(pile != NULL){
        
        if(element != NULL){
            
            if(__gigou_kernel_mem_pile_canPushElement(pile)){
                
                *(pile->da_stackElement + pile->v_nbrElement) = element;
                
                pile->p_topElement = *(pile->da_stackElement + pile->v_nbrElement);
                
                pile->v_nbrElement = pile->v_nbrElement + 1;
                
                
            }else{
                
                __GigouError("Pile is over ! Are you sure that you use pile as you do ?")
            }
            
        }else{
            
            __GigouError("Invalid argument, this element can't be NULL")
            
        }
        
    }else{
        
        __GigouError("This pile doesn't exist")
        
    }
    
    
    
}



__GigouWinAPI void  __GigouUnixAPI __gigou_kernel_mem_pile_reallocPile(gigou_MemoryPile * pile){
    
    void ** da_buffer = NULL;
    
    int i = 0;
    
    if(pile != NULL){
        
        if(pile->v_nbrElement == 0 && pile->v_val > 0){
            
            pile->v_nbrElementMax = pile->v_nbrElementMax + GIGOU_MEM_NBR_REALLOC;
            
            da_buffer = realloc(pile->da_stackElement,pile->v_nbrElementMax * sizeof(void*));
            
            if(da_buffer == NULL){
                
                __GigouError("Can't realloc memory on this pile")
                
                exit(EXIT_FAILURE);
                
            }
            
            
            pile->da_stackElement = da_buffer;
            
            da_buffer = NULL;
            
            
            for(i=0;i<GIGOU_MEM_NBR_REALLOC;i++){
                
                *(pile->da_stackElement + i) = (void*)malloc(pile->v_val * sizeof(char));
                
                if(*(pile->da_stackElement + i) == NULL){
                    
                    __GigouError("Can't realloc memory on this pile")
                    
                    exit(EXIT_FAILURE);
                    
                }
                
            }
            
            
            pile->p_topElement = *(pile->da_stackElement + i - 1);
            
            pile->v_nbrElement = GIGOU_MEM_NBR_REALLOC;
            
        }else{
            
            __GigouError("Invalid argument")
            
        }
        
    }else{
        
        __GigouError("This pile doesn't exist")
        
    }
}


__GigouWinAPI UINT32  __GigouUnixAPI __gigou_kernel_mem_pile_preAlloc(gigou_MemoryPile * pile,
                                                                      UINT32 nbr){
    
    void ** buffer = NULL;
    
    int i = 0;
    
    if(pile != NULL){
        
        if(nbr > 0){
            
            pile->v_nbrElementMax = pile->v_nbrElementMax + nbr;
            
            buffer = realloc(pile->da_stackElement, pile->v_nbrElementMax * sizeof(void*));
            
            if(buffer == NULL){
                
                __GigouError("Can't realloc memory on pile")
                
                exit(EXIT_FAILURE);
                
            }
            
            pile->da_stackElement = buffer;
            
            buffer = NULL;
            
            for(i=pile->v_nbrElement;i< __GigouCastInt pile->v_nbrElementMax;i++){
                
                *(pile->da_stackElement + i) = (void*)malloc(pile->v_val * sizeof(char));
                
                if(*(pile->da_stackElement + i) == NULL){
                    
                    __GigouError("Can't realloc memory on this pile")
                    
                    exit(EXIT_FAILURE);
                    
                }
                
            }
            
            pile->p_topElement = *(pile->da_stackElement + i - 1);
            
            pile->v_nbrElement = pile->v_nbrElement + nbr;
            
            return 1;
            
        }else{
            
            __GigouError("Invalid argument")
            
        }
        
    }else{
        
        __GigouError("This pile doesn't exist")
        
    }
    
    return 0;
    
}



__GigouWinAPI void  __GigouUnixAPI __gigou_kernel_mem_pile_display(gigou_MemoryPile * pile){
    
    int i = 0;
    
    printf("=====PILE OF %lu byte object=====\n",pile->v_val);
    
    printf("================================\n");
    
    printf("=====THERE ARE %lu ELEMENTS FREE\n",pile->v_nbrElement);
    printf("=====THERE ARE %lu TOTAL ELEMENTS \n",pile->v_nbrElementMax);
    
    printf("================================\n");
    
    for(i=0;i<__GigouCastInt pile->v_nbrElement;i++){
        
        printf("=====ELEMENT %d AT ADDR %p\n",i,*(pile->da_stackElement + i));
        
    }
    
    printf("================================\n");
    
}





