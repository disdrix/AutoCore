// =============================================================================
// FUN_008e1cb0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e1cb0
// Address:   0x008e1cb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e1cb0 @ 0x008e1cb0
// Stable ID: aa_008e1cb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, do×2, while×2, goto×1.
//  - Notable callees: FUN_00791f30×3, FUN_008e1bb0, FUN_008e1cb0, FUN_0092cc60.
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

void __thiscall FUN_008e1cb0(int *param_1,float param_2)



{

  float fVar1;

  float fVar2;

  char cVar3;

  int *piVar4;

  int iVar5;

  

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  fVar2 = DAT_00a0f704;

  if ((cVar3 != '\0') && (DAT_00d1b6d8 != 0)) {

    fVar1 = (float)param_1[0x189];

    param_1[0x189] = (int)(fVar1 + param_2);

    if (fVar2 < fVar1 + param_2) {

      param_1[0x189] = 0;

      FUN_008e1bb0();

      piVar4 = param_1 + 0x149;

      if (0 < *(short *)(DAT_00d1b6d8 + 0x580)) {

        cVar3 = (**(code **)(*(int *)param_1[0x149] + 0xd8))();

        if (cVar3 == '\0') {

          iVar5 = 0x10;

          do {

            if (*piVar4 != 0) {

              (**(code **)(*(int *)*piVar4 + 0xd4))(1);

              (**(code **)(*(int *)*piVar4 + 0x34c))();

            }

            piVar4 = piVar4 + 1;

            iVar5 = iVar5 + -1;

          } while (iVar5 != 0);

          FUN_00791f30(param_2);

          return;

        }

LAB_008e1d73:

        FUN_00791f30(param_2);

        return;

      }

      cVar3 = (**(code **)(*(int *)param_1[0x149] + 0xd8))();

      if (cVar3 == '\0') goto LAB_008e1d73;

      iVar5 = 0x10;

      do {

        if (*piVar4 != 0) {

          (**(code **)(*(int *)*piVar4 + 0xd4))(0);

          (**(code **)(*(int *)*piVar4 + 0x34c))();

        }

        piVar4 = piVar4 + 1;

        iVar5 = iVar5 + -1;

      } while (iVar5 != 0);

      FUN_0092cc60();

    }

    FUN_00791f30(param_2);

  }

  return;

}
