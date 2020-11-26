/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Tue Nov 24 01:06:11 JST 2020 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw.native -fma -compact -variables 4 -pipeline-latency 4 -n 20 -name n1_20 -include dft/scalar/n.h */

/*
 * This function contains 208 FP additions, 72 FP multiplications,
 * (or, 136 additions, 0 multiplications, 72 fused multiply/add),
 * 81 stack variables, 4 constants, and 80 memory accesses
 */
#include "dft/scalar/n.h"

static void n1_20(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, ri = ri + ivs, ii = ii + ivs, ro = ro + ovs, io = io + ovs, MAKE_VOLATILE_STRIDE(80, is), MAKE_VOLATILE_STRIDE(80, os)) {
	       E T7, T2N, T3b, TD, TP, T1R, T2f, T1d, Tt, TA, TB, T2w, T2z, T2P, T35;
	       E T36, T3d, TH, TI, TJ, T15, T1a, T1b, T1s, T1x, T1T, T29, T2a, T2h, T1h;
	       E T1i, T1j, Te, Tl, Tm, T2D, T2G, T2O, T32, T33, T3c, TE, TF, TG, TU;
	       E TZ, T10, T1D, T1I, T1S, T26, T27, T2g, T1e, T1f, T1g;
	       {
		    E T3, T1N, TN, T2L, T6, TO, T1Q, T2M;
		    {
			 E T1, T2, TL, TM;
			 T1 = ri[0];
			 T2 = ri[WS(is, 10)];
			 T3 = T1 + T2;
			 T1N = T1 - T2;
			 TL = ii[0];
			 TM = ii[WS(is, 10)];
			 TN = TL - TM;
			 T2L = TL + TM;
		    }
		    {
			 E T4, T5, T1O, T1P;
			 T4 = ri[WS(is, 5)];
			 T5 = ri[WS(is, 15)];
			 T6 = T4 + T5;
			 TO = T4 - T5;
			 T1O = ii[WS(is, 5)];
			 T1P = ii[WS(is, 15)];
			 T1Q = T1O - T1P;
			 T2M = T1O + T1P;
		    }
		    T7 = T3 - T6;
		    T2N = T2L - T2M;
		    T3b = T2L + T2M;
		    TD = T3 + T6;
		    TP = TN - TO;
		    T1R = T1N - T1Q;
		    T2f = T1N + T1Q;
		    T1d = TO + TN;
	       }
	       {
		    E Tp, T1o, T13, T2u, Ts, T14, T1r, T2v, Tw, T1t, T18, T2x, Tz, T19, T1w;
		    E T2y;
		    {
			 E Tn, To, T11, T12;
			 Tn = ri[WS(is, 8)];
			 To = ri[WS(is, 18)];
			 Tp = Tn + To;
			 T1o = Tn - To;
			 T11 = ii[WS(is, 8)];
			 T12 = ii[WS(is, 18)];
			 T13 = T11 - T12;
			 T2u = T11 + T12;
		    }
		    {
			 E Tq, Tr, T1p, T1q;
			 Tq = ri[WS(is, 13)];
			 Tr = ri[WS(is, 3)];
			 Ts = Tq + Tr;
			 T14 = Tq - Tr;
			 T1p = ii[WS(is, 13)];
			 T1q = ii[WS(is, 3)];
			 T1r = T1p - T1q;
			 T2v = T1p + T1q;
		    }
		    {
			 E Tu, Tv, T16, T17;
			 Tu = ri[WS(is, 12)];
			 Tv = ri[WS(is, 2)];
			 Tw = Tu + Tv;
			 T1t = Tu - Tv;
			 T16 = ii[WS(is, 12)];
			 T17 = ii[WS(is, 2)];
			 T18 = T16 - T17;
			 T2x = T16 + T17;
		    }
		    {
			 E Tx, Ty, T1u, T1v;
			 Tx = ri[WS(is, 17)];
			 Ty = ri[WS(is, 7)];
			 Tz = Tx + Ty;
			 T19 = Tx - Ty;
			 T1u = ii[WS(is, 17)];
			 T1v = ii[WS(is, 7)];
			 T1w = T1u - T1v;
			 T2y = T1u + T1v;
		    }
		    Tt = Tp - Ts;
		    TA = Tw - Tz;
		    TB = Tt + TA;
		    T2w = T2u - T2v;
		    T2z = T2x - T2y;
		    T2P = T2w + T2z;
		    T35 = T2u + T2v;
		    T36 = T2x + T2y;
		    T3d = T35 + T36;
		    TH = Tp + Ts;
		    TI = Tw + Tz;
		    TJ = TH + TI;
		    T15 = T13 - T14;
		    T1a = T18 - T19;
		    T1b = T15 + T1a;
		    T1s = T1o - T1r;
		    T1x = T1t - T1w;
		    T1T = T1s + T1x;
		    T29 = T1o + T1r;
		    T2a = T1t + T1w;
		    T2h = T29 + T2a;
		    T1h = T14 + T13;
		    T1i = T19 + T18;
		    T1j = T1h + T1i;
	       }
	       {
		    E Ta, T1z, TS, T2B, Td, TT, T1C, T2C, Th, T1E, TX, T2E, Tk, TY, T1H;
		    E T2F;
		    {
			 E T8, T9, TQ, TR;
			 T8 = ri[WS(is, 4)];
			 T9 = ri[WS(is, 14)];
			 Ta = T8 + T9;
			 T1z = T8 - T9;
			 TQ = ii[WS(is, 4)];
			 TR = ii[WS(is, 14)];
			 TS = TQ - TR;
			 T2B = TQ + TR;
		    }
		    {
			 E Tb, Tc, T1A, T1B;
			 Tb = ri[WS(is, 9)];
			 Tc = ri[WS(is, 19)];
			 Td = Tb + Tc;
			 TT = Tb - Tc;
			 T1A = ii[WS(is, 9)];
			 T1B = ii[WS(is, 19)];
			 T1C = T1A - T1B;
			 T2C = T1A + T1B;
		    }
		    {
			 E Tf, Tg, TV, TW;
			 Tf = ri[WS(is, 16)];
			 Tg = ri[WS(is, 6)];
			 Th = Tf + Tg;
			 T1E = Tf - Tg;
			 TV = ii[WS(is, 16)];
			 TW = ii[WS(is, 6)];
			 TX = TV - TW;
			 T2E = TV + TW;
		    }
		    {
			 E Ti, Tj, T1F, T1G;
			 Ti = ri[WS(is, 1)];
			 Tj = ri[WS(is, 11)];
			 Tk = Ti + Tj;
			 TY = Ti - Tj;
			 T1F = ii[WS(is, 1)];
			 T1G = ii[WS(is, 11)];
			 T1H = T1F - T1G;
			 T2F = T1F + T1G;
		    }
		    Te = Ta - Td;
		    Tl = Th - Tk;
		    Tm = Te + Tl;
		    T2D = T2B - T2C;
		    T2G = T2E - T2F;
		    T2O = T2D + T2G;
		    T32 = T2B + T2C;
		    T33 = T2E + T2F;
		    T3c = T32 + T33;
		    TE = Ta + Td;
		    TF = Th + Tk;
		    TG = TE + TF;
		    TU = TS - TT;
		    TZ = TX - TY;
		    T10 = TU + TZ;
		    T1D = T1z - T1C;
		    T1I = T1E - T1H;
		    T1S = T1D + T1I;
		    T26 = T1z + T1C;
		    T27 = T1E + T1H;
		    T2g = T26 + T27;
		    T1e = TT + TS;
		    T1f = TY + TX;
		    T1g = T1e + T1f;
	       }
	       {
		    E T2s, TC, T2r, T2I, T2K, T2A, T2H, T2J, T2t;
		    T2s = Tm - TB;
		    TC = Tm + TB;
		    T2r = FNMS(KP250000000, TC, T7);
		    T2A = T2w - T2z;
		    T2H = T2D - T2G;
		    T2I = FNMS(KP618033988, T2H, T2A);
		    T2K = FMA(KP618033988, T2A, T2H);
		    ro[WS(os, 10)] = T7 + TC;
		    T2J = FMA(KP559016994, T2s, T2r);
		    ro[WS(os, 14)] = FNMS(KP951056516, T2K, T2J);
		    ro[WS(os, 6)] = FMA(KP951056516, T2K, T2J);
		    T2t = FNMS(KP559016994, T2s, T2r);
		    ro[WS(os, 2)] = FNMS(KP951056516, T2I, T2t);
		    ro[WS(os, 18)] = FMA(KP951056516, T2I, T2t);
	       }
	       {
		    E T2S, T2Q, T2R, T2W, T2Y, T2U, T2V, T2X, T2T;
		    T2S = T2O - T2P;
		    T2Q = T2O + T2P;
		    T2R = FNMS(KP250000000, T2Q, T2N);
		    T2U = Tt - TA;
		    T2V = Te - Tl;
		    T2W = FNMS(KP618033988, T2V, T2U);
		    T2Y = FMA(KP618033988, T2U, T2V);
		    io[WS(os, 10)] = T2N + T2Q;
		    T2X = FMA(KP559016994, T2S, T2R);
		    io[WS(os, 6)] = FNMS(KP951056516, T2Y, T2X);
		    io[WS(os, 14)] = FMA(KP951056516, T2Y, T2X);
		    T2T = FNMS(KP559016994, T2S, T2R);
		    io[WS(os, 2)] = FMA(KP951056516, T2W, T2T);
		    io[WS(os, 18)] = FNMS(KP951056516, T2W, T2T);
	       }
	       {
		    E T30, TK, T2Z, T38, T3a, T34, T37, T39, T31;
		    T30 = TG - TJ;
		    TK = TG + TJ;
		    T2Z = FNMS(KP250000000, TK, TD);
		    T34 = T32 - T33;
		    T37 = T35 - T36;
		    T38 = FMA(KP618033988, T37, T34);
		    T3a = FNMS(KP618033988, T34, T37);
		    ro[0] = TD + TK;
		    T39 = FNMS(KP559016994, T30, T2Z);
		    ro[WS(os, 12)] = FNMS(KP951056516, T3a, T39);
		    ro[WS(os, 8)] = FMA(KP951056516, T3a, T39);
		    T31 = FMA(KP559016994, T30, T2Z);
		    ro[WS(os, 4)] = FNMS(KP951056516, T38, T31);
		    ro[WS(os, 16)] = FMA(KP951056516, T38, T31);
	       }
	       {
		    E T3g, T3e, T3f, T3k, T3m, T3i, T3j, T3l, T3h;
		    T3g = T3c - T3d;
		    T3e = T3c + T3d;
		    T3f = FNMS(KP250000000, T3e, T3b);
		    T3i = TE - TF;
		    T3j = TH - TI;
		    T3k = FMA(KP618033988, T3j, T3i);
		    T3m = FNMS(KP618033988, T3i, T3j);
		    io[0] = T3b + T3e;
		    T3l = FNMS(KP559016994, T3g, T3f);
		    io[WS(os, 8)] = FNMS(KP951056516, T3m, T3l);
		    io[WS(os, 12)] = FMA(KP951056516, T3m, T3l);
		    T3h = FMA(KP559016994, T3g, T3f);
		    io[WS(os, 4)] = FMA(KP951056516, T3k, T3h);
		    io[WS(os, 16)] = FNMS(KP951056516, T3k, T3h);
	       }
	       {
		    E T24, T1c, T23, T2c, T2e, T28, T2b, T2d, T25;
		    T24 = T10 - T1b;
		    T1c = T10 + T1b;
		    T23 = FNMS(KP250000000, T1c, TP);
		    T28 = T26 - T27;
		    T2b = T29 - T2a;
		    T2c = FMA(KP618033988, T2b, T28);
		    T2e = FNMS(KP618033988, T28, T2b);
		    io[WS(os, 5)] = TP + T1c;
		    T2d = FNMS(KP559016994, T24, T23);
		    io[WS(os, 13)] = FNMS(KP951056516, T2e, T2d);
		    io[WS(os, 17)] = FMA(KP951056516, T2e, T2d);
		    T25 = FMA(KP559016994, T24, T23);
		    io[WS(os, 1)] = FNMS(KP951056516, T2c, T25);
		    io[WS(os, 9)] = FMA(KP951056516, T2c, T25);
	       }
	       {
		    E T2k, T2i, T2j, T2o, T2q, T2m, T2n, T2p, T2l;
		    T2k = T2g - T2h;
		    T2i = T2g + T2h;
		    T2j = FNMS(KP250000000, T2i, T2f);
		    T2m = TU - TZ;
		    T2n = T15 - T1a;
		    T2o = FMA(KP618033988, T2n, T2m);
		    T2q = FNMS(KP618033988, T2m, T2n);
		    ro[WS(os, 5)] = T2f + T2i;
		    T2p = FNMS(KP559016994, T2k, T2j);
		    ro[WS(os, 13)] = FMA(KP951056516, T2q, T2p);
		    ro[WS(os, 17)] = FNMS(KP951056516, T2q, T2p);
		    T2l = FMA(KP559016994, T2k, T2j);
		    ro[WS(os, 1)] = FMA(KP951056516, T2o, T2l);
		    ro[WS(os, 9)] = FNMS(KP951056516, T2o, T2l);
	       }
	       {
		    E T1m, T1k, T1l, T1K, T1M, T1y, T1J, T1L, T1n;
		    T1m = T1g - T1j;
		    T1k = T1g + T1j;
		    T1l = FNMS(KP250000000, T1k, T1d);
		    T1y = T1s - T1x;
		    T1J = T1D - T1I;
		    T1K = FNMS(KP618033988, T1J, T1y);
		    T1M = FMA(KP618033988, T1y, T1J);
		    io[WS(os, 15)] = T1d + T1k;
		    T1L = FMA(KP559016994, T1m, T1l);
		    io[WS(os, 11)] = FNMS(KP951056516, T1M, T1L);
		    io[WS(os, 19)] = FMA(KP951056516, T1M, T1L);
		    T1n = FNMS(KP559016994, T1m, T1l);
		    io[WS(os, 3)] = FNMS(KP951056516, T1K, T1n);
		    io[WS(os, 7)] = FMA(KP951056516, T1K, T1n);
	       }
	       {
		    E T1W, T1U, T1V, T20, T22, T1Y, T1Z, T21, T1X;
		    T1W = T1S - T1T;
		    T1U = T1S + T1T;
		    T1V = FNMS(KP250000000, T1U, T1R);
		    T1Y = T1h - T1i;
		    T1Z = T1e - T1f;
		    T20 = FNMS(KP618033988, T1Z, T1Y);
		    T22 = FMA(KP618033988, T1Y, T1Z);
		    ro[WS(os, 15)] = T1R + T1U;
		    T21 = FMA(KP559016994, T1W, T1V);
		    ro[WS(os, 11)] = FMA(KP951056516, T22, T21);
		    ro[WS(os, 19)] = FNMS(KP951056516, T22, T21);
		    T1X = FNMS(KP559016994, T1W, T1V);
		    ro[WS(os, 3)] = FMA(KP951056516, T20, T1X);
		    ro[WS(os, 7)] = FNMS(KP951056516, T20, T1X);
	       }
	  }
     }
}

static const kdft_desc desc = { 20, "n1_20", { 136, 0, 72, 0 }, &GENUS, 0, 0, 0, 0 };

void X(codelet_n1_20) (planner *p) { X(kdft_register) (p, n1_20, &desc);
}

#else

/* Generated by: ../../../genfft/gen_notw.native -compact -variables 4 -pipeline-latency 4 -n 20 -name n1_20 -include dft/scalar/n.h */

/*
 * This function contains 208 FP additions, 48 FP multiplications,
 * (or, 184 additions, 24 multiplications, 24 fused multiply/add),
 * 81 stack variables, 4 constants, and 80 memory accesses
 */
#include "dft/scalar/n.h"

static void n1_20(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, ri = ri + ivs, ii = ii + ivs, ro = ro + ovs, io = io + ovs, MAKE_VOLATILE_STRIDE(80, is), MAKE_VOLATILE_STRIDE(80, os)) {
	       E T7, T2Q, T3h, TD, TP, T1U, T2l, T1d, Tt, TA, TB, T2w, T2z, T2S, T35;
	       E T36, T3f, TH, TI, TJ, T15, T1a, T1b, T1s, T1x, T1W, T29, T2a, T2j, T1h;
	       E T1i, T1j, Te, Tl, Tm, T2D, T2G, T2R, T32, T33, T3e, TE, TF, TG, TU;
	       E TZ, T10, T1D, T1I, T1V, T26, T27, T2i, T1e, T1f, T1g;
	       {
		    E T3, T1Q, TN, T2O, T6, TO, T1T, T2P;
		    {
			 E T1, T2, TL, TM;
			 T1 = ri[0];
			 T2 = ri[WS(is, 10)];
			 T3 = T1 + T2;
			 T1Q = T1 - T2;
			 TL = ii[0];
			 TM = ii[WS(is, 10)];
			 TN = TL - TM;
			 T2O = TL + TM;
		    }
		    {
			 E T4, T5, T1R, T1S;
			 T4 = ri[WS(is, 5)];
			 T5 = ri[WS(is, 15)];
			 T6 = T4 + T5;
			 TO = T4 - T5;
			 T1R = ii[WS(is, 5)];
			 T1S = ii[WS(is, 15)];
			 T1T = T1R - T1S;
			 T2P = T1R + T1S;
		    }
		    T7 = T3 - T6;
		    T2Q = T2O - T2P;
		    T3h = T2O + T2P;
		    TD = T3 + T6;
		    TP = TN - TO;
		    T1U = T1Q - T1T;
		    T2l = T1Q + T1T;
		    T1d = TO + TN;
	       }
	       {
		    E Tp, T1o, T13, T2u, Ts, T14, T1r, T2v, Tw, T1t, T18, T2x, Tz, T19, T1w;
		    E T2y;
		    {
			 E Tn, To, T11, T12;
			 Tn = ri[WS(is, 8)];
			 To = ri[WS(is, 18)];
			 Tp = Tn + To;
			 T1o = Tn - To;
			 T11 = ii[WS(is, 8)];
			 T12 = ii[WS(is, 18)];
			 T13 = T11 - T12;
			 T2u = T11 + T12;
		    }
		    {
			 E Tq, Tr, T1p, T1q;
			 Tq = ri[WS(is, 13)];
			 Tr = ri[WS(is, 3)];
			 Ts = Tq + Tr;
			 T14 = Tq - Tr;
			 T1p = ii[WS(is, 13)];
			 T1q = ii[WS(is, 3)];
			 T1r = T1p - T1q;
			 T2v = T1p + T1q;
		    }
		    {
			 E Tu, Tv, T16, T17;
			 Tu = ri[WS(is, 12)];
			 Tv = ri[WS(is, 2)];
			 Tw = Tu + Tv;
			 T1t = Tu - Tv;
			 T16 = ii[WS(is, 12)];
			 T17 = ii[WS(is, 2)];
			 T18 = T16 - T17;
			 T2x = T16 + T17;
		    }
		    {
			 E Tx, Ty, T1u, T1v;
			 Tx = ri[WS(is, 17)];
			 Ty = ri[WS(is, 7)];
			 Tz = Tx + Ty;
			 T19 = Tx - Ty;
			 T1u = ii[WS(is, 17)];
			 T1v = ii[WS(is, 7)];
			 T1w = T1u - T1v;
			 T2y = T1u + T1v;
		    }
		    Tt = Tp - Ts;
		    TA = Tw - Tz;
		    TB = Tt + TA;
		    T2w = T2u - T2v;
		    T2z = T2x - T2y;
		    T2S = T2w + T2z;
		    T35 = T2u + T2v;
		    T36 = T2x + T2y;
		    T3f = T35 + T36;
		    TH = Tp + Ts;
		    TI = Tw + Tz;
		    TJ = TH + TI;
		    T15 = T13 - T14;
		    T1a = T18 - T19;
		    T1b = T15 + T1a;
		    T1s = T1o - T1r;
		    T1x = T1t - T1w;
		    T1W = T1s + T1x;
		    T29 = T1o + T1r;
		    T2a = T1t + T1w;
		    T2j = T29 + T2a;
		    T1h = T14 + T13;
		    T1i = T19 + T18;
		    T1j = T1h + T1i;
	       }
	       {
		    E Ta, T1z, TS, T2B, Td, TT, T1C, T2C, Th, T1E, TX, T2E, Tk, TY, T1H;
		    E T2F;
		    {
			 E T8, T9, TQ, TR;
			 T8 = ri[WS(is, 4)];
			 T9 = ri[WS(is, 14)];
			 Ta = T8 + T9;
			 T1z = T8 - T9;
			 TQ = ii[WS(is, 4)];
			 TR = ii[WS(is, 14)];
			 TS = TQ - TR;
			 T2B = TQ + TR;
		    }
		    {
			 E Tb, Tc, T1A, T1B;
			 Tb = ri[WS(is, 9)];
			 Tc = ri[WS(is, 19)];
			 Td = Tb + Tc;
			 TT = Tb - Tc;
			 T1A = ii[WS(is, 9)];
			 T1B = ii[WS(is, 19)];
			 T1C = T1A - T1B;
			 T2C = T1A + T1B;
		    }
		    {
			 E Tf, Tg, TV, TW;
			 Tf = ri[WS(is, 16)];
			 Tg = ri[WS(is, 6)];
			 Th = Tf + Tg;
			 T1E = Tf - Tg;
			 TV = ii[WS(is, 16)];
			 TW = ii[WS(is, 6)];
			 TX = TV - TW;
			 T2E = TV + TW;
		    }
		    {
			 E Ti, Tj, T1F, T1G;
			 Ti = ri[WS(is, 1)];
			 Tj = ri[WS(is, 11)];
			 Tk = Ti + Tj;
			 TY = Ti - Tj;
			 T1F = ii[WS(is, 1)];
			 T1G = ii[WS(is, 11)];
			 T1H = T1F - T1G;
			 T2F = T1F + T1G;
		    }
		    Te = Ta - Td;
		    Tl = Th - Tk;
		    Tm = Te + Tl;
		    T2D = T2B - T2C;
		    T2G = T2E - T2F;
		    T2R = T2D + T2G;
		    T32 = T2B + T2C;
		    T33 = T2E + T2F;
		    T3e = T32 + T33;
		    TE = Ta + Td;
		    TF = Th + Tk;
		    TG = TE + TF;
		    TU = TS - TT;
		    TZ = TX - TY;
		    T10 = TU + TZ;
		    T1D = T1z - T1C;
		    T1I = T1E - T1H;
		    T1V = T1D + T1I;
		    T26 = T1z + T1C;
		    T27 = T1E + T1H;
		    T2i = T26 + T27;
		    T1e = TT + TS;
		    T1f = TY + TX;
		    T1g = T1e + T1f;
	       }
	       {
		    E T2s, TC, T2r, T2I, T2K, T2A, T2H, T2J, T2t;
		    T2s = KP559016994 * (Tm - TB);
		    TC = Tm + TB;
		    T2r = FNMS(KP250000000, TC, T7);
		    T2A = T2w - T2z;
		    T2H = T2D - T2G;
		    T2I = FNMS(KP587785252, T2H, KP951056516 * T2A);
		    T2K = FMA(KP951056516, T2H, KP587785252 * T2A);
		    ro[WS(os, 10)] = T7 + TC;
		    T2J = T2s + T2r;
		    ro[WS(os, 14)] = T2J - T2K;
		    ro[WS(os, 6)] = T2J + T2K;
		    T2t = T2r - T2s;
		    ro[WS(os, 2)] = T2t - T2I;
		    ro[WS(os, 18)] = T2t + T2I;
	       }
	       {
		    E T2V, T2T, T2U, T2N, T2Y, T2L, T2M, T2X, T2W;
		    T2V = KP559016994 * (T2R - T2S);
		    T2T = T2R + T2S;
		    T2U = FNMS(KP250000000, T2T, T2Q);
		    T2L = Tt - TA;
		    T2M = Te - Tl;
		    T2N = FNMS(KP587785252, T2M, KP951056516 * T2L);
		    T2Y = FMA(KP951056516, T2M, KP587785252 * T2L);
		    io[WS(os, 10)] = T2Q + T2T;
		    T2X = T2V + T2U;
		    io[WS(os, 6)] = T2X - T2Y;
		    io[WS(os, 14)] = T2Y + T2X;
		    T2W = T2U - T2V;
		    io[WS(os, 2)] = T2N + T2W;
		    io[WS(os, 18)] = T2W - T2N;
	       }
	       {
		    E T2Z, TK, T30, T38, T3a, T34, T37, T39, T31;
		    T2Z = KP559016994 * (TG - TJ);
		    TK = TG + TJ;
		    T30 = FNMS(KP250000000, TK, TD);
		    T34 = T32 - T33;
		    T37 = T35 - T36;
		    T38 = FMA(KP951056516, T34, KP587785252 * T37);
		    T3a = FNMS(KP587785252, T34, KP951056516 * T37);
		    ro[0] = TD + TK;
		    T39 = T30 - T2Z;
		    ro[WS(os, 12)] = T39 - T3a;
		    ro[WS(os, 8)] = T39 + T3a;
		    T31 = T2Z + T30;
		    ro[WS(os, 4)] = T31 - T38;
		    ro[WS(os, 16)] = T31 + T38;
	       }
	       {
		    E T3g, T3i, T3j, T3d, T3m, T3b, T3c, T3l, T3k;
		    T3g = KP559016994 * (T3e - T3f);
		    T3i = T3e + T3f;
		    T3j = FNMS(KP250000000, T3i, T3h);
		    T3b = TE - TF;
		    T3c = TH - TI;
		    T3d = FMA(KP951056516, T3b, KP587785252 * T3c);
		    T3m = FNMS(KP587785252, T3b, KP951056516 * T3c);
		    io[0] = T3h + T3i;
		    T3l = T3j - T3g;
		    io[WS(os, 8)] = T3l - T3m;
		    io[WS(os, 12)] = T3m + T3l;
		    T3k = T3g + T3j;
		    io[WS(os, 4)] = T3d + T3k;
		    io[WS(os, 16)] = T3k - T3d;
	       }
	       {
		    E T23, T1c, T24, T2c, T2e, T28, T2b, T2d, T25;
		    T23 = KP559016994 * (T10 - T1b);
		    T1c = T10 + T1b;
		    T24 = FNMS(KP250000000, T1c, TP);
		    T28 = T26 - T27;
		    T2b = T29 - T2a;
		    T2c = FMA(KP951056516, T28, KP587785252 * T2b);
		    T2e = FNMS(KP587785252, T28, KP951056516 * T2b);
		    io[WS(os, 5)] = TP + T1c;
		    T2d = T24 - T23;
		    io[WS(os, 13)] = T2d - T2e;
		    io[WS(os, 17)] = T2d + T2e;
		    T25 = T23 + T24;
		    io[WS(os, 1)] = T25 - T2c;
		    io[WS(os, 9)] = T25 + T2c;
	       }
	       {
		    E T2k, T2m, T2n, T2h, T2p, T2f, T2g, T2q, T2o;
		    T2k = KP559016994 * (T2i - T2j);
		    T2m = T2i + T2j;
		    T2n = FNMS(KP250000000, T2m, T2l);
		    T2f = TU - TZ;
		    T2g = T15 - T1a;
		    T2h = FMA(KP951056516, T2f, KP587785252 * T2g);
		    T2p = FNMS(KP587785252, T2f, KP951056516 * T2g);
		    ro[WS(os, 5)] = T2l + T2m;
		    T2q = T2n - T2k;
		    ro[WS(os, 13)] = T2p + T2q;
		    ro[WS(os, 17)] = T2q - T2p;
		    T2o = T2k + T2n;
		    ro[WS(os, 1)] = T2h + T2o;
		    ro[WS(os, 9)] = T2o - T2h;
	       }
	       {
		    E T1m, T1k, T1l, T1K, T1M, T1y, T1J, T1L, T1n;
		    T1m = KP559016994 * (T1g - T1j);
		    T1k = T1g + T1j;
		    T1l = FNMS(KP250000000, T1k, T1d);
		    T1y = T1s - T1x;
		    T1J = T1D - T1I;
		    T1K = FNMS(KP587785252, T1J, KP951056516 * T1y);
		    T1M = FMA(KP951056516, T1J, KP587785252 * T1y);
		    io[WS(os, 15)] = T1d + T1k;
		    T1L = T1m + T1l;
		    io[WS(os, 11)] = T1L - T1M;
		    io[WS(os, 19)] = T1L + T1M;
		    T1n = T1l - T1m;
		    io[WS(os, 3)] = T1n - T1K;
		    io[WS(os, 7)] = T1n + T1K;
	       }
	       {
		    E T1Z, T1X, T1Y, T1P, T21, T1N, T1O, T22, T20;
		    T1Z = KP559016994 * (T1V - T1W);
		    T1X = T1V + T1W;
		    T1Y = FNMS(KP250000000, T1X, T1U);
		    T1N = T1h - T1i;
		    T1O = T1e - T1f;
		    T1P = FNMS(KP587785252, T1O, KP951056516 * T1N);
		    T21 = FMA(KP951056516, T1O, KP587785252 * T1N);
		    ro[WS(os, 15)] = T1U + T1X;
		    T22 = T1Z + T1Y;
		    ro[WS(os, 11)] = T21 + T22;
		    ro[WS(os, 19)] = T22 - T21;
		    T20 = T1Y - T1Z;
		    ro[WS(os, 3)] = T1P + T20;
		    ro[WS(os, 7)] = T20 - T1P;
	       }
	  }
     }
}

static const kdft_desc desc = { 20, "n1_20", { 184, 24, 24, 0 }, &GENUS, 0, 0, 0, 0 };

void X(codelet_n1_20) (planner *p) { X(kdft_register) (p, n1_20, &desc);
}

#endif
