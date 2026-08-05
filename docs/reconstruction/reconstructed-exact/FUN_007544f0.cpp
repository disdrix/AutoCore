// =============================================================================
// FUN_007544f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007544f0
// Address:   0x007544f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007544f0 @ 0x007544f0
// Stable ID: aa_007544f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×8, return×3.
//  - Notable callees: FUN_007544f0, FUN_0075d6f0, FUN_0075de80, FUN_0075f560, FUN_00970a90, FUN_00971050, FUN_00971180.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_007544f0(int param_1)



{

  void *pvVar1;

  int *piVar2;

  

  *(uint8_t *)(param_1 + 4) = 0;

  FUN_0075de80(0,0x41200000);

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x2c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x2c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  piVar2 = DAT_00d1ecac;

  if (DAT_00d1ecac != (int *)0x0) {

    DAT_00d1ecac[1] = DAT_00d1ecac[1] + -1;

    if (piVar2[1] == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    DAT_00d1ecac = (int *)0x0;

  }

  pvVar1 = *(void **)(param_1 + 0x28);

  if (pvVar1 != (void *)0x0) {

    FUN_0075f560();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0xffffffff;

  if (*(int *)(param_1 + 0xd4) != 0) {

    FUN_00970a90();

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0xd4) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0xd4))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd4) = 0;

  }

  FUN_0075d6f0();

  if (*(int *)(param_1 + 0x9c) != 0) {

    FUN_00971050();

    pvVar1 = *(void **)(param_1 + 0x9c);

    if (pvVar1 != (void *)0x0) {

      FUN_00971180(pvVar1);

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = 0;

  }

  return 0;

}
