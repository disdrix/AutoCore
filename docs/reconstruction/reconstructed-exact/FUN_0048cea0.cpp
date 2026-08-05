// =============================================================================
// FUN_0048cea0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048cea0
// Address:   0x0048cea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048cea0 @ 0x0048cea0
// Stable ID: aa_0048cea0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, goto×2, do×1, while×1, for×1.
//  - Notable callees: isspace×2, FUN_0048cea0.
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

byte * FUN_0048cea0(byte *param_1,int param_2)



{

  int iVar1;

  byte bVar2;

  

  if ((param_1 == (byte *)0x0) || (bVar2 = *param_1, bVar2 == 0)) {

    return (byte *)0x0;

  }

  if (param_2 == 1) {

    do {

      if (bVar2 == 0xef) {

        if ((param_1[1] == 0xbb) && (param_1[2] == 0xbf)) {

          param_1 = param_1 + 3;

        }

        else {

          if (param_1[1] != 0xbf) goto LAB_0048cef5;

          if (param_1[2] == 0xbe) {

            param_1 = param_1 + 3;

          }

          else {

            if (param_1[2] != 0xbf) goto LAB_0048cef5;

            param_1 = param_1 + 3;

          }

        }

      }

      else {

LAB_0048cef5:

        iVar1 = isspace((uint)bVar2);

        if ((((iVar1 == 0) && (bVar2 != 10)) && (bVar2 != 0xd)) &&

           ((*param_1 != 10 && (*param_1 != 0xd)))) {

          return param_1;

        }

        param_1 = param_1 + 1;

      }

      bVar2 = *param_1;

    } while (bVar2 != 0);

  }

  else {

    for (; ((bVar2 = *param_1, bVar2 != 0 &&

            (((iVar1 = isspace((uint)bVar2), iVar1 != 0 || (bVar2 == 10)) || (bVar2 == 0xd)))) ||

           ((*param_1 == 10 || (*param_1 == 0xd)))); param_1 = param_1 + 1) {

    }

  }

  return param_1;

}
