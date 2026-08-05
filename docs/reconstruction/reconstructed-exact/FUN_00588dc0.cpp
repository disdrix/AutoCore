// =============================================================================
// FUN_00588dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00588dc0
// Address:   0x00588dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00588dc0 @ 0x00588dc0
// Stable ID: aa_00588dc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: CONCAT31, FUN_00518940, FUN_005878b0, FUN_00588dc0, FUN_005c82a0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00588dc0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a56fa;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    param_1[1] = &DAT_009d4d14;

    param_1[0x11] = &DAT_009d4d0c;

    FUN_00518940();

    local_4 = 0;

  }

  FUN_005c82a0(0);

  *param_1 = &PTR_LAB_009d4cc4;

  param_1[0x10] = &PTR_FUN_009d4c88;

  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009d49c4;

  local_4 = 1;

  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x4fc;

  _eh_vector_constructor_iterator_

            (param_1 + 0xd8,0xc,0x1f,FUN_00589b00,(_func_void_void_ptr *)&DAT_00589930);

  local_4 = CONCAT31(local_4._1_3_,2);

  param_1[0x135] = 0;

  puVar1 = param_1 + 0x41;

  iVar2 = 0x1e;

  do {

    *(uint8_t *)(puVar1 + 3) = 0;

    *(uint8_t *)puVar1 = 0;

    puVar1[1] = 0;

    puVar1[2] = 0;

    puVar1[4] = 0xffffffff;

    puVar1 = puVar1 + 5;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  *(uint8_t *)(param_1 + 0x40) = 0;

  param_1[0xd7] = 0;

  param_1[0x136] = 0;

  param_1[0x137] = 0;

  param_1[0x138] = 0xf;

  *(uint8_t *)(param_1 + 0x139) = 0;

  *(uint8_t *)((int)param_1 + 0x4e5) = 0;

  *(uint8_t *)((int)param_1 + 0x4e6) = 0;

  FUN_005878b0();

  ExceptionList = local_c;

  return param_1;

}
