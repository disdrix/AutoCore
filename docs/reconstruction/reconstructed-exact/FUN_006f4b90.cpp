// =============================================================================
// FUN_006f4b90
// -----------------------------------------------------------------------------
// Stable ID: aa_006f4b90
// Address:   0x006f4b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f4b90 @ 0x006f4b90
// Stable ID: aa_006f4b90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_00646a60, FUN_006f4550, FUN_006f4990, FUN_006f4b90.
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

/* WARNING: Type propagation algorithm not settling */



void FUN_006f4b90(uint *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint *param_4,

                 uint32_t /* width from decompiler */ *param_5)



{

  float fVar1;

  float fVar2;

  uint *puVar3;

  uint uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint *puVar7;

  uint uVar8;

  uint uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ *local_1c;

  uint local_18;

  uint32_t /* width from decompiler */ *local_14;

  uint local_10;

  uint local_c [2];

  uint32_t /* width from decompiler */ *local_4;

  

  uVar6 = param_3;

  iVar5 = (int)param_2;

  puVar3 = param_1;

  local_18 = param_1[2];

  local_10 = *param_1;

  local_1c = (uint32_t /* width from decompiler */ *)((param_1[1] + local_18) * 0x10 + local_10);

  param_1 = (uint *)(param_1[1] * 0x10 + local_10);

  local_c[1] = 0;

  local_14 = local_1c;

  local_c[0] = local_10;

  local_4 = local_1c;

  if (local_10 < param_1) {

    do {

      uVar10 = 0;

      fVar1 = *(float *)(local_c[0] + 0xc);

      fVar2 = *(float *)(iVar5 + 0xc0);

      if (*(float *)(iVar5 + 0xbc) <= *(float *)(local_c[0] + 8)) {

        if (fVar2 < fVar1) {

          uVar10 = 2;

        }

      }

      else if (fVar1 < fVar2 == (fVar1 == fVar2)) {

        uVar10 = 3;

      }

      else {

        uVar10 = 1;

      }

      FUN_006f4550(uVar10,iVar5,uVar6,&local_18,local_c + 1,local_c,&param_1,&local_14,&local_1c);

    } while (local_c[0] < param_1);

  }

  uVar8 = local_18;

  param_2 = local_1c;

  FUN_006f4990(&local_10,&param_1,&local_14,&param_2,&local_1c,&local_4,iVar5);

  puVar7 = param_4;

  uVar4 = (uint)param_1;

  param_1 = (uint *)((int)((int)param_1 - local_10) >> 4);

  param_4[1] = (uint)param_1;

  uVar9 = FUN_00646a60(((float)(int)param_1 * (float)(int)local_18) / (float)(int)puVar3[1]);

  puVar7[2] = uVar9;

  param_5[1] = (int)param_2 - (int)local_14 >> 4;

  param_5[2] = uVar8 - puVar7[2];

  *puVar7 = local_10;

  puVar11 = (uint32_t /* width from decompiler */ *)(puVar7[2] * 0x10 + uVar4);

  *param_5 = puVar11;

  if (param_5[2] != 0) {

    for (; local_14 < param_2; local_14 = local_14 + 4) {

      *puVar11 = *local_14;

      puVar11[1] = local_14[1];

      puVar11[2] = local_14[2];

      puVar11[3] = local_14[3];

      puVar11 = puVar11 + 4;

    }

  }

  return;

}
