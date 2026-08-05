// =============================================================================
// FUN_0073b4f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073b4f0
// Address:   0x0073b4f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073b4f0 @ 0x0073b4f0
// Stable ID: aa_0073b4f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×11, return×4, goto×2, while×1, for×1.
//  - Notable callees: FUN_00464780, FUN_0073b4f0, FUN_0074e9d0, FUN_0074ebe0, FUN_0074ecf0, FUN_0095d580, FUN_00972cc0.
//  - Return sites: 4.

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

void __thiscall FUN_0073b4f0(int *param_1,float param_2)



{

  float fVar1;

  int *piVar2;

  int *piVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int extraout_ECX;

  int iVar7;

  bool bVar8;

  int *piVar9;

  float local_104;

  uint8_t auStack_f8 [244];

  

  fVar1 = (float)param_1[2];

  param_1[2] = (int)param_2;

  if (DAT_00aaa664 < param_2 - fVar1) {

    piVar2 = (int *)param_1[4];

    piVar3 = (int *)*piVar2;

    local_104 = DAT_00aaa664;

    while (piVar3 != piVar2) {

      iVar7 = piVar3[5];

      if ((piVar3[2] & 2U) == 0) {

LAB_0073b60e:

        piVar9 = piVar3;

        if (iVar7 != 0) {

          FUN_0074ebe0(param_2);

        }

      }

      else {

        local_104 = (float)piVar3[4] * (param_2 - fVar1) + *(float *)(iVar7 + 0x10);

        if (0.0 < (float)piVar3[4]) {

          if ((float)piVar3[3] <= local_104) goto LAB_0073b583;

        }

        else if (local_104 <= (float)piVar3[3]) {

LAB_0073b583:

          local_104 = (float)piVar3[3];

          piVar3[2] = piVar3[2] & 0xfffffffd;

        }

        if (0.0 < local_104) {

          FUN_0074e9d0(local_104);

          iVar7 = extraout_ECX;

          goto LAB_0073b60e;

        }

        (**(code **)(*param_1 + 0x1c))(piVar3 + 2);

        pvVar4 = (void *)piVar3[5];

        if (pvVar4 != (void *)0x0) {

          FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar4);

        }

        if ((void *)piVar3[7] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete((void *)piVar3[7]);

        }

        piVar3[7] = 0;

        piVar3[8] = 0;

        piVar3[9] = 0;

        piVar9 = (int *)piVar3[1];

        if (piVar3 != (int *)param_1[4]) {

          *piVar9 = *piVar3;

          *(int *)(*piVar3 + 4) = piVar3[1];

          FUN_00464780();

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar3);

        }

      }

      piVar3 = (int *)*piVar9;

    }

    FUN_00972cc0();

    puVar5 = (uint32_t /* width from decompiler */ *)param_1[8];

    for (puVar6 = (uint32_t /* width from decompiler */ *)*puVar5; puVar6 != puVar5; puVar6 = (uint32_t /* width from decompiler */ *)*puVar6) {

      piVar2 = (int *)puVar6[2];

      (**(code **)(*piVar2 + 8))(auStack_f8);

      FUN_0095d580(param_2,auStack_f8,1);

      bVar8 = g_flZero < local_104;

      if ((*(char *)(puVar6 + 4) != '\0') || (g_flZero < local_104)) {

        (**(code **)(*piVar2 + 4))(auStack_f8);

        *(bool *)(puVar6 + 4) = bVar8;

      }

    }

  }

  return;

}
