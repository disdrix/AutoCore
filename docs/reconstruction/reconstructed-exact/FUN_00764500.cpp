// =============================================================================
// FUN_00764500
// -----------------------------------------------------------------------------
// Stable ID: aa_00764500
// Address:   0x00764500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00764500 @ 0x00764500
// Stable ID: aa_00764500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×13, return×7, do×1, goto×1, while×1.
//  - Notable callees: FUN_0074c8a0×2, FUN_0074c420, FUN_00764500.
//  - Return sites: 7.

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

uint32_t /* width from decompiler */ __thiscall FUN_00764500(int *param_1,int param_2,byte *param_3)



{

  float *pfVar1;

  float *pfVar2;

  float fVar3;

  char cVar4;

  char cVar5;

  uint32_t /* width from decompiler */ uVar6;

  byte *pbVar7;

  uint32_t /* width from decompiler */ *puVar8;

  byte *pbVar9;

  float *pfVar10;

  float *pfVar11;

  uint32_t /* width from decompiler */ uVar12;

  

  if (param_2 == 0) {

    if ((*param_3 & 1) == 0) {

      pbVar7 = (byte *)0x0;

    }

    else {

      pbVar7 = param_3 + 0x1c;

    }

    pfVar1 = (float *)(param_3 + 0x10);

    pfVar2 = (float *)(param_3 + 4);

    pfVar10 = pfVar2;

    pfVar11 = pfVar1;

    uVar6 = (**(code **)(*param_1 + 0xc))(pfVar2,pfVar1,pbVar7);

    cVar4 = FUN_0074c8a0(uVar6,pfVar10,pfVar11,pbVar7);

    if (cVar4 != '\0') {

      *(int **)(param_3 + 0x38) = param_1;

      if (((byte)*(uint32_t /* width from decompiler */ *)param_3 & 3) == 3) {

        fVar3 = *(float *)(param_3 + 0x1c);

        *(float *)(param_3 + 0x20) = *pfVar2 + *pfVar1 * fVar3;

        *(float *)(param_3 + 0x24) = *(float *)(param_3 + 8) + *(float *)(param_3 + 0x14) * fVar3;

        *(float *)(param_3 + 0x28) = *(float *)(param_3 + 0xc) + *(float *)(param_3 + 0x18) * fVar3;

      }

      return 1;

    }

  }

  else if (param_2 == 1) {

    pbVar7 = param_3 + 0x10;

    pbVar9 = param_3 + 4;

    (**(code **)(*param_1 + 0xc))(pbVar9,pbVar7);

    cVar4 = FUN_0074c420(pbVar9,pbVar7);

    if (cVar4 != '\0') {

      *(int **)(param_3 + 0x38) = param_1;

      if (((byte)*(uint32_t /* width from decompiler */ *)param_3 & 3) != 3) {

        return 1;

      }

      fVar3 = *(float *)(param_3 + 0x1c);

      *(float *)(param_3 + 0x20) = *(float *)(param_3 + 4) + *(float *)(param_3 + 0x10) * fVar3;

      *(float *)(param_3 + 0x24) = *(float *)(param_3 + 8) + *(float *)(param_3 + 0x14) * fVar3;

      *(float *)(param_3 + 0x28) = *(float *)(param_3 + 0xc) + *(float *)(param_3 + 0x18) * fVar3;

      return 1;

    }

  }

  else {

    uVar12 = 0;

    pbVar7 = param_3 + 0x10;

    pbVar9 = param_3 + 4;

    uVar6 = (**(code **)(*param_1 + 0xc))(pbVar9,pbVar7,0);

    cVar4 = FUN_0074c8a0(uVar6,pbVar9,pbVar7,uVar12);

    if (cVar4 != '\0') {

      cVar4 = '\0';

      (**(code **)(*param_1 + 0x34))();

      if (param_1[0x25] == 0) {

        puVar8 = (uint32_t /* width from decompiler */ *)param_1[0x30];

        if (puVar8 == (uint32_t /* width from decompiler */ *)param_1[0x31]) {

          return 0;

        }

        do {

          cVar5 = (**(code **)(*(int *)*puVar8 + 0x6c))(param_2,param_3);

          if ((cVar5 != '\0') && (cVar4 = '\x01', *(int *)param_3 == 0)) goto LAB_007645ac;

          puVar8 = puVar8 + 1;

        } while (puVar8 != (uint32_t /* width from decompiler */ *)param_1[0x31]);

      }

      else {

        cVar4 = (**(code **)(*(int *)param_1[0x25] + 0x1c))(param_2,param_3);

      }

      if (cVar4 != '\0') {

LAB_007645ac:

        *(int **)(param_3 + 0x38) = param_1;

        if (((byte)*(uint32_t /* width from decompiler */ *)param_3 & 3) != 3) {

          return 1;

        }

        fVar3 = *(float *)(param_3 + 0x1c);

        *(float *)(param_3 + 0x20) = *(float *)(param_3 + 4) + *(float *)(param_3 + 0x10) * fVar3;

        *(float *)(param_3 + 0x24) = *(float *)(param_3 + 8) + *(float *)(param_3 + 0x14) * fVar3;

        *(float *)(param_3 + 0x28) = *(float *)(param_3 + 0xc) + *(float *)(param_3 + 0x18) * fVar3;

        return 1;

      }

    }

  }

  return 0;

}
