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
/* Generated on Tue Nov 24 01:07:47 JST 2020 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -simd -compact -variables 4 -pipeline-latency 8 -n 20 -name t1fv_20 -include dft/simd/t1f.h */

/*
 * This function contains 123 FP additions, 88 FP multiplications,
 * (or, 77 additions, 42 multiplications, 46 fused multiply/add),
 * 54 stack variables, 4 constants, and 40 memory accesses
 */
#include "dft/simd/t1f.h"

static void t1fv_20(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     VENTER();
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 38)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 38), MAKE_VOLATILE_STRIDE(20, rs)) {
	       V T4, Tx, T1m, T1K, TZ, T16, T17, T10, Tf, Tq, Tr, T1O, T1P, T1Q, T1w;
	       V T1z, T1A, TI, TT, TU, T1L, T1M, T1N, T1p, T1s, T1t, Ts, TV;
	       {
		    V T1, Tw, T3, Tu, Tv, T2, Tt, T1k, T1l;
		    T1 = LD(&(x[0]), ms, &(x[0]));
		    Tv = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
		    Tw = BYTWJ(&(W[TWVL * 28]), Tv);
		    T2 = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
		    T3 = BYTWJ(&(W[TWVL * 18]), T2);
		    Tt = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
		    Tu = BYTWJ(&(W[TWVL * 8]), Tt);
		    T4 = VSUB(T1, T3);
		    Tx = VSUB(Tu, Tw);
		    T1k = VADD(T1, T3);
		    T1l = VADD(Tu, Tw);
		    T1m = VSUB(T1k, T1l);
		    T1K = VADD(T1k, T1l);
	       }
	       {
		    V T9, T1n, TN, T1v, TS, T1y, Te, T1q, Tk, T1u, TC, T1o, TH, T1r, Tp;
		    V T1x;
		    {
			 V T6, T8, T5, T7;
			 T5 = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			 T6 = BYTWJ(&(W[TWVL * 6]), T5);
			 T7 = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			 T8 = BYTWJ(&(W[TWVL * 26]), T7);
			 T9 = VSUB(T6, T8);
			 T1n = VADD(T6, T8);
		    }
		    {
			 V TK, TM, TJ, TL;
			 TJ = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
			 TK = BYTWJ(&(W[TWVL * 24]), TJ);
			 TL = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 TM = BYTWJ(&(W[TWVL * 4]), TL);
			 TN = VSUB(TK, TM);
			 T1v = VADD(TK, TM);
		    }
		    {
			 V TP, TR, TO, TQ;
			 TO = LD(&(x[WS(rs, 17)]), ms, &(x[WS(rs, 1)]));
			 TP = BYTWJ(&(W[TWVL * 32]), TO);
			 TQ = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 TR = BYTWJ(&(W[TWVL * 12]), TQ);
			 TS = VSUB(TP, TR);
			 T1y = VADD(TP, TR);
		    }
		    {
			 V Tb, Td, Ta, Tc;
			 Ta = LD(&(x[WS(rs, 16)]), ms, &(x[0]));
			 Tb = BYTWJ(&(W[TWVL * 30]), Ta);
			 Tc = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Td = BYTWJ(&(W[TWVL * 10]), Tc);
			 Te = VSUB(Tb, Td);
			 T1q = VADD(Tb, Td);
		    }
		    {
			 V Th, Tj, Tg, Ti;
			 Tg = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			 Th = BYTWJ(&(W[TWVL * 14]), Tg);
			 Ti = LD(&(x[WS(rs, 18)]), ms, &(x[0]));
			 Tj = BYTWJ(&(W[TWVL * 34]), Ti);
			 Tk = VSUB(Th, Tj);
			 T1u = VADD(Th, Tj);
		    }
		    {
			 V Tz, TB, Ty, TA;
			 Ty = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			 Tz = BYTWJ(&(W[TWVL * 16]), Ty);
			 TA = LD(&(x[WS(rs, 19)]), ms, &(x[WS(rs, 1)]));
			 TB = BYTWJ(&(W[TWVL * 36]), TA);
			 TC = VSUB(Tz, TB);
			 T1o = VADD(Tz, TB);
		    }
		    {
			 V TE, TG, TD, TF;
			 TD = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 TE = BYTWJ(&(W[0]), TD);
			 TF = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
			 TG = BYTWJ(&(W[TWVL * 20]), TF);
			 TH = VSUB(TE, TG);
			 T1r = VADD(TE, TG);
		    }
		    {
			 V Tm, To, Tl, Tn;
			 Tl = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
			 Tm = BYTWJ(&(W[TWVL * 22]), Tl);
			 Tn = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 To = BYTWJ(&(W[TWVL * 2]), Tn);
			 Tp = VSUB(Tm, To);
			 T1x = VADD(Tm, To);
		    }
		    TZ = VSUB(TH, TC);
		    T16 = VSUB(T9, Te);
		    T17 = VSUB(Tk, Tp);
		    T10 = VSUB(TS, TN);
		    Tf = VADD(T9, Te);
		    Tq = VADD(Tk, Tp);
		    Tr = VADD(Tf, Tq);
		    T1O = VADD(T1u, T1v);
		    T1P = VADD(T1x, T1y);
		    T1Q = VADD(T1O, T1P);
		    T1w = VSUB(T1u, T1v);
		    T1z = VSUB(T1x, T1y);
		    T1A = VADD(T1w, T1z);
		    TI = VADD(TC, TH);
		    TT = VADD(TN, TS);
		    TU = VADD(TI, TT);
		    T1L = VADD(T1n, T1o);
		    T1M = VADD(T1q, T1r);
		    T1N = VADD(T1L, T1M);
		    T1p = VSUB(T1n, T1o);
		    T1s = VSUB(T1q, T1r);
		    T1t = VADD(T1p, T1s);
	       }
	       Ts = VADD(T4, Tr);
	       TV = VADD(Tx, TU);
	       ST(&(x[WS(rs, 5)]), VFNMSI(TV, Ts), ms, &(x[WS(rs, 1)]));
	       ST(&(x[WS(rs, 15)]), VFMAI(TV, Ts), ms, &(x[WS(rs, 1)]));
	       {
		    V T1T, T1R, T1S, T1X, T1Z, T1V, T1W, T1Y, T1U;
		    T1T = VSUB(T1N, T1Q);
		    T1R = VADD(T1N, T1Q);
		    T1S = VFNMS(LDK(KP250000000), T1R, T1K);
		    T1V = VSUB(T1L, T1M);
		    T1W = VSUB(T1O, T1P);
		    T1X = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T1W, T1V));
		    T1Z = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T1V, T1W));
		    ST(&(x[0]), VADD(T1K, T1R), ms, &(x[0]));
		    T1Y = VFNMS(LDK(KP559016994), T1T, T1S);
		    ST(&(x[WS(rs, 8)]), VFNMSI(T1Z, T1Y), ms, &(x[0]));
		    ST(&(x[WS(rs, 12)]), VFMAI(T1Z, T1Y), ms, &(x[0]));
		    T1U = VFMA(LDK(KP559016994), T1T, T1S);
		    ST(&(x[WS(rs, 4)]), VFMAI(T1X, T1U), ms, &(x[0]));
		    ST(&(x[WS(rs, 16)]), VFNMSI(T1X, T1U), ms, &(x[0]));
	       }
	       {
		    V T1D, T1B, T1C, T1H, T1J, T1F, T1G, T1I, T1E;
		    T1D = VSUB(T1t, T1A);
		    T1B = VADD(T1t, T1A);
		    T1C = VFNMS(LDK(KP250000000), T1B, T1m);
		    T1F = VSUB(T1w, T1z);
		    T1G = VSUB(T1p, T1s);
		    T1H = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T1G, T1F));
		    T1J = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T1F, T1G));
		    ST(&(x[WS(rs, 10)]), VADD(T1m, T1B), ms, &(x[0]));
		    T1I = VFMA(LDK(KP559016994), T1D, T1C);
		    ST(&(x[WS(rs, 6)]), VFNMSI(T1J, T1I), ms, &(x[0]));
		    ST(&(x[WS(rs, 14)]), VFMAI(T1J, T1I), ms, &(x[0]));
		    T1E = VFNMS(LDK(KP559016994), T1D, T1C);
		    ST(&(x[WS(rs, 2)]), VFMAI(T1H, T1E), ms, &(x[0]));
		    ST(&(x[WS(rs, 18)]), VFNMSI(T1H, T1E), ms, &(x[0]));
	       }
	       {
		    V T11, T18, T1g, T1d, T15, T1f, TY, T1c;
		    T11 = VFMA(LDK(KP618033988), T10, TZ);
		    T18 = VFMA(LDK(KP618033988), T17, T16);
		    T1g = VFNMS(LDK(KP618033988), T16, T17);
		    T1d = VFNMS(LDK(KP618033988), TZ, T10);
		    {
			 V T13, T14, TW, TX;
			 T13 = VFNMS(LDK(KP250000000), TU, Tx);
			 T14 = VSUB(TT, TI);
			 T15 = VFNMS(LDK(KP559016994), T14, T13);
			 T1f = VFMA(LDK(KP559016994), T14, T13);
			 TW = VFNMS(LDK(KP250000000), Tr, T4);
			 TX = VSUB(Tf, Tq);
			 TY = VFMA(LDK(KP559016994), TX, TW);
			 T1c = VFNMS(LDK(KP559016994), TX, TW);
		    }
		    {
			 V T12, T19, T1i, T1j;
			 T12 = VFMA(LDK(KP951056516), T11, TY);
			 T19 = VFMA(LDK(KP951056516), T18, T15);
			 ST(&(x[WS(rs, 1)]), VFNMSI(T19, T12), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 19)]), VFMAI(T19, T12), ms, &(x[WS(rs, 1)]));
			 T1i = VFMA(LDK(KP951056516), T1d, T1c);
			 T1j = VFMA(LDK(KP951056516), T1g, T1f);
			 ST(&(x[WS(rs, 13)]), VFNMSI(T1j, T1i), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 7)]), VFMAI(T1j, T1i), ms, &(x[WS(rs, 1)]));
		    }
		    {
			 V T1a, T1b, T1e, T1h;
			 T1a = VFNMS(LDK(KP951056516), T11, TY);
			 T1b = VFNMS(LDK(KP951056516), T18, T15);
			 ST(&(x[WS(rs, 9)]), VFNMSI(T1b, T1a), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 11)]), VFMAI(T1b, T1a), ms, &(x[WS(rs, 1)]));
			 T1e = VFNMS(LDK(KP951056516), T1d, T1c);
			 T1h = VFNMS(LDK(KP951056516), T1g, T1f);
			 ST(&(x[WS(rs, 17)]), VFNMSI(T1h, T1e), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 3)]), VFMAI(T1h, T1e), ms, &(x[WS(rs, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     VTW(0, 9),
     VTW(0, 10),
     VTW(0, 11),
     VTW(0, 12),
     VTW(0, 13),
     VTW(0, 14),
     VTW(0, 15),
     VTW(0, 16),
     VTW(0, 17),
     VTW(0, 18),
     VTW(0, 19),
     { TW_NEXT, VL, 0 }
};

static const ct_desc desc = { 20, XSIMD_STRING("t1fv_20"), twinstr, &GENUS, { 77, 42, 46, 0 }, 0, 0, 0 };

void XSIMD(codelet_t1fv_20) (planner *p) {
     X(kdft_dit_register) (p, t1fv_20, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 20 -name t1fv_20 -include dft/simd/t1f.h */

/*
 * This function contains 123 FP additions, 62 FP multiplications,
 * (or, 111 additions, 50 multiplications, 12 fused multiply/add),
 * 54 stack variables, 4 constants, and 40 memory accesses
 */
#include "dft/simd/t1f.h"

static void t1fv_20(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     VENTER();
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 38)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 38), MAKE_VOLATILE_STRIDE(20, rs)) {
	       V T4, Tx, T1B, T1U, TZ, T16, T17, T10, Tf, Tq, Tr, T1N, T1O, T1S, T1t;
	       V T1w, T1C, TI, TT, TU, T1K, T1L, T1R, T1m, T1p, T1D, Ts, TV;
	       {
		    V T1, Tw, T3, Tu, Tv, T2, Tt, T1z, T1A;
		    T1 = LD(&(x[0]), ms, &(x[0]));
		    Tv = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
		    Tw = BYTWJ(&(W[TWVL * 28]), Tv);
		    T2 = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
		    T3 = BYTWJ(&(W[TWVL * 18]), T2);
		    Tt = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
		    Tu = BYTWJ(&(W[TWVL * 8]), Tt);
		    T4 = VSUB(T1, T3);
		    Tx = VSUB(Tu, Tw);
		    T1z = VADD(T1, T3);
		    T1A = VADD(Tu, Tw);
		    T1B = VSUB(T1z, T1A);
		    T1U = VADD(T1z, T1A);
	       }
	       {
		    V T9, T1r, TN, T1l, TS, T1o, Te, T1u, Tk, T1k, TC, T1s, TH, T1v, Tp;
		    V T1n;
		    {
			 V T6, T8, T5, T7;
			 T5 = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			 T6 = BYTWJ(&(W[TWVL * 6]), T5);
			 T7 = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			 T8 = BYTWJ(&(W[TWVL * 26]), T7);
			 T9 = VSUB(T6, T8);
			 T1r = VADD(T6, T8);
		    }
		    {
			 V TK, TM, TJ, TL;
			 TJ = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
			 TK = BYTWJ(&(W[TWVL * 24]), TJ);
			 TL = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 TM = BYTWJ(&(W[TWVL * 4]), TL);
			 TN = VSUB(TK, TM);
			 T1l = VADD(TK, TM);
		    }
		    {
			 V TP, TR, TO, TQ;
			 TO = LD(&(x[WS(rs, 17)]), ms, &(x[WS(rs, 1)]));
			 TP = BYTWJ(&(W[TWVL * 32]), TO);
			 TQ = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 TR = BYTWJ(&(W[TWVL * 12]), TQ);
			 TS = VSUB(TP, TR);
			 T1o = VADD(TP, TR);
		    }
		    {
			 V Tb, Td, Ta, Tc;
			 Ta = LD(&(x[WS(rs, 16)]), ms, &(x[0]));
			 Tb = BYTWJ(&(W[TWVL * 30]), Ta);
			 Tc = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Td = BYTWJ(&(W[TWVL * 10]), Tc);
			 Te = VSUB(Tb, Td);
			 T1u = VADD(Tb, Td);
		    }
		    {
			 V Th, Tj, Tg, Ti;
			 Tg = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			 Th = BYTWJ(&(W[TWVL * 14]), Tg);
			 Ti = LD(&(x[WS(rs, 18)]), ms, &(x[0]));
			 Tj = BYTWJ(&(W[TWVL * 34]), Ti);
			 Tk = VSUB(Th, Tj);
			 T1k = VADD(Th, Tj);
		    }
		    {
			 V Tz, TB, Ty, TA;
			 Ty = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			 Tz = BYTWJ(&(W[TWVL * 16]), Ty);
			 TA = LD(&(x[WS(rs, 19)]), ms, &(x[WS(rs, 1)]));
			 TB = BYTWJ(&(W[TWVL * 36]), TA);
			 TC = VSUB(Tz, TB);
			 T1s = VADD(Tz, TB);
		    }
		    {
			 V TE, TG, TD, TF;
			 TD = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 TE = BYTWJ(&(W[0]), TD);
			 TF = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
			 TG = BYTWJ(&(W[TWVL * 20]), TF);
			 TH = VSUB(TE, TG);
			 T1v = VADD(TE, TG);
		    }
		    {
			 V Tm, To, Tl, Tn;
			 Tl = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
			 Tm = BYTWJ(&(W[TWVL * 22]), Tl);
			 Tn = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 To = BYTWJ(&(W[TWVL * 2]), Tn);
			 Tp = VSUB(Tm, To);
			 T1n = VADD(Tm, To);
		    }
		    TZ = VSUB(TH, TC);
		    T16 = VSUB(T9, Te);
		    T17 = VSUB(Tk, Tp);
		    T10 = VSUB(TS, TN);
		    Tf = VADD(T9, Te);
		    Tq = VADD(Tk, Tp);
		    Tr = VADD(Tf, Tq);
		    T1N = VADD(T1k, T1l);
		    T1O = VADD(T1n, T1o);
		    T1S = VADD(T1N, T1O);
		    T1t = VSUB(T1r, T1s);
		    T1w = VSUB(T1u, T1v);
		    T1C = VADD(T1t, T1w);
		    TI = VADD(TC, TH);
		    TT = VADD(TN, TS);
		    TU = VADD(TI, TT);
		    T1K = VADD(T1r, T1s);
		    T1L = VADD(T1u, T1v);
		    T1R = VADD(T1K, T1L);
		    T1m = VSUB(T1k, T1l);
		    T1p = VSUB(T1n, T1o);
		    T1D = VADD(T1m, T1p);
	       }
	       Ts = VADD(T4, Tr);
	       TV = VBYI(VADD(Tx, TU));
	       ST(&(x[WS(rs, 5)]), VSUB(Ts, TV), ms, &(x[WS(rs, 1)]));
	       ST(&(x[WS(rs, 15)]), VADD(Ts, TV), ms, &(x[WS(rs, 1)]));
	       {
		    V T1T, T1V, T1W, T1Q, T1Z, T1M, T1P, T1Y, T1X;
		    T1T = VMUL(LDK(KP559016994), VSUB(T1R, T1S));
		    T1V = VADD(T1R, T1S);
		    T1W = VFNMS(LDK(KP250000000), T1V, T1U);
		    T1M = VSUB(T1K, T1L);
		    T1P = VSUB(T1N, T1O);
		    T1Q = VBYI(VFMA(LDK(KP951056516), T1M, VMUL(LDK(KP587785252), T1P)));
		    T1Z = VBYI(VFNMS(LDK(KP587785252), T1M, VMUL(LDK(KP951056516), T1P)));
		    ST(&(x[0]), VADD(T1U, T1V), ms, &(x[0]));
		    T1Y = VSUB(T1W, T1T);
		    ST(&(x[WS(rs, 8)]), VSUB(T1Y, T1Z), ms, &(x[0]));
		    ST(&(x[WS(rs, 12)]), VADD(T1Z, T1Y), ms, &(x[0]));
		    T1X = VADD(T1T, T1W);
		    ST(&(x[WS(rs, 4)]), VADD(T1Q, T1X), ms, &(x[0]));
		    ST(&(x[WS(rs, 16)]), VSUB(T1X, T1Q), ms, &(x[0]));
	       }
	       {
		    V T1G, T1E, T1F, T1y, T1J, T1q, T1x, T1I, T1H;
		    T1G = VMUL(LDK(KP559016994), VSUB(T1C, T1D));
		    T1E = VADD(T1C, T1D);
		    T1F = VFNMS(LDK(KP250000000), T1E, T1B);
		    T1q = VSUB(T1m, T1p);
		    T1x = VSUB(T1t, T1w);
		    T1y = VBYI(VFNMS(LDK(KP587785252), T1x, VMUL(LDK(KP951056516), T1q)));
		    T1J = VBYI(VFMA(LDK(KP951056516), T1x, VMUL(LDK(KP587785252), T1q)));
		    ST(&(x[WS(rs, 10)]), VADD(T1B, T1E), ms, &(x[0]));
		    T1I = VADD(T1G, T1F);
		    ST(&(x[WS(rs, 6)]), VSUB(T1I, T1J), ms, &(x[0]));
		    ST(&(x[WS(rs, 14)]), VADD(T1J, T1I), ms, &(x[0]));
		    T1H = VSUB(T1F, T1G);
		    ST(&(x[WS(rs, 2)]), VADD(T1y, T1H), ms, &(x[0]));
		    ST(&(x[WS(rs, 18)]), VSUB(T1H, T1y), ms, &(x[0]));
	       }
	       {
		    V T11, T18, T1g, T1d, T15, T1f, TY, T1c;
		    T11 = VFMA(LDK(KP951056516), TZ, VMUL(LDK(KP587785252), T10));
		    T18 = VFMA(LDK(KP951056516), T16, VMUL(LDK(KP587785252), T17));
		    T1g = VFNMS(LDK(KP587785252), T16, VMUL(LDK(KP951056516), T17));
		    T1d = VFNMS(LDK(KP587785252), TZ, VMUL(LDK(KP951056516), T10));
		    {
			 V T13, T14, TW, TX;
			 T13 = VFMS(LDK(KP250000000), TU, Tx);
			 T14 = VMUL(LDK(KP559016994), VSUB(TT, TI));
			 T15 = VADD(T13, T14);
			 T1f = VSUB(T14, T13);
			 TW = VMUL(LDK(KP559016994), VSUB(Tf, Tq));
			 TX = VFNMS(LDK(KP250000000), Tr, T4);
			 TY = VADD(TW, TX);
			 T1c = VSUB(TX, TW);
		    }
		    {
			 V T12, T19, T1i, T1j;
			 T12 = VADD(TY, T11);
			 T19 = VBYI(VSUB(T15, T18));
			 ST(&(x[WS(rs, 19)]), VSUB(T12, T19), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 1)]), VADD(T12, T19), ms, &(x[WS(rs, 1)]));
			 T1i = VADD(T1c, T1d);
			 T1j = VBYI(VADD(T1g, T1f));
			 ST(&(x[WS(rs, 13)]), VSUB(T1i, T1j), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 7)]), VADD(T1i, T1j), ms, &(x[WS(rs, 1)]));
		    }
		    {
			 V T1a, T1b, T1e, T1h;
			 T1a = VSUB(TY, T11);
			 T1b = VBYI(VADD(T18, T15));
			 ST(&(x[WS(rs, 11)]), VSUB(T1a, T1b), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 9)]), VADD(T1a, T1b), ms, &(x[WS(rs, 1)]));
			 T1e = VSUB(T1c, T1d);
			 T1h = VBYI(VSUB(T1f, T1g));
			 ST(&(x[WS(rs, 17)]), VSUB(T1e, T1h), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 3)]), VADD(T1e, T1h), ms, &(x[WS(rs, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     VTW(0, 9),
     VTW(0, 10),
     VTW(0, 11),
     VTW(0, 12),
     VTW(0, 13),
     VTW(0, 14),
     VTW(0, 15),
     VTW(0, 16),
     VTW(0, 17),
     VTW(0, 18),
     VTW(0, 19),
     { TW_NEXT, VL, 0 }
};

static const ct_desc desc = { 20, XSIMD_STRING("t1fv_20"), twinstr, &GENUS, { 111, 50, 12, 0 }, 0, 0, 0 };

void XSIMD(codelet_t1fv_20) (planner *p) {
     X(kdft_dit_register) (p, t1fv_20, &desc);
}
#endif
