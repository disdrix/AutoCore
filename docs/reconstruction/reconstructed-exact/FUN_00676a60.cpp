// =============================================================================
// FUN_00676a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00676a60
// Address:   0x00676a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00676a60 @ 0x00676a60
// Stable ID: aa_00676a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00675660, FUN_006767f0, FUN_00676a60.
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

void __thiscall FUN_00676a60(int param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  int iVar2;

  

  if (*(uint *)(param_1 + 8) <= *(int *)(param_1 + 0x10) + 1U) {

    FUN_006767f0(1);

  }

  iVar2 = *(int *)(param_1 + 0xc);

  if (iVar2 == 0) {

    iVar2 = *(int *)(param_1 + 8);

  }

  iVar2 = iVar2 + -1;

  if (*(int *)(*(int *)(param_1 + 4) + iVar2 * 4) == 0) {

    pvVar1 = operator_new(0x1c);

    *(void **)(*(int *)(param_1 + 4) + iVar2 * 4) = pvVar1;

  }

  FUN_00675660(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + iVar2 * 4),param_2);

  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;

  *(int *)(param_1 + 0xc) = iVar2;

  return;

}
