// =============================================================================
// FUN_0092f140
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f140
// Address:   0x0092f140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092f140 @ 0x0092f140
// Stable ID: aa_0092f140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0048ead0, FUN_0092f140.
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

void __thiscall FUN_0092f140(int param_1,int param_2)



{

  int iVar1;

  float fVar2;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0xe04) + 0xe890);

  fVar2 = (float)param_2 * DAT_00a27c54;

  *(uint8_t *)(iVar1 + 0x48) = 1;

  *(uint8_t *)(iVar1 + 0xcc) = 1;

  *(float *)(iVar1 + 0x10c) = fVar2;

  FUN_0048ead0();

  return;

}
