// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_006462a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006462a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x006462a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006380a0, FUN_006462a0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ * __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_006462a0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ unaff_ESI;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009e4568;

  param_1[3] = 0;

  param_1[4] = param_3;

  param_1[5] = 0xffffffff;

  param_1[6] = param_4;

  if (param_4 == 0) {

    uVar1 = (**(code **)*DAT_00b05060)(param_3,0x15);

    param_1[2] = uVar1;

    FUN_006380a0(uVar1,unaff_ESI,param_3);

    return param_1;

  }

  param_1[2] = param_2;

  return param_1;

}
