// =============================================================================
// FUN_0074dc80
// -----------------------------------------------------------------------------
// Stable ID: aa_0074dc80
// Address:   0x0074dc80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074dc80 @ 0x0074dc80
// Stable ID: aa_0074dc80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×8, for×2, goto×2, return×1.
//  - Notable callees: FUN_00734700, FUN_0074dc80, FUN_0074e9d0, FUN_0074ebe0, FUN_00972cc0.
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

void __thiscall FUN_0074dc80(int *param_1,float param_2,uint32_t /* width from decompiler */ param_3)



{

  uint *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  int extraout_ECX;

  int iVar6;

  bool bVar7;

  float fVar8;

  float fVar9;

  float local_100;

  uint8_t auStack_f8 [244];

  

  fVar8 = param_2 - (float)param_1[2];

  param_1[2] = (int)param_2;

  if (DAT_00aaa664 < fVar8) {

    puVar2 = (uint32_t /* width from decompiler */ *)param_1[5];

    fVar9 = fVar8;

    local_100 = DAT_00aaa664;

    for (puVar3 = (uint32_t /* width from decompiler */ *)*puVar2; puVar3 != puVar2; puVar3 = (uint32_t /* width from decompiler */ *)*puVar3) {

      iVar6 = puVar3[2];

      puVar1 = puVar3 + 3;

      if ((puVar3[3] & 2) == 0) {

LAB_0074dd35:

        if ((iVar6 != 0) && ((*puVar1 & 4) != 0)) {

          FUN_0074ebe0(param_2);

          fVar9 = fVar8;

        }

      }

      else {

        local_100 = (float)puVar3[9] * fVar9 + *(float *)(iVar6 + 0x10);

        if (0.0 < (float)puVar3[9]) {

          if ((float)puVar3[8] <= local_100) goto LAB_0074dd0c;

        }

        else if (local_100 <= (float)puVar3[8]) {

LAB_0074dd0c:

          local_100 = (float)puVar3[8];

          *puVar1 = puVar3[3] & 0xfffffffd;

        }

        if (0.0 < local_100) {

          FUN_0074e9d0(local_100);

          iVar6 = extraout_ECX;

          goto LAB_0074dd35;

        }

        (**(code **)(*param_1 + 0x3c))(iVar6,puVar1);

        fVar9 = fVar8;

      }

    }

    FUN_00972cc0();

    puVar2 = (uint32_t /* width from decompiler */ *)param_1[0xf];

    for (puVar3 = (uint32_t /* width from decompiler */ *)*puVar2; puVar3 != puVar2; puVar3 = (uint32_t /* width from decompiler */ *)*puVar3) {

      piVar4 = (int *)puVar3[2];

      uVar5 = puVar3[3];

      (**(code **)(*piVar4 + 8))(auStack_f8);

      FUN_00734700(uVar5,param_2,auStack_f8,param_3);

      bVar7 = g_flZero < local_100;

      if ((*(char *)(puVar3 + 4) != '\0') || (g_flZero < local_100)) {

        (**(code **)(*piVar4 + 4))(auStack_f8);

        *(bool *)(puVar3 + 4) = bVar7;

      }

    }

  }

  return;

}
