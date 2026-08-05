// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069fec0
// -----------------------------------------------------------------------------
// Stable ID: aa_0069fec0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069fec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0069fec0, FUN_006a1be0, FUN_006a1cd0, FUN_006a3db0, _atexit.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069fec0(float *param_1,float param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  float10 fVar6;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab00e;

  local_c = ExceptionList;

  fVar6 = (float10)g_flZero;

  if ((param_1[0x10] != 0.0) && (((int)param_1[0x11] - (int)param_1[0x10]) / 0x18 == 500)) {

    ExceptionList = &local_c;

    iVar5 = FUN_006a3db0();

    if (iVar5 == 499) {

      fVar1 = *(float *)((int)param_1[0x10] + 0x2ecc);

    }

    else {

      fVar1 = *(float *)(iVar5 * 0x18 + 4 + (int)param_1[0x10]);

      fVar1 = fVar1 + (*(float *)(iVar5 * 0x18 + 0x1c + (int)param_1[0x10]) - fVar1) *

                      (param_2 - (float)iVar5 * _DAT_009eb514) * _DAT_009eb518;

    }

    fVar2 = param_1[1];

    fVar3 = *param_1;

    fVar4 = *param_1;

    if ((_DAT_00d08f80 & 1) == 0) {

      _DAT_00d08f80 = _DAT_00d08f80 | 1;

      local_4 = 0;

      FUN_006a1cd0();

      _atexit((_func_4879 *)&LAB_009c5570);

      local_4 = 0xffffffff;

    }

    fVar6 = (float10)FUN_006a1be0(-param_1[2],param_1[2]);

    fVar6 = fVar6 + (float10)((fVar2 - fVar3) * fVar1 + fVar4);

  }

  ExceptionList = local_c;

  return fVar6;

}
