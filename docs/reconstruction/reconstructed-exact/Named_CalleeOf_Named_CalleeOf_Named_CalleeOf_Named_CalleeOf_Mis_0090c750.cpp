// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_0090c750
// -----------------------------------------------------------------------------
// Stable ID: aa_0090c750
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI
// Address:   0x0090c750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, if×1, return×1.
//  - Notable callees: FUN_0090c750.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_0090c750(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x504) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x528) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x52c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x530) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x534) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x538) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x53c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = 0;

  iVar1 = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x540);

  do {

    *(uint8_t *)(param_1 + 0x510 + iVar1) = 0;

    *puVar2 = 0;

    iVar1 = iVar1 + 1;

    puVar2 = puVar2 + 1;

  } while (iVar1 < 0x18);

  DAT_00d1d8f8 = 1;

  DAT_00d1d8f9 = 0;

  if (DAT_00d1d8e4 != (int *)0x0) {

    (**(code **)(*DAT_00d1d8e4 + 4))(0);

  }

  return;

}
