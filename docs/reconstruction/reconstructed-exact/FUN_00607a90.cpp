// =============================================================================
// FUN_00607a90
// -----------------------------------------------------------------------------
// Stable ID: aa_00607a90
// Address:   0x00607a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00607a90 @ 0x00607a90
// Stable ID: aa_00607a90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, while×1, if×1.
//  - Notable callees: FUN_005afc80×2, FUN_004cd5e0, FUN_005cb480, FUN_00607a90, _eh_vector_destructor_iterator_.
//  - Return sites: 2.

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

void __fastcall FUN_00607a90(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009a8176;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(undefined ***)(param_1 + -0x260) = &PTR_FUN_009debb4;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x25c) + 4) + -0x25c + param_1) = &PTR_LAB_009de8ec;

  iVar2 = *(int *)(*(int *)(param_1 + -0x25c) + 4);

  *(int *)(iVar2 + -0x260 + param_1) = iVar2 + -0x25c;

  iVar2 = *(int *)(*(int *)(param_1 + -0x25c) + 4);

  local_4 = 2;

  FUN_005afc80(*(uint32_t /* width from decompiler */ *)(param_1 + -0x90),*(uint32_t /* width from decompiler */ *)(iVar2 + -0xfc + param_1),

               *(uint32_t /* width from decompiler */ *)(iVar2 + -0xf8 + param_1));

  puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + -0x170);

  iVar2 = 4;

  do {

    iVar1 = *(int *)(*(int *)(param_1 + -0x25c) + 4);

    FUN_005afc80(*puVar3,*(uint32_t /* width from decompiler */ *)(iVar1 + -0xfc + param_1),

                 *(uint32_t /* width from decompiler */ *)(iVar1 + -0xf8 + param_1));

    puVar3 = puVar3 + 0x12;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  FUN_004cd5e0();

  if (*(void **)(param_1 + -0x38) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x38));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x30) = 0;

  local_4 = local_4 & 0xffffff00;

  _eh_vector_destructor_iterator_((void *)(param_1 + -0x1b0),0x48,4,FUN_00608a10);

  local_4 = 0xffffffff;

  FUN_005cb480();

  ExceptionList = local_c;

  return;

}
