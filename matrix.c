#include "matrix.h"//the header file of this file. 
#include "stdbool.h"//because bools are nice. 
#include <stdio.h>//for file opens.
#include "linkedlistint.h"
#include "validint.h"
#include "linkedlistintpointer.h"
#include "numbers.h"




typedef struct {
    bool filedone;
    FILE* fp;
    int length;
    bool error;
    int* values;//isnt being used yet. 
} rowinfo_t;//lengthofrow uses this one to communicate to parsematrix.



//find the length of the row. 
//Do this a nunch of times. 
rowinfo_t lengthofrow(FILE* fp){


    /*I will be engineering the future of this function here. 
    Things have to be checked. 
    Two things can be checked without any other things: \n and EOF. 
    These should be safe and easy to work with. 
    
    
    */
    
    rowinfo_t retInfo;//I havent put any information in here yet. 
    retInfo.error=false;
    retInfo.filedone=false;
    retInfo.length=0;
    bool expectingspace=true;
    int storedint;
    num_t storednum;
    void* linkedlist;
    
    
    while(true){
        char currletter=fgetc(fp);
        //My guess is that the issue is here already. 
        
        if(currletter==EOF){
            retInfo.filedone=true;
            if(!expectingspace){
                linkedlist=addToIntList(storedint,linkedlist,false);
            }
            break;
        }
        if(currletter=='\n'){
                //This is a datastructure that I should get. 
            if(!expectingspace){
                linkedlist=addToIntList(storedint,linkedlist,false);
            }
            
           
            break;
        }

        //There are four conditions...
        validint_t vi=maybeint(currletter);//still cursed that I use the pointer but I havent fixed yet. 

        if(expectingspace){

            if(currletter==' '){
                

                continue;
            }
            if(vi.valid){
                //Now we have to start to write a number. 
               
                retInfo.length+=1;
                expectingspace=false;
                //This one is going to be changed very soon...
                storedint=vi.value;
                
                continue;
            }
            printf("was expecting space and something dumb came along\n");
            retInfo.error=true;
            continue;


        }
        if(!expectingspace){
            if(vi.valid){
                storedint*=10;
                storedint+=vi.value;
                printf("the number is now %d\n",storedint);
                continue;
            }
            if(currletter==' '){
                linkedlist= addToIntList(storedint,linkedlist,false);
                expectingspace=true;
                continue;
            }
            if(currletter=='/'){
                printf("we are trying to parse a num_t now, which is epic but I dont have coverage for it yet.\n");
                continue;
            }
            //Shouldn't get here. 
            printf("was working with a num and something dumb happened!");
            retInfo.error=true;
            continue;
        }

        printf("something wrong is happening right now\n");
        printf("im working on the char %c\n",currletter);
        printf("is has the int value of %d\n",(int)currletter);
        
        retInfo.error=true;
        return retInfo; 
        
    
    }
    if(retInfo.error){
        printf("there is an error in the matrix\n");
    }

    retInfo.values=getIntsOut(linkedlist,retInfo.length,false);
    return retInfo;


}

matrix_t parsematrix(FILE *fp){
    matrix_t m;
    m.height=0;
    m.len=-1;
    
    //parse row a bunch of times. 
    /*tasks:
        1. Find a bunch of ints and make sure that they are the same ones. 
        2. Know how many they are. 
        3. Re-set everything and get a hold of the ints after I have malloc-ed. 
    */

    //for solving 1. 
    void* linkedlistofpointer;

    m.valid=true;
    while(true){
        rowinfo_t ri=lengthofrow(fp);
        
        
        if(ri.error){
            printf("error with the matrix!\n");
            m.valid=false;
            return m;
        }//from here on we know that there is no error. 



        if(ri.length==0){
            printf("found an empty row!\n");
            continue;
        }
        if(ri.length!=0){//I dont actually have to test this because it gets checked above and continue fixes it.
            m.height+=1; 
            
            linkedlistofpointer=addToPointerList(ri.values,linkedlistofpointer,false);
            //This one has to be here because the length isnt zero. 
            
            //This is where I add to linkedlist. 
            
            


            if(m.len==-1){
                m.len=ri.length;
                continue;
            }
            else if(m.len!=ri.length){
                printf("invalid because a row had %d numbers while standard is %d\n",m.len,ri.length);
                m.valid==false;
                return m;
                //Here I should also free a bunch of shit but I havent. 
            }
            printf("I got to somewhere I shouldn't\n");
        }
        if(ri.filedone){
            break;
        }


        //This one should be good. Who the fuck knows though. 
        //At some point I should learn to make tests. 

    }
    m.p=getPointersOut(linkedlistofpointer,m.height,false);

    printf("do I have the right first numbers?\n");
    int **resultasint = m.p;
    for (int i = 0; i < m.height; i++){
        
        int* ip=resultasint[i];//This should be the intpointer.
        for(int j=0;j<m.len;j++){
            printf("%d ",ip[j]);
            //This will probably not work.
        }
        printf("\n");

    }
    printf("\n");

    return m;
    
}

void printmatrix(matrix_t m){
    int **resultasint = m.p;
    for (int i = 0; i < m.height; i++)
    {

        int *ip = resultasint[i]; // This should be the intpointer.
        for (int j = 0; j < m.len; j++)
        {
            printf("%d ", ip[j]);
            // This will probably not work.
        }
        printf("\n");
    }
    printf("\n");
}