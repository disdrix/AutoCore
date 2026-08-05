// =============================================================================
// FUN_005c00b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c00b0
// Address:   0x005c00b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c00b0 @ 0x005c00b0
// Stable ID: aa_005c00b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_005c00b0.
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

uint __fastcall FUN_005c00b0(int param_1)



{

  int *piVar1;

  int *piVar2;

  uint in_EAX;

  

  if (*(char *)(param_1 + 0xe8) != '\0') {

    *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;

    piVar2 = *(int **)(param_1 + 0x14);

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        in_EAX = (**(code **)(*piVar2 + 8))();

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

    }

    *(uint8_t *)(param_1 + 0xe8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = 0;

  }

  return in_EAX & 0xffffff00;

}
