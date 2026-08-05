// =============================================================================
// FUN_007fd7a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fd7a0
// Address:   0x007fd7a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fd7a0 @ 0x007fd7a0
// Stable ID: aa_007fd7a0
// Embedded strings (evidence for future rename):
//   - "Working.."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_007fb690, FUN_007fd7a0.
//  - Strings: "Working..".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_007fd7a0(void)



{

  int in_EAX;

  int *piVar1;

  int iVar2;

  

  if ((in_EAX != -1) && (in_EAX != 0)) {

    piVar1 = (int *)CVOGReaction_ResolveObjectTarget(0,in_EAX,in_EAX >> 0x1f);

    if (piVar1 != (int *)0x0) {

      iVar2 = (**(code **)(*piVar1 + 0x1e4))();

      if (iVar2 != 0) {

        iVar2 = (**(code **)(*piVar1 + 0x1e4))();

        if (*(char *)(iVar2 + 0x1d1) == '=') {

          FUN_007fb690(0,(float)*(int *)(iVar2 + 0x25c),0,"Working..",DAT_00afdef4,DAT_00afdef0,0,0)

          ;

          return 1;

        }

      }

    }

    return 0;

  }

  return 0;

}
