// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Incompatible_Driver_Version_0096eec0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096eec0
// Callee of Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive
// Address:   0x0096eec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT31, FUN_0043bd40, FUN_0043fdf0, FUN_0096eec0, _atexit.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive
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



int Named_CalleeOf_Named_CalleeOf_Drive_Incompatible_Driver_Version_0096eec0(int param_1)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b1316;

  local_c = ExceptionList;

  DAT_00d1f04c = param_1;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_0043fdf0(param_1);

  local_4 = CONCAT31(local_4._1_3_,1);

  uVar1 = _DAT_00d1f7e8 & 1;

  *(uint8_t *)(param_1 + 0x28) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  if (uVar1 == 0) {

    _DAT_00d1f7e8 = _DAT_00d1f7e8 | 1;

    _DAT_00d1f7e4 = &PTR_FUN_00a9ef54;

    _atexit((_func_4879 *)&LAB_009c3370);

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_0043bd40();

  *puVar2 = &LAB_0096ed30;

  puVar2[1] = 0;

  ExceptionList = local_c;

  return param_1;

}
