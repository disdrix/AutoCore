// =============================================================================
// FUN_004c00f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c00f0
// Address:   0x004c00f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c00f0 @ 0x004c00f0
// Stable ID: aa_004c00f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004bff90, FUN_004c00f0.
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

uint32_t /* width from decompiler */ FUN_004c00f0(int param_1)



{

  int iVar1;

  

  if ((param_1 != 0) && (*(char *)(param_1 + 0xf) == '\0')) {

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;

    iVar1 = FUN_004bff90(param_1,iVar1 + 0x84,iVar1 + 0x94,1,0,0);

    if (iVar1 != 0) {

      *(uint8_t *)(iVar1 + 0x66) = 1;

      return 1;

    }

  }

  return 0;

}
