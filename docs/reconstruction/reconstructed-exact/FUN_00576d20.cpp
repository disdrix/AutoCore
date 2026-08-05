// =============================================================================
// FUN_00576d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00576d20
// Address:   0x00576d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00576d20 @ 0x00576d20
// Stable ID: aa_00576d20
// Embedded strings (evidence for future rename):
//   - "Phase"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00576d20, FUN_0074f1b0.
//  - Strings: "Phase".
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

uint32_t /* width from decompiler */ __thiscall FUN_00576d20(int *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_EDI;

  

  iVar1 = param_2;

  iVar2 = FUN_0074f1b0("Phase");

  if (iVar2 != 0) {

    (**(code **)(**(int **)(iVar1 + 0xc) + 0xcc))(*(int **)(iVar1 + 0xc),iVar2,&param_2);

    if (unaff_EDI != 0) {

      uVar3 = (**(code **)(*param_1 + 4))(unaff_EDI);

      return uVar3;

    }

  }

  return 0xffff;

}
