// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_00433ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_00433ba0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Sending_Co
// Address:   0x00433ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Sending_Co: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00433ba0, FUN_00433c60, free, malloc.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Sending_Co
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_00433ba0(uint param_1)



{

  void *_Memory;

  int in_EAX;

  void *pvVar1;

  int iVar2;

  

  if (*(uint *)(in_EAX + 4) < param_1) {

    iVar2 = param_1 + (0x10 - (param_1 & 0xf));

    pvVar1 = malloc(iVar2 * 8);

    _Memory = *(void **)(in_EAX + 8);

    *(void **)(in_EAX + 8) = pvVar1;

    FUN_00433c60();

    *(void **)(in_EAX + 8) = _Memory;

    free(_Memory);

    *(void **)(in_EAX + 8) = pvVar1;

    *(int *)(in_EAX + 4) = iVar2;

  }

  return;

}
