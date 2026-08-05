// =============================================================================
// FUN_00731d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00731d70
// Address:   0x00731d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00731d70 @ 0x00731d70
// Stable ID: aa_00731d70
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceInstancing.cpp"
//   - "Error locking source vertex buffer for instancing.\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: if×10, for×4, return×2, do×1, switch×1, goto×1, while×1.
//  - Notable callees: FUN_0076f240×2, FUN_00731d70, FUN_00746520, FUN_007467b0, FUN_0076f6e0, FUN_00972e50, vog_LogMessage.
//  - Strings: ",

                   0x232,3,".
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

uint32_t /* width from decompiler */ FUN_00731d70(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  char cVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint64_t uVar10;

  uint local_70;

  uint32_t /* width from decompiler */ *local_64;

  int local_60;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  iVar2 = *(int *)(param_1 + 0x1f8);

  if (*(int *)(iVar2 + 0x10) == 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar4 = (uint32_t /* width from decompiler */ *)

             FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x18),4);

  }

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceInstancing.cpp",

                   0x232,3,"Error locking source vertex buffer for instancing.\n");

    return 0xffffffff;

  }

  iVar2 = *(int *)(param_1 + 0x14);

  if ((*(int *)(iVar2 + 0x28) == 0) || (*(int *)(iVar2 + 0x2c) - *(int *)(iVar2 + 0x28) >> 3 == 0))

  {

    iVar5 = 0;

  }

  else {

    uVar10 = FUN_007467b0();

    iVar5 = (int)uVar10 + (uint)*(ushort *)((int)((ulonglong)uVar10 >> 0x20) + 2);

  }

  if (*(int *)(param_1 + 0x1f8) == 0) {

    local_60 = 0;

  }

  else {

    local_60 = *(int *)(*(int *)(param_1 + 0x1f8) + 0x18);

  }

  param_3 = (uint32_t /* width from decompiler */ *)((int)param_3 + *(int *)(param_1 + 0x1c0) * local_60 * iVar5);

  if ((*(byte *)(param_2 + 0xbc) & 1) != 0) {

    FUN_00972e50();

  }

  local_64 = puVar4;

  if (0 < local_60) {

    do {

      iVar3 = *(int *)(iVar2 + 0x2c);

      for (iVar5 = *(int *)(iVar2 + 0x28); iVar5 != iVar3; iVar5 = iVar5 + 8) {

        cVar1 = *(char *)(iVar5 + 4);

        switch(cVar1) {

        case '\0':

        case '\x04':

        case '\x05':

        case '\x06':

        case '\b':

        case '\t':

        case '\v':

        case '\r':

        case '\x0e':

        case '\x0f':

          local_70 = 4;

          break;

        case '\x01':

        case '\a':

        case '\n':

        case '\f':

        case '\x10':

          local_70 = 8;

          break;

        case '\x02':

          local_70 = 0xc;

          break;

        case '\x03':

          local_70 = 0x10;

          break;

        default:

          local_70 = 0;

        }

        if ((*(char *)(iVar5 + 6) == '\x03') && (cVar1 == '\x02')) {

          local_30 = *puVar4;

          local_2c = puVar4[1];

          local_28 = puVar4[2];

          local_24 = 0;

          FUN_0076f240(&local_30);

          *param_3 = local_30;

          param_3[1] = local_2c;

          param_3[2] = local_28;

        }

        else if (*(char *)(iVar5 + 6) == '\0') {

          if (cVar1 == '\x02') {

            FUN_0076f6e0();

            *param_3 = local_3c;

            param_3[1] = local_38;

            param_3[2] = local_34;

            puVar4 = local_64;

          }

          else {

            if (cVar1 != '\x03') goto LAB_00731fe4;

            FUN_0076f240(&local_20);

            *param_3 = local_20;

            param_3[1] = local_1c;

            param_3[2] = local_18;

            param_3[3] = local_14;

          }

        }

        else {

LAB_00731fe4:

          puVar8 = puVar4;

          puVar9 = param_3;

          for (uVar6 = local_70 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

            *puVar9 = *puVar8;

            puVar8 = puVar8 + 1;

            puVar9 = puVar9 + 1;

          }

          for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {

            *(uint8_t *)puVar9 = *(uint8_t *)puVar8;

            puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

            puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

          }

        }

        param_3 = (uint32_t /* width from decompiler */ *)((int)param_3 + local_70);

        puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + local_70);

        local_64 = puVar4;

      }

      local_60 = local_60 + -1;

    } while (local_60 != 0);

  }

  return 0;

}
