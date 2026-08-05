// =============================================================================
// FUN_0094f2e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094f2e0
// Address:   0x0094f2e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094f2e0 @ 0x0094f2e0
// Stable ID: aa_0094f2e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~117 non-empty decompiler lines.
//  - Control keywords: if×14, return×2.
//  - Notable callees: strchr×4, strtok×3, FUN_00404a20×2, atof×2, CVOGMap_CastTerrainHeight, CVOGReaction_TeleportTarget, FUN_00404c90, FUN_004e8a40.
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

uint32_t /* width from decompiler */ __thiscall FUN_0094f2e0(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  char *pcVar1;

  int iVar2;

  char *pcVar3;

  void *this;

  float *pfVar4;

  uint32_t /* width from decompiler */ uVar5;

  bool bVar6;

  float10 fVar7;

  float fVar8;

  float fVar9;

  double dVar10;

  float local_54;

  float local_50;

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

  float fStack_18;

  float fStack_14;

  

  pcVar1 = strtok((char *)0x0,param_3);

  if (((pcVar1 != (char *)0x0) && (*(int *)(param_1 + 0xe98) != 0)) &&

     (*(int *)(*(int *)(param_1 + 0xe98) + 0x250) != 0)) {

    iVar2 = _stricmp(pcVar1,"f");

    bVar6 = iVar2 == 0;

    if (bVar6) {

      pcVar1 = strtok((char *)0x0,param_3);

    }

    local_54 = 0.0;

    if (bVar6) {

      local_54 = g_flOne;

    }

    pcVar3 = strchr(pcVar1,0x2b);

    fVar9 = g_flOne;

    if ((pcVar3 != (char *)0x0) ||

       (pcVar3 = strchr(pcVar1,0x2d), fVar9 = DAT_00aaa668, pcVar3 != (char *)0x0)) {

      *pcVar3 = ' ';

      local_54 = fVar9;

    }

    dVar10 = atof(pcVar1);

    fVar9 = (float)dVar10;

    if (fVar9 == g_flZero) {

      local_54 = g_flOne;

    }

    pcVar1 = strtok((char *)0x0,param_3);

    if (pcVar1 != (char *)0x0) {

      local_50 = 0.0;

      if (bVar6) {

        local_50 = g_flOne;

      }

      pcVar3 = strchr(pcVar1,0x2b);

      fVar8 = g_flOne;

      if ((pcVar3 != (char *)0x0) ||

         (pcVar3 = strchr(pcVar1,0x2d), fVar8 = DAT_00aaa668, pcVar3 != (char *)0x0)) {

        *pcVar3 = ' ';

        local_50 = fVar8;

      }

      dVar10 = atof(pcVar1);

      fVar8 = (float)dVar10;

      if (fVar8 == g_flZero) {

        local_50 = g_flOne;

      }

      iVar2 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250);

      this = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x1c8))

                               ();

      if ((this == (void *)0x0) || (*(int *)((int)this + 8) == 0)) {

        this = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) +

                                             4 + *(int *)(param_1 + 0xe98)) + 0x1c8))();

      }

      if ((this != (void *)0x0) && (*(int *)((int)this + 8) != 0)) {

        pfVar4 = (float *)FUN_00404c90();

        fStack_40 = *pfVar4;

        fStack_3c = pfVar4[1];

        fStack_38 = pfVar4[2];

        fStack_34 = pfVar4[3];

        if (bVar6) {

          uVar5 = FUN_00404a20(&fStack_30);

          FUN_004e8a40(uVar5);

          fVar8 = fVar8 * local_50;

          fStack_30 = fStack_30 * fVar8;

          fStack_2c = fStack_2c * fVar8;

          fStack_28 = fStack_28 * fVar8;

          fStack_24 = fStack_24 * fVar8;

          uVar5 = FUN_00404a20(&fStack_20);

          FUN_004e8ad0(uVar5);

          fVar9 = fVar9 * local_54;

          fStack_40 = fStack_20 * fVar9 + fStack_30 + fStack_40;

          fStack_3c = fStack_1c * fVar9 + fStack_2c + fStack_3c;

          fStack_34 = fStack_14 * fVar9 + fStack_24 + fStack_34;

          fVar8 = fStack_18 * fVar9 + fStack_28 + fStack_38;

        }

        else {

          if (local_54 != 0.0) {

            fVar9 = fVar9 * local_54 + fStack_40;

          }

          fStack_40 = fVar9;

          if (local_50 != 0.0) {

            fVar8 = fVar8 * local_50 + fStack_38;

          }

        }

        fStack_38 = fVar8;

        fVar7 = (float10)CVOGMap_CastTerrainHeight(fStack_40,fStack_38,0x447a0000,0);

        fStack_3c = (float)(fVar7 + (float10)DAT_00aaa688);

        CVOGReaction_TeleportTarget(this,&fStack_40);

      }

      return 1;

    }

  }

  return 0;

}
