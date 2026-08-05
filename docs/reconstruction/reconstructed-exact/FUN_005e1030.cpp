// =============================================================================
// FUN_005e1030
// -----------------------------------------------------------------------------
// Stable ID: aa_005e1030
// Address:   0x005e1030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e1030 @ 0x005e1030
// Stable ID: aa_005e1030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×4, return×4, for×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_005e07d0, FUN_005e1030, FUN_007a41f0.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_005e1030(int param_1)



{

  void *pvVar1;

  int iVar2;

  void **ppvVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int in_stack_00000024;

  uint32_t /* width from decompiler */ auStackY_54 [8];

  uint8_t *puStackY_34;

  undefined *puStackY_30;

  uint8_t local_1c [4];

  void *local_18;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a7478;

  ppvVar3 = &local_c;

  local_c = ExceptionList;

  local_18 = (void *)0x0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  if (in_stack_00000024 == 0) {

    puStackY_30 = (undefined *)(param_1 + 0x8700c);

  }

  else {

    if (in_stack_00000024 != 1) {

      return 0xffffffff;

    }

    puStackY_30 = (undefined *)(param_1 + 0xc);

  }

  puStackY_34 = local_1c;

  puVar4 = auStackY_54;

  for (iVar2 = 8; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4), iVar2 != 0;

      iVar2 = iVar2 + -1) {

    *puVar4 = *(uint32_t /* width from decompiler */ *)register0x00000010;

    puVar4 = puVar4 + 1;

  }

  ExceptionList = ppvVar3;

  FUN_005e07d0();

  pvVar1 = local_18;

  if (local_18 == (void *)0x0) {

    ExceptionList = local_c;

    return 0xffffffff;

  }

  if (local_14 - (int)local_18 >> 2 != 0) {

    CVOGReaction_RandomUnitScalar();

    FUN_007a41f0();

                    /* WARNING: Subroutine does not return */

    puStackY_30 = &UNK_005e10e5;

    operator_delete(pvVar1);

  }

                    /* WARNING: Subroutine does not return */

  puStackY_30 = &UNK_005e10af;

  operator_delete(local_18);

}
