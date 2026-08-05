// =============================================================================
// FUN_008b3400
// -----------------------------------------------------------------------------
// Stable ID: aa_008b3400
// Address:   0x008b3400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b3400 @ 0x008b3400
// Stable ID: aa_008b3400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×20, do×1, goto×1, while×1, return×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_00522000, FUN_00599dd0, FUN_00792250, FUN_008b30c0, FUN_008b3400.
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

void __thiscall FUN_008b3400(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int iVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  int *piVar6;

  uint uVar7;

  

  FUN_00792250(param_2,param_3);

  if ((char)param_2 != '\0') {

    cVar2 = (**(code **)(*param_1 + 0x3d8))();

    if (cVar2 != '\0') {

      if (DAT_00d1b6d8 == 0) {

        param_3 = 8;

      }

      else {

        param_3 = FUN_00522000();

      }

      uVar5 = 0;

      piVar6 = param_1 + 0x163;

      do {

        if (DAT_00d1b6d8 == 0) {

          uVar7 = 0xffffffff;

          uVar3 = 0xffffffff;

        }

        else {

          uVar7 = *(uint *)(DAT_00d1b6d8 + 0x5a0 + (uVar5 & 0xff) * 8);

          uVar3 = *(uint *)(DAT_00d1b6d8 + 0x5a4 + (uVar5 & 0xff) * 8);

        }

        iVar4 = 0;

        if (((DAT_00d1b6d8 != 0) &&

            (iVar1 = *(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8),

            iVar1 != 0)) && (*(int *)(iVar1 + 0xe4e8) != 0)) {

          iVar4 = CVOGReaction_ResolveObjectTarget(1,uVar7,uVar3);

        }

        if (((((uVar7 & uVar3) == 0xffffffff) || ((int)uVar5 < param_1[0x1ab])) ||

            ((param_1[0x1ab] + 5 <= (int)uVar5 || ((param_3 <= (int)uVar5 || (iVar4 == 0)))))) ||

           (*(int *)(*(int *)(iVar4 + 0xa8) + 0x3c) == 0)) {

LAB_008b34ef:

          if (((int)uVar5 < param_1[0x1ab]) || (param_1[0x1ab] + 5 <= (int)uVar5)) {

            if (piVar6[-8] != 0) {

              (**(code **)(*(int *)piVar6[-8] + 0xcc))(0);

            }

            if (*piVar6 != 0) {

              (**(code **)(*(int *)*piVar6 + 0xcc))(0);

            }

          }

          if (piVar6[0x4b] != 0) {

            (**(code **)(*(int *)piVar6[0x4b] + 0xcc))(0);

          }

          if (piVar6[0x53] != 0) {

            (**(code **)(*(int *)piVar6[0x53] + 0xcc))(0);

          }

          if (piVar6[0x18] != 0) {

            (**(code **)(*(int *)piVar6[0x18] + 0xcc))(0);

          }

          if (piVar6[0x20] != 0) {

            (**(code **)(*(int *)piVar6[0x20] + 0xcc))(0);

          }

          if (piVar6[8] != 0) {

            (**(code **)(*(int *)piVar6[8] + 0xcc))(0);

          }

          if (piVar6[0x10] != 0) {

            (**(code **)(*(int *)piVar6[0x10] + 0xcc))(0);

          }

          if (piVar6[0x28] != 0) {

            (**(code **)(*(int *)piVar6[0x28] + 0xcc))(0);

          }

          if (piVar6[0x30] != 0) {

            (**(code **)(*(int *)piVar6[0x30] + 0xcc))(0);

          }

          if (piVar6[0x38] != 0) {

            (**(code **)(*(int *)piVar6[0x38] + 0xcc))(0);

          }

          if (piVar6[0x40] != 0) {

            (**(code **)(*(int *)piVar6[0x40] + 0xcc))(0);

          }

        }

        else {

          iVar4 = FUN_00599dd0();

          if (iVar4 == 0) goto LAB_008b34ef;

        }

        uVar5 = uVar5 + 1;

        piVar6 = piVar6 + 1;

      } while ((int)uVar5 < 8);

      FUN_008b30c0((char)param_1[0x1c3]);

    }

  }

  return;

}
