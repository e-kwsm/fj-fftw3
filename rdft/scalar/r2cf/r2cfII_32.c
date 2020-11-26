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
/* Generated on Tue Nov 24 01:10:31 JST 2020 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_r2cf.native -fma -compact -variables 4 -pipeline-latency 4 -n 32 -name r2cfII_32 -dft-II -include rdft/scalar/r2cfII.h */

/*
 * This function contains 174 FP additions, 128 FP multiplications,
 * (or, 46 additions, 0 multiplications, 128 fused multiply/add),
 * 62 stack variables, 15 constants, and 64 memory accesses
 */
#include "rdft/scalar/r2cfII.h"

static void r2cfII_32(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP773010453, +0.773010453362736960810906609758469800971041293);
     DK(KP820678790, +0.820678790828660330972281985331011598767386482);
     DK(KP956940335, +0.956940335732208864935797886980269969482849206);
     DK(KP303346683, +0.303346683607342391675883946941299872384187453);
     DK(KP995184726, +0.995184726672196886244836953109479921575474869);
     DK(KP098491403, +0.098491403357164253077197521291327432293052451);
     DK(KP980785280, +0.980785280403230449126182236134239036973933731);
     DK(KP881921264, +0.881921264348355029712756863660388349508442621);
     DK(KP534511135, +0.534511135950791641089685961295362908582039528);
     DK(KP831469612, +0.831469612302545237078788377617905756738560812);
     DK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DK(KP198912367, +0.198912367379658006911597622644676228597850501);
     DK(KP668178637, +0.668178637919298919997757686523080761552472251);
     DK(KP414213562, +0.414213562373095048801688724209698078569671875);
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(128, rs), MAKE_VOLATILE_STRIDE(128, csr), MAKE_VOLATILE_STRIDE(128, csi)) {
	       E T5, T2B, T1z, T2n, Tc, T2C, T1C, T2o, Tm, T1l, T1J, T27, Tv, T1k, T1G;
	       E T26, T15, T1r, T1Y, T2e, T1c, T1s, T1V, T2d, TK, T1o, T1R, T2b, TR, T1p;
	       E T1O, T2a;
	       {
		    E T1, T2l, T4, T2m, T2, T3;
		    T1 = R0[0];
		    T2l = R0[WS(rs, 8)];
		    T2 = R0[WS(rs, 4)];
		    T3 = R0[WS(rs, 12)];
		    T4 = T2 - T3;
		    T2m = T2 + T3;
		    T5 = FNMS(KP707106781, T4, T1);
		    T2B = FNMS(KP707106781, T2m, T2l);
		    T1z = FMA(KP707106781, T4, T1);
		    T2n = FMA(KP707106781, T2m, T2l);
	       }
	       {
		    E T8, T1A, Tb, T1B;
		    {
			 E T6, T7, T9, Ta;
			 T6 = R0[WS(rs, 10)];
			 T7 = R0[WS(rs, 2)];
			 T8 = FMA(KP414213562, T7, T6);
			 T1A = FNMS(KP414213562, T6, T7);
			 T9 = R0[WS(rs, 6)];
			 Ta = R0[WS(rs, 14)];
			 Tb = FMA(KP414213562, Ta, T9);
			 T1B = FMS(KP414213562, T9, Ta);
		    }
		    Tc = T8 - Tb;
		    T2C = T1B - T1A;
		    T1C = T1A + T1B;
		    T2o = T8 + Tb;
	       }
	       {
		    E Te, Tj, Th, Tk, Tf, Tg;
		    Te = R0[WS(rs, 7)];
		    Tj = R0[WS(rs, 15)];
		    Tf = R0[WS(rs, 3)];
		    Tg = R0[WS(rs, 11)];
		    Th = Tf + Tg;
		    Tk = Tg - Tf;
		    {
			 E Ti, Tl, T1H, T1I;
			 Ti = FNMS(KP707106781, Th, Te);
			 Tl = FNMS(KP707106781, Tk, Tj);
			 Tm = FNMS(KP668178637, Tl, Ti);
			 T1l = FMA(KP668178637, Ti, Tl);
			 T1H = FMA(KP707106781, Th, Te);
			 T1I = FMA(KP707106781, Tk, Tj);
			 T1J = FMA(KP198912367, T1I, T1H);
			 T27 = FNMS(KP198912367, T1H, T1I);
		    }
	       }
	       {
		    E Tn, Ts, Tq, Tt, To, Tp;
		    Tn = R0[WS(rs, 9)];
		    Ts = R0[WS(rs, 1)];
		    To = R0[WS(rs, 5)];
		    Tp = R0[WS(rs, 13)];
		    Tq = To + Tp;
		    Tt = To - Tp;
		    {
			 E Tr, Tu, T1E, T1F;
			 Tr = FNMS(KP707106781, Tq, Tn);
			 Tu = FNMS(KP707106781, Tt, Ts);
			 Tv = FNMS(KP668178637, Tu, Tr);
			 T1k = FMA(KP668178637, Tr, Tu);
			 T1E = FMA(KP707106781, Tq, Tn);
			 T1F = FMA(KP707106781, Tt, Ts);
			 T1G = FMA(KP198912367, T1F, T1E);
			 T26 = FNMS(KP198912367, T1E, T1F);
		    }
	       }
	       {
		    E TT, T16, TW, T17, T10, T1a, T13, T19, TU, TV;
		    TT = R1[WS(rs, 15)];
		    T16 = R1[WS(rs, 7)];
		    TU = R1[WS(rs, 3)];
		    TV = R1[WS(rs, 11)];
		    TW = TU - TV;
		    T17 = TU + TV;
		    {
			 E TY, TZ, T11, T12;
			 TY = R1[WS(rs, 9)];
			 TZ = R1[WS(rs, 1)];
			 T10 = FMA(KP414213562, TZ, TY);
			 T1a = FNMS(KP414213562, TY, TZ);
			 T11 = R1[WS(rs, 5)];
			 T12 = R1[WS(rs, 13)];
			 T13 = FMA(KP414213562, T12, T11);
			 T19 = FMS(KP414213562, T11, T12);
		    }
		    {
			 E TX, T14, T1W, T1X;
			 TX = FMA(KP707106781, TW, TT);
			 T14 = T10 - T13;
			 T15 = FMA(KP923879532, T14, TX);
			 T1r = FNMS(KP923879532, T14, TX);
			 T1W = FMA(KP707106781, T17, T16);
			 T1X = T10 + T13;
			 T1Y = FNMS(KP923879532, T1X, T1W);
			 T2e = FMA(KP923879532, T1X, T1W);
		    }
		    {
			 E T18, T1b, T1T, T1U;
			 T18 = FNMS(KP707106781, T17, T16);
			 T1b = T19 - T1a;
			 T1c = FNMS(KP923879532, T1b, T18);
			 T1s = FMA(KP923879532, T1b, T18);
			 T1T = FMS(KP707106781, TW, TT);
			 T1U = T1a + T19;
			 T1V = FNMS(KP923879532, T1U, T1T);
			 T2d = FMA(KP923879532, T1U, T1T);
		    }
	       }
	       {
		    E Ty, TL, TB, TM, TF, TP, TI, TO, Tz, TA;
		    Ty = R1[0];
		    TL = R1[WS(rs, 8)];
		    Tz = R1[WS(rs, 4)];
		    TA = R1[WS(rs, 12)];
		    TB = Tz - TA;
		    TM = Tz + TA;
		    {
			 E TD, TE, TG, TH;
			 TD = R1[WS(rs, 10)];
			 TE = R1[WS(rs, 2)];
			 TF = FMA(KP414213562, TE, TD);
			 TP = FNMS(KP414213562, TD, TE);
			 TG = R1[WS(rs, 6)];
			 TH = R1[WS(rs, 14)];
			 TI = FMA(KP414213562, TH, TG);
			 TO = FMS(KP414213562, TG, TH);
		    }
		    {
			 E TC, TJ, T1P, T1Q;
			 TC = FNMS(KP707106781, TB, Ty);
			 TJ = TF - TI;
			 TK = FNMS(KP923879532, TJ, TC);
			 T1o = FMA(KP923879532, TJ, TC);
			 T1P = FMA(KP707106781, TM, TL);
			 T1Q = TF + TI;
			 T1R = FNMS(KP923879532, T1Q, T1P);
			 T2b = FMA(KP923879532, T1Q, T1P);
		    }
		    {
			 E TN, TQ, T1M, T1N;
			 TN = FNMS(KP707106781, TM, TL);
			 TQ = TO - TP;
			 TR = FNMS(KP923879532, TQ, TN);
			 T1p = FMA(KP923879532, TQ, TN);
			 T1M = FMA(KP707106781, TB, Ty);
			 T1N = TP + TO;
			 T1O = FNMS(KP923879532, T1N, T1M);
			 T2a = FMA(KP923879532, T1N, T1M);
		    }
	       }
	       {
		    E Tx, T1f, T2L, T2N, T1e, T2O, T1i, T2M;
		    {
			 E Td, Tw, T2J, T2K;
			 Td = FNMS(KP923879532, Tc, T5);
			 Tw = Tm - Tv;
			 Tx = FMA(KP831469612, Tw, Td);
			 T1f = FNMS(KP831469612, Tw, Td);
			 T2J = FNMS(KP923879532, T2C, T2B);
			 T2K = T1k + T1l;
			 T2L = FMA(KP831469612, T2K, T2J);
			 T2N = FNMS(KP831469612, T2K, T2J);
		    }
		    {
			 E TS, T1d, T1g, T1h;
			 TS = FNMS(KP534511135, TR, TK);
			 T1d = FNMS(KP534511135, T1c, T15);
			 T1e = TS - T1d;
			 T2O = TS + T1d;
			 T1g = FMA(KP534511135, TK, TR);
			 T1h = FMA(KP534511135, T15, T1c);
			 T1i = T1g - T1h;
			 T2M = T1g + T1h;
		    }
		    Cr[WS(csr, 13)] = FNMS(KP881921264, T1e, Tx);
		    Ci[WS(csi, 13)] = FNMS(KP881921264, T2M, T2L);
		    Cr[WS(csr, 2)] = FMA(KP881921264, T1e, Tx);
		    Ci[WS(csi, 2)] = -(FMA(KP881921264, T2M, T2L));
		    Cr[WS(csr, 10)] = FNMS(KP881921264, T1i, T1f);
		    Ci[WS(csi, 10)] = -(FMA(KP881921264, T2O, T2N));
		    Cr[WS(csr, 5)] = FMA(KP881921264, T1i, T1f);
		    Ci[WS(csi, 5)] = FNMS(KP881921264, T2O, T2N);
	       }
	       {
		    E T29, T2h, T2r, T2t, T2g, T2u, T2k, T2s;
		    {
			 E T25, T28, T2p, T2q;
			 T25 = FMA(KP923879532, T1C, T1z);
			 T28 = T26 - T27;
			 T29 = FMA(KP980785280, T28, T25);
			 T2h = FNMS(KP980785280, T28, T25);
			 T2p = FMA(KP923879532, T2o, T2n);
			 T2q = T1G + T1J;
			 T2r = FMA(KP980785280, T2q, T2p);
			 T2t = FNMS(KP980785280, T2q, T2p);
		    }
		    {
			 E T2c, T2f, T2i, T2j;
			 T2c = FNMS(KP098491403, T2b, T2a);
			 T2f = FMA(KP098491403, T2e, T2d);
			 T2g = T2c + T2f;
			 T2u = T2f - T2c;
			 T2i = FMA(KP098491403, T2a, T2b);
			 T2j = FNMS(KP098491403, T2d, T2e);
			 T2k = T2i - T2j;
			 T2s = T2i + T2j;
		    }
		    Cr[WS(csr, 15)] = FNMS(KP995184726, T2g, T29);
		    Ci[WS(csi, 15)] = FNMS(KP995184726, T2s, T2r);
		    Cr[0] = FMA(KP995184726, T2g, T29);
		    Ci[0] = -(FMA(KP995184726, T2s, T2r));
		    Cr[WS(csr, 8)] = FNMS(KP995184726, T2k, T2h);
		    Ci[WS(csi, 8)] = FMS(KP995184726, T2u, T2t);
		    Cr[WS(csr, 7)] = FMA(KP995184726, T2k, T2h);
		    Ci[WS(csi, 7)] = FMA(KP995184726, T2u, T2t);
	       }
	       {
		    E T1n, T1v, T2F, T2H, T1u, T2I, T1y, T2G;
		    {
			 E T1j, T1m, T2D, T2E;
			 T1j = FMA(KP923879532, Tc, T5);
			 T1m = T1k - T1l;
			 T1n = FMA(KP831469612, T1m, T1j);
			 T1v = FNMS(KP831469612, T1m, T1j);
			 T2D = FMA(KP923879532, T2C, T2B);
			 T2E = Tv + Tm;
			 T2F = FMA(KP831469612, T2E, T2D);
			 T2H = FNMS(KP831469612, T2E, T2D);
		    }
		    {
			 E T1q, T1t, T1w, T1x;
			 T1q = FMA(KP303346683, T1p, T1o);
			 T1t = FMA(KP303346683, T1s, T1r);
			 T1u = T1q - T1t;
			 T2I = T1q + T1t;
			 T1w = FNMS(KP303346683, T1r, T1s);
			 T1x = FNMS(KP303346683, T1o, T1p);
			 T1y = T1w - T1x;
			 T2G = T1x + T1w;
		    }
		    Cr[WS(csr, 14)] = FNMS(KP956940335, T1u, T1n);
		    Ci[WS(csi, 14)] = FMS(KP956940335, T2G, T2F);
		    Cr[WS(csr, 1)] = FMA(KP956940335, T1u, T1n);
		    Ci[WS(csi, 1)] = FMA(KP956940335, T2G, T2F);
		    Cr[WS(csr, 9)] = FNMS(KP956940335, T1y, T1v);
		    Ci[WS(csi, 9)] = FNMS(KP956940335, T2I, T2H);
		    Cr[WS(csr, 6)] = FMA(KP956940335, T1y, T1v);
		    Ci[WS(csi, 6)] = -(FMA(KP956940335, T2I, T2H));
	       }
	       {
		    E T1L, T21, T2x, T2z, T20, T2A, T24, T2y;
		    {
			 E T1D, T1K, T2v, T2w;
			 T1D = FNMS(KP923879532, T1C, T1z);
			 T1K = T1G - T1J;
			 T1L = FMA(KP980785280, T1K, T1D);
			 T21 = FNMS(KP980785280, T1K, T1D);
			 T2v = FNMS(KP923879532, T2o, T2n);
			 T2w = T26 + T27;
			 T2x = FNMS(KP980785280, T2w, T2v);
			 T2z = FMA(KP980785280, T2w, T2v);
		    }
		    {
			 E T1S, T1Z, T22, T23;
			 T1S = FMA(KP820678790, T1R, T1O);
			 T1Z = FNMS(KP820678790, T1Y, T1V);
			 T20 = T1S + T1Z;
			 T2A = T1Z - T1S;
			 T22 = FMA(KP820678790, T1V, T1Y);
			 T23 = FNMS(KP820678790, T1O, T1R);
			 T24 = T22 - T23;
			 T2y = T23 + T22;
		    }
		    Cr[WS(csr, 12)] = FNMS(KP773010453, T20, T1L);
		    Ci[WS(csi, 12)] = FMS(KP773010453, T2y, T2x);
		    Cr[WS(csr, 3)] = FMA(KP773010453, T20, T1L);
		    Ci[WS(csi, 3)] = FMA(KP773010453, T2y, T2x);
		    Cr[WS(csr, 11)] = FNMS(KP773010453, T24, T21);
		    Ci[WS(csi, 11)] = FMA(KP773010453, T2A, T2z);
		    Cr[WS(csr, 4)] = FMA(KP773010453, T24, T21);
		    Ci[WS(csi, 4)] = FMS(KP773010453, T2A, T2z);
	       }
	  }
     }
}

static const kr2c_desc desc = { 32, "r2cfII_32", { 46, 0, 128, 0 }, &GENUS };

void X(codelet_r2cfII_32) (planner *p) { X(kr2c_register) (p, r2cfII_32, &desc);
}

#else

/* Generated by: ../../../genfft/gen_r2cf.native -compact -variables 4 -pipeline-latency 4 -n 32 -name r2cfII_32 -dft-II -include rdft/scalar/r2cfII.h */

/*
 * This function contains 174 FP additions, 82 FP multiplications,
 * (or, 138 additions, 46 multiplications, 36 fused multiply/add),
 * 62 stack variables, 15 constants, and 64 memory accesses
 */
#include "rdft/scalar/r2cfII.h"

static void r2cfII_32(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP471396736, +0.471396736825997648556387625905254377657460319);
     DK(KP881921264, +0.881921264348355029712756863660388349508442621);
     DK(KP634393284, +0.634393284163645498215171613225493370675687095);
     DK(KP773010453, +0.773010453362736960810906609758469800971041293);
     DK(KP290284677, +0.290284677254462367636192375817395274691476278);
     DK(KP956940335, +0.956940335732208864935797886980269969482849206);
     DK(KP995184726, +0.995184726672196886244836953109479921575474869);
     DK(KP098017140, +0.098017140329560601994195563888641845861136673);
     DK(KP555570233, +0.555570233019602224742830813948532874374937191);
     DK(KP831469612, +0.831469612302545237078788377617905756738560812);
     DK(KP195090322, +0.195090322016128267848284868477022240927691618);
     DK(KP980785280, +0.980785280403230449126182236134239036973933731);
     DK(KP382683432, +0.382683432365089771728459984030398866761344562);
     DK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(128, rs), MAKE_VOLATILE_STRIDE(128, csr), MAKE_VOLATILE_STRIDE(128, csi)) {
	       E T5, T2D, T1z, T2q, Tc, T2C, T1C, T2n, Tm, T1k, T1J, T26, Tv, T1l, T1G;
	       E T27, T15, T1r, T1Y, T2e, T1c, T1s, T1V, T2d, TK, T1o, T1R, T2b, TR, T1p;
	       E T1O, T2a;
	       {
		    E T1, T2p, T4, T2o, T2, T3;
		    T1 = R0[0];
		    T2p = R0[WS(rs, 8)];
		    T2 = R0[WS(rs, 4)];
		    T3 = R0[WS(rs, 12)];
		    T4 = KP707106781 * (T2 - T3);
		    T2o = KP707106781 * (T2 + T3);
		    T5 = T1 + T4;
		    T2D = T2p - T2o;
		    T1z = T1 - T4;
		    T2q = T2o + T2p;
	       }
	       {
		    E T8, T1A, Tb, T1B;
		    {
			 E T6, T7, T9, Ta;
			 T6 = R0[WS(rs, 2)];
			 T7 = R0[WS(rs, 10)];
			 T8 = FNMS(KP382683432, T7, KP923879532 * T6);
			 T1A = FMA(KP382683432, T6, KP923879532 * T7);
			 T9 = R0[WS(rs, 6)];
			 Ta = R0[WS(rs, 14)];
			 Tb = FNMS(KP923879532, Ta, KP382683432 * T9);
			 T1B = FMA(KP923879532, T9, KP382683432 * Ta);
		    }
		    Tc = T8 + Tb;
		    T2C = Tb - T8;
		    T1C = T1A - T1B;
		    T2n = T1A + T1B;
	       }
	       {
		    E Te, Tk, Th, Tj, Tf, Tg;
		    Te = R0[WS(rs, 1)];
		    Tk = R0[WS(rs, 9)];
		    Tf = R0[WS(rs, 5)];
		    Tg = R0[WS(rs, 13)];
		    Th = KP707106781 * (Tf - Tg);
		    Tj = KP707106781 * (Tf + Tg);
		    {
			 E Ti, Tl, T1H, T1I;
			 Ti = Te + Th;
			 Tl = Tj + Tk;
			 Tm = FNMS(KP195090322, Tl, KP980785280 * Ti);
			 T1k = FMA(KP195090322, Ti, KP980785280 * Tl);
			 T1H = Tk - Tj;
			 T1I = Te - Th;
			 T1J = FNMS(KP555570233, T1I, KP831469612 * T1H);
			 T26 = FMA(KP831469612, T1I, KP555570233 * T1H);
		    }
	       }
	       {
		    E Tq, Tt, Tp, Ts, Tn, To;
		    Tq = R0[WS(rs, 15)];
		    Tt = R0[WS(rs, 7)];
		    Tn = R0[WS(rs, 3)];
		    To = R0[WS(rs, 11)];
		    Tp = KP707106781 * (Tn - To);
		    Ts = KP707106781 * (Tn + To);
		    {
			 E Tr, Tu, T1E, T1F;
			 Tr = Tp - Tq;
			 Tu = Ts + Tt;
			 Tv = FMA(KP980785280, Tr, KP195090322 * Tu);
			 T1l = FNMS(KP980785280, Tu, KP195090322 * Tr);
			 T1E = Tt - Ts;
			 T1F = Tp + Tq;
			 T1G = FNMS(KP555570233, T1F, KP831469612 * T1E);
			 T27 = FMA(KP831469612, T1F, KP555570233 * T1E);
		    }
	       }
	       {
		    E TW, T1a, TV, T19, T10, T16, T13, T17, TT, TU;
		    TW = R1[WS(rs, 15)];
		    T1a = R1[WS(rs, 7)];
		    TT = R1[WS(rs, 3)];
		    TU = R1[WS(rs, 11)];
		    TV = KP707106781 * (TT - TU);
		    T19 = KP707106781 * (TT + TU);
		    {
			 E TY, TZ, T11, T12;
			 TY = R1[WS(rs, 1)];
			 TZ = R1[WS(rs, 9)];
			 T10 = FNMS(KP382683432, TZ, KP923879532 * TY);
			 T16 = FMA(KP382683432, TY, KP923879532 * TZ);
			 T11 = R1[WS(rs, 5)];
			 T12 = R1[WS(rs, 13)];
			 T13 = FNMS(KP923879532, T12, KP382683432 * T11);
			 T17 = FMA(KP923879532, T11, KP382683432 * T12);
		    }
		    {
			 E TX, T14, T1W, T1X;
			 TX = TV - TW;
			 T14 = T10 + T13;
			 T15 = TX + T14;
			 T1r = TX - T14;
			 T1W = T13 - T10;
			 T1X = T1a - T19;
			 T1Y = T1W - T1X;
			 T2e = T1W + T1X;
		    }
		    {
			 E T18, T1b, T1T, T1U;
			 T18 = T16 + T17;
			 T1b = T19 + T1a;
			 T1c = T18 + T1b;
			 T1s = T1b - T18;
			 T1T = TV + TW;
			 T1U = T16 - T17;
			 T1V = T1T + T1U;
			 T2d = T1U - T1T;
		    }
	       }
	       {
		    E Ty, TP, TB, TO, TF, TL, TI, TM, Tz, TA;
		    Ty = R1[0];
		    TP = R1[WS(rs, 8)];
		    Tz = R1[WS(rs, 4)];
		    TA = R1[WS(rs, 12)];
		    TB = KP707106781 * (Tz - TA);
		    TO = KP707106781 * (Tz + TA);
		    {
			 E TD, TE, TG, TH;
			 TD = R1[WS(rs, 2)];
			 TE = R1[WS(rs, 10)];
			 TF = FNMS(KP382683432, TE, KP923879532 * TD);
			 TL = FMA(KP382683432, TD, KP923879532 * TE);
			 TG = R1[WS(rs, 6)];
			 TH = R1[WS(rs, 14)];
			 TI = FNMS(KP923879532, TH, KP382683432 * TG);
			 TM = FMA(KP923879532, TG, KP382683432 * TH);
		    }
		    {
			 E TC, TJ, T1P, T1Q;
			 TC = Ty + TB;
			 TJ = TF + TI;
			 TK = TC + TJ;
			 T1o = TC - TJ;
			 T1P = TI - TF;
			 T1Q = TP - TO;
			 T1R = T1P - T1Q;
			 T2b = T1P + T1Q;
		    }
		    {
			 E TN, TQ, T1M, T1N;
			 TN = TL + TM;
			 TQ = TO + TP;
			 TR = TN + TQ;
			 T1p = TQ - TN;
			 T1M = Ty - TB;
			 T1N = TL - TM;
			 T1O = T1M - T1N;
			 T2a = T1M + T1N;
		    }
	       }
	       {
		    E Tx, T1f, T2s, T2u, T1e, T2l, T1i, T2t;
		    {
			 E Td, Tw, T2m, T2r;
			 Td = T5 + Tc;
			 Tw = Tm + Tv;
			 Tx = Td - Tw;
			 T1f = Td + Tw;
			 T2m = T1l - T1k;
			 T2r = T2n + T2q;
			 T2s = T2m - T2r;
			 T2u = T2m + T2r;
		    }
		    {
			 E TS, T1d, T1g, T1h;
			 TS = FMA(KP098017140, TK, KP995184726 * TR);
			 T1d = FNMS(KP995184726, T1c, KP098017140 * T15);
			 T1e = TS + T1d;
			 T2l = T1d - TS;
			 T1g = FNMS(KP098017140, TR, KP995184726 * TK);
			 T1h = FMA(KP995184726, T15, KP098017140 * T1c);
			 T1i = T1g + T1h;
			 T2t = T1h - T1g;
		    }
		    Cr[WS(csr, 8)] = Tx - T1e;
		    Ci[WS(csi, 8)] = T2t - T2u;
		    Cr[WS(csr, 7)] = Tx + T1e;
		    Ci[WS(csi, 7)] = T2t + T2u;
		    Cr[WS(csr, 15)] = T1f - T1i;
		    Ci[WS(csi, 15)] = T2l - T2s;
		    Cr[0] = T1f + T1i;
		    Ci[0] = T2l + T2s;
	       }
	       {
		    E T29, T2h, T2M, T2O, T2g, T2J, T2k, T2N;
		    {
			 E T25, T28, T2K, T2L;
			 T25 = T1z + T1C;
			 T28 = T26 - T27;
			 T29 = T25 + T28;
			 T2h = T25 - T28;
			 T2K = T1J + T1G;
			 T2L = T2C + T2D;
			 T2M = T2K - T2L;
			 T2O = T2K + T2L;
		    }
		    {
			 E T2c, T2f, T2i, T2j;
			 T2c = FMA(KP956940335, T2a, KP290284677 * T2b);
			 T2f = FNMS(KP290284677, T2e, KP956940335 * T2d);
			 T2g = T2c + T2f;
			 T2J = T2f - T2c;
			 T2i = FMA(KP290284677, T2d, KP956940335 * T2e);
			 T2j = FNMS(KP290284677, T2a, KP956940335 * T2b);
			 T2k = T2i - T2j;
			 T2N = T2j + T2i;
		    }
		    Cr[WS(csr, 14)] = T29 - T2g;
		    Ci[WS(csi, 14)] = T2N - T2O;
		    Cr[WS(csr, 1)] = T29 + T2g;
		    Ci[WS(csi, 1)] = T2N + T2O;
		    Cr[WS(csr, 9)] = T2h - T2k;
		    Ci[WS(csi, 9)] = T2J - T2M;
		    Cr[WS(csr, 6)] = T2h + T2k;
		    Ci[WS(csi, 6)] = T2J + T2M;
	       }
	       {
		    E T1n, T1v, T2y, T2A, T1u, T2v, T1y, T2z;
		    {
			 E T1j, T1m, T2w, T2x;
			 T1j = T5 - Tc;
			 T1m = T1k + T1l;
			 T1n = T1j + T1m;
			 T1v = T1j - T1m;
			 T2w = Tv - Tm;
			 T2x = T2q - T2n;
			 T2y = T2w - T2x;
			 T2A = T2w + T2x;
		    }
		    {
			 E T1q, T1t, T1w, T1x;
			 T1q = FMA(KP773010453, T1o, KP634393284 * T1p);
			 T1t = FNMS(KP634393284, T1s, KP773010453 * T1r);
			 T1u = T1q + T1t;
			 T2v = T1t - T1q;
			 T1w = FMA(KP634393284, T1r, KP773010453 * T1s);
			 T1x = FNMS(KP634393284, T1o, KP773010453 * T1p);
			 T1y = T1w - T1x;
			 T2z = T1x + T1w;
		    }
		    Cr[WS(csr, 12)] = T1n - T1u;
		    Ci[WS(csi, 12)] = T2z - T2A;
		    Cr[WS(csr, 3)] = T1n + T1u;
		    Ci[WS(csi, 3)] = T2z + T2A;
		    Cr[WS(csr, 11)] = T1v - T1y;
		    Ci[WS(csi, 11)] = T2v - T2y;
		    Cr[WS(csr, 4)] = T1v + T1y;
		    Ci[WS(csi, 4)] = T2v + T2y;
	       }
	       {
		    E T1L, T21, T2G, T2I, T20, T2H, T24, T2B;
		    {
			 E T1D, T1K, T2E, T2F;
			 T1D = T1z - T1C;
			 T1K = T1G - T1J;
			 T1L = T1D + T1K;
			 T21 = T1D - T1K;
			 T2E = T2C - T2D;
			 T2F = T26 + T27;
			 T2G = T2E - T2F;
			 T2I = T2F + T2E;
		    }
		    {
			 E T1S, T1Z, T22, T23;
			 T1S = FMA(KP881921264, T1O, KP471396736 * T1R);
			 T1Z = FMA(KP881921264, T1V, KP471396736 * T1Y);
			 T20 = T1S - T1Z;
			 T2H = T1S + T1Z;
			 T22 = FNMS(KP471396736, T1V, KP881921264 * T1Y);
			 T23 = FNMS(KP471396736, T1O, KP881921264 * T1R);
			 T24 = T22 - T23;
			 T2B = T23 + T22;
		    }
		    Cr[WS(csr, 13)] = T1L - T20;
		    Ci[WS(csi, 13)] = T2B - T2G;
		    Cr[WS(csr, 2)] = T1L + T20;
		    Ci[WS(csi, 2)] = T2B + T2G;
		    Cr[WS(csr, 10)] = T21 - T24;
		    Ci[WS(csi, 10)] = T2I - T2H;
		    Cr[WS(csr, 5)] = T21 + T24;
		    Ci[WS(csi, 5)] = -(T2H + T2I);
	       }
	  }
     }
}

static const kr2c_desc desc = { 32, "r2cfII_32", { 138, 46, 36, 0 }, &GENUS };

void X(codelet_r2cfII_32) (planner *p) { X(kr2c_register) (p, r2cfII_32, &desc);
}

#endif
