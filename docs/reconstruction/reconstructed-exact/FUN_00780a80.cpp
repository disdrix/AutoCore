// =============================================================================
// FUN_00780a80
// -----------------------------------------------------------------------------
// Stable ID: aa_00780a80
// Address:   0x00780a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00780a80 @ 0x00780a80
// Stable ID: aa_00780a80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, for×1.
//  - Notable callees: FUN_00780a80.
//  - Return sites: 3.

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

uint __thiscall FUN_00780a80(int param_1,uint param_2)



{

  uint *puVar1;

  

  if (param_2 != 0) {

    if (*(int *)(param_1 + 0x208) == 0) {

      return *(uint *)(param_2 + 0x20);

    }

    for (puVar1 = *(uint **)(*(int *)(param_1 + 0x224) + (param_2 & 0x3ff) * 4);

        puVar1 != (uint *)0x0; puVar1 = (uint *)puVar1[8]) {

      if ((*puVar1 == param_2) && ((puVar1[10] & 0x3c) == 0)) {

        return puVar1[0xc];

      }

    }

  }

  return 0xffffffff;

}
