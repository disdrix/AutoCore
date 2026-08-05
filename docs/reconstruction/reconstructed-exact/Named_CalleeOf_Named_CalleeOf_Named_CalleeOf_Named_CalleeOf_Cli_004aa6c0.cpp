// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004aa6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004aa6c0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa
// Address:   0x004aa6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: if×9, return×4, do×3, while×3.
//  - Notable callees: FUN_004a9800×3, FUN_0096ef70×3, FUN_0096efd0×3, FUN_0096f3e0×3, FUN_00989e00×3, FUN_004aa6c0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004aa6c0(int param_1)



{

  char cVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *local_320;

  uint8_t local_31c [4];

  char local_318 [260];

  char local_214 [260];

  char local_110 [260];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a12b2;

  local_c = ExceptionList;

  pvVar2 = *(void **)(param_1 + 0x3f0);

  if (pvVar2 != (void *)0x0) {

    ExceptionList = &local_c;

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  pvVar2 = *(void **)(param_1 + 0x3f4);

  if (pvVar2 != (void *)0x0) {

    ExceptionList = &local_c;

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  pvVar2 = *(void **)(param_1 + 0x3f8);

  if (pvVar2 != (void *)0x0) {

    ExceptionList = &local_c;

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  ExceptionList = &local_c;

  local_320 = operator_new(4);

  local_4 = 0;

  if (local_320 == (char *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0096ef70();

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3f0) = uVar3;

  local_320 = operator_new(4);

  local_4 = 1;

  if (local_320 == (char *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0096ef70();

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3f4) = uVar3;

  local_320 = operator_new(4);

  local_4 = 2;

  if (local_320 == (char *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0096ef70();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3f8) = uVar3;

  local_4 = 0xffffffff;

  FUN_004a9800(0,*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x340) + 0x78) + 0x154),local_110);

  FUN_004a9800(2,*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x340) + 0x78) + 0x154),local_214);

  FUN_004a9800(1,*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x340) + 0x78) + 0x154),local_318);

  local_320 = local_110;

  do {

    cVar1 = *local_320;

    local_320 = local_320 + 1;

  } while (cVar1 != '\0');

  local_320 = local_320 + -(int)(local_110 + 1);

  if (local_320 != (char *)0x0) {

    FUN_00989e00(local_31c,local_214);

    FUN_0096f3e0(local_31c,0);

  }

  local_320 = local_318;

  do {

    cVar1 = *local_320;

    local_320 = local_320 + 1;

  } while (cVar1 != '\0');

  local_320 = local_320 + -(int)(local_318 + 1);

  if (local_320 != (char *)0x0) {

    FUN_00989e00(local_31c,local_318);

    FUN_0096f3e0(local_31c,0);

  }

  local_320 = local_214;

  do {

    cVar1 = *local_320;

    local_320 = local_320 + 1;

  } while (cVar1 != '\0');

  local_320 = local_320 + -(int)(local_214 + 1);

  if (local_320 != (char *)0x0) {

    FUN_00989e00(&local_320,local_110);

    FUN_0096f3e0(&local_320,0);

  }

  ExceptionList = local_c;

  return;

}
