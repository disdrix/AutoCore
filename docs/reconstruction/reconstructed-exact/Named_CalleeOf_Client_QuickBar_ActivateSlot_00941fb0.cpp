// =============================================================================
// Named_CalleeOf_Client_QuickBar_ActivateSlot_00941fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00941fb0
// Callee of Client_QuickBar_ActivateSlot (+1 other named callers)
// Address:   0x00941fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_QuickBar_ActivateSlot: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_QuickBar_ActivateSlot (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~199 non-empty decompiler lines.
//  - Control keywords: if×17, return×8, do×7, while×7, switch×1, for×1.
//  - Notable callees: CONCAT22×3, FUN_00807440×3, Client_SendSectorPacket×2, FUN_008073b0×2, FUN_007a75e0, FUN_00807370, FUN_00865970, FUN_008f8200.
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Callee of Client_QuickBar_ActivateSlot (+1 other named callers)
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

int __fastcall Named_CalleeOf_Client_QuickBar_ActivateSlot_00941fb0(char *param_1,char *param_2,void *param_3,int param_4,char param_5)



{

  int iVar1;

  char cVar2;

  short sVar3;

  char *pcVar4;

  char *pcVar5;

  int iVar6;

  DWORD DVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int local_c38;

  char local_c34 [4];

  char local_c30 [16];

  uint32_t /* width from decompiler */ uStack_c20;

  int iStack_c1c;

  uint8_t uStack_c18;

  char local_c17 [17];

  char local_c06 [18];

  uint32_t /* width from decompiler */ uStack_bf4;

  uint32_t /* width from decompiler */ local_808;

  int local_804;

  uint32_t /* width from decompiler */ local_800;

  uint32_t /* width from decompiler */ local_7fc;

  uint8_t local_7f8;

  uint32_t /* width from decompiler */ local_7f6;

  char local_7e3 [1003];

  uint16_t uStack_3f8;

  uint32_t /* width from decompiler */ auStack_3f6 [252];

  

  if (param_2 != (char *)0x0) {

    local_c38 = 0;

    pcVar4 = param_2;

    do {

      cVar2 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar2 != '\0');

    if (0 < (int)pcVar4 - (int)(param_2 + 1)) {

      if ((DAT_00af9218 & 1 << ((byte)param_4 & 0x1f)) == 0) {

        return 0;

      }

      iVar6 = *(int *)((int)param_3 + 0xe98);

      if (iVar6 == 0) {

        local_c34 = (char  [4])s_DEBUG_00a28b7c._0_4_;

        local_c30._0_2_ = s_DEBUG_00a28b7c._4_2_;

      }

      else {

        pcVar5 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) +

                                     0x160))();

        pcVar4 = local_c34;

        do {

          cVar2 = *pcVar5;

          *pcVar4 = cVar2;

          pcVar5 = pcVar5 + 1;

          pcVar4 = pcVar4 + 1;

        } while (cVar2 != '\0');

      }

      local_800 = 0xffffffff;

      local_7fc = 0xffffffff;

      local_7f6 = (uint)local_7f6._3_1_ << 0x18;

      local_7e3[0] = '\0';

      local_7f8 = 0;

      local_808 = 0x2021;

      local_804 = 5;

      local_c06[0] = '\0';

      uStack_bf4 = (uint)uStack_bf4._3_1_ << 0x18;

      local_c17[0] = '\0';

      uStack_c18 = 0;

      uStack_c20 = 0x8000;

      iStack_c1c = param_4;

      strncpy((char *)((int)&uStack_bf4 + 2),param_2,1000);

      iVar6 = -(int)param_1;

      do {

        cVar2 = *param_1;

        param_1[(int)(local_c17 + iVar6)] = cVar2;

        param_1 = param_1 + 1;

      } while (cVar2 != '\0');

      iVar6 = 0;

      do {

        pcVar4 = local_c34 + iVar6;

        local_c06[iVar6] = *pcVar4;

        iVar6 = iVar6 + 1;

      } while (*pcVar4 != '\0');

      pcVar4 = (char *)((int)&uStack_bf4 + 2);

      do {

        cVar2 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      sVar3 = (short)pcVar4 - ((short)&uStack_bf4 + 3);

      uStack_bf4 = CONCAT22(uStack_bf4._2_2_,sVar3);

      if (param_5 != '\0') {

        local_c38 = FUN_0093bd10(param_3,&uStack_c20);

        sVar3 = (short)uStack_bf4;

      }

      if (0 < sVar3) {

        if (param_5 != '\0') {

          FUN_00865970();

          sVar3 = (short)uStack_bf4;

        }

        if (local_c38 != 0) {

          return local_c38;

        }

        switch(iStack_c1c) {

        case 1:

        case 2:

        case 4:

        case 0xd:

        case 0xe:

        case 0xf:

          if ((iStack_c1c == 2) && (param_5 != '\0')) {

            uStack_3f8 = 0;

            puVar9 = auStack_3f6;

            for (iVar6 = 0xf9; iVar6 != 0; iVar6 = iVar6 + -1) {

              *puVar9 = 0;

              puVar9 = puVar9 + 1;

            }

            *(uint16_t *)puVar9 = 0;

            FUN_007a75e0();

            if (DAT_00d1b8dc != 0) {

              FUN_008f8200(DAT_00d1b8dc,7,local_c17,&uStack_3f8,0);

            }

          }

          cVar2 = FUN_00807370();

          if (cVar2 != '\0') {

            iVar6 = FUN_008073b0(uStack_bf4 + 0x31,&uStack_c20);

            return iVar6;

          }

          break;

        case 3:

          iVar6 = *(int *)((int)param_3 + 0xe98);

          iVar1 = *(int *)(*(int *)(iVar6 + 4) + 4);

          iVar8 = iVar1 + iVar6;

          if (*(char *)(*(int *)(iVar1 + 0xa8 + iVar6) + 0xf6) == '\0') {

            cVar2 = FUN_00807440();

            if (cVar2 != '\0') {

              iVar6 = FUN_008073b0(uStack_bf4 + 0x31,&uStack_c20);

              return iVar6;

            }

          }

          else {

            if (iVar6 == 0) {

              local_800 = 0xffffffff;

              local_7fc = 0xffffffff;

            }

            else {

              local_800 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x164);

              local_7fc = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x168);

            }

            local_804 = iStack_c1c;

            local_7f6 = CONCAT22(local_7f6._2_2_,sVar3);

            iVar6 = 0;

            do {

              cVar2 = *(char *)((int)&uStack_bf4 + iVar6 + 2);

              local_7e3[iVar6] = cVar2;

              iVar6 = iVar6 + 1;

            } while (cVar2 != '\0');

            cVar2 = FUN_00807440();

            if (cVar2 != '\0') {

              iVar6 = Client_SendSectorPacket(param_3,(short)local_7f6 + 0x29,&local_808);

              return iVar6;

            }

          }

          break;

        case 5:

        case 8:

        case 9:

        case 10:

          iVar6 = *(int *)((int)param_3 + 0xe98);

          if (iVar6 == 0) {

            local_800 = 0xffffffff;

            local_7fc = 0xffffffff;

          }

          else {

            iVar1 = *(int *)(*(int *)(iVar6 + 4) + 4);

            local_800 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + iVar6);

            local_7fc = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + iVar6);

          }

          local_804 = iStack_c1c;

          local_7f6 = CONCAT22(local_7f6._2_2_,sVar3);

          iVar6 = 0;

          do {

            cVar2 = *(char *)((int)&uStack_bf4 + iVar6 + 2);

            local_7e3[iVar6] = cVar2;

            iVar6 = iVar6 + 1;

          } while (cVar2 != '\0');

          DVar7 = GetTickCount();

          *(DWORD *)((int)param_3 + 0x30e8) = DVar7;

          *(int *)((int)param_3 + 0x30ec) = (int)(short)uStack_bf4;

          cVar2 = FUN_00807440();

          if (cVar2 != '\0') {

            iVar6 = Client_SendSectorPacket(param_3,(short)local_7f6 + 0x29,&local_808);

            return iVar6;

          }

        }

        return 1;

      }

    }

  }

  return -0x7ff8ffa9;

}
