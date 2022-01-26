#ifndef SHAPES_H
#define SHAPES_H

#include "./fillit.h"

/*
** 0b 0000 0010 0011 0001
** 0b 0000 0000 0001 1011
** 0b 0000 0000 1001 1001
** 0b 0000 0000 0110 0011
** 0b 0000 0000 0011 1001
** 0b 0000 0000 0010 0111
** 0b 0000 0001 0001 1001
** 0b 0000 0001 0011 0001
** 0b 0000 0001 1001 0001
** 0b 0000 0010 0010 0011
** 0b 0000 0001 0001 0011
** 0b 0000 0011 0001 0001
** 0b 0000 0000 0001 1101
** 0b 0000 0000 0100 0111
** 0b 0000 0000 0111 0001
** 0b 0000 0000 0001 0111
** 0b 0000 0000 0000 1111
** 0b 0001 0001 0001 0001
** 0b 0000 0000 0011 0011
*/

// int a;
// a = 0b 1000 1100 0100 0000;
// a = 0b 1101 1000 0000 0000;
// a = 0b 1001 1001 0000 0000;
// a = 0b 1100 0110 0000 0000;
// a = 0b 1110 0100 0000 0000;
// a = 0b 1001 1100 0000 0000;
// a = 0b 1000 1100 1000 0000;
// a = 0b 1001 1000 1000 0000;
// a = 0b 1100 1000 1000 0000;
// a = 0b 1000 1000 1100 0000;
// a = 0b 1000 1001 1000 0000;
// a = 0b 1100 0100 0100 0000;
// a = 0b 1110 1000 0000 0000;
// a = 0b 1000 1110 0000 0000;
// a = 0b 1110 0010 0000 0000;
// a = 0b 1011 1000 0000 0000;
// a = 0b 1111 0000 0000 0000;
// a = 0b 1000 1000 1000 1000;
// a = 0b 1100 1100 0000 0000;

const t_shape g_S_shape1 = {.h = 3, .w = 2, .bin_id = 0x0231, .bin_rep = 0x00004000C0008000};
const t_shape g_S_shape2 = {.h = 2, .w = 3, .bin_id = 0x001B, .bin_rep = 0x00000000C0006000};

const t_shape g_Z_shape1 = {.h = 3, .w = 2, .bin_id = 0x0099, .bin_rep = 0x00008000C0004000};
const t_shape g_Z_shape2 = {.h = 2, .w = 3, .bin_id = 0x0063, .bin_rep = 0x000000006000C000};

const t_shape g_T_shape1 = {.h = 2, .w = 3, .bin_id = 0x0039, .bin_rep = 0x000000004000E000};
const t_shape g_T_shape2 = {.h = 2, .w = 3, .bin_id = 0x0027, .bin_rep = 0x00000000E0004000};
const t_shape g_T_shape3 = {.h = 3, .w = 2, .bin_id = 0x0119, .bin_rep = 0x00008000C0008000};
const t_shape g_T_shape4 = {.h = 3, .w = 2, .bin_id = 0x0131, .bin_rep = 0x00004000C0004000};

const t_shape g_L_shape1 = {.h = 3, .w = 2, .bin_id = 0x0191, .bin_rep = 0x000080008000C000};
const t_shape g_L_shape2 = {.h = 3, .w = 2, .bin_id = 0x0223, .bin_rep = 0x0000C00080008000};
const t_shape g_L_shape3 = {.h = 3, .w = 2, .bin_id = 0x0113, .bin_rep = 0x0000C00040004000};
const t_shape g_L_shape4 = {.h = 3, .w = 2, .bin_id = 0x0311, .bin_rep = 0x000040004000C000};

const t_shape g_L_shape5 = {.h = 2, .w = 3, .bin_id = 0x001D, .bin_rep = 0x000000008000E000};
const t_shape g_L_shape6 = {.h = 2, .w = 3, .bin_id = 0x0047, .bin_rep = 0x00000000E0008000};
const t_shape g_L_shape7 = {.h = 2, .w = 3, .bin_id = 0x0071, .bin_rep = 0x000000002000E000};
const t_shape g_L_shape8 = {.h = 2, .w = 3, .bin_id = 0x0017, .bin_rep = 0x00000000E0002000};

const t_shape g_Line_shape1 = {.h = 1, .w = 4, .bin_id = 0x000F, .bin_rep = 0x000000000000F000};
const t_shape g_Line_shape2 = {.h = 4, .w = 1, .bin_id = 0x1111, .bin_rep = 0x8000800080008000};

const t_shape g_Square_shape = {.h = 2, .w = 2, .bin_id = 0x0033, .bin_rep = 0x00000000C000C000};

const t_shape *g_shapes[SHAPES_LEN] = {
    &g_S_shape1,
    &g_S_shape2,
    &g_Z_shape1,
    &g_Z_shape2,
    &g_T_shape1,
    &g_T_shape2,
    &g_T_shape3,
    &g_T_shape4,
    &g_L_shape1,
    &g_L_shape2,
    &g_L_shape3,
    &g_L_shape4,
    &g_L_shape5,
    &g_L_shape6,
    &g_L_shape7,
    &g_L_shape8,
    &g_Line_shape1,
    &g_Line_shape2,
    &g_Square_shape};

#endif