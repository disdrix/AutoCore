// =============================================================================
// FUN_007204d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007204d0
// Address:   0x007204d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007204d0 @ 0x007204d0
// Stable ID: aa_007204d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_007204d0.
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

uint32_t /* width from decompiler */ __thiscall FUN_007204d0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (*(char *)(param_1 + 0x10) != '\0') {

    *(uint8_t *)(param_1 + 0x12) = 1;

    puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x90);

    for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = *param_2;

      param_2 = param_2 + 1;

      puVar2 = puVar2 + 1;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x148) = 3;

    *(uint8_t *)(param_1 + 0x134) = 0;

    *(uint8_t *)(param_1 + 0x16) = 1;

  }

  return 0;

}
