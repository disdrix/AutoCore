// =============================================================================
// FUN_00890e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00890e20
// Address:   0x00890e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00890e20 @ 0x00890e20
// Stable ID: aa_00890e20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, do×1, while×1.
//  - Notable callees: FUN_007916e0, FUN_00890e20, GetTickCount.
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



void __thiscall FUN_00890e20(int param_1,uint32_t /* width from decompiler */ param_2)



{

  DWORD DVar1;

  int iVar2;

  ushort uVar3;

  int *piVar4;

  float fVar5;

  

  FUN_007916e0(param_2);

  if ((char)param_2 != '\0') {

    if (*(int *)(param_1 + 0x5ac) == 3) {

      piVar4 = (int *)(param_1 + 0x554);

      uVar3 = 0;

      do {

        if (*(ushort *)(param_1 + 0x598) <= uVar3) {

          if (piVar4[-4] != 0) {

            (**(code **)(*(int *)piVar4[-4] + 0xcc))(0);

          }

          if (*piVar4 != 0) {

            (**(code **)(*(int *)*piVar4 + 0xcc))(0);

          }

        }

        uVar3 = uVar3 + 1;

        piVar4 = piVar4 + 1;

      } while (uVar3 < 4);

      return;

    }

    if (((*(int *)(param_1 + 0x5ac) == 2) && (*(int *)(param_1 + 0x530) != 0)) &&

       (*(float *)(param_1 + 0x540) != 0.0)) {

      if (*(float *)(param_1 + 0x540) == 0.0) {

        fVar5 = *(float *)(param_1 + 0x53c);

      }

      else {

        DVar1 = GetTickCount();

        iVar2 = DVar1 - *(int *)(param_1 + 0x5a0);

        fVar5 = (float)iVar2;

        if (iVar2 < 0) {

          fVar5 = fVar5 + _DAT_00aaa5dc;

        }

        fVar5 = (fVar5 * g_flMsToSeconds_Inferred) / *(float *)(param_1 + 0x540);

        if (g_flOne < fVar5) {

          fVar5 = g_flOne;

        }

      }

      (**(code **)(**(int **)(param_1 + 0x530) + 0x3b0))(fVar5);

      (**(code **)(**(int **)(param_1 + 0x530) + 0x3ac))(0x3f800000);

      (**(code **)(**(int **)(param_1 + 0x530) + 0x34c))();

    }

  }

  return;

}
