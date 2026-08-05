// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00971820
// -----------------------------------------------------------------------------
// Stable ID: aa_00971820
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00971820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_0043d670, FUN_0043df90, FUN_005b2ba0, FUN_00744360, FUN_00971640, FUN_00971820.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00971820(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  uint8_t local_28 [8];

  uint8_t local_20 [4];

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009afe27;

  local_c = ExceptionList;

  local_1c = 0;

  local_18 = 0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  for (uVar3 = *(uint *)(param_2 + 0xc); uVar3 != *(int *)(param_2 + 0x10) + *(int *)(param_2 + 0xc)

      ; uVar3 = uVar3 + 1) {

    if (local_10 != 0) {

      FUN_0043df90(local_28,local_20,local_14,local_20,local_10 + local_14);

    }

    uVar2 = uVar3 >> 2;

    iVar1 = uVar2 * -4;

    if (*(uint *)(param_2 + 8) <= uVar2) {

      uVar2 = uVar2 - *(uint *)(param_2 + 8);

    }

    iVar1 = *(int *)(*(int *)(param_2 + 4) + uVar2 * 4) + (uVar3 + iVar1) * 4;

    FUN_0043d670(iVar1);

    FUN_00744360(iVar1,local_20);

    FUN_00971640(param_1);

  }

  FUN_005b2ba0();

  ExceptionList = local_c;

  return 0;

}
