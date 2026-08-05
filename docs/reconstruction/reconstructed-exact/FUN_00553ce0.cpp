// =============================================================================
// FUN_00553ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_00553ce0
// Address:   0x00553ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00553ce0 @ 0x00553ce0
// Stable ID: aa_00553ce0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_00553ce0.
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

uint __thiscall FUN_00553ce0(int param_1,uint param_2,int param_3)



{

  char cVar1;

  char *pcVar2;

  

  if ((-1 < (int)param_2) && ((int)param_2 < 4)) {

    pcVar2 = (char *)(param_1 + param_2 * 0x10c);

    param_3 = param_3 - (int)pcVar2;

    do {

      cVar1 = *pcVar2;

      pcVar2[param_3] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    return CONCAT31((int3)((uint)pcVar2 >> 8),1);

  }

  return param_2 & 0xffffff00;

}
