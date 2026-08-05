// =============================================================================
// FUN_0099c2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099c2a0
// Address:   0x0099c2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099c2a0 @ 0x0099c2a0
// Stable ID: aa_0099c2a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, do×1, while×1.
//  - Notable callees: FUN_0040c5c0, FUN_004e87d0, FUN_009765d0, FUN_0099c2a0, strncpy.
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



uint32_t /* width from decompiler */ __fastcall FUN_0099c2a0(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  char *_Source;

  float fVar4;

  float fVar5;

  char cVar6;

  uint uVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ local_f0;

  uint32_t /* width from decompiler */ local_ec;

  uint32_t /* width from decompiler */ local_e8;

  float local_d0;

  float local_cc;

  float local_c8;

  float local_c4;

  uint8_t local_c0 [24];

  char local_a8 [128];

  uint32_t /* width from decompiler */ local_28;

  float local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  if (*(int *)(param_1 + 0x18) != 0) {

    cVar6 = FUN_009765d0(local_c0);

    if (cVar6 == '\0') {

      iVar3 = *(int *)(param_1 + 0x18);

      uVar7 = 0;

      if (*(int *)(iVar3 + 0x6c) != 0) {

        uVar7 = (*(int *)(iVar3 + 0x70) - *(int *)(iVar3 + 0x6c)) / 0x28;

      }

      if (*(uint *)(iVar3 + 100) < uVar7) {

        iVar2 = *(int *)(iVar3 + 0x6c) + *(uint *)(iVar3 + 100) * 0x28;

        piVar1 = (int *)(iVar2 + 0x20);

        *(uint32_t /* width from decompiler */ *)(iVar3 + 100) = 0xffffffff;

        if ((piVar1 != (int *)0x0) && (_Source = *(char **)(iVar2 + 0x24), _Source != (char *)0x0))

        {

          pcVar8 = _Source;

          do {

            cVar6 = *pcVar8;

            pcVar8 = pcVar8 + 1;

          } while (cVar6 != '\0');

          if (1 < (uint)((int)pcVar8 - (int)(_Source + 1))) {

            local_28 = 0xffffffff;

            strncpy(local_a8,_Source,0x80);

            local_24 = (float)*piVar1;

            local_1c = 4;

            if (*piVar1 < 0) {

              local_24 = local_24 + _DAT_00aaa5dc;

            }

            local_24 = local_24 * g_flMsToSeconds_Inferred;

            local_20 = DAT_00aaa68c;

            local_28 = 0xffeeeeee;

            local_18 = 0xffffffff;

            local_14 = 0xffffffff;

            FUN_0040c5c0(local_a8);

          }

        }

      }

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x228) = local_f0;

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x22c) = local_ec;

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x230) = local_e8;

      FUN_004e87d0(&local_d0,local_c0);

      fVar5 = g_flLevelUpUiBase_Inferred;

      fVar4 = g_flOne;

      *(float *)(DAT_00d1b628 + 0x204) =

           g_flOne - (local_cc * local_cc + local_c8 * local_c8) * g_flLevelUpUiBase_Inferred;

      *(float *)(DAT_00d1b628 + 0x208) = (local_c4 * local_c8 + local_cc * local_d0) * fVar5;

      *(float *)(DAT_00d1b628 + 0x20c) = (local_c8 * local_d0 - local_cc * local_c4) * fVar5;

      *(float *)(DAT_00d1b628 + 0x210) = (local_cc * local_d0 - local_c4 * local_c8) * fVar5;

      *(float *)(DAT_00d1b628 + 0x214) = fVar4 - (local_c8 * local_c8 + local_d0 * local_d0) * fVar5

      ;

      *(float *)(DAT_00d1b628 + 0x218) = (local_cc * local_c8 + local_c4 * local_d0) * fVar5;

      *(float *)(DAT_00d1b628 + 0x21c) = (local_cc * local_c4 + local_c8 * local_d0) * fVar5;

      *(float *)(DAT_00d1b628 + 0x220) = (local_cc * local_c8 - local_c4 * local_d0) * fVar5;

      *(float *)(DAT_00d1b628 + 0x224) = fVar4 - (local_cc * local_cc + local_d0 * local_d0) * fVar5

      ;

      return 0;

    }

  }

  return 1;

}
