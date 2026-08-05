// =============================================================================
// FUN_0044cc30
// -----------------------------------------------------------------------------
// Stable ID: aa_0044cc30
// Address:   0x0044cc30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044cc30 @ 0x0044cc30
// Stable ID: aa_0044cc30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_0044cc30×3, FUN_0044cd20, FUN_0044cf90, FUN_0044cff0, FUN_0044d130.
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

void FUN_0044cc30(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int local_8;

  int local_4;

  

  iVar1 = param_2 - param_1;

  do {

    iVar1 = iVar1 >> 3;

    if (iVar1 < 0x21) {

LAB_0044ccc7:

      if (1 < iVar1) {

        FUN_0044cff0(param_1,param_2,param_4);

      }

      return;

    }

    if (param_3 < 1) {

      if (0x20 < iVar1) {

        if (8 < (int)(param_2 - param_1 & 0xfffffff8U)) {

          FUN_0044d130(param_1,param_2,param_4);

        }

        FUN_0044cf90(param_1,param_2,param_4);

        return;

      }

      goto LAB_0044ccc7;

    }

    FUN_0044cd20(&local_8,param_1,param_2,param_4);

    iVar1 = local_4;

    param_3 = param_3 / 2 + (param_3 / 2) / 2;

    if ((int)(local_8 - param_1 & 0xfffffff8U) < (int)(param_2 - local_4 & 0xfffffff8U)) {

      FUN_0044cc30(param_1,local_8,param_3,param_4);

      param_1 = iVar1;

    }

    else {

      FUN_0044cc30(local_4,param_2,param_3,param_4);

      param_2 = local_8;

    }

    iVar1 = param_2 - param_1;

  } while( true );

}
