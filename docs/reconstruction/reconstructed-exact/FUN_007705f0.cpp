// =============================================================================
// FUN_007705f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007705f0
// Address:   0x007705f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007705f0 @ 0x007705f0
// Stable ID: aa_007705f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, if×1, while×1.
//  - Notable callees: FUN_007705f0.
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

uint32_t /* width from decompiler */ FUN_007705f0(int *param_1)



{

  int in_EAX;

  int iVar1;

  

  iVar1 = 1;

  do {

    if (in_EAX == 1 << ((byte)iVar1 & 0x1f)) {

      *param_1 = iVar1;

      return 1;

    }

    iVar1 = iVar1 + 1;

  } while (iVar1 < 0x1c);

  return 0;

}
