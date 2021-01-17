#ifndef DESIGN_H_
#define DESIGN_H_

#define A 0x0A
#define B 0x0B
#define C 0x0C
#define D 0x0D
#define E 0x0E
#define F 0x0F

const int char_target1[5][5] =
{
    {7,0,7,0,7},
    {0,7,7,7,0},
    {7,7,0,7,7},
    {0,7,7,7,0},
    {7,0,7,0,7}
};

const int char_target2[5][5] =
{
    {0,0,7,0,0},
    {0,7,7,7,0},
    {7,7,7,7,7},
    {0,7,7,7,0},
    {0,0,7,0,0}
};

const int char_target3[3][3] =
{
    {0,7,0},
    {7,7,7},
    {0,7,0},
};

const int char_target4[2][2] =
{
    {7,7},
    {7,7}
};

const int char_bullet1[2][4] =
{
    {1,1,1,1},
    {1,1,1,1}
};

const int char_bullet2[2][4] =
{
    {4,4,4,4},
    {4,4,4,4}
};

const int char_ship1[15][15] =
{
    {0,0,0,0,0,0,0,4,1,1,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,0,8,8,8,8,8,0,0,0,0},
    {0,0,8,8,8,8,8,C,C,8,8,8,0,0,0},
    {0,0,8,8,8,8,8,C,C,C,8,8,0,C,4},
    {C,8,8,8,8,8,8,C,C,C,8,8,0,0,0},
    {0,0,8,8,8,8,8,C,C,C,8,8,0,0,0},
    {0,0,8,8,8,8,8,C,C,8,8,8,0,C,4},
    {0,0,0,0,0,0,8,8,8,8,8,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},
    {0,0,0,0,0,0,0,4,1,1,1,1,1,0,0}
};

const int char_ship2[15][15] =
{
    {0,0,4,4,4,4,4,1,0,0,0,0,0,0,0},
    {0,0,0,0,4,4,0,0,0,0,0,0,0,0,0},
    {0,0,0,4,4,4,4,4,4,4,0,0,0,0,0},
    {0,0,0,4,4,4,4,4,4,4,0,0,0,0,0},
    {0,0,0,0,8,8,8,8,8,0,0,0,0,0,0},
    {1,B,0,8,8,8,C,C,8,8,8,8,8,0,0},
    {0,0,0,8,8,C,C,C,8,8,8,8,8,0,0},
    {0,0,0,8,8,C,C,C,8,8,8,8,8,8,B},
    {0,0,0,8,8,C,C,C,8,8,8,8,8,0,0},
    {1,B,0,8,8,8,C,C,8,8,8,8,8,0,0},
    {0,0,0,0,8,8,8,8,8,0,0,0,0,0,0},
    {0,0,0,4,4,4,4,4,4,4,0,0,0,0,0},
    {0,0,0,4,4,4,4,4,4,4,0,0,0,0,0},
    {0,0,0,0,4,4,0,0,0,0,0,0,0,0,0},
    {0,0,4,4,4,4,4,1,0,0,0,0,0,0,0}
};

const int char_ship1_2[15][15] =
{
    {0,0,0,0,0,0,0,4,1,1,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0},
    {0,0,1,1,1,1,1,7,7,1,1,1,0,0,0},
    {0,0,1,1,1,1,1,7,7,7,1,1,0,C,4},
    {C,1,1,1,1,1,1,7,7,7,1,1,0,0,0},
    {0,0,1,1,1,1,1,7,7,7,1,1,0,0,0},
    {0,0,1,1,1,1,1,7,7,1,1,1,0,C,4},
    {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},
    {0,0,0,0,0,0,0,4,1,1,1,1,1,0,0}
};

const int char_ship2_2[15][15] =
{
    {0,0,4,4,4,4,4,1,0,0,0,0,0,0,0},
    {0,0,0,0,4,4,0,0,0,0,0,0,0,0,0},
    {0,0,0,4,4,4,4,4,4,4,0,0,0,0,0},
    {0,0,0,4,4,4,4,4,4,4,0,0,0,0,0},
    {0,0,0,0,4,4,4,4,4,0,0,0,0,0,0},
    {1,B,0,4,4,4,7,7,4,4,4,4,4,0,0},
    {0,0,0,4,4,7,7,7,4,4,4,4,4,0,0},
    {0,0,0,4,4,7,7,7,4,4,4,4,4,4,B},
    {0,0,0,4,4,7,7,7,4,4,4,4,4,0,0},
    {1,B,0,4,4,4,7,7,4,4,4,4,4,0,0},
    {0,0,0,0,4,4,4,4,4,0,0,0,0,0,0},
    {0,0,0,4,4,4,4,4,4,4,0,0,0,0,0},
    {0,0,0,4,4,4,4,4,4,4,0,0,0,0,0},
    {0,0,0,0,4,4,0,0,0,0,0,0,0,0,0},
    {0,0,4,4,4,4,4,1,0,0,0,0,0,0,0}
};

#endif /* DESIGN_H_ */