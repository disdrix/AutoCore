// READABILITY (auto CF):
//  - Body size: ~171 non-empty decompiler lines.
//  - Control keywords: if×24, goto×5, return×5, for×4, while×1.
//  - Notable callees: FUN_00681020×2, FUN_0076cec0×2, vog_LogMessage×2, FUN_00685210.
//  - Strings: "Packet digest check failed"; "Packet decryption failed during receive!".
//  - Return sites: 5.

// =============================================================================
// Named_netBaseUdpConnection_00685210
// -----------------------------------------------------------------------------
// Stable ID: aa_00685210
// Address:   0x00685210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "netBaseUdpConnection"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_netBaseUdpConnection_00685210(int *param_1)



{

  char cVar1;

  uint uVar2;

  void *pvVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint uVar7;

  uint unaff_ESI;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  bool bVar11;

  uint uStack_14;

  uint8_t auStack_10 [12];

  uint32_t /* width from decompiler */ *puStack_4;

  

  uVar2 = (**(code **)(*param_1 + 0x4c))();

  bVar11 = uVar2 == 0;

  uStack_14 = uVar2;

  if (!bVar11) {

    if ((uint)param_1[0x22] < uVar2) {

      if ((void *)param_1[0x20] != (void *)0x0) {

        operator_delete__((void *)param_1[0x20]);

      }

      pvVar3 = operator_new__(uVar2);

      param_1[0x20] = (int)pvVar3;

      param_1[0x22] = uVar2;

    }

    bVar11 = uStack_14 == 0;

  }

  if (!bVar11) {

    while (cVar1 = (**(code **)(*param_1 + 0x40))(param_1[0x20],&uStack_14,0), puVar9 = puStack_4,

          cVar1 == '\x01') {

      if (unaff_ESI < 8) {

LAB_00685474:

        uVar2 = (**(code **)(*param_1 + 0x4c))();

        bVar11 = uVar2 == 0;

        uStack_14 = uVar2;

        if (!bVar11) {

          if ((uint)param_1[0x22] < uVar2) {

LAB_0068548d:

            uStack_14 = uVar2;

            if ((void *)param_1[0x20] != (void *)0x0) {

              operator_delete__((void *)param_1[0x20]);

            }

            pvVar3 = operator_new__(uVar2);

            param_1[0x20] = (int)pvVar3;

            param_1[0x22] = uVar2;

          }

          goto LAB_006854b9;

        }

      }

      else {

        uVar7 = unaff_ESI - 8;

        puVar8 = (uint32_t /* width from decompiler */ *)param_1[0x20];

        *puStack_4 = *puVar8;

        *(uint8_t *)(puStack_4 + 1) = *(uint8_t *)(puVar8 + 1);

        *(uint8_t *)((int)puStack_4 + 5) = *(uint8_t *)((int)puVar8 + 5);

        *(uint16_t *)((int)puStack_4 + 6) = *(uint16_t *)((int)puVar8 + 6);

        uVar2 = uVar7;

        if (uVar7 == 0) {

          if ((uint)param_1[0x21] < 8) {

            if ((void *)param_1[0x1f] != (void *)0x0) {

              operator_delete__((void *)param_1[0x1f]);

            }

            pvVar3 = operator_new__(8);

            param_1[0x1f] = (int)pvVar3;

            param_1[0x21] = 8;

          }

LAB_00685408:

          puVar8 = (uint32_t /* width from decompiler */ *)param_1[0x1f];

          *puVar8 = *puVar9;

          *(uint8_t *)(puVar8 + 1) = *(uint8_t *)(puVar9 + 1);

          *(uint8_t *)((int)puVar8 + 5) = *(uint8_t *)((int)puVar9 + 5);

          *(uint16_t *)((int)puVar8 + 6) = *(uint16_t *)((int)puVar9 + 6);

          if (7 < uVar2 + 8) {

            if ((char)param_1[2] == '\0') {

              cVar1 = (**(code **)(*(int *)param_1[3] + 0x1c))

                                ((uint32_t /* width from decompiler */ *)param_1[0x1f] + 1,uVar2 + 4,

                                 *(uint32_t /* width from decompiler */ *)param_1[0x1f]);

            }

            else {

              cVar1 = (**(code **)(*(int *)param_1[3] + 0x24))();

            }

            if (cVar1 != '\0') {

              if (uVar2 != 0) {

                puStack_4 = operator_new__(uVar2);

                puVar9 = (uint32_t /* width from decompiler */ *)(param_1[0x1f] + 8);

                puVar8 = puStack_4;

                for (uVar7 = uVar2 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

                  *puVar8 = *puVar9;

                  puVar9 = puVar9 + 1;

                  puVar8 = puVar8 + 1;

                }

                for (uVar7 = uVar2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

                  *(uint8_t *)puVar8 = *(uint8_t *)puVar9;

                  puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

                  puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

                }

                FUN_00681020(&puStack_4,uVar2,1);

                return 1;

              }

              puStack_4 = (uint32_t /* width from decompiler */ *)0x0;

              FUN_00681020(&puStack_4,0,1);

              return 1;

            }

          }

          uVar5 = FUN_0076cec0(auStack_10,"Packet digest check failed");

          vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netBaseUdpConnection.cpp"

                         ,599,2,uVar5);

          goto LAB_00685474;

        }

        if ((char)param_1[2] == '\0') {

          if (((uint)param_1[0x21] < unaff_ESI) && (unaff_ESI != 0)) {

            if ((void *)param_1[0x1f] != (void *)0x0) {

              operator_delete__((void *)param_1[0x1f]);

            }

            pvVar3 = operator_new__(unaff_ESI);

            param_1[0x1f] = (int)pvVar3;

            param_1[0x21] = unaff_ESI;

          }

          puVar8 = (uint32_t /* width from decompiler */ *)(param_1[0x20] + 8);

          puVar10 = (uint32_t /* width from decompiler */ *)(param_1[0x1f] + 8);

          for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

            *puVar10 = *puVar8;

            puVar8 = puVar8 + 1;

            puVar10 = puVar10 + 1;

          }

          for (uVar7 = uVar7 & 3; puVar9 = puStack_4, uVar7 != 0; uVar7 = uVar7 - 1) {

            *(uint8_t *)puVar10 = *(uint8_t *)puVar8;

            puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

            puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

          }

          goto LAB_00685408;

        }

        unaff_ESI = (**(code **)(*(int *)param_1[3] + 0x10))(uVar7);

        uVar2 = unaff_ESI + 8;

        if (((uint)param_1[0x21] < uVar2) && (uVar2 != 0)) {

          if ((void *)param_1[0x1f] != (void *)0x0) {

            operator_delete__((void *)param_1[0x1f]);

          }

          pvVar3 = operator_new__(uVar2);

          param_1[0x1f] = (int)pvVar3;

          param_1[0x21] = uVar2;

        }

        uVar2 = param_1[0x1f] + 8;

        iVar4 = (**(code **)(*(int *)param_1[3] + 0x14))

                          (&stack0xffffffe4,&stack0xffffffe0,param_1[0x20] + 8,uVar7,0);

        if (iVar4 == 0) goto LAB_00685408;

        uVar5 = FUN_0076cec0(&uStack_14,"Packet decryption failed during receive!");

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netBaseUdpConnection.cpp"

                       ,0x224,2,uVar5);

        uVar2 = (**(code **)(*param_1 + 0x4c))();

        uStack_14 = uVar2;

        if ((uint)param_1[0x22] < uVar2) {

          if (uVar2 == 0) {

            return 0;

          }

          goto LAB_0068548d;

        }

LAB_006854b9:

        bVar11 = uStack_14 == 0;

      }

      if (bVar11) {

        return 0;

      }

    }

  }

  return 0;

}
