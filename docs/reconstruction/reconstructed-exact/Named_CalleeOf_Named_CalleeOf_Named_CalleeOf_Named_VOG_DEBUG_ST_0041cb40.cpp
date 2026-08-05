// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0041cb40
// -----------------------------------------------------------------------------
// Stable ID: aa_0041cb40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0041cb40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0041cb40, FUN_0041fdd0, FUN_0041fe30.
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0041cb40(void)



{

  uint in_EAX;

  uint uVar1;

  int iVar2;

  int unaff_ESI;

  

  iVar2 = *(int *)(unaff_ESI + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = (*(int *)(unaff_ESI + 8) - iVar2) / 0xc4;

  }

  if (in_EAX <= uVar1) {

    if ((iVar2 != 0) && (in_EAX < (uint)((*(int *)(unaff_ESI + 8) - iVar2) / 0xc4))) {

      FUN_0041fdd0(unaff_ESI,&stack0x00000004,iVar2 + in_EAX * 0xc4,*(int *)(unaff_ESI + 8));

    }

    return;

  }

  if (iVar2 == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = (*(int *)(unaff_ESI + 8) - iVar2) / 0xc4;

  }

  FUN_0041fe30(unaff_ESI,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),in_EAX - iVar2);

  return;

}
