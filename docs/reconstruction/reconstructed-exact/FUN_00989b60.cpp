// =============================================================================
// FUN_00989b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00989b60
// Address:   0x00989b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00989b60 @ 0x00989b60
// Stable ID: aa_00989b60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0044ff40, FUN_00989b60, _stricmp.
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

uint32_t /* width from decompiler */ FUN_00989b60(char *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *local_4;

  

  FUN_0044ff40(&local_4,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 4),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),&param_1,

               &LAB_00435ae0);

  *param_2 = local_4;

  if (local_4 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) {

    iVar1 = _stricmp((char *)*local_4,param_1);

    if (iVar1 == 0) {

      return 1;

    }

  }

  return 0;

}
