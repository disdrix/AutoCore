// =============================================================================
// Named_CalleeOf_Named_VOGMapText_00720670
// -----------------------------------------------------------------------------
// Stable ID: aa_00720670
// Callee of Named_VOGMapText (+1 other named callers)
// Address:   0x00720670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOGMapText: map/sector helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOGMapText (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, return×1.
//  - Notable callees: FUN_00720090×2, EnterCriticalSection, FUN_004804d0, FUN_00720670, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOGMapText (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_VOGMapText_00720670(int param_1)



{

  int in_stack_000000bc;

  char in_stack_000000c0;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009abd9c;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x170));

  local_4 = 0;

  if (in_stack_000000c0 != '\0') {

    if (in_stack_000000bc == 1) {

      FUN_00720090(param_1);

      *(uint8_t *)(param_1 + 0x13) = 1;

      goto LAB_007206f4;

    }

    if (in_stack_000000bc == 2) {

      FUN_00720090(param_1);

      *(uint8_t *)(param_1 + 0x14) = 1;

      goto LAB_007206f4;

    }

  }

  if (in_stack_000000bc == 1) {

    *(uint8_t *)(param_1 + 0x13) = 1;

  }

  else if (in_stack_000000bc == 2) {

    *(uint8_t *)(param_1 + 0x14) = 1;

  }

  else if (in_stack_000000bc == 5) {

    *(uint8_t *)(param_1 + 0x15) = 1;

  }

LAB_007206f4:

  FUN_004804d0(&stack0x00000004);

  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x170));

  ExceptionList = pvStack_c;

  return;

}
