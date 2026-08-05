// =============================================================================
// FUN_006d5340
// -----------------------------------------------------------------------------
// Stable ID: aa_006d5340
// Address:   0x006d5340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d5340 @ 0x006d5340
// Stable ID: aa_006d5340
// Embedded strings (evidence for future rename):
//   - "TtmultiRay-cvx"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: rdtsc×2, FUN_005b3370, FUN_005d68f0, FUN_005d6ae0, FUN_0063a3f0, FUN_006d5340.
//  - Strings: "TtmultiRay-cvx".
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

void __thiscall

FUN_006d5340(int param_1,int *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4,int *param_5)



{

  char *pcVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  int *piVar6;

  uint64_t uVar7;

  uint16_t uVar8;

  float *pfVar9;

  float *pfVar10;

  int iVar11;

  int iVar12;

  char local_b8 [4];

  int *local_b4;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  uint32_t /* width from decompiler */ local_8c;

  float local_80;

  float local_7c;

  float local_78;

  float local_70;

  float local_6c;

  float local_68;

  float local_60;

  float local_5c;

  float local_58;

  float local_50;

  float local_4c;

  float local_48;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  uint8_t local_30 [20];

  float local_1c;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtmultiRay-cvx";

    uVar7 = rdtsc();

    DAT_00bc5644[1] = (int)uVar7;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar11 = *param_2;

  local_b4 = (int *)*param_3;

  FUN_0063a3f0(param_3[2] + 0x20,param_2[2] + 0x20);

  iVar5 = *(int *)(iVar11 + 0x14);

  iVar12 = 0;

  local_8c = 0;

  pfVar9 = *(float **)(iVar11 + 0x10);

  if (0 < iVar5) {

    pfVar10 = pfVar9 + 6;

    do {

      fVar2 = *pfVar9;

      fVar3 = pfVar10[-5];

      fVar4 = pfVar10[-4];

      local_a4 = 0.0;

      local_1c = 1.0;

      local_b0 = local_80 * fVar2 + local_70 * fVar3 + local_60 * fVar4 + local_50;

      local_ac = local_7c * fVar2 + local_6c * fVar3 + local_5c * fVar4 + local_4c;

      local_a8 = local_78 * fVar2 + local_68 * fVar3 + local_58 * fVar4 + local_48;

      fVar2 = pfVar10[-2];

      fVar3 = pfVar10[-1];

      fVar4 = *pfVar10;

      local_94 = 0.0;

      local_a0 = local_80 * fVar2 + local_70 * fVar3 + local_60 * fVar4 + local_50;

      local_9c = local_7c * fVar2 + local_6c * fVar3 + local_5c * fVar4 + local_4c;

      local_98 = local_78 * fVar2 + local_68 * fVar3 + local_58 * fVar4 + local_48;

      (**(code **)(*local_b4 + 0x20))(local_b8,&local_b0,local_30);

      if (local_b8[0] == '\0') {

        pcVar1 = (char *)(*(int *)(param_1 + 0xc) + iVar12 * 4);

        if (*pcVar1 != '\0') {

          (**(code **)(**(int **)(param_1 + 8) + 8))(*(uint16_t *)(pcVar1 + 2));

          *(uint8_t *)(*(int *)(param_1 + 0xc) + iVar12 * 4) = 0;

        }

      }

      else {

        piVar6 = (int *)*param_5;

        if (piVar6[1] == (piVar6[2] & 0x7fffffffU)) {

          FUN_005b3370(piVar6,0x30);

        }

        fVar2 = g_flOne;

        iVar11 = piVar6[1] * 0x30 + *piVar6;

        piVar6[1] = piVar6[1] + 1;

        fVar2 = fVar2 - local_1c;

        fStack_40 = local_a0 * local_1c + local_b0 * fVar2;

        fStack_3c = local_9c * local_1c + local_ac * fVar2;

        fStack_38 = local_98 * local_1c + local_a8 * fVar2;

        fStack_34 = local_94 * local_1c + local_a4 * fVar2;

        FUN_005d68f0(param_3[2] + 0x20,&fStack_40);

        FUN_005d6ae0(param_3[2] + 0x20,local_30);

        *(float *)(iVar11 + 0xc) = (local_1c - g_flOne) * pfVar10[-3];

        pcVar1 = (char *)(*(int *)(param_1 + 0xc) + iVar12 * 4);

        if (*pcVar1 == '\0') {

          uVar8 = (**(code **)(**(int **)(param_1 + 8) + 4))(param_2,param_3,param_4,iVar11);

          *(uint16_t *)(pcVar1 + 2) = uVar8;

          if (*(short *)(*(int *)(param_1 + 0xc) + 2 + iVar12 * 4) == -1) {

            *(int *)(*param_5 + 4) = *(int *)(*param_5 + 4) + -1;

          }

          else {

            *(uint8_t *)(*(int *)(param_1 + 0xc) + iVar12 * 4) = 1;

            *(uint16_t *)(iVar11 + 0x20) =

                 *(uint16_t *)(*(int *)(param_1 + 0xc) + 2 + iVar12 * 4);

          }

        }

        *(uint16_t *)(iVar11 + 0x20) = *(uint16_t *)(*(int *)(param_1 + 0xc) + 2 + iVar12 * 4);

      }

      pfVar9 = pfVar9 + 8;

      pfVar10 = pfVar10 + 8;

      iVar12 = iVar12 + 1;

    } while (iVar12 < iVar5);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar7 = rdtsc();

    DAT_00bc5644[1] = (int)uVar7;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
