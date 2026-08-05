// =============================================================================
// FUN_004b0a20
// -----------------------------------------------------------------------------
// Stable ID: aa_004b0a20
// Address:   0x004b0a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b0a20 @ 0x004b0a20
// Stable ID: aa_004b0a20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_004b0a20×3, FUN_004af630, FUN_004af8a0, FUN_004aff50, FUN_004b0770.
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

void FUN_004b0a20(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int local_8;

  int local_4;

  

  iVar1 = param_2 - param_1;

  do {

    iVar1 = iVar1 >> 3;

    if (iVar1 < 0x21) {

LAB_004b0ab7:

      if (1 < iVar1) {

        FUN_004aff50(param_1,param_2,param_4);

      }

      return;

    }

    if (param_3 < 1) {

      if (0x20 < iVar1) {

        if (8 < (int)(param_2 - param_1 & 0xfffffff8U)) {

          FUN_004af8a0(param_1,param_2,param_4,0,0);

        }

        FUN_004b0770(param_1,param_2,param_4);

        return;

      }

      goto LAB_004b0ab7;

    }

    FUN_004af630(&local_8,param_1,param_2,param_4);

    iVar1 = local_4;

    param_3 = param_3 / 2 + (param_3 / 2) / 2;

    if ((int)(local_8 - param_1 & 0xfffffff8U) < (int)(param_2 - local_4 & 0xfffffff8U)) {

      FUN_004b0a20(param_1,local_8,param_3,param_4);

      param_1 = iVar1;

    }

    else {

      FUN_004b0a20(local_4,param_2,param_3,param_4);

      param_2 = local_8;

    }

    iVar1 = param_2 - param_1;

  } while( true );

}
