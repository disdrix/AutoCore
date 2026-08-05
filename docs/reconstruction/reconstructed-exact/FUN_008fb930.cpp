// =============================================================================
// FUN_008fb930
// -----------------------------------------------------------------------------
// Stable ID: aa_008fb930
// Address:   0x008fb930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008fb930 @ 0x008fb930
// Stable ID: aa_008fb930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_008fb930.
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

void FUN_008fb930(void)



{

  int iVar1;

  int unaff_ESI;

  int unaff_EDI;

  

  if (unaff_ESI != *(int *)(unaff_EDI + 0x660)) {

    iVar1 = (**(code **)(**(int **)(unaff_EDI + 0x548 + unaff_ESI * 4) + 0x164))(0);

    *(uint8_t *)(iVar1 + 3) = 0x32;

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x548 + unaff_ESI * 4) + 0xf8) = 0x32;

    (**(code **)(**(int **)(unaff_EDI + 0x548 + unaff_ESI * 4) + 0x154))(0,iVar1);

                    /* WARNING: Could not recover jumptable at 0x008fb979. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_EDI + 0x548 + unaff_ESI * 4) + 0x34c))();

    return;

  }

  return;

}
