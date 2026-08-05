// =============================================================================
// FUN_0053db40
// -----------------------------------------------------------------------------
// Stable ID: aa_0053db40
// Address:   0x0053db40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053db40 @ 0x0053db40
// Stable ID: aa_0053db40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00512210, FUN_0053db40.
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

void __thiscall FUN_0053db40(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  FUN_00512210(param_2);

  iVar1 = *(int *)(*(int *)(param_1 + -0x4c) + 4) + param_1;

  if ((((*(int *)(*(int *)(iVar1 + 0x5c) + 0x38) == 3) &&

       ((*(byte *)(*(int *)(*(int *)(iVar1 + 0x5c) + 0x3c) + 0x3f2) & 0x20) == 0)) &&

      ((*(uint *)(iVar1 + 0x130) >> 10 & 1) == 0)) && (*(int *)(iVar1 + -0x38) == 0)) {

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + -0x4c + param_1) + 0x2b4))();

  }

  return;

}
