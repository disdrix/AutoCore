// =============================================================================
// FUN_0056d020
// -----------------------------------------------------------------------------
// Stable ID: aa_0056d020
// Address:   0x0056d020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056d020 @ 0x0056d020
// Stable ID: aa_0056d020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_004b99c0, FUN_0056bf70, FUN_0056d020, FUN_005cb480.
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

void __fastcall FUN_0056d020(int param_1)



{

  int iVar1;

  void *pvVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a4da6;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *(undefined ***)(param_1 + -0x150) = &PTR_LAB_009d32d4;

  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x14c + param_1) = &PTR_LAB_009d300c;

  iVar1 = *(int *)(*(int *)(param_1 + -0x14c) + 4);

  *(int *)(iVar1 + -0x150 + param_1) = iVar1 + -0x14c;

  local_4 = 0;

  if (*(int *)(param_1 + -0x14) != 0) {

    FUN_0056bf70();

    if (*(uint32_t /* width from decompiler */ **)(param_1 + -0x14) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + -0x14))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x14) = 0;

  }

  pvVar2 = *(void **)(param_1 + -0x94);

  if (pvVar2 != (void *)0x0) {

    FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x94) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + -0x98) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + -0x98))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x98) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + -0x90) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + -0x90))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x90) = 0;

  local_4 = 0xffffffff;

  FUN_005cb480();

  ExceptionList = pvStack_c;

  return;

}
