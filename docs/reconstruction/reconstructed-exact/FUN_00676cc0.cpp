// =============================================================================
// FUN_00676cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00676cc0
// Address:   0x00676cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00676cc0 @ 0x00676cc0
// Stable ID: aa_00676cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00675660, FUN_006767f0, FUN_00676cc0.
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

void __thiscall FUN_00676cc0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  uint uVar2;

  

  if (*(uint *)(param_1 + 8) <= *(int *)(param_1 + 0x10) + 1U) {

    FUN_006767f0(1);

  }

  uVar2 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10);

  if (*(uint *)(param_1 + 8) <= uVar2) {

    uVar2 = uVar2 - *(uint *)(param_1 + 8);

  }

  if (*(int *)(*(int *)(param_1 + 4) + uVar2 * 4) == 0) {

    pvVar1 = operator_new(0x1c);

    *(void **)(*(int *)(param_1 + 4) + uVar2 * 4) = pvVar1;

  }

  FUN_00675660(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + uVar2 * 4),param_2);

  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;

  return;

}
