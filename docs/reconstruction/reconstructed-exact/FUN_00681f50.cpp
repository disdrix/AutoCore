// =============================================================================
// FUN_00681f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00681f50
// Address:   0x00681f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00681f50 @ 0x00681f50
// Stable ID: aa_00681f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00681f50.
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

void __thiscall FUN_00681f50(int param_1,uint32_t /* width from decompiler */ param_2,uint8_t param_3)



{

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  if (*(char *)(param_1 + 0x2a) == '\0') {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = param_2;

    *(uint8_t *)(param_1 + 0x2a) = param_3;

    return;

  }

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x30) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x30))(1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = unaff_retaddr;

    *(uint8_t *)(param_1 + 0x2a) = (uint8_t)param_2;

    return;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = param_2;

  *(uint8_t *)(param_1 + 0x2a) = param_3;

  return;

}
