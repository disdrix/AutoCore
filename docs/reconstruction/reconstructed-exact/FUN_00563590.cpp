// =============================================================================
// FUN_00563590
// -----------------------------------------------------------------------------
// Stable ID: aa_00563590
// Address:   0x00563590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00563590 @ 0x00563590
// Stable ID: aa_00563590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00563590.
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

void __fastcall FUN_00563590(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + -0x1dc);

  iVar2 = 0;

  if (*(char *)(*(int *)(*(int *)(iVar1 + 4) + -0x138 + param_1) + 0x7e) != '\0') {

    *(uint8_t *)(param_1 + -0x136) = 0;

    if (param_1 != 0x1e0) {

      iVar2 = *(int *)(iVar1 + 4) + -0x1dc + param_1;

    }

    (**(code **)(*(int *)(*(int *)(iVar1 + 4) + -0x1dc + param_1) + 0x114))(iVar2);

  }

  return;

}
