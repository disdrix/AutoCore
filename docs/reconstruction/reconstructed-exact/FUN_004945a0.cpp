// =============================================================================
// FUN_004945a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004945a0
// Address:   0x004945a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004945a0 @ 0x004945a0
// Stable ID: aa_004945a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00402090, FUN_004945a0, FUN_004bf570, FUN_00581c10, FUN_005b7e40.
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

void FUN_004945a0(uint32_t /* width from decompiler */ param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_c [2];

  uint32_t /* width from decompiler */ local_4;

  

  FUN_00581c10(local_c);

  iVar2 = FUN_00402090(local_c[0],local_4);

  if ((*(int *)(iVar2 + 0x24) != 0) && (cVar1 = FUN_004bf570(param_1), cVar1 != '\0')) {

    return;

  }

  FUN_005b7e40(param_1);

  return;

}
