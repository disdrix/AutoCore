// =============================================================================
// Named_CalleeOf_Named_assManager_0076c330
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c330
// Callee of Named_assManager (+4 other named callers)
// Address:   0x0076c330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_assManager (+4 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT44, FUN_0076c270, FUN_0076c330, __aulldiv, rdtsc.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_assManager (+4 other named callers)
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

float10 Named_CalleeOf_Named_assManager_0076c330(void)



{

  uint64_t uVar1;

  int iVar2;

  uint uVar3;

  longlong lVar4;

  

  if (DAT_00d1a530 == '\0') {

    FUN_0076c270();

  }

  uVar3 = DAT_00d1a53c;

  iVar2 = DAT_00d1a538;

  uVar1 = rdtsc();

  lVar4 = __aulldiv((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),DAT_00d1a538,DAT_00d1a53c);

  return (float10)lVar4 +

         (float10)((int)uVar1 - iVar2 * (int)lVar4) /

         (-(float10)(longlong)(((ulonglong)uVar3 & 0x80000000) << 0x20) +

         (float10)(CONCAT44(uVar3,iVar2) & 0x7fffffffffffffff));

}
