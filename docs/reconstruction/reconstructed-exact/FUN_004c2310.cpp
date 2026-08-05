// =============================================================================
// FUN_004c2310
// -----------------------------------------------------------------------------
// Stable ID: aa_004c2310
// Address:   0x004c2310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c2310 @ 0x004c2310
// Stable ID: aa_004c2310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_004c2310, _stricmp.
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

uint32_t /* width from decompiler */ __thiscall FUN_004c2310(int param_1,char *param_2)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  while( true ) {

    if (*(int *)(param_1 + 0x1e4) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_1 + 0x1e8) - *(int *)(param_1 + 0x1e4) >> 2;

    }

    if (iVar1 <= iVar2) break;

    iVar1 = _stricmp((char *)(*(int *)(*(int *)(param_1 + 0x1e4) + iVar2 * 4) + 8),param_2);

    if (iVar1 == 0) {

      return *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1e4) + iVar2 * 4);

    }

    iVar2 = iVar2 + 1;

  }

  return 0;

}
