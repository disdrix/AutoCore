// =============================================================================
// FUN_00844b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00844b00
// Address:   0x00844b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00844b00 @ 0x00844b00
// Stable ID: aa_00844b00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT22, FUN_00844b00.
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

void __fastcall FUN_00844b00(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  if ((param_1 != 0) && (*(void **)(param_1 + 0x150) != (void *)0x0)) {

    puVar1 = CVOGReaction_ResolveSkillTargets

                       (*(void **)(param_1 + 0x150),

                        CONCAT22((short)((uint)param_1 >> 0x10),*(uint16_t *)(param_1 + 0x5f6)));

                    /* WARNING: Subroutine does not return */

    operator_delete(puVar1);

  }

  return;

}
