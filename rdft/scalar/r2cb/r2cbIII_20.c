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
/* Generated on Tue Nov 24 01:12:13 JST 2020 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_r2cb.native -fma -compact -variables 4 -pipeline-latency 4 -sign 1 -n 20 -name r2cbIII_20 -dft-III -include rdft/scalar/r2cbIII.h */

/*
 * This function contains 94 FP additions, 56 FP multiplications,
 * (or, 58 additions, 20 multiplications, 36 fused multiply/add),
 * 43 stack variables, 6 constants, and 40 memory accesses
 */
#include "rdft/scalar/r2cbIII.h"

static void r2cbIII_20(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP1_414213562, +1.414213562373095048801688724209698078569671875);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(80, rs), MAKE_VOLATILE_STRIDE(80, csr), MAKE_VOLATILE_STRIDE(80, csi)) {
	       E T1, Tk, T1l, TZ, T8, Tj, TQ, Ts, TV, TI, TT, TU, Ta, Tv, T1i;
	       E T1a, Th, Tu, T11, TD, T16, TL, T14, T15;
	       {
		    E T7, TY, T4, TX;
		    T1 = Cr[WS(csr, 2)];
		    {
			 E T5, T6, T2, T3;
			 T5 = Cr[WS(csr, 9)];
			 T6 = Cr[WS(csr, 5)];
			 T7 = T5 + T6;
			 TY = T5 - T6;
			 T2 = Cr[WS(csr, 6)];
			 T3 = Cr[WS(csr, 1)];
			 T4 = T2 + T3;
			 TX = T2 - T3;
		    }
		    Tk = T4 - T7;
		    T1l = FNMS(KP618033988, TX, TY);
		    TZ = FMA(KP618033988, TY, TX);
		    T8 = T4 + T7;
		    Tj = FNMS(KP250000000, T8, T1);
	       }
	       {
		    E Tr, TS, To, TR;
		    TQ = Ci[WS(csi, 2)];
		    {
			 E Tp, Tq, Tm, Tn;
			 Tp = Ci[WS(csi, 5)];
			 Tq = Ci[WS(csi, 9)];
			 Tr = Tp - Tq;
			 TS = Tp + Tq;
			 Tm = Ci[WS(csi, 6)];
			 Tn = Ci[WS(csi, 1)];
			 To = Tm + Tn;
			 TR = Tm - Tn;
		    }
		    Ts = FMA(KP618033988, Tr, To);
		    TV = TR + TS;
		    TI = FNMS(KP618033988, To, Tr);
		    TT = TR - TS;
		    TU = FNMS(KP250000000, TT, TQ);
	       }
	       {
		    E Tg, T19, Td, T18;
		    Ta = Cr[WS(csr, 7)];
		    {
			 E Te, Tf, Tb, Tc;
			 Te = Cr[0];
			 Tf = Cr[WS(csr, 4)];
			 Tg = Te + Tf;
			 T19 = Te - Tf;
			 Tb = Cr[WS(csr, 3)];
			 Tc = Cr[WS(csr, 8)];
			 Td = Tb + Tc;
			 T18 = Tb - Tc;
		    }
		    Tv = Td - Tg;
		    T1i = FNMS(KP618033988, T18, T19);
		    T1a = FMA(KP618033988, T19, T18);
		    Th = Td + Tg;
		    Tu = FNMS(KP250000000, Th, Ta);
	       }
	       {
		    E TC, T13, Tz, T12;
		    T11 = Ci[WS(csi, 7)];
		    {
			 E TA, TB, Tx, Ty;
			 TA = Ci[WS(csi, 4)];
			 TB = Ci[0];
			 TC = TA - TB;
			 T13 = TB + TA;
			 Tx = Ci[WS(csi, 3)];
			 Ty = Ci[WS(csi, 8)];
			 Tz = Tx + Ty;
			 T12 = Tx - Ty;
		    }
		    TD = FMA(KP618033988, TC, Tz);
		    T16 = T12 + T13;
		    TL = FNMS(KP618033988, Tz, TC);
		    T14 = T12 - T13;
		    T15 = FNMS(KP250000000, T14, T11);
	       }
	       {
		    E T9, Ti, T1w, T1t, T1u, T1v;
		    T9 = T1 + T8;
		    Ti = Ta + Th;
		    T1w = T9 - Ti;
		    T1t = TT + TQ;
		    T1u = T14 + T11;
		    T1v = T1t + T1u;
		    R0[0] = KP2_000000000 * (T9 + Ti);
		    R0[WS(rs, 5)] = KP2_000000000 * (T1u - T1t);
		    R1[WS(rs, 2)] = KP1_414213562 * (T1v - T1w);
		    R1[WS(rs, 7)] = KP1_414213562 * (T1w + T1v);
	       }
	       {
		    E TJ, TN, T1m, T1q, TM, TO, T1j, T1r;
		    {
			 E TH, T1k, TK, T1h;
			 TH = FNMS(KP559016994, Tk, Tj);
			 TJ = FNMS(KP951056516, TI, TH);
			 TN = FMA(KP951056516, TI, TH);
			 T1k = FNMS(KP559016994, TV, TU);
			 T1m = FNMS(KP951056516, T1l, T1k);
			 T1q = FMA(KP951056516, T1l, T1k);
			 TK = FNMS(KP559016994, Tv, Tu);
			 TM = FMA(KP951056516, TL, TK);
			 TO = FNMS(KP951056516, TL, TK);
			 T1h = FNMS(KP559016994, T16, T15);
			 T1j = FMA(KP951056516, T1i, T1h);
			 T1r = FNMS(KP951056516, T1i, T1h);
		    }
		    R0[WS(rs, 4)] = KP2_000000000 * (TJ + TM);
		    R0[WS(rs, 6)] = -(KP2_000000000 * (TN + TO));
		    R0[WS(rs, 9)] = KP2_000000000 * (T1r - T1q);
		    R0[WS(rs, 1)] = KP2_000000000 * (T1j - T1m);
		    {
			 E T1p, T1s, T1n, T1o;
			 T1p = TM - TJ;
			 T1s = T1q + T1r;
			 R1[WS(rs, 1)] = KP1_414213562 * (T1p - T1s);
			 R1[WS(rs, 6)] = KP1_414213562 * (T1p + T1s);
			 T1n = TN - TO;
			 T1o = T1m + T1j;
			 R1[WS(rs, 8)] = KP1_414213562 * (T1n - T1o);
			 R1[WS(rs, 3)] = KP1_414213562 * (T1n + T1o);
		    }
	       }
	       {
		    E Tt, TF, T1b, T1f, TE, TG, T10, T1e;
		    {
			 E Tl, T17, Tw, TW;
			 Tl = FMA(KP559016994, Tk, Tj);
			 Tt = FNMS(KP951056516, Ts, Tl);
			 TF = FMA(KP951056516, Ts, Tl);
			 T17 = FMA(KP559016994, T16, T15);
			 T1b = FNMS(KP951056516, T1a, T17);
			 T1f = FMA(KP951056516, T1a, T17);
			 Tw = FMA(KP559016994, Tv, Tu);
			 TE = FMA(KP951056516, TD, Tw);
			 TG = FNMS(KP951056516, TD, Tw);
			 TW = FMA(KP559016994, TV, TU);
			 T10 = FMA(KP951056516, TZ, TW);
			 T1e = FNMS(KP951056516, TZ, TW);
		    }
		    R0[WS(rs, 8)] = KP2_000000000 * (Tt + TE);
		    R0[WS(rs, 2)] = -(KP2_000000000 * (TF + TG));
		    R0[WS(rs, 7)] = KP2_000000000 * (T1e - T1f);
		    R0[WS(rs, 3)] = KP2_000000000 * (T10 - T1b);
		    {
			 E T1d, T1g, TP, T1c;
			 T1d = TF - TG;
			 T1g = T1e + T1f;
			 R1[WS(rs, 4)] = KP1_414213562 * (T1d - T1g);
			 R1[WS(rs, 9)] = -(KP1_414213562 * (T1d + T1g));
			 TP = Tt - TE;
			 T1c = T10 + T1b;
			 R1[0] = KP1_414213562 * (TP - T1c);
			 R1[WS(rs, 5)] = -(KP1_414213562 * (TP + T1c));
		    }
	       }
	  }
     }
}

static const kr2c_desc desc = { 20, "r2cbIII_20", { 58, 20, 36, 0 }, &GENUS };

void X(codelet_r2cbIII_20) (planner *p) { X(kr2c_register) (p, r2cbIII_20, &desc);
}

#else

/* Generated by: ../../../genfft/gen_r2cb.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 20 -name r2cbIII_20 -dft-III -include rdft/scalar/r2cbIII.h */

/*
 * This function contains 94 FP additions, 44 FP multiplications,
 * (or, 82 additions, 32 multiplications, 12 fused multiply/add),
 * 43 stack variables, 6 constants, and 40 memory accesses
 */
#include "rdft/scalar/r2cbIII.h"

static void r2cbIII_20(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP1_414213562, +1.414213562373095048801688724209698078569671875);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(80, rs), MAKE_VOLATILE_STRIDE(80, csr), MAKE_VOLATILE_STRIDE(80, csi)) {
	       E T1, Tj, T1k, T13, T8, Tk, T17, Ts, T16, TI, T18, T19, Ta, Tu, T1i;
	       E TS, Th, Tv, TX, TD, TV, TL, TW, TY;
	       {
		    E T7, T12, T4, T11;
		    T1 = Cr[WS(csr, 2)];
		    {
			 E T5, T6, T2, T3;
			 T5 = Cr[WS(csr, 9)];
			 T6 = Cr[WS(csr, 5)];
			 T7 = T5 + T6;
			 T12 = T5 - T6;
			 T2 = Cr[WS(csr, 6)];
			 T3 = Cr[WS(csr, 1)];
			 T4 = T2 + T3;
			 T11 = T2 - T3;
		    }
		    Tj = KP559016994 * (T4 - T7);
		    T1k = FNMS(KP951056516, T12, KP587785252 * T11);
		    T13 = FMA(KP951056516, T11, KP587785252 * T12);
		    T8 = T4 + T7;
		    Tk = FNMS(KP250000000, T8, T1);
	       }
	       {
		    E Tr, T15, To, T14;
		    T17 = Ci[WS(csi, 2)];
		    {
			 E Tp, Tq, Tm, Tn;
			 Tp = Ci[WS(csi, 5)];
			 Tq = Ci[WS(csi, 9)];
			 Tr = Tp - Tq;
			 T15 = Tp + Tq;
			 Tm = Ci[WS(csi, 6)];
			 Tn = Ci[WS(csi, 1)];
			 To = Tm + Tn;
			 T14 = Tm - Tn;
		    }
		    Ts = FMA(KP951056516, To, KP587785252 * Tr);
		    T16 = KP559016994 * (T14 + T15);
		    TI = FNMS(KP951056516, Tr, KP587785252 * To);
		    T18 = T14 - T15;
		    T19 = FNMS(KP250000000, T18, T17);
	       }
	       {
		    E Tg, TR, Td, TQ;
		    Ta = Cr[WS(csr, 7)];
		    {
			 E Te, Tf, Tb, Tc;
			 Te = Cr[0];
			 Tf = Cr[WS(csr, 4)];
			 Tg = Te + Tf;
			 TR = Te - Tf;
			 Tb = Cr[WS(csr, 3)];
			 Tc = Cr[WS(csr, 8)];
			 Td = Tb + Tc;
			 TQ = Tb - Tc;
		    }
		    Tu = KP559016994 * (Td - Tg);
		    T1i = FNMS(KP951056516, TR, KP587785252 * TQ);
		    TS = FMA(KP951056516, TQ, KP587785252 * TR);
		    Th = Td + Tg;
		    Tv = FNMS(KP250000000, Th, Ta);
	       }
	       {
		    E TC, TU, Tz, TT;
		    TX = Ci[WS(csi, 7)];
		    {
			 E TA, TB, Tx, Ty;
			 TA = Ci[WS(csi, 4)];
			 TB = Ci[0];
			 TC = TA - TB;
			 TU = TB + TA;
			 Tx = Ci[WS(csi, 3)];
			 Ty = Ci[WS(csi, 8)];
			 Tz = Tx + Ty;
			 TT = Ty - Tx;
		    }
		    TD = FMA(KP951056516, Tz, KP587785252 * TC);
		    TV = KP559016994 * (TT - TU);
		    TL = FNMS(KP587785252, Tz, KP951056516 * TC);
		    TW = TT + TU;
		    TY = FMA(KP250000000, TW, TX);
	       }
	       {
		    E T9, Ti, T1w, T1t, T1u, T1v;
		    T9 = T1 + T8;
		    Ti = Ta + Th;
		    T1w = T9 - Ti;
		    T1t = T18 + T17;
		    T1u = TX - TW;
		    T1v = T1t + T1u;
		    R0[0] = KP2_000000000 * (T9 + Ti);
		    R0[WS(rs, 5)] = KP2_000000000 * (T1u - T1t);
		    R1[WS(rs, 2)] = KP1_414213562 * (T1v - T1w);
		    R1[WS(rs, 7)] = KP1_414213562 * (T1w + T1v);
	       }
	       {
		    E TJ, TO, T1m, T1q, TM, TN, T1j, T1r;
		    {
			 E TH, T1l, TK, T1h;
			 TH = Tk - Tj;
			 TJ = TH + TI;
			 TO = TH - TI;
			 T1l = T19 - T16;
			 T1m = T1k + T1l;
			 T1q = T1l - T1k;
			 TK = Tv - Tu;
			 TM = TK + TL;
			 TN = TL - TK;
			 T1h = TV + TY;
			 T1j = T1h - T1i;
			 T1r = T1i + T1h;
		    }
		    R0[WS(rs, 4)] = KP2_000000000 * (TJ + TM);
		    R0[WS(rs, 6)] = KP2_000000000 * (TN - TO);
		    R0[WS(rs, 9)] = KP2_000000000 * (T1r - T1q);
		    R0[WS(rs, 1)] = KP2_000000000 * (T1j - T1m);
		    {
			 E T1p, T1s, T1n, T1o;
			 T1p = TM - TJ;
			 T1s = T1q + T1r;
			 R1[WS(rs, 1)] = KP1_414213562 * (T1p - T1s);
			 R1[WS(rs, 6)] = KP1_414213562 * (T1p + T1s);
			 T1n = TO + TN;
			 T1o = T1m + T1j;
			 R1[WS(rs, 8)] = KP1_414213562 * (T1n - T1o);
			 R1[WS(rs, 3)] = KP1_414213562 * (T1n + T1o);
		    }
	       }
	       {
		    E Tt, TG, T1b, T1f, TE, TF, T10, T1e;
		    {
			 E Tl, T1a, Tw, TZ;
			 Tl = Tj + Tk;
			 Tt = Tl - Ts;
			 TG = Tl + Ts;
			 T1a = T16 + T19;
			 T1b = T13 + T1a;
			 T1f = T1a - T13;
			 Tw = Tu + Tv;
			 TE = Tw + TD;
			 TF = TD - Tw;
			 TZ = TV - TY;
			 T10 = TS + TZ;
			 T1e = TZ - TS;
		    }
		    R0[WS(rs, 8)] = KP2_000000000 * (Tt + TE);
		    R0[WS(rs, 2)] = KP2_000000000 * (TF - TG);
		    R0[WS(rs, 7)] = KP2_000000000 * (T1f + T1e);
		    R0[WS(rs, 3)] = KP2_000000000 * (T1b + T10);
		    {
			 E T1d, T1g, TP, T1c;
			 T1d = TG + TF;
			 T1g = T1e - T1f;
			 R1[WS(rs, 4)] = KP1_414213562 * (T1d + T1g);
			 R1[WS(rs, 9)] = KP1_414213562 * (T1g - T1d);
			 TP = Tt - TE;
			 T1c = T10 - T1b;
			 R1[0] = KP1_414213562 * (TP + T1c);
			 R1[WS(rs, 5)] = KP1_414213562 * (T1c - TP);
		    }
	       }
	  }
     }
}

static const kr2c_desc desc = { 20, "r2cbIII_20", { 82, 32, 12, 0 }, &GENUS };

void X(codelet_r2cbIII_20) (planner *p) { X(kr2c_register) (p, r2cbIII_20, &desc);
}

#endif
