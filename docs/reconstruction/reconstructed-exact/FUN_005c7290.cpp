// =============================================================================
// FUN_005c7290
// -----------------------------------------------------------------------------
// Stable ID: aa_005c7290
// Address:   0x005c7290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c7290 @ 0x005c7290
// Stable ID: aa_005c7290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_005c7290, FUN_00971ea0.
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

void FUN_005c7290(int param_1)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  

  if (*(int *)(DAT_00d1f050 + 0x6c) != 0) {

    for (uVar3 = *(uint *)(param_1 + 0xc);

        uVar3 != *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc); uVar3 = uVar3 + 1) {

      uVar2 = uVar3 >> 2;

      iVar1 = uVar2 * -4;

      if (*(uint *)(param_1 + 8) <= uVar2) {

        uVar2 = uVar2 - *(uint *)(param_1 + 8);

      }

      FUN_00971ea0(*(int *)(*(int *)(param_1 + 4) + uVar2 * 4) + (uVar3 + iVar1) * 4);

    }

  }

  return;

}
