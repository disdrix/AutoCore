// =============================================================================
// FUN_005316c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005316c0
// Address:   0x005316c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005316c0 @ 0x005316c0
// Stable ID: aa_005316c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: if×14, return×5, do×1, while×1.
//  - Notable callees: CVOGReaction_RemoveInventoryItem×4, CONCAT31×3, FUN_00599dd0×3, FUN_005711c0×2, FUN_004f1e20, FUN_00522060, FUN_005310a0, FUN_005316c0.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ __thiscall FUN_005316c0(int param_1,int param_2,uint param_3,int param_4)



{

  int iVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  uint8_t local_19;

  int local_18;

  int local_14;

  int local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  int local_4;

  

  iVar7 = param_3;

  iVar2 = param_2;

  if (param_2 == 0) {

    return 0;

  }

  if ((*(int *)(param_1 + 0x250) != 0) &&

     (local_10 = *(int *)(*(int *)(param_1 + 0x250) + 0x2b0), local_10 != 0)) {

    local_14 = *(int *)(param_1 + 0xcbc);

    if (((0 < (int)param_3) && (local_14 != 0)) &&

       ((local_4 = param_1, *(int *)(param_2 + 0x3c) != 0 ||

        (FUN_004f1e20(0,1), *(int *)(param_2 + 0x3c) != 0)))) {

      param_3 = 0;

      local_18 = 0;

      cVar3 = FUN_00522060(param_2,&param_3,param_4,0);

      if (cVar3 == '\0') {

        return 1;

      }

      if (iVar7 <= (int)param_3) {

        local_19 = 0;

        param_3 = param_3 & 0xffffff00;

        local_c = CONCAT31(local_c._1_3_,*(uint8_t *)(*(int *)(param_2 + 0x3c) + 0x407));

        local_8 = CONCAT31(local_8._1_3_,*(uint8_t *)(*(int *)(param_2 + 0x3c) + 0x406));

        cVar3 = FUN_005713a0(local_8,local_c,&local_19,&param_3,0xffffffff);

        if (cVar3 != '\0') {

          cVar3 = (char)param_4;

          iVar1 = *(int *)(param_2 + 0x3c);

          param_4 = CONCAT31(param_4._1_3_,(char)param_4 != '\x02');

          if (iVar1 != 0) {

            iVar4 = iVar7;

            iVar5 = local_18;

            if ((cVar3 != '\x01') && ('\0' < *(char *)(iVar1 + 0x4d4))) {

              iVar4 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x4d0),0);

              iVar5 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x4d0),0);

              iVar8 = (int)*(char *)(iVar1 + 0x4d4);

              if (iVar5 + iVar4 < iVar8 * iVar7) {

                iVar5 = (iVar5 + iVar4) / iVar8;

                iVar4 = iVar7 - iVar5;

                iVar7 = iVar5;

              }

              else {

                iVar4 = 0;

              }

              iVar6 = CVOGReaction_RemoveInventoryItem(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x4d0),iVar8 * iVar7)

              ;

              iVar6 = iVar8 * iVar7 - iVar6;

              iVar5 = iVar7;

              if (0 < iVar6) {

                CVOGReaction_RemoveInventoryItem(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x4d0),iVar6);

              }

            }

            local_18 = iVar5;

            if (((char)param_4 != '\0') && (iVar7 = FUN_00599dd0(), 0 < iVar7)) {

              param_2 = 0;

              iVar7 = FUN_00599dd0();

              if (0 < iVar7) {

                param_4 = 0x498;

                do {

                  iVar7 = *(int *)(param_4 + *(int *)(iVar2 + 0x3c));

                  if (iVar7 != -1) {

                    iVar5 = CVOGReaction_RemoveInventoryItem(iVar7,iVar4);

                    if (0 < iVar4 - iVar5) {

                      CVOGReaction_RemoveInventoryItem(iVar7,iVar4 - iVar5);

                    }

                  }

                  param_4 = param_4 + 4;

                  param_2 = param_2 + 1;

                  iVar7 = FUN_00599dd0();

                } while (param_2 < iVar7);

              }

              local_18 = local_18 + iVar4;

            }

            FUN_005310a0(*(uint32_t /* width from decompiler */ *)(iVar1 + 4),local_18);

            return 1;

          }

        }

      }

    }

    return 0;

  }

  return 0;

}
