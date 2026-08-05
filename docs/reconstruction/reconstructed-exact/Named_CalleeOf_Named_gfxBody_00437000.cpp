// =============================================================================
// Named_CalleeOf_Named_gfxBody_00437000
// -----------------------------------------------------------------------------
// Stable ID: aa_00437000
// Callee of Named_gfxBody (+6 other named callers)
// Address:   0x00437000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxBody (+6 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00435df0, FUN_00437000.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxBody (+6 other named callers)
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_gfxBody_00437000(uint32_t /* width from decompiler */ param_1)



{

  uint8_t uVar1;

  int in_EAX;

  int iVar2;

  uint8_t *unaff_EDI;

  uint8_t local_1;

  

  if (*(int *)(in_EAX + 0x20) < *(int *)(in_EAX + 0x18) + 1) {

    iVar2 = FUN_00435df0(*(int *)(in_EAX + 0x1c) + *(int *)(in_EAX + 0x18));

    if ((iVar2 < 0) || (*(int *)(in_EAX + 0x20) < 1)) {

      local_1 = (uint8_t)((uint)param_1 >> 0x18);

      *unaff_EDI = local_1;

      return 0xffffffff;

    }

  }

  uVar1 = *(uint8_t *)(*(int *)(in_EAX + 0x18) + in_EAX + 0x2c);

  *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + 1;

  *unaff_EDI = uVar1;

  return 0;

}
