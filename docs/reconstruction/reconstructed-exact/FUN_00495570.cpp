// =============================================================================
// FUN_00495570
// -----------------------------------------------------------------------------
// Stable ID: aa_00495570
// Address:   0x00495570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00495570 @ 0x00495570
// Stable ID: aa_00495570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00495570, FUN_004baf50.
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

void __fastcall FUN_00495570(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int *piVar3;

  int *piVar4;

  

  piVar4 = (int *)**(int **)(param_1 + 0x10);

  if (piVar4 != *(int **)(param_1 + 0x10)) {

    do {

      piVar3 = (int *)FUN_004baf50(piVar4 + 2);

      if (piVar3 != (int *)0x0) {

        (**(code **)(*(int *)(*(int *)(piVar3[1] + 4) + 4 + (int)piVar3) + 0xb4))();

        *(uint8_t *)((int)piVar3 + 0xf) = 0;

        (**(code **)(*piVar3 + 0x18))(0);

        (**(code **)(*piVar3 + 0x18))(1);

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)*(int *)(param_1 + 0x10));

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x10);

  pvVar2 = (void *)*puVar1;

  *puVar1 = puVar1;

  *(int *)(*(int *)(param_1 + 0x10) + 4) = *(int *)(param_1 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  if (pvVar2 == *(void **)(param_1 + 0x10)) {

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar2);

}
