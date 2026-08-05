// =============================================================================
// FUN_0058fe90
// -----------------------------------------------------------------------------
// Stable ID: aa_0058fe90
// Address:   0x0058fe90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058fe90 @ 0x0058fe90
// Stable ID: aa_0058fe90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×10, return×3.
//  - Notable callees: FUN_00493e90, FUN_0058fe90, FUN_0074e310.
//  - Return sites: 3.

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

void __thiscall FUN_0058fe90(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  float fVar4;

  float fVar5;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  if ((*(int *)(param_1 + 0x914) != 0) && ((*(byte *)(param_1 + 0x90e) & 4) != 0)) {

    if (((*(byte *)(param_1 + 0x90f) & 2) != 0) &&

       ((*(int *)(param_1 + 0x91c) != 0 && (*(int *)(param_1 + 0x918) == 0)))) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x918) = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

      FUN_0074e310(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x91c) + 0x8c));

    }

    if (((*(byte *)(param_1 + 0x90e) & 8) == 0) &&

       ((iVar2 = (**(code **)(**(int **)(param_1 + 0x914) + 0xc))(),

        DAT_00a0f718 < *(float *)(iVar2 + 0x9c) || DAT_00a0f718 == *(float *)(iVar2 + 0x9c) ||

        (*(int *)(param_1 + 0x91c) != 0)))) {

      if ((*(char *)(param_1 + 0x911) != '\0') && ((*(byte *)(param_1 + 0x90c) & 2) == 0)) {

        FUN_00493e90(*(uint32_t /* width from decompiler */ *)(param_1 + 0x914));

        return;

      }

      iVar2 = (**(code **)(**(int **)(param_1 + 0x914) + 0xc))();

      fStack_c = *(float *)(iVar2 + 0x90);

      fStack_8 = *(float *)(iVar2 + 0x94);

      fStack_4 = *(float *)(iVar2 + 0x98);

      if ((*(byte *)(param_1 + 0x90c) & 2) != 0) {

        iVar2 = *(int *)(*(int *)(*(int *)(param_3 + 0xe894) + 0xc0) + 8);

        pfVar3 = (float *)(iVar2 + 0x90);

        if ((*(byte *)(param_1 + 0x90c) & 1) == 0) {

          fStack_18 = *pfVar3 + fStack_c;

          fStack_14 = *(float *)(iVar2 + 0x94);

          fStack_10 = *(float *)(iVar2 + 0x98) + fStack_4;

        }

        else {

          fVar4 = DAT_009cc4dc;

          fVar5 = DAT_009cc4dc;

          if (*(int *)(param_3 + 0xe4f8) != 0) {

            iVar1 = *(int *)(param_3 + 0xe4f8);

            fVar4 = (float)*(int *)(iVar1 + 0x10) * *(float *)(iVar1 + 0x18) * DAT_00a0f298;

            fVar5 = (float)*(int *)(iVar1 + 0x14) * *(float *)(iVar1 + 0x18) * DAT_00a0f298;

          }

          fStack_14 = *(float *)(iVar2 + 0x94);

          fStack_18 = *pfVar3 + fStack_c + ((*pfVar3 - fVar4) / fVar4) * DAT_00af32d0;

          fStack_10 = *(float *)(iVar2 + 0x98) + fStack_4 +

                      ((*(float *)(iVar2 + 0x98) - fVar5) / fVar5) * DAT_00af32d0;

        }

        fStack_14 = fStack_14 + fStack_8;

        fStack_24 = fStack_18;

        fStack_1c = fStack_10;

        fStack_20 = fStack_14 - fStack_14 * g_flMultiKillCountBlend;

        (**(code **)(**(int **)(param_1 + 0x914) + 0x18))(&fStack_24);

      }

      (**(code **)(**(int **)(param_1 + 0x914) + 0x3c))(*(int *)(param_2 + 0xc0) + 0x10);

      if ((*(byte *)(param_1 + 0x90c) & 2) == 0) {

        if (*(char *)(DAT_00d1f048 + 0xf) != '\0') {

          (**(code **)(**(int **)(param_1 + 0x914) + 0x40))(*(int *)(param_2 + 0xc0) + 0x10);

        }

        if ((*(byte *)(param_1 + 0x90c) & 2) == 0) {

          return;

        }

      }

      (**(code **)(**(int **)(param_1 + 0x914) + 0x18))(&fStack_10);

    }

  }

  return;

}
