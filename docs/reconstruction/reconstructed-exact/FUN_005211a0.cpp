// =============================================================================
// FUN_005211a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005211a0
// Address:   0x005211a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005211a0 @ 0x005211a0
// Stable ID: aa_005211a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_004c96c0, FUN_005211a0.
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

void __fastcall FUN_005211a0(int param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  

  piVar3 = (int *)(param_1 + 0x63c);

  iVar2 = 9;

  do {

    if ((uint32_t /* width from decompiler */ *)*piVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)*piVar3)(1);

    }

    *piVar3 = 0;

    piVar3 = piVar3 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  FUN_004c96c0();

  if ((*(int *)(param_1 + 0x240) != 0) &&

     (pvVar1 = *(void **)(*(int *)(param_1 + 0x240) + 0x78), pvVar1 != (void *)0x0)) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x240) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x240))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x240) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x23c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x23c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x23c) = 0;

  return;

}
