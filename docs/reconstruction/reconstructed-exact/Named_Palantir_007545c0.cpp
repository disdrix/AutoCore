// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×11, return×6.
//  - Notable callees: FUN_00444620, FUN_007545c0, FUN_0075e6d0, FUN_0075ec90, FUN_0075ece0, FUN_0075fb90, FUN_009668a0, FUN_00968b20.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\framework\\Palantir.cpp"; "Failed Render.".
//  - Return sites: 6.

// =============================================================================
// Named_Palantir_007545c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007545c0
// Address:   0x007545c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Palantir"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_Palantir_007545c0(void)



{

  int *in_EAX;

  int iVar1;

  int iVar2;

  

  if (in_EAX[10] != 0) {

    if ((char)in_EAX[1] == '\0') {

      return 0;

    }

    if (DAT_00d1f614 != 0) {

      FUN_009668a0(DAT_00d1f614);

    }

    iVar1 = FUN_0075e6d0();

    if (iVar1 == 0) {

      if (*(char *)((int)in_EAX + 6) == '\0') {

        iVar1 = FUN_0075fb90();

        if (-1 < iVar1) {

          FUN_00968b20();

          iVar1 = (**(code **)(*(int *)in_EAX[0xb] + 0x28))();

          if (iVar1 < 0) {

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\framework\\Palantir.cpp",0x16b,3,

                           "Failed Render.");

            return -1;

          }

          iVar1 = FUN_0075ece0();

          if (-1 < iVar1) {

            iVar2 = FUN_0075ec90();

            if (iVar2 != 0) {

              iVar1 = 1;

            }

            FUN_00444620();

          }

        }

        return iVar1;

      }

    }

    else {

      if (iVar1 == 1) {

        return 1;

      }

      if (iVar1 != 2) {

        return -1;

      }

    }

    (**(code **)(*in_EAX + 4))();

  }

  return 1;

}
