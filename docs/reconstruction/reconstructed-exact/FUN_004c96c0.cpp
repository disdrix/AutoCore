// =============================================================================
// FUN_004c96c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c96c0
// Address:   0x004c96c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c96c0 @ 0x004c96c0
// Stable ID: aa_004c96c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, do×1, while×1.
//  - Notable callees: FUN_004c92f0, FUN_004c96c0, FUN_0074ecf0, FUN_0096d550, thunk_FUN_00584290.
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

void __fastcall FUN_004c96c0(int param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  

  if (*(int *)(param_1 + 0x248) != 0) {

    piVar3 = (int *)(param_1 + 0x250);

    iVar2 = 0x13;

    do {

      if (*piVar3 != 0) {

        (**(code **)(**(int **)(param_1 + 0x248) + 0x10))(*piVar3);

        pvVar1 = (void *)*piVar3;

        if (pvVar1 != (void *)0x0) {

          FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        *piVar3 = 0;

      }

      piVar3 = piVar3 + 1;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x24c) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x24c))(1);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x24c) = 0;

    }

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x248) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x248))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x248) = 0;

  }

  FUN_004c92f0();

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x244) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x244))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x244) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x23c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x23c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x23c) = 0;

  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0x240) != 0)) {

    FUN_0096d550(*(int *)(param_1 + 0x240));

  }

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x240) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x240))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x240) = 0;

  thunk_FUN_00584290();

  return;

}
