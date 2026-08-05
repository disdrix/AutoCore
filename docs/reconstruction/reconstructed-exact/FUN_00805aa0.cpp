// =============================================================================
// FUN_00805aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00805aa0
// Address:   0x00805aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00805aa0 @ 0x00805aa0
// Stable ID: aa_00805aa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: SelectObject×2, BitBlt, CreateCompatibleDC, DeleteDC, FUN_00805aa0.
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

void __thiscall FUN_00805aa0(int param_1,int param_2)



{

  HDC hdc;

  HGDIOBJ h;

  

  if (*(int *)(param_1 + 0x34) != 0) {

    hdc = CreateCompatibleDC(*(HDC *)(param_2 + 0x14));

    h = SelectObject(hdc,*(HGDIOBJ *)(param_1 + 0x34));

    BitBlt(*(HDC *)(param_2 + 0x14),0,0,*(int *)(param_1 + 4),*(int *)(param_1 + 8),hdc,

           *(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x20),*(DWORD *)(param_1 + 0x38));

    SelectObject(hdc,h);

    DeleteDC(hdc);

  }

  return;

}
