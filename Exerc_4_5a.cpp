/* ====================================
File name: exerc_4_5a.cpp
Date: 2016-02-17
Group Number: 4
Members that contributed:
Mariam Mahoob
Mariam Jobe
Linhang Nie
Demonstration code: [<13650>]
Important, No code no bonus!
====================================== */
unsigned char check_keyboard(void){
    unsigned char* outport = 0x09C0;
    unsigned char* inport = 0x09C1;
    int i, j;

    while (1){
        for (int i = 0; i < 4; ++i) {
            *outport = 1 << i; // set ith bit of inport 1;

            for (int j = 3; j >=0 ; --j) {
                if(!(*inport & (1 << j))) // check if the jth bit of inport is 1;
                    printf("%X", (i+1)*4 - j); //print out key value i * 4 + 4 - j
            }
        }
    }

}