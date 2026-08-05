// =============================================================================
// FUN_00808cf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00808cf0
// Address:   0x00808cf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00808cf0 @ 0x00808cf0
// Stable ID: aa_00808cf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00808cf0.
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

void __fastcall FUN_00808cf0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  bool bVar2;

  int in_EAX;

  

  iVar1 = *(int *)(param_2 + 0x10a0);

  bVar2 = '\0' < *(char *)(in_EAX + 4);

  if ((iVar1 != 0) && (DAT_00d1775e = bVar2, *(int *)(iVar1 + 0x5b4) != 0)) {

    (**(code **)(**(int **)(iVar1 + 0x5b4) + 0x3c8))(bVar2,1);

  }

  return;

}
