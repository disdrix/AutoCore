// =============================================================================
// FUN_004bbbc0
// -----------------------------------------------------------------------------
// Stable ID: aa_004bbbc0
// Address:   0x004bbbc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bbbc0 @ 0x004bbbc0
// Stable ID: aa_004bbbc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_004bbbc0.
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

uint32_t /* width from decompiler */ FUN_004bbbc0(int param_1,uint8_t *param_2)



{

  uint8_t uVar1;

  int *piVar2;

  

  piVar2 = *(int **)(param_1 + 0x140);

  if (piVar2 == (int *)0x0) {

    piVar2 = (int *)CVOGReaction_ResolveObjectTarget

                              (*(uint32_t /* width from decompiler */ *)(param_1 + 0x130),*(uint *)(param_1 + 0x128),

                               *(uint32_t /* width from decompiler */ *)(param_1 + 300));

    *(int **)(param_1 + 0x140) = piVar2;

    if (piVar2 == (int *)0x0) {

      if ((*(uint *)(param_1 + 0x128) & *(uint *)(param_1 + 300)) == 0xffffffff) {

        return 1;

      }

      return 0;

    }

  }

  (**(code **)(*piVar2 + 0x144))();

  *(int *)(param_1 + 0x10) = piVar2[0x20];

  *(int *)(param_1 + 0x14) = piVar2[0x21];

  *(int *)(param_1 + 0x18) = piVar2[0x22];

  *(int *)(param_1 + 0x1c) = piVar2[0x23];

  uVar1 = (**(code **)(*piVar2 + 0x198))();

  *param_2 = uVar1;

  return 1;

}
