// =============================================================================
// FUN_005cc630
// -----------------------------------------------------------------------------
// Stable ID: aa_005cc630
// Address:   0x005cc630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cc630 @ 0x005cc630
// Stable ID: aa_005cc630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: NAN×2, CONCAT21, CONCAT31, FUN_005cc630.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint __fastcall FUN_005cc630(int param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ in_EAX;

  uint uVar2;

  

  fVar1 = *(float *)(param_1 + 0x34);

  uVar2 = (uint)CONCAT21((short)((uint)in_EAX >> 0x10),

                         (fVar1 == g_flZero) << 6 | (NAN(fVar1) || NAN(g_flZero)) << 2 | 2U |

                         fVar1 < g_flZero) << 8;

  if (fVar1 != g_flZero) {

    fVar1 = (float)(int)g_dwClientTickMs;

    if ((int)g_dwClientTickMs < 0) {

      fVar1 = fVar1 + _DAT_00aaa5dc;

    }

    uVar2 = g_dwClientTickMs;

    if (fVar1 * g_flMsToSeconds_Inferred - *(float *)(param_1 + 0x38) < *(float *)(param_1 + 0x34))

    {

      return CONCAT31((int3)(g_dwClientTickMs >> 8),1);

    }

  }

  return uVar2 & 0xffffff00;

}
