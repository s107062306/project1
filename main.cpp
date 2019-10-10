#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//name different blocks
int row, col = 0;/*the size of the game matrix*/
int term = 1; /*to decide whether the game is over or not*/
int T1[4][4]{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,0},
    {0,1,0,0}
};
int T2[4][4]{
    {0,0,0,0},
    {0,1,0,0},
    {1,1,0,0},
    {0,1,0,0}
};
int T3[4][4]{
    {0,0,0,0},
    {0,0,0,0},
    {0,1,0,0},
    {1,1,1,0}
};
int T4[4][4]{
    {0,0,0,0},
    {1,0,0,0},
    {1,1,0,0},
    {1,0,0,0}
};
int L1[4][4]{
    {0,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {1,1,0,0}
};
int L2[4][4]{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,0},
    {1,0,0,0}
};
int L3[4][4]{
    {0,0,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,1,0,0}
};
int L4[4][4]{
    {0,0,0,0},
    {0,0,0,0},
    {0,0,1,0},
    {1,1,1,0}
};
int J1[4][4]{
    {0,0,0,0},
    {0,1,0,0},
    {0,1,0,0},
    {1,1,0,0}
};
int J2[4][4]{
    {0,0,0,0},
    {0,0,0,0},
    {1,0,0,0},
    {1,1,1,0}
};
int J3[4][4]{
    {0,0,0,0},
    {1,1,0,0},
    {1,0,0,0},
    {1,0,0,0}
};
int J4[4][4]{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,0},
    {0,0,1,0}
};
int S1[4][4]{
    {0,0,0,0},
    {0,0,0,0},
    {0,1,1,0},
    {1,1,0,0}
};
int S2[4][4]{
    {0,0,0,0},
    {1,0,0,0},
    {1,1,0,0},
    {0,1,0,0}
};
int Z1[4][4]{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,0,0},
    {0,1,1,0}
};
int Z2[4][4]{
    {0,0,0,0},
    {0,1,0,0},
    {1,1,0,0},
    {1,0,0,0}
};
int I1[4][4]{
    {1,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {1,0,0,0}
};
int I2[4][4]{
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,1}
};
int O[4][4]{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,0,0},
    {1,1,0,0}
};

void drop(int A[4][4], int loc, int map[10][20])
{
    for(int i = 0; i < row;)
    {
        int fin = 1;
        for(int j = 0; j < 4 ; j++)
        {
            for(int k = 0; k < 4 ; k++)
            {
                if(A[j][k] + map[i+j][loc+k] == 2)
                {
                    fin = 0;
                }
                if(fin == 0)break; 
            }
            if(fin == 0)break;           
        }

        if(fin == 0){
            i++;
            continue;
        }

        else/*print the block on the map*/
        {
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    map[i+j][loc+k] = map[i+j][loc+k] + A[j][k];
                }
            }
            /*check game over*/
            for(int j = 0; j < col; j++)
            {
                if(map[row][j] == 1)term = 0;
            }
        }

    }/*decide location*/

    for(int i = 0 ; i < col; i++){
        if(map[row][i] == 1){
            term = 0;
            break;
        }
        else continue;
    }/*check game over*/

};


int main(void){
    ifstream fin("tetris.data");
    ofstream fout("tetris.final");
    fin >>row >>col;
    int map[row+4][col];
    for(int i = 0; i < row+4; i++){
        for(int j = 0; j < col; j++){
            map[i][j] = 0;
        }
    }
    char cmd[4];
    fin >> cmd;
    int loc;//the location of the block
    while(cmd[0]!='E'){
        fin >> loc;
        loc = loc - 1;
        if(cmd[0] == 'T'){
            if(cmd[1] == '1'){
                /*for(int i = row;i >= 0;i--){
                    if(map[i][loc]==1)stop = i+1;//the place the block should stop
                    else if(map[i+1][loc-1] == 1 || map[i+1][loc+1] == 1)stop = i+1;
                }*/
            }
            else if(cmd[1] == '2'){

            }
            else if(cmd[1] == '3'){

            }
            else if(cmd[1] == '4'){

            }
        }
    }


    
}