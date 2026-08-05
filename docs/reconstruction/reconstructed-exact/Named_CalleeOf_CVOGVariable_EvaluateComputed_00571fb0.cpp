// =============================================================================
// Named_CalleeOf_CVOGVariable_EvaluateComputed_00571fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00571fb0
// Callee of CVOGVariable_EvaluateComputed
// Address:   0x00571fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGVariable_EvaluateComputed: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_004022a0×2, FUN_00404840, FUN_00418700, FUN_004294f0, FUN_00571fb0, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGVariable_EvaluateComputed
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

void __thiscall Named_CalleeOf_CVOGVariable_EvaluateComputed_00571fb0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  FUN_004294f0();

  iVar1 = FUN_004022a0(&local_4,&local_8);

  while (iVar1 == 0) {

    if ((local_8 != 0) && (*(int *)(*(int *)(local_8 + 0xa8) + 0x34) == param_2)) {

      iVar1 = *(int *)(param_3 + 4);

      iVar2 = FUN_00418700(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&local_8);

      FUN_00404840(1);

      *(int *)(iVar1 + 4) = iVar2;

      **(int **)(iVar2 + 4) = iVar2;

    }

    iVar1 = FUN_004022a0(&local_4,&local_8);

  }

  if (*(char *)(param_1 + 0x54) != '\0') {

    *(uint8_t *)(param_1 + 0x54) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));

  }

  return;

}
