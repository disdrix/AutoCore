// =============================================================================
// FUN_0073d200
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d200
// Address:   0x0073d200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073d200 @ 0x0073d200
// Stable ID: aa_0073d200
// Embedded strings (evidence for future rename):
//   - "Directional"
//   - "Color"
//   - "Direction"
//   - "Hemispheric"
//   - "ColorTop"
//   - "ColorBottom"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×10, while×4, do×3, goto×2, return×1.
//  - Notable callees: FUN_00973590×5, FUN_0073c1d0, FUN_0073d020, FUN_0073d0a0, FUN_0073d120, FUN_0073d200.
//  - Strings: "Directional"; "Color"; "Direction"; "Hemispheric".
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

void FUN_0073d200(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  char *pcVar5;

  bool bVar6;

  float fVar7;

  int local_74;

  uint8_t auStack_70 [4];

  uint8_t auStack_6c [4];

  float fStack_68;

  float fStack_64;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  uint8_t auStack_14 [4];

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  float fStack_4;

  

  FUN_0073c1d0();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  if ((*(uint *)(param_1 + 0x58) >> 10 & 1) != 0) {

    local_74 = 0;

    while( true ) {

      if (*(int *)(param_2 + 8) == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = *(int *)(param_2 + 0xc) - *(int *)(param_2 + 8) >> 2;

      }

      if (local_74 == iVar1) break;

      piVar4 = *(int **)(*(int *)(param_2 + 8) + local_74 * 4);

      pcVar2 = (char *)(**(code **)(*piVar4 + 0x20))();

      iVar1 = 0xc;

      bVar6 = true;

      pcVar5 = "Directional";

      do {

        if (iVar1 == 0) break;

        iVar1 = iVar1 + -1;

        bVar6 = *pcVar2 == *pcVar5;

        pcVar2 = pcVar2 + 1;

        pcVar5 = pcVar5 + 1;

      } while (bVar6);

      if (bVar6) {

        fStack_50 = 0.0;

        fStack_4c = 0.0;

        fStack_48 = 0.0;

        fStack_44 = g_flOne;

        uVar3 = (**(code **)(*piVar4 + 0x40))("Color");

        (**(code **)(*piVar4 + 0x58))(uVar3,&fStack_54);

        uVar3 = (**(code **)(*piVar4 + 0x40))("Direction");

        (**(code **)(*piVar4 + 0x5c))(uVar3,auStack_6c);

        FUN_00973590(fStack_68 * DAT_00aaa6f8,fStack_64 * DAT_00aaa6f8,fStack_60 * DAT_00aaa6f8,

                     fStack_5c * DAT_00aaa6f8);

        iVar1 = (**(code **)(*piVar4 + 0x1c))();

        piVar4 = (int *)FUN_0073d120(iVar1 + 0x90,&fStack_5c,auStack_70);

LAB_0073d5f3:

        if (piVar4 != (int *)0x0) {

          (**(code **)(*piVar4 + 0x3c))(param_3);

        }

      }

      else {

        pcVar2 = (char *)(**(code **)(*piVar4 + 0x20))();

        iVar1 = 0xc;

        bVar6 = true;

        pcVar5 = "Hemispheric";

        do {

          if (iVar1 == 0) break;

          iVar1 = iVar1 + -1;

          bVar6 = *pcVar2 == *pcVar5;

          pcVar2 = pcVar2 + 1;

          pcVar5 = pcVar5 + 1;

        } while (bVar6);

        if (bVar6) {

          fStack_30 = 0.0;

          fStack_2c = 0.0;

          fStack_28 = 0.0;

          fStack_24 = g_flOne;

          uVar3 = (**(code **)(*piVar4 + 0x40))("ColorTop");

          (**(code **)(*piVar4 + 0x58))(uVar3,&fStack_34);

          fStack_4c = 0.0;

          fStack_48 = 0.0;

          fStack_44 = 0.0;

          fStack_40 = g_flOne;

          uVar3 = (**(code **)(*piVar4 + 0x40))("ColorBottom");

          (**(code **)(*piVar4 + 0x58))(uVar3,&fStack_50);

          fVar7 = DAT_00aaa6f8;

          FUN_00973590(fStack_58 * DAT_00aaa6f8,fStack_54 * DAT_00aaa6f8,fStack_50 * DAT_00aaa6f8,

                       fStack_4c * DAT_00aaa6f8);

          FUN_00973590(fStack_48 * fVar7,fStack_44 * fVar7,fStack_40 * fVar7,fStack_3c * fVar7);

          iVar1 = (**(code **)(*piVar4 + 0x1c))();

          piVar4 = (int *)FUN_0073d0a0(iVar1 + 0x90,&fStack_68,auStack_6c);

          goto LAB_0073d5f3;

        }

        pcVar2 = (char *)(**(code **)(*piVar4 + 0x20))();

        iVar1 = 6;

        bVar6 = true;

        pcVar5 = "Point";

        do {

          if (iVar1 == 0) break;

          iVar1 = iVar1 + -1;

          bVar6 = *pcVar2 == *pcVar5;

          pcVar2 = pcVar2 + 1;

          pcVar5 = pcVar5 + 1;

        } while (bVar6);

        if (bVar6) {

          uStack_10 = 0;

          uStack_c = 0;

          uStack_8 = 0;

          fStack_4 = g_flOne;

          uVar3 = (**(code **)(*piVar4 + 0x40))("Color");

          (**(code **)(*piVar4 + 0x58))(uVar3,auStack_14);

          fStack_2c = 0.0;

          fStack_28 = 0.0;

          fStack_24 = 0.0;

          fStack_20 = g_flOne;

          uVar3 = (**(code **)(*piVar4 + 0x40))("Ambient");

          (**(code **)(*piVar4 + 0x58))(uVar3,&fStack_30);

          fVar7 = DAT_00aaa6f8;

          FUN_00973590(fStack_38 * DAT_00aaa6f8,fStack_34 * DAT_00aaa6f8,fStack_30 * DAT_00aaa6f8,

                       fStack_2c * DAT_00aaa6f8);

          FUN_00973590(fStack_28 * fVar7,fStack_24 * fVar7,fStack_20 * fVar7,fStack_1c * fVar7);

          iVar1 = (**(code **)(*piVar4 + 0x1c))();

          piVar4 = (int *)FUN_0073d020(iVar1 + 0x90,&fStack_60,&fStack_64);

          goto LAB_0073d5f3;

        }

      }

      local_74 = local_74 + 1;

    }

  }

  return;

}
