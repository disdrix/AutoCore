// =============================================================================
// FUN_00588cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00588cc0
// Address:   0x00588cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00588cc0 @ 0x00588cc0
// Stable ID: aa_00588cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00570f50, FUN_00588cc0, FUN_005cbc00.
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

void __fastcall FUN_00588cc0(int param_1)



{

  int iVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009a56ab;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *(undefined ***)(param_1 + -0x500) = &PTR_LAB_009d4cc4;

  *(undefined ***)(param_1 + -0x4c0) = &PTR_FUN_009d4c88;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) = &PTR_LAB_009d49c4;

  iVar1 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

  *(int *)(iVar1 + -0x500 + param_1) = iVar1 + -0x4fc;

  local_4 = 1;

  if (*(void **)(param_1 + -0x28) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + -0x28));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x28) = 0;

  FUN_00570f50();

  if (*(uint32_t /* width from decompiler */ **)(param_1 + -0x1a4) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + -0x1a4))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x1a4) = 0;

  local_4 = local_4 & 0xffffff00;

  _eh_vector_destructor_iterator_

            ((void *)(param_1 + -0x1a0),0xc,0x1f,(_func_void_void_ptr *)&DAT_00589930);

  local_4 = 0xffffffff;

  FUN_005cbc00();

  ExceptionList = pvStack_c;

  return;

}
