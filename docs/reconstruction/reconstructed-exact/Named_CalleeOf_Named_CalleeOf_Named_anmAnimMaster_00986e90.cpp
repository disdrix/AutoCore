// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaster_00986e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00986e90
// Callee of Named_CalleeOf_Named_anmAnimMaster
// Address:   0x00986e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_anmAnimMaster: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×21, return×10.
//  - Notable callees: FUN_00457eb0, FUN_00457f30, FUN_00457f80, FUN_00457fd0, FUN_00458020, FUN_00458070, FUN_004580c0, FUN_00458110.
//  - Return sites: 10.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_anmAnimMaster
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_anmAnimMaster_00986e90(uint param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac026;

  local_c = ExceptionList;

  if (param_1 < 0x4b455947) {

    if (param_1 == 0x4b455946) {

      ExceptionList = &local_c;

      pvVar1 = operator_new(0x30);

      local_4 = 7;

      if (pvVar1 != (void *)0x0) {

        uVar2 = FUN_00458110(pvVar1);

        ExceptionList = local_c;

        return uVar2;

      }

    }

    else if (param_1 < 0x4b455353) {

      if (param_1 == 0x4b455352) {

        ExceptionList = &local_c;

        pvVar1 = operator_new(0x30);

        local_4 = 3;

        if (pvVar1 != (void *)0x0) {

          uVar2 = FUN_00457fd0(pvVar1);

          ExceptionList = local_c;

          return uVar2;

        }

      }

      else if ((param_1 == 3) || (param_1 == 0x4b455254)) {

        ExceptionList = &local_c;

        pvVar1 = operator_new(0x30);

        local_4 = 1;

        if (pvVar1 != (void *)0x0) {

          uVar2 = FUN_00457f30(pvVar1);

          ExceptionList = local_c;

          return uVar2;

        }

      }

    }

    else if (param_1 == 0x4b455354) {

      ExceptionList = &local_c;

      pvVar1 = operator_new(0x30);

      local_4 = 2;

      if (pvVar1 != (void *)0x0) {

        uVar2 = FUN_00457f80(pvVar1);

        ExceptionList = local_c;

        return uVar2;

      }

    }

    else if (param_1 == 0x4b455556) {

      ExceptionList = &local_c;

      pvVar1 = operator_new(0x30);

      local_4 = 8;

      if (pvVar1 != (void *)0x0) {

        uVar2 = FUN_00458160(pvVar1);

        ExceptionList = local_c;

        return uVar2;

      }

    }

  }

  else if (param_1 < 0x4b455955) {

    if (param_1 == 0x4b455954) {

      ExceptionList = &local_c;

      pvVar1 = operator_new(0x30);

      local_4 = 6;

      if (pvVar1 != (void *)0x0) {

        uVar2 = FUN_004580c0(pvVar1);

        ExceptionList = local_c;

        return uVar2;

      }

    }

    else if (param_1 == 0x4b455952) {

      ExceptionList = &local_c;

      pvVar1 = operator_new(0x30);

      local_4 = 4;

      if (pvVar1 != (void *)0x0) {

        uVar2 = FUN_00458020(pvVar1);

        ExceptionList = local_c;

        return uVar2;

      }

    }

    else if (param_1 == 0x4b455953) {

      ExceptionList = &local_c;

      pvVar1 = operator_new(0x30);

      local_4 = 5;

      if (pvVar1 != (void *)0x0) {

        uVar2 = FUN_00458070(pvVar1);

        ExceptionList = local_c;

        return uVar2;

      }

    }

  }

  else if (param_1 == 0x4b535254) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x30);

    local_4 = 0;

    if (pvVar1 != (void *)0x0) {

      uVar2 = FUN_00457eb0(pvVar1);

      ExceptionList = local_c;

      return uVar2;

    }

  }

  ExceptionList = local_c;

  return 0;

}
