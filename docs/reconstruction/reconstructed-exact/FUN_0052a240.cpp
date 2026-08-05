// =============================================================================
// FUN_0052a240
// -----------------------------------------------------------------------------
// Stable ID: aa_0052a240
// Address:   0x0052a240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052a240 @ 0x0052a240
// Stable ID: aa_0052a240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_0052a240, FUN_00538d50.
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

void __thiscall FUN_0052a240(int param_1,uint param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe5c4);

  iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0x10) + (*(uint *)(iVar1 + 8) & param_2) * 4) + 4);

  if (iVar1 != 0) {

    while (param_2 != *(uint *)(iVar1 + 0x10)) {

      iVar1 = *(int *)(iVar1 + 0xc);

      if (iVar1 == 0) {

        return;

      }

    }

    if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {

      FUN_00538d50(param_2,0);

    }

  }

  return;

}
