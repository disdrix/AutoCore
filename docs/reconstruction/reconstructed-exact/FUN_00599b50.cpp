// =============================================================================
// FUN_00599b50
// -----------------------------------------------------------------------------
// Stable ID: aa_00599b50
// Address:   0x00599b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00599b50 @ 0x00599b50
// Stable ID: aa_00599b50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: fread×4, CoTaskMemAlloc, CoTaskMemFree, FUN_00599b50.
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

void __thiscall FUN_00599b50(int param_1,FILE *param_2)



{

  LPVOID _DstBuf;

  

  if (*(LPVOID *)(param_1 + 0x720) != (LPVOID)0x0) {

    CoTaskMemFree(*(LPVOID *)(param_1 + 0x720));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x720) = 0;

  }

  fread((void *)(param_1 + 4),0x3b4,1,param_2);

  fread((void *)(param_1 + 0x3b8),0x108,1,param_2);

  fread((void *)(param_1 + 0x4c0),0x284,1,param_2);

  if (*(byte *)(param_1 + 0x716) != 0) {

    _DstBuf = CoTaskMemAlloc((uint)*(byte *)(param_1 + 0x716) * 0x110);

    *(LPVOID *)(param_1 + 0x720) = _DstBuf;

    fread(_DstBuf,0x110,(uint)*(byte *)(param_1 + 0x716),param_2);

  }

  return;

}
