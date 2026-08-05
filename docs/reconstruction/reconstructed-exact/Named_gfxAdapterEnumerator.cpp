// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: Direct3DCreate9, FUN_00456960, FUN_00735810, FUN_007358c0, FUN_00964dd0, vog_LogMessage.
//  - Strings: "Failed to create Direct3D9 object."; "Failed to enumerate any adapters".
//  - Return sites: 2.

// =============================================================================
// Named_gfxAdapterEnumerator
// -----------------------------------------------------------------------------
// Stable ID: aa_00964dd0
// Address:   0x00964dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxAdapterEnumerator"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_gfxAdapterEnumerator(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  int iVar4;

  void *pvVar5;

  int iVar6;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  char *pcVar9;

  uint32_t /* width from decompiler */ extraout_var;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009af8e9;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  piVar3 = (int *)Direct3DCreate9(0x20);

  *(int **)(unaff_ESI + 0x10) = piVar3;

  uVar7 = extraout_var;

  if (piVar3 == (int *)0x0) {

    pcVar9 = "Failed to create Direct3D9 object.";

    uVar8 = 0x55;

  }

  else {

    iVar4 = (**(code **)(*piVar3 + 0x10))(piVar3);

    iVar6 = 0;

    if (0 < iVar4) {

      do {

        pvVar5 = operator_new(0x71c);

        uVar7 = 0;

        uStack_4 = 0;

        if (pvVar5 != (void *)0x0) {

          uVar7 = FUN_00735810(pvVar5,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10),iVar6);

        }

        uStack_4 = 0xffffffff;

        iVar1 = *(int *)(unaff_ESI + 4);

        if ((iVar1 == 0) ||

           ((uint)(*(int *)(unaff_ESI + 0xc) - iVar1 >> 2) <=

            (uint)(*(int *)(unaff_ESI + 8) - iVar1 >> 2))) {

          FUN_00456960(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

        }

        else {

          puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8);

          *puVar2 = uVar7;

          *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8) = puVar2 + 1;

        }

        FUN_007358c0(param_1);

        iVar6 = iVar6 + 1;

      } while (iVar6 < iVar4);

    }

    if (iVar4 != 0) {

      ExceptionList = local_c;

      return 0;

    }

    pcVar9 = "Failed to enumerate any adapters";

    uVar8 = 0x65;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxAdapterEnumerator.cpp",uVar8,3,

                 pcVar9,uVar7);

  ExceptionList = local_c;

  return 0xffffffff;

}
