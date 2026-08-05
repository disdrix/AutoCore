// =============================================================================
// FUN_00496810
// -----------------------------------------------------------------------------
// Stable ID: aa_00496810
// Address:   0x00496810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00496810 @ 0x00496810
// Stable ID: aa_00496810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_004073a0, FUN_00410420, FUN_00496750, FUN_00496810, FUN_0079a110.
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

void __fastcall FUN_00496810(int param_1)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  char cVar4;

  int *piVar5;

  float10 fVar6;

  int *local_4;

  

  FUN_00410420(0,0);

  piVar5 = *(int **)(param_1 + 0x1c);

  if (piVar5 != *(int **)(param_1 + 0x20)) {

    do {

      piVar1 = (int *)*piVar5;

      if ((((*(char *)(param_1 + 0x4e) != '\0') ||

           (*(int *)(*(int *)(*(int *)(piVar1[1] + 4) + 0xac + (int)piVar1) + 0x38) != 0x36)) &&

          ((*(char *)(param_1 + 0x4f) != '\0' ||

           (*(int *)(*(int *)(*(int *)(piVar1[1] + 4) + 0xac + (int)piVar1) + 0x38) != 0x38)))) &&

         (local_4 = piVar1, cVar4 = FUN_00496750(piVar1), cVar4 == '\0')) {

        if (((char)piVar1[3] != '\0') && (piVar1[2] != 0)) {

          iVar2 = *piVar1;

          fVar6 = (float10)FUN_0079a110();

          (**(code **)(iVar2 + 0x28))((float)fVar6);

          (**(code **)(*(int *)piVar1[2] + 0x10))(3);

          (**(code **)(*(int *)piVar1[2] + 0x34))();

        }

        iVar2 = *(int *)(param_1 + 0x9c);

        if ((iVar2 == 0) ||

           ((uint)(*(int *)(param_1 + 0xa4) - iVar2 >> 2) <=

            (uint)(*(int *)(param_1 + 0xa0) - iVar2 >> 2))) {

          FUN_004073a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xa0),1,&local_4);

        }

        else {

          piVar3 = *(int **)(param_1 + 0xa0);

          *piVar3 = (int)piVar1;

          *(int **)(param_1 + 0xa0) = piVar3 + 1;

        }

      }

      piVar5 = piVar5 + 1;

    } while (piVar5 != *(int **)(param_1 + 0x20));

  }

  return;

}
