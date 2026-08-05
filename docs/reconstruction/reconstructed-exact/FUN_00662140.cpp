// =============================================================================
// FUN_00662140
// -----------------------------------------------------------------------------
// Stable ID: aa_00662140
// Address:   0x00662140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00662140 @ 0x00662140
// Stable ID: aa_00662140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00646a60×4, CONCAT11, FUN_00662140.
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

int FUN_00662140(float param_1,float param_2,float param_3,float param_4)



{

  uint8_t uVar1;

  uint8_t uVar2;

  byte bVar3;

  uint uVar4;

  

  uVar1 = FUN_00646a60(param_4 * DAT_00aaa6f8);

  uVar2 = FUN_00646a60(param_1 * DAT_00aaa6f8);

  bVar3 = FUN_00646a60(param_2 * DAT_00aaa6f8);

  uVar4 = FUN_00646a60(param_3 * DAT_00aaa6f8);

  return (uVar4 & 0xff) + ((uint)CONCAT11(uVar1,uVar2) * 0x100 + (uint)bVar3) * 0x100;

}
