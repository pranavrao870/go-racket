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

static struct patval attpat0[] = {
  {144,1},	{162,1},	{178,2},	{146,2},
  {196,0},	{179,0},	{163,0},	{180,0},
  {164,0}
};

static struct patval attpat1[] = {
  {128,1},	{161,1},	{144,1},	{110,2},
  {111,0},	{112,0},	{129,0},	{146,0},
  {163,0}
};

static struct patval attpat2[] = {
  {128,1},	{144,1},	{110,0},	{111,0}
};

static struct patval attpat3[] = {
  {147,1},	{144,1},	{128,1},	{146,0},
  {130,0},	{129,0}
};

static struct patval attpat4[] = {
  {144,1},	{129,1},	{130,2},	{146,0},
  {147,0}
};

static struct patval attpat5[] = {
  {144,1},	{146,0}
};

static struct patval attpat6[] = {
  {144,1},	{145,1},	{163,2},	{196,4},
  {195,4},	{179,4},	{125,4},	{178,0},
  {142,0},	{159,0},	{177,0}
};

static struct patval attpat7[] = {
  {144,1},	{196,2},	{194,0},	{178,0},
  {195,0},	{179,0},	{177,0}
};

static struct patval attpat8[] = {
  {144,1},	{142,0}
};

static struct patval attpat9[] = {
  {144,1},	{145,1},	{178,1},	{179,0}
};

static struct patval attpat10[] = {
  {129,1},	{144,1},	{162,1},	{146,1},
  {111,2}
};

static struct patval attpat11[] = {
  {144,1},	{163,4},	{146,0}
};

static struct patval attpat12[] = {
  {129,1},	{144,1},	{146,0}
};

static struct patval attpat13[] = {
  {144,1},	{110,2},	{109,0},	{111,0}
};

static struct pattern attpat[15];

static int
autohelperattpat9(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(109, trans, move);

  return  countlib(A)==1;
}

static int
autohelperattpat10(int trans, int move, int color, int action)
{
  int b, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(128, trans, move);
  A = AFFINE_TRANSFORM(146, trans, move);

  return countlib(A)==1 && accuratelib(move, color, MAX_LIBERTIES, NULL)>1 && countlib(b)>1;
}

static int
autohelperattpat13(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(179, trans, move);

  return  countlib(A) == 1;
}

static struct pattern attpat[] = {
  {attpat0,9,8, "Attack1",0,0,3,3,3,3,0x0,180,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00251810, 0x00609010, 0x90600000, 0x18250000, 0x90600000, 0x18250000, 0x00251810, 0x00609010}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {attpat1,9,8, "Attack2",0,-2,2,1,2,3,0x2,162,
    { 0x00fcfcfc, 0xf0f0f000, 0xffff0000, 0x3f3f3f3f, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0x00ffffff},
    { 0x00689000, 0x90602000, 0x18a50000, 0x20241810, 0x20609010, 0x90680000, 0x18242000, 0x00a51800}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {attpat2,4,8, "Attack4",0,-2,1,0,1,2,0x0,110,
    { 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0x003f3f00},
    { 0x00609000, 0x90600000, 0x18240000, 0x00241800, 0x00609000, 0x90600000, 0x18240000, 0x00241800}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {attpat3,6,8, "Attack5",0,-1,3,0,3,1,0x8,129,
    { 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c},
    { 0x00209000, 0x80600000, 0x18200000, 0x00240800, 0x00608000, 0x90200000, 0x08240000, 0x00201800}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {attpat4,5,8, "Attack6",0,-1,3,0,3,1,0x0,146,
    { 0x003030f0, 0x00f00000, 0x30300000, 0x003f0300, 0x00f00000, 0x30300000, 0x033f0000, 0x0030303c},
    { 0x00201080, 0x00600000, 0x10200000, 0x00240200, 0x00600000, 0x10200000, 0x02240000, 0x00201008}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {attpat5,2,8, "Attack10",-1,-1,2,1,3,2,0x0,162,
    { 0x3cfcfc30, 0xf0fcfc00, 0xfcfcf000, 0xfcff3c00, 0xfcfcf000, 0xfcfc3c00, 0x3cfffc00, 0xf0fcfc30},
    { 0x10604000, 0x50240000, 0x04241000, 0x00601400, 0x00245000, 0x40601000, 0x14600000, 0x10240400}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {attpat6,11,8, "Attack11",-2,-1,2,3,4,4,0x0,160,
    { 0xff3f3e0c, 0x0effffbc, 0xf0f0fcf8, 0xfffcc000, 0xffff0e00, 0x3e3fffbc, 0xc0fcfff8, 0xfcf0f0c0},
    { 0x40202004, 0x04a00000, 0x20200400, 0x01284000, 0x00a00400, 0x20204000, 0x40280100, 0x04202040}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {attpat7,7,8, "Attack13",-1,0,1,3,2,3,0x1,162,
    { 0x3f3f3f00, 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc, 0xf0f0f000},
    { 0x00201000, 0x00600000, 0x10200000, 0x00240000, 0x00600000, 0x10200000, 0x00240000, 0x00201000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {attpat8,2,8, "Attack14",-2,-1,1,1,3,2,0x0,126,
    { 0xfcfc3000, 0x3cff3c00, 0x30fcfc30, 0xf0fcf000, 0x3cff3c00, 0x30fcfc30, 0xf0fcf000, 0xfcfc3000},
    { 0x04641000, 0x10601400, 0x10644000, 0x50241000, 0x14601000, 0x10640400, 0x10245000, 0x40641000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {attpat9,4,8, "Attack15",0,0,1,2,1,2,0x2,179,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00262000, 0x00a01020, 0x20600000, 0x10280000, 0x10a00000, 0x20260000, 0x00281020, 0x00602000}
   , 0x400,0.000000,NULL,1,NULL
,autohelperattpat9,3,0.010000},
  {attpat10,5,8, "Attack16",0,-2,2,1,2,3,0x0,127,
    { 0x00f0fcf0, 0xf0f0c000, 0xff3c0000, 0x0c3f3f0c, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0c00, 0x003cff3c},
    { 0x002018a0, 0x00608000, 0x91200000, 0x08260204, 0x80600040, 0x18200000, 0x02260800, 0x00209128}
   , 0x400,0.000000,NULL,1,NULL,autohelperattpat10,3,0.043600},
  {attpat11,3,8, "Attack17",0,-1,2,1,2,2,0x0,146,
    { 0x0030fc38, 0xc0f0c000, 0xfc300000, 0x0e3f0c00, 0xc0f0c000, 0xfc300000, 0x0c3f0e00, 0x0030fcb0},
    { 0x00204400, 0x40204000, 0x44200000, 0x04200400, 0x40204000, 0x44200000, 0x04200400, 0x00204400}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {attpat12,3,8, "Attack18",0,-1,2,0,2,1,0x2,146,
    { 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c},
    { 0x00604080, 0x50200000, 0x04240000, 0x00201600, 0x00205000, 0x40600000, 0x16200000, 0x00240408}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {attpat13,4,8, "Attack19",-1,-2,1,0,2,2,0x0,109,
    { 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc, 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00},
    { 0x10201000, 0x00640000, 0x10211000, 0x00640010, 0x00640010, 0x10201000, 0x00640000, 0x10211000}
   , 0x400,0.000000,NULL,1,NULL,autohelperattpat13,3,0.010000},
  {NULL, 0,0,NULL,0,0,0,0,0,0,0,0,{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},0,0.0,NULL,0,NULL,NULL,0,0.0}
};

struct pattern_db attpat_db = {
  -1,
  0,
  attpat
 , NULL
};
