// =============================================================================
// FUN_00784f20
// -----------------------------------------------------------------------------
// Stable ID: aa_00784f20
// Address:   0x00784f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00784f20 @ 0x00784f20
// Stable ID: aa_00784f20
// Embedded strings (evidence for future rename):
//   - "Socket::~Socket"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×11, return×6.
//  - Notable callees: FUN_007803f0×2, swi×2, FUN_00780060, FUN_00784f20, WSACleanup, closesocket, shutdown.
//  - Strings: "Socket::~Socket".
//  - Return sites: 6.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00784f20(void)



{

  code *pcVar1;

  SOCKET *unaff_EDI;

  

  if (DAT_00d179e4 == 2) {

    if (DAT_00d179e0 != '\0') {

      if ((_DAT_00d206a8 & 1) == 0) {

        _DAT_00d206a8 = _DAT_00d206a8 | 1;

        _DAT_00d2069c = "Socket::~Socket";

        _DAT_00d206a0 = 0xffffffff;

        _DAT_00d206a4 = DAT_00d17a00;

        DAT_00d17a00 = &DAT_00d2069c;

      }

      FUN_007803f0(&DAT_00d2069c);

      DAT_00d179fc = DAT_00d179fc + 1;

      if ((DAT_00d179f8 != 0) && (DAT_00d179f8 <= DAT_00d179fc)) {

        pcVar1 = (code *)swi(3);

        (*pcVar1)();

        return;

      }

      if ((DAT_00afddd4 == '\0') && (DAT_00afddd0 < DAT_00d179e8)) {

        return;

      }

      pcVar1 = (code *)swi(3);

      (*pcVar1)();

      return;

    }

  }

  else if ((DAT_00d179e4 == 1) && (DAT_00d179e0 != '\0')) {

    if ((_DAT_00d206a8 & 2) == 0) {

      _DAT_00d206a8 = _DAT_00d206a8 | 2;

      _DAT_00d20690 = "Socket::~Socket";

      _DAT_00d20694 = 0xffffffff;

      _DAT_00d20698 = DAT_00d17a00;

      DAT_00d17a00 = &DAT_00d20690;

    }

    FUN_007803f0(&DAT_00d20690);

    FUN_00780060();

  }

  if (*unaff_EDI != 0xffffffff) {

    shutdown(*unaff_EDI,2);

    closesocket(*unaff_EDI);

  }

  DAT_00d17994 = DAT_00d17994 + -1;

  if (DAT_00d17994 == 0) {

    WSACleanup();

  }

  if (unaff_EDI[3] == 0) {

    if (unaff_EDI[2] == 0) {

      return;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_EDI[2] + 0x14));

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(unaff_EDI[3] + 0x14));

}
