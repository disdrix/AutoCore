// =============================================================================
// FUN_00892be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00892be0
// Address:   0x00892be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00892be0 @ 0x00892be0
// Stable ID: aa_00892be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×8, do×3, while×3, return×2.
//  - Notable callees: FUN_00892890, FUN_00892be0.
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

void __fastcall FUN_00892be0(int *param_1)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 != '\0') && (DAT_00d1b6d8 != 0)) {

    if (*(char *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8) + 0xf5)

        == '\0') {

      iVar3 = *(int *)(DAT_00d1b6d8 + 0xd64);

      param_1[0x143] = iVar3;

      if (((iVar3 < 0) || (2 < iVar3)) || (param_1[iVar3 + 0x14c] == 0)) {

        piVar2 = param_1 + 0x14c;

        iVar3 = 3;

        do {

          if (*piVar2 != 0) {

            (**(code **)(*(int *)*piVar2 + 0x3c8))(0,0);

          }

          (**(code **)(*(int *)*piVar2 + 0x34c))();

          piVar2 = piVar2 + 1;

          iVar3 = iVar3 + -1;

        } while (iVar3 != 0);

      }

      else {

        (**(code **)(*(int *)param_1[iVar3 + 0x14c] + 0x3c8))(1,1);

      }

      iVar3 = 0;

      piVar2 = param_1 + 0x14f;

      do {

        if ((*piVar2 != 0) && (iVar3 != param_1[0x143])) {

          (**(code **)(*(int *)*piVar2 + 4))(0);

        }

        iVar3 = iVar3 + 1;

        piVar2 = piVar2 + 1;

      } while (iVar3 < 3);

      FUN_00892890();

      return;

    }

    param_1 = param_1 + 0x14c;

    iVar3 = 3;

    do {

      if ((*param_1 != 0) && (cVar1 = (**(code **)(*(int *)*param_1 + 0xd8))(), cVar1 != '\0')) {

        (**(code **)(*(int *)*param_1 + 0xd4))(0);

        (**(code **)(*(int *)*param_1 + 0x34c))();

      }

      if (param_1[3] != 0) {

        (**(code **)(*(int *)param_1[3] + 4))(0);

      }

      if (param_1[6] != 0) {

        (**(code **)(*(int *)param_1[6] + 4))(0);

      }

      param_1 = param_1 + 1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

  }

  return;

}
