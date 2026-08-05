// =============================================================================
// UI_first_btn_minimize_off
// -----------------------------------------------------------------------------
// Stable ID: aa_008db3f0
// Address:   0x008db3f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_first_btn_minimize_off @ 0x008db3f0
// Stable ID: aa_008db3f0
// Embedded strings (evidence for future rename):
//   - "i_d_first_2d_btn_minimize_off.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: UI_first_btn_minimize_off.
//  - Strings: "i_d_first_2d_btn_minimize_off.dds".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_first_2d_btn_minimize_off.dds"
 * Domain alias of FUN_008db3f0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall UI_first_btn_minimize_off(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  if (*(int *)(param_1 + 0x584) != 0) {

    if (param_2 != 6) {

      (**(code **)(**(int **)(param_1 + 0x584) + 0x58))();

      return;

    }

    piVar1 = *(int **)(param_1 + 0x584);

    iVar2 = *piVar1;

    uVar3 = (**(code **)(**(int **)(param_1 + 0x584) + 0x2d8))();

    uVar3 = (**(code **)(*piVar1 + 0x2c8))(uVar3);

    (**(code **)(iVar2 + 0x50))("i_d_first_2d_btn_minimize_off.dds",uVar3);

  }

  return;

}
