// =============================================================================
// Named_CalleeOf_Named_hkError_00631ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00631ff0
// Callee of Named_hkError (+2 other named callers)
// Address:   0x00631ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_hkError: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_hkError (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00631ff0, FUN_00643210.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_hkError (+2 other named callers)
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_hkError_00631ff0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ unaff_ESI;

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  *param_1 = &PTR_FUN_009e3440;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x1c,0x15);

  *(uint16_t *)(iVar1 + 4) = 0x1c;

  uVar2 = FUN_00643210(unaff_ESI,unaff_retaddr,param_2);

  param_1[2] = uVar2;

  return param_1;

}
