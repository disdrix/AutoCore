// =============================================================================
// FUN_005c8b30
// -----------------------------------------------------------------------------
// Stable ID: aa_005c8b30
// Address:   0x005c8b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c8b30 @ 0x005c8b30
// Stable ID: aa_005c8b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: FUN_004bc180, FUN_004c0140, FUN_005c8b30, FUN_00797170.
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

void __thiscall

FUN_005c8b30(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  uint *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ unaff_ESI;

  int unaff_retaddr;

  

  uVar5 = param_3;

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 0x218))

            (param_4);

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 0xc0))

            (unaff_retaddr,param_2,param_7);

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 0x230))();

  if (param_4 != 0) {

    uVar2 = *(uint32_t /* width from decompiler */ *)(unaff_retaddr + 100);

    uVar8 = *(uint32_t /* width from decompiler */ *)(unaff_retaddr + 0x68);

    puVar7 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0x3c + param_1);

    puVar7[2] = *(uint32_t /* width from decompiler */ *)(unaff_retaddr + 0x6c);

    *puVar7 = uVar2;

    puVar7[1] = uVar8;

    puVar7[3] = 0;

    FUN_00797170(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0x2c + param_1);

    if (((char)unaff_retaddr != '\0') && (*(int *)(param_4 + 0xe4e8) != 0)) {

      if (param_1 == 0xc0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1;

      }

      FUN_004bc180(iVar6);

    }

    if (((((char)param_2 != '\0') &&

         (uVar3 = *(uint *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + 0xc0 + param_1),

         (uVar3 >> 5 & 1) != 0)) && (*(char *)(unaff_retaddr + 0xa2) == '\0')) &&

       (((char)param_3 == '\0' || ((uVar3 >> 6 & 1) == 0)))) {

      puVar7 = (uint32_t /* width from decompiler */ *)

               (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) +

                           0x1c8))();

      iVar6 = *(int *)(*(int *)(param_1 + -0xbc) + 4) + param_1;

      (**(code **)*puVar7)(param_4,iVar6 + -0x3c,iVar6 + -0x2c,0);

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xac + param_1) =

         *(uint32_t /* width from decompiler */ *)(unaff_retaddr + 0x1c);

    puVar1 = (uint *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + 0xc0 + param_1);

    *puVar1 = *puVar1 ^ ((uint)*(byte *)(unaff_retaddr + 0x8a) << 8 ^ *puVar1) & 0x100;

    if ((char)param_3 == '\0') {

      if (*(char *)(unaff_retaddr + 0xa2) == '\0') {

        (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 0x28))();

      }

    }

    else {

      iVar6 = *(int *)(*(int *)(param_1 + -0xbc) + 4);

      uVar3 = *(uint *)(iVar6 + 0xc0 + param_1);

      if (((uVar3 >> 6 & 1) != 0) && (*(char *)(unaff_retaddr + 0xa2) == '\0')) {

        iVar6 = *(int *)(iVar6 + param_1 + -0x14);

        iVar4 = *(int *)(iVar6 + 0x38);

        param_3 = 0;

        if ((((iVar4 == 0x12) || (((iVar4 == 0xe || (iVar4 == 0xc)) || (iVar4 == 0x14)))) ||

            (((iVar4 == 0x1c || (iVar4 == 10)) || (iVar4 == 0x10)))) ||

           ((iVar4 == 6 && (*(short *)(*(int *)(iVar6 + 0x3c) + 0x3f4) == 10)))) {

          param_3 = 0;

        }

        else if (((((uVar3 >> 5 & 1) != 0) &&

                  (iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc +

                                                param_1) + 0x1c8))(), iVar6 != 0)) &&

                 (*(int *)(iVar6 + 8) != 0)) && (*(char *)(*(int *)(iVar6 + 8) + 0x40) != '\0')) {

          param_3 = 1;

        }

        uVar8 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) +

                            0x1cc))();

        FUN_004c0140(uVar8,unaff_retaddr,unaff_ESI,unaff_retaddr,param_2,uVar5,param_3,param_4);

        return;

      }

    }

  }

  return;

}
