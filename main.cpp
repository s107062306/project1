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

//
void clear(int ** map){
    for(int i = 0; i < row+4; i++)
    {
        int done = 1;
        for(int j = 0 ; j < col; j++)
        {
            if(map[i][j] == 0)
            {
                done = 0;
                break;
            }
        }
        if(done)
        {
            for(int j = i; j < row + 5 - i; j++)
            {
                for(int k = 0; k < col; k++)
                {
                    map[j][k] = map[j+1][k];
                }
            }
        }
        else
        {
            continue;
        }
    }
};

void drop(int A[4][4], int loc, int ** map)
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
    }
};

int main(void)
{
    ifstream fin("tetris.data");
    ofstream fout("tetris.final");
    fin >>row >>col;
    int **map = new int *[row+4];
    for(int i = 0; i < row+4; i++)
    {
        map[i] = new int [col];
    }
    for(int i = 0; i < row+4; i++)
    {
        for(int j = 0; j < col; j++)
        {
            map[i][j] = 0;
        }
    }
    char cmd[4];
    fin >> cmd;
    int loc;//the location of the block
    while(cmd[0]!='E')
    {
        fin >> loc;
        loc = loc - 1;
        if(cmd[0] == 'T')
        {
            if(cmd[1] == '1')
            {
                drop(T1, loc, map);
            }
            else if(cmd[1] == '2')
            {
                drop(T2, loc, map);
            }
            else if(cmd[1] == '3')
            {
                drop(T3, loc, map);
            }
            else if(cmd[1] == '4')
            {
                drop(T4, loc, map);
            }
        }
        else if(cmd[0] == 'L')
        {
            if(cmd[1] == '1')
            {
                drop(L1, loc, map);
            }
            else if(cmd[1] == '2')
            {
                drop(L2, loc, map);
            }
            else if(cmd[1] == '3')
            {
                drop(L3, loc, map);
            }
            else if(cmd[1] == '4')
            {
                drop(L4, loc, map);
            }
        }
        else if(cmd[0] == 'J')
        {
            if(cmd[1] == '1')
            {
                drop(J1, loc, map);
            }
            else if(cmd[1] == '2')
            {
                drop(J2, loc, map);
            }
            else if(cmd[1] == '3')
            {
                drop(J3, loc, map);
            }
            else if(cmd[1] == '4')
            {
                drop(J4, loc, map);
            }
        }
        else if(cmd[0] == 'S')
        {
            if(cmd[1] == '1')
            {
                drop(S1, loc, map);
            }
            else if(cmd[1] == '2')
            {
                drop(S2, loc, map);
            }
        }
        else if(cmd[0] == 'Z')
        {
            if(cmd[1] == '1')
            {
                drop(Z1, loc, map);
            }
            else if(cmd[1] == '2')
            {
                drop(Z2, loc, map);
            }
        }
        else if(cmd[0] == 'I')
        {
            if(cmd[1] == '1')
            {
                drop(I1, loc, map);
            }
            else if(cmd[1] == '2')
            {
                drop(I2, loc, map);
            }
        }
        else if(cmd[0] == 'O')
        {
            drop(O, loc, map);
        }
        if(!term)break;
        clear(map);
        continue;
    }
    fout
}