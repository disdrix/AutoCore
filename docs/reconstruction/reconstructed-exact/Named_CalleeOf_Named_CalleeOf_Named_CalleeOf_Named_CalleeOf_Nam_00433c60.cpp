// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00433c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00433c60
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis
// Address:   0x00433c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_00433c60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00433c60(uint32_t /* width from decompiler */ param_1,uint param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int unaff_EBX;

  int unaff_ESI;

  uint unaff_EDI;

  

  for (; param_2 < unaff_EDI; param_2 = param_2 + 1) {

    iVar1 = param_2 * 8;

    puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_EBX + 8) + iVar1);

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      *puVar2 = *(uint32_t /* width from decompiler */ *)(iVar1 + unaff_ESI);

      puVar2[1] = *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + unaff_ESI);

    }

  }

  return;

}
