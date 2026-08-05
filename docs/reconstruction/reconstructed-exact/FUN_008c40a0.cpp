// =============================================================================
// FUN_008c40a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008c40a0
// Address:   0x008c40a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c40a0 @ 0x008c40a0
// Stable ID: aa_008c40a0
// Embedded strings (evidence for future rename):
//   - "Controls"
//   - "(Hide Tips)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, do×2, while×2.
//  - Notable callees: CDlgFirstTime_ctor, CONCAT31, Client_SendUpdateFirstTimeFlags, Client_SetFirstTimeTipBit, FUN_0040ad70, FUN_0040d950, FUN_0040d980, FUN_004133c0.
//  - Strings: "Controls"; "(Hide Tips)".
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

uint32_t /* width from decompiler */ FUN_008c40a0(int param_1,int param_2)



{

  void **ppvVar1;

  char cVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint8_t *puVar5;

  char *pcVar6;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b9ed2;

  local_c = ExceptionList;

  ppvVar1 = &local_c;

  if (param_1 == 8) {

    if (param_2 == 40000) {

      ExceptionList = &local_c;

      FUN_007fca10();

      ppvVar1 = ExceptionList;

    }

    else {

      ppvVar1 = &local_c;

      if ((param_2 == 0x9c41) && (ppvVar1 = &local_c, DAT_00d1b6d8 != 0)) {

        if (*(int *)(DAT_00d1b6d8 + 0xd30) == 0) {

          return CONCAT31((int3)((uint)DAT_00d1b6d8 >> 8),1);

        }

        ExceptionList = &local_c;

        if (DAT_00d1b9a4 == (int *)0x0) {

          ExceptionList = &local_c;

          pvVar3 = operator_new(0x5b0);

          local_4 = 0;

          if (pvVar3 == (void *)0x0) {

            DAT_00d1b9a4 = (int *)0x0;

          }

          else {

            DAT_00d1b9a4 = (int *)CDlgFirstTime_ctor(pvVar3);

          }

        }

        local_4 = 0xffffffff;

        ppvVar1 = ExceptionList;

        if (((DAT_00d1b778 != (int *)0x0) && (DAT_00d1b780 != (int *)0x0)) &&

           ((int *)*DAT_00d1b780 == DAT_00d1b778)) {

          cVar2 = (**(code **)(*DAT_00d1b9a4 + 0x3d8))();

          if (cVar2 == '\0') {

            (**(code **)(*DAT_00d1b778 + 0xa8))(DAT_00d1b9a4);

            (**(code **)(*DAT_00d1b9a4 + 0x43c))();

          }

          (**(code **)(*DAT_00d1b9a4 + 0x460))(1);

          (**(code **)(*DAT_00d1b9a4 + 0xfc))(1,0x3f000000);

          if (DAT_00d1b9a4[0x151] != 0) {

            do {

              FUN_0040d950();

              FUN_0040d980();

              Client_SetFirstTimeTipBit();

            } while (DAT_00d1b9a4[0x151] != 0);

            Client_SendUpdateFirstTimeFlags();

          }

          FUN_004133c0(0);

          puStack_8 = (uint8_t *)0x0;

          pcVar6 = "Controls";

          do {

            puVar5 = puStack_8;

            if (((pcVar6 != "(Hide Tips)") && (cVar2 = FUN_0040ad70(DAT_00d1b6d8), cVar2 != '\0'))

               && (*pcVar6 != '\0')) {

              FUN_00414a20();

              puVar5 = puStack_8;

            }

            puStack_8 = puVar5 + 1;

            pcVar6 = pcVar6 + 0x1e;

          } while ((int)pcVar6 < 0xa15f0c);

          (**(code **)(*DAT_00d1b9a4 + 0x450))(*(uint32_t /* width from decompiler */ *)(*(int *)DAT_00d1b9a4[0x153] + 8));

          (**(code **)(*DAT_00d1b9a4 + 0x464))(0);

          (**(code **)(*DAT_00d1b778 + 0x3c4))(1);

          FUN_0092f000();

          ppvVar1 = ExceptionList;

        }

      }

    }

  }

  ExceptionList = ppvVar1;

  uVar4 = FUN_0087b500(param_1,param_2);

  ExceptionList = local_c;

  return uVar4;

}
