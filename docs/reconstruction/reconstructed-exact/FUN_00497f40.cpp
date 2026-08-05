// =============================================================================
// FUN_00497f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00497f40
// Address:   0x00497f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00497f40 @ 0x00497f40
// Stable ID: aa_00497f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, do×1, while×1.
//  - Notable callees: FUN_00972d70×2, FUN_0040cf90, FUN_00497650, FUN_00497f40, FUN_004a8940, FUN_004a8a90, FUN_004cd220, FUN_004d10d0.
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



int __thiscall FUN_00497f40(char *param_1,int param_2,int param_3)



{

  int *piVar1;

  float fVar2;

  double dVar3;

  int iVar4;

  int iVar5;

  byte *pbVar6;

  int iVar7;

  uint uVar8;

  float10 fVar9;

  float local_14c;

  float local_148;

  float local_144;

  int local_140;

  float local_13c;

  int local_138;

  uint32_t /* width from decompiler */ local_134;

  uint32_t /* width from decompiler */ local_130;

  float local_12c;

  float local_128;

  int local_124;

  uint8_t local_120 [16];

  uint8_t local_110 [64];

  uint8_t local_d0 [204];

  

  if ((*param_1 == '\0') && (*(int *)(param_1 + 0x10) != 0)) {

    uVar8 = *(int *)(param_1 + 4) * param_3 + param_2;

    uVar8 = uVar8 | uVar8 * 0x10000;

    iVar4 = FUN_00497650(param_2,param_3);

    local_140 = (*(int *)(param_1 + 0xc) * iVar4) / 0xff;

    local_13c = (float)iVar4 * DAT_00aaa7a8;

    if (0 < local_140) {

      local_128 = (float)param_2 * DAT_009c7a24;

      local_12c = (float)param_3 * DAT_009c7a24;

      local_138 = local_140;

      local_124 = iVar4;

      do {

        iVar5 = uVar8 * 0x19660d + 0x3c6ef35f;

        fVar2 = (float)iVar5;

        if (iVar5 < 0) {

          fVar2 = fVar2 + (float)_DAT_00aaa728;

        }

        uVar8 = iVar5 * 0x19660d + 0x3c6ef35f;

        local_14c = fVar2 * (float)_DAT_009c7b58 * (float)_DAT_00aaa9d0 + local_128;

        fVar2 = (float)(int)uVar8;

        if ((int)uVar8 < 0) {

          fVar2 = fVar2 + (float)_DAT_00aaa728;

        }

        local_144 = fVar2 * (float)_DAT_009c7b58 * (float)_DAT_00aaa9d0 + local_12c;

        fVar9 = (float10)FUN_004cd220(local_14c,local_144);

        local_148 = (float)fVar9;

        FUN_004a8a90(local_14c,local_144,&local_134,&local_130);

        pbVar6 = (byte *)FUN_004a8940(local_134,local_130);

        piVar1 = (int *)(*(int *)(param_1 + 0xb4) + ((*pbVar6 & 7) * 0x100 + iVar4) * 0xa4);

        iVar5 = *piVar1;

        if (iVar5 != 0) {

          iVar4 = uVar8 * 0x19660d + 0x3c6ef35f;

          dVar3 = (double)iVar4;

          if (iVar4 < 0) {

            dVar3 = dVar3 + _DAT_00aaa728;

          }

          iVar7 = iVar4 * 0x19660d + 0x3c6ef35f;

          iVar4 = piVar1[(int)ROUND(dVar3 * (double)iVar5 * _DAT_00aaa9d0) + 1];

          fVar2 = (float)iVar7;

          if (iVar7 < 0) {

            fVar2 = fVar2 + (float)_DAT_00aaa728;

          }

          uVar8 = iVar7 * 0x19660d + 0x3c6ef35f;

          *(float *)(*(int *)(iVar4 + 0x10) * 0xd0 + 0x20 + iVar4) =

               fVar2 * local_13c * *(float *)(iVar4 + 4) * (float)_DAT_00aaa9d0 +

               *(float *)(iVar4 + 4);

          FUN_0040cf90(&local_14c);

          FUN_00972d70(0,0,0);

          FUN_00972cc0();

          fVar2 = (float)(int)uVar8;

          if ((int)uVar8 < 0) {

            fVar2 = fVar2 + (float)_DAT_00aaa728;

          }

          FUN_00972d70(fVar2 * (float)_DAT_009c7b50 * (float)_DAT_00aaa9d0,0,0);

          if (*(char *)(iVar4 + 0xf) != '\0') {

            FUN_004d10d0(&local_14c,local_110);

            FUN_0099b8a0(local_110);

            FUN_00972bd0(local_120);

          }

          FUN_00973030(local_d0);

          *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;

          iVar4 = local_124;

        }

        local_140 = local_140 + -1;

      } while (local_140 != 0);

      return local_138;

    }

  }

  else {

    local_140 = 0;

  }

  return local_140;

}
