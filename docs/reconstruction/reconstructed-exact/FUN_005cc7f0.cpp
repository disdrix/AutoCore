// =============================================================================
// FUN_005cc7f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005cc7f0
// Address:   0x005cc7f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cc7f0 @ 0x005cc7f0
// Stable ID: aa_005cc7f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: CVOGReaction_TeleportTarget, FUN_004baec0, FUN_004e9720, FUN_0053e510, FUN_005cc7f0.
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

uint32_t /* width from decompiler */ __fastcall FUN_005cc7f0(int *param_1)



{

  int iVar1;

  int iVar2;

  bool bVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  void *this;

  float10 fVar7;

  uint32_t /* width from decompiler */ *pTeleportData;

  uint32_t /* width from decompiler */ auStack_20 [3];

  uint32_t /* width from decompiler */ uStack_14;

  

  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 4 + param_1[0x19]) +

                      0x19c))();

  iVar4 = *(int *)(iVar4 + 8);

  if (iVar4 != 0) {

    if ((*(char *)(iVar4 + 0x40) == '\0') || (*(int *)(iVar4 + 8) == 0)) {

      bVar3 = true;

    }

    else {

      bVar3 = false;

    }

    if (bVar3) {

      iVar4 = param_1[0x19];

      uStack_14 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x234);

      iVar4 = FUN_004baec0(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x230),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x228),

                           *(uint32_t /* width from decompiler */ *)(iVar4 + 0x22c));

      if (iVar4 != 0) {

        iVar1 = param_1[0x19];

        iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

        uVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x19c))();

        (**(code **)(*(int *)(iVar2 + 4 + iVar1) + 0x19c))(uVar5);

        fVar7 = (float10)FUN_0053e510(uVar5);

        iVar1 = param_1[0x19];

        if (*(float *)(iVar1 + 0x270) < (float)fVar7) {

          if ((0.0 < *(float *)(iVar1 + 0x310) || *(float *)(iVar1 + 0x310) == 0.0) &&

             (*(float *)(iVar1 + 0x310) < (float)fVar7)) {

            iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + iVar4;

            uVar5 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0xa8);

            uVar6 = (**(code **)(*(int *)(iVar4 + 4) + 0x1a0))

                              (0x41700000,0x40a00000,auStack_20,1,5,0);

            FUN_004e9720(uVar5,uVar6);

            pTeleportData = auStack_20;

            this = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 4 +

                                                param_1[0x19]) + 0x19c))();

            CVOGReaction_TeleportTarget(this,pTeleportData);

            return 1;

          }

          iVar1 = *param_1;

          uVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1a0))(1);

          (**(code **)(iVar1 + 0x4c))(uVar5);

          return 1;

        }

      }

    }

  }

  return 0;

}
