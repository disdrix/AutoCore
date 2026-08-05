// =============================================================================
// FUN_00857d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00857d80
// Address:   0x00857d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00857d80 @ 0x00857d80
// Stable ID: aa_00857d80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×1.
//  - Notable callees: FUN_00404d80, FUN_00857d80.
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

void __thiscall FUN_00857d80(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  int iVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad224;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(int *)(param_1 + 0x6a8) = param_2;

  if (param_2 < 1) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x6a8) = 0x1e;

  }

  *(int *)(param_1 + 0x6ac) = (*(int *)(param_1 + 0x6a8) + 1) * 3;

  if (*(void **)(param_1 + 0x64c) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x64c));

  }

  iVar3 = *(int *)(param_1 + 0x6ac);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x64c) = 0;

  puVar1 = operator_new__(iVar3 * 0x18);

  local_4 = 0;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_00404d80(puVar1,0x18,iVar3,&LAB_00413510);

  }

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x64c) = puVar1;

  for (uVar2 = (uint)(*(int *)(param_1 + 0x6ac) * 0x18) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *puVar1 = 0;

    puVar1 = puVar1 + 1;

  }

  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {

    *(uint8_t *)puVar1 = 0;

    puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

  }

  ExceptionList = local_c;

  return;

}
