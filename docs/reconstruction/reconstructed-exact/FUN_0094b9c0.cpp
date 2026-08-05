// =============================================================================
// FUN_0094b9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094b9c0
// Address:   0x0094b9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094b9c0 @ 0x0094b9c0
// Stable ID: aa_0094b9c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: while×2, do×1, return×1.
//  - Notable callees: PeekMessageA×2, DispatchMessageA, FUN_0094b520, FUN_0094b9c0, TranslateMessage.
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

WPARAM FUN_0094b9c0(void)



{

  bool bVar1;

  int iVar2;

  tagMSG local_1c;

  

  do {

    bVar1 = true;

    FUN_0094b520();

    iVar2 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);

    while (iVar2 != 0) {

      bVar1 = (bool)(bVar1 & local_1c.message != 0x12);

      TranslateMessage(&local_1c);

      DispatchMessageA(&local_1c);

      iVar2 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);

    }

  } while (bVar1);

  return local_1c.wParam;

}
