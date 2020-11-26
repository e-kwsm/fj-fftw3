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

/* Generated by: ../../../genfft/gen_hc2hc.native -fma -compact -variables 4 -pipeline-latency 4 -n 3 -dit -name hf_3 -include rdft/scalar/hf.h */

/*
 * This function contains 16 FP additions, 14 FP multiplications,
 * (or, 6 additions, 4 multiplications, 10 fused multiply/add),
 * 15 stack variables, 2 constants, and 12 memory accesses
 */
#include "rdft/scalar/hf.h"

static void hf_3(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 4); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 4, MAKE_VOLATILE_STRIDE(6, rs)) {
	       E T1, Tl, T7, Th, Td, Tj;
	       T1 = cr[0];
	       Tl = ci[0];
	       {
		    E T3, T6, T4, Tg, T2, T5;
		    T3 = cr[WS(rs, 1)];
		    T6 = ci[WS(rs, 1)];
		    T2 = W[0];
		    T4 = T2 * T3;
		    Tg = T2 * T6;
		    T5 = W[1];
		    T7 = FMA(T5, T6, T4);
		    Th = FNMS(T5, T3, Tg);
	       }
	       {
		    E T9, Tc, Ta, Ti, T8, Tb;
		    T9 = cr[WS(rs, 2)];
		    Tc = ci[WS(rs, 2)];
		    T8 = W[2];
		    Ta = T8 * T9;
		    Ti = T8 * Tc;
		    Tb = W[3];
		    Td = FMA(Tb, Tc, Ta);
		    Tj = FNMS(Tb, T9, Ti);
	       }
	       {
		    E Tk, Te, Tf, To, Tm, Tn;
		    Tk = Th - Tj;
		    Te = T7 + Td;
		    Tf = FNMS(KP500000000, Te, T1);
		    cr[0] = T1 + Te;
		    ci[0] = FNMS(KP866025403, Tk, Tf);
		    cr[WS(rs, 1)] = FMA(KP866025403, Tk, Tf);
		    To = Td - T7;
		    Tm = Th + Tj;
		    Tn = FNMS(KP500000000, Tm, Tl);
		    cr[WS(rs, 2)] = FMS(KP866025403, To, Tn);
		    ci[WS(rs, 2)] = Tm + Tl;
		    ci[WS(rs, 1)] = FMA(KP866025403, To, Tn);
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 1, 3 },
     { TW_NEXT, 1, 0 }
};

static const hc2hc_desc desc = { 3, "hf_3", twinstr, &GENUS, { 6, 4, 10, 0 } };

void X(codelet_hf_3) (planner *p) {
     X(khc2hc_register) (p, hf_3, &desc);
}
#else

/* Generated by: ../../../genfft/gen_hc2hc.native -compact -variables 4 -pipeline-latency 4 -n 3 -dit -name hf_3 -include rdft/scalar/hf.h */

/*
 * This function contains 16 FP additions, 12 FP multiplications,
 * (or, 10 additions, 6 multiplications, 6 fused multiply/add),
 * 15 stack variables, 2 constants, and 12 memory accesses
 */
#include "rdft/scalar/hf.h"

static void hf_3(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 4); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 4, MAKE_VOLATILE_STRIDE(6, rs)) {
	       E T1, Ti, T6, Te, Tb, Tf, Tc, Tj;
	       T1 = cr[0];
	       Ti = ci[0];
	       {
		    E T3, T5, T2, T4;
		    T3 = cr[WS(rs, 1)];
		    T5 = ci[WS(rs, 1)];
		    T2 = W[0];
		    T4 = W[1];
		    T6 = FMA(T2, T3, T4 * T5);
		    Te = FNMS(T4, T3, T2 * T5);
	       }
	       {
		    E T8, Ta, T7, T9;
		    T8 = cr[WS(rs, 2)];
		    Ta = ci[WS(rs, 2)];
		    T7 = W[2];
		    T9 = W[3];
		    Tb = FMA(T7, T8, T9 * Ta);
		    Tf = FNMS(T9, T8, T7 * Ta);
	       }
	       Tc = T6 + Tb;
	       Tj = Te + Tf;
	       {
		    E Td, Tg, Th, Tk;
		    cr[0] = T1 + Tc;
		    Td = FNMS(KP500000000, Tc, T1);
		    Tg = KP866025403 * (Te - Tf);
		    ci[0] = Td - Tg;
		    cr[WS(rs, 1)] = Td + Tg;
		    ci[WS(rs, 2)] = Tj + Ti;
		    Th = KP866025403 * (Tb - T6);
		    Tk = FNMS(KP500000000, Tj, Ti);
		    cr[WS(rs, 2)] = Th - Tk;
		    ci[WS(rs, 1)] = Th + Tk;
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 1, 3 },
     { TW_NEXT, 1, 0 }
};

static const hc2hc_desc desc = { 3, "hf_3", twinstr, &GENUS, { 10, 6, 6, 0 } };

void X(codelet_hf_3) (planner *p) {
     X(khc2hc_register) (p, hf_3, &desc);
}
#endif
