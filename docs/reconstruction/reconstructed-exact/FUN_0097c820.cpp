// =============================================================================
// FUN_0097c820
// -----------------------------------------------------------------------------
// Stable ID: aa_0097c820
// Address:   0x0097c820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0097c820 @ 0x0097c820
// Stable ID: aa_0097c820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×15, return×7.
//  - Notable callees: FUN_007a7d30×2, FUN_00413600, FUN_0097c820, _CIacos.
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

uint32_t /* width from decompiler */ __thiscall FUN_0097c820(int *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  float10 extraout_ST0;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  uint8_t *puVar8;

  float fStack_10;

  uint8_t local_8 [8];

  

  if ((char)param_1[300] == '\0') {

    uVar2 = FUN_007a7d30(param_2,param_3);

    return uVar2;

  }

  cVar1 = FUN_007a7d30(param_2,param_3,param_4);

  if (cVar1 != '\0') {

    puVar8 = local_8;

    (**(code **)(*param_1 + 0x140))(puVar8,1);

    (**(code **)(*param_1 + 0x2a8))(&stack0xffffffe8,param_1[0x12e],1,1);

    fVar4 = (float)*param_2;

    if ((char)param_3 == '\0') {

      fVar4 = (float)(int)(fVar4 * (float)DAT_00d1e81c * DAT_00aaa678);

      iVar3 = (int)((float)param_2[1] * (float)DAT_00d1e818 * DAT_00aaa67c);

    }

    else {

      iVar3 = param_2[1];

    }

    fVar4 = fVar4 - (float)param_4;

    fVar5 = (float)iVar3 - (float)(int)puVar8;

    fVar6 = (float)param_1[0x128];

    if (fVar6 < (float)param_1[0x127] || fVar6 == (float)param_1[0x127]) {

      fVar6 = (float)param_1[0x127];

    }

    if (fVar6 * fStack_10 * fVar6 * fStack_10 < fVar5 * fVar5 + fVar4 * fVar4) {

      return 0;

    }

    if (fVar4 == 0.0) {

      fVar4 = DAT_00d1e508;

      if (0.0 < fVar5) {

        fVar4 = DAT_00aaa7dc - DAT_00d1e508;

      }

    }

    else {

      FUN_00413600();

      _CIacos();

      fVar4 = (float)extraout_ST0;

      if (fVar5 < 0.0) {

        fVar4 = DAT_00aaa7dc - fVar4;

      }

    }

    fVar6 = (float)param_1[299];

    fVar5 = fVar6;

    fVar7 = fVar6 + (float)param_1[0x12a];

    if ((float)param_1[0x12a] <= 0.0 && (float)param_1[0x12a] != 0.0) {

      fVar5 = fVar6 + (float)param_1[0x12a];

      fVar7 = fVar6;

    }

    if (0.0 <= fVar5) {

      if (fVar4 < fVar5) {

        return 0;

      }

    }

    else if (0.0 <= fVar7) {

      if (fVar5 + DAT_00aaa7dc <= fVar4) {

        return 1;

      }

    }

    else {

      if (fVar4 < fVar5 + DAT_00aaa7dc) {

        return 0;

      }

      fVar7 = fVar7 + DAT_00aaa7dc;

    }

    if (fVar4 <= fVar7) {

      return 1;

    }

  }

  return 0;

}
