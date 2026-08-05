// =============================================================================
// FUN_00495600
// -----------------------------------------------------------------------------
// Stable ID: aa_00495600
// Address:   0x00495600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00495600 @ 0x00495600
// Stable ID: aa_00495600
// Embedded strings (evidence for future rename):
//   - "CVOGEnvironmentSector::ProcessPreloads"
//   - "ProcessPreloads"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_0076cef0×3, FUN_0076cf00×2, FUN_00495600, FUN_004baf50, FUN_004c00f0.
//  - Strings: "CVOGEnvironmentSector::ProcessPreloads"; "ProcessPreloads".
//  - Return sites: 3.

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

void __fastcall FUN_00495600(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int *piVar3;

  int *piVar4;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0c3b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CVOGEnvironmentSector::ProcessPreloads");

  local_4 = 0;

  if (*(int *)(param_1 + 0x14) == 0) {

    local_4 = 0xffffffff;

    FUN_0076cef0();

    ExceptionList = local_c;

    return;

  }

  piVar4 = (int *)**(int **)(param_1 + 0x10);

  if (piVar4 != *(int **)(param_1 + 0x10)) {

    do {

      piVar3 = (int *)FUN_004baf50(piVar4 + 2);

      if (piVar3 != (int *)0x0) {

        FUN_0076cf00("ProcessPreloads");

        local_4._0_1_ = 1;

        (**(code **)(*piVar3 + 0x18))(0);

        FUN_004c00f0(piVar3);

        local_4 = (uint)local_4._1_3_ << 8;

        FUN_0076cef0();

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)*(int *)(param_1 + 0x10));

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x10);

  pvVar2 = (void *)*puVar1;

  *puVar1 = puVar1;

  *(int *)(*(int *)(param_1 + 0x10) + 4) = *(int *)(param_1 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  if (pvVar2 == *(void **)(param_1 + 0x10)) {

    local_4 = 0xffffffff;

    FUN_0076cef0();

    ExceptionList = local_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar2);

}
