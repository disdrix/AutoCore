// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005c79f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c79f0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x005c79f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×9, return×6, goto×1.
//  - Notable callees: FUN_0076cef0×3, FUN_005b2ba0×2, FUN_005c6ad0×2, FUN_005c7290×2, FUN_004e87d0, FUN_004e88e0, FUN_00583fa0, FUN_005c79f0.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005c79f0(int param_1,uint32_t /* width from decompiler */ *param_2,char param_3)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t auStack_50 [12];

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ *local_38;

  uint32_t /* width from decompiler */ local_1c [4];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6e5f;

  local_c = ExceptionList;

  local_38 = (uint32_t /* width from decompiler */ *)0x5c7a24;

  ExceptionList = &local_c;

  FUN_0076cf00();

  local_4 = 0;

  if (param_3 == '\0') {

    if (*(int *)(param_1 + 0x58) != 0) {

      local_38 = (uint32_t /* width from decompiler */ *)0x5c7a40;

      iVar4 = FUN_005c6ad0();

      if (iVar4 == 3) goto LAB_005c7a86;

      pvVar1 = *(void **)(param_1 + 0x58);

      if (pvVar1 != (void *)0x0) {

        FUN_005b2ba0();

                    /* WARNING: Subroutine does not return */

        local_38 = (uint32_t /* width from decompiler */ *)&UNK_005c7a59;

        operator_delete(pvVar1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

    }

    local_38 = (uint32_t /* width from decompiler */ *)0x5c7a7d;

    iVar4 = FUN_005c6ad0();

    if (iVar4 == 3) {

LAB_005c7a86:

      local_4 = 0xffffffff;

      FUN_0076cef0();

      ExceptionList = local_c;

      return 3;

    }

    cVar3 = FUN_00583fa0();

    if (cVar3 != '\0') {

      local_4 = 0xffffffff;

      FUN_0076cef0();

      ExceptionList = local_c;

      return 0;

    }

  }

  else {

    if (*(int *)(param_1 + 0x58) != 0) {

      local_38 = (uint32_t /* width from decompiler */ *)0x5c7abb;

      FUN_005c7290();

      pvVar1 = *(void **)(param_1 + 0x58);

      if (pvVar1 != (void *)0x0) {

        FUN_005b2ba0();

                    /* WARNING: Subroutine does not return */

        local_38 = (uint32_t /* width from decompiler */ *)&UNK_005c7acf;

        operator_delete(pvVar1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

    }

    local_38 = (uint32_t /* width from decompiler */ *)0x5c7af3;

    FUN_005c7290();

  }

  local_38 = local_1c;

  *(uint8_t *)(param_1 + 0x60) = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)*param_2;

  local_3c = 0x5c7b07;

  puVar5 = (uint32_t /* width from decompiler */ *)FUN_004e87d0();

  local_44 = *puVar5;

  local_40 = puVar5[1];

  local_3c = puVar5[2];

  local_38 = (uint32_t /* width from decompiler */ *)puVar5[3];

  FUN_004e88e0(auStack_50,param_1 + 0x30);

  cVar3 = (*(code *)*puVar2)(*(uint8_t *)(param_1 + 0x50));

  local_1c[0] = *(uint32_t /* width from decompiler */ *)(*(int *)(param_2[1] + 4) + 0xbc + (int)param_2);

  (**(code **)(*(int *)((int)param_2 + *(int *)(param_2[1] + 4) + 4) + 0xb8))(local_1c[0]);

  local_4 = 0xffffffff;

  FUN_0076cef0();

  if (cVar3 != '\0') {

    ExceptionList = local_c;

    return 0;

  }

  ExceptionList = local_c;

  return 1;

}
