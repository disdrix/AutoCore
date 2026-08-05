// =============================================================================
// FUN_005d3ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d3ac0
// Address:   0x005d3ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d3ac0 @ 0x005d3ac0
// Stable ID: aa_005d3ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0055dfb0×2, FUN_005074d0, FUN_005d3ac0.
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

void __fastcall FUN_005d3ac0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  piVar1 = (int *)param_1[0xf];

  *param_1 = &PTR_FUN_009daabc;

  iVar2 = (**(code **)(*piVar1 + 0x18))();

  if (iVar2 == 6) {

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_0055dfb0();

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar3)(1);

    }

  }

  iVar2 = (**(code **)(*(int *)param_1[0xf] + 0x18))();

  if (iVar2 == 7) {

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_0055dfb0();

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar3)(1);

    }

  }

  if (piVar1 != (int *)0x0) {

    (**(code **)*piVar1)(1);

  }

  FUN_005074d0();

  return;

}
