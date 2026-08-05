// =============================================================================
// FUN_0060c3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0060c3c0
// Address:   0x0060c3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060c3c0 @ 0x0060c3c0
// Stable ID: aa_0060c3c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT22, FUN_0060c3c0.
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

void __fastcall FUN_0060c3c0(int param_1)



{

  uint32_t /* width from decompiler */ in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  

  if (*(int *)(param_1 + 0x44) == -1) {

    puVar1 = CVOGReaction_ResolveSkillTargets

                       (*(void **)(param_1 + 0x10),

                        CONCAT22((short)((uint)in_EAX >> 0x10),*(uint16_t *)(param_1 + 0x14)));

    if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = puVar1[0x53];

      *(bool *)(param_1 + 0x48) = *(char *)((int)puVar1 + 0x22) != '\0';

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar1);

    }

  }

  return;

}
