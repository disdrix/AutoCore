// =============================================================================
// FUN_00681f00
// -----------------------------------------------------------------------------
// Stable ID: aa_00681f00
// Address:   0x00681f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00681f00 @ 0x00681f00
// Stable ID: aa_00681f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00681f00.
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

void __thiscall FUN_00681f00(int param_1,uint32_t /* width from decompiler */ param_2,uint8_t param_3)



{

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x2c) == (uint32_t /* width from decompiler */ *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = param_2;

    *(uint8_t *)(param_1 + 0x29) = param_3;

    return;

  }

  if (*(char *)(param_1 + 0x29) != '\0') {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x2c))(1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = unaff_retaddr;

    *(uint8_t *)(param_1 + 0x29) = (uint8_t)param_2;

    return;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = param_2;

  *(uint8_t *)(param_1 + 0x29) = param_3;

  return;

}
