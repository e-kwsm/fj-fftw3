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
/* Generated on Tue Nov 24 01:07:46 JST 2020 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw_c.native -fma -simd -compact -variables 4 -pipeline-latency 8 -n 20 -name n1fv_20 -include dft/simd/n1f.h */

/*
 * This function contains 104 FP additions, 50 FP multiplications,
 * (or, 58 additions, 4 multiplications, 46 fused multiply/add),
 * 53 stack variables, 4 constants, and 40 memory accesses
 */
#include "dft/simd/n1f.h"

static void n1fv_20(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     VENTER();
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(40, is), MAKE_VOLATILE_STRIDE(40, os)) {
	       V T3, T1r, Tm, T13, TG, TN, TO, TH, T16, T19, T1a, T1v, T1w, T1x, T1s;
	       V T1t, T1u, T1d, T1g, T1h, Ti, TE, TB, TL, Tj, TC;
	       {
		    V T1, T2, T11, Tk, Tl, T12;
		    T1 = LD(&(xi[0]), ivs, &(xi[0]));
		    T2 = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
		    T11 = VADD(T1, T2);
		    Tk = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
		    Tl = LD(&(xi[WS(is, 15)]), ivs, &(xi[WS(is, 1)]));
		    T12 = VADD(Tk, Tl);
		    T3 = VSUB(T1, T2);
		    T1r = VADD(T11, T12);
		    Tm = VSUB(Tk, Tl);
		    T13 = VSUB(T11, T12);
	       }
	       {
		    V T6, T14, Tw, T1c, Tz, T1f, T9, T17, Td, T1b, Tp, T15, Ts, T18, Tg;
		    V T1e;
		    {
			 V T4, T5, Tu, Tv;
			 T4 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			 T5 = LD(&(xi[WS(is, 14)]), ivs, &(xi[0]));
			 T6 = VSUB(T4, T5);
			 T14 = VADD(T4, T5);
			 Tu = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
			 Tv = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 Tw = VSUB(Tu, Tv);
			 T1c = VADD(Tu, Tv);
		    }
		    {
			 V Tx, Ty, T7, T8;
			 Tx = LD(&(xi[WS(is, 17)]), ivs, &(xi[WS(is, 1)]));
			 Ty = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
			 Tz = VSUB(Tx, Ty);
			 T1f = VADD(Tx, Ty);
			 T7 = LD(&(xi[WS(is, 16)]), ivs, &(xi[0]));
			 T8 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 T9 = VSUB(T7, T8);
			 T17 = VADD(T7, T8);
		    }
		    {
			 V Tb, Tc, Tn, To;
			 Tb = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			 Tc = LD(&(xi[WS(is, 18)]), ivs, &(xi[0]));
			 Td = VSUB(Tb, Tc);
			 T1b = VADD(Tb, Tc);
			 Tn = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
			 To = LD(&(xi[WS(is, 19)]), ivs, &(xi[WS(is, 1)]));
			 Tp = VSUB(Tn, To);
			 T15 = VADD(Tn, To);
		    }
		    {
			 V Tq, Tr, Te, Tf;
			 Tq = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 Tr = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
			 Ts = VSUB(Tq, Tr);
			 T18 = VADD(Tq, Tr);
			 Te = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
			 Tf = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 Tg = VSUB(Te, Tf);
			 T1e = VADD(Te, Tf);
		    }
		    TG = VSUB(Ts, Tp);
		    TN = VSUB(T6, T9);
		    TO = VSUB(Td, Tg);
		    TH = VSUB(Tz, Tw);
		    T16 = VSUB(T14, T15);
		    T19 = VSUB(T17, T18);
		    T1a = VADD(T16, T19);
		    T1v = VADD(T1b, T1c);
		    T1w = VADD(T1e, T1f);
		    T1x = VADD(T1v, T1w);
		    T1s = VADD(T14, T15);
		    T1t = VADD(T17, T18);
		    T1u = VADD(T1s, T1t);
		    T1d = VSUB(T1b, T1c);
		    T1g = VSUB(T1e, T1f);
		    T1h = VADD(T1d, T1g);
		    {
			 V Ta, Th, Tt, TA;
			 Ta = VADD(T6, T9);
			 Th = VADD(Td, Tg);
			 Ti = VADD(Ta, Th);
			 TE = VSUB(Ta, Th);
			 Tt = VADD(Tp, Ts);
			 TA = VADD(Tw, Tz);
			 TB = VADD(Tt, TA);
			 TL = VSUB(TA, Tt);
		    }
	       }
	       Tj = VADD(T3, Ti);
	       TC = VADD(Tm, TB);
	       ST(&(xo[WS(os, 5)]), VFNMSI(TC, Tj), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 15)]), VFMAI(TC, Tj), ovs, &(xo[WS(os, 1)]));
	       {
		    V T1A, T1y, T1z, T1E, T1G, T1C, T1D, T1F, T1B;
		    T1A = VSUB(T1u, T1x);
		    T1y = VADD(T1u, T1x);
		    T1z = VFNMS(LDK(KP250000000), T1y, T1r);
		    T1C = VSUB(T1s, T1t);
		    T1D = VSUB(T1v, T1w);
		    T1E = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T1D, T1C));
		    T1G = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T1C, T1D));
		    ST(&(xo[0]), VADD(T1r, T1y), ovs, &(xo[0]));
		    T1F = VFNMS(LDK(KP559016994), T1A, T1z);
		    ST(&(xo[WS(os, 8)]), VFNMSI(T1G, T1F), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 12)]), VFMAI(T1G, T1F), ovs, &(xo[0]));
		    T1B = VFMA(LDK(KP559016994), T1A, T1z);
		    ST(&(xo[WS(os, 4)]), VFMAI(T1E, T1B), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 16)]), VFNMSI(T1E, T1B), ovs, &(xo[0]));
	       }
	       {
		    V T1k, T1i, T1j, T1o, T1q, T1m, T1n, T1p, T1l;
		    T1k = VSUB(T1a, T1h);
		    T1i = VADD(T1a, T1h);
		    T1j = VFNMS(LDK(KP250000000), T1i, T13);
		    T1m = VSUB(T1d, T1g);
		    T1n = VSUB(T16, T19);
		    T1o = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T1n, T1m));
		    T1q = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T1m, T1n));
		    ST(&(xo[WS(os, 10)]), VADD(T13, T1i), ovs, &(xo[0]));
		    T1p = VFMA(LDK(KP559016994), T1k, T1j);
		    ST(&(xo[WS(os, 6)]), VFNMSI(T1q, T1p), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 14)]), VFMAI(T1q, T1p), ovs, &(xo[0]));
		    T1l = VFNMS(LDK(KP559016994), T1k, T1j);
		    ST(&(xo[WS(os, 2)]), VFMAI(T1o, T1l), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 18)]), VFNMSI(T1o, T1l), ovs, &(xo[0]));
	       }
	       {
		    V TI, TP, TX, TU, TM, TW, TF, TT, TK, TD;
		    TI = VFMA(LDK(KP618033988), TH, TG);
		    TP = VFMA(LDK(KP618033988), TO, TN);
		    TX = VFNMS(LDK(KP618033988), TN, TO);
		    TU = VFNMS(LDK(KP618033988), TG, TH);
		    TK = VFNMS(LDK(KP250000000), TB, Tm);
		    TM = VFNMS(LDK(KP559016994), TL, TK);
		    TW = VFMA(LDK(KP559016994), TL, TK);
		    TD = VFNMS(LDK(KP250000000), Ti, T3);
		    TF = VFMA(LDK(KP559016994), TE, TD);
		    TT = VFNMS(LDK(KP559016994), TE, TD);
		    {
			 V TJ, TQ, TZ, T10;
			 TJ = VFMA(LDK(KP951056516), TI, TF);
			 TQ = VFMA(LDK(KP951056516), TP, TM);
			 ST(&(xo[WS(os, 1)]), VFNMSI(TQ, TJ), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 19)]), VFMAI(TQ, TJ), ovs, &(xo[WS(os, 1)]));
			 TZ = VFMA(LDK(KP951056516), TU, TT);
			 T10 = VFMA(LDK(KP951056516), TX, TW);
			 ST(&(xo[WS(os, 13)]), VFNMSI(T10, TZ), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 7)]), VFMAI(T10, TZ), ovs, &(xo[WS(os, 1)]));
		    }
		    {
			 V TR, TS, TV, TY;
			 TR = VFNMS(LDK(KP951056516), TI, TF);
			 TS = VFNMS(LDK(KP951056516), TP, TM);
			 ST(&(xo[WS(os, 9)]), VFNMSI(TS, TR), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 11)]), VFMAI(TS, TR), ovs, &(xo[WS(os, 1)]));
			 TV = VFNMS(LDK(KP951056516), TU, TT);
			 TY = VFNMS(LDK(KP951056516), TX, TW);
			 ST(&(xo[WS(os, 17)]), VFNMSI(TY, TV), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 3)]), VFMAI(TY, TV), ovs, &(xo[WS(os, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 20, XSIMD_STRING("n1fv_20"), { 58, 4, 46, 0 }, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_20) (planner *p) { X(kdft_register) (p, n1fv_20, &desc);
}

#else

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 20 -name n1fv_20 -include dft/simd/n1f.h */

/*
 * This function contains 104 FP additions, 24 FP multiplications,
 * (or, 92 additions, 12 multiplications, 12 fused multiply/add),
 * 53 stack variables, 4 constants, and 40 memory accesses
 */
#include "dft/simd/n1f.h"

static void n1fv_20(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     VENTER();
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(40, is), MAKE_VOLATILE_STRIDE(40, os)) {
	       V T3, T1B, Tm, T1i, TG, TN, TO, TH, T13, T16, T1k, T1u, T1v, T1z, T1r;
	       V T1s, T1y, T1a, T1d, T1j, Ti, TD, TB, TL, Tj, TC;
	       {
		    V T1, T2, T1g, Tk, Tl, T1h;
		    T1 = LD(&(xi[0]), ivs, &(xi[0]));
		    T2 = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
		    T1g = VADD(T1, T2);
		    Tk = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
		    Tl = LD(&(xi[WS(is, 15)]), ivs, &(xi[WS(is, 1)]));
		    T1h = VADD(Tk, Tl);
		    T3 = VSUB(T1, T2);
		    T1B = VADD(T1g, T1h);
		    Tm = VSUB(Tk, Tl);
		    T1i = VSUB(T1g, T1h);
	       }
	       {
		    V T6, T18, Tw, T12, Tz, T15, T9, T1b, Td, T11, Tp, T19, Ts, T1c, Tg;
		    V T14;
		    {
			 V T4, T5, Tu, Tv;
			 T4 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			 T5 = LD(&(xi[WS(is, 14)]), ivs, &(xi[0]));
			 T6 = VSUB(T4, T5);
			 T18 = VADD(T4, T5);
			 Tu = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
			 Tv = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 Tw = VSUB(Tu, Tv);
			 T12 = VADD(Tu, Tv);
		    }
		    {
			 V Tx, Ty, T7, T8;
			 Tx = LD(&(xi[WS(is, 17)]), ivs, &(xi[WS(is, 1)]));
			 Ty = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
			 Tz = VSUB(Tx, Ty);
			 T15 = VADD(Tx, Ty);
			 T7 = LD(&(xi[WS(is, 16)]), ivs, &(xi[0]));
			 T8 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 T9 = VSUB(T7, T8);
			 T1b = VADD(T7, T8);
		    }
		    {
			 V Tb, Tc, Tn, To;
			 Tb = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			 Tc = LD(&(xi[WS(is, 18)]), ivs, &(xi[0]));
			 Td = VSUB(Tb, Tc);
			 T11 = VADD(Tb, Tc);
			 Tn = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
			 To = LD(&(xi[WS(is, 19)]), ivs, &(xi[WS(is, 1)]));
			 Tp = VSUB(Tn, To);
			 T19 = VADD(Tn, To);
		    }
		    {
			 V Tq, Tr, Te, Tf;
			 Tq = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 Tr = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
			 Ts = VSUB(Tq, Tr);
			 T1c = VADD(Tq, Tr);
			 Te = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
			 Tf = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 Tg = VSUB(Te, Tf);
			 T14 = VADD(Te, Tf);
		    }
		    TG = VSUB(Ts, Tp);
		    TN = VSUB(T6, T9);
		    TO = VSUB(Td, Tg);
		    TH = VSUB(Tz, Tw);
		    T13 = VSUB(T11, T12);
		    T16 = VSUB(T14, T15);
		    T1k = VADD(T13, T16);
		    T1u = VADD(T11, T12);
		    T1v = VADD(T14, T15);
		    T1z = VADD(T1u, T1v);
		    T1r = VADD(T18, T19);
		    T1s = VADD(T1b, T1c);
		    T1y = VADD(T1r, T1s);
		    T1a = VSUB(T18, T19);
		    T1d = VSUB(T1b, T1c);
		    T1j = VADD(T1a, T1d);
		    {
			 V Ta, Th, Tt, TA;
			 Ta = VADD(T6, T9);
			 Th = VADD(Td, Tg);
			 Ti = VADD(Ta, Th);
			 TD = VMUL(LDK(KP559016994), VSUB(Ta, Th));
			 Tt = VADD(Tp, Ts);
			 TA = VADD(Tw, Tz);
			 TB = VADD(Tt, TA);
			 TL = VMUL(LDK(KP559016994), VSUB(TA, Tt));
		    }
	       }
	       Tj = VADD(T3, Ti);
	       TC = VBYI(VADD(Tm, TB));
	       ST(&(xo[WS(os, 5)]), VSUB(Tj, TC), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 15)]), VADD(Tj, TC), ovs, &(xo[WS(os, 1)]));
	       {
		    V T1A, T1C, T1D, T1x, T1G, T1t, T1w, T1F, T1E;
		    T1A = VMUL(LDK(KP559016994), VSUB(T1y, T1z));
		    T1C = VADD(T1y, T1z);
		    T1D = VFNMS(LDK(KP250000000), T1C, T1B);
		    T1t = VSUB(T1r, T1s);
		    T1w = VSUB(T1u, T1v);
		    T1x = VBYI(VFMA(LDK(KP951056516), T1t, VMUL(LDK(KP587785252), T1w)));
		    T1G = VBYI(VFNMS(LDK(KP587785252), T1t, VMUL(LDK(KP951056516), T1w)));
		    ST(&(xo[0]), VADD(T1B, T1C), ovs, &(xo[0]));
		    T1F = VSUB(T1D, T1A);
		    ST(&(xo[WS(os, 8)]), VSUB(T1F, T1G), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 12)]), VADD(T1G, T1F), ovs, &(xo[0]));
		    T1E = VADD(T1A, T1D);
		    ST(&(xo[WS(os, 4)]), VADD(T1x, T1E), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 16)]), VSUB(T1E, T1x), ovs, &(xo[0]));
	       }
	       {
		    V T1n, T1l, T1m, T1f, T1q, T17, T1e, T1p, T1o;
		    T1n = VMUL(LDK(KP559016994), VSUB(T1j, T1k));
		    T1l = VADD(T1j, T1k);
		    T1m = VFNMS(LDK(KP250000000), T1l, T1i);
		    T17 = VSUB(T13, T16);
		    T1e = VSUB(T1a, T1d);
		    T1f = VBYI(VFNMS(LDK(KP587785252), T1e, VMUL(LDK(KP951056516), T17)));
		    T1q = VBYI(VFMA(LDK(KP951056516), T1e, VMUL(LDK(KP587785252), T17)));
		    ST(&(xo[WS(os, 10)]), VADD(T1i, T1l), ovs, &(xo[0]));
		    T1p = VADD(T1n, T1m);
		    ST(&(xo[WS(os, 6)]), VSUB(T1p, T1q), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 14)]), VADD(T1q, T1p), ovs, &(xo[0]));
		    T1o = VSUB(T1m, T1n);
		    ST(&(xo[WS(os, 2)]), VADD(T1f, T1o), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 18)]), VSUB(T1o, T1f), ovs, &(xo[0]));
	       }
	       {
		    V TI, TP, TX, TU, TM, TW, TF, TT, TK, TE;
		    TI = VFMA(LDK(KP951056516), TG, VMUL(LDK(KP587785252), TH));
		    TP = VFMA(LDK(KP951056516), TN, VMUL(LDK(KP587785252), TO));
		    TX = VFNMS(LDK(KP587785252), TN, VMUL(LDK(KP951056516), TO));
		    TU = VFNMS(LDK(KP587785252), TG, VMUL(LDK(KP951056516), TH));
		    TK = VFMS(LDK(KP250000000), TB, Tm);
		    TM = VADD(TK, TL);
		    TW = VSUB(TL, TK);
		    TE = VFNMS(LDK(KP250000000), Ti, T3);
		    TF = VADD(TD, TE);
		    TT = VSUB(TE, TD);
		    {
			 V TJ, TQ, TZ, T10;
			 TJ = VADD(TF, TI);
			 TQ = VBYI(VSUB(TM, TP));
			 ST(&(xo[WS(os, 19)]), VSUB(TJ, TQ), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 1)]), VADD(TJ, TQ), ovs, &(xo[WS(os, 1)]));
			 TZ = VADD(TT, TU);
			 T10 = VBYI(VADD(TX, TW));
			 ST(&(xo[WS(os, 13)]), VSUB(TZ, T10), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 7)]), VADD(TZ, T10), ovs, &(xo[WS(os, 1)]));
		    }
		    {
			 V TR, TS, TV, TY;
			 TR = VSUB(TF, TI);
			 TS = VBYI(VADD(TP, TM));
			 ST(&(xo[WS(os, 11)]), VSUB(TR, TS), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 9)]), VADD(TR, TS), ovs, &(xo[WS(os, 1)]));
			 TV = VSUB(TT, TU);
			 TY = VBYI(VSUB(TW, TX));
			 ST(&(xo[WS(os, 17)]), VSUB(TV, TY), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 3)]), VADD(TV, TY), ovs, &(xo[WS(os, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 20, XSIMD_STRING("n1fv_20"), { 92, 12, 12, 0 }, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_20) (planner *p) { X(kdft_register) (p, n1fv_20, &desc);
}

#endif
