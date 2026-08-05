// =============================================================================
// FUN_009755d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009755d0
// Address:   0x009755d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009755d0 @ 0x009755d0
// Stable ID: aa_009755d0
// Embedded strings (evidence for future rename):
//   - "LogEventConnection"
//   - "EventConnection %s: DroppedGuaranteed - %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×13, do×2, while×2, return×1, goto×1.
//  - Notable callees: FUN_00430170, FUN_00783aa0, FUN_00783b60, FUN_007845c0, FUN_009755d0.
//  - Strings: "LogEventConnection"; "EventConnection %s: DroppedGuaranteed - %d".
//  - Return sites: 1.

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



void __thiscall FUN_009755d0(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piVar6;

  int *piVar7;

  

  if (*(int *)(param_1 + 0x1cc) != 0) {

    FUN_00430170();

  }

  piVar6 = (int *)(param_1 + 0x1d0);

  piVar7 = *(int **)(param_2 + 0x14);

joined_r0x009755f6:

  do {

    piVar4 = piVar7;

    if (piVar4 == (int *)0x0) {

      return;

    }

    iVar2 = ((int *)*piVar4)[4];

    if (iVar2 == 0) {

      if ((_DAT_00d207e0 & 1) == 0) {

        _DAT_00d207e0 = _DAT_00d207e0 | 1;

        DAT_00d207dc = FUN_00783b60("LogEventConnection");

      }

      if (*(char *)(DAT_00d207dc + 4) != '\0') {

        DAT_00d179a0 = DAT_00d207dc;

        uVar5 = FUN_007845c0();

        FUN_00783aa0("EventConnection %s: DroppedGuaranteed - %d",uVar5,piVar4[1]);

        DAT_00d179a0 = 0;

      }

      if (*piVar6 != 0) {

        do {

          iVar2 = *piVar6;

          if (piVar4[1] <= *(int *)(iVar2 + 4)) break;

          piVar6 = (int *)(iVar2 + 8);

        } while (*(int *)(iVar2 + 8) != 0);

      }

      iVar2 = *piVar6;

      piVar7 = (int *)piVar4[2];

      piVar4[2] = iVar2;

      if (iVar2 == 0) {

        *(int **)(param_1 + 0x1d4) = piVar4;

      }

      *piVar6 = (int)piVar4;

      piVar6 = piVar4 + 2;

    }

    else {

      if (iVar2 != 1) {

        piVar7 = piVar4;

        if (iVar2 == 2) {

          (**(code **)(*(int *)*piVar4 + 0x20))(param_1,0);

          piVar3 = (int *)*piVar4;

          piVar7 = (int *)piVar4[2];

          if (piVar3 != (int *)0x0) {

            piVar1 = piVar3 + 2;

            *piVar1 = *piVar1 + -1;

            if (*piVar1 == 0) {

              (**(code **)(*piVar3 + 8))();

            }

          }

          _DAT_00afdc70 = _DAT_00afdc70 + -1;

          *piVar4 = (int)DAT_00afdc78;

          DAT_00afdc78 = piVar4;

        }

        goto joined_r0x009755f6;

      }

      piVar7 = (int *)piVar4[2];

      piVar4[2] = *(int *)(param_1 + 0x1d8);

      *(int **)(param_1 + 0x1d8) = piVar4;

      if (piVar4[2] == 0) {

        *(int **)(param_1 + 0x1dc) = piVar4;

      }

    }

    *(int *)(param_1 + 0x204) = *(int *)(param_1 + 0x204) + 1;

  } while( true );

}
