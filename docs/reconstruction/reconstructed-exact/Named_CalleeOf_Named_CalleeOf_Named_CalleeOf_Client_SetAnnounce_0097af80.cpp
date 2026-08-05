// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_SetAnnounce_0097af80
// -----------------------------------------------------------------------------
// Stable ID: aa_0097af80
// Callee of Named_CalleeOf_Named_CalleeOf_Client_SetAnnouncementLabelTextur
// Address:   0x0097af80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_SetAnnouncementLabelTextur: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGReaction_FailMissionNotify, FUN_004b70c0, FUN_004b7e50, FUN_0097af80, NDSpecialFX_LoadFromScriptName.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_SetAnnouncementLabelTextur
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

void * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_SetAnnounce_0097af80(void)



{

  char *in_EAX;

  void *pvVar1;

  void *local_4;

  

  pvVar1 = NDSpecialFX_LoadFromScriptName(in_EAX,-1,0);

  if (pvVar1 != (void *)0x0) {

    local_4 = pvVar1;

    FUN_004b70c0(0,0,DAT_00a0f718);

    FUN_004b7e50(0,0,0,0,0,0);

    CVOGReaction_FailMissionNotify(&local_4);

  }

  return pvVar1;

}
