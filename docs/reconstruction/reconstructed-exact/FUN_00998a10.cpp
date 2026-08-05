// =============================================================================
// FUN_00998a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00998a10
// Address:   0x00998a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00998a10 @ 0x00998a10
// Stable ID: aa_00998a10
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp"
//   - "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo..."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×12, goto×2, do×2, while×2, for×1, return×1.
//  - Notable callees: FUN_00414b60, FUN_00414bc0, FUN_00414c20, FUN_00464d80, FUN_00746520, FUN_00997b90, FUN_00998a10, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp".
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

uint32_t /* width from decompiler */ __thiscall FUN_00998a10(int *param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int *piVar10;

  int iVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ uVar13;

  int iStack_38;

  int iStack_34;

  int iStack_30;

  undefined **local_2c;

  int *local_28;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009b2079;

  pvStack_c = ExceptionList;

  local_28 = (int *)0x0;

  local_2c = &PTR_FUN_00a9db18;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  uVar4 = FUN_00414bc0(0x12);

  uVar13 = 0;

  uVar12 = 8;

  local_4._0_1_ = 1;

  uVar5 = (**(code **)(*param_1 + 0x44))(uVar4,8,0);

  FUN_00414c20(uVar5,uVar4,uVar12,uVar13);

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_00414b60();

  FUN_00464d80();

  FUN_00997b90(param_1 + 4,param_1[0x40],&local_2c);

  piVar10 = local_28;

  if (local_28 == (int *)0x0) {

    iVar11 = 0;

  }

  else {

    iVar11 = local_28[6];

  }

  iStack_34 = local_28[10];

  for (iStack_38 = iStack_34; iStack_38 != local_28[0xb]; iStack_38 = iStack_38 + 8) {

    if ((*(char *)(iStack_38 + 6) == '\0') && (*(char *)(iStack_38 + 7) == '\0'))

    goto joined_r0x00998acb;

  }

  iStack_38 = 0;

joined_r0x00998acb:

  do {

    if (iStack_34 == local_28[0xb]) {

      iStack_34 = 0;

LAB_00998ae6:

      if (local_28[4] == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = FUN_00746520(local_28[5],local_28[6],4);

      }

      if (piVar10[4] == 0) {

        iStack_30 = 0;

      }

      else {

        iStack_30 = *(int *)(piVar10[4] + 8);

      }

      if ((iVar6 != 0) && (0 < iVar11)) {

        puVar7 = param_3;

        do {

          if (param_2 != 0) {

            puVar8 = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(iStack_38 + 2) + iVar6);

            puVar9 = (uint32_t /* width from decompiler */ *)((param_2 - (int)param_3) + (int)puVar7);

            *puVar9 = *puVar8;

            puVar9[1] = puVar8[1];

            puVar9[2] = puVar8[2];

            piVar10 = local_28;

          }

          if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

            puVar9 = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(iStack_34 + 2) + iVar6);

            *puVar7 = *puVar9;

            puVar7[1] = puVar9[1];

            puVar7[2] = puVar9[2];

            piVar10 = local_28;

          }

          iVar6 = iVar6 + iStack_30;

          puVar7 = puVar7 + 3;

          iVar11 = iVar11 + -1;

        } while (iVar11 != 0);

      }

      piVar2 = (int *)piVar10[4];

      if ((piVar2 != (int *)0x0) && (piVar3 = (int *)*piVar2, piVar3 != (int *)0x0)) {

        piVar1 = piVar2 + 4;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                         "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

          piVar2[4] = 0;

        }

        else {

          (**(code **)(*piVar3 + 0x30))(piVar3);

        }

      }

      local_4 = 0xffffffff;

      piVar2 = piVar10 + 1;

      *piVar2 = *piVar2 + -1;

      if (*piVar2 == 0) {

        (**(code **)(*piVar10 + 8))();

      }

      ExceptionList = pvStack_c;

      return 0;

    }

    if ((*(char *)(iStack_34 + 6) == '\x03') && (*(char *)(iStack_34 + 7) == '\0'))

    goto LAB_00998ae6;

    iStack_34 = iStack_34 + 8;

  } while( true );

}
