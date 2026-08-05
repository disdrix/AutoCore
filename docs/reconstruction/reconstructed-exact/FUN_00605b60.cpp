// =============================================================================
// FUN_00605b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00605b60
// Address:   0x00605b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00605b60 @ 0x00605b60
// Stable ID: aa_00605b60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004e9530, FUN_00581d90, FUN_00605b60.
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

void __thiscall FUN_00605b60(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint8_t local_20 [28];

  

  FUN_00581d90(param_2,param_3,0x3f800000);

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_004e9530(local_20,param_2);

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);

  *puVar1 = *puVar2;

  puVar1[1] = puVar2[1];

  puVar1[2] = puVar2[2];

  puVar1[3] = puVar2[3];

  return;

}
