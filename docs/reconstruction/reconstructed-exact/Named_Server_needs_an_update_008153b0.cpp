// READABILITY (auto CF):
//  - Body size: ~135 non-empty decompiler lines.
//  - Control keywords: if×17, for×3, goto×3, do×2, while×2, return×1.
//  - Notable callees: FUN_007a4480×7, FUN_007a6de0×6, FUN_00541a80×4, sprintf×2, Client_GetMissionCompleteAudioTable, FUN_00403450, FUN_00411e40, FUN_005569a0.
//  - Strings: "start MapInfo for"; "%s <%s>"; "mapinfo:after reinitphysics"; "Server needs an update".
//  - Return sites: 1.

// =============================================================================
// Named_Server_needs_an_update_008153b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008153b0
// Address:   0x008153b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Server needs an update"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x00815602) */



void Named_Server_needs_an_update_008153b0(int param_1,int param_2)



{

  byte bVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  byte *pbVar8;

  int iVar9;

  byte *pbVar10;

  bool bVar11;

  char *pcVar12;

  byte local_28c [128];

  char local_20c [512];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009bbae1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007a69d0();

  iVar4 = param_2 + 0x1c;

  uVar3 = FUN_007a6de0("start MapInfo for",0xffffffff);

  FUN_007a4480(0,"%s <%s>",uVar3,iVar4);

  DAT_00d17930 = 0;

  if ((*(char *)(param_2 + 0x5e) != '\0') && (*(int *)(param_1 + 0xdec) != 0)) {

    FUN_0066e8d0();

  }

  Client_GetMissionCompleteAudioTable();

  FUN_007246d0();

  FUN_00943db0();

  FUN_00943b80(0);

  iVar4 = FUN_009463b0(param_1);

  if (-1 < iVar4) {

    FUN_007a4480(0,"mapinfo:after reinitphysics");

    iVar4 = *(int *)(param_2 + 0x6c);

    if (iVar4 != *(int *)(*(int *)(*(int *)(param_1 + 0xe04) + 0xe4f8) + 4)) {

      iVar9 = *(int *)(*(int *)(param_1 + 0xe04) + 0xe4f8);

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar9 + 4);

      uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x109c);

      if (iVar4 < *(int *)(iVar9 + 4)) {

        uVar5 = FUN_007a6de0("Server needs an update",0xffffffff);

        uVar6 = FUN_007a6de0("Map versions incorrect",0xffffffff);

        sprintf(local_20c,"%s. %s: S:%d C:%d.",uVar6,uVar5,iVar4,uVar3);

      }

      else {

        uVar3 = FUN_007a6de0("Client needs an update",0xffffffff);

        uVar5 = FUN_007a6de0("Map versions incorrect",0xffffffff);

        sprintf(local_20c,"%s. %s: S:%d C:%d.",uVar5,uVar3);

      }

      pcVar12 = local_20c;

      uVar5 = 0;

      uVar3 = FUN_007a6de0("Map Error",0xffffffff);

      FUN_008f8200(uVar2,0x18,uVar3,pcVar12,uVar5);

      FUN_007a4480(1,local_20c);

    }

    FUN_005569a0(param_2 + 0x90);

    if (*(char *)(param_1 + 0x1b) != '\0') {

      iVar4 = FUN_00541a80();

      if (*(char *)(iVar4 + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      *(uint8_t *)(iVar4 + 0x1d) = 1;

      FUN_00541a80();

      puVar7 = (uint32_t /* width from decompiler */ *)FUN_00411e40();

      if (puVar7 != (uint32_t /* width from decompiler */ *)0x0) {

        iVar4 = 0;

        do {

          pbVar10 = local_28c;

          uVar3 = (*(code *)PTR_FUN_00af8c9c)();

          FUN_00403450(puVar7 + 7,uVar3);

          uStack_4 = 0xffffffff;

          pbVar8 = (byte *)(*(int *)(param_1 + 0xe04) + 0xb4);

          do {

            bVar1 = *pbVar8;

            bVar11 = bVar1 < *pbVar10;

            if (bVar1 != *pbVar10) {

LAB_00815644:

              iVar9 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);

              goto LAB_00815649;

            }

            if (bVar1 == 0) break;

            bVar1 = pbVar8[1];

            bVar11 = bVar1 < pbVar10[1];

            if (bVar1 != pbVar10[1]) goto LAB_00815644;

            pbVar8 = pbVar8 + 2;

            pbVar10 = pbVar10 + 2;

          } while (bVar1 != 0);

          iVar9 = 0;

LAB_00815649:

          if (iVar9 == 0) {

            *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xfc) = *puVar7;

          }

          iVar9 = FUN_00541a80();

          if (*(char *)(iVar9 + 0x1d) == '\0') {

            FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

            FUN_007a4480(0,"VOG_DEBUG_STOP");

          }

          if (iVar4 == 0) {

            iVar4 = *(int *)(iVar9 + 0x14);

            if (iVar4 == 0) goto LAB_0081569f;

            puVar7 = *(uint32_t /* width from decompiler */ **)(iVar4 + 8);

          }

          else {

            iVar4 = *(int *)(iVar4 + 0x14);

            if (iVar4 == 0) {

LAB_0081569f:

              puVar7 = (uint32_t /* width from decompiler */ *)0x0;

            }

            else {

              puVar7 = *(uint32_t /* width from decompiler */ **)(iVar4 + 8);

            }

          }

        } while (puVar7 != (uint32_t /* width from decompiler */ *)0x0);

      }

      iVar4 = FUN_00541a80();

      *(uint8_t *)(iVar4 + 0x1d) = 0;

    }

    if (*(int *)(param_1 + 0x10cc) != 0) {

      FUN_00871b90();

    }

    FUN_007fd930();

    if (*(int *)(param_1 + 0x10ec) != 0) {

      FUN_00890660(*(int *)(param_1 + 0x10ec));

    }

    FUN_007fe2c0();

  }

  ExceptionList = local_c;

  return;

}
