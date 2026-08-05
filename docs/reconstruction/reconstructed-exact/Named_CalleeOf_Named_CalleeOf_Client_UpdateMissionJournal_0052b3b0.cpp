// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_0052b3b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b3b0
// Callee of Named_CalleeOf_Client_UpdateMissionJournal
// Address:   0x0052b3b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_UpdateMissionJournal: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×5, return×5, while×1.
//  - Notable callees: FUN_0052a020, FUN_0052b3b0.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_UpdateMissionJournal
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_0052b3b0(int param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  char cVar4;

  

  iVar1 = *(int *)(*(int *)(param_2 + 0x13c) + -4 + (uint)*(byte *)(param_2 + 0x130) * 4);

  uVar2 = *(uint *)(iVar1 + 0x10);

  iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x548) + 0x10) +

                           (*(uint *)(*(int *)(param_1 + 0x548) + 8) & uVar2) * 4) + 4);

  while( true ) {

    if (iVar3 == 0) {

      return 0;

    }

    if (uVar2 == *(uint *)(iVar3 + 0x10)) break;

    iVar3 = *(int *)(iVar3 + 0xc);

  }

  if (iVar3 == 0) {

    return 0;

  }

  if (*(int *)(iVar3 + 8) == 0) {

    return 0;

  }

  cVar4 = FUN_0052a020(iVar1,0);

  if (cVar4 == '\0') {

    return 0;

  }

  return 1;

}
