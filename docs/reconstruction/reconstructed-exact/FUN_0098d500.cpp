// =============================================================================
// FUN_0098d500
// -----------------------------------------------------------------------------
// Stable ID: aa_0098d500
// Address:   0x0098d500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098d500 @ 0x0098d500
// Stable ID: aa_0098d500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_004367f0, FUN_0098d500.
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

void __fastcall FUN_0098d500(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x10);

  piVar4 = DAT_00d21984;

  for (puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xc); puVar3 != puVar1; puVar3 = puVar3 + 1) {

    piVar2 = (int *)*puVar3;

    if (piVar2 != (int *)0x0) {

      *piVar2 = (int)piVar4;

      piVar4 = piVar2;

      DAT_00d21984 = piVar2;

    }

  }

  FUN_004367f0(0,0);

  return;

}
