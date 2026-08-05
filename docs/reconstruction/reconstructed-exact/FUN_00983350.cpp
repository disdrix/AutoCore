// =============================================================================
// FUN_00983350
// -----------------------------------------------------------------------------
// Stable ID: aa_00983350
// Address:   0x00983350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00983350 @ 0x00983350
// Stable ID: aa_00983350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, for×2, do×1, while×1.
//  - Notable callees: FUN_00469b80×2, EnterCriticalSection, FUN_00469c80, FUN_00983350, LeaveCriticalSection.
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

uint32_t /* width from decompiler */ FUN_00983350(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  undefined3 uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint8_t local_48 [4];

  uint32_t /* width from decompiler */ *local_44;

  uint32_t /* width from decompiler */ *local_40;

  uint32_t /* width from decompiler */ local_3c;

  void *local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28 [7];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009abf0e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (*(char *)(param_1 + 0x50) != '\0') {

    ExceptionList = &local_c;

    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));

  }

  local_34 = (void *)0x0;

  local_30 = 0;

  local_2c = 0;

  local_4._1_3_ = 0;

  uVar3 = local_4._1_3_;

  local_4._1_3_ = 0;

  iVar7 = *(int *)(param_1 + 0x2c);

  if (iVar7 != *(int *)(param_1 + 0x30)) {

    do {

      local_4._0_1_ = 1;

      FUN_00469b80(local_48);

      puVar1 = local_40;

      local_4._0_1_ = 2;

      for (puVar5 = local_44; puVar5 != puVar1; puVar5 = puVar5 + 7) {

        puVar6 = puVar5;

        puVar8 = local_28;

        for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar8 = *puVar6;

          puVar6 = puVar6 + 1;

          puVar8 = puVar8 + 1;

        }

        FUN_00469c80();

      }

      local_4._0_1_ = 1;

      if (local_44 != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(local_44);

      }

      iVar7 = iVar7 + 4;

      local_44 = (uint32_t /* width from decompiler */ *)0x0;

      local_40 = (uint32_t /* width from decompiler */ *)0x0;

      local_3c = 0;

      uVar3 = local_4._1_3_;

    } while (iVar7 != *(int *)(param_1 + 0x30));

  }

  local_4._1_3_ = uVar3;

  pvVar2 = local_34;

  local_4._0_1_ = 1;

  FUN_00469b80(param_2);

  if (pvVar2 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  if (*(char *)(param_1 + 0x50) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));

  }

  ExceptionList = local_c;

  return param_2;

}
