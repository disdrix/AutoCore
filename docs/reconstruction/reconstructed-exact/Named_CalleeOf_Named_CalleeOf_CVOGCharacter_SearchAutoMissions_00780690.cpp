// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGCharacter_SearchAutoMissions_00780690
// -----------------------------------------------------------------------------
// Stable ID: aa_00780690
// Callee of Named_CalleeOf_CVOGCharacter_SearchAutoMissions
// Address:   0x00780690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGCharacter_SearchAutoMissions: character create/apply helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: __alldiv×2, CARRY4, FUN_00780690, QueryPerformanceCounter.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGCharacter_SearchAutoMissions
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

void Named_CalleeOf_Named_CalleeOf_CVOGCharacter_SearchAutoMissions_00780690(void)



{

  uint *puVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  uint *unaff_ESI;

  uint64_t uVar5;

  LARGE_INTEGER local_8;

  

  QueryPerformanceCounter(&local_8);

  uVar2 = local_8.s.LowPart - *unaff_ESI;

  iVar4 = (local_8.s.HighPart - unaff_ESI[1]) - (uint)(local_8.s.LowPart < *unaff_ESI);

  puVar1 = unaff_ESI + 2;

  uVar3 = *puVar1;

  *puVar1 = *puVar1 + uVar2;

  unaff_ESI[3] = unaff_ESI[3] + iVar4 + (uint)CARRY4(uVar3,uVar2);

  uVar3 = __alldiv(uVar2,iVar4,unaff_ESI[4],unaff_ESI[5]);

  unaff_ESI[9] = uVar3;

  if ((int)unaff_ESI[10] < (int)uVar3) {

    unaff_ESI[10] = uVar3;

  }

  puVar1 = unaff_ESI + 8;

  *puVar1 = *puVar1 + 1;

  if (*puVar1 != 0) {

    uVar5 = __alldiv(unaff_ESI[2],unaff_ESI[3],unaff_ESI[8],0);

    *(uint64_t *)(unaff_ESI + 6) = uVar5;

  }

  return;

}
