// =============================================================================
// FUN_00833640
// -----------------------------------------------------------------------------
// Stable ID: aa_00833640
// Address:   0x00833640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00833640 @ 0x00833640
// Stable ID: aa_00833640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076e5e0, FUN_00833640.
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

void __fastcall FUN_00833640(int param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  

  *(uint8_t *)(param_1 + 0x5dc) = 1;

  puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5e0);

  *puVar1 = *in_EAX;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5e4) = in_EAX[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5e8) = in_EAX[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5ec) = in_EAX[3];

  FUN_0076e5e0(puVar1,puVar1);

  return;

}
