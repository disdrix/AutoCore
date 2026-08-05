// =============================================================================
// FUN_007889b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007889b0
// Address:   0x007889b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007889b0 @ 0x007889b0
// Stable ID: aa_007889b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: NAN×2, CONCAT21, CONCAT31, FUN_007889b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __fastcall

FUN_007889b0(uint32_t /* width from decompiler */ param_1,float *param_2,float *param_3,float *param_4,float *param_5)



{

  uint3 uVar1;

  float *in_EAX;

  float *unaff_ESI;

  float *unaff_EDI;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  

  fVar4 = *unaff_ESI - *param_4;

  fVar5 = unaff_ESI[1] - param_4[1];

  fVar2 = fVar4 * (param_2[1] - in_EAX[1]) - fVar5 * (*param_2 - *in_EAX);

  uVar1 = CONCAT21((short)((uint)in_EAX >> 0x10),

                   (fVar2 == g_flZero) << 6 | (NAN(fVar2) || NAN(g_flZero)) << 2 | 2U |

                   fVar2 < g_flZero);

  if (fVar2 != g_flZero) {

    fVar3 = ((param_4[1] - in_EAX[1]) * (*param_2 - *in_EAX) -

            (*param_4 - *in_EAX) * (param_2[1] - in_EAX[1])) * (g_flOne / fVar2);

    fVar2 = ((param_4[1] - in_EAX[1]) * fVar4 - (*param_4 - *in_EAX) * fVar5) * (g_flOne / fVar2);

    if (unaff_EDI != (float *)0x0) {

      *unaff_EDI = fVar3;

    }

    if (param_5 != (float *)0x0) {

      *param_5 = fVar2;

    }

    if ((((0.0 < fVar3) && (fVar3 < g_flOne)) && (0.0 < fVar2)) && (fVar2 < g_flOne)) {

      if (param_3 != (float *)0x0) {

        *param_3 = fVar3 * fVar4 + *param_4;

        param_3[1] = fVar3 * fVar5 + param_4[1];

      }

      return CONCAT31(uVar1,1);

    }

  }

  return (uint)uVar1 << 8;

}
