/* ====================================
File name: exerc_4_3a.cpp
Date: 2016-02-17
Group Number: 4
Members that contributed:
Mariam Mahoob
Mariam Jobe
Linhang Nie
Demonstration code: [<13741>]
Important, No code no bonus!
====================================== */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
void f_delay(int);
unsigned char random_inport( void);
void printport( int, int);


int main(){
    //int nr;
    unsigned char inport = 0;
    unsigned char outport = 3;
    srand(time(0));
    printport(outport, inport);

    while (1){
        inport = random_inport();

        if(inport & (1 << 3)){
            if(outport == 192){
                printport(outport, inport);
                outport = 129;
            }
            if(outport == 129){
                printport(outport,inport);
                outport= 3;
            }


            printport(outport, inport);
            outport = outport << 1;

        }

        f_delay(5);
    }
    return(0);
}


void f_delay( int tenth_sec){

    clock_t start_t, end_t;
    long int i;
    start_t = clock();
    do{
        for(i=0; i< 10000000; i++);
        end_t = clock();
    }while ((end_t - start_t) < (tenth_sec*CLOCKS_PER_SEC)/10);
    return;
}

unsigned char random_inport(void){
    unsigned char inport = 0;
    inport=  rand() % 256;
    return (inport);
}

void printport( int portvalue, int inport){
    int binchar[8], rest, j, i=0;
    rest = portvalue;
    while(rest!=0){
        binchar[i++]= rest % 2;
        rest = rest / 2;
    }
    // Fill to 8 bits
    while(i<8){
        binchar[i++]=0;
    }
    // Print bits and at the end corresponding decimal value
    printf("Inport is %d OUT", inport);
    for(j =i-1 ;j > -1;j--)
        printf(" %d", binchar[j]);
    printf(" --------Porten value = %d  \n", portvalue);
    return ;
}