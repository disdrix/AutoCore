// =============================================================================
// FUN_0048cf60
// -----------------------------------------------------------------------------
// Stable ID: aa_0048cf60
// Address:   0x0048cf60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048cf60 @ 0x0048cf60
// Stable ID: aa_0048cf60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×4, while×1.
//  - Notable callees: CONCAT31, FUN_0048a940, FUN_0048aa20, FUN_0048cf60, isalnum, isalpha.
//  - Return sites: 4.

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

byte * FUN_0048cf60(byte *param_1)



{

  byte bVar1;

  int iVar2;

  byte *pbVar3;

  

  FUN_0048a940(&DAT_00a1419b,0);

  pbVar3 = param_1;

  if (((param_1 != (byte *)0x0) && (bVar1 = *param_1, bVar1 != 0)) &&

     ((0x7e < bVar1 || ((iVar2 = isalpha((uint)bVar1), iVar2 != 0 || (*pbVar3 == 0x5f)))))) {

    while( true ) {

      bVar1 = *pbVar3;

      if (bVar1 == 0) {

        return pbVar3;

      }

      if (((((bVar1 < 0x7f) && (iVar2 = isalnum((uint)bVar1), iVar2 == 0)) &&

           (bVar1 = *pbVar3, bVar1 != 0x5f)) && ((bVar1 != 0x2d && (bVar1 != 0x2e)))) &&

         (bVar1 != 0x3a)) break;

      param_1 = (byte *)CONCAT31(param_1._1_3_,*pbVar3);

      FUN_0048aa20(&param_1,1);

      pbVar3 = pbVar3 + 1;

      if (pbVar3 == (byte *)0x0) {

        return (byte *)0x0;

      }

    }

    return pbVar3;

  }

  return (byte *)0x0;

}
