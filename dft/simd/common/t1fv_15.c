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

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -simd -compact -variables 4 -pipeline-latency 8 -n 15 -name t1fv_15 -include dft/simd/t1f.h */

/*
 * This function contains 92 FP additions, 77 FP multiplications,
 * (or, 50 additions, 35 multiplications, 42 fused multiply/add),
 * 50 stack variables, 8 constants, and 30 memory accesses
 */
#include "dft/simd/t1f.h"

static void t1fv_15(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP910592997, +0.910592997310029334643087372129977886038870291);
     DVK(KP823639103, +0.823639103546331925877420039278190003029660514);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     VENTER();
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 28)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 28), MAKE_VOLATILE_STRIDE(15, rs)) {
	       V T1b, T7, TP, T12, T15, Tf, Tn, To, T1c, T1d, T1e, TQ, TR, TS, Tw;
	       V TE, TF, TT, TU, TV;
	       {
		    V T1, T5, T3, T4, T2, T6;
		    T1 = LD(&(x[0]), ms, &(x[0]));
		    T4 = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
		    T5 = BYTWJ(&(W[TWVL * 18]), T4);
		    T2 = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
		    T3 = BYTWJ(&(W[TWVL * 8]), T2);
		    T1b = VSUB(T5, T3);
		    T6 = VADD(T3, T5);
		    T7 = VADD(T1, T6);
		    TP = VFNMS(LDK(KP500000000), T6, T1);
	       }
	       {
		    V T9, Tq, Ty, Th, Te, T10, Tv, T13, TD, T14, Tm, T11;
		    {
			 V T8, Tp, Tx, Tg;
			 T8 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 T9 = BYTWJ(&(W[TWVL * 4]), T8);
			 Tp = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Tq = BYTWJ(&(W[TWVL * 10]), Tp);
			 Tx = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			 Ty = BYTWJ(&(W[TWVL * 16]), Tx);
			 Tg = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
			 Th = BYTWJ(&(W[TWVL * 22]), Tg);
		    }
		    {
			 V Tb, Td, Ta, Tc;
			 Ta = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			 Tb = BYTWJ(&(W[TWVL * 14]), Ta);
			 Tc = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
			 Td = BYTWJ(&(W[TWVL * 24]), Tc);
			 Te = VADD(Tb, Td);
			 T10 = VSUB(Td, Tb);
		    }
		    {
			 V Ts, Tu, Tr, Tt;
			 Tr = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
			 Ts = BYTWJ(&(W[TWVL * 20]), Tr);
			 Tt = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 Tu = BYTWJ(&(W[0]), Tt);
			 Tv = VADD(Ts, Tu);
			 T13 = VSUB(Tu, Ts);
		    }
		    {
			 V TA, TC, Tz, TB;
			 Tz = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			 TA = BYTWJ(&(W[TWVL * 26]), Tz);
			 TB = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			 TC = BYTWJ(&(W[TWVL * 6]), TB);
			 TD = VADD(TA, TC);
			 T14 = VSUB(TC, TA);
		    }
		    {
			 V Tj, Tl, Ti, Tk;
			 Ti = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 Tj = BYTWJ(&(W[TWVL * 2]), Ti);
			 Tk = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 Tl = BYTWJ(&(W[TWVL * 12]), Tk);
			 Tm = VADD(Tj, Tl);
			 T11 = VSUB(Tl, Tj);
		    }
		    T12 = VSUB(T10, T11);
		    T15 = VSUB(T13, T14);
		    Tf = VADD(T9, Te);
		    Tn = VADD(Th, Tm);
		    To = VADD(Tf, Tn);
		    T1c = VADD(T10, T11);
		    T1d = VADD(T13, T14);
		    T1e = VADD(T1c, T1d);
		    TQ = VFNMS(LDK(KP500000000), Te, T9);
		    TR = VFNMS(LDK(KP500000000), Tm, Th);
		    TS = VADD(TQ, TR);
		    Tw = VADD(Tq, Tv);
		    TE = VADD(Ty, TD);
		    TF = VADD(Tw, TE);
		    TT = VFNMS(LDK(KP500000000), Tv, Tq);
		    TU = VFNMS(LDK(KP500000000), TD, Ty);
		    TV = VADD(TT, TU);
	       }
	       {
		    V TI, TG, TH, TM, TO, TK, TL, TN, TJ;
		    TI = VSUB(To, TF);
		    TG = VADD(To, TF);
		    TH = VFNMS(LDK(KP250000000), TG, T7);
		    TK = VSUB(Tw, TE);
		    TL = VSUB(Tf, Tn);
		    TM = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), TL, TK));
		    TO = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), TK, TL));
		    ST(&(x[0]), VADD(T7, TG), ms, &(x[0]));
		    TN = VFMA(LDK(KP559016994), TI, TH);
		    ST(&(x[WS(rs, 6)]), VFNMSI(TO, TN), ms, &(x[0]));
		    ST(&(x[WS(rs, 9)]), VFMAI(TO, TN), ms, &(x[WS(rs, 1)]));
		    TJ = VFNMS(LDK(KP559016994), TI, TH);
		    ST(&(x[WS(rs, 3)]), VFNMSI(TM, TJ), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 12)]), VFMAI(TM, TJ), ms, &(x[0]));
	       }
	       {
		    V T16, T1m, T1u, T1h, T1p, T1a, T1o, TZ, T1t, T1l, T1f, T1g;
		    T16 = VFMA(LDK(KP618033988), T15, T12);
		    T1m = VFNMS(LDK(KP618033988), T12, T15);
		    T1u = VMUL(LDK(KP866025403), VADD(T1b, T1e));
		    T1f = VFNMS(LDK(KP250000000), T1e, T1b);
		    T1g = VSUB(T1c, T1d);
		    T1h = VFMA(LDK(KP559016994), T1g, T1f);
		    T1p = VFNMS(LDK(KP559016994), T1g, T1f);
		    {
			 V T18, T19, TY, TW, TX;
			 T18 = VSUB(TQ, TR);
			 T19 = VSUB(TT, TU);
			 T1a = VFMA(LDK(KP618033988), T19, T18);
			 T1o = VFNMS(LDK(KP618033988), T18, T19);
			 TY = VSUB(TS, TV);
			 TW = VADD(TS, TV);
			 TX = VFNMS(LDK(KP250000000), TW, TP);
			 TZ = VFMA(LDK(KP559016994), TY, TX);
			 T1t = VADD(TP, TW);
			 T1l = VFNMS(LDK(KP559016994), TY, TX);
		    }
		    {
			 V T17, T1i, T1r, T1s;
			 ST(&(x[WS(rs, 5)]), VFNMSI(T1u, T1t), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 10)]), VFMAI(T1u, T1t), ms, &(x[0]));
			 T17 = VFMA(LDK(KP823639103), T16, TZ);
			 T1i = VMUL(LDK(KP951056516), VFNMS(LDK(KP910592997), T1h, T1a));
			 ST(&(x[WS(rs, 1)]), VFNMSI(T1i, T17), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 14)]), VFMAI(T1i, T17), ms, &(x[0]));
			 T1r = VFNMS(LDK(KP823639103), T1m, T1l);
			 T1s = VMUL(LDK(KP951056516), VFMA(LDK(KP910592997), T1p, T1o));
			 ST(&(x[WS(rs, 8)]), VFNMSI(T1s, T1r), ms, &(x[0]));
			 ST(&(x[WS(rs, 7)]), VFMAI(T1s, T1r), ms, &(x[WS(rs, 1)]));
			 {
			      V T1n, T1q, T1j, T1k;
			      T1n = VFMA(LDK(KP823639103), T1m, T1l);
			      T1q = VMUL(LDK(KP951056516), VFNMS(LDK(KP910592997), T1p, T1o));
			      ST(&(x[WS(rs, 13)]), VFNMSI(T1q, T1n), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 2)]), VFMAI(T1q, T1n), ms, &(x[0]));
			      T1j = VFNMS(LDK(KP823639103), T16, TZ);
			      T1k = VMUL(LDK(KP951056516), VFMA(LDK(KP910592997), T1h, T1a));
			      ST(&(x[WS(rs, 11)]), VFNMSI(T1k, T1j), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 4)]), VFMAI(T1k, T1j), ms, &(x[0]));
			 }
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
     { TW_NEXT, VL, 0 }
};

static const ct_desc desc = { 15, XSIMD_STRING("t1fv_15"), twinstr, &GENUS, { 50, 35, 42, 0 }, 0, 0, 0 };

void XSIMD(codelet_t1fv_15) (planner *p) {
     X(kdft_dit_register) (p, t1fv_15, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 15 -name t1fv_15 -include dft/simd/t1f.h */

/*
 * This function contains 92 FP additions, 53 FP multiplications,
 * (or, 78 additions, 39 multiplications, 14 fused multiply/add),
 * 52 stack variables, 10 constants, and 30 memory accesses
 */
#include "dft/simd/t1f.h"

static void t1fv_15(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP216506350, +0.216506350946109661690930792688234045867850657);
     DVK(KP484122918, +0.484122918275927110647408174972799951354115213);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP509036960, +0.509036960455127183450980863393907648510733164);
     DVK(KP823639103, +0.823639103546331925877420039278190003029660514);
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     VENTER();
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 28)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 28), MAKE_VOLATILE_STRIDE(15, rs)) {
	       V T1e, T7, TP, T12, T15, Tf, Tn, To, T1b, T1c, T1f, TQ, TR, TS, Tw;
	       V TE, TF, TT, TU, TV;
	       {
		    V T1, T5, T3, T4, T2, T6;
		    T1 = LD(&(x[0]), ms, &(x[0]));
		    T4 = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
		    T5 = BYTWJ(&(W[TWVL * 18]), T4);
		    T2 = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
		    T3 = BYTWJ(&(W[TWVL * 8]), T2);
		    T1e = VSUB(T5, T3);
		    T6 = VADD(T3, T5);
		    T7 = VADD(T1, T6);
		    TP = VFNMS(LDK(KP500000000), T6, T1);
	       }
	       {
		    V T9, Tq, Ty, Th, Te, T13, Tv, T10, TD, T11, Tm, T14;
		    {
			 V T8, Tp, Tx, Tg;
			 T8 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 T9 = BYTWJ(&(W[TWVL * 4]), T8);
			 Tp = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Tq = BYTWJ(&(W[TWVL * 10]), Tp);
			 Tx = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			 Ty = BYTWJ(&(W[TWVL * 16]), Tx);
			 Tg = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
			 Th = BYTWJ(&(W[TWVL * 22]), Tg);
		    }
		    {
			 V Tb, Td, Ta, Tc;
			 Ta = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			 Tb = BYTWJ(&(W[TWVL * 14]), Ta);
			 Tc = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
			 Td = BYTWJ(&(W[TWVL * 24]), Tc);
			 Te = VADD(Tb, Td);
			 T13 = VSUB(Td, Tb);
		    }
		    {
			 V Ts, Tu, Tr, Tt;
			 Tr = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
			 Ts = BYTWJ(&(W[TWVL * 20]), Tr);
			 Tt = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 Tu = BYTWJ(&(W[0]), Tt);
			 Tv = VADD(Ts, Tu);
			 T10 = VSUB(Tu, Ts);
		    }
		    {
			 V TA, TC, Tz, TB;
			 Tz = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			 TA = BYTWJ(&(W[TWVL * 26]), Tz);
			 TB = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			 TC = BYTWJ(&(W[TWVL * 6]), TB);
			 TD = VADD(TA, TC);
			 T11 = VSUB(TC, TA);
		    }
		    {
			 V Tj, Tl, Ti, Tk;
			 Ti = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 Tj = BYTWJ(&(W[TWVL * 2]), Ti);
			 Tk = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 Tl = BYTWJ(&(W[TWVL * 12]), Tk);
			 Tm = VADD(Tj, Tl);
			 T14 = VSUB(Tl, Tj);
		    }
		    T12 = VSUB(T10, T11);
		    T15 = VSUB(T13, T14);
		    Tf = VADD(T9, Te);
		    Tn = VADD(Th, Tm);
		    To = VADD(Tf, Tn);
		    T1b = VADD(T13, T14);
		    T1c = VADD(T10, T11);
		    T1f = VADD(T1b, T1c);
		    TQ = VFNMS(LDK(KP500000000), Te, T9);
		    TR = VFNMS(LDK(KP500000000), Tm, Th);
		    TS = VADD(TQ, TR);
		    Tw = VADD(Tq, Tv);
		    TE = VADD(Ty, TD);
		    TF = VADD(Tw, TE);
		    TT = VFNMS(LDK(KP500000000), Tv, Tq);
		    TU = VFNMS(LDK(KP500000000), TD, Ty);
		    TV = VADD(TT, TU);
	       }
	       {
		    V TI, TG, TH, TM, TO, TK, TL, TN, TJ;
		    TI = VMUL(LDK(KP559016994), VSUB(To, TF));
		    TG = VADD(To, TF);
		    TH = VFNMS(LDK(KP250000000), TG, T7);
		    TK = VSUB(Tw, TE);
		    TL = VSUB(Tf, Tn);
		    TM = VBYI(VFNMS(LDK(KP587785252), TL, VMUL(LDK(KP951056516), TK)));
		    TO = VBYI(VFMA(LDK(KP951056516), TL, VMUL(LDK(KP587785252), TK)));
		    ST(&(x[0]), VADD(T7, TG), ms, &(x[0]));
		    TN = VADD(TI, TH);
		    ST(&(x[WS(rs, 6)]), VSUB(TN, TO), ms, &(x[0]));
		    ST(&(x[WS(rs, 9)]), VADD(TO, TN), ms, &(x[WS(rs, 1)]));
		    TJ = VSUB(TH, TI);
		    ST(&(x[WS(rs, 3)]), VSUB(TJ, TM), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 12)]), VADD(TM, TJ), ms, &(x[0]));
	       }
	       {
		    V T16, T1m, T1u, T1h, T1o, T1a, T1p, TZ, T1t, T1l, T1d, T1g;
		    T16 = VFNMS(LDK(KP509036960), T15, VMUL(LDK(KP823639103), T12));
		    T1m = VFMA(LDK(KP823639103), T15, VMUL(LDK(KP509036960), T12));
		    T1u = VBYI(VMUL(LDK(KP866025403), VADD(T1e, T1f)));
		    T1d = VMUL(LDK(KP484122918), VSUB(T1b, T1c));
		    T1g = VFNMS(LDK(KP216506350), T1f, VMUL(LDK(KP866025403), T1e));
		    T1h = VSUB(T1d, T1g);
		    T1o = VADD(T1d, T1g);
		    {
			 V T18, T19, TY, TW, TX;
			 T18 = VSUB(TT, TU);
			 T19 = VSUB(TQ, TR);
			 T1a = VFNMS(LDK(KP587785252), T19, VMUL(LDK(KP951056516), T18));
			 T1p = VFMA(LDK(KP951056516), T19, VMUL(LDK(KP587785252), T18));
			 TY = VMUL(LDK(KP559016994), VSUB(TS, TV));
			 TW = VADD(TS, TV);
			 TX = VFNMS(LDK(KP250000000), TW, TP);
			 TZ = VSUB(TX, TY);
			 T1t = VADD(TP, TW);
			 T1l = VADD(TY, TX);
		    }
		    {
			 V T17, T1i, T1r, T1s;
			 ST(&(x[WS(rs, 5)]), VSUB(T1t, T1u), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 10)]), VADD(T1t, T1u), ms, &(x[0]));
			 T17 = VSUB(TZ, T16);
			 T1i = VBYI(VSUB(T1a, T1h));
			 ST(&(x[WS(rs, 8)]), VSUB(T17, T1i), ms, &(x[0]));
			 ST(&(x[WS(rs, 7)]), VADD(T17, T1i), ms, &(x[WS(rs, 1)]));
			 T1r = VSUB(T1l, T1m);
			 T1s = VBYI(VADD(T1p, T1o));
			 ST(&(x[WS(rs, 11)]), VSUB(T1r, T1s), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 4)]), VADD(T1r, T1s), ms, &(x[0]));
			 {
			      V T1n, T1q, T1j, T1k;
			      T1n = VADD(T1l, T1m);
			      T1q = VBYI(VSUB(T1o, T1p));
			      ST(&(x[WS(rs, 14)]), VSUB(T1n, T1q), ms, &(x[0]));
			      ST(&(x[WS(rs, 1)]), VADD(T1n, T1q), ms, &(x[WS(rs, 1)]));
			      T1j = VADD(TZ, T16);
			      T1k = VBYI(VADD(T1a, T1h));
			      ST(&(x[WS(rs, 13)]), VSUB(T1j, T1k), ms, &(x[WS(rs, 1)]));
			      ST(&(x[WS(rs, 2)]), VADD(T1j, T1k), ms, &(x[0]));
			 }
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
     { TW_NEXT, VL, 0 }
};

static const ct_desc desc = { 15, XSIMD_STRING("t1fv_15"), twinstr, &GENUS, { 78, 39, 14, 0 }, 0, 0, 0 };

void XSIMD(codelet_t1fv_15) (planner *p) {
     X(kdft_dit_register) (p, t1fv_15, &desc);
}
#endif
