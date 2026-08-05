// =============================================================================
// FUN_004c9f80
// -----------------------------------------------------------------------------
// Stable ID: aa_004c9f80
// Address:   0x004c9f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c9f80 @ 0x004c9f80
// Stable ID: aa_004c9f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×6, return×5.
//  - Notable callees: FUN_004c9f80, FUN_004cbaa0, FUN_00564200, FUN_0096df50.
//  - Return sites: 5.

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

void __fastcall FUN_004c9f80(int param_1)



{

  int iVar1;

  uint8_t auStack_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a1d88;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *(undefined ***)(param_1 + -0x500) = &PTR_LAB_009cbe74;

  *(undefined ***)(param_1 + -0x4c0) = &PTR_CVOGCreature_SetupGraphics_009cbe38;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) = &PTR_LAB_009cbb74;

  iVar1 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

  *(int *)(iVar1 + -0x500 + param_1) = iVar1 + -0x4fc;

  local_4 = 6;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x2b0) = 0;

  if (*(int *)(param_1 + -0x2a8) != 0) {

    FUN_00564200((int *)(param_1 + -0x500));

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x2a8) = 0;

  }

  if (*(uint32_t /* width from decompiler */ **)(param_1 + -0x408) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + -0x408))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x408) = 0;

  (**(code **)(*(int *)(param_1 + -0x500) + 4))();

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) + 0xfc))();

  (**(code **)(*(int *)(param_1 + -0x4c0) + 4))();

  local_4._0_1_ = 5;

  FUN_0096df50();

  if (*(void **)(param_1 + -0x208) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x208));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x208) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x204) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x200) = 0;

  if (*(void **)(param_1 + -0x21c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x21c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x21c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x218) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x214) = 0;

  if (*(void **)(param_1 + -0x334) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x334));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x334) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x330) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x32c) = 0;

  if (*(void **)(param_1 + -0x344) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + -0x344));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x344) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x340) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x33c) = 0;

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_004cbaa0(auStack_10,**(uint32_t /* width from decompiler */ **)(param_1 + -0x3a8),*(uint32_t /* width from decompiler */ **)(param_1 + -0x3a8));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + -0x3a8));

}
