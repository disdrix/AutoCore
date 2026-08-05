// =============================================================================
// FUN_00804290
// -----------------------------------------------------------------------------
// Stable ID: aa_00804290
// Address:   0x00804290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00804290 @ 0x00804290
// Stable ID: aa_00804290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00804290, GetStockObject, GetTickCount.
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

int __fastcall FUN_00804290(int *param_1)



{

  DWORD DVar1;

  HGDIOBJ pvVar2;

  

  param_1[0x5d] = 1000;

  param_1[0x5f] = 0x14;

  param_1[0x62] = -1;

  param_1[0x60] = 0;

  param_1[0x5c] = 0;

  DVar1 = GetTickCount();

  param_1[0x60] = DVar1;

  param_1[99] = 0;

  param_1[100] = 0;

  param_1[0x5e] = 1000;

  param_1[0x61] = 1;

  pvVar2 = GetStockObject(0x11);

  param_1[0x4d] = (int)pvVar2;

  if (pvVar2 != (HGDIOBJ)0x0) {

    (**(code **)(*param_1 + 0x74))(8);

  }

  return (-(uint)(param_1[0x4d] != 0) & 0x7ff8fff2) + 0x8007000e;

}
