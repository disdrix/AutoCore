// =============================================================================
// Named_CalleeOf_Named_anmTrackMaster_inl_00468aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00468aa0
// Callee of Named_anmTrackMaster_inl
// Address:   0x00468aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_anmTrackMaster_inl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00435df0, FUN_00468aa0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_anmTrackMaster_inl
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_anmTrackMaster_inl_00468aa0(void)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  if (*(int *)(in_EAX + 0x20) < *(int *)(in_EAX + 0x18) + 8) {

    iVar1 = FUN_00435df0(*(int *)(in_EAX + 0x1c) + *(int *)(in_EAX + 0x18));

    if ((iVar1 < 0) || (*(int *)(in_EAX + 0x20) < 8)) {

      return 0xffffffff;

    }

  }

  iVar1 = *(int *)(in_EAX + 0x18);

  *unaff_EDI = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18 + in_EAX + 0x14);

  unaff_EDI[1] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c + in_EAX + 0x14);

  *(int *)(in_EAX + 0x18) = *(int *)(in_EAX + 0x18) + 8;

  return 0;

}
