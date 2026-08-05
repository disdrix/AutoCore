// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_00892820
// -----------------------------------------------------------------------------
// Stable ID: aa_00892820
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x00892820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_00892820.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_00892820(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x504) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = 0;

  iVar2 = 0;

  puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x53c);

  do {

    puVar1[-3] = 0;

    *puVar1 = 0;

    puVar1[3] = 0;

    *(uint8_t *)(param_1 + 0x528 + iVar2) = 0;

    iVar2 = iVar2 + 1;

    puVar1 = puVar1 + 1;

  } while (iVar2 < 3);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x52c) = 0;

  return;

}
