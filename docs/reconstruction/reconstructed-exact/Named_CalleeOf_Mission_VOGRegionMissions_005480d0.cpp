// =============================================================================
// Named_CalleeOf_Mission_VOGRegionMissions_005480d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005480d0
// Callee of Mission_VOGRegionMissions
// Address:   0x005480d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_VOGRegionMissions: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×1.
//  - Notable callees: FUN_00546d50, FUN_005480d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_VOGRegionMissions
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Mission_VOGRegionMissions_005480d0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a43d5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[0x4f] = 0;

  param_1[0x50] = 0;

  param_1[0x51] = 0;

  local_4 = 0;

  iVar1 = 0x4e;

  puVar2 = param_2;

  puVar3 = param_1;

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    for (; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

  }

  else {

    for (; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar3 = puVar3 + 1;

    }

  }

  param_1[0x4d] = 0;

  *(uint8_t *)(param_1 + 0x5a) = 0;

  param_1[0x53] = 0;

  param_1[0x52] = 0;

  param_1[0x54] = 0;

  param_1[0x55] = 0;

  param_1[0x56] = 0;

  param_1[0x57] = 0;

  param_1[0x58] = 0;

  param_1[0x59] = 0;

  *(uint8_t *)((int)param_1 + 0x169) = 0;

  param_1[0x5b] = 0;

  if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00546d50(param_2);

  }

  ExceptionList = local_c;

  return param_1;

}
