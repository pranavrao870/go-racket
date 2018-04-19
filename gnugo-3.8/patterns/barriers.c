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

static struct patval barrierspat0[] = {
  {161,5},	{144,2},	{178,2}
};

static struct patval barrierspat1[] = {
  {161,5},	{160,5},	{178,2},	{144,2},
  {177,4}
};

static struct patval barrierspat2[] = {
  {161,5},	{178,1},	{144,1},	{177,3},
  {179,3}
};

static struct patval barrierspat3[] = {
  {161,5},	{160,5},	{178,1},	{144,1},
  {177,0}
};

static struct patval barrierspat4[] = {
  {127,5},	{144,2}
};

static struct patval barrierspat5[] = {
  {126,5},	{161,1},	{144,2},	{143,4}
};

static struct patval barrierspat6[] = {
  {145,5},	{144,1}
};

static struct patval barrierspat7[] = {
  {127,5},	{128,5},	{144,1}
};

static struct patval barrierspat8[] = {
  {145,5},	{161,1},	{144,2}
};

static struct patval barrierspat9[] = {
  {162,5},	{145,5},	{161,1},	{144,1}
};

static struct patval barrierspat10[] = {
  {127,5},	{145,5},	{128,2},	{144,2}
};

static struct patval barrierspat11[] = {
  {127,5},	{145,5},	{128,1},	{144,1}
};

static struct patval barrierspat12[] = {
  {162,5},	{144,1},	{145,2},	{161,2}
};

static struct patval barrierspat13[] = {
  {162,5},	{161,1},	{145,1},	{144,2}
};

static struct patval barrierspat14[] = {
  {162,5},	{161,5},	{179,2},	{144,2},
  {178,0}
};

static struct patval barrierspat15[] = {
  {162,5},	{161,5},	{178,1},	{145,1},
  {144,1},	{179,1}
};

static struct patval barrierspat16[] = {
  {162,5},	{161,5},	{179,1},	{145,1},
  {144,1},	{178,4}
};

static struct patval barrierspat17[] = {
  {162,5},	{161,5},	{179,1},	{144,1},
  {177,3},	{178,3},	{146,3},	{163,3},
  {180,3}
};

static struct patval barrierspat18[] = {
  {162,5},	{161,5},	{179,1},	{144,1},
  {178,0}
};

static struct patval barrierspat19[] = {
  {162,5},	{161,5},	{178,1},	{179,1},
  {144,1}
};

static struct patval barrierspat20[] = {
  {162,5},	{161,5},	{179,1},	{144,1},
  {145,2},	{178,0}
};

static struct patval barrierspat21[] = {
  {162,5},	{161,5},	{179,1},	{144,1},
  {145,2},	{178,2}
};

static struct patval barrierspat22[] = {
  {178,5},	{161,5},	{144,2},	{195,2},
  {196,4},	{179,0}
};

static struct patval barrierspat23[] = {
  {178,5},	{161,5},	{144,2},	{195,2},
  {145,2},	{196,4},	{179,0}
};

static struct patval barrierspat24[] = {
  {161,5},	{178,5},	{195,1},	{144,1},
  {177,3},	{194,3},	{176,3},	{159,3},
  {179,3},	{196,3},	{163,3},	{180,3}
};

static struct patval barrierspat25[] = {
  {161,5},	{178,5},	{195,1},	{144,1},
  {194,3},	{196,3},	{179,0},	{177,0}
};

static struct patval barrierspat26[] = {
  {161,5},	{178,5},	{162,5},	{179,5},
  {144,1},	{195,1},	{177,3},	{194,3},
  {211,3},	{142,3},	{159,3},	{212,3},
  {176,3},	{193,3},	{196,3},	{213,3},
  {129,3},	{146,3},	{163,3},	{180,3},
  {197,3},	{214,3}
};

static struct patval barrierspat27[] = {
  {162,5},	{179,5},	{144,1},	{195,1},
  {197,3},	{180,3},	{196,3},	{146,3},
  {163,3},	{178,0}
};

static struct patval barrierspat28[] = {
  {179,5},	{161,5},	{178,5},	{162,5},
  {144,2},	{196,2},	{195,0}
};

static struct patval barrierspat29[] = {
  {179,5},	{162,5},	{146,2},	{144,2},
  {196,2},	{195,0},	{178,0},	{163,0},
  {180,0},	{197,0}
};

static struct patval barrierspat30[] = {
  {161,5},	{179,5},	{196,1},	{144,1},
  {177,3},	{194,3},	{159,3},	{181,3},
  {195,3},	{197,3},	{176,3},	{146,3},
  {163,3},	{180,3},	{164,3},	{178,0}
};

static struct patval barrierspat31[] = {
  {179,5},	{161,5},	{178,5},	{162,5},
  {144,1},	{196,1},	{195,3}
};

static struct patval barrierspat32[] = {
  {146,5},	{145,5},	{144,2},	{129,4},
  {163,4}
};

static struct patval barrierspat33[] = {
  {146,5},	{145,5},	{144,1},	{129,3},
  {163,3}
};

static struct patval barrierspat34[] = {
  {127,5},	{128,5},	{145,1},	{144,2}
};

static struct patval barrierspat35[] = {
  {145,5},	{162,1},	{161,2},	{144,2}
};

static struct patval barrierspat36[] = {
  {161,5},	{163,5},	{162,5},	{145,1},
  {144,2},	{179,4},	{178,4},	{180,4},
  {112,4},	{129,0},	{146,0}
};

static struct patval barrierspat37[] = {
  {145,5},	{163,5},	{162,5},	{128,1},
  {144,2},	{178,4},	{179,4},	{180,4},
  {146,0},	{129,0}
};

static struct patval barrierspat38[] = {
  {179,5},	{180,5},	{144,1},	{162,1},
  {161,2},	{197,4},	{178,4},	{196,4},
  {195,4},	{163,0},	{146,0}
};

static struct patval barrierspat39[] = {
  {163,5},	{162,5},	{144,1},	{161,2},
  {180,4},	{179,4},	{178,4},	{146,0}
};

static struct patval barrierspat40[] = {
  {162,5},	{163,5},	{179,1},	{144,1},
  {161,2},	{178,2},	{146,0}
};

static struct patval barrierspat41[] = {
  {146,5},	{163,5},	{180,5},	{162,5},
  {179,5},	{145,5},	{144,2},	{178,2},
  {196,4},	{129,4},	{195,4},	{197,4}
};

static struct patval barrierspat42[] = {
  {146,5},	{163,5},	{180,5},	{162,5},
  {179,5},	{145,5},	{144,1},	{178,1},
  {196,3},	{129,3},	{195,3},	{197,3}
};

static struct patval barrierspat43[] = {
  {162,5},	{180,5},	{179,5},	{161,1},
  {144,2},	{197,3},	{178,3},	{196,3},
  {195,3},	{163,0},	{146,0}
};

static struct patval barrierspat44[] = {
  {162,5},	{145,5},	{161,1},	{178,2},
  {144,2}
};

static struct patval barrierspat45[] = {
  {129,5},	{146,5},	{130,5},	{147,5},
  {144,2},	{111,2},	{94,4},	{164,4},
  {95,4},	{93,4},	{110,4},	{163,4},
  {96,4},	{113,0},	{112,0}
};

static struct patval barrierspat46[] = {
  {129,5},	{146,5},	{130,5},	{147,5},
  {144,1},	{111,1},	{94,3},	{164,3},
  {95,3},	{93,3},	{110,3},	{163,3},
  {96,3},	{113,0},	{112,0}
};

static struct patval barrierspat47[] = {
  {179,5},	{162,5},	{178,1},	{195,2},
  {144,2},	{196,2}
};

static struct patval barrierspat48[] = {
  {179,5},	{162,5},	{178,1},	{195,2},
  {144,2},	{196,0}
};

static struct patval barrierspat49[] = {
  {162,5},	{161,1},	{179,2},	{144,2}
};

static struct patval barrierspat50[] = {
  {162,5},	{180,5},	{179,5},	{144,1},
  {195,2},	{145,2},	{197,4},	{196,4},
  {129,4},	{146,0},	{163,0},	{178,0}
};

static struct patval barrierspat51[] = {
  {145,5},	{163,5},	{162,5},	{144,1},
  {128,2},	{178,2},	{180,4},	{129,0},
  {146,0},	{179,0}
};

static struct patval barrierspat52[] = {
  {163,5},	{180,5},	{179,5},	{162,5},
  {145,1},	{195,1},	{178,1},	{144,1},
  {146,0},	{196,0},	{197,0}
};

static struct patval barrierspat53[] = {
  {146,5},	{163,5},	{179,5},	{144,1},
  {128,2},	{178,2},	{180,4},	{129,0}
};

static struct patval barrierspat54[] = {
  {146,5},	{163,5},	{147,5},	{164,5},
  {181,5},	{162,5},	{180,5},	{179,5},
  {145,5},	{178,2},	{144,2},	{195,4},
  {196,4},	{112,4},	{129,4},	{110,4},
  {212,4},	{197,4},	{214,4},	{113,4},
  {130,4},	{111,4},	{213,4},	{198,4},
  {215,4}
};

static struct patval barrierspat55[] = {
  {145,5},	{162,5},	{146,5},	{147,5},
  {164,5},	{181,5},	{179,5},	{180,5},
  {163,5},	{178,1},	{144,1},	{110,3},
  {195,3},	{111,3},	{109,3},	{211,3},
  {196,3},	{213,3},	{112,3},	{129,3},
  {212,3},	{197,3},	{214,3},	{113,3},
  {130,3},	{177,3},	{194,3},	{198,3},
  {215,3}
};

static struct patval barrierspat56[] = {
  {163,5},	{162,5},	{145,5},	{180,2},
  {144,2},	{146,0},	{179,0}
};

static struct patval barrierspat57[] = {
  {163,5},	{145,5},	{162,5},	{180,2},
  {144,2},	{146,0}
};

static struct patval barrierspat58[] = {
  {178,5},	{161,5},	{144,2},	{195,2}
};

static struct patval barrierspat59[] = {
  {129,5},	{128,5},	{145,1},	{144,2},
  {110,4},	{111,4},	{179,0},	{112,0},
  {146,0},	{163,0},	{180,0}
};

static struct patval barrierspat60[] = {
  {146,5},	{145,1},	{128,2},	{162,2},
  {144,2},	{163,3},	{129,0}
};

static struct patval barrierspat61[] = {
  {145,5},	{162,5},	{179,5},	{144,1},
  {178,1},	{161,2},	{177,3},	{194,3},
  {195,3},	{196,3},	{129,0},	{146,0},
  {163,0},	{180,0},	{197,0}
};

static struct patval barrierspat62[] = {
  {179,5},	{162,5},	{161,1},	{195,2},
  {144,2},	{178,0},	{196,0}
};

static struct patval barrierspat63[] = {
  {179,5},	{180,5},	{144,1},	{162,1},
  {161,2},	{145,2},	{146,3},	{178,4},
  {163,0},	{129,0}
};

static struct patval barrierspat64[] = {
  {179,5},	{180,5},	{144,1},	{146,1},
  {128,1},	{145,2},	{161,2},	{178,4},
  {129,0},	{163,0}
};

static struct patval barrierspat65[] = {
  {161,5},	{144,1},	{145,2}
};

static struct patval barrierspat66[] = {
  {160,5},	{161,1},	{178,2},	{144,2},
  {177,4}
};

static struct patval barrierspat67[] = {
  {143,5},	{144,1},	{161,2}
};

static struct patval barrierspat68[] = {
  {146,7},	{147,7},	{144,1},	{129,0},
  {163,0},	{130,0},	{164,0}
};

static struct patval barrierspat69[] = {
  {145,5},	{147,7},	{146,7},	{144,2},
  {129,0},	{163,0},	{130,0},	{164,0}
};

static struct patval barrierspat70[] = {
  {109,7},	{163,7},	{92,7},	{164,7},
  {128,1},	{144,2},	{125,4},	{91,4},
  {176,4},	{179,4},	{178,4},	{177,4},
  {108,4},	{181,4},	{180,4},	{142,4},
  {159,4},	{94,0},	{111,0},	{95,0},
  {112,0},	{129,0},	{146,0},	{93,0},
  {96,0},	{113,0},	{130,0},	{147,0},
  {110,0}
};

static struct patval barrierspat71[] = {
  {129,7},	{144,1},	{162,2},	{127,3},
  {112,0},	{111,0},	{146,0},	{163,0}
};

static struct patval barrierspat72[] = {
  {146,5},	{163,5},	{145,5},	{144,1},
  {128,2},	{179,0},	{129,0},	{178,0},
  {180,0},	{130,0},	{147,0},	{164,0},
  {181,0}
};

static struct patval barrierspat73[] = {
  {145,5},	{163,5},	{180,5},	{162,5},
  {144,1},	{128,2},	{179,0},	{129,0},
  {146,0},	{178,0},	{130,0},	{147,0},
  {164,0},	{181,0}
};

static struct patval barrierspat74[] = {
  {146,5},	{145,5},	{128,1},	{144,2},
  {129,3},	{163,0}
};

static struct patval barrierspat75[] = {
  {164,5},	{148,5},	{147,5},	{146,1},
  {144,1},	{163,2},	{111,0},	{179,0},
  {196,0},	{112,0},	{129,0},	{180,0},
  {197,0},	{113,0},	{130,0},	{178,0},
  {110,0},	{181,0},	{198,0},	{114,0},
  {131,0},	{195,0},	{165,0},	{182,0},
  {199,0},	{115,0},	{132,0},	{149,0},
  {166,0},	{183,0},	{200,0}
};

static struct patval barrierspat76[] = {
  {128,5},	{111,5},	{94,5},	{77,2},
  {144,2},	{110,0},	{93,0},	{76,0},
  {78,0},	{95,0},	{112,0},	{129,0},
  {146,0},	{79,0},	{96,0},	{113,0},
  {130,0},	{147,0}
};

static struct patval barrierspat77[] = {
  {93,7},	{110,7},	{143,1},	{144,2},
  {142,3},	{109,0},	{92,0}
};

static struct patval barrierspat78[] = {
  {126,7},	{109,7},	{143,1},	{144,2},
  {142,3},	{110,0}
};

static struct patval barrierspat79[] = {
  {127,7},	{143,1},	{92,1},	{144,2},
  {142,3},	{108,3},	{125,3},	{91,3},
  {93,0},	{110,0},	{109,0}
};

static struct patval barrierspat80[] = {
  {110,7},	{92,1},	{143,1},	{144,2},
  {108,3},	{91,3},	{125,3},	{142,3},
  {93,0},	{109,0}
};

static struct patval barrierspat81[] = {
  {109,7},	{92,7},	{143,1},	{144,2},
  {142,3},	{108,3},	{125,3},	{91,3},
  {93,0},	{110,0}
};

static struct patval barrierspat82[] = {
  {111,7},	{94,7},	{109,1},	{144,2},
  {92,3},	{93,0},	{110,0}
};

static struct patval barrierspat83[] = {
  {111,7},	{94,7},	{126,1},	{144,2},
  {92,3},	{109,3},	{93,0},	{110,0}
};

static struct patval barrierspat84[] = {
  {145,7},	{129,7},	{128,7},	{178,1},
  {162,1},	{127,1},	{161,2},	{144,2},
  {179,0},	{146,0},	{163,0},	{180,0}
};

static struct patval barrierspat85[] = {
  {129,7},	{128,7},	{110,1},	{161,1},
  {145,1},	{144,2},	{112,0},	{111,0},
  {146,0},	{163,0}
};

static struct patval barrierspat86[] = {
  {128,7},	{145,1},	{161,1},	{144,2}
};

static struct patval barrierspat87[] = {
  {162,7},	{145,7},	{128,1},	{161,1},
  {144,2},	{129,3},	{146,0},	{163,0}
};

static struct patval barrierspat88[] = {
  {162,7},	{145,7},	{161,1},	{144,2}
};

static struct patval barrierspat89[] = {
  {161,7},	{178,7},	{177,1},	{162,1},
  {143,1},	{144,2},	{179,0}
};

static struct patval barrierspat90[] = {
  {162,7},	{161,7},	{160,1},	{145,1},
  {144,2}
};

static struct patval barrierspat91[] = {
  {162,7},	{143,1},	{161,1},	{144,2}
};

static struct patval barrierspat92[] = {
  {110,7},	{93,7},	{126,1},	{143,2},
  {144,2},	{125,3},	{108,3},	{91,3},
  {92,0},	{109,0}
};

static struct patval barrierspat93[] = {
  {146,7},	{145,1},	{144,2},	{129,0},
  {163,0},	{130,0},	{147,0},	{164,0}
};

static struct patval barrierspat94[] = {
  {127,7},	{162,7},	{161,7},	{128,7},
  {145,1},	{144,2},	{129,0},	{146,0},
  {163,0},	{130,0},	{147,0},	{164,0}
};

static struct patval barrierspat95[] = {
  {162,7},	{145,1},	{144,2},	{127,4},
  {161,4},	{129,0},	{146,0},	{163,0}
};

static struct patval barrierspat96[] = {
  {129,7},	{128,7},	{95,1},	{94,1},
  {145,1},	{110,2},	{144,2},	{112,0},
  {111,0},	{146,0},	{163,0},	{96,0},
  {113,0},	{130,0},	{147,0},	{164,0}
};

static struct patval barrierspat97[] = {
  {147,7},	{146,7},	{145,7},	{128,1},
  {162,1},	{144,2},	{161,2},	{129,0},
  {163,0},	{180,0},	{130,0},	{179,0},
  {164,0},	{181,0}
};

static struct patval barrierspat98[] = {
  {129,7},	{145,1},	{163,1},	{144,2},
  {162,2},	{146,0}
};

static struct patval barrierspat99[] = {
  {162,7},	{161,7},	{145,7},	{180,1},
  {144,2},	{163,3},	{146,0},	{178,0},
  {179,0}
};

static struct patval barrierspat100[] = {
  {162,7},	{161,7},	{146,1},	{180,1},
  {144,2},	{163,3},	{179,0},	{178,0}
};

static struct patval barrierspat101[] = {
  {178,7},	{161,7},	{163,1},	{159,1},
  {144,2},	{176,3},	{146,3},	{180,3},
  {142,3},	{179,0},	{177,0}
};

static struct patval barrierspat102[] = {
  {161,7},	{163,1},	{143,1},	{144,2},
  {180,3},	{146,3},	{179,0},	{178,0},
  {177,0}
};

static struct patval barrierspat103[] = {
  {161,7},	{162,7},	{145,1},	{128,2},
  {144,2}
};

static struct patval barrierspat104[] = {
  {162,7},	{178,1},	{144,2},	{146,3},
  {179,0},	{163,0},	{180,0}
};

static struct patval barrierspat105[] = {
  {161,7},	{177,1},	{144,2},	{178,0},
  {179,0}
};

static struct patval barrierspat106[] = {
  {163,7},	{178,1},	{144,2},	{179,0},
  {146,0},	{180,0}
};

static struct patval barrierspat107[] = {
  {162,7},	{179,7},	{144,2},	{178,0}
};

static struct patval barrierspat108[] = {
  {161,7},	{178,7},	{143,2},	{144,2},
  {177,0}
};

static struct patval barrierspat109[] = {
  {109,7},	{126,7},	{110,7},	{127,1},
  {160,2},	{144,2},	{111,0},	{112,0},
  {129,0},	{146,0},	{163,0}
};

static struct patval barrierspat110[] = {
  {109,7},	{126,7},	{162,7},	{145,1},
  {127,1},	{144,2},	{160,2},	{110,0},
  {111,0},	{112,0},	{129,0},	{146,0},
  {163,0}
};

static struct patval barrierspat111[] = {
  {163,7},	{162,7},	{144,2},	{179,0},
  {146,0},	{178,0},	{180,0},	{147,0},
  {164,0},	{181,0}
};

static struct patval barrierspat112[] = {
  {146,7},	{145,7},	{162,1},	{144,2},
  {111,3},	{112,0},	{129,0},	{163,0},
  {113,0},	{130,0},	{147,0},	{164,0}
};

static struct patval barrierspat113[] = {
  {163,7},	{147,7},	{146,7},	{144,2},
  {159,4},	{177,4},	{125,4},	{142,4},
  {176,4},	{178,4},	{179,0},	{129,0},
  {180,0},	{130,0},	{164,0},	{181,0}
};

static struct patval barrierspat114[] = {
  {163,7},	{147,7},	{146,7},	{127,1},
  {144,2},	{177,4},	{159,4},	{142,4},
  {176,4},	{178,4},	{125,4},	{179,0},
  {129,0},	{180,0},	{130,0},	{164,0},
  {181,0}
};

static struct patval barrierspat115[] = {
  {146,7},	{179,1},	{144,2},	{178,4},
  {129,0},	{163,0},	{180,0}
};

static struct patval barrierspat116[] = {
  {146,7},	{162,7},	{145,7},	{127,1},
  {144,2},	{129,0},	{163,0},	{147,0}
};

static struct patval barrierspat117[] = {
  {145,7},	{127,1},	{144,2},	{146,0}
};

static struct patval barrierspat118[] = {
  {145,7},	{161,1},	{127,1},	{143,2},
  {144,2},	{146,0}
};

static struct patval barrierspat119[] = {
  {145,7},	{161,1},	{127,1},	{144,2},
  {146,0}
};

static struct patval barrierspat120[] = {
  {145,7},	{147,7},	{146,7},	{162,1},
  {128,1},	{126,1},	{144,2},	{94,0},
  {111,0},	{110,0},	{92,0},	{109,0},
  {95,0},	{112,0},	{129,0},	{163,0},
  {96,0},	{113,0},	{130,0},	{93,0},
  {164,0}
};

static struct patval barrierspat121[] = {
  {161,7},	{145,1},	{160,1},	{144,2}
};

static struct patval barrierspat122[] = {
  {161,7},	{162,1},	{160,1},	{144,2}
};

static struct patval barrierspat123[] = {
  {127,7},	{126,1},	{144,2}
};

static struct patval barrierspat124[] = {
  {162,7},	{161,7},	{160,1},	{179,1},
  {144,2},	{177,3},	{178,0}
};

static struct patval barrierspat125[] = {
  {160,7},	{143,1},	{144,2}
};

static struct patval barrierspat126[] = {
  {161,7},	{160,7},	{143,1},	{144,2}
};

static struct patval barrierspat127[] = {
  {128,7},	{145,1},	{127,1},	{144,2},
  {126,2},	{111,0},	{110,0},	{112,0},
  {129,0},	{146,0},	{163,0}
};

static struct patval barrierspat128[] = {
  {128,7},	{111,7},	{126,1},	{127,1},
  {143,2},	{144,2},	{93,0},	{110,0}
};

static struct patval barrierspat129[] = {
  {128,7},	{111,7},	{127,1},	{144,2},
  {110,0}
};

static struct patval barrierspat130[] = {
  {111,7},	{128,7},	{143,1},	{127,1},
  {144,2},	{109,0},	{110,0}
};

static struct patval barrierspat131[] = {
  {128,7},	{145,1},	{110,1},	{144,2},
  {111,0},	{112,0},	{129,0},	{146,0},
  {163,0}
};

static struct patval barrierspat132[] = {
  {162,7},	{128,7},	{145,1},	{144,2},
  {178,3},	{181,3},	{180,3},	{112,3},
  {110,3},	{113,3},	{111,0},	{146,0},
  {163,0},	{179,0},	{130,0},	{147,0},
  {164,0},	{129,0}
};

static struct patval barrierspat133[] = {
  {194,7},	{176,1},	{144,2},	{177,0},
  {193,0},	{211,0},	{178,0},	{195,0},
  {212,0}
};

static struct patval barrierspat134[] = {
  {178,7},	{179,1},	{144,2},	{159,3},
  {177,0},	{176,0}
};

static struct patval barrierspat135[] = {
  {145,7},	{162,7},	{161,1},	{127,1},
  {144,2}
};

static struct patval barrierspat136[] = {
  {178,7},	{161,1},	{144,2},	{177,0},
  {179,0}
};

static struct patval barrierspat137[] = {
  {146,7},	{128,1},	{162,1},	{144,2},
  {129,0},	{163,0}
};

static struct patval barrierspat138[] = {
  {128,7},	{162,7},	{127,1},	{161,1},
  {145,1},	{143,2},	{144,2}
};

static struct patval barrierspat139[] = {
  {161,7},	{143,1},	{162,1},	{144,2},
  {177,3},	{178,0},	{179,0}
};

static struct patval barrierspat140[] = {
  {178,7},	{160,7},	{143,1},	{161,1},
  {144,2},	{177,0}
};

static struct patval barrierspat141[] = {
  {111,7},	{127,1},	{143,1},	{144,2},
  {110,0},	{109,0}
};

static struct patval barrierspat142[] = {
  {110,7},	{109,7},	{144,2},	{125,3},
  {108,3},	{91,3},	{92,0},	{93,0}
};

static struct patval barrierspat143[] = {
  {92,7},	{93,7},	{144,2},	{91,3},
  {125,3},	{108,3},	{110,0},	{109,0}
};

static struct patval barrierspat144[] = {
  {127,7},	{143,1},	{128,1},	{144,2}
};

static struct patval barrierspat145[] = {
  {162,7},	{163,7},	{145,1},	{127,1},
  {109,1},	{126,2},	{144,2},	{110,0},
  {129,0},	{146,0},	{111,0}
};

static struct patval barrierspat146[] = {
  {142,7},	{141,7},	{177,1},	{143,1},
  {127,1},	{144,2},	{161,2},	{176,3},
  {175,3},	{124,3},	{158,3},	{125,0},
  {159,0}
};

static struct patval barrierspat147[] = {
  {162,7},	{128,1},	{144,2},	{146,2},
  {127,2},	{129,2}
};

static struct patval barrierspat148[] = {
  {159,7},	{161,1},	{143,1},	{178,1},
  {144,2},	{162,2},	{145,2},	{125,0},
  {177,0},	{142,0}
};

static struct patval barrierspat149[] = {
  {128,7},	{145,1},	{143,1},	{162,2},
  {144,2}
};

static struct patval barrierspat150[] = {
  {196,7},	{145,1},	{194,1},	{160,1},
  {161,1},	{143,2},	{176,2},	{144,2},
  {159,2},	{142,4},	{125,0},	{178,0},
  {195,0},	{177,0},	{179,0}
};

static struct patval barrierspat151[] = {
  {145,1},	{179,1},	{178,2},	{144,2}
};

static struct patval barrierspat152[] = {
  {145,1},	{179,1},	{144,2},	{178,0}
};

static struct patval barrierspat153[] = {
  {144,1},	{179,2},	{145,2},	{178,0}
};

static struct patval barrierspat154[] = {
  {145,1},	{144,2},	{112,2},	{129,3},
  {111,3}
};

static struct patval barrierspat155[] = {
  {112,1},	{144,1},	{145,2},	{129,4},
  {111,4}
};

static struct patval barrierspat156[] = {
  {145,1},	{144,2}
};

static struct patval barrierspat157[] = {
  {146,1},	{144,2},	{129,3}
};

static struct patval barrierspat158[] = {
  {144,1},	{146,2},	{129,4}
};

static struct patval barrierspat159[] = {
  {144,1},	{162,2}
};

static struct patval barrierspat160[] = {
  {144,1},	{162,2}
};

static struct patval barrierspat161[] = {
  {144,1},	{162,2},	{110,0},	{111,0}
};

static struct patval barrierspat162[] = {
  {144,1},	{161,2}
};

static struct patval barrierspat163[] = {
  {144,1},	{161,2}
};

static struct patval barrierspat164[] = {
  {94,1},	{144,1},	{129,2},	{112,4},
  {111,0},	{93,0},	{110,0}
};

static struct patval barrierspat165[] = {
  {144,1},	{178,1},	{161,2},	{176,3},
  {177,0},	{142,0},	{159,0}
};

static struct patval barrierspat166[] = {
  {146,1},	{145,1},	{161,1},	{128,2},
  {144,2},	{129,0},	{163,0}
};

static struct patval barrierspat167[] = {
  {144,2}
};

static struct patval barrierspat168[] = {
  {144,1}
};

static struct patval barrierspat169[] = {
  {161,1},	{144,2},	{142,0}
};

static struct patval barrierspat170[] = {
  {161,1},	{144,2},	{159,0},	{141,0},
  {142,0}
};

static struct patval barrierspat171[] = {
  {144,1},	{146,1},	{129,2}
};

static struct patval barrierspat172[] = {
  {144,1},	{162,1},	{161,2}
};

static struct patval barrierspat173[] = {
  {145,1},	{162,2},	{144,2}
};

static struct patval barrierspat174[] = {
  {144,1},	{179,2},	{161,2},	{178,4}
};

static struct patval barrierspat175[] = {
  {144,1},	{161,2},	{179,2},	{178,4},
  {110,0},	{111,0}
};

static struct patval barrierspat176[] = {
  {144,1},	{145,2}
};

static struct patval barrierspat177[] = {
  {144,1},	{145,2}
};

static struct patval barrierspat178[] = {
  {144,1},	{128,2}
};

static struct patval barrierspat179[] = {
  {144,1},	{128,2}
};

static struct patval barrierspat180[] = {
  {144,2}
};

static struct patval barrierspat181[] = {
  {144,1}
};

static struct patval barrierspat182[] = {
  {144,1},	{161,2}
};

static struct patval barrierspat183[] = {
  {128,1},	{144,1},	{146,1},	{129,2},
  {111,2}
};

static struct patval barrierspat184[] = {
  {144,2},	{178,0}
};

static struct patval barrierspat185[] = {
  {144,2}
};

static struct patval barrierspat186[] = {
  {128,1},	{161,2},	{144,2},	{178,0},
  {179,0}
};

static struct patval barrierspat187[] = {
  {144,1},	{161,1},	{128,2},	{178,0},
  {179,0}
};

static struct patval barrierspat188[] = {
  {144,1},	{161,1},	{178,1},	{128,2},
  {195,0},	{179,0},	{196,0}
};

static struct patval barrierspat189[] = {
  {112,1},	{144,2},	{110,0},	{111,0},
  {129,0},	{146,0}
};

static struct patval barrierspat190[] = {
  {144,1},	{180,1},	{178,2},	{179,0},
  {146,0},	{163,0}
};

static struct patval barrierspat191[] = {
  {128,1},	{146,2},	{144,2},	{145,2},
  {129,3},	{110,3},	{112,0},	{111,0}
};

static struct patval barrierspat192[] = {
  {145,1},	{144,2},	{110,0},	{111,0}
};

static struct patval barrierspat193[] = {
  {179,1},	{161,1},	{144,2},	{162,2},
  {163,4},	{146,0}
};

static struct patval barrierspat194[] = {
  {144,1},	{162,1},	{179,2},	{163,3},
  {146,0}
};

static struct patval barrierspat195[] = {
  {179,1},	{161,1},	{144,2},	{162,2},
  {180,2},	{163,0},	{146,0}
};

static struct patval barrierspat196[] = {
  {144,1},	{180,1},	{162,1},	{179,2},
  {178,2},	{146,0},	{163,0}
};

static struct patval barrierspat197[] = {
  {145,1},	{144,1},	{128,2},	{129,0},
  {146,0},	{163,0},	{130,0},	{147,0},
  {164,0}
};

static struct patval barrierspat198[] = {
  {111,1},	{146,1},	{144,2},	{162,2},
  {112,0},	{129,0}
};

static struct patval barrierspat199[] = {
  {161,1},	{144,2},	{162,2}
};

static struct patval barrierspat200[] = {
  {179,1},	{180,1},	{161,1},	{146,2},
  {144,2},	{128,2},	{178,3},	{129,4},
  {163,0}
};

static struct patval barrierspat201[] = {
  {196,1},	{161,1},	{178,1},	{144,2},
  {179,2},	{162,2},	{213,3},	{195,3},
  {146,0},	{163,0},	{180,0},	{197,0},
  {214,0}
};

static struct patval barrierspat202[] = {
  {162,1},	{178,1},	{144,2},	{179,0}
};

static struct patval barrierspat203[] = {
  {144,1},	{112,1},	{147,1},	{111,2},
  {129,0},	{146,0},	{163,0},	{130,0}
};

static struct patval barrierspat204[] = {
  {144,1},	{212,1},	{194,4},	{177,4},
  {178,0},	{195,0}
};

static struct patval barrierspat205[] = {
  {162,1},	{144,2},	{179,2},	{178,0}
};

static struct patval barrierspat206[] = {
  {162,1},	{144,2},	{129,0},	{146,0}
};

static struct patval barrierspat207[] = {
  {111,1},	{144,2},	{129,0},	{146,0}
};

static struct patval barrierspat208[] = {
  {145,1},	{163,1},	{146,2},	{144,2},
  {129,0}
};

static struct patval barrierspat209[] = {
  {162,1},	{179,2},	{144,2},	{163,0}
};

static struct patval barrierspat210[] = {
  {162,1},	{179,2},	{178,2},	{144,2},
  {163,0}
};

static struct patval barrierspat211[] = {
  {161,1},	{144,2},	{178,0},	{179,0},
  {146,0},	{163,0},	{180,0}
};

static struct patval barrierspat212[] = {
  {144,1},	{111,2}
};

static struct patval barrierspat213[] = {
  {144,1},	{178,2},	{162,2},	{177,0},
  {179,0}
};

static struct patval barrierspat214[] = {
  {128,1},	{144,1},	{145,2},	{111,0},
  {110,0},	{112,0},	{129,0},	{146,0}
};

static struct patval barrierspat215[] = {
  {144,1},	{212,1},	{178,2},	{195,2},
  {161,2},	{213,3},	{179,0},	{196,0}
};

static struct patval barrierspat216[] = {
  {128,1},	{178,1},	{161,2},	{144,2},
  {163,2},	{146,2},	{179,0}
};

static struct patval barrierspat217[] = {
  {111,1},	{163,1},	{144,2},	{161,2},
  {146,2}
};

static struct pattern barrierspat[219];

static int
autohelperbarrierspat3(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(160, trans, move);
  b = AFFINE_TRANSFORM(159, trans, move);
  c = AFFINE_TRANSFORM(143, trans, move);
  d = AFFINE_TRANSFORM(177, trans, move);

  return !(play_break_through_n(color, 2, a, b, c, b, d)==WIN);
}

static int
autohelperbarrierspat4(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(110, trans, move);

  return !play_attack_defend_n(color, 1, 1, a, a);
}

static int
autohelperbarrierspat5(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(108, trans, move);

  return !play_attack_defend_n(color, 1, 1, a, a);
}

static int
autohelperbarrierspat7(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);
  c = AFFINE_TRANSFORM(110, trans, move);
  d = AFFINE_TRANSFORM(127, trans, move);

  return play_attack_defend2_n(color, 1, 3, a, b, c, a, c) || !play_attack_defend2_n(color, 1, 2, a, b, b, d);
}

static int
autohelperbarrierspat8(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(144, trans, move);

  return !DEFEND_MACRO(a);
}

static int
autohelperbarrierspat13(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(162, trans, move);
  b = AFFINE_TRANSFORM(145, trans, move);
  c = AFFINE_TRANSFORM(161, trans, move);

  return !safe_move(a, color) || play_attack_defend2_n(color, 0, 1, a, b, c);
}

static int
autohelperbarrierspat16(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(162, trans, move);
  b = AFFINE_TRANSFORM(161, trans, move);
  c = AFFINE_TRANSFORM(179, trans, move);

  return !play_attack_defend2_n(color, 1, 2, a, b, b, c);
}

static int
autohelperbarrierspat18(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(161, trans, move);
  b = AFFINE_TRANSFORM(162, trans, move);
  c = AFFINE_TRANSFORM(144, trans, move);
  d = AFFINE_TRANSFORM(179, trans, move);
  e = AFFINE_TRANSFORM(178, trans, move);
  f = AFFINE_TRANSFORM(145, trans, move);

  return (play_attack_defend2_n(color, 1, 3, a, b, f, a, f) || !play_attack_defend2_n(color, 1, 2, a, b, c, d))&& (play_attack_defend2_n(color, 1, 3, b, a, e, b, e) || !play_attack_defend2_n(color, 1, 2, b, a, c, d));
}

static int
autohelperbarrierspat19(int trans, int move, int color, int action)
{
  int a, b, c, d, f;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(161, trans, move);
  b = AFFINE_TRANSFORM(162, trans, move);
  c = AFFINE_TRANSFORM(144, trans, move);
  d = AFFINE_TRANSFORM(178, trans, move);
  f = AFFINE_TRANSFORM(145, trans, move);

  return (play_attack_defend2_n(color, 1, 3, a, b, f, a, f) || !play_attack_defend2_n(color, 1, 2, a, b, c, d))&& !play_attack_defend_n(color, 1, 2, b, a, c);
}

static int
autohelperbarrierspat20(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(161, trans, move);
  b = AFFINE_TRANSFORM(162, trans, move);
  c = AFFINE_TRANSFORM(144, trans, move);
  d = AFFINE_TRANSFORM(179, trans, move);
  e = AFFINE_TRANSFORM(178, trans, move);

  return !play_attack_defend2_n(color, 1, 2, a, b, c, d)&& (play_attack_defend2_n(color, 1, 3, b, a, e, b, e) || !play_attack_defend2_n(color, 1, 2, b, a, c, d));
}

static int
autohelperbarrierspat21(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(161, trans, move);
  b = AFFINE_TRANSFORM(162, trans, move);
  c = AFFINE_TRANSFORM(144, trans, move);
  d = AFFINE_TRANSFORM(179, trans, move);

  return !play_attack_defend2_n(color, 1, 2, a, b, c, d) && !play_attack_defend2_n(color, 1, 2, b, a, c, d);
}

static int
autohelperbarrierspat22(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(178, trans, move);
  b = AFFINE_TRANSFORM(161, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);
  d = AFFINE_TRANSFORM(144, trans, move);

  return !play_break_through_n(color, 3, a, b, c, a, c, d);
}

static int
autohelperbarrierspat23(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(178, trans, move);
  b = AFFINE_TRANSFORM(161, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);
  d = AFFINE_TRANSFORM(179, trans, move);
  e = AFFINE_TRANSFORM(195, trans, move);

  return !play_attack_defend2_n(color, 1, 3, a, b, c, a, c) || !play_attack_defend2_n(color, 1, 3, b, a, d, d, e);
}

static int
autohelperbarrierspat25(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(177, trans, move);
  b = AFFINE_TRANSFORM(178, trans, move);
  c = AFFINE_TRANSFORM(161, trans, move);
  d = AFFINE_TRANSFORM(160, trans, move);

  return !play_attack_defend2_n(color, 1, 4, a, b, c, d, b, d) && !play_attack_defend2_n(color, 1, 4, d, c, b, a, c, a);
}

static int
autohelperbarrierspat27(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(178, trans, move);
  b = AFFINE_TRANSFORM(179, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);
  d = AFFINE_TRANSFORM(161, trans, move);

  return !play_attack_defend2_n(color, 1, 4, a, b, c, d, b, d) && !play_attack_defend2_n(color, 1, 4, d, c, b, a, c, a);
}

static int
autohelperbarrierspat28(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(161, trans, move);
  b = AFFINE_TRANSFORM(178, trans, move);
  c = AFFINE_TRANSFORM(179, trans, move);
  d = AFFINE_TRANSFORM(162, trans, move);

  return play_attack_defend2_n(color, 1, 4, a, b, c, d, b, d) || play_attack_defend2_n(color, 0, 4, a, b, c, d, a, c);
}

static int
autohelperbarrierspat31(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(178, trans, move);
  b = AFFINE_TRANSFORM(179, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);
  d = AFFINE_TRANSFORM(161, trans, move);

  return !play_attack_defend2_n(color, 1, 4, a, b, c, d, b, d) && !play_attack_defend2_n(color, 1, 4, d, c, b, a, c, a);
}

static int
autohelperbarrierspat34(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(111, trans, move);
  b = AFFINE_TRANSFORM(127, trans, move);

  return !play_attack_defend2_n(color, 1, 1, a, a, b);
}

static int
autohelperbarrierspat35(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(145, trans, move);

  return !play_attack_defend_n(color, 1, 1, a, a);
}

static int
autohelperbarrierspat38(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(179, trans, move);
  B = AFFINE_TRANSFORM(162, trans, move);

  return play_attack_defend_n(color, 1, 1, a, B);
}

static int
autohelperbarrierspat40(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(179, trans, move);

  return ATTACK_MACRO(A);
}

static int
autohelperbarrierspat43(int trans, int move, int color, int action)
{
  int b, c, d, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(178, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);
  d = AFFINE_TRANSFORM(179, trans, move);
  A = AFFINE_TRANSFORM(161, trans, move);

  return countlib(A)>3 || (!is_legal(b, color))|| (countlib(A)>2 && (accuratelib(b, color, MAX_LIBERTIES, NULL) <= 2 || play_attack_defend2_n(color, 1, 3, c, d, b, b, c)));
}

static int
autohelperbarrierspat44(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(161, trans, move);

  return countlib(A)==1;
}

static int
autohelperbarrierspat47(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(179, trans, move);
  b = AFFINE_TRANSFORM(162, trans, move);
  c = AFFINE_TRANSFORM(161, trans, move);

  return !play_attack_defend2_n(color, 1, 3, a, b, c, a, c);
}

static int
autohelperbarrierspat48(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(179, trans, move);
  b = AFFINE_TRANSFORM(162, trans, move);
  c = AFFINE_TRANSFORM(161, trans, move);
  d = AFFINE_TRANSFORM(196, trans, move);
  e = AFFINE_TRANSFORM(195, trans, move);

  return play_attack_defend2_n(color, 0, 4, a, b, c, d, a, e);
}

static int
autohelperbarrierspat49(int trans, int move, int color, int action)
{
  int a, b, c, D;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(162, trans, move);
  b = AFFINE_TRANSFORM(145, trans, move);
  c = AFFINE_TRANSFORM(144, trans, move);
  D = AFFINE_TRANSFORM(161, trans, move);

  return play_attack_defend2_n(color, 1, 2, a, b, b, D) || play_attack_defend2_n(color, 0, 2, a, b, a, c);
}

static int
autohelperbarrierspat51(int trans, int move, int color, int action)
{
  int a, b, c, d, E;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(144, trans, move);
  c = AFFINE_TRANSFORM(145, trans, move);
  d = AFFINE_TRANSFORM(162, trans, move);
  E = AFFINE_TRANSFORM(127, trans, move);

  return play_attack_defend2_n(color, 1, 4, a, b, c, d, d, b) && !play_attack_defend2_n(color, 0, 3, a, c, b, c, E);
}

static int
autohelperbarrierspat59(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(94, trans, move);
  b = AFFINE_TRANSFORM(110, trans, move);

  return !play_attack_defend_n(color, 1, 1, a, b);
}

static int
autohelperbarrierspat61(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(144, trans, move);

  return play_attack_defend_n(color, 1, 1, a, a);
}

static int
autohelperbarrierspat62(int trans, int move, int color, int action)
{
  int b, c, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(144, trans, move);
  c = AFFINE_TRANSFORM(195, trans, move);
  A = AFFINE_TRANSFORM(161, trans, move);

  return countlib(A)<=3 && countlib(b)>=3 && countlib(c)>=3;
}

static int
autohelperbarrierspat63(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(162, trans, move);
  b = AFFINE_TRANSFORM(144, trans, move);

  return !play_attack_defend_n(color, 1, 1, a, b);
}

static int
autohelperbarrierspat64(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(145, trans, move);

  return safe_move(a, color);
}

static int
autohelperbarrierspat65(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(144, trans, move);

  return countlib(A)==1;
}

static int
autohelperbarrierspat66(int trans, int move, int color, int action)
{
  int b, c, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(143, trans, move);
  c = AFFINE_TRANSFORM(177, trans, move);
  A = AFFINE_TRANSFORM(160, trans, move);

  return countlib(A)<=2 && countlib(b)>1 && countlib(c)>1;
}

static int
autohelperbarrierspat67(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(142, trans, move);
  b = AFFINE_TRANSFORM(159, trans, move);

  return play_attack_defend_n(color, 1, 2, a, b, b);
}

static int
autohelperbarrierspat73(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(145, trans, move);
  c = AFFINE_TRANSFORM(144, trans, move);

  return !play_attack_defend_n(color, 1, 3, a, b, c, c);
}

static int
autohelperbarrierspat74(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(129, trans, move);
  C = AFFINE_TRANSFORM(111, trans, move);

  return play_attack_defend_n(color, 1, 2, a, b, C);
}

static int
autohelperbarrierspat77(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(91, trans, move);
  b = AFFINE_TRANSFORM(74, trans, move);
  c = AFFINE_TRANSFORM(73, trans, move);

  return (countlib(a)>2 || (countlib(a) == 2 && connect_and_cut_helper(a, b, c)));;

  return 0;
}

static int
autohelperbarrierspat78(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);

  a = AFFINE_TRANSFORM(108, trans, move);
  b = AFFINE_TRANSFORM(91, trans, move);
  c = AFFINE_TRANSFORM(90, trans, move);

  if (!action)
    return safe_move(c, color);
  return (countlib(a)>2 || (countlib(a) == 2 && connect_and_cut_helper(a, b, c)));;

  return 0;
}

static int
autohelperbarrierspat79(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(91, trans, move);
  b = AFFINE_TRANSFORM(74, trans, move);
  c = AFFINE_TRANSFORM(73, trans, move);

  return (countlib(a)>2 || (countlib(a) == 2 && connect_and_cut_helper(a, b, c)));;

  return 0;
}

static int
autohelperbarrierspat80(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);

  a = AFFINE_TRANSFORM(57, trans, move);
  b = AFFINE_TRANSFORM(91, trans, move);
  c = AFFINE_TRANSFORM(74, trans, move);
  d = AFFINE_TRANSFORM(73, trans, move);

  if (!action)
    return safe_move(a, color);
  return (countlib(b)>2 || (countlib(b) == 2 && connect_and_cut_helper(b, c, d)));;

  return 0;
}

static int
autohelperbarrierspat81(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(39, trans, move);
  b = AFFINE_TRANSFORM(74, trans, move);
  c = AFFINE_TRANSFORM(73, trans, move);

  return !play_attack_defend_n(color, 0, 3, a, b, c, b);
}

static int
autohelperbarrierspat82(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);

  a = AFFINE_TRANSFORM(42, trans, move);
  b = AFFINE_TRANSFORM(75, trans, move);
  c = AFFINE_TRANSFORM(76, trans, move);
  d = AFFINE_TRANSFORM(92, trans, move);

  if (!action)
    return !play_attack_defend_n(color, 1, 3, a, b, c, d);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, b, d));;

  return 0;
}

static int
autohelperbarrierspat83(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);

  a = AFFINE_TRANSFORM(42, trans, move);
  b = AFFINE_TRANSFORM(75, trans, move);
  c = AFFINE_TRANSFORM(76, trans, move);
  d = AFFINE_TRANSFORM(92, trans, move);

  if (!action)
    return !play_attack_defend_n(color, 1, 3, a, b, c, d);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, b, d));;

  return 0;
}

static int
autohelperbarrierspat84(int trans, int move, int color, int action)
{
  int a, b, d, C;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);
  d = AFFINE_TRANSFORM(127, trans, move);
  C = AFFINE_TRANSFORM(145, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 2, a, b, C);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, d));;

  return 0;
}

static int
autohelperbarrierspat85(int trans, int move, int color, int action)
{
  int a, b, d, C;
  UNUSED(color);

  a = AFFINE_TRANSFORM(94, trans, move);
  b = AFFINE_TRANSFORM(93, trans, move);
  d = AFFINE_TRANSFORM(110, trans, move);
  C = AFFINE_TRANSFORM(111, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 2, a, b, C);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, b, d));;

  return 0;
}

static int
autohelperbarrierspat86(int trans, int move, int color, int action)
{
  int a, b, c, f, D, E;
  UNUSED(color);

  a = AFFINE_TRANSFORM(111, trans, move);
  b = AFFINE_TRANSFORM(110, trans, move);
  c = AFFINE_TRANSFORM(145, trans, move);
  f = AFFINE_TRANSFORM(127, trans, move);
  D = AFFINE_TRANSFORM(128, trans, move);
  E = AFFINE_TRANSFORM(144, trans, move);

  if (!action)
    return !play_attack_defend2_n(color, 0, 3, a, b, c, D, E);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, b, f));;

  return 0;
}

static int
autohelperbarrierspat87(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(127, trans, move);
  b = AFFINE_TRANSFORM(128, trans, move);

  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, b, a));;

  return 0;
}

static int
autohelperbarrierspat88(int trans, int move, int color, int action)
{
  int a, b, c, C;
  UNUSED(color);

  a = AFFINE_TRANSFORM(162, trans, move);
  b = AFFINE_TRANSFORM(145, trans, move);
  c = AFFINE_TRANSFORM(144, trans, move);
  C = AFFINE_TRANSFORM(161, trans, move);

  if (!action)
    return play_attack_defend2_n(color, 1, 2, a, b, C, b);;
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, b, c));;

  return 0;
}

static int
autohelperbarrierspat89(int trans, int move, int color, int action)
{
  int a, c, B;
  UNUSED(color);

  a = AFFINE_TRANSFORM(160, trans, move);
  c = AFFINE_TRANSFORM(143, trans, move);
  B = AFFINE_TRANSFORM(142, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 1, a, B) && !ATTACK_MACRO(B);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, c));;

  return 0;
}

static int
autohelperbarrierspat90(int trans, int move, int color, int action)
{
  int a, c, B;
  UNUSED(color);

  a = AFFINE_TRANSFORM(160, trans, move);
  c = AFFINE_TRANSFORM(143, trans, move);
  B = AFFINE_TRANSFORM(159, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 1, a, B) && !ATTACK_MACRO(B);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, c));;

  return 0;
}

static int
autohelperbarrierspat91(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(161, trans, move);
  b = AFFINE_TRANSFORM(144, trans, move);
  C = AFFINE_TRANSFORM(160, trans, move);

  return play_attack_defend_n(color, 1, 2, a, b, C);
}

static int
autohelperbarrierspat92(int trans, int move, int color, int action)
{
  int a, b, d, e, f, g, h, C;
  UNUSED(color);

  a = AFFINE_TRANSFORM(74, trans, move);
  b = AFFINE_TRANSFORM(57, trans, move);
  d = AFFINE_TRANSFORM(91, trans, move);
  e = AFFINE_TRANSFORM(89, trans, move);
  f = AFFINE_TRANSFORM(106, trans, move);
  g = AFFINE_TRANSFORM(107, trans, move);
  h = AFFINE_TRANSFORM(108, trans, move);
  C = AFFINE_TRANSFORM(73, trans, move);

  if (!action)
    return play_attack_defend2_n(color, 1, 2, a, b, b, C);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, d) && somewhere(color, 0, 4, g, e, f, h));;

  return 0;
}

static int
autohelperbarrierspat93(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(145, trans, move);
  b = AFFINE_TRANSFORM(144, trans, move);
  c = AFFINE_TRANSFORM(111, trans, move);
  d = AFFINE_TRANSFORM(110, trans, move);

  return play_attack_defend_n(color, 1, 2, a, b, b) && play_attack_defend_n(color, 1, 2, c, d, d);
}

static int
autohelperbarrierspat94(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(145, trans, move);
  b = AFFINE_TRANSFORM(144, trans, move);
  c = AFFINE_TRANSFORM(111, trans, move);
  d = AFFINE_TRANSFORM(110, trans, move);

  return play_attack_defend_n(color, 1, 2, a, b, b) || play_attack_defend_n(color, 1, 2, c, d, d);
}

static int
autohelperbarrierspat95(int trans, int move, int color, int action)
{
  int a, b, d, C;
  UNUSED(color);

  a = AFFINE_TRANSFORM(145, trans, move);
  b = AFFINE_TRANSFORM(144, trans, move);
  d = AFFINE_TRANSFORM(127, trans, move);
  C = AFFINE_TRANSFORM(128, trans, move);

  if (!action)
    return somewhere(color, 0, 1, b) || play_attack_defend2_n(color, 1, 2, a, b, b, C);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, b, d));;

  return 0;
}

static int
autohelperbarrierspat96(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(93, trans, move);
  b = AFFINE_TRANSFORM(59, trans, move);

  return countlib(a)>=2 && countlib(b)>=2;
}

static int
autohelperbarrierspat97(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(129, trans, move);
  c = AFFINE_TRANSFORM(146, trans, move);
  d = AFFINE_TRANSFORM(162, trans, move);

  return play_attack_defend2_n(color, 1, 4, a, b, c, d, b, d);
}

static int
autohelperbarrierspat98(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);

  a = AFFINE_TRANSFORM(111, trans, move);
  b = AFFINE_TRANSFORM(129, trans, move);
  c = AFFINE_TRANSFORM(112, trans, move);
  d = AFFINE_TRANSFORM(145, trans, move);
  e = AFFINE_TRANSFORM(127, trans, move);

  if (!action)
    return !play_attack_defend_n(color, 1, 3, a, b, c, a);
  return (countlib(d)>2 && countlib(e)>2 && !play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, e));;

  return 0;
}

static int
autohelperbarrierspat102(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(160, trans, move);
  b = AFFINE_TRANSFORM(143, trans, move);

  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b));;

  return 0;
}

static int
autohelperbarrierspat103(int trans, int move, int color, int action)
{
  int b, c, d, e, f, A;
  UNUSED(color);

  b = AFFINE_TRANSFORM(145, trans, move);
  c = AFFINE_TRANSFORM(144, trans, move);
  d = AFFINE_TRANSFORM(127, trans, move);
  e = AFFINE_TRANSFORM(110, trans, move);
  f = AFFINE_TRANSFORM(111, trans, move);
  A = AFFINE_TRANSFORM(128, trans, move);

  if (!action)
    return countlib(A)==2 && !play_attack_defend_n(color, 1, 1, b, b);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, c, d) && play_attack_defend2_n(OTHER_COLOR(color), 0, 1, e, d, f));;

  return 0;
}

static int
autohelperbarrierspat104(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(145, trans, move);
  b = AFFINE_TRANSFORM(144, trans, move);

  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b));;

  return 0;
}

static int
autohelperbarrierspat105(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(160, trans, move);
  b = AFFINE_TRANSFORM(143, trans, move);

  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b));;

  return 0;
}

static int
autohelperbarrierspat106(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(145, trans, move);
  b = AFFINE_TRANSFORM(144, trans, move);

  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b));;

  return 0;
}

static int
autohelperbarrierspat107(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);

  a = AFFINE_TRANSFORM(179, trans, move);
  b = AFFINE_TRANSFORM(161, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);
  d = AFFINE_TRANSFORM(145, trans, move);
  e = AFFINE_TRANSFORM(144, trans, move);

  if (!action)
    return play_attack_defend2_n(color, 1, 4, a, b, c, d, b, d);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, b, e));;

  return 0;
}

static int
autohelperbarrierspat108(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(159, trans, move);
  b = AFFINE_TRANSFORM(142, trans, move);

  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b));;

  return 0;
}

static int
autohelperbarrierspat112(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(111, trans, move);
  b = AFFINE_TRANSFORM(112, trans, move);
  c = AFFINE_TRANSFORM(95, trans, move);
  d = AFFINE_TRANSFORM(94, trans, move);

  return play_attack_defend2_n(color, 1, 4, a, b, c, d, b, d);
}

static int
autohelperbarrierspat114(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(127, trans, move);
  b = AFFINE_TRANSFORM(126, trans, move);
  c = AFFINE_TRANSFORM(143, trans, move);
  d = AFFINE_TRANSFORM(109, trans, move);
  e = AFFINE_TRANSFORM(144, trans, move);
  f = AFFINE_TRANSFORM(142, trans, move);

  return play_attack_defend_n(color, 1, 6, a, b, c, d, e, f, f);
}

static int
autohelperbarrierspat115(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);

  a = AFFINE_TRANSFORM(127, trans, move);
  b = AFFINE_TRANSFORM(126, trans, move);
  c = AFFINE_TRANSFORM(125, trans, move);

  if (!action)
    return play_connect_n(color, 1, 2, a, b, a, c);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, b, c));

  return 0;
}

static int
autohelperbarrierspat116(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(127, trans, move);
  b = AFFINE_TRANSFORM(126, trans, move);

  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b));;

  return 0;
}

static int
autohelperbarrierspat117(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(127, trans, move);
  b = AFFINE_TRANSFORM(126, trans, move);

  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b));;

  return 0;
}

static int
autohelperbarrierspat119(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(127, trans, move);
  b = AFFINE_TRANSFORM(125, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 2, a, b, b);
  return 0;;

  return 0;
}

static int
autohelperbarrierspat120(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(75, trans, move);
  b = AFFINE_TRANSFORM(58, trans, move);
  c = AFFINE_TRANSFORM(93, trans, move);
  d = AFFINE_TRANSFORM(94, trans, move);
  e = AFFINE_TRANSFORM(77, trans, move);
  f = AFFINE_TRANSFORM(59, trans, move);

  return play_attack_defend_n(color, 1, 6, a, b, c, d, e, f, d);
}

static int
autohelperbarrierspat121(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(160, trans, move);
  b = AFFINE_TRANSFORM(143, trans, move);

  if (!action)
    return safe_move(a, color);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b));;

  return 0;
}

static int
autohelperbarrierspat122(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(160, trans, move);
  b = AFFINE_TRANSFORM(143, trans, move);

  if (!action)
    return safe_move(a, color);
   return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b));;

  return 0;
}

static int
autohelperbarrierspat123(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(109, trans, move);
  b = AFFINE_TRANSFORM(126, trans, move);

  if (!action)
    return safe_move(a, color);
   return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b));;

  return 0;
}

static int
autohelperbarrierspat124(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(160, trans, move);
  b = AFFINE_TRANSFORM(143, trans, move);

  if (!action)
    return safe_move(a, color);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b));;

  return 0;
}

static int
autohelperbarrierspat125(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(142, trans, move);

  return countlib(A)==1 && ATTACK_MACRO(A);
}

static int
autohelperbarrierspat126(int trans, int move, int color, int action)
{
  int A;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(142, trans, move);

  return countlib(A)==1;
}

static int
autohelperbarrierspat127(int trans, int move, int color, int action)
{
  int a, b, c, e, D;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(93, trans, move);
  b = AFFINE_TRANSFORM(75, trans, move);
  c = AFFINE_TRANSFORM(127, trans, move);
  e = AFFINE_TRANSFORM(108, trans, move);
  D = AFFINE_TRANSFORM(110, trans, move);

  return (somewhere(color, 0, 1, e) || !safe_move(e, OTHER_COLOR(color))) && !play_attack_defend_n(color, 0, 3, a, b, c, D);
}

static int
autohelperbarrierspat128(int trans, int move, int color, int action)
{
  int b, c, d, A;
  UNUSED(color);
  UNUSED(action);

  b = AFFINE_TRANSFORM(76, trans, move);
  c = AFFINE_TRANSFORM(58, trans, move);
  d = AFFINE_TRANSFORM(59, trans, move);
  A = AFFINE_TRANSFORM(74, trans, move);

  return countlib(A)==2 && !ATTACK_MACRO(A) && !play_attack_defend_n(color, 1, 3, b, c, d, d);
}

static int
autohelperbarrierspat129(int trans, int move, int color, int action)
{
  int a, b, c, e, f, D;
  UNUSED(color);

  a = AFFINE_TRANSFORM(94, trans, move);
  b = AFFINE_TRANSFORM(77, trans, move);
  c = AFFINE_TRANSFORM(76, trans, move);
  e = AFFINE_TRANSFORM(111, trans, move);
  f = AFFINE_TRANSFORM(110, trans, move);
  D = AFFINE_TRANSFORM(93, trans, move);

  if (!action)
    return safe_move(a, color)&& (somewhere(color, 0, 1, e) || play_attack_defend_n(color, 1, 2, a, e, e))&& !play_attack_defend2_n(color, 0, 3, a, b, c, b, D);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, f) && (somewhere(color, 0, 1, e) || (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, e, f))));;

  return 0;
}

static int
autohelperbarrierspat130(int trans, int move, int color, int action)
{
  int a, b, c, d, e, h, F, G;
  UNUSED(color);

  a = AFFINE_TRANSFORM(93, trans, move);
  b = AFFINE_TRANSFORM(110, trans, move);
  c = AFFINE_TRANSFORM(76, trans, move);
  d = AFFINE_TRANSFORM(91, trans, move);
  e = AFFINE_TRANSFORM(75, trans, move);
  h = AFFINE_TRANSFORM(109, trans, move);
  F = AFFINE_TRANSFORM(92, trans, move);
  G = AFFINE_TRANSFORM(108, trans, move);

  if (!action)
    return safe_move(a, color)&& (somewhere(color, 0, 1, b) || play_attack_defend_n(color, 1, 2, a, b, b))&& !play_attack_defend2_n(color, 0, 4, a, c, d, e, F, G);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, h));;

  return 0;
}

static int
autohelperbarrierspat131(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(94, trans, move);
  b = AFFINE_TRANSFORM(93, trans, move);
  C = AFFINE_TRANSFORM(111, trans, move);

  return safe_move(a, color) && play_attack_defend_n(color, 1, 2, a, b, C);
}

static int
autohelperbarrierspat132(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(127, trans, move);
  c = AFFINE_TRANSFORM(94, trans, move);
  d = AFFINE_TRANSFORM(110, trans, move);

  return !play_attack_defend_n(color, 1, 3, a, b, c, d);
}

static int
autohelperbarrierspat133(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(142, trans, move);

  return countlib(a)>2;
}

static int
autohelperbarrierspat135(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(110, trans, move);
  c = AFFINE_TRANSFORM(127, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 1, a, b) && ! ATTACK_MACRO(b);
  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, c));;

  return 0;
}

static int
autohelperbarrierspat136(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(177, trans, move);
  b = AFFINE_TRANSFORM(161, trans, move);
  c = AFFINE_TRANSFORM(159, trans, move);
  d = AFFINE_TRANSFORM(143, trans, move);

  return !play_attack_defend2_n(color, 1, 3, a, b, c, c, d);
}

static int
autohelperbarrierspat137(int trans, int move, int color, int action)
{
  int a, b, e, C, D;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(129, trans, move);
  e = AFFINE_TRANSFORM(127, trans, move);
  C = AFFINE_TRANSFORM(111, trans, move);
  D = AFFINE_TRANSFORM(145, trans, move);

  if (!action)
    return play_break_through_n(color, 2, a, b, C, b, D);
  return(!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, e));;

  return 0;
}

static int
autohelperbarrierspat138(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(109, trans, move);
  b = AFFINE_TRANSFORM(127, trans, move);
  c = AFFINE_TRANSFORM(143, trans, move);
  d = AFFINE_TRANSFORM(110, trans, move);
  e = AFFINE_TRANSFORM(144, trans, move);

  return  (play_break_through_n(color, 0, a, b, c)==WIN  && (!is_ko_point(a) || play_attack_defend2_n(color, 1, 1, d, b, c))  && (!is_ko_point(c) || play_attack_defend2_n(color, 1, 1, e, b, a)));
}

static int
autohelperbarrierspat139(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(160, trans, move);
  b = AFFINE_TRANSFORM(143, trans, move);

  return (!play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b));;

  return 0;
}

static int
autohelperbarrierspat140(int trans, int move, int color, int action)
{
  int a, B;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(159, trans, move);
  B = AFFINE_TRANSFORM(160, trans, move);

  return !play_attack_defend_n(color, 0, 1, a, B);
}

static int
autohelperbarrierspat141(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, G;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(110, trans, move);
  b = AFFINE_TRANSFORM(126, trans, move);
  c = AFFINE_TRANSFORM(127, trans, move);
  d = AFFINE_TRANSFORM(93, trans, move);
  e = AFFINE_TRANSFORM(91, trans, move);
  f = AFFINE_TRANSFORM(75, trans, move);
  G = AFFINE_TRANSFORM(108, trans, move);

  return (somewhere(color, 0, 1, a) || somewhere(color, 0, 1, b) || somewhere(color, 0, 1, c))&& (somewhere(color, 0, 1, a) || play_attack_defend_n(color, 1, 2, d, a, a)) && play_attack_defend_n(color, 1, 2, e, f, G);
}

static int
autohelperbarrierspat142(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, g;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(56, trans, move);
  b = AFFINE_TRANSFORM(37, trans, move);
  c = AFFINE_TRANSFORM(54, trans, move);
  d = AFFINE_TRANSFORM(71, trans, move);
  e = AFFINE_TRANSFORM(36, trans, move);
  f = AFFINE_TRANSFORM(53, trans, move);
  g = AFFINE_TRANSFORM(70, trans, move);

  return somewhere(OTHER_COLOR(color), 0, 6, b, c, d, e, f, g) && safe_move(a, color);
}

static int
autohelperbarrierspat143(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, g, h;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(38, trans, move);
  b = AFFINE_TRANSFORM(90, trans, move);
  c = AFFINE_TRANSFORM(37, trans, move);
  d = AFFINE_TRANSFORM(54, trans, move);
  e = AFFINE_TRANSFORM(71, trans, move);
  f = AFFINE_TRANSFORM(36, trans, move);
  g = AFFINE_TRANSFORM(53, trans, move);
  h = AFFINE_TRANSFORM(70, trans, move);

  return somewhere(OTHER_COLOR(color), 0, 6, c, d, e, f, g, h) && !play_connect_n(color, 0, 1, a, a, b);
}

static int
autohelperbarrierspat144(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(109, trans, move);
  b = AFFINE_TRANSFORM(126, trans, move);

  if (!action)
    return safe_move(a, color);
  return !play_attack_defend_n(OTHER_COLOR(color), 1, 1, a, b);;

  return 0;
}

static int
autohelperbarrierspat145(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f, g;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(93, trans, move);
  b = AFFINE_TRANSFORM(75, trans, move);
  c = AFFINE_TRANSFORM(127, trans, move);
  d = AFFINE_TRANSFORM(111, trans, move);
  e = AFFINE_TRANSFORM(128, trans, move);
  f = AFFINE_TRANSFORM(109, trans, move);
  g = AFFINE_TRANSFORM(91, trans, move);

  return !play_connect_n(color, 0, 0, f, g) && !play_connect_n(color, 0, 5, a, b, c, d, e, c, f);
}

static int
autohelperbarrierspat146(int trans, int move, int color, int action)
{
  int A, B;
  UNUSED(color);
  UNUSED(action);

  A = AFFINE_TRANSFORM(107, trans, move);
  B = AFFINE_TRANSFORM(157, trans, move);

  return !ATTACK_MACRO(A) && play_connect_n(color, 0, 0, A, B) && !ATTACK_MACRO(B);
}

static int
autohelperbarrierspat148(int trans, int move, int color, int action)
{
  int a, b, c, D, E;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(123, trans, move);
  b = AFFINE_TRANSFORM(107, trans, move);
  c = AFFINE_TRANSFORM(141, trans, move);
  D = AFFINE_TRANSFORM(142, trans, move);
  E = AFFINE_TRANSFORM(124, trans, move);

  return !play_connect_n(color, 1, 3, a, b, c, D, E);
}

static int
autohelperbarrierspat149(int trans, int move, int color, int action)
{
  int a, b, c, D;
  UNUSED(color);

  a = AFFINE_TRANSFORM(143, trans, move);
  b = AFFINE_TRANSFORM(109, trans, move);
  c = AFFINE_TRANSFORM(110, trans, move);
  D = AFFINE_TRANSFORM(127, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 2, c, b, D);
  return !safe_move(a, OTHER_COLOR(color)) && !play_attack_defend2_n(color, 0, 3, c, b, a, b, D);;

  return 0;
}

static int
autohelperbarrierspat150(int trans, int move, int color, int action)
{
  int a, b, c, D;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(109, trans, move);
  b = AFFINE_TRANSFORM(143, trans, move);
  c = AFFINE_TRANSFORM(158, trans, move);
  D = AFFINE_TRANSFORM(175, trans, move);

  return accuratelib(a, color, MAX_LIBERTIES, NULL)>1 && !play_connect_n(color, 1, 3, a, b, c, b, D);
}

static int
autohelperbarrierspat151(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(161, trans, move);
  b = AFFINE_TRANSFORM(162, trans, move);

  if (!false_eye_territory[a]) influence_mark_non_territory(a, color);if (!false_eye_territory[b]) influence_mark_non_territory(b, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat152(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(162, trans, move);
  b = AFFINE_TRANSFORM(178, trans, move);

  if ((is_halfeye(half_eye,a) || is_false_eye(half_eye, a)) && safe_move(b, color)    && !false_eye_territory[a]) influence_mark_non_territory(a, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat153(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(162, trans, move);

  if (is_false_eye(half_eye, a)    && !false_eye_territory[a]) influence_mark_non_territory(a, color);;

  return 0;
}

static int
autohelperbarrierspat154(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(94, trans, move);

  if (!false_eye_territory[a]) influence_mark_non_territory(a, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat155(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(94, trans, move);

  if (!false_eye_territory[a]) influence_mark_non_territory(a, color);;

  return 0;
}

static int
autohelperbarrierspat156(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(110, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);

  if (!false_eye_territory[a]) influence_mark_non_territory(a, color);if (!false_eye_territory[b]) influence_mark_non_territory(b, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat157(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(111, trans, move);
  b = AFFINE_TRANSFORM(128, trans, move);

  influence_mark_non_territory(a, OTHER_COLOR(color));influence_mark_non_territory(b, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat158(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(111, trans, move);
  b = AFFINE_TRANSFORM(128, trans, move);

  influence_mark_non_territory(a, color);influence_mark_non_territory(b, color);;

  return 0;
}

static int
autohelperbarrierspat159(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);

  if (!action)
    return safe_move(a, color);
  influence_mark_non_territory(a, OTHER_COLOR(color));influence_mark_non_territory(b, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat160(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);
  c = AFFINE_TRANSFORM(110, trans, move);

  if (!action)
    return safe_move(a, color) && play_attack_defend_n(color, 1, 3, a, b, c, a) && connect_and_cut_helper2(a, b, c, color);
  influence_mark_non_territory(c, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat161(int trans, int move, int color, int action)
{
  int a, b, c, e, D;
  UNUSED(color);

  a = AFFINE_TRANSFORM(111, trans, move);
  b = AFFINE_TRANSFORM(94, trans, move);
  c = AFFINE_TRANSFORM(93, trans, move);
  e = AFFINE_TRANSFORM(77, trans, move);
  D = AFFINE_TRANSFORM(110, trans, move);

  if (!action)
    return !play_attack_defend2_n(color, 0, 3, a, b, c, b, D);
  influence_mark_non_territory(b, OTHER_COLOR(color));influence_mark_non_territory(c, OTHER_COLOR(color));influence_mark_non_territory(e, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat162(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);

  if (!action)
    return safe_move(a, color);
  influence_mark_non_territory(a, OTHER_COLOR(color));influence_mark_non_territory(b, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat163(int trans, int move, int color, int action)
{
  int a, b, c, d, E;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);
  c = AFFINE_TRANSFORM(145, trans, move);
  d = AFFINE_TRANSFORM(110, trans, move);
  E = AFFINE_TRANSFORM(127, trans, move);

  if (!action)
    return safe_move(a, color) && !play_attack_defend2_n(color, 0, 5, a, b, c, NO_MOVE, d, b, E);
  influence_mark_non_territory(d, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat164(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);

  a = AFFINE_TRANSFORM(77, trans, move);
  b = AFFINE_TRANSFORM(76, trans, move);
  c = AFFINE_TRANSFORM(59, trans, move);

  if (!action)
    return safe_move(a, color);
  influence_mark_non_territory(b, OTHER_COLOR(color));influence_mark_non_territory(c, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat165(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);

  a = AFFINE_TRANSFORM(158, trans, move);
  b = AFFINE_TRANSFORM(175, trans, move);
  c = AFFINE_TRANSFORM(141, trans, move);
  d = AFFINE_TRANSFORM(157, trans, move);
  e = AFFINE_TRANSFORM(140, trans, move);

  if (!action)
    return safe_move(a, color);
  influence_mark_non_territory(b, OTHER_COLOR(color));influence_mark_non_territory(c, OTHER_COLOR(color));influence_mark_non_territory(d, OTHER_COLOR(color));influence_mark_non_territory(e, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat166(int trans, int move, int color, int action)
{
  int a, c, B;
  UNUSED(color);

  a = AFFINE_TRANSFORM(112, trans, move);
  c = AFFINE_TRANSFORM(145, trans, move);
  B = AFFINE_TRANSFORM(128, trans, move);

  if (!action)
    return safe_move(a, color) && play_attack_defend_n(color, 1, 1, a, B);
  influence_mark_non_territory(c, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat167(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(160, trans, move);
  b = AFFINE_TRANSFORM(142, trans, move);
  c = AFFINE_TRANSFORM(159, trans, move);

  influence_mark_non_territory(a, OTHER_COLOR(color));influence_mark_non_territory(b, OTHER_COLOR(color));influence_mark_non_territory(c, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat168(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(142, trans, move);
  b = AFFINE_TRANSFORM(160, trans, move);

  influence_mark_non_territory(a, color);influence_mark_non_territory(b, color);;

  return 0;
}

static int
autohelperbarrierspat169(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);

  a = AFFINE_TRANSFORM(141, trans, move);
  b = AFFINE_TRANSFORM(158, trans, move);
  c = AFFINE_TRANSFORM(140, trans, move);

  if (!action)
    return safe_move(a, color);
  influence_mark_non_territory(a, OTHER_COLOR(color));influence_mark_non_territory(b, OTHER_COLOR(color));influence_mark_non_territory(c, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat170(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f;
  UNUSED(color);

  a = AFFINE_TRANSFORM(140, trans, move);
  b = AFFINE_TRANSFORM(157, trans, move);
  c = AFFINE_TRANSFORM(139, trans, move);
  d = AFFINE_TRANSFORM(156, trans, move);
  e = AFFINE_TRANSFORM(138, trans, move);
  f = AFFINE_TRANSFORM(155, trans, move);

  if (!action)
    return safe_move(a, color);
  influence_mark_non_territory(a, OTHER_COLOR(color));influence_mark_non_territory(b, OTHER_COLOR(color));influence_mark_non_territory(c, OTHER_COLOR(color));influence_mark_non_territory(d, OTHER_COLOR(color));influence_mark_non_territory(e, OTHER_COLOR(color));influence_mark_non_territory(f, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat171(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);

  a = AFFINE_TRANSFORM(110, trans, move);
  b = AFFINE_TRANSFORM(127, trans, move);
  c = AFFINE_TRANSFORM(109, trans, move);
  d = AFFINE_TRANSFORM(126, trans, move);
  e = AFFINE_TRANSFORM(108, trans, move);

  if (!action)
    return safe_move(a, color);
  influence_mark_non_territory(a, OTHER_COLOR(color));influence_mark_non_territory(b, OTHER_COLOR(color));influence_mark_non_territory(c, OTHER_COLOR(color));influence_mark_non_territory(d, OTHER_COLOR(color));influence_mark_non_territory(e, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat172(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);

  a = AFFINE_TRANSFORM(142, trans, move);
  b = AFFINE_TRANSFORM(144, trans, move);
  c = AFFINE_TRANSFORM(159, trans, move);
  d = AFFINE_TRANSFORM(160, trans, move);

  if (!action)
    return !play_attack_defend2_n(color, 0, 4, a, b, NO_MOVE, c, a, d);
  influence_mark_non_territory(a, color);influence_mark_non_territory(c, color);;

  return 0;
}

static int
autohelperbarrierspat173(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);

  a = AFFINE_TRANSFORM(161, trans, move);
  b = AFFINE_TRANSFORM(144, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);

  if (!action)
    return !play_attack_defend2_n(OTHER_COLOR(color), 0, 1, a, b, c);
  influence_mark_non_territory(a, color);;

  return 0;
}

static int
autohelperbarrierspat174(int trans, int move, int color, int action)
{
  int a, b, c, d, E;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);
  c = AFFINE_TRANSFORM(145, trans, move);
  d = AFFINE_TRANSFORM(110, trans, move);
  E = AFFINE_TRANSFORM(127, trans, move);

  if (!action)
    return !play_attack_defend2_n(color, 0, 5, a, b, c, NO_MOVE, d, b, E);
  influence_mark_non_territory(a, OTHER_COLOR(color));influence_mark_non_territory(b, OTHER_COLOR(color));influence_mark_non_territory(d, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat175(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f;
  UNUSED(color);

  a = AFFINE_TRANSFORM(111, trans, move);
  b = AFFINE_TRANSFORM(93, trans, move);
  c = AFFINE_TRANSFORM(94, trans, move);
  d = AFFINE_TRANSFORM(77, trans, move);
  e = AFFINE_TRANSFORM(128, trans, move);
  f = AFFINE_TRANSFORM(76, trans, move);

  if (!action)
    return !play_attack_defend2_n(color, 0, 7, a, b, c, d, e, NO_MOVE, f, d, b);
  influence_mark_non_territory(a, OTHER_COLOR(color));influence_mark_non_territory(b, OTHER_COLOR(color));influence_mark_non_territory(c, OTHER_COLOR(color));influence_mark_non_territory(d, OTHER_COLOR(color));influence_mark_non_territory(f, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat176(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(145, trans, move);
  b = AFFINE_TRANSFORM(143, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 2, move, a, a) && safe_move(move, color);
  influence_mark_non_territory(move, OTHER_COLOR(color));influence_mark_non_territory(b, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat177(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(145, trans, move);
  b = AFFINE_TRANSFORM(162, trans, move);

  if (!action)
    return ATTACK_MACRO(b) && play_attack_defend_n(color, 1, 1, move, b);
  influence_mark_non_territory(a, color);;

  return 0;
}

static int
autohelperbarrierspat178(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);

  a = AFFINE_TRANSFORM(109, trans, move);
  b = AFFINE_TRANSFORM(125, trans, move);
  c = AFFINE_TRANSFORM(108, trans, move);

  if (!action)
    return !play_attack_defend_n(color, 1, 2, a, b, b) && !play_attack_defend_n(color, 1, 2, b, a, a);
  influence_mark_non_territory(a, color);influence_mark_non_territory(b, color);influence_mark_non_territory(c, color);;

  return 0;
}

static int
autohelperbarrierspat179(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);

  a = AFFINE_TRANSFORM(143, trans, move);

  if (!action)
    return safe_move(move, color);
  influence_mark_non_territory(move, OTHER_COLOR(color));influence_mark_non_territory(a, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat180(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(161, trans, move);

  influence_mark_non_territory(a, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat181(int trans, int move, int color, int action)
{
  int a;
  UNUSED(color);
  UNUSED(action);

  a = AFFINE_TRANSFORM(161, trans, move);

  influence_mark_non_territory(a, color);;

  return 0;
}

static int
autohelperbarrierspat182(int trans, int move, int color, int action)
{
  int b, c, A;
  UNUSED(color);

  b = AFFINE_TRANSFORM(145, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);
  A = AFFINE_TRANSFORM(144, trans, move);

  if (!action)
    return countlib(A)==2 && connect_and_cut_helper(A, b, c);
  influence_mark_non_territory(b, color);influence_mark_non_territory(c, color);;

  return 0;
}

static int
autohelperbarrierspat183(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(93, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);

  if (!action)
    return safe_move(a, color);
  influence_mark_non_territory(b, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat184(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(161, trans, move);
  b = AFFINE_TRANSFORM(178, trans, move);

  if (!action)
    return safe_move(a, color);
  influence_mark_non_territory(b, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat185(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(161, trans, move);
  b = AFFINE_TRANSFORM(162, trans, move);

  if (!action)
    return safe_move(a, color);
  influence_mark_non_territory(b, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat186(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(145, trans, move);
  c = AFFINE_TRANSFORM(161, trans, move);

  if (!action)
    return !safe_move(a, color) && play_attack_defend_n(color, 1, 2, b, a, b);
  influence_mark_non_territory(b, color);influence_mark_non_territory(c, color);;

  return 0;
}

static int
autohelperbarrierspat187(int trans, int move, int color, int action)
{
  int a, b, c, d, E;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(145, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);
  d = AFFINE_TRANSFORM(161, trans, move);
  E = AFFINE_TRANSFORM(127, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 2, a, b, b) && !play_attack_defend_n(color, 1, 3, a, c, b, b) && play_attack_defend_n(color, 1, 3, a, c, b, E);
  influence_mark_non_territory(c, OTHER_COLOR(color));influence_mark_non_territory(d, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat188(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(145, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);
  d = AFFINE_TRANSFORM(178, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 2, a, b, b) && play_attack_defend_n(color, 1, 3, a, c, b, c);
  influence_mark_non_territory(c, OTHER_COLOR(color));influence_mark_non_territory(d, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat189(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);

  a = AFFINE_TRANSFORM(94, trans, move);
  b = AFFINE_TRANSFORM(95, trans, move);
  c = AFFINE_TRANSFORM(112, trans, move);
  d = AFFINE_TRANSFORM(77, trans, move);
  e = AFFINE_TRANSFORM(76, trans, move);

  if (!action)
    return !play_attack_defend_n(color, 1, 5, a, b, c, d, e, d);
  influence_mark_non_territory(a, color);influence_mark_non_territory(c, color);influence_mark_non_territory(e, color);;

  return 0;
}

static int
autohelperbarrierspat190(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);

  a = AFFINE_TRANSFORM(162, trans, move);
  b = AFFINE_TRANSFORM(163, trans, move);
  c = AFFINE_TRANSFORM(145, trans, move);
  d = AFFINE_TRANSFORM(146, trans, move);

  if (!action)
    return !play_attack_defend_n(color, 1, 3, a, b, c, a) && !play_attack_defend_n(color, 1, 3, a, c, b, a);
  influence_mark_non_territory(b, OTHER_COLOR(color));influence_mark_non_territory(c, OTHER_COLOR(color));influence_mark_non_territory(d, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat191(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);

  a = AFFINE_TRANSFORM(93, trans, move);
  b = AFFINE_TRANSFORM(95, trans, move);
  c = AFFINE_TRANSFORM(77, trans, move);

  if (!action)
    return safe_move(a, color)&& ((somewhere(OTHER_COLOR(color), 0, 1, b) && play_attack_defend_n(color, 1, 1, a, b))    || (!somewhere(OTHER_COLOR(color), 0, 1, b) && play_attack_defend_n(color, 1, 2, a, b, b)));
  influence_mark_non_territory(c, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat192(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);

  a = AFFINE_TRANSFORM(93, trans, move);
  b = AFFINE_TRANSFORM(94, trans, move);
  c = AFFINE_TRANSFORM(76, trans, move);
  d = AFFINE_TRANSFORM(77, trans, move);

  if (!action)
    return !play_attack_defend_n(color, 1, 3, a, b, c, a) && !play_attack_defend_n(color, 1, 3, a, c, b, a);
  influence_mark_non_territory(b, OTHER_COLOR(color));influence_mark_non_territory(c, OTHER_COLOR(color));influence_mark_non_territory(d, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat193(int trans, int move, int color, int action)
{
  int a, b;
  UNUSED(color);

  a = AFFINE_TRANSFORM(162, trans, move);
  b = AFFINE_TRANSFORM(145, trans, move);

  if (!action)
    return countlib(a)==2 && ATTACK_MACRO(a);
  influence_mark_non_territory(b, color);;

  return 0;
}

static int
autohelperbarrierspat194(int trans, int move, int color, int action)
{
  int a, c, B;
  UNUSED(color);

  a = AFFINE_TRANSFORM(161, trans, move);
  c = AFFINE_TRANSFORM(145, trans, move);
  B = AFFINE_TRANSFORM(162, trans, move);

  if (!action)
    return countlib(B)==3 && safe_move(a, color) && play_attack_defend_n(color, 1, 1, a, B);
  influence_mark_non_territory(c, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat195(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);

  a = AFFINE_TRANSFORM(163, trans, move);
  b = AFFINE_TRANSFORM(180, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);

  if (!action)
    return !play_attack_defend2_n(OTHER_COLOR(color), 0, 1, a, b, c);
  influence_mark_non_territory(a, color);;

  return 0;
}

static int
autohelperbarrierspat196(int trans, int move, int color, int action)
{
  int a, b, C, D;
  UNUSED(color);

  a = AFFINE_TRANSFORM(161, trans, move);
  b = AFFINE_TRANSFORM(163, trans, move);
  C = AFFINE_TRANSFORM(180, trans, move);
  D = AFFINE_TRANSFORM(162, trans, move);

  if (!action)
    return !play_attack_defend2_n(color, 0, 3, a, NO_MOVE, b, C, D);
  influence_mark_non_territory(b, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat197(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);

  a = AFFINE_TRANSFORM(129, trans, move);
  b = AFFINE_TRANSFORM(146, trans, move);
  c = AFFINE_TRANSFORM(145, trans, move);
  d = AFFINE_TRANSFORM(112, trans, move);
  e = AFFINE_TRANSFORM(130, trans, move);

  if (!action)
    return !play_attack_defend_n(color, 0, 4, a, b, c, d, a);
  influence_mark_non_territory(d, color);influence_mark_non_territory(e, color);;

  return 0;
}

static int
autohelperbarrierspat198(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);

  a = AFFINE_TRANSFORM(94, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);
  c = AFFINE_TRANSFORM(95, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 2, a, b, b);
  influence_mark_non_territory(c, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat199(int trans, int move, int color, int action)
{
  int a, b, c;
  UNUSED(color);

  a = AFFINE_TRANSFORM(145, trans, move);
  b = AFFINE_TRANSFORM(144, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);

  if (!action)
    return !play_attack_defend2_n(OTHER_COLOR(color), 0, 1, a, b, c) && !adjacent_to_defendable_stone_in_atari(b)&& !adjacent_to_defendable_stone_in_atari(c);
  influence_mark_non_territory(a, color);;

  return 0;
}

static int
autohelperbarrierspat200(int trans, int move, int color, int action)
{
  int a, b, c, D;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(145, trans, move);
  c = AFFINE_TRANSFORM(146, trans, move);
  D = AFFINE_TRANSFORM(144, trans, move);

  if (!action)
    return !play_attack_defend_n(color, 1, 1, b, D) && !play_attack_defend_n(color, 1, 2, b, c, c);
  influence_mark_non_territory(a, color);;

  return 0;
}

static int
autohelperbarrierspat201(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);

  a = AFFINE_TRANSFORM(180, trans, move);
  b = AFFINE_TRANSFORM(197, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);
  d = AFFINE_TRANSFORM(214, trans, move);
  e = AFFINE_TRANSFORM(145, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 2, a, b, c) && !play_attack_defend_n(color, 1, 2, b, d, d);
  influence_mark_non_territory(e, color);;

  return 0;
}

static int
autohelperbarrierspat202(int trans, int move, int color, int action)
{
  int a, b, C;
  UNUSED(color);

  a = AFFINE_TRANSFORM(161, trans, move);
  b = AFFINE_TRANSFORM(179, trans, move);
  C = AFFINE_TRANSFORM(162, trans, move);

  if (!action)
    return countlib(C)==2 && safe_move(a, color) && play_attack_defend_n(color, 1, 1, a, C) && !play_attack_defend_n(color, 1, 2, a, b, a);
  influence_mark_non_territory(b, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat203(int trans, int move, int color, int action)
{
  int a, b, c, d, e, f;
  UNUSED(color);

  a = AFFINE_TRANSFORM(94, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);
  c = AFFINE_TRANSFORM(95, trans, move);
  d = AFFINE_TRANSFORM(96, trans, move);
  e = AFFINE_TRANSFORM(112, trans, move);
  f = AFFINE_TRANSFORM(129, trans, move);

  if (!action)
    return play_attack_defend_n(color, 0, 6, a, b, c, d, e, f, a);
  influence_mark_non_territory(b, OTHER_COLOR(color));influence_mark_non_territory(c, OTHER_COLOR(color));influence_mark_non_territory(d, OTHER_COLOR(color));influence_mark_non_territory(e, OTHER_COLOR(color));influence_mark_non_territory(f, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat204(int trans, int move, int color, int action)
{
  int a, b, e, C, D;
  UNUSED(color);

  a = AFFINE_TRANSFORM(160, trans, move);
  b = AFFINE_TRANSFORM(194, trans, move);
  e = AFFINE_TRANSFORM(177, trans, move);
  C = AFFINE_TRANSFORM(143, trans, move);
  D = AFFINE_TRANSFORM(211, trans, move);

  if (!action)
    return !play_attack_defend_n(color, 1, 1, a, C) && !play_attack_defend_n(color, 1, 1, b, D);
  influence_mark_non_territory(e, color);;

  return 0;
}

static int
autohelperbarrierspat205(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);

  a = AFFINE_TRANSFORM(160, trans, move);
  b = AFFINE_TRANSFORM(177, trans, move);
  c = AFFINE_TRANSFORM(178, trans, move);
  d = AFFINE_TRANSFORM(159, trans, move);

  if (!action)
    return !play_attack_defend2_n(color, 0, 2, a, b, a, c);
  influence_mark_non_territory(b, color);influence_mark_non_territory(d, color);;

  return 0;
}

static int
autohelperbarrierspat206(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);
  c = AFFINE_TRANSFORM(129, trans, move);
  d = AFFINE_TRANSFORM(112, trans, move);

  if (!action)
    return !play_attack_defend_n(color, 1, 3, a, b, c, a) && !play_attack_defend_n(color, 1, 3, a, c, b, a);
  influence_mark_non_territory(d, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat207(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);

  a = AFFINE_TRANSFORM(111, trans, move);
  b = AFFINE_TRANSFORM(94, trans, move);
  c = AFFINE_TRANSFORM(112, trans, move);
  d = AFFINE_TRANSFORM(95, trans, move);

  if (!action)
    return !play_attack_defend_n(color, 1, 3, a, b, c, a) && !play_attack_defend_n(color, 1, 3, a, c, b, a);
  influence_mark_non_territory(d, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat208(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);

  a = AFFINE_TRANSFORM(145, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);
  c = AFFINE_TRANSFORM(112, trans, move);
  d = AFFINE_TRANSFORM(129, trans, move);

  if (!action)
    return !safe_move(a, color) && !play_attack_defend2_n(color, 0, 4, b, a, NO_MOVE, c, b, d);
  influence_mark_non_territory(c, color);;

  return 0;
}

static int
autohelperbarrierspat209(int trans, int move, int color, int action)
{
  int a, b, d, C;
  UNUSED(color);

  a = AFFINE_TRANSFORM(145, trans, move);
  b = AFFINE_TRANSFORM(179, trans, move);
  d = AFFINE_TRANSFORM(163, trans, move);
  C = AFFINE_TRANSFORM(162, trans, move);

  if (!action)
    return countlib(C)==2 && !adjacent_to_stone_in_atari(C) && !play_attack_defend2_n(color, 1, 1, a, a, b);
  influence_mark_non_territory(d, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat210(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);

  a = AFFINE_TRANSFORM(145, trans, move);
  b = AFFINE_TRANSFORM(161, trans, move);
  c = AFFINE_TRANSFORM(178, trans, move);
  d = AFFINE_TRANSFORM(163, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 2, a, b, b) && !play_attack_defend2_n(color, 1, 1, a, a, c);
  influence_mark_non_territory(d, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat211(int trans, int move, int color, int action)
{
  int a, b, c, e, D;
  UNUSED(color);

  a = AFFINE_TRANSFORM(162, trans, move);
  b = AFFINE_TRANSFORM(179, trans, move);
  c = AFFINE_TRANSFORM(178, trans, move);
  e = AFFINE_TRANSFORM(145, trans, move);
  D = AFFINE_TRANSFORM(161, trans, move);

  if (!action)
    return play_attack_defend2_n(color, 0, 3, a, b, c, D, b) && play_attack_defend_n(color, 1, 2, a, b, a);
  influence_mark_non_territory(e, color);;

  return 0;
}

static int
autohelperbarrierspat212(int trans, int move, int color, int action)
{
  int a, b, c, d;
  UNUSED(color);

  a = AFFINE_TRANSFORM(111, trans, move);
  b = AFFINE_TRANSFORM(128, trans, move);
  c = AFFINE_TRANSFORM(94, trans, move);
  d = AFFINE_TRANSFORM(93, trans, move);

  if (!action)
    return !play_attack_defend_n(color, 1, 3, a, b, c, a) && !play_attack_defend_n(color, 1, 3, a, d, c, a);
  influence_mark_non_territory(b, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat213(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);

  a = AFFINE_TRANSFORM(159, trans, move);
  b = AFFINE_TRANSFORM(160, trans, move);
  c = AFFINE_TRANSFORM(176, trans, move);
  d = AFFINE_TRANSFORM(178, trans, move);
  e = AFFINE_TRANSFORM(142, trans, move);

  if (!action)
    return play_attack_defend_n(color, 1, 4, a, b, c, d, d);
  influence_mark_non_territory(e, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat214(int trans, int move, int color, int action)
{
  int a, b, c, d, e;
  UNUSED(color);

  a = AFFINE_TRANSFORM(95, trans, move);
  b = AFFINE_TRANSFORM(77, trans, move);
  c = AFFINE_TRANSFORM(112, trans, move);
  d = AFFINE_TRANSFORM(78, trans, move);
  e = AFFINE_TRANSFORM(93, trans, move);

  if (!action)
    return safe_move(a, color) && play_attack_defend_n(color, 1, 4, a, b, c, d, b);
  influence_mark_non_territory(e, OTHER_COLOR(color));;

  return 0;
}

static int
autohelperbarrierspat215(int trans, int move, int color, int action)
{
  int a, b, c, D, E;
  UNUSED(color);

  a = AFFINE_TRANSFORM(162, trans, move);
  b = AFFINE_TRANSFORM(179, trans, move);
  c = AFFINE_TRANSFORM(196, trans, move);
  D = AFFINE_TRANSFORM(144, trans, move);
  E = AFFINE_TRANSFORM(212, trans, move);

  if (!action)
    return !play_attack_defend2_n(color, 1, 2, a, c, D, c) && !play_attack_defend2_n(color, 1, 2, c, a, E, a);
  influence_mark_non_territory(b, color);;

  return 0;
}

static int
autohelperbarrierspat216(int trans, int move, int color, int action)
{
  int a, b, c, D, E;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(145, trans, move);
  c = AFFINE_TRANSFORM(162, trans, move);
  D = AFFINE_TRANSFORM(111, trans, move);
  E = AFFINE_TRANSFORM(161, trans, move);

  if (!action)
    return !play_attack_defend2_n(color, 1, 2, a, c, D, c) && !play_attack_defend2_n(color, 1, 2, c, a, E, a);
  influence_mark_non_territory(b, color);;

  return 0;
}

static int
autohelperbarrierspat217(int trans, int move, int color, int action)
{
  int a, b, c, D, E;
  UNUSED(color);

  a = AFFINE_TRANSFORM(128, trans, move);
  b = AFFINE_TRANSFORM(111, trans, move);
  c = AFFINE_TRANSFORM(94, trans, move);
  D = AFFINE_TRANSFORM(129, trans, move);
  E = AFFINE_TRANSFORM(77, trans, move);

  if (!action)
    return !play_attack_defend2_n(color, 1, 2, a, c, D, c) && !play_attack_defend2_n(color, 1, 2, c, a, E, a);
  influence_mark_non_territory(b, color);;

  return 0;
}

static struct pattern barrierspat[] = {
  {barrierspat0,3,2, "Barrier1",0,0,0,2,0,2,0x0,144,
    { 0x003f0000, 0x00303030, 0x00f00000, 0x30300000, 0x30300000, 0x003f0000, 0x00303030, 0x00f00000},
    { 0x00110000, 0x00100010, 0x00100000, 0x00100000, 0x00100000, 0x00110000, 0x00100010, 0x00100000}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat1,5,4, "Barrier1b",-1,0,0,2,1,2,0x0,145,
    { 0x2e3f0000, 0x00383c38, 0x00f0e000, 0xf0b00000, 0x3c380000, 0x003f2e00, 0x00b0f0b0, 0xe0f00000},
    { 0x00110000, 0x00100010, 0x00100000, 0x00100000, 0x00100000, 0x00110000, 0x00100010, 0x00100000}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat2,5,2, "Barrier2",-1,0,1,2,2,2,0x0,145,
    { 0x153f1500, 0x00747474, 0x50f05000, 0x74740000, 0x74740000, 0x153f1500, 0x00747474, 0x50f05000},
    { 0x00220000, 0x00200020, 0x00200000, 0x00200000, 0x00200000, 0x00220000, 0x00200020, 0x00200000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat3,5,4, "Barrier3",-1,0,0,2,1,2,0x0,145,
    { 0x3f3f0000, 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0, 0xf0f00000},
    { 0x00220000, 0x00200020, 0x00200000, 0x00200000, 0x00200000, 0x00220000, 0x00200020, 0x00200000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat3,3,5.000000},
  {barrierspat4,2,4, "Barrier4a",0,-1,0,0,0,1,0x8,161,
    { 0x00f00000, 0x30300000, 0x003c0000, 0x00303000, 0x00303000, 0x00f00000, 0x30300000, 0x003c0000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat4,0,1.000000},
  {barrierspat5,4,8, "Barrier4b",-1,-1,0,1,1,2,0x8,162,
    { 0xe0fc0000, 0x3c383000, 0x00fc2c00, 0x30b0f000, 0x30383c00, 0x00fce000, 0xf0b03000, 0x2cfc0000},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x41,0.000000,NULL,1,NULL,autohelperbarrierspat5,0,1.000000},
  {barrierspat6,2,4, "Barrier5",0,-1,1,1,1,2,0x2,161,
    { 0x00747400, 0x50f05000, 0x74740000, 0x143c1400, 0x50f05000, 0x74740000, 0x143c1400, 0x00747400},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat7,3,8, "Barrier6",0,-1,1,0,1,1,0x2,161,
    { 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat7,3,4.800000},
  {barrierspat8,3,8, "Barrier6b",0,0,1,1,1,1,0x2,144,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat8,0,1.000000},
  {barrierspat9,4,4, "Barrier7",0,0,1,1,1,1,0x2,144,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00280000, 0x00202000, 0x00a00000, 0x20200000, 0x20200000, 0x00280000, 0x00202000, 0x00a00000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat10,4,2, "Barrier8",0,-1,1,0,1,1,0x0,161,
    { 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00},
    { 0x00104000, 0x40100000, 0x04100000, 0x00100400, 0x00104000, 0x40100000, 0x04100000, 0x00100400}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat11,4,2, "Barrier9",0,-1,1,0,1,1,0x0,161,
    { 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00},
    { 0x00208000, 0x80200000, 0x08200000, 0x00200800, 0x00208000, 0x80200000, 0x08200000, 0x00200800}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat12,4,4, "Barrier10",0,0,1,1,1,1,0x0,144,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00241000, 0x00601000, 0x10600000, 0x10240000, 0x10600000, 0x10240000, 0x00241000, 0x00601000}
   , 0x40,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat13,4,4, "Barrier11",0,0,1,1,1,1,0x0,144,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00182000, 0x00902000, 0x20900000, 0x20180000, 0x20900000, 0x20180000, 0x00182000, 0x00902000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat13,0,2.800000},
  {barrierspat14,5,8, "Barrier12",0,0,1,2,1,2,0x0,144,
    { 0x003f0f00, 0x0030f0f0, 0xc0f00000, 0x3c300000, 0xf0300000, 0x0f3f0000, 0x00303c3c, 0x00f0c000},
    { 0x00100100, 0x00100040, 0x00100000, 0x00100000, 0x00100000, 0x01100000, 0x00100004, 0x00100000}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat15,6,2, "Barrier13",0,0,1,2,1,2,0x0,144,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00222200, 0x00a000a0, 0x20200000, 0x00280000, 0x00a00000, 0x22220000, 0x00280028, 0x00202000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat16,6,8, "Barrier14",0,0,1,2,1,2,0x0,144,
    { 0x003e3f00, 0x00f0f0e0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3e0000, 0x003c3c2c, 0x00f0f000},
    { 0x00202200, 0x00a00080, 0x20200000, 0x00280000, 0x00a00000, 0x22200000, 0x00280008, 0x00202000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat16,3,3.000000},
  {barrierspat17,9,8, "Barrier15",-1,0,2,2,3,2,0x0,145,
    { 0x153d1f15, 0x0074f4d4, 0xd0f05000, 0x7d750000, 0xf4740000, 0x1f3d1500, 0x00757d5d, 0x50f0d050},
    { 0x00200200, 0x00200080, 0x00200000, 0x00200000, 0x00200000, 0x02200000, 0x00200008, 0x00200000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat18,5,5, "Barrier16",0,0,1,2,1,2,0x0,144,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00200200, 0x00200080, 0x00200000, 0x00200000, 0x00200000, 0x02200000, 0x00200008, 0x00200000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat18,3,6.528000},
  {barrierspat19,5,8, "Barrier16b",0,0,1,2,1,2,0x0,144,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00220200, 0x002000a0, 0x00200000, 0x00200000, 0x00200000, 0x02220000, 0x00200028, 0x00200000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat19,3,5.160000},
  {barrierspat20,6,8, "Barrier17",0,0,1,2,1,2,0x0,144,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00201200, 0x00600080, 0x10200000, 0x00240000, 0x00600000, 0x12200000, 0x00240008, 0x00201000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat20,3,5.880000},
  {barrierspat21,6,8, "Barrier18",0,0,1,2,1,2,0x0,144,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00211200, 0x00600090, 0x10200000, 0x00240000, 0x00600000, 0x12210000, 0x00240018, 0x00201000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat21,3,4.800000},
  {barrierspat22,6,8, "Barrier19",0,0,1,3,1,3,0x0,144,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat22,0,5.000000},
  {barrierspat23,7,8, "Barrier20",0,0,1,3,1,3,0x0,144,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00101000, 0x00500000, 0x10100000, 0x00140000, 0x00500000, 0x10100000, 0x00140000, 0x00101000}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat23,0,4.800000},
  {barrierspat24,12,2, "Barrier21",-2,0,2,3,4,3,0x0,146,
    { 0x153f1505, 0x00747575, 0x50f05040, 0x75740000, 0x75740000, 0x153f1505, 0x00747575, 0x50f05040},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat25,8,4, "Barrier22",-1,0,1,3,2,3,0x0,145,
    { 0x1f3f1f00, 0x0074fcfc, 0xd0f0d000, 0xfc740000, 0xfc740000, 0x1f3f1f00, 0x0074fcfc, 0xd0f0d000},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat25,3,4.800000},
  {barrierspat26,22,8, "Barrier22a",-2,-1,2,4,4,5,0x2,163,
    { 0x557f5f55, 0x5475f5f5, 0xd4f45450, 0x7d755500, 0xf5755400, 0x5f7f5515, 0x55757d7d, 0x54f4d454},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat27,10,4, "Barrier22b",0,0,2,3,2,3,0x0,144,
    { 0x003f1f15, 0x0070f0f0, 0xd0f00000, 0x3d350000, 0xf0700000, 0x1f3f0000, 0x00353d3d, 0x00f0d050},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat27,3,4.800000},
  {barrierspat28,7,5, "Barrier23",0,0,1,3,1,3,0x0,144,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat28,0,4.800000},
  {barrierspat29,10,4, "Barrier24",0,-1,2,3,2,4,0x0,161,
    { 0x003faf3f, 0x80b0f0f0, 0xe8f00000, 0x3f3b0800, 0xf0b08000, 0xaf3f0000, 0x083b3f3f, 0x00f0e8f0},
    { 0x00100010, 0x00100000, 0x00100000, 0x00110000, 0x00100000, 0x00100000, 0x00110000, 0x00100010}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat30,16,8, "Barrier25",-2,0,3,3,5,3,0x0,146,
    { 0x153f1f15, 0x0074f5f5, 0xd0f05040, 0x7d750000, 0xf5740000, 0x1f3f1505, 0x00757d7d, 0x50f0d050},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat31,7,5, "Barrier26",0,0,1,3,1,3,0x0,144,
    { 0x003f1f00, 0x0070f0f0, 0xd0f00000, 0x3c340000, 0xf0700000, 0x1f3f0000, 0x00343c3c, 0x00f0d000},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat31,3,4.800000},
  {barrierspat32,5,4, "Barrier27",0,-1,2,1,2,2,0x2,161,
    { 0x00b8b8b8, 0xa0f0a000, 0xb8b80000, 0x2a3f2a00, 0xa0f0a000, 0xb8b80000, 0x2a3f2a00, 0x00b8b8b8},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat33,5,4, "Barrier28",0,-1,2,1,2,2,0x2,161,
    { 0x00747474, 0x50f05000, 0x74740000, 0x153f1500, 0x50f05000, 0x74740000, 0x153f1500, 0x00747474},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat34,4,8, "Barrier29",0,-1,1,0,1,1,0x2,161,
    { 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180000, 0x00900000, 0x20100000, 0x00180000, 0x00102000}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat34,0,3.000000},
  {barrierspat35,4,8, "Barrier30",0,0,1,1,1,1,0x2,144,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00140800, 0x00109000, 0x80500000, 0x18100000, 0x90100000, 0x08140000, 0x00101800, 0x00508000}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat35,0,1.000000},
  {barrierspat36,11,8, "Barrier31",0,-2,2,2,2,4,0x2,178,
    { 0x00fefefe, 0xf0f0f0a0, 0xfcfc0000, 0x3f3f3f02, 0xf0f0f000, 0xfefe0000, 0x3f3f3f2a, 0x00fcfcfe},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180000, 0x00900000, 0x20100000, 0x00180000, 0x00102000}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat37,10,8, "Barrier32",0,-1,2,2,2,3,0x2,161,
    { 0x003afefe, 0xc0f0e0a0, 0xfcb00000, 0x2f3f0f00, 0xe0f0c000, 0xfe3a0000, 0x0f3f2f2a, 0x00b0fcfc},
    { 0x00108000, 0x80100000, 0x08100000, 0x00100800, 0x00108000, 0x80100000, 0x08100000, 0x00100800}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat38,11,8, "Barrier33",0,0,2,3,2,3,0x2,144,
    { 0x003e3f3f, 0x00f0f0e0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3e0000, 0x003f3f2f, 0x00f0f0f0},
    { 0x00240800, 0x00209000, 0x80600000, 0x18200000, 0x90200000, 0x08240000, 0x00201800, 0x00608000}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat38,3,1.000000},
  {barrierspat39,8,8, "Barrier34",0,0,2,2,2,2,0x2,144,
    { 0x003e3e3e, 0x00f0f0a0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3e3e0000, 0x003f3f2a, 0x00f0f0f0},
    { 0x00240000, 0x00201000, 0x00600000, 0x10200000, 0x10200000, 0x00240000, 0x00201000, 0x00600000}
   , 0x40,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat40,7,8, "Barrier34b",0,0,2,2,2,2,0x2,144,
    { 0x003f3f3c, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3c, 0x00f0f0f0},
    { 0x00250200, 0x00201090, 0x00600000, 0x10200000, 0x10200000, 0x02250000, 0x00201018, 0x00600000}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat40,3,1.000000},
  {barrierspat41,12,4, "Barrier35",0,-1,2,3,2,4,0x2,161,
    { 0x00bbbfbf, 0xa0f0e0f0, 0xf8b80000, 0x2f3f2a00, 0xe0f0a000, 0xbfbb0000, 0x2a3f2f3f, 0x00b8f8f8},
    { 0x00110000, 0x00100010, 0x00100000, 0x00100000, 0x00100000, 0x00110000, 0x00100010, 0x00100000}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat42,12,4, "Barrier36",0,-1,2,3,2,4,0x2,161,
    { 0x00777f7f, 0x50f0d0f0, 0xf4740000, 0x1f3f1500, 0xd0f05000, 0x7f770000, 0x153f1f3f, 0x0074f4f4},
    { 0x00220000, 0x00200020, 0x00200000, 0x00200000, 0x00200000, 0x00220000, 0x00200020, 0x00200000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat43,11,8, "Barrier37",0,0,2,3,2,3,0x2,144,
    { 0x003d3f3f, 0x00f0f0d0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3d0000, 0x003f3f1f, 0x00f0f0f0},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat43,0,0.443200},
  {barrierspat44,5,8, "Barrier38",0,0,1,2,1,2,0x2,144,
    { 0x003f3c00, 0x00f0f030, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3f0000, 0x003c3c30, 0x00f0f000},
    { 0x00190000, 0x00102010, 0x00900000, 0x20100000, 0x20100000, 0x00190000, 0x00102010, 0x00900000}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat44,0,0.010000},
  {barrierspat45,15,8, "Barrier39",0,-3,3,1,3,4,0x2,195,
    { 0x00b0f8f8, 0xe0f08000, 0xbf3a0000, 0x0a3f2f2f, 0x80f0e0e0, 0xf8b00000, 0x2f3f0a00, 0x003abfbf},
    { 0x00100000, 0x00100000, 0x01100000, 0x00100004, 0x00100040, 0x00100000, 0x00100000, 0x00100100}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat46,15,8, "Barrier40",0,-3,3,1,3,4,0x2,195,
    { 0x0070f4f4, 0xd0f04000, 0x7f350000, 0x053f1f1f, 0x40f0d0d0, 0xf4700000, 0x1f3f0500, 0x00357f7f},
    { 0x00200000, 0x00200000, 0x02200000, 0x00200008, 0x00200080, 0x00200000, 0x00200000, 0x00200200}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat47,6,8, "Barrier41a",0,0,1,3,1,3,0x0,144,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00120000, 0x00100020, 0x00100000, 0x00100000, 0x00100000, 0x00120000, 0x00100020, 0x00100000}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat47,0,3.000000},
  {barrierspat48,6,8, "Barrier41b",0,0,1,3,1,3,0x0,144,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00120000, 0x00100020, 0x00100000, 0x00100000, 0x00100000, 0x00120000, 0x00100020, 0x00100000}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat48,0,3.000000},
  {barrierspat49,4,8, "Barrier42",0,0,1,2,1,2,0x0,144,
    { 0x003c3f00, 0x00f0f0c0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3c0000, 0x003c3c0c, 0x00f0f000},
    { 0x00180100, 0x00102040, 0x00900000, 0x20100000, 0x20100000, 0x01180000, 0x00102004, 0x00900000}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat49,0,4.800000},
  {barrierspat50,12,8, "Barrier43",0,-1,2,3,2,4,0x2,161,
    { 0x003fbfbf, 0x80f0f0f0, 0xf8f00000, 0x3f3f0a00, 0xf0f08000, 0xbf3f0000, 0x0a3f3f3f, 0x00f0f8f8},
    { 0x00201000, 0x00600000, 0x10200000, 0x00240000, 0x00600000, 0x10200000, 0x00240000, 0x00201000}
   , 0x40,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat51,10,8, "Barrier44",0,-1,2,2,2,3,0x2,161,
    { 0x003ffffe, 0xc0f0f0f0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3f0000, 0x0f3f3f3e, 0x00f0fcfc},
    { 0x00214000, 0x40200010, 0x04200000, 0x00200400, 0x00204000, 0x40210000, 0x04200010, 0x00200400}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat51,3,4.800000},
  {barrierspat52,11,8, "Barrier45",0,0,2,3,2,3,0x2,144,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00222000, 0x00a00020, 0x20200000, 0x00280000, 0x00a00000, 0x20220000, 0x00280020, 0x00202000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat53,8,8, "Barrier46",0,-1,2,2,2,3,0x0,161,
    { 0x00fffffe, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xffff0000, 0x3f3f3f3e, 0x00fcfcfc},
    { 0x00214000, 0x40200010, 0x04200000, 0x00200400, 0x00204000, 0x40210000, 0x04200010, 0x00200400}
   , 0x40,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat54,25,4, "Barrier47",0,-2,3,4,3,6,0x2,178,
    { 0x00bbbfbf, 0xa0f0e0f0, 0xfaba0000, 0x2f3f2a2a, 0xe0f0a0a0, 0xbfbb0000, 0x2a3f2f3f, 0x00bafafa},
    { 0x00110000, 0x00100010, 0x00100000, 0x00100000, 0x00100000, 0x00110000, 0x00100010, 0x00100000}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat55,29,4, "Barrier48",-1,-2,3,4,4,6,0x2,179,
    { 0x55777f7f, 0x54f4d4f4, 0xf5755500, 0x5f7f5555, 0xd4f45454, 0x7f775500, 0x557f5f7f, 0x5575f5f5},
    { 0x00220000, 0x00200020, 0x00200000, 0x00200000, 0x00200000, 0x00220000, 0x00200020, 0x00200000}
   , 0x400,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat56,7,4, "Barrier49",0,0,2,2,2,2,0x0,144,
    { 0x003c3f3f, 0x00f0f0c0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3c0000, 0x003f3f0f, 0x00f0f0f0},
    { 0x00100001, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100001, 0x00100000}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat57,6,4, "Barrier50",0,0,2,2,2,2,0x0,144,
    { 0x00303c3f, 0x00f0c000, 0xf0300000, 0x0f3f0000, 0xc0f00000, 0x3c300000, 0x003f0f03, 0x0030f0f0},
    { 0x00100001, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100001, 0x00100000}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat58,4,8, "Barrier51",-1,0,0,3,1,3,0x0,145,
    { 0x2c3f0000, 0x00383c30, 0x00f0e000, 0xf0b00000, 0x3c380000, 0x003f2c00, 0x00b0f030, 0xe0f00000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat59,11,8, "Barrier52",0,-2,2,2,2,4,0x2,178,
    { 0x00fcffff, 0xf0f0f0c0, 0xfefe0000, 0x3f3f3f2b, 0xf0f0f0a0, 0xfffc0000, 0x3f3f3f0f, 0x00fefeff},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180000, 0x00900000, 0x20100000, 0x00180000, 0x00102000}
   , 0x50,0.000000,NULL,1,NULL,autohelperbarrierspat59,0,1.000000},
  {barrierspat60,7,8, "Barrier53",0,-1,2,1,2,2,0x2,161,
    { 0x0030fcf4, 0xc0f0c000, 0xfc300000, 0x0d3f0f00, 0xc0f0c000, 0xfc300000, 0x0f3f0d00, 0x0030fc7c},
    { 0x00106400, 0x40904000, 0x64100000, 0x04180400, 0x40904000, 0x64100000, 0x04180400, 0x00106400}
   , 0x50,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat61,15,4, "Barrier54",-1,-1,2,3,3,4,0x2,162,
    { 0x5d7f7fff, 0x54f4fcf4, 0xf4f4d400, 0xff7f5700, 0xfcf45400, 0x7f7f5d00, 0x577fff7f, 0xd4f4f4fc},
    { 0x00260000, 0x00201020, 0x00600000, 0x10200000, 0x10200000, 0x00260000, 0x00201020, 0x00600000}
   , 0x400,0.000000,NULL,1,NULL,autohelperbarrierspat61,3,1.000000},
  {barrierspat62,7,8, "Barrier55",0,0,1,3,1,3,0x0,144,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x50,0.000000,NULL,1,NULL,autohelperbarrierspat62,0,0.019600},
  {barrierspat63,10,8, "Barrier56",0,-1,2,2,2,3,0x2,161,
    { 0x007e7fdf, 0x50f0f0e0, 0xf4f40000, 0x3f3d1700, 0xf0f05000, 0x7f7e0000, 0x173d3f2f, 0x00f4f4dc},
    { 0x00241800, 0x00609000, 0x90600000, 0x18240000, 0x90600000, 0x18240000, 0x00241800, 0x00609000}
   , 0x50,0.000000,NULL,1,NULL,autohelperbarrierspat63,3,1.000000},
  {barrierspat64,10,8, "Barrier56b",0,-1,2,2,2,3,0x2,161,
    { 0x007effff, 0xd0f0f0e0, 0xfcf40000, 0x3f3f1f00, 0xf0f0d000, 0xff7e0000, 0x1f3f3f2f, 0x00f4fcfc},
    { 0x00249020, 0x80601000, 0x18600000, 0x10260800, 0x10608000, 0x90240000, 0x08261000, 0x00601820}
   , 0x50,0.000000,NULL,1,NULL,autohelperbarrierspat64,3,1.000000},
  {barrierspat65,3,8, "Barrier57",0,0,1,1,1,1,0x0,144,
    { 0x003c3000, 0x00f03000, 0x30f00000, 0x303c0000, 0x30f00000, 0x303c0000, 0x003c3000, 0x00f03000},
    { 0x00201000, 0x00600000, 0x10200000, 0x00240000, 0x00600000, 0x10200000, 0x00240000, 0x00201000}
   , 0x50,0.000000,NULL,1,NULL,autohelperbarrierspat65,3,0.010000},
  {barrierspat66,5,8, "Barrier58",-1,0,0,2,1,2,0x0,145,
    { 0x2e3f0000, 0x00383c38, 0x00f0e000, 0xf0b00000, 0x3c380000, 0x003f2e00, 0x00b0f0b0, 0xe0f00000},
    { 0x00190000, 0x00102010, 0x00900000, 0x20100000, 0x20100000, 0x00190000, 0x00102010, 0x00900000}
   , 0x50,0.000000,NULL,1,NULL,autohelperbarrierspat66,0,0.019600},
  {barrierspat67,3,8, "Barrier59",-1,0,0,1,1,1,0x0,145,
    { 0x3c3c0000, 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000, 0xf0f00000},
    { 0x00240000, 0x00201000, 0x00600000, 0x10200000, 0x10200000, 0x00240000, 0x00201000, 0x00600000}
   , 0x50,0.000000,NULL,1,NULL,autohelperbarrierspat67,3,1.000000},
  {barrierspat68,7,4, "Barrier60a",0,-1,3,1,3,2,0x2,161,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x404,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat69,8,4, "Barrier60b",0,-1,3,1,3,2,0x2,161,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x41,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat70,29,4, "Barrier61",-2,-3,3,2,5,5,0xa,197,
    { 0xfefefefe, 0xfefefeaa, 0xffffffaa, 0xffffffff, 0xfefefefe, 0xfefefeaa, 0xffffffaa, 0xffffffff},
    { 0x00108000, 0x80100000, 0x08100000, 0x00100800, 0x00108000, 0x80100000, 0x08100000, 0x00100800}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat71,8,8, "Barrier62",0,-2,2,1,2,3,0x0,178,
    { 0x0070fcfc, 0xd0f0c000, 0xff340000, 0x0f3f1f0f, 0xc0f0d0c0, 0xfc700000, 0x1f3f0f00, 0x0034ffff},
    { 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x40200000, 0x04200000, 0x00200400, 0x00204000}
   , 0x45,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat72,13,8, "Barrier63",0,-1,3,2,3,3,0x2,161,
    { 0x00bfffff, 0xe0f0f0f0, 0xfcf80000, 0x3f3f2f00, 0xf0f0e000, 0xffbf0000, 0x2f3f3f3f, 0x00f8fcfc},
    { 0x00204000, 0x40200000, 0x04200000, 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x00200400}
   , 0x40,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat73,14,8, "Barrier64",0,-1,3,2,3,3,0x2,161,
    { 0x00bfffff, 0xe0f0f0f0, 0xfcf80000, 0x3f3f2f00, 0xf0f0e000, 0xffbf0000, 0x2f3f3f3f, 0x00f8fcfc},
    { 0x00204000, 0x40200000, 0x04200000, 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x00200400}
   , 0x40,0.000000,NULL,1,NULL,autohelperbarrierspat73,3,1.000000},
  {barrierspat74,6,8, "Barrier65",0,-1,2,1,2,2,0x2,161,
    { 0x003cfc7c, 0xc0f0f000, 0xfcf00000, 0x3f3f0d00, 0xf0f0c000, 0xfc3c0000, 0x0d3f3f00, 0x00f0fcf4},
    { 0x00108000, 0x80100000, 0x08100000, 0x00100800, 0x00108000, 0x80100000, 0x08100000, 0x00100800}
   , 0x41,0.000000,NULL,1,NULL,autohelperbarrierspat74,0,1.000000},
  {barrierspat75,31,8, "Barrier66",0,-2,5,3,5,5,0xa,178,
    { 0x00ffffff, 0xf0f0f0f0, 0xffff0000, 0x3f3f3f3f, 0xf0f0f0f0, 0xffff0000, 0x3f3f3f3f, 0x00ffffff},
    { 0x00200024, 0x00200000, 0x00200000, 0x01220000, 0x00200000, 0x00200000, 0x00220100, 0x00200060}
   , 0x40,0.000000,NULL,0,NULL,NULL,3,0.000000},
  {barrierspat76,18,8, "Barrier67",0,-4,3,0,3,4,0x2,212,
    { 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0x003f3f3f},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x40,0.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat77,7,8, "Intrusion1",-2,-3,0,0,2,3,0x2,197,
    { 0xf0f00000, 0x3c3d0000, 0x003f3f10, 0x00f0f0f0, 0x003d3c3c, 0x00f0f010, 0xf0f00000, 0x3f3f0000},
    { 0x20100000, 0x00180000, 0x00102000, 0x00900000, 0x00180000, 0x00102000, 0x00900000, 0x20100000}
   , 0x200,30.000000,NULL,2,NULL,autohelperbarrierspat77,0,0.000000},
  {barrierspat78,6,8, "Intrusion1a",-2,-2,0,0,2,2,0xa,180,
    { 0xf0f00000, 0x3c3d0000, 0x003f3f10, 0x00f0f0f0, 0x003d3c3c, 0x00f0f010, 0xf0f00000, 0x3f3f0000},
    { 0x20100000, 0x00180000, 0x00102000, 0x00900000, 0x00180000, 0x00102000, 0x00900000, 0x20100000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat78,0,1.000000},
  {barrierspat79,11,8, "Intrusion1b",-2,-3,0,0,2,3,0x2,197,
    { 0xf0f00000, 0x3d3d0000, 0x003f3f15, 0x00f0f0f0, 0x003d3d3d, 0x00f0f050, 0xf0f00000, 0x3f3f0000},
    { 0x20100000, 0x00180000, 0x00102000, 0x00900000, 0x00180000, 0x00102000, 0x00900000, 0x20100000}
   , 0x200,30.000000,NULL,2,NULL,autohelperbarrierspat79,0,0.000000},
  {barrierspat80,10,8, "Intrusion1c",-2,-3,0,0,2,3,0x2,197,
    { 0xf0f00000, 0x3d3d0000, 0x003f3f15, 0x00f0f0f0, 0x003d3d3d, 0x00f0f050, 0xf0f00000, 0x3f3f0000},
    { 0x20100000, 0x00180000, 0x00102000, 0x00900000, 0x00180000, 0x00102000, 0x00900000, 0x20100000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat80,0,1.000000},
  {barrierspat81,10,8, "Intrusion1d",-2,-3,0,0,2,3,0x2,197,
    { 0xf0f00000, 0x3d3d0000, 0x003f3f15, 0x00f0f0f0, 0x003d3d3d, 0x00f0f050, 0xf0f00000, 0x3f3f0000},
    { 0x20100000, 0x00180000, 0x00102000, 0x00900000, 0x00180000, 0x00102000, 0x00900000, 0x20100000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat81,0,1.000000},
  {barrierspat82,7,8, "Intrusion2",-1,-3,1,0,2,3,0x2,196,
    { 0x40f0f000, 0xf4f00000, 0x3f3f0700, 0x003c7cfc, 0x00f0f4fc, 0xf0f04000, 0x7c3c0000, 0x073f3f00},
    { 0x00100000, 0x00100000, 0x00100200, 0x00100080, 0x00100008, 0x00100000, 0x00100000, 0x02100000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat82,0,1.000000},
  {barrierspat83,8,8, "Intrusion3",-1,-3,1,0,2,3,0x2,196,
    { 0xc0f0f000, 0xfcf00000, 0x3f3f0d00, 0x003cfc7c, 0x00f0fcf4, 0xf0f0c000, 0xfc3c0000, 0x0d3f3f00},
    { 0x80100000, 0x08100000, 0x00100800, 0x00108000, 0x00100800, 0x00108000, 0x80100000, 0x08100000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat83,0,1.000000},
  {barrierspat84,12,8, "Intrusion4",0,-1,2,2,2,3,0x2,161,
    { 0x00ffffff, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xffff0000, 0x3f3f3f3f, 0x00fcfcfc},
    { 0x00960800, 0x20109020, 0x80580000, 0x18102000, 0x90102000, 0x08960000, 0x20101820, 0x00588000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat84,0,1.000000},
  {barrierspat85,10,8, "Intrusion5a",0,-2,2,1,2,3,0x2,178,
    { 0x00fcfcfc, 0xf0f0f000, 0xffff0000, 0x3f3f3f3f, 0xf0f0f0f0, 0xfcfc0000, 0x3f3f3f00, 0x00ffffff},
    { 0x00182000, 0x00902000, 0x20920000, 0x20180020, 0x20900020, 0x20180000, 0x00182000, 0x00922000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat85,0,1.000000},
  {barrierspat86,4,8, "Intrusion5b",0,-1,1,1,1,2,0x0,161,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00182000, 0x00902000, 0x20900000, 0x20180000, 0x20900000, 0x20180000, 0x00182000, 0x00902000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat86,0,3.000000},
  {barrierspat87,8,8, "Intrusion6",0,-1,2,1,2,2,0x0,161,
    { 0x003cfc7c, 0xc0f0f000, 0xfcf00000, 0x3f3f0d00, 0xf0f0c000, 0xfc3c0000, 0x0d3f3f00, 0x00f0fcf4},
    { 0x00188000, 0x80102000, 0x08900000, 0x20100800, 0x20108000, 0x80180000, 0x08102000, 0x00900800}
   , 0x200,30.000000,NULL,2,NULL,autohelperbarrierspat87,0,0.000000},
  {barrierspat88,4,8, "Intrusion7b",0,0,1,1,1,1,0x0,144,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat88,0,3.000000},
  {barrierspat89,7,8, "Intrusion8a",-1,0,1,2,2,2,0x0,145,
    { 0x3f3f0f00, 0x003cfcfc, 0xc0f0f000, 0xfcf00000, 0xfc3c0000, 0x0f3f3f00, 0x00f0fcfc, 0xf0f0c000},
    { 0x22100800, 0x00188008, 0x80102000, 0x08900000, 0x80180000, 0x08102200, 0x00900880, 0x20108000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat89,0,1.600000},
  {barrierspat90,5,8, "Intrusion8b",-1,0,1,1,2,1,0x0,145,
    { 0x0c3c3c00, 0x00f0fc00, 0xf0f0c000, 0xfc3c0000, 0xfcf00000, 0x3c3c0c00, 0x003cfc00, 0xc0f0f000},
    { 0x08102000, 0x00900800, 0x20108000, 0x80180000, 0x08900000, 0x20100800, 0x00188000, 0x80102000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat90,0,1.600000},
  {barrierspat91,4,8, "Intrusion9",-1,0,1,1,2,1,0x0,145,
    { 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000},
    { 0x20180000, 0x00182000, 0x00902000, 0x20900000, 0x20180000, 0x00182000, 0x00902000, 0x20900000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat91,0,1.000000},
  {barrierspat92,10,8, "Intrusion10",-2,-3,0,1,2,4,0x2,197,
    { 0xf0f00000, 0x3d3c0000, 0x003f3f05, 0x00f0f0f0, 0x003c3d3d, 0x00f0f040, 0xf0f00000, 0x3f3f0000},
    { 0x90100000, 0x08140000, 0x00101800, 0x00508000, 0x00140800, 0x00109000, 0x80500000, 0x18100000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat92,0,3.000000},
  {barrierspat93,8,4, "Intrusion11",0,-1,3,1,3,2,0x2,161,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180000, 0x00900000, 0x20100000, 0x00180000, 0x00102000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat93,0,1.600000},
  {barrierspat94,12,4, "Intrusion12a",0,-1,3,1,3,2,0x2,161,
    { 0x00fcfcfc, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0xf0f0f000, 0xfcfc0000, 0x3f3f3f00, 0x00fcfcfc},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180000, 0x00900000, 0x20100000, 0x00180000, 0x00102000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat94,0,1.600000},
  {barrierspat95,8,8, "Intrusion12b",0,-1,2,1,2,2,0x0,161,
    { 0x00b8fcfc, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0x00b8fcfc},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180000, 0x00900000, 0x20100000, 0x00180000, 0x00102000}
   , 0x201,30.000000,NULL,3,NULL,autohelperbarrierspat95,0,1.810000},
  {barrierspat96,16,8, "Intrusion13",0,-3,3,1,3,4,0x2,195,
    { 0x00b0fcfc, 0xe0f0c000, 0xff3b0000, 0x0f3f2f3f, 0xc0f0e0f0, 0xfcb00000, 0x2f3f0f00, 0x003bffff},
    { 0x00102000, 0x00900000, 0x20110000, 0x00180010, 0x00900010, 0x20100000, 0x00180000, 0x00112000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat96,0,0.016000},
  {barrierspat97,14,8, "Intrusion14",0,-1,3,2,3,3,0x2,161,
    { 0x003cffff, 0xc0f0f0c0, 0xfcf00000, 0x3f3f0f00, 0xf0f0c000, 0xff3c0000, 0x0f3f3f0f, 0x00f0fcfc},
    { 0x00148800, 0x80109000, 0x88500000, 0x18100800, 0x90108000, 0x88140000, 0x08101800, 0x00508800}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat97,0,3.000000},
  {barrierspat98,6,8, "Intrusion15",0,-1,2,1,2,2,0x0,161,
    { 0x00b8fcfc, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0xe0f0e000, 0xfcb80000, 0x2f3f2f00, 0x00b8fcfc},
    { 0x00102408, 0x00904000, 0x60100000, 0x06180000, 0x40900000, 0x24100000, 0x00180600, 0x00106080}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat98,0,1.000000},
  {barrierspat99,9,8, "Intrusion16",0,0,2,2,2,2,0x0,144,
    { 0x003f3f37, 0x00f0f0f0, 0xf0f00000, 0x3d3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3d3f, 0x00f0f070},
    { 0x00100002, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100002, 0x00100000}
   , 0x200,20.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat100,8,8, "Intrusion17",0,0,2,2,2,2,0x0,144,
    { 0x003f3f37, 0x00f0f0f0, 0xf0f00000, 0x3d3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3d3f, 0x00f0f070},
    { 0x00100022, 0x00100000, 0x00100000, 0x00120000, 0x00100000, 0x00100000, 0x00120002, 0x00100020}
   , 0x200,20.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat101,11,8, "Intrusion18",-2,0,2,2,4,2,0x0,146,
    { 0x2f3f2f1d, 0x00b9fffd, 0xe0f0e0d0, 0xffb90000, 0xffb90000, 0x2f3f2f1d, 0x00b9fffd, 0xe0f0e0d0},
    { 0x00100008, 0x00100200, 0x00100080, 0x02100000, 0x02100000, 0x00100008, 0x00100200, 0x00100080}
   , 0x200,30.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat102,9,8, "Intrusion19",-1,0,2,2,3,2,0x0,145,
    { 0x3f3f2f1d, 0x00bcfcfc, 0xe0f0f000, 0xfff90000, 0xfcbc0000, 0x2f3f3f00, 0x00f9fffd, 0xf0f0e0d0},
    { 0x20100008, 0x00180000, 0x00102000, 0x02900000, 0x00180000, 0x00102000, 0x00900200, 0x20100080}
   , 0x200,30.000000,NULL,2,NULL,autohelperbarrierspat102,0,0.000000},
  {barrierspat103,5,8, "Intrusion20",0,-1,1,1,1,2,0x0,161,
    { 0x00bcfc00, 0xe0f0f000, 0xfcf80000, 0x3c3c2c00, 0xf0f0e000, 0xfcbc0000, 0x2c3c3c00, 0x00f8fc00},
    { 0x00106000, 0x40900000, 0x24100000, 0x00180400, 0x00904000, 0x60100000, 0x04180000, 0x00102400}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat103,0,0.610000},
  {barrierspat104,7,8, "Intrusion21",0,0,2,2,2,2,0x0,144,
    { 0x003f3f1f, 0x00f0f0f0, 0xf0f00000, 0x3f3d0000, 0xf0f00000, 0x3f3f0000, 0x003d3f3f, 0x00f0f0d0},
    { 0x00120000, 0x00100020, 0x00100000, 0x00100000, 0x00100000, 0x00120000, 0x00100020, 0x00100000}
   , 0x200,30.000000,NULL,2,NULL,autohelperbarrierspat104,0,0.000000},
  {barrierspat105,5,8, "Intrusion21b",-1,0,1,2,2,2,0x0,145,
    { 0x2b3f1f00, 0x0078f8fc, 0xd0f0a000, 0xbcb40000, 0xf8780000, 0x1f3f2b00, 0x00b4bcfc, 0xa0f0d000},
    { 0x02100000, 0x00100008, 0x00100000, 0x00100000, 0x00100000, 0x00100200, 0x00100080, 0x00100000}
   , 0x200,30.000000,NULL,2,NULL,autohelperbarrierspat105,0,0.000000},
  {barrierspat106,6,8, "Intrusion22",0,0,2,2,2,2,0x0,144,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00120000, 0x00100020, 0x00100000, 0x00100000, 0x00100000, 0x00120000, 0x00100020, 0x00100000}
   , 0x200,10.000000,NULL,2,NULL,autohelperbarrierspat106,0,0.000000},
  {barrierspat107,4,8, "Intrusion23",0,0,1,2,1,2,0x2,144,
    { 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x200,10.000000,NULL,3,NULL,autohelperbarrierspat107,0,3.000000},
  {barrierspat108,5,8, "Intrusion24",-1,0,0,2,1,2,0x2,145,
    { 0x3f3f0000, 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0, 0xf0f00000},
    { 0x10100000, 0x00140000, 0x00101000, 0x00500000, 0x00140000, 0x00101000, 0x00500000, 0x10100000}
   , 0x200,30.000000,NULL,2,NULL,autohelperbarrierspat108,0,0.000000},
  {barrierspat109,11,8, "Intrusion25",-1,-2,2,1,3,3,0x2,179,
    { 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xffffffff, 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xffffffff},
    { 0x04900000, 0x20100400, 0x00184000, 0x40102000, 0x04102000, 0x00900400, 0x20104000, 0x40180000}
   , 0x200,30.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat110,13,8, "Intrusion26",-1,-2,2,1,3,3,0x2,179,
    { 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xffffffff, 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xffffffff},
    { 0x04902000, 0x20900400, 0x20184000, 0x40182000, 0x04902000, 0x20900400, 0x20184000, 0x40182000}
   , 0x200,30.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat111,10,8, "Intrusion27",0,0,3,2,3,2,0x0,144,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x200,30.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat112,12,8, "Intrusion28",0,-2,3,1,3,3,0x2,178,
    { 0x0030fcfc, 0xc0f0c000, 0xfd300000, 0x0f3f0f07, 0xc0f0c040, 0xfc300000, 0x0f3f0f00, 0x0030fdff},
    { 0x00100800, 0x00108000, 0x80100000, 0x08100000, 0x80100000, 0x08100000, 0x00100800, 0x00108000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat112,0,3.000000},
  {barrierspat113,16,8, "Intrusion29",-2,-1,3,2,5,3,0x0,163,
    { 0xaafeffff, 0xfafafaea, 0xfcfca8a8, 0xbfbfbf00, 0xfafafa00, 0xfffeaaaa, 0xbfbfbfaf, 0xa8fcfcfc},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x200,30.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat114,17,8, "Intrusion30",-2,-1,3,2,5,3,0x0,163,
    { 0xaafeffff, 0xfafafaea, 0xfcfca8a8, 0xbfbfbf00, 0xfafafa00, 0xfffeaaaa, 0xbfbfbfaf, 0xa8fcfcfc},
    { 0x00900000, 0x20100000, 0x00180000, 0x00102000, 0x00102000, 0x00900000, 0x20100000, 0x00180000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat114,0,1.000000},
  {barrierspat115,7,8, "Intrusion30a",-2,-1,3,2,5,3,0x0,163,
    { 0x00baffff, 0xe0f0e0e0, 0xfcb80000, 0x2f3f2f00, 0xe0f0e000, 0xffba0000, 0x2f3f2f2f, 0x00b8fcfc},
    { 0x00100200, 0x00100080, 0x00100000, 0x00100000, 0x00100000, 0x02100000, 0x00100008, 0x00100000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat115,0,10.000000},
  {barrierspat116,8,8, "Intrusion31",-1,-1,3,1,4,2,0x0,162,
    { 0xa8fcfcfc, 0xf8f8f800, 0xfcfca800, 0xbfbfbf00, 0xf8f8f800, 0xfcfca800, 0xbfbfbf00, 0xa8fcfcfc},
    { 0x00900000, 0x20100000, 0x00180000, 0x00102000, 0x00102000, 0x00900000, 0x20100000, 0x00180000}
   , 0x200,30.000000,NULL,2,NULL,autohelperbarrierspat116,0,0.000000},
  {barrierspat117,4,8, "Intrusion32",-1,-1,2,1,3,2,0x0,162,
    { 0xa8fcfc30, 0xf8f8f800, 0xfcfca800, 0xbcbfbc00, 0xf8f8f800, 0xfcfca800, 0xbcbfbc00, 0xa8fcfc30},
    { 0x00900000, 0x20100000, 0x00180000, 0x00102000, 0x00102000, 0x00900000, 0x20100000, 0x00180000}
   , 0x200,30.000000,NULL,2,NULL,autohelperbarrierspat117,0,0.000000},
  {barrierspat118,6,8, "Intrusion33",-1,-1,2,1,3,2,0x0,162,
    { 0xb8fcfc30, 0xf8fcf800, 0xfcfcb800, 0xbcffbc00, 0xf8fcf800, 0xfcfcb800, 0xbcffbc00, 0xb8fcfc30},
    { 0x10980000, 0x20142000, 0x00981000, 0x20502000, 0x20142000, 0x00981000, 0x20502000, 0x10980000}
   , 0x200,30.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat119,5,8, "Intrusion34",-1,-1,2,1,3,2,0x0,162,
    { 0xb8fcfc30, 0xf8fcf800, 0xfcfcb800, 0xbcffbc00, 0xf8fcf800, 0xfcfcb800, 0xbcffbc00, 0xb8fcfc30},
    { 0x00980000, 0x20102000, 0x00980000, 0x20102000, 0x20102000, 0x00980000, 0x20102000, 0x00980000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat119,0,1.000000},
  {barrierspat120,21,8, "Intrusion35",-1,-3,3,1,4,4,0xa,196,
    { 0xc0f0fcfc, 0xfcf0c000, 0xff3f0f00, 0x0f3fffff, 0xc0f0fcfc, 0xfcf0c000, 0xff3f0f00, 0x0f3fffff},
    { 0x80108800, 0x88108000, 0x88100800, 0x08108800, 0x80108800, 0x88108000, 0x88100800, 0x08108800}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat120,0,1.000000},
  {barrierspat121,4,8, "Intrusion36",-1,0,1,1,2,1,0x0,145,
    { 0x0c3c3400, 0x00f07c00, 0x70f0c000, 0xf43c0000, 0x7cf00000, 0x343c0c00, 0x003cf400, 0xc0f07000},
    { 0x08102000, 0x00900800, 0x20108000, 0x80180000, 0x08900000, 0x20100800, 0x00188000, 0x80102000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat121,0,1.000000},
  {barrierspat122,4,8, "Intrusion37",-1,0,1,1,2,1,0x0,145,
    { 0x0c3c2c00, 0x00b0fc00, 0xe0f0c000, 0xfc380000, 0xfcb00000, 0x2c3c0c00, 0x0038fc00, 0xc0f0e000},
    { 0x08100800, 0x00108800, 0x80108000, 0x88100000, 0x88100000, 0x08100800, 0x00108800, 0x80108000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat122,0,1.000000},
  {barrierspat123,3,8, "Intrusion38",-1,-1,0,0,1,1,0x2,162,
    { 0xc0f00000, 0x3c300000, 0x003c0c00, 0x0030f000, 0x00303c00, 0x00f0c000, 0xf0300000, 0x0c3c0000},
    { 0x80100000, 0x08100000, 0x00100800, 0x00108000, 0x00100800, 0x00108000, 0x80100000, 0x08100000}
   , 0x200,5.000000,NULL,3,NULL,autohelperbarrierspat123,0,1.000000},
  {barrierspat124,7,8, "Intrusion39",-1,0,1,2,2,2,0x0,145,
    { 0x0d3f2f00, 0x00b0fcf4, 0xe0f0c000, 0xfc380000, 0xfcb00000, 0x2f3f0d00, 0x0038fc7c, 0xc0f0e000},
    { 0x08100200, 0x00100880, 0x00108000, 0x80100000, 0x08100000, 0x02100800, 0x00108008, 0x80100000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat124,0,1.000000},
  {barrierspat125,3,8, "Intrusion40",-1,0,0,1,1,1,0x0,145,
    { 0x3c300000, 0x003c0c00, 0x0030f000, 0xc0f00000, 0x0c3c0000, 0x00303c00, 0x00f0c000, 0xf0300000},
    { 0x20100000, 0x00180000, 0x00102000, 0x00900000, 0x00180000, 0x00102000, 0x00900000, 0x20100000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat125,0,0.610000},
  {barrierspat126,4,8, "Intrusion41",-1,0,0,1,1,1,0x0,145,
    { 0x3c3c0000, 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000, 0xf0f00000},
    { 0x20100000, 0x00180000, 0x00102000, 0x00900000, 0x00180000, 0x00102000, 0x00900000, 0x20100000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat126,0,0.010000},
  {barrierspat127,11,8, "Intrusion42",-1,-2,2,1,3,3,0x2,179,
    { 0xe8f8fcfc, 0xfcf8e800, 0xffbfac00, 0xafbfff3f, 0xe8f8fcf0, 0xfcf8e800, 0xffbfaf00, 0xacbfffff},
    { 0x40902000, 0x24900000, 0x20180400, 0x00186000, 0x00902400, 0x20904000, 0x60180000, 0x04182000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat127,0,0.970000},
  {barrierspat128,8,8, "Intrusion43",-1,-3,1,0,2,3,0x0,196,
    { 0xf0f0e000, 0xfcbc0000, 0x2f3f3c00, 0x00f8fc3c, 0x00bcfcf0, 0xe0f0f000, 0xfcf80000, 0x3c3f2f00},
    { 0x90900000, 0x28140000, 0x00181800, 0x0050a000, 0x00142800, 0x00909000, 0xa0500000, 0x18180000}
   , 0x200,50.000000,NULL,1,NULL,autohelperbarrierspat128,0,0.970000},
  {barrierspat129,5,8, "Intrusion44a",0,-2,1,0,1,2,0x0,178,
    { 0x00f0e000, 0xf0b00000, 0x2f3f0000, 0x00383c3c, 0x00b0f0f0, 0xe0f00000, 0x3c380000, 0x003f2f00},
    { 0x00900000, 0x20100000, 0x00180000, 0x00102000, 0x00102000, 0x00900000, 0x20100000, 0x00180000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat129,0,2.014000},
  {barrierspat130,7,8, "Intrusion44b",-1,-2,1,1,2,3,0x0,179,
    { 0xf0f8e000, 0xfcbc2000, 0x2fbf3f00, 0x20f8fcfc, 0x20bcfcfc, 0xe0f8f000, 0xfcf82000, 0x3fbf2f00},
    { 0x20900000, 0x20180000, 0x00182000, 0x00902000, 0x00182000, 0x00902000, 0x20900000, 0x20180000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat130,0,2.014000},
  {barrierspat131,9,8, "Intrusion45",0,-2,2,1,2,3,0x2,178,
    { 0x00f8fcfc, 0xf0f0e000, 0xffbf0000, 0x2f3f3f3f, 0xe0f0f0f0, 0xfcf80000, 0x3f3f2f00, 0x00bfffff},
    { 0x00102000, 0x00900000, 0x20120000, 0x00180020, 0x00900020, 0x20100000, 0x00180000, 0x00122000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat131,0,1.600000},
  {barrierspat132,18,4, "Intrusion46",0,-2,3,2,3,4,0x2,178,
    { 0x00fdfffd, 0xf0f0f0d0, 0xfffd0000, 0x3f3f3f1d, 0xf0f0f0d0, 0xfffd0000, 0x3f3f3f1d, 0x00fdfffd},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180000, 0x00900000, 0x20100000, 0x00180000, 0x00102000}
   , 0x200,10.000000,NULL,1,NULL,autohelperbarrierspat132,0,1.000000},
  {barrierspat133,9,8, "Intrusion47",-2,0,0,4,2,4,0x2,146,
    { 0x2f3f0000, 0x00383c3f, 0x00f0e000, 0xf0b00000, 0x3c380000, 0x003f2f03, 0x00b0f0f0, 0xe0f00000},
    { 0x00100000, 0x00100002, 0x00100000, 0x00100000, 0x00100000, 0x00100002, 0x00100000, 0x00100000}
   , 0x200,20.000000,NULL,1,NULL,autohelperbarrierspat133,0,0.010000},
  {barrierspat134,6,8, "Intrusion48",-2,0,1,2,3,2,0x0,146,
    { 0x3f3f3f00, 0x00fcfdff, 0xf0f0f040, 0xfcfc0000, 0xfdfc0000, 0x3f3f3f07, 0x00fcfcfc, 0xf0f0f000},
    { 0x00100200, 0x00100080, 0x00100000, 0x00100000, 0x00100000, 0x02100000, 0x00100008, 0x00100000}
   , 0x200,20.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat135,5,8, "Intrusion49",0,-1,1,1,1,2,0x0,161,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00980000, 0x20102000, 0x00980000, 0x20102000, 0x20102000, 0x00980000, 0x20102000, 0x00980000}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat135,0,1.600000},
  {barrierspat136,5,8, "Intrusion50",-1,0,1,2,2,2,0x2,145,
    { 0x0f3f3f00, 0x00f0fcfc, 0xf0f0c000, 0xfc3c0000, 0xfcf00000, 0x3f3f0f00, 0x003cfcfc, 0xc0f0f000},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x201,30.000000,NULL,1,NULL,autohelperbarrierspat136,0,3.000000},
  {barrierspat137,6,4, "Intrusion51a",0,-1,2,1,2,2,0x0,161,
    { 0x0030fcfc, 0xc0f0c000, 0xfc300000, 0x0f3f0f00, 0xc0f0c000, 0xfc300000, 0x0f3f0f00, 0x0030fcfc},
    { 0x00108800, 0x80108000, 0x88100000, 0x08100800, 0x80108000, 0x88100000, 0x08100800, 0x00108800}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat137,0,5.000000},
  {barrierspat138,7,4, "Intrusion51b",-1,-1,1,1,2,2,0x0,162,
    { 0x30fcfc00, 0xf0fcf000, 0xfcfc3000, 0x3cfc3c00, 0xf0fcf000, 0xfcfc3000, 0x3cfc3c00, 0x30fcfc00},
    { 0x10982000, 0x20942000, 0x20981000, 0x20582000, 0x20942000, 0x20981000, 0x20582000, 0x10982000}
   , 0x204,20.000000,NULL,1,NULL,autohelperbarrierspat138,0,6.476960},
  {barrierspat139,7,8, "Intrusion52",-1,0,1,2,2,2,0x0,145,
    { 0x3d3f3f00, 0x00fcfcf4, 0xf0f0f000, 0xfcfc0000, 0xfcfc0000, 0x3f3f3d00, 0x00fcfc7c, 0xf0f0f000},
    { 0x20100800, 0x00188000, 0x80102000, 0x08900000, 0x80180000, 0x08102000, 0x00900800, 0x20108000}
   , 0x200,30.000000,NULL,2,NULL,autohelperbarrierspat139,0,0.000000},
  {barrierspat140,6,8, "Intrusion53",-1,0,0,2,1,2,0x0,145,
    { 0x3f3f0000, 0x003c3c3c, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003f3f00, 0x00f0f0f0, 0xf0f00000},
    { 0x20180000, 0x00182000, 0x00902000, 0x20900000, 0x20180000, 0x00182000, 0x00902000, 0x20900000}
   , 0x200,50.000000,NULL,1,NULL,autohelperbarrierspat140,0,1.000000},
  {barrierspat141,6,8, "Intrusion54",-1,-2,1,1,2,3,0x0,179,
    { 0xf0f8e800, 0xfcbca000, 0xafbf3f00, 0x28f8fcfc, 0xa0bcfcfc, 0xe8f8f000, 0xfcf82800, 0x3fbfaf00},
    { 0x20900000, 0x20180000, 0x00182000, 0x00902000, 0x00182000, 0x00902000, 0x20900000, 0x20180000}
   , 0x200,40.000000,NULL,1,NULL,autohelperbarrierspat141,0,0.229120},
  {barrierspat142,8,8, "Intrusion55",-3,-3,0,0,3,3,0x2,198,
    { 0xe0f00000, 0x3d380000, 0x003f2f05, 0x00b0f0f0, 0x00383d3d, 0x00f0e040, 0xf0b00000, 0x2f3f0000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat142,0,0.610000},
  {barrierspat143,8,8, "Intrusion56",-3,-3,0,0,3,3,0x2,198,
    { 0xe0f00000, 0x3d380000, 0x003f2f05, 0x00b0f0f0, 0x00383d3d, 0x00f0e040, 0xf0b00000, 0x2f3f0000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat143,0,6.010000},
  {barrierspat144,4,8, "Intrusion57",-1,-1,1,0,2,1,0x0,162,
    { 0x70f0c000, 0xf43c0000, 0x0c3c3400, 0x00f07c00, 0x003cf400, 0xc0f07000, 0x7cf00000, 0x343c0c00},
    { 0x20108000, 0x80180000, 0x08102000, 0x00900800, 0x00188000, 0x80102000, 0x08900000, 0x20100800}
   , 0x200,30.000000,NULL,3,NULL,autohelperbarrierspat144,0,1.000000},
  {barrierspat145,11,8, "Intrusion58",-1,-2,2,1,3,3,0x0,179,
    { 0xe8f8fcfc, 0xfcf8e800, 0xffbfaf00, 0xafbffffc, 0xe8f8fcfc, 0xfcf8e800, 0xffbfaf00, 0xafbffffc},
    { 0x40902000, 0x24900000, 0x20180600, 0x00186080, 0x00902408, 0x20904000, 0x60180000, 0x06182000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat145,0,16.000000},
  {barrierspat146,13,8, "Intrusion59",-3,-1,1,2,4,3,0x8,164,
    { 0xfffce800, 0xffbfbf0d, 0xacfcfcfc, 0xf8f8fc00, 0xbfbfff00, 0xe8fcfffd, 0xfcf8f8c0, 0xfcfcac00},
    { 0x22940000, 0x20181008, 0x00582000, 0x10902000, 0x10182000, 0x00942200, 0x20901080, 0x20580000}
   , 0x200,30.000000,NULL,1,NULL,autohelperbarrierspat146,0,7.360000},
  {barrierspat147,6,8, "Intrusion60",0,-1,2,1,2,2,0x0,161,
    { 0x00f0fcf0, 0xf0f0c000, 0xfc3c0000, 0x0c3f3f00, 0xc0f0f000, 0xfcf00000, 0x3f3f0c00, 0x003cfc3c},
    { 0x00508050, 0x90100000, 0x08140000, 0x00111900, 0x00109000, 0x80500000, 0x19110000, 0x00140814}
   , 0x200,20.000000,NULL,0,NULL,NULL,0,0.000000},
  {barrierspat148,10,8, "Intrusion61",-2,-1,1,2,3,3,0x8,163,
    { 0xfffffc00, 0xffffff3c, 0xfcfcfcfc, 0xfcfcfc00, 0xffffff00, 0xfcfffffc, 0xfcfcfcf0, 0xfcfcfc00},
    { 0x201a1400, 0x00586020, 0x50902000, 0x24940000, 0x60580000, 0x141a2000, 0x00942420, 0x20905000}
   , 0x200,20.000000,NULL,1,NULL,autohelperbarrierspat148,0,10.000000},
  {barrierspat149,5,8, "Intrusion62",-1,-1,1,1,2,2,0x0,162,
    { 0xf8fcfc00, 0xfcfcf800, 0xfcfcbc00, 0xbcfcfc00, 0xf8fcfc00, 0xfcfcf800, 0xfcfcbc00, 0xbcfcfc00},
    { 0x20102400, 0x00984000, 0x60102000, 0x04980000, 0x40980000, 0x24102000, 0x00980400, 0x20106000}
   , 0x200,20.000000,NULL,3,NULL,autohelperbarrierspat149,0,1.000000},
  {barrierspat150,15,8, "Intrusion63",-2,-1,1,3,3,4,0x2,163,
    { 0xffffff00, 0xfffeffff, 0xfcfcfcec, 0xfcfcfc00, 0xfffeff00, 0xffffffef, 0xfcfcfcfc, 0xfcfcfc00},
    { 0x18182000, 0x00942901, 0x20909040, 0xa0580000, 0x29940000, 0x20181805, 0x0058a000, 0x90902000}
   , 0x200,50.000000,NULL,1,NULL,autohelperbarrierspat150,0,6.050000},
  {barrierspat151,4,4, "Nonterritory1",0,0,1,2,1,2,0x0,144,
    { 0x00373b00, 0x00f090f0, 0xb0700000, 0x183c0000, 0x90f00000, 0x3b370000, 0x003c183c, 0x0070b000},
    { 0x00112200, 0x00900090, 0x20100000, 0x00180000, 0x00900000, 0x22110000, 0x00180018, 0x00102000}
   , 0x80000,0.000000,NULL,2,NULL,autohelperbarrierspat151,0,0.000000},
  {barrierspat152,4,8, "Nonterritory1b",0,0,1,2,1,2,0x0,144,
    { 0x00373b00, 0x00f090f0, 0xb0700000, 0x183c0000, 0x90f00000, 0x3b370000, 0x003c183c, 0x0070b000},
    { 0x00102200, 0x00900080, 0x20100000, 0x00180000, 0x00900000, 0x22100000, 0x00180008, 0x00102000}
   , 0x80000,0.000000,NULL,2,NULL,autohelperbarrierspat152,0,0.000000},
  {barrierspat153,4,8, "Nonterritory1c",0,0,1,2,1,2,0x0,144,
    { 0x003b3700, 0x00f060f0, 0x70b00000, 0x243c0000, 0x60f00000, 0x373b0000, 0x003c243c, 0x00b07000},
    { 0x00201100, 0x00600040, 0x10200000, 0x00240000, 0x00600000, 0x11200000, 0x00240004, 0x00201000}
   , 0x80000,0.000000,NULL,2,NULL,autohelperbarrierspat153,3,0.000000},
  {barrierspat154,5,8, "Nonterritory2",0,-2,2,0,2,2,0x0,178,
    { 0x0070f040, 0xd0f00000, 0x3d340000, 0x003c1d07, 0x00f0d040, 0xf0700000, 0x1d3c0000, 0x00343d07},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180001, 0x00900000, 0x20100000, 0x00180000, 0x00102001}
   , 0x80000,0.000000,NULL,2,NULL,autohelperbarrierspat154,0,0.000000},
  {barrierspat155,5,8, "Nonterritory3",0,-2,2,0,2,2,0x0,178,
    { 0x00b0f080, 0xe0f00000, 0x3e380000, 0x003c2e0b, 0x00f0e080, 0xf0b00000, 0x2e3c0000, 0x00383e0b},
    { 0x00201000, 0x00600000, 0x10200000, 0x00240002, 0x00600000, 0x10200000, 0x00240000, 0x00201002}
   , 0x80000,0.000000,NULL,2,NULL,autohelperbarrierspat155,3,0.000000},
  {barrierspat156,2,8, "Nonterritory4",0,-1,1,0,1,1,0x8,161,
    { 0x0070b000, 0x90f00000, 0x38340000, 0x003c1800, 0x00f09000, 0xb0700000, 0x183c0000, 0x00343800},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180000, 0x00900000, 0x20100000, 0x00180000, 0x00102000}
   , 0x80000,0.000000,NULL,2,NULL,autohelperbarrierspat156,0,0.000000},
  {barrierspat157,3,8, "Nonterritory5",0,-1,2,0,2,1,0x8,161,
    { 0x0030f070, 0xc0f00000, 0x3c300000, 0x003f0d00, 0x00f0c000, 0xf0300000, 0x0d3f0000, 0x00303c34},
    { 0x00100020, 0x00100000, 0x00100000, 0x00120000, 0x00100000, 0x00100000, 0x00120000, 0x00100020}
   , 0x80000,0.000000,NULL,2,NULL,autohelperbarrierspat157,0,0.000000},
  {barrierspat158,3,8, "Nonterritory6",0,-1,2,0,2,1,0x8,161,
    { 0x0030f0b0, 0xc0f00000, 0x3c300000, 0x003f0e00, 0x00f0c000, 0xf0300000, 0x0e3f0000, 0x00303c38},
    { 0x00200010, 0x00200000, 0x00200000, 0x00210000, 0x00200000, 0x00200000, 0x00210000, 0x00200010}
   , 0x80000,0.000000,NULL,2,NULL,autohelperbarrierspat158,3,0.000000},
  {barrierspat159,2,8, "Nonterritory7",0,-1,1,1,1,2,0x2,161,
    { 0x00f0fc00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0x003cfc00},
    { 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x40200000, 0x04200000, 0x00200400, 0x00204000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat159,3,1.000000},
  {barrierspat160,2,8, "Nonterritory7b",0,-1,1,1,1,2,0x2,161,
    { 0x00f0fc00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0x003cfc00},
    { 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x40200000, 0x04200000, 0x00200400, 0x00204000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat160,3,2.680000},
  {barrierspat161,4,8, "Nonterritory7c",0,-2,1,1,1,3,0x2,178,
    { 0x00f0fc00, 0xf0f0c000, 0xff3f0000, 0x0c3c3c3c, 0xc0f0f0f0, 0xfcf00000, 0x3c3c0c00, 0x003fff00},
    { 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x40200000, 0x04200000, 0x00200400, 0x00204000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat161,3,3.000000},
  {barrierspat162,2,8, "Nonterritory8",0,-1,1,1,1,2,0x2,161,
    { 0x007cf800, 0xd0f0b000, 0xbcf40000, 0x383c1c00, 0xb0f0d000, 0xf87c0000, 0x1c3c3800, 0x00f4bc00},
    { 0x00240000, 0x00201000, 0x00600000, 0x10200000, 0x10200000, 0x00240000, 0x00201000, 0x00600000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat162,3,1.000000},
  {barrierspat163,2,8, "Nonterritory8b",0,-1,1,1,1,2,0x2,161,
    { 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0xf0f0f000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00},
    { 0x00240000, 0x00201000, 0x00600000, 0x10200000, 0x10200000, 0x00240000, 0x00201000, 0x00600000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat163,3,2.800000},
  {barrierspat164,7,8, "Nonterritory9",0,-3,2,0,2,3,0x0,195,
    { 0x00f0c0c0, 0xf0300000, 0x0f3f0000, 0x00303f3e, 0x0030f0f0, 0xc0f00000, 0x3f300000, 0x003f0f0e},
    { 0x00200040, 0x00200000, 0x00200000, 0x00200100, 0x00200000, 0x00200000, 0x01200000, 0x00200004}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat164,3,1.000000},
  {barrierspat165,7,8, "Nonterritory10",-2,0,0,2,2,2,0x0,146,
    { 0x3f3f0000, 0x003f3f3d, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0x003f3f3d, 0x00f0f0f0, 0xf0f00000},
    { 0x00260000, 0x00201020, 0x00600000, 0x10200000, 0x10200000, 0x00260000, 0x00201020, 0x00600000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat165,3,1.000000},
  {barrierspat166,7,8, "Nonterritory11",0,-1,2,1,2,2,0x2,161,
    { 0x00bcfcfc, 0xe0f0f000, 0xfcf80000, 0x3f3f2f00, 0xf0f0e000, 0xfcbc0000, 0x2f3f3f00, 0x00f8fcfc},
    { 0x00186020, 0x40902000, 0x24900000, 0x201a0400, 0x20904000, 0x60180000, 0x041a2000, 0x00902420}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat166,0,1.600000},
  {barrierspat167,1,4, "Nonterritory12",-1,0,0,1,1,1,0x0,145,
    { 0x303c0000, 0x003c3000, 0x00f03000, 0x30f00000, 0x303c0000, 0x003c3000, 0x00f03000, 0x30f00000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x80000,0.000000,NULL,2,NULL,autohelperbarrierspat167,0,0.000000},
  {barrierspat168,1,4, "Nonterritory13",-1,0,0,1,1,1,0x0,145,
    { 0x303c0000, 0x003c3000, 0x00f03000, 0x30f00000, 0x303c0000, 0x003c3000, 0x00f03000, 0x30f00000},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x80000,0.000000,NULL,2,NULL,autohelperbarrierspat168,3,0.000000},
  {barrierspat169,3,8, "Nonterritory14",-2,0,0,1,2,1,0x0,146,
    { 0x3c3c0000, 0x003f3c00, 0x00f0f030, 0xf0f00000, 0x3c3f0000, 0x003c3c30, 0x00f0f000, 0xf0f00000},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat169,0,1.000000},
  {barrierspat170,5,8, "Nonterritory15",-3,0,0,1,3,1,0x8,147,
    { 0x3c3c0000, 0x003f3f00, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f000, 0xf0f00000},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat170,0,1.000000},
  {barrierspat171,3,8, "Nonterritory16",-1,-1,2,0,3,1,0x8,162,
    { 0xc0f0f0f0, 0xfcf00000, 0x3c3c0c00, 0x003fff00, 0x00f0fc00, 0xf0f0c000, 0xff3f0000, 0x0c3c3c3c},
    { 0x00200060, 0x00200000, 0x00200000, 0x00220100, 0x00200000, 0x00200000, 0x01220000, 0x00200024}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat171,3,1.000000},
  {barrierspat172,3,8, "Nonterritory17",-1,0,1,1,2,1,0x8,145,
    { 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000, 0xfcfc0000, 0xfcfc0000, 0x3c3c3c00, 0x00fcfc00, 0xf0f0f000},
    { 0x00240800, 0x00209000, 0x80600000, 0x18200000, 0x90200000, 0x08240000, 0x00201800, 0x00608000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat172,3,3.000000},
  {barrierspat173,3,8, "Nonterritory17b",0,0,1,1,1,1,0x8,144,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00102400, 0x00904000, 0x60100000, 0x04180000, 0x40900000, 0x24100000, 0x00180400, 0x00106000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat173,0,3.000000},
  {barrierspat174,4,8, "Nonterritory18a",0,-1,1,2,1,3,0x2,161,
    { 0x00fef700, 0xf0f070e0, 0x7cfc0000, 0x343c3c00, 0x70f0f000, 0xf7fe0000, 0x3c3c342c, 0x00fc7c00},
    { 0x00240100, 0x00201040, 0x00600000, 0x10200000, 0x10200000, 0x01240000, 0x00201004, 0x00600000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat174,3,3.000000},
  {barrierspat175,6,8, "Nonterritory18b",0,-2,1,2,1,4,0x2,178,
    { 0x00fef700, 0xf0f070e0, 0x7fff0000, 0x343c3c3c, 0x70f0f0f0, 0xf7fe0000, 0x3c3c342c, 0x00ff7f00},
    { 0x00240100, 0x00201040, 0x00600000, 0x10200000, 0x10200000, 0x01240000, 0x00201004, 0x00600000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat175,3,3.000000},
  {barrierspat176,2,8, "Nonterritory19",-1,-1,1,0,2,1,0x0,127,
    { 0xc0f0f000, 0xfcf00000, 0x3c3c0c00, 0x003cfc00, 0x00f0fc00, 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00},
    { 0x00201000, 0x00600000, 0x10200000, 0x00240000, 0x00600000, 0x10200000, 0x00240000, 0x00201000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat176,3,1.600000},
  {barrierspat177,2,8, "Nonterritory20",0,-1,1,0,1,1,0x0,127,
    { 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0x003c3c00},
    { 0x00201000, 0x00600000, 0x10200000, 0x00240000, 0x00600000, 0x10200000, 0x00240000, 0x00201000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat177,3,1.600000},
  {barrierspat178,2,8, "Nonterritory21",-1,-1,1,0,2,1,0x0,162,
    { 0xf0f0c000, 0xfc3c0000, 0x0c3c3c00, 0x00f0fc00, 0x003cfc00, 0xc0f0f000, 0xfcf00000, 0x3c3c0c00},
    { 0x00204000, 0x40200000, 0x04200000, 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x00200400}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat178,3,1.600000},
  {barrierspat179,2,8, "Nonterritory22",-1,-1,1,0,2,1,0x0,127,
    { 0xc0f0c000, 0xfc300000, 0x0c3c0c00, 0x0030fc00, 0x0030fc00, 0xc0f0c000, 0xfc300000, 0x0c3c0c00},
    { 0x00204000, 0x40200000, 0x04200000, 0x00200400, 0x00204000, 0x40200000, 0x04200000, 0x00200400}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat179,3,1.000000},
  {barrierspat180,1,4, "Nonterritory23",0,0,0,1,0,1,0x0,144,
    { 0x003c0000, 0x00303000, 0x00f00000, 0x30300000, 0x30300000, 0x003c0000, 0x00303000, 0x00f00000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x80000,0.000000,NULL,2,NULL,autohelperbarrierspat180,0,0.000000},
  {barrierspat181,1,4, "Nonterritory24",0,0,0,1,0,1,0x0,144,
    { 0x003c0000, 0x00303000, 0x00f00000, 0x30300000, 0x30300000, 0x003c0000, 0x00303000, 0x00f00000},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x80000,0.000000,NULL,2,NULL,autohelperbarrierspat181,3,0.000000},
  {barrierspat182,2,8, "Nonterritory25",0,0,1,1,1,1,0x8,144,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00240000, 0x00201000, 0x00600000, 0x10200000, 0x10200000, 0x00240000, 0x00201000, 0x00600000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat182,3,1.810000},
  {barrierspat183,5,8, "Nonterritory26",0,-2,2,0,2,2,0x0,178,
    { 0x00f0f0f0, 0xf0f00000, 0x3f3c0000, 0x003f3f0c, 0x00f0f0c0, 0xf0f00000, 0x3f3f0000, 0x003c3f3c},
    { 0x00208060, 0x80200000, 0x09200000, 0x00220904, 0x00208040, 0x80200000, 0x09220000, 0x00200924}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat183,3,1.000000},
  {barrierspat184,2,4, "Nonterritory27",0,0,0,2,0,2,0x0,144,
    { 0x003f0000, 0x00303030, 0x00f00000, 0x30300000, 0x30300000, 0x003f0000, 0x00303030, 0x00f00000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat184,0,1.000000},
  {barrierspat185,1,8, "Nonterritory28",0,0,1,1,1,1,0x0,144,
    { 0x003c1c00, 0x0070f000, 0xd0f00000, 0x3c340000, 0xf0700000, 0x1c3c0000, 0x00343c00, 0x00f0d000},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000, 0x00100000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat185,0,1.000000},
  {barrierspat186,5,8, "Nonterritory29",0,-1,1,2,1,3,0x2,161,
    { 0x003fff00, 0xc0f0f0f0, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xff3f0000, 0x0c3c3c3c, 0x00f0fc00},
    { 0x00148000, 0x80101000, 0x08500000, 0x10100800, 0x10108000, 0x80140000, 0x08101000, 0x00500800}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat186,0,1.600000},
  {barrierspat187,5,8, "Nonterritory30",0,-1,1,2,1,3,0x2,161,
    { 0x003fff00, 0xc0f0f0f0, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xff3f0000, 0x0c3c3c3c, 0x00f0fc00},
    { 0x00284000, 0x40202000, 0x04a00000, 0x20200400, 0x20204000, 0x40280000, 0x04202000, 0x00a00400}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat187,3,1.960000},
  {barrierspat188,7,8, "Nonterritory31",0,-1,1,3,1,4,0x2,161,
    { 0x003fff00, 0xc0f0f0f0, 0xfcf00000, 0x3c3c0c00, 0xf0f0c000, 0xff3f0000, 0x0c3c3c3c, 0x00f0fc00},
    { 0x002a4000, 0x40202020, 0x04a00000, 0x20200400, 0x20204000, 0x402a0000, 0x04202020, 0x00a00400}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat188,3,1.600000},
  {barrierspat189,6,4, "Nonterritory32",0,-2,2,0,2,2,0x0,178,
    { 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0x003f3f3f},
    { 0x00100000, 0x00100000, 0x00100000, 0x00100002, 0x00100000, 0x00100000, 0x00100000, 0x00100002}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat189,0,1.000000},
  {barrierspat190,6,4, "Nonterritory33",0,0,2,2,2,2,0x0,144,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00210002, 0x00200010, 0x00200000, 0x00200000, 0x00200000, 0x00210000, 0x00200012, 0x00200000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat190,3,1.600000},
  {barrierspat191,8,8, "Nonterritory34",0,-2,2,0,2,2,0x2,178,
    { 0x00f0f070, 0xf0f00000, 0x3f3d0000, 0x003f3d1f, 0x00f0f0d0, 0xf0f00000, 0x3d3f0000, 0x003d3f37},
    { 0x00109010, 0x80500000, 0x18100000, 0x00150800, 0x00508000, 0x90100000, 0x08150000, 0x00101810}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat191,0,1.497760},
  {barrierspat192,4,8, "Nonterritory35",0,-2,1,0,1,2,0x0,178,
    { 0x00f0f000, 0xf0f00000, 0x3f3f0000, 0x003c3c3c, 0x00f0f0f0, 0xf0f00000, 0x3c3c0000, 0x003f3f00},
    { 0x00102000, 0x00900000, 0x20100000, 0x00180000, 0x00900000, 0x20100000, 0x00180000, 0x00102000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat192,0,1.600000},
  {barrierspat193,6,8, "Nonterritory36",0,0,2,2,2,2,0x2,144,
    { 0x003c3f38, 0x00f0f0c0, 0xf0f00000, 0x3e3f0000, 0xf0f00000, 0x3f3c0000, 0x003f3e0c, 0x00f0f0b0},
    { 0x00180600, 0x00106080, 0x40900000, 0x24100000, 0x60100000, 0x06180000, 0x00102408, 0x00904000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat193,0,0.610000},
  {barrierspat194,5,8, "Nonterritory37",0,0,2,2,2,2,0x2,144,
    { 0x003c3f34, 0x00f0f0c0, 0xf0f00000, 0x3d3f0000, 0xf0f00000, 0x3f3c0000, 0x003f3d0c, 0x00f0f070},
    { 0x00200900, 0x00208040, 0x80200000, 0x08200000, 0x80200000, 0x09200000, 0x00200804, 0x00208000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat194,3,0.970000},
  {barrierspat195,7,8, "Nonterritory38",0,0,2,2,2,2,0x0,144,
    { 0x003c3f3f, 0x00f0f0c0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3c0000, 0x003f3f0f, 0x00f0f0f0},
    { 0x00180601, 0x00106080, 0x40900000, 0x24100000, 0x60100000, 0x06180000, 0x00102409, 0x00904000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat195,0,3.000000},
  {barrierspat196,7,8, "Nonterritory39",0,0,2,2,2,2,0x0,144,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00210902, 0x00208050, 0x80200000, 0x08200000, 0x80200000, 0x09210000, 0x00200816, 0x00208000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat196,3,3.000000},
  {barrierspat197,9,8, "Nonterritory40",0,-1,3,1,3,2,0x2,161,
    { 0x00bcfcfc, 0xe0f0f000, 0xfcf80000, 0x3f3f2f00, 0xf0f0e000, 0xfcbc0000, 0x2f3f3f00, 0x00f8fcfc},
    { 0x00206000, 0x40a00000, 0x24200000, 0x00280400, 0x00a04000, 0x60200000, 0x04280000, 0x00202400}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat197,3,1.000000},
  {barrierspat198,6,8, "Nonterritory41",0,-2,2,1,2,3,0x0,178,
    { 0x00b8fcf0, 0xe0f0e000, 0xffb80000, 0x2c3f2f0f, 0xe0f0e0c0, 0xfcb80000, 0x2f3f2c00, 0x00b8ff3f},
    { 0x00100420, 0x00104000, 0x42100000, 0x04120008, 0x40100080, 0x04100000, 0x00120400, 0x00104220}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat198,0,1.000000},
  {barrierspat199,3,8, "Nonterritory42",0,0,1,1,1,1,0x0,144,
    { 0x003c3c00, 0x00f0f000, 0xf0f00000, 0x3c3c0000, 0xf0f00000, 0x3c3c0000, 0x003c3c00, 0x00f0f000},
    { 0x00180400, 0x00106000, 0x40900000, 0x24100000, 0x60100000, 0x04180000, 0x00102400, 0x00904000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat199,0,3.960000},
  {barrierspat200,9,8, "Nonterritory43",0,-1,2,2,2,3,0x0,161,
    { 0x00bdffbf, 0xe0f0f0d0, 0xfcf80000, 0x3f3f2e00, 0xf0f0e000, 0xffbd0000, 0x2e3f3f1f, 0x00f8fcf8},
    { 0x00184212, 0x40102080, 0x04900000, 0x20110400, 0x20104000, 0x42180000, 0x0411200a, 0x00900410}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat200,0,1.600000},
  {barrierspat201,13,8, "Nonterritory44",0,0,2,4,2,4,0x2,144,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x001a0500, 0x00106060, 0x40900000, 0x24100000, 0x60100000, 0x051a0000, 0x00102424, 0x00904000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat201,0,1.600000},
  {barrierspat202,4,8, "Nonterritory45",0,0,1,2,1,2,0x0,144,
    { 0x003f0f00, 0x0030f0f0, 0xc0f00000, 0x3c300000, 0xf0300000, 0x0f3f0000, 0x00303c3c, 0x00f0c000},
    { 0x00120800, 0x00108020, 0x80100000, 0x08100000, 0x80100000, 0x08120000, 0x00100820, 0x00108000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat202,0,1.186000},
  {barrierspat203,8,8, "Nonterritory46",0,-2,3,1,3,3,0x0,178,
    { 0x0030fcfc, 0xc0f0c000, 0xff300000, 0x0f3f0f0f, 0xc0f0c0c0, 0xfc300000, 0x0f3f0f00, 0x0030ffff},
    { 0x00200000, 0x00200000, 0x01200000, 0x00200006, 0x00200040, 0x00200000, 0x00200000, 0x00200102}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat203,3,1.000000},
  {barrierspat204,6,4, "Nonterritory47",-1,0,0,4,1,4,0x0,145,
    { 0x0a3f0000, 0x00303838, 0x00f08000, 0xb0300000, 0x38300000, 0x003f0a00, 0x0030b0b0, 0x80f00000},
    { 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000, 0x00200000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat204,3,1.600000},
  {barrierspat205,4,8, "Nonterritory48",-1,0,1,2,2,2,0x0,145,
    { 0x0c3f0f00, 0x0030fcf0, 0xc0f0c000, 0xfc300000, 0xfc300000, 0x0f3f0c00, 0x0030fc3c, 0xc0f0c000},
    { 0x00100900, 0x00108040, 0x80100000, 0x08100000, 0x80100000, 0x09100000, 0x00100804, 0x00108000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat205,0,3.000000},
  {barrierspat206,4,8, "Nonterritory49",0,-1,2,1,2,2,0x0,161,
    { 0x0030fcf0, 0xc0f0c000, 0xfc300000, 0x0c3f0f00, 0xc0f0c000, 0xfc300000, 0x0f3f0c00, 0x0030fc3c},
    { 0x00100800, 0x00108000, 0x80100000, 0x08100000, 0x80100000, 0x08100000, 0x00100800, 0x00108000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat206,0,1.600000},
  {barrierspat207,4,8, "Nonterritory50",0,-2,2,0,2,2,0x0,178,
    { 0x0030f0f0, 0xc0f00000, 0x3f300000, 0x003f0f0c, 0x00f0c0c0, 0xf0300000, 0x0f3f0000, 0x00303f3c},
    { 0x00100000, 0x00100000, 0x02100000, 0x00100008, 0x00100080, 0x00100000, 0x00100000, 0x00100200}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat207,0,1.600000},
  {barrierspat208,5,8, "Nonterritory51",0,-1,2,1,2,2,0x0,161,
    { 0x00f4fcfc, 0xf0f0d000, 0xfc7c0000, 0x1f3f3f00, 0xd0f0f000, 0xfcf40000, 0x3f3f1f00, 0x007cfcfc},
    { 0x00102018, 0x00900000, 0x20100000, 0x02190000, 0x00900000, 0x20100000, 0x00190200, 0x00102090}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat208,0,2.800000},
  {barrierspat209,4,8, "Nonterritory52",0,0,2,2,2,2,0x0,144,
    { 0x00303f0c, 0x00f0c0c0, 0xf0300000, 0x0f3c0000, 0xc0f00000, 0x3f300000, 0x003c0f0c, 0x0030f0c0},
    { 0x00100900, 0x00108040, 0x80100000, 0x08100000, 0x80100000, 0x09100000, 0x00100804, 0x00108000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat209,0,1.690000},
  {barrierspat210,5,8, "Nonterritory53",0,0,2,2,2,2,0x0,144,
    { 0x003f3f0c, 0x00f0f0f0, 0xf0f00000, 0x3f3c0000, 0xf0f00000, 0x3f3f0000, 0x003c3f3c, 0x00f0f0c0},
    { 0x00110900, 0x00108050, 0x80100000, 0x08100000, 0x80100000, 0x09110000, 0x00100814, 0x00108000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat210,0,2.800000},
  {barrierspat211,7,8, "Nonterritory54",0,0,2,2,2,2,0x2,144,
    { 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0},
    { 0x00180000, 0x00102000, 0x00900000, 0x20100000, 0x20100000, 0x00180000, 0x00102000, 0x00900000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat211,0,3.600000},
  {barrierspat212,2,8, "Nonterritory55",0,-2,1,1,1,3,0x2,178,
    { 0x00fcfc00, 0xf0f0f000, 0xfffc0000, 0x3c3c3c0c, 0xf0f0f0c0, 0xfcfc0000, 0x3c3c3c00, 0x00fcff00},
    { 0x00200000, 0x00200000, 0x01200000, 0x00200004, 0x00200040, 0x00200000, 0x00200000, 0x00200100}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat212,3,1.600000},
  {barrierspat213,5,8, "Nonterritory56",-1,0,1,2,2,2,0x0,145,
    { 0x3f3f0f00, 0x003cfcfc, 0xc0f0f000, 0xfcf00000, 0xfc3c0000, 0x0f3f3f00, 0x00f0fcfc, 0xf0f0c000},
    { 0x00210400, 0x00204010, 0x40200000, 0x04200000, 0x40200000, 0x04210000, 0x00200410, 0x00204000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat213,3,1.000000},
  {barrierspat214,8,8, "Nonterritory57",0,-2,2,0,2,2,0xa,178,
    { 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0x003f3f3f, 0x00f0f0f0, 0xf0f00000, 0x3f3f0000, 0x003f3f3f},
    { 0x00209000, 0x80600000, 0x18200000, 0x00240800, 0x00608000, 0x90200000, 0x08240000, 0x00201800}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat214,3,1.600000},
  {barrierspat215,8,4, "Nonterritory58",0,0,1,4,1,4,0x2,144,
    { 0x003f1f00, 0x0070f0f0, 0xd0f00000, 0x3c340000, 0xf0700000, 0x1f3f0000, 0x00343c3c, 0x00f0d000},
    { 0x00250000, 0x00201010, 0x00600000, 0x10200000, 0x10200000, 0x00250000, 0x00201010, 0x00600000}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat215,3,4.800000},
  {barrierspat216,7,8, "Nonterritory59",0,-1,2,2,2,3,0x0,161,
    { 0x003fff3c, 0xc0f0f0f0, 0xfcf00000, 0x3f3f0c00, 0xf0f0c000, 0xff3f0000, 0x0c3f3f3c, 0x00f0fcf0},
    { 0x00168014, 0x80101020, 0x08500000, 0x11110800, 0x10108000, 0x80160000, 0x08111120, 0x00500850}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat216,0,4.800000},
  {barrierspat217,5,8, "Nonterritory60",0,-2,2,1,2,3,0x0,178,
    { 0x003cfc3c, 0xc0f0f000, 0xfff00000, 0x3f3f0c0c, 0xf0f0c0c0, 0xfc3c0000, 0x0c3f3f00, 0x00f0fff0},
    { 0x00140018, 0x00101000, 0x02500000, 0x12110008, 0x10100080, 0x00140000, 0x00111200, 0x00500290}
   , 0x80000,0.000000,NULL,3,NULL,autohelperbarrierspat217,0,4.800000},
  {NULL, 0,0,NULL,0,0,0,0,0,0,0,0,{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},0,0.0,NULL,0,NULL,NULL,0,0.0}
};

struct pattern_db barrierspat_db = {
  -1,
  0,
  barrierspat
 , NULL
};
