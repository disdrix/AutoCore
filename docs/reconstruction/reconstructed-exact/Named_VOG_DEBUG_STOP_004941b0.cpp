// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: ROUND×2, FUN_004941b0, FUN_007a4480, _eh_vector_constructor_iterator_, _eh_vector_destructor_iterator_.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_004941b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004941b0
// Address:   0x004941b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_VOG_DEBUG_STOP_004941b0(int param_1,int param_2)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0bbb;

  local_c = ExceptionList;

  pvVar1 = *(void **)(param_1 + 0x28);

  piVar5 = (int *)0x0;

  ExceptionList = &local_c;

  if (pvVar1 != (void *)0x0) {

    ExceptionList = &local_c;

    _eh_vector_destructor_iterator_(pvVar1,0x28,*(int *)((int)pvVar1 + -4),FUN_005b8000);

    operator_delete__((void *)((int)pvVar1 + -4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  if (*(int *)(param_2 + 0xe4f8) == 0) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    ExceptionList = local_c;

    return;

  }

  DAT_00aefa50 = DAT_00a11088;

  if (*(char *)(param_2 + 0xf5) == '\0') {

    DAT_00aefa50 = DAT_00aaa8a4;

  }

  iVar4 = (int)ROUND(((float)*(int *)(*(int *)(param_2 + 0xe4f8) + 0x10) / DAT_00aefa50) *

                     *(float *)(*(int *)(param_2 + 0xe4f8) + 0x18)) + 1;

  *(int *)(param_1 + 4) = iVar4;

  iVar2 = (int)ROUND(((float)*(int *)(*(int *)(param_2 + 0xe4f8) + 0x14) / DAT_00aefa50) *

                     *(float *)(*(int *)(param_2 + 0xe4f8) + 0x18)) + 1;

  *(int *)(param_1 + 8) = iVar2;

  iVar2 = iVar2 * iVar4;

  piVar3 = operator_new__(iVar2 * 0x28 + 4);

  local_4 = 0;

  if (piVar3 != (int *)0x0) {

    piVar5 = piVar3 + 1;

    *piVar3 = iVar2;

    _eh_vector_constructor_iterator_(piVar5,0x28,iVar2,FUN_005b7db0,FUN_005b8000);

  }

  *(int **)(param_1 + 0x28) = piVar5;

  ExceptionList = local_c;

  return;

}
