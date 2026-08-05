// =============================================================================
// FUN_008a1280
// -----------------------------------------------------------------------------
// Stable ID: aa_008a1280
// Address:   0x008a1280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a1280 @ 0x008a1280
// Stable ID: aa_008a1280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008a0e10, FUN_008a1110, FUN_008a1280, NDUIWindow_ReloadInterface.
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

void __thiscall FUN_008a1280(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint8_t local_8 [8];

  

  NDUIWindow_ReloadInterface(param_2);

  FUN_008a1110();

  FUN_008a0e10(param_1);

  if (param_1[0x19b] != 0) {

    (**(code **)(*(int *)param_1[0x19b] + 0x134))(local_8);

    (**(code **)(*(int *)param_1[0x19b] + 0x118))(&stack0xffffffec);

  }

  if (param_1[0x19c] != 0) {

    (**(code **)(*(int *)param_1[0x19c] + 0x134))(local_8);

    (**(code **)(*(int *)param_1[0x19c] + 0x118))(&stack0xffffffec);

  }

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  return;

}
