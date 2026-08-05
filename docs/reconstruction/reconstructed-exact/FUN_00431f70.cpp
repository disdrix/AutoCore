// =============================================================================
// FUN_00431f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00431f70
// Address:   0x00431f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00431f70 @ 0x00431f70
// Stable ID: aa_00431f70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00431f70.
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

uint32_t /* width from decompiler */ __fastcall FUN_00431f70(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int in_EAX;

  

  iVar1 = in_EAX + param_2 * 3;

  if ((param_1 != (&DAT_00d1ea08)[iVar1 * 3]) &&

     ((param_1 == 0 ||

      (piVar2 = (int *)((&DAT_00d1ea10)[iVar1 * 3] + param_1 * 4),

      *(int *)(*piVar2 + 8) == *(int *)(piVar2[-1] + 8))))) {

    return 0;

  }

  return 1;

}
