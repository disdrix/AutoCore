// =============================================================================
// Named_CalleeOf_Mission_Mission_killaggregate_objective_requirem_006127a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006127a0
// Callee of Mission_Mission_killaggregate_objective_requirement_lack
// Address:   0x006127a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Mission_killaggregate_objective_requirem: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006127a0, wcscpy, wcslen.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Mission_killaggregate_objective_requirement_lack
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

void __thiscall Named_CalleeOf_Mission_Mission_killaggregate_objective_requirem_006127a0(int param_1,wchar_t *param_2)



{

  size_t sVar1;

  wchar_t *_Dest;

  

  if (*(void **)(param_1 + 0x40) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x40));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  if ((param_2 != (wchar_t *)0x0) && (sVar1 = wcslen(param_2), sVar1 != 0)) {

    _Dest = operator_new__(sVar1 * 2 + 2);

    *(wchar_t **)(param_1 + 0x40) = _Dest;

    wcscpy(_Dest,param_2);

    *(uint16_t *)(*(int *)(param_1 + 0x40) + sVar1 * 2) = 0;

  }

  return;

}
