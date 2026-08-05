// =============================================================================
// FUN_0046d930
// -----------------------------------------------------------------------------
// Stable ID: aa_0046d930
// Address:   0x0046d930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046d930 @ 0x0046d930
// Stable ID: aa_0046d930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_0046d930×3, FUN_00468db0, FUN_00468f80, FUN_00469080, FUN_0046db10.
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

void FUN_0046d930(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int local_8;

  int local_4;

  

  iVar1 = param_2 - param_1;

  do {

    iVar1 = iVar1 >> 2;

    if (iVar1 < 0x21) {

LAB_0046d9c7:

      if (1 < iVar1) {

        FUN_0046db10(param_1,param_2,param_4);

      }

      return;

    }

    if (param_3 < 1) {

      if (0x20 < iVar1) {

        if (4 < (int)(param_2 - param_1 & 0xfffffffcU)) {

          FUN_00469080(param_1,param_2,param_4);

        }

        FUN_00468f80(param_1,param_2,param_4);

        return;

      }

      goto LAB_0046d9c7;

    }

    FUN_00468db0(&local_8,param_1,param_2,param_4);

    iVar1 = local_4;

    param_3 = param_3 / 2 + (param_3 / 2) / 2;

    if ((int)(local_8 - param_1 & 0xfffffffcU) < (int)(param_2 - local_4 & 0xfffffffcU)) {

      FUN_0046d930(param_1,local_8,param_3,param_4);

      param_1 = iVar1;

    }

    else {

      FUN_0046d930(local_4,param_2,param_3,param_4);

      param_2 = local_8;

    }

    iVar1 = param_2 - param_1;

  } while( true );

}
