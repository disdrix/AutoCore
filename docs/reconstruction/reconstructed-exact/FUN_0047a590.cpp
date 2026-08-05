// =============================================================================
// FUN_0047a590
// -----------------------------------------------------------------------------
// Stable ID: aa_0047a590
// Address:   0x0047a590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047a590 @ 0x0047a590
// Stable ID: aa_0047a590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, goto×2.
//  - Notable callees: FUN_00476cc0, FUN_0047a590.
//  - Return sites: 3.

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

bool __fastcall FUN_0047a590(uint param_1)



{

  bool bVar1;

  int unaff_ESI;

  ushort uStack_2;

  

  bVar1 = true;

  if ((*(byte *)(unaff_ESI + 0x11c) & 0x20) == 0) {

    if ((*(byte *)(unaff_ESI + 0x6d) & 8) == 0) goto LAB_0047a5b9;

  }

  else if ((*(uint *)(unaff_ESI + 0x6c) & 0x300) != 0x300) goto LAB_0047a5b9;

  bVar1 = false;

LAB_0047a5b9:

  if (*(code **)(unaff_ESI + 0x50) == (code *)0x0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0();

  }

  (**(code **)(unaff_ESI + 0x50))();

  if (!bVar1) {

    return false;

  }

  uStack_2 = (ushort)(param_1 >> 0x10);

  return (((param_1 & 0xff) * 0x100 + (param_1 >> 8 & 0xff)) * 0x100 + (uStack_2 & 0xff)) * 0x100 +

         (uint)(uStack_2 >> 8) != *(int *)(unaff_ESI + 0x110);

}
