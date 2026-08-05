// =============================================================================
// FUN_00774a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00774a10
// Address:   0x00774a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00774a10 @ 0x00774a10
// Stable ID: aa_00774a10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, goto×2, do×1, while×1.
//  - Notable callees: FUN_00770440×2, FUN_007707d0×2, FUN_00772190×2, FUN_00772390×2, FUN_00773600×2, FUN_007701d0, FUN_00770280, FUN_00770540.
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

int FUN_00774a10(int *param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ extraout_EDX;

  uint8_t local_20 [16];

  uint8_t local_10 [16];

  

  if (param_1[2] == 1) {

    return -3;

  }

  if (*param_1 == 0) {

    FUN_007701d0();

    return 0;

  }

  iVar1 = FUN_00770440();

  if ((iVar1 == 0) && (iVar1 = FUN_00770650(), iVar1 == 0)) {

    iVar1 = FUN_00770440();

    if (iVar1 == 0) {

      FUN_00770280();

      iVar1 = FUN_00773600(param_1,extraout_EDX,local_10,0);

      if (iVar1 == 0) {

        iVar1 = FUN_00772390();

        if ((iVar1 == 0) && (iVar1 = FUN_00772190(local_20), iVar1 == 0)) {

          do {

            iVar1 = FUN_00773600(param_1,local_20,local_10,0);

            if (iVar1 != 0) goto LAB_00774b2e;

            iVar1 = FUN_00772390();

            if ((iVar1 != 0) || (iVar1 = FUN_00772190(local_20), iVar1 != 0)) goto LAB_00774b2e;

            iVar2 = FUN_00770710();

          } while (iVar2 == 1);

          FUN_00770540();

        }

      }

LAB_00774b2e:

      FUN_007707d0();

    }

    FUN_007707d0();

  }

  return iVar1;

}
