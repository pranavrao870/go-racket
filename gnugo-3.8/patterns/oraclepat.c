/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This is GNU Go, a Go program. Contact gnugo@gnu.org, or see       *
 * http://www.gnu.org/software/gnugo/ for more information.          *
 *                                                                   *
 * Copyright 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007,   *
 * 2008 and 2009 by the Free Software Foundation.                    *
 *                                                                   *
 * This program is free software; you can redistribute it and/or     *
 * modify it under the terms of the GNU General Public License as    *
 * published by the Free Software Foundation - version 3 or          *
 * (at your option) any later version.                               *
 *                                                                   *
 * This program is distributed in the hope that it will be useful,   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of    *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     *
 * GNU General Public License in file COPYING for more details.      *
 *                                                                   *
 * You should have received a copy of the GNU General Public         *
 * License along with this program; if not, write to the Free        *
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,       *
 * Boston, MA 02111, USA.                                            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h> /* for NULL */
#include "liberty.h"
#include "patterns.h"

static struct patval oracle0[] = {
  {145,1},	{128,1},	{111,2},	{144,2},
  {74,0},	{159,0},	{91,0},	{75,0},
  {92,0},	{109,0},	{126,0},	{143,0},
  {160,0},	{177,0},	{76,0},	{93,0},
  {110,0},	{127,0},	{176,0},	{161,0},
  {178,0},	{77,0},	{94,0},	{108,0},
  {125,0},	{142,0},	{162,0},	{179,0},
  {78,0},	{95,0},	{112,0},	{129,0},
  {146,0},	{163,0},	{180,0}
};

static struct patval oracle1[] = {
  {161,1},	{128,1},	{144,1},	{162,2},
  {145,2},	{125,0},	{193,0},	{92,0},
  {109,0},	{126,0},	{143,0},	{160,0},
  {177,0},	{194,0},	{93,0},	{110,0},
  {127,0},	{142,0},	{159,0},	{178,0},
  {195,0},	{94,0},	{111,0},	{176,0},
  {91,0},	{108,0},	{179,0},	{196,0},
  {95,0},	{112,0},	{129,0},	{146,0},
  {163,0},	{180,0},	{197,0},	{96,0},
  {113,0},	{130,0},	{147,0},	{164,0},
  {181,0},	{198,0}
};

static struct patval oracle2[] = {
  {162,1},	{145,1},	{129,1},	{144,2},
  {128,2},	{161,2},	{176,0},	{91,0},
  {109,0},	{126,0},	{143,0},	{160,0},
  {177,0},	{194,0},	{93,0},	{110,0},
  {127,0},	{108,0},	{193,0},	{178,0},
  {195,0},	{94,0},	{111,0},	{92,0},
  {142,0},	{159,0},	{179,0},	{196,0},
  {95,0},	{112,0},	{125,0},	{146,0},
  {163,0},	{180,0},	{197,0},	{96,0},
  {113,0},	{130,0},	{147,0},	{164,0},
  {181,0},	{198,0},	{97,0},	{114,0},
  {131,0},	{148,0},	{165,0},	{182,0},
  {199,0}
};

static struct patval oracle3[] = {
  {162,1},	{145,1},	{129,1},	{144,2},
  {128,2},	{161,2},	{176,0},	{91,0},
  {109,0},	{126,0},	{143,0},	{160,0},
  {177,0},	{194,0},	{93,0},	{110,0},
  {127,0},	{108,0},	{193,0},	{178,0},
  {195,0},	{94,0},	{111,0},	{92,0},
  {142,0},	{159,0},	{179,0},	{196,0},
  {95,0},	{112,0},	{125,0},	{146,0},
  {163,0},	{180,0},	{197,0},	{96,0},
  {113,0},	{130,0},	{147,0},	{164,0},
  {181,0},	{198,0},	{97,0},	{114,0},
  {131,0},	{148,0},	{165,0},	{182,0},
  {199,0}
};

static struct pattern oracle[5];

static int
autohelperoracle2(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, g, H;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(92, trans, move);
  b = AFFINE_TRANSFORM(76, trans, move);
  c = AFFINE_TRANSFORM(91, trans, move);
  d = AFFINE_TRANSFORM(77, trans, move);
  e = AFFINE_TRANSFORM(95, trans, move);
  f = AFFINE_TRANSFORM(78, trans, move);
  g = AFFINE_TRANSFORM(143, trans, move);
  H = AFFINE_TRANSFORM(110, trans, move);

  return  play_attack_defend_n(color, 1, 8, move, a, b, c, d, e, f, g, H);
}

static struct pattern oracle[] = {
  {oracle0,35,8, "O1",-2,-4,2,2,4,6,0x9,127,
    { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff},
    { 0x0010a000, 0x80900000, 0x29100000, 0x00180804, 0x00908040, 0xa0100000, 0x08180000, 0x00102900}
   , 0x0,10.000000,NULL,0,NULL,NULL,0,0.000000},
  {oracle1,42,8, "O2",-2,-3,3,3,5,6,0x9,129,
    { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff},
    { 0x00289400, 0x80606000, 0x58a00000, 0x24240800, 0x60608000, 0x94280000, 0x08242400, 0x00a05800}
   , 0x0,10.000000,NULL,0,NULL,NULL,3,0.000000},
  {oracle2,49,8, "O3",-2,-3,4,3,6,6,0x9,179,
    { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff},
    { 0x00146880, 0x40909000, 0xa4500000, 0x18180600, 0x90904000, 0x68140000, 0x06181800, 0x0050a408}
   , 0x0,10.000000,NULL,1,NULL,autohelperoracle2,0,1.000000},
  {oracle3,49,8, "O4",-2,-3,4,3,6,6,0x9,178,
    { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff},
    { 0x00146880, 0x40909000, 0xa4500000, 0x18180600, 0x90904000, 0x68140000, 0x06181800, 0x0050a408}
   , 0x0,10.000000,NULL,0,NULL,NULL,0,0.000000},
  {NULL, 0,0,NULL,0,0,0,0,0,0,0,0,{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},0,0.0,NULL,0,NULL,NULL,0,0.0}
};

struct pattern_db oracle_db = {
  -1,
  0,
  oracle
 , NULL
};
