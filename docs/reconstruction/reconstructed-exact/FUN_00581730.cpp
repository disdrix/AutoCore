// =============================================================================
// FUN_00581730
// -----------------------------------------------------------------------------
// Stable ID: aa_00581730
// Address:   0x00581730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00581730 @ 0x00581730
// Stable ID: aa_00581730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, do×1, while×1.
//  - Notable callees: FUN_00581730, FUN_0074ecf0.
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

void __thiscall FUN_00581730(int param_1,char param_2)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  

  if (param_2 != '\0') {

    *(uint8_t *)(param_1 + 0xc) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0xffffffff;

  }

  piVar3 = (int *)(param_1 + 0x2c);

  iVar2 = 0x13;

  do {

    if (*piVar3 != 0) {

      if (*(int **)(param_1 + 0x24) != (int *)0x0) {

        (**(code **)(**(int **)(param_1 + 0x24) + 0x10))(*piVar3);

      }

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

    if (iVar2 == 0) {

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x28) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x28))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x24) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x24))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

      return;

    }

  } while( true );

}
