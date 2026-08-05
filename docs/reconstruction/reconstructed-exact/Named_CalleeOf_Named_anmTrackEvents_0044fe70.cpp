// =============================================================================
// Named_CalleeOf_Named_anmTrackEvents_0044fe70
// -----------------------------------------------------------------------------
// Stable ID: aa_0044fe70
// Callee of Named_anmTrackEvents
// Address:   0x0044fe70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_anmTrackEvents: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0044fe70, FUN_004507a0, FUN_00456660.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_anmTrackEvents
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

void __fastcall Named_CalleeOf_Named_anmTrackEvents_0044fe70(int param_1)



{

  uint in_EAX;

  uint uVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(param_1 + 8) - iVar2 >> 2;

  }

  if (uVar1 < in_EAX) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_1 + 8) - iVar2 >> 2;

    }

    FUN_004507a0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),in_EAX - iVar2,&stack0x00000004);

    return;

  }

  if ((iVar2 != 0) && (in_EAX < (uint)(*(int *)(param_1 + 8) - iVar2 >> 2))) {

    FUN_00456660(param_1,iVar2 + in_EAX * 4,*(int *)(param_1 + 8));

  }

  return;

}
