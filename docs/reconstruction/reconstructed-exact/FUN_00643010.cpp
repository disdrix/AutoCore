// =============================================================================
// FUN_00643010
// -----------------------------------------------------------------------------
// Stable ID: aa_00643010
// Address:   0x00643010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00643010 @ 0x00643010
// Stable ID: aa_00643010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00643010.
//  - Return sites: 2.

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

int __fastcall FUN_00643010(int *param_1)



{

  int iVar1;

  uint8_t *puVar2;

  

  puVar2 = &stack0xffffffff;

  iVar1 = (**(code **)(*param_1 + 8))(puVar2,1,param_1);

  if (iVar1 != 0) {

    return (int)(char)((uint)puVar2 >> 0x18);

  }

  return -1;

}
