// =============================================================================
// FUN_00680940
// -----------------------------------------------------------------------------
// Stable ID: aa_00680940
// Address:   0x00680940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00680940 @ 0x00680940
// Stable ID: aa_00680940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00680680, FUN_00680940.
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

void __thiscall FUN_00680940(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  uint uVar3;

  uint uVar4;

  

  if (((*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10) & 1U) == 0) &&

     (*(uint *)(param_1 + 8) <= *(int *)(param_1 + 0x10) + 2U >> 1)) {

    FUN_00680680(1);

  }

  uVar4 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10);

  uVar3 = uVar4 >> 1;

  if (*(uint *)(param_1 + 8) <= uVar3) {

    uVar3 = uVar3 - *(uint *)(param_1 + 8);

  }

  if (*(int *)(*(int *)(param_1 + 4) + uVar3 * 4) == 0) {

    pvVar2 = operator_new(0x10);

    *(void **)(*(int *)(param_1 + 4) + uVar3 * 4) = pvVar2;

  }

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + uVar3 * 4) + (uVar4 & 1) * 8);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar1 = *param_2;

    puVar1[1] = param_2[1];

  }

  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;

  return;

}
