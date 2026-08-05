// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×11, while×2, return×2, for×1.
//  - Notable callees: FUN_007a4480×2, FUN_00411e10, FUN_00791f30.
//  - Strings: "HashError:TraverseToNext, not locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00791f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00791f30
// Address:   0x00791f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_VOG_DEBUG_STOP_00791f30(int *param_1,float param_2)



{

  int iVar1;

  char cVar2;

  int iVar3;

  int *piVar4;

  float fVar5;

  

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar2 != '\0') && (cVar2 = (**(code **)(*param_1 + 0xd0))(), cVar2 != '\0')) {

    if ((g_flZero <= (float)param_1[299]) &&

       (fVar5 = (float)param_1[299] + param_2, param_1[299] = (int)fVar5,

       (float)param_1[300] <= fVar5)) {

      if ((int *)param_1[0x12e] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x12e] + 0x374))(0,0);

      }

      param_1[299] = DAT_00aaa668;

    }

    cVar2 = (**(code **)(*param_1 + 0xf8))();

    if (cVar2 != '\0') {

      (**(code **)(*param_1 + 0x348))(param_2);

    }

    if (param_1[0x130] != 0) {

      iVar3 = 0;

      FUN_00411e10();

      while( true ) {

        iVar1 = param_1[0x130];

        if (*(char *)(iVar1 + 0x1d) == '\0') {

          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        if (iVar3 == 0) {

          iVar3 = *(int *)(iVar1 + 0x14);

        }

        else {

          iVar3 = *(int *)(iVar3 + 0x14);

        }

        if (iVar3 == 0) {

          piVar4 = (int *)0x0;

        }

        else {

          piVar4 = *(int **)(iVar3 + 8);

        }

        if (piVar4 == (int *)0x0) break;

        cVar2 = (**(code **)(*piVar4 + 0xd0))();

        if (cVar2 != '\0') {

          (**(code **)(*piVar4 + 0x33c))(param_2);

        }

      }

      *(uint8_t *)(param_1[0x130] + 0x1d) = 0;

    }

    iVar3 = param_1[0x139];

    while (iVar3 != 0) {

      (**(code **)(*param_1 + 0xb4))(*(uint32_t /* width from decompiler */ *)(*(int *)param_1[0x138] + 8));

      piVar4 = *(int **)param_1[0x138];

      if (piVar4 != (int *)param_1[0x138]) {

        *(int *)piVar4[1] = *piVar4;

        *(int *)(*piVar4 + 4) = piVar4[1];

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar4);

      }

      iVar3 = param_1[0x139];

    }

  }

  return;

}
