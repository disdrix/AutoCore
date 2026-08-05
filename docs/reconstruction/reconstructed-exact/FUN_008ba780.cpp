// =============================================================================
// FUN_008ba780
// -----------------------------------------------------------------------------
// Stable ID: aa_008ba780
// Address:   0x008ba780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ba780 @ 0x008ba780
// Stable ID: aa_008ba780
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_008ba780, NDUIWindow_ReloadInterface.
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

void __thiscall FUN_008ba780(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  float *pfVar4;

  float *pfVar5;

  float unaff_EBX;

  float unaff_ESI;

  int *piVar6;

  int iVar7;

  float fStack_5c;

  int *local_58;

  float fStack_54;

  float fStack_50;

  int iStack_4c;

  uint8_t auStack_38 [4];

  uint8_t auStack_34 [4];

  uint8_t auStack_30 [8];

  uint8_t auStack_28 [8];

  uint8_t auStack_20 [4];

  uint8_t auStack_1c [4];

  uint8_t auStack_18 [8];

  uint8_t auStack_10 [12];

  

  local_58 = param_1;

  NDUIWindow_ReloadInterface(param_2);

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar2 != '\0') {

    iVar7 = 0;

    piVar6 = param_1 + 0x14e;

    do {

      if (*piVar6 != 0) {

        piVar1 = (int *)*piVar6;

        iVar3 = (**(code **)(*piVar1 + 0x134))(auStack_38);

        local_58 = (int *)((float)iVar7 * *(float *)(iVar3 + 4) * DAT_00aaa68c);

        iVar3 = (**(code **)(*piVar1 + 0x124))(auStack_34);

        local_58 = (int *)((float)DAT_00d1e81c * (fStack_5c + *(float *)(iVar3 + 4)) * DAT_00aaa678)

        ;

        pfVar4 = (float *)(**(code **)(*(int *)*piVar6 + 0x120))(auStack_30,1,0);

        fStack_5c = *pfVar4;

        local_58 = (int *)(int)unaff_ESI;

        (**(code **)(*(int *)*piVar6 + 0x110))(&fStack_5c);

        param_1 = local_58;

      }

      if (piVar6[5] != 0) {

        piVar1 = (int *)piVar6[5];

        iVar3 = (**(code **)(*(int *)*piVar6 + 0x134))(auStack_20);

        local_58 = (int *)((float)iVar7 * *(float *)(iVar3 + 4) * DAT_00aaa68c);

        iVar3 = (**(code **)(*piVar1 + 0x124))(auStack_1c);

        fStack_54 = (float)DAT_00d1e81c * (fStack_5c + *(float *)(iVar3 + 4)) * DAT_00aaa678;

        pfVar4 = (float *)(**(code **)(*(int *)piVar6[5] + 0x120))(auStack_18,1,0);

        fStack_54 = *pfVar4;

        fStack_50 = (float)(int)unaff_EBX;

        (**(code **)(*(int *)piVar6[5] + 0x110))(&fStack_54);

        param_1 = local_58;

      }

      iVar7 = iVar7 + 1;

      piVar6 = piVar6 + 1;

    } while (iVar7 < 5);

    fStack_54 = 0.0;

    piVar6 = param_1 + 0x15a;

    do {

      iStack_4c = (int)fStack_54 / param_1[0x16b];

      iVar7 = (int)fStack_54 % param_1[0x16b];

      if (*piVar6 != 0) {

        piVar1 = (int *)*piVar6;

        iVar3 = (**(code **)(*piVar1 + 0x134))(auStack_10);

        fStack_50 = (float)(int)fStack_50 * *(float *)(iVar3 + 4);

        iVar3 = (**(code **)(*piVar1 + 0x124))(auStack_1c);

        local_58 = (int *)((float)DAT_00d1e81c * (fStack_54 + *(float *)(iVar3 + 4)) * DAT_00aaa678)

        ;

        pfVar4 = (float *)(**(code **)(*(int *)*piVar6 + 0x134))(auStack_28);

        pfVar5 = (float *)(**(code **)(*(int *)*piVar6 + 0x124))(auStack_34);

        iStack_4c = (int)unaff_EBX;

        fStack_50 = (float)(int)((float)DAT_00d1e818 * ((float)iVar7 * *pfVar4 + *pfVar5) *

                                DAT_00aaa67c);

        (**(code **)(*(int *)*piVar6 + 0x118))(&fStack_50);

      }

      fStack_54 = (float)((int)fStack_54 + 1);

      piVar6 = piVar6 + 1;

      param_1 = local_58;

    } while ((int)fStack_54 < 0xf);

    (**(code **)(*local_58 + 0x448))();

    param_1 = local_58;

  }

  (**(code **)(*param_1 + 0x34c))();

  return;

}
