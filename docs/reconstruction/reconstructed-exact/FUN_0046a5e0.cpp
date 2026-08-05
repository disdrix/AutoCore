// =============================================================================
// FUN_0046a5e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0046a5e0
// Address:   0x0046a5e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046a5e0 @ 0x0046a5e0
// Stable ID: aa_0046a5e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0043fe60, FUN_0044b150, FUN_0046a5e0.
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

uint32_t /* width from decompiler */ FUN_0046a5e0(void)



{

  int iVar1;

  int *in_EAX;

  int iVar2;

  

  if (*in_EAX != 0) {

    iVar1 = *(int *)(*in_EAX + 0xc);

    iVar2 = FUN_0044b150(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4));

    FUN_0043fe60();

    *(int *)(iVar1 + 4) = iVar2;

    **(int **)(iVar2 + 4) = iVar2;

    return 1;

  }

  return 0;

}
