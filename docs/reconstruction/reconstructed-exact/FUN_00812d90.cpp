// =============================================================================
// FUN_00812d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00812d90
// Address:   0x00812d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00812d90 @ 0x00812d90
// Stable ID: aa_00812d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00812d90, FUN_009423b0.
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

void FUN_00812d90(void)



{

  int *piVar1;

  int iVar2;

  int unaff_ESI;

  int unaff_EDI;

  

  piVar1 = (int *)CVOGReaction_ResolveObjectTarget

                            (1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc));

  if ((piVar1 != (int *)0x0) && (*(int *)(piVar1[0x2a] + 0x38) == 0x14)) {

    iVar2 = (**(code **)(*piVar1 + 0x1dc))();

    if (iVar2 == *(int *)(unaff_EDI + 0xe98)) {

      FUN_009423b0(unaff_EDI,*(uint8_t *)(unaff_ESI + 0x10),1);

    }

  }

  return;

}
