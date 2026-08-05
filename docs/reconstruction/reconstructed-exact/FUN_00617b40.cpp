// =============================================================================
// FUN_00617b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00617b40
// Address:   0x00617b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00617b40 @ 0x00617b40
// Stable ID: aa_00617b40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00578b30, FUN_00589e60, FUN_00617b40.
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

void __fastcall FUN_00617b40(int param_1)



{

  char *pcVar1;

  

  if (*(int *)(param_1 + 0x18) != 0) {

    pcVar1 = (char *)(*(int *)(param_1 + 0x18) + 0x20);

    *pcVar1 = *pcVar1 + '\x01';

  }

  if ((*(byte *)(param_1 + 0x649) & 4) != 0) {

    FUN_00589e60(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),param_1 + 0x24,0x3f800000);

  }

  FUN_00578b30();

  return;

}
