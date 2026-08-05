// =============================================================================
// FUN_00682390
// -----------------------------------------------------------------------------
// Stable ID: aa_00682390
// Address:   0x00682390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00682390 @ 0x00682390
// Stable ID: aa_00682390
// Embedded strings (evidence for future rename):
//   - "Error receiving %d bytes, connection terminated"
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"
//   - "Attempt to decrypt incoming data failed: %d"
//   - "Received a packet that exceeds the max payload size (packet size %u)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~111 non-empty decompiler lines.
//  - Control keywords: if×15, return×7, goto×3, while×2.
//  - Notable callees: FUN_0067bce0×3, FUN_0076cec0×3, FUN_0067b610×2, FUN_00681020×2, FUN_006819f0×2, FUN_00681dc0×2, vog_LogMessage×2, FUN_0067bbb0.
//  - Strings: "Error receiving %d bytes, connection terminated"; "Attempt to decrypt incoming data failed: %d".
//  - Return sites: 7.

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

uint32_t /* width from decompiler */ __fastcall FUN_00682390(uint param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint local_4;

  

  uVar4 = *(uint *)(param_1 + 0x10);

  local_4 = param_1;

  while (uVar4 < 4) {

    iVar3 = FUN_0067bbb0(0,1);

    if ((iVar3 == 1) && (iVar3 = FUN_0067bce0(), iVar3 == 0)) {

LAB_0068249f:

      FUN_00681dc0();

      return 0;

    }

    uVar4 = FUN_0067bce0();

    if (uVar4 < 0x1000000) {

      if (uVar4 == 0) {

        return 0;

      }

    }

    else {

      uVar4 = 0xffffff;

    }

    local_4 = 0;

    FUN_006819f0(uVar4);

    iVar3 = FUN_0067b610(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8) + *(int *)(param_1 + 0x10)

                         ,uVar4,&local_4,0);

    if (iVar3 < 0) {

      uVar5 = FUN_0076cec0(&stack0x00000004,"Error receiving %d bytes, connection terminated",uVar4)

      ;

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                     ,0x1cd,1,uVar5);

      goto LAB_0068249f;

    }

    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + local_4;

    if (local_4 == 0) {

      return 0;

    }

    uVar4 = *(uint *)(param_1 + 0x10);

  }

  if (3 < *(uint *)(param_1 + 0x10)) {

    uVar4 = *(uint *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8));

    if (uVar4 < 0x1000000) {

      uVar6 = *(uint *)(param_1 + 0x10);

      while (uVar6 < uVar4 + 4) {

        uVar6 = FUN_0067bce0();

        if (uVar6 < 0x1000000) {

          if (uVar6 == 0) break;

        }

        else {

          uVar6 = 0xffffff;

        }

        local_4 = 0;

        FUN_006819f0(uVar6);

        iVar3 = FUN_0067b610(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x10) +

                             *(int *)(param_1 + 8),uVar6,&local_4,0);

        if (iVar3 < 0) goto LAB_00682469;

        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + local_4;

        if (local_4 == 0) {

          return 0;

        }

        uVar6 = *(uint *)(param_1 + 0x10);

      }

      if (*(int *)(param_1 + 0x10) - 4U < uVar4) {

        return 0;

      }

      if (*(char *)(param_1 + 0x28) == '\0') {

        local_4 = *(int *)(param_1 + 0x14) + 4 + *(int *)(param_1 + 8);

        FUN_00681020(&local_4,uVar4,0);

LAB_006825c2:

        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar4 + 4;

        piVar2 = (int *)(param_1 + 0x10);

        *piVar2 = *piVar2 + (-4 - uVar4);

        if (*piVar2 == 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

        }

        return 1;

      }

      uVar5 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x10))(uVar4);

      FUN_00681a90(uVar5);

      puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x34);

      iVar3 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x14))

                        (puVar1,&stack0xfffffff8,

                         *(int *)(param_1 + 0x14) + 4 + *(int *)(param_1 + 8),uVar4,0);

      if (iVar3 == 0) {

        FUN_00681020(puVar1,local_4,1);

        *puVar1 = 0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

        goto LAB_006825c2;

      }

      uVar5 = FUN_0076cec0(&stack0x00000004,"Attempt to decrypt incoming data failed: %d",iVar3);

      uVar7 = 0x228;

    }

    else {

      uVar5 = FUN_0076cec0(&stack0x00000004,

                           "Received a packet that exceeds the max payload size (packet size %u)",

                           uVar4);

      uVar7 = 0x1f1;

    }

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netTcpConnection.cpp"

                   ,uVar7,2,uVar5);

LAB_00682469:

    FUN_00681dc0();

  }

  return 0;

}
