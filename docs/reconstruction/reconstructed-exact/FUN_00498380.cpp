// =============================================================================
// FUN_00498380
// -----------------------------------------------------------------------------
// Stable ID: aa_00498380
// Address:   0x00498380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00498380 @ 0x00498380
// Stable ID: aa_00498380
// Embedded strings (evidence for future rename):
//   - "Could not find flair %d."
//   - "allocatenewobjectfromcbid failed %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~130 non-empty decompiler lines.
//  - Control keywords: if×10, do×6, while×6, goto×2, return×1.
//  - Notable callees: FUN_007a4480×2, CVOGReaction_GiveItemByCbid, CVOGReaction_ResolveObjectTarget, FUN_00498380, FUN_004bc180, FUN_00512160, FUN_00788db0, Object_ResolveFromTFID.
//  - Strings: "Could not find flair %d."; "allocatenewobjectfromcbid failed %d".
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

int __fastcall FUN_00498380(int param_1)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  void *pvVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *local_44;

  int local_40;

  int local_3c;

  int local_38;

  int local_34;

  int local_30;

  int local_2c;

  TFID_16 local_10;

  

  local_2c = DAT_00b041fc;

  uVar6 = 10000000;

  local_40 = 0;

  local_38 = 0;

  if (0 < *(int *)(param_1 + 0x10)) {

    local_44 = (uint32_t /* width from decompiler */ *)(param_1 + 0x14);

    do {

      uVar7 = *(uint *)*local_44;

      iVar9 = *(int *)(*(int *)(*(int *)(*(int *)(local_2c + 0xf10) + 0x10) +

                               (*(uint *)(*(int *)(local_2c + 0xf10) + 8) & uVar7) * 4) + 4);

      if (iVar9 == 0) {

LAB_004983f2:

        iVar9 = 0;

      }

      else {

        do {

          if (uVar7 == *(uint *)(iVar9 + 0x10)) {

            if (iVar9 == 0) goto LAB_004983f2;

            iVar9 = *(int *)(iVar9 + 8);

            goto LAB_004983f9;

          }

          iVar9 = *(int *)(iVar9 + 0xc);

        } while (iVar9 != 0);

        iVar9 = 0;

      }

LAB_004983f9:

      if (iVar9 == 0) {

        FUN_007a4480(1,"Could not find flair %d.",uVar7);

      }

      else {

        local_10.dwCoidLo = *(uint *)(iVar9 + 0x100);

        local_10.dwCoidHi = *(uint *)(iVar9 + 0x104);

        local_10._8_4_ = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x108);

        local_10._12_4_ = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x10c);

        pvVar5 = Object_ResolveFromTFID(&local_10);

        if (pvVar5 == (void *)0x0) {

          piVar2 = (int *)CVOGReaction_GiveItemByCbid(uVar7);

          if (piVar2 == (int *)0x0) {

            FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",uVar7);

          }

          else {

            (**(code **)(*piVar2 + 8))(uVar7,*(uint32_t /* width from decompiler */ *)(param_1 + 0xc4),0);

            *(byte *)((int)piVar2 + 0x17d) = *(byte *)((int)piVar2 + 0x17d) | 0x40;

            do {

              uVar7 = uVar6;

              uVar8 = uVar7 + 1;

              local_30 = local_30 + (uint)(0xfffffffe < uVar7);

              iVar3 = CVOGReaction_ResolveObjectTarget(0,uVar8,local_30);

              uVar6 = uVar8;

            } while (iVar3 != 0);

            FUN_00512160(uVar8,local_30,0);

            uVar6 = uVar7 + 2;

            local_30 = local_30 + (uint)(0xfffffffe < uVar8);

            FUN_004bc180(piVar2);

            *(uint *)(iVar9 + 0x100) = piVar2[0x58];

            *(int *)(iVar9 + 0x104) = piVar2[0x59];

            *(int *)(iVar9 + 0x108) = piVar2[0x5a];

            *(int *)(iVar9 + 0x10c) = piVar2[0x5b];

            puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar2 + 0x1cc))();

            local_2c = 0;

            (**(code **)*puVar4)(0,0,0,0,0,0,0,g_flOne,0);

            local_40 = local_40 + 1;

          }

        }

      }

      local_44 = local_44 + 1;

      local_38 = local_38 + 1;

    } while (local_38 < *(int *)(param_1 + 0x10));

  }

  if (*(void **)(param_1 + 0xb4) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0xb4));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = 0;

  }

  pvVar5 = operator_new__(0x52000);

  *(void **)(param_1 + 0xb4) = pvVar5;

  FUN_00788db0(pvVar5,0x52000);

  local_34 = 0;

  local_2c = 0;

  local_30 = 0;

  do {

    local_3c = 0;

    iVar9 = local_2c;

    local_44 = (uint32_t /* width from decompiler */ *)local_30;

    do {

      if ((*(int *)(iVar9 + *(int *)(param_1 + 0xb4)) < 0x28) &&

         (local_38 = 0, 0 < *(int *)(param_1 + 0x10))) {

        piVar2 = (int *)(param_1 + 0x14);

        do {

          iVar3 = *piVar2;

          if ((((*(byte *)(iVar3 + 0xe) & (byte)(1 << ((byte)local_3c & 0x1f))) != 0) &&

              ((int)(uint)*(byte *)(iVar3 + 0xc) <= local_34)) &&

             (local_34 <= (int)(uint)*(byte *)(iVar3 + 0xd))) {

            *(int *)(*(int *)(param_1 + 0xb4) + 4 +

                    (*(int *)(iVar9 + *(int *)(param_1 + 0xb4)) + (int)local_44) * 4) = iVar3;

            piVar1 = (int *)(iVar9 + *(int *)(param_1 + 0xb4));

            *piVar1 = *piVar1 + 1;

          }

          local_38 = local_38 + 1;

          piVar2 = piVar2 + 1;

        } while (local_38 < *(int *)(param_1 + 0x10));

      }

      local_44 = (uint32_t /* width from decompiler */ *)((int)local_44 + 0x2900);

      local_3c = local_3c + 1;

      iVar9 = iVar9 + 0xa400;

    } while (local_3c < 8);

    local_30 = local_30 + 0x29;

    local_34 = local_34 + 1;

    local_2c = local_2c + 0xa4;

  } while (local_30 < 0x2900);

  return local_40;

}
