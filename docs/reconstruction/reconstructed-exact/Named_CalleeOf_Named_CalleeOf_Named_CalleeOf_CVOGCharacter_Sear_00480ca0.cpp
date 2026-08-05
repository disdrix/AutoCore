// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCharacter_Sear_00480ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_00480ca0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGCharacter_SearchAutoMissions
// Address:   0x00480ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGCharacter_SearchAutoMissions: character create/apply helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0042a710, FUN_0042acc0, FUN_00480ca0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGCharacter_SearchAutoMissions
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCharacter_Sear_00480ca0(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = *(int *)(in_EAX + 4);

  local_4 = param_1;

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(in_EAX + 8) - iVar1) / 0xc) < (uint)((*(int *)(in_EAX + 0xc) - iVar1) / 0xc))

     ) {

    iVar1 = *(int *)(in_EAX + 8);

    FUN_0042acc0(param_1);

    *(int *)(in_EAX + 8) = iVar1 + 0xc;

    return;

  }

  FUN_0042a710(&local_4,*(uint32_t /* width from decompiler */ *)(in_EAX + 8),unaff_EBX);

  return;

}
