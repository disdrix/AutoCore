// =============================================================================
// FUN_00586ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00586ac0
// Address:   0x00586ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00586ac0 @ 0x00586ac0
// Stable ID: aa_00586ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×10, return×6.
//  - Notable callees: FUN_00988860×6, FUN_007567b0×5, FUN_00988710×4, FUN_00586ac0, FUN_0096f510.
//  - Return sites: 6.

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

void __fastcall FUN_00586ac0(int param_1)



{

  void *pvVar1;

  

  if (*(char *)(param_1 + 0x10) != '\0') {

    FUN_007567b0(0,1);

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x3c) + 0xc0) = 7;

    *(uint8_t *)(param_1 + 0x10) = 0;

  }

  FUN_00988860(*(uint32_t /* width from decompiler */ *)(param_1 + 0x3c));

  FUN_00988860(*(uint32_t /* width from decompiler */ *)(param_1 + 0x24));

  FUN_00988860(*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c));

  FUN_00988860(*(uint32_t /* width from decompiler */ *)(param_1 + 0x34));

  FUN_00988860(*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c));

  FUN_00988860(*(uint32_t /* width from decompiler */ *)(param_1 + 0x3c));

  FUN_007567b0(0,0);

  FUN_007567b0(0,0);

  FUN_007567b0(0,0);

  FUN_007567b0(0,0);

  pvVar1 = *(void **)(param_1 + 0x20);

  if (pvVar1 != (void *)0x0) {

    FUN_00988710();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  pvVar1 = *(void **)(param_1 + 0x28);

  if (pvVar1 != (void *)0x0) {

    FUN_00988710();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  pvVar1 = *(void **)(param_1 + 0x30);

  if (pvVar1 != (void *)0x0) {

    FUN_00988710();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  pvVar1 = *(void **)(param_1 + 0x38);

  if (pvVar1 != (void *)0x0) {

    FUN_00988710();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x3c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x3c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x24) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x24))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x2c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x2c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x34) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x34))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  pvVar1 = *(void **)(param_1 + 0x40);

  if (pvVar1 != (void *)0x0) {

    FUN_0096f510();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  return;

}
