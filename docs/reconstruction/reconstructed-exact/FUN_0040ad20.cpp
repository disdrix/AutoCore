// =============================================================================
// FUN_0040ad20
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ad20
// Address:   0x0040ad20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040ad20 @ 0x0040ad20
// Stable ID: aa_0040ad20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040ad20, __alldiv.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_0040ad20(void)



{

  int in_EAX;

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = *(int *)(in_EAX + 4);

  iVar3 = *(int *)(iVar1 + 4);

  iVar2 = *(int *)(iVar1 + 4);

  iVar1 = (**(code **)(*(int *)(*(int *)(iVar1 + 4) + 4 + in_EAX) + 0x27c))();

  iVar2 = (**(code **)(*(int *)(iVar2 + 4 + in_EAX) + 0x27c))();

  iVar3 = (**(code **)(*(int *)(iVar3 + 4 + in_EAX) + 0x27c))();

  iVar3 = iVar3 * iVar1 * iVar2;

  __alldiv(iVar3,iVar3 >> 0x1f,8,0);

  return;

}
