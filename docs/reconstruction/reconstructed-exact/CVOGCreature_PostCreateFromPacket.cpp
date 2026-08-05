// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×17, goto×1, return×1.
//  - Notable callees: FUN_004962b0, FUN_004bafe0, FUN_004c49d0, FUN_004cf320, FUN_00516720, FUN_00516a00, FUN_0053d970, FUN_00568640.
//  - Strings: "%S %s"; "generic_elite".
//  - Return sites: 1.

// =============================================================================
// CVOGCreature_PostCreateFromPacket
// -----------------------------------------------------------------------------
// Stable ID: aa_004c5c30
// Address:   0x004c5c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

CVOGCreature_PostCreateFromPacket

          (int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

          uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  int *piVar1;

  bool bVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  void *pvVar7;

  uint32_t /* width from decompiler */ uStack_74;

  uint32_t /* width from decompiler */ uStack_70;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  char acStack_64 [100];

  

  if ((char)param_7 != '\0') {

    FUN_005c93f0(param_2,param_3,param_4,param_5,param_6,param_7);

  }

  iVar4 = *(int *)(param_1 + -0x4f8);

  piVar1 = (int *)(param_1 + -0x500);

  if (iVar4 != 0) {

    if ((*(char *)(iVar4 + 0x40) == '\0') || (*(int *)(iVar4 + 8) == 0)) {

      bVar2 = true;

    }

    else {

      bVar2 = false;

    }

    if (bVar2) {

      FUN_0053d970(1);

    }

  }

  cVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) + 0x198

                      ))();

  if (cVar3 == '\0') {

    FUN_00516a00(0);

    if (param_3 == 2) {

      iVar5 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

      iVar4 = iVar5 + param_1;

      if (*(int *)(*(int *)(iVar5 + -0x454 + param_1) + 0x38) == 0x12) {

        if ((*(uint *)(param_2 + 0xf8) & *(uint *)(param_2 + 0xfc)) != 0xffffffff) {

          iVar4 = FUN_004bafe0(*(uint8_t *)

                                (*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x394 + param_1),

                               *(uint *)(param_2 + 0xf8),*(uint *)(param_2 + 0xfc));

          if (iVar4 != 0) {

            uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + -0x3d8);

            FUN_004cf320(uVar6);

            iVar5 = FUN_00568640(uVar6);

            if ((iVar5 != 0) && (99 < *(short *)(iVar5 + 0x12))) {

              uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x15c))

                                ();

              sprintf(acStack_64,"%S %s",iVar5 + 0x16,uVar6);

              FUN_00516720(acStack_64);

            }

            FUN_004c49d0(iVar4);

            if (*(int *)(iVar4 + 8) != 0) {

              *(bool *)(iVar4 + 0x101) = *(char *)(param_1 + -500) == '\0';

            }

          }

          goto LAB_004c5e82;

        }

      }

      if (*(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + 0xac + (int)piVar1

                                      ) + 0x3c) + 0x4c0) == DAT_00aaa668) {

        *(int **)(*(int *)(iVar4 + -0x458) + 0xe4f0) = piVar1;

      }

      else if (((char)param_6 == '\0') || ((*(uint *)(iVar4 + -0x380) >> 6 & 1) == 0)) {

        iVar4 = *piVar1;

        uStack_74 = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2d8);

        uStack_70 = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2d4);

        uStack_6c = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2d0);

        uStack_68 = *(uint32_t /* width from decompiler */ *)(param_1 + -0x2cc);

        uVar6 = 0xffffffff;

        iVar5 = TFID_NotEquals(&uStack_74,&DAT_009cb8c0);

        (**(code **)(iVar4 + 0xc0))(iVar5,uVar6);

      }

    }

  }

LAB_004c5e82:

  if (*(char *)(param_1 + -0x1f5) != '\0') {

    pvVar7 = NDSpecialFX_LoadFromScriptName("generic_elite",-1,0);

    if (pvVar7 != (void *)0x0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) + 0xf8))

                (pvVar7,1,0);

    }

  }

  iVar4 = *(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x458 + param_1);

  if ((iVar4 != 0) && (*(int *)(iVar4 + 0xe898) != 0)) {

    FUN_004962b0();

  }

  if ((*(int *)(param_1 + -0x304) == 0) &&

     ((*(uint *)(param_2 + 0xf8) & *(uint *)(param_2 + 0xfc)) == 0xffffffff)) {

    uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) +

                        0x160))();

    FUN_007a4480(1,"Creature/character %s created from packet without an HBAI created...!!!",uVar6);

  }

  return;

}
