// =============================================================================
// FUN_0056a500
// -----------------------------------------------------------------------------
// Stable ID: aa_0056a500
// Address:   0x0056a500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056a500 @ 0x0056a500
// Stable ID: aa_0056a500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004bc180×2, FUN_0056a500.
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

void __fastcall FUN_0056a500(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(*(int *)(param_1 + -0x14c) + 4);

  iVar2 = iVar1 + param_1;

  iVar2 = CVOGReaction_ResolveObjectTarget

                    (*(uint8_t *)(iVar2 + 0x1c),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x14),

                     *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18 + param_1));

  if (iVar2 == 0) {

    if (param_1 == 0x150) {

      FUN_004bc180(0);

      return;

    }

    FUN_004bc180(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x14c + param_1);

  }

  return;

}
