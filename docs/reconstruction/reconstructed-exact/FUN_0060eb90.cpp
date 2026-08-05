// =============================================================================
// FUN_0060eb90
// -----------------------------------------------------------------------------
// Stable ID: aa_0060eb90
// Address:   0x0060eb90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060eb90 @ 0x0060eb90
// Stable ID: aa_0060eb90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: __alldiv×2, FUN_0060eb90, GetTickCount.
//  - Return sites: 2.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 __fastcall FUN_0060eb90(int param_1)



{

  int iVar1;

  longlong lVar2;

  DWORD DVar3;

  

  DVar3 = GetTickCount();

  iVar1 = *(int *)(param_1 + 0x10);

  if (*(char *)(param_1 + 0x14) != '\0') {

    lVar2 = __alldiv(DVar3,0,1000,0);

    return (float10)iVar1 - (float10)lVar2;

  }

  lVar2 = __alldiv(DVar3,0,1000,0);

  return (float10)iVar1 - ((float10)lVar2 - (float10)_DAT_00d02aa0);

}
