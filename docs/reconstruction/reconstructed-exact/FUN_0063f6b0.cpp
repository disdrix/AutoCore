// =============================================================================
// FUN_0063f6b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0063f6b0
// Address:   0x0063f6b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063f6b0 @ 0x0063f6b0
// Stable ID: aa_0063f6b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00638180, FUN_0063f6b0.
//  - Return sites: 1.

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

void __fastcall FUN_0063f6b0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = 0;

  if (0 < (int)param_1[4]) {

    iVar3 = 0;

    do {

      piVar1 = (int *)(*(int *)(param_1[3] + iVar3) + -4);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        FUN_00638180();

      }

      iVar2 = iVar2 + 1;

      iVar3 = iVar3 + 0xc;

    } while (iVar2 < (int)param_1[4]);

  }

  if (-1 < (int)param_1[5]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[3],(param_1[5] & 0x7fffffff) * 0xc,0x12);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
