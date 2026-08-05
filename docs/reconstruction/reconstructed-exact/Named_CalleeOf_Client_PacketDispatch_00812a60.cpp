// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_00812a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00812a60
// Callee of Client_PacketDispatch
// Address:   0x00812a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~159 non-empty decompiler lines.
//  - Control keywords: if×21, goto×3, do×1, while×1, return×1.
//  - Notable callees: CONCAT31, Client_EnqueueCombatFloater_INFERRED, FUN_00514ff0, FUN_005150d0, FUN_0056bab0, FUN_00812a60, FUN_0093e120, Object_ResolveFromTFID.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Client_PacketDispatch_00812a60(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  char cVar3;

  void *pvVar4;

  int *piVar5;

  void *pvVar6;

  uint8_t *puVar7;

  int iStack_70;

  int *piStack_6c;

  int iStack_64;

  int iStack_60;

  int iStack_5c;

  uint uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint8_t uStack_43;

  uint32_t /* width from decompiler */ uStack_42;

  uint32_t /* width from decompiler */ uStack_3e;

  uint8_t uStack_3a;

  int iStack_38;

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  int iStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint8_t uStack_10;

  uint8_t uStack_f;

  uint8_t uStack_e;

  uint8_t uStack_d;

  uint8_t uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  

  if (((*(int *)(param_1 + 0xc78) != 0) &&

      (cVar3 = (**(code **)(**(int **)(param_1 + 0xc78) + 8))(), cVar3 != '\0')) &&

     (*(int *)(param_1 + 0xe98) != 0)) {

    piStack_6c = (int *)CVOGReaction_ResolveObjectTarget

                                  (*(uint8_t *)(param_2 + 0x10),*(uint32_t /* width from decompiler */ *)(param_2 + 8),

                                   *(uint32_t /* width from decompiler */ *)(param_2 + 0xc));

    if (piStack_6c == (int *)0x0) {

      iStack_70 = 0;

      iStack_60 = 0;

    }

    else {

      iStack_70 = (**(code **)(*piStack_6c + 0x1e0))();

      iStack_60 = (**(code **)(*piStack_6c + 0x1d4))();

      if (iStack_70 != 0) {

        piStack_6c = (int *)piStack_6c[0x2b];

      }

      if (piStack_6c != (int *)0x0) {

        FUN_00514ff0(0);

      }

    }

    iStack_5c = 0;

    iStack_64 = 0;

    if (0 < *(int *)(param_2 + 0x18)) {

      puVar7 = (uint8_t *)(param_2 + 0x30);

      do {

        pvVar4 = Object_ResolveFromTFID((TFID_16 *)(puVar7 + -0x14));

        if (pvVar4 != (void *)0x0) {

          iVar1 = *(int *)(puVar7 + -4);

          if (iVar1 == 0) {

            if (iStack_70 != 0) {

LAB_00812ce2:

              uStack_43 = *puVar7;

              uStack_58 = ((TFID_16 *)(puVar7 + -0x14))->dwCoidLo;

              uStack_54 = *(uint32_t /* width from decompiler */ *)(puVar7 + -0x10);

              uStack_50 = *(uint32_t /* width from decompiler */ *)(puVar7 + -0xc);

              uStack_4c = *(uint32_t /* width from decompiler */ *)(puVar7 + -8);

              uStack_48 = *(uint32_t /* width from decompiler */ *)(puVar7 + -4);

              uStack_42 = *(uint32_t /* width from decompiler */ *)(puVar7 + 1);

              uStack_3e = *(uint32_t /* width from decompiler */ *)(puVar7 + 5);

              uStack_3a = puVar7[9];

              piVar5 = piStack_6c;

              if (piStack_6c == (int *)0x0) {

                if (iStack_70 == 0) {

                  piVar5 = (int *)0x0;

                }

                else {

                  piVar5 = (int *)(*(int *)(*(int *)(iStack_70 + 4) + 4) + 4 + iStack_70);

                }

              }

              FUN_0056bab0(piVar5,pvVar4,&uStack_58,iVar1,

                           CONCAT31((int3)((uint)uStack_3e >> 8),0 < iStack_64));

            }

          }

          else {

            if ((*(uint *)((int)pvVar4 + 0x17c) >> 5 & 1) == 0) goto LAB_00812d59;

            if (piStack_6c != (int *)0x0) {

              (**(code **)(*piStack_6c + 0x214))();

              piVar5 = (int *)FUN_005150d0();

              if (piVar5 != (int *)0x0) {

                (**(code **)(*piVar5 + 0x4c))(pvVar4,iVar1);

              }

              if (*(int *)(param_1 + 0x3048) == 0) {

                iVar2 = *(int *)(param_1 + 0xe98);

                if (iVar2 == 0) {

                  pvVar6 = (void *)0x0;

                }

                else {

                  pvVar6 = (void *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                                   *(int *)(param_1 + 0xe98));

                }

                if (pvVar4 != pvVar6) {

                  pvVar6 = *(void **)(iVar2 + 0x250);

                  if (pvVar6 != (void *)0x0) {

                    pvVar6 = (void *)(*(int *)(*(int *)((int)pvVar6 + 4) + 4) + 4 + (int)pvVar6);

                  }

                  if ((pvVar4 != pvVar6) &&

                     ((*(char *)(iVar2 + 0x6b9) == '\0' ||

                      (pvVar4 != *(void **)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) +

                                            0xa4 + *(int *)(param_1 + 0xe98)))))) goto LAB_00812c36;

                }

                if ((*(int *)(piStack_6c[0x2a] + 0x38) == 0x12) ||

                   (*(int *)(piStack_6c[0x2a] + 0x38) == 0xe)) {

                  FUN_0093e120(piStack_6c);

                }

              }

            }

LAB_00812c36:

            if (iStack_70 != 0) goto LAB_00812ce2;

            piVar5 = piStack_6c + 0x58;

            if (piStack_6c == (int *)0x0) {

              piVar5 = &DAT_00a1e840;

            }

            iStack_38 = *piVar5;

            iStack_34 = piVar5[1];

            iStack_30 = piVar5[2];

            iStack_2c = piVar5[3];

            uStack_28 = *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x160);

            uStack_24 = *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x164);

            uStack_20 = *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x168);

            uStack_1c = *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x16c);

            uStack_f = *puVar7;

            uStack_d = puVar7[7];

            uStack_10 = iStack_60 != 0;

            uStack_c = puVar7[8];

            uStack_14 = 0;

            uStack_e = 0;

            uStack_8 = 0;

            iStack_18 = iVar1;

            Client_EnqueueCombatFloater_INFERRED(&iStack_38);

          }

          iStack_64 = iStack_64 + 1;

        }

LAB_00812d59:

        iStack_5c = iStack_5c + 1;

        puVar7 = puVar7 + 0x20;

      } while (iStack_5c < *(int *)(param_2 + 0x18));

    }

  }

  return;

}
