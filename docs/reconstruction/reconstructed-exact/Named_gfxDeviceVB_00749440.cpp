// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×13, goto×2, do×2, while×2, return×2, for×1.
//  - Notable callees: FUN_00746520, FUN_00749440, FUN_00972f10, FUN_00972fa0, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_gfxDeviceVB_00749440
// -----------------------------------------------------------------------------
// Stable ID: aa_00749440
// Address:   0x00749440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxDeviceVB"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_gfxDeviceVB_00749440(int *param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int local_30;

  int local_2c;

  int local_28;

  int local_24;

  uint8_t auStack_c [12];

  

  iVar7 = param_1[5];

  if (iVar7 == 0) {

    local_30 = 0;

  }

  else {

    local_30 = *(int *)(iVar7 + 0x18);

  }

  local_28 = *(int *)(iVar7 + 0x28);

  for (local_2c = local_28; local_2c != *(int *)(iVar7 + 0x2c); local_2c = local_2c + 8) {

    if ((*(char *)(local_2c + 6) == '\0') && (*(char *)(local_2c + 7) == '\0'))

    goto joined_r0x0074948b;

  }

  local_2c = 0;

joined_r0x0074948b:

  do {

    if (local_28 == *(int *)(iVar7 + 0x2c)) {

      local_28 = 0;

LAB_007494a6:

      if (*(int *)(iVar7 + 0x10) == 0) {

        iVar7 = 0;

      }

      else {

        iVar7 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar7 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar7 + 0x18),4);

      }

      if (param_1[5] == 0) {

        local_24 = 0;

      }

      else {

        iVar2 = *(int *)(param_1[5] + 0x10);

        if (iVar2 == 0) {

          local_24 = 0;

        }

        else {

          local_24 = *(int *)(iVar2 + 8);

        }

      }

      if (((param_1[0x16] != 0) && (param_1[0x17] != 0)) &&

         (*(int *)(param_1[0x17] + 0x1c) != param_1[0x18])) {

        (**(code **)(*param_1 + 0x80))();

      }

      if ((iVar7 != 0) && (0 < local_30)) {

        puVar8 = param_3;

        do {

          if (param_2 != 0) {

            puVar5 = (uint32_t /* width from decompiler */ *)FUN_00972fa0((uint)*(ushort *)(local_2c + 2) + iVar7);

            puVar6 = (uint32_t /* width from decompiler */ *)((param_2 - (int)param_3) + (int)puVar8);

            *puVar6 = *puVar5;

            puVar6[1] = puVar5[1];

            puVar6[2] = puVar5[2];

          }

          if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

            puVar5 = (uint32_t /* width from decompiler */ *)FUN_00972f10(auStack_c,(uint)*(ushort *)(local_28 + 2) + iVar7);

            *puVar8 = *puVar5;

            puVar8[1] = puVar5[1];

            puVar8[2] = puVar5[2];

          }

          iVar7 = iVar7 + local_24;

          puVar8 = puVar8 + 3;

          local_30 = local_30 + -1;

        } while (local_30 != 0);

      }

      piVar3 = *(int **)(param_1[5] + 0x10);

      if ((piVar3 != (int *)0x0) && (piVar4 = (int *)*piVar3, piVar4 != (int *)0x0)) {

        piVar1 = piVar3 + 4;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                         "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

          piVar3[4] = 0;

          return 0;

        }

        (**(code **)(*piVar4 + 0x30))(piVar4);

      }

      return 0;

    }

    if ((*(char *)(local_28 + 6) == '\x03') && (*(char *)(local_28 + 7) == '\0')) goto LAB_007494a6;

    local_28 = local_28 + 8;

  } while( true );

}
