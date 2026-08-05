// =============================================================================
// FUN_00975450
// -----------------------------------------------------------------------------
// Stable ID: aa_00975450
// Address:   0x00975450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00975450 @ 0x00975450
// Stable ID: aa_00975450
// Embedded strings (evidence for future rename):
//   - "LogEventConnection"
//   - "EventConnection %s: NotifyDelivered - %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×13, while×4, do×2, return×2.
//  - Notable callees: FUN_00430130, FUN_00783aa0, FUN_00783b60, FUN_007845c0, FUN_00975450.
//  - Strings: "LogEventConnection"; "EventConnection %s: NotifyDelivered - %d".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00975450(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  uint uVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  int *piVar9;

  

  if (*(int *)(param_1 + 0x1cc) != 0) {

    FUN_00430130();

  }

  piVar3 = (int *)(param_1 + 0x1e4);

  piVar4 = *(int **)(param_2 + 0x14);

  piVar9 = piVar3;

  do {

    while( true ) {

      piVar2 = piVar4;

      if (piVar2 == (int *)0x0) {

        iVar7 = *piVar3;

        while( true ) {

          if (iVar7 == 0) {

            return;

          }

          iVar7 = *(int *)(param_1 + 0x1f0) + 1;

          if (*(int *)(*piVar3 + 4) != iVar7) break;

          uVar6 = _DAT_00d207d8 & 1;

          *(int *)(param_1 + 0x1f0) = iVar7;

          iVar7 = *(int *)(*piVar3 + 8);

          if (uVar6 == 0) {

            _DAT_00d207d8 = _DAT_00d207d8 | 1;

            DAT_00d207d4 = FUN_00783b60("LogEventConnection");

          }

          if (*(char *)(DAT_00d207d4 + 4) != '\0') {

            DAT_00d179a0 = DAT_00d207d4;

            uVar8 = FUN_007845c0();

            FUN_00783aa0("EventConnection %s: NotifyDelivered - %d",uVar8,

                         *(uint32_t /* width from decompiler */ *)(*piVar3 + 4));

            DAT_00d179a0 = 0;

          }

          (**(code **)(**(int **)*piVar3 + 0x20))(param_1,1);

          piVar9 = (int *)*piVar3;

          piVar4 = (int *)*piVar9;

          if (piVar4 != (int *)0x0) {

            piVar2 = piVar4 + 2;

            *piVar2 = *piVar2 + -1;

            if (*piVar2 == 0) {

              (**(code **)(*piVar4 + 8))();

            }

          }

          _DAT_00afdc70 = _DAT_00afdc70 + -1;

          *piVar9 = (int)DAT_00afdc78;

          DAT_00afdc78 = piVar9;

          *piVar3 = iVar7;

        }

        return;

      }

      piVar4 = (int *)piVar2[2];

      if (((int *)*piVar2)[4] == 0) break;

      (**(code **)(*(int *)*piVar2 + 0x20))(param_1,1);

      piVar5 = (int *)*piVar2;

      if (piVar5 != (int *)0x0) {

        piVar1 = piVar5 + 2;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*piVar5 + 8))();

        }

      }

      _DAT_00afdc70 = _DAT_00afdc70 + -1;

      *piVar2 = (int)DAT_00afdc78;

      DAT_00afdc78 = piVar2;

    }

    if (*piVar9 != 0) {

      do {

        iVar7 = *piVar9;

        if (piVar2[1] <= *(int *)(iVar7 + 4)) break;

        piVar9 = (int *)(iVar7 + 8);

      } while (*(int *)(iVar7 + 8) != 0);

    }

    piVar2[2] = *piVar9;

    *piVar9 = (int)piVar2;

    piVar9 = piVar2 + 2;

  } while( true );

}
