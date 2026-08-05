// =============================================================================
// FUN_007a3c80
// -----------------------------------------------------------------------------
// Stable ID: aa_007a3c80
// Address:   0x007a3c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a3c80 @ 0x007a3c80
// Stable ID: aa_007a3c80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00754480, FUN_007a3c80, SendNotifyMessageA.
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

int __fastcall FUN_007a3c80(int param_1)



{

  int iVar1;

  

  iVar1 = FUN_00754480();

  if (iVar1 == 0) {

    SendNotifyMessageA((HWND)0xffff,0x801b,0,0);

    *(uint8_t *)(param_1 + 300) = 1;

  }

  return iVar1;

}
