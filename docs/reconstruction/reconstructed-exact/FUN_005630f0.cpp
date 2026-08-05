// =============================================================================
// FUN_005630f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005630f0
// Address:   0x005630f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005630f0 @ 0x005630f0
// Stable ID: aa_005630f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~125 non-empty decompiler lines.
//  - Control keywords: return×39, if×25, switch×4.
//  - Notable callees: FUN_005630f0.
//  - Return sites: 39.

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

uint32_t /* width from decompiler */ FUN_005630f0(int param_1)



{

  if (param_1 < 0x570) {

    if (param_1 == 0x56f) {

      return 0xd;

    }

    if (param_1 < 0x4a8) {

      if (param_1 == 0x4a7) {

        return 0x1b;

      }

      if (param_1 < 0x328) {

        if (param_1 == 0x327) {

          return 0x17;

        }

        switch(param_1) {

        case 1:

          return 0x20;

        case 2:

          return 0x2a;

        case 3:

          return 0x21;

        case 4:

          return 0x25;

        }

      }

      else if (param_1 < 0x416) {

        if (param_1 == 0x415) {

          return 0x19;

        }

        if (param_1 == 0x329) {

          return 0x18;

        }

        if (param_1 == 0x349) {

          return 0x1a;

        }

      }

      else if (param_1 == 0x464) {

        return 0x12;

      }

    }

    else {

      switch(param_1) {

      case 0x4a8:

        return 0xe;

      case 0x4a9:

        return 0x10;

      case 0x4aa:

        return 0x1c;

      case 0x4ab:

        return 0x14;

      case 0x4ac:

        return 0x1e;

      case 0x4ad:

        return 0x1d;

      case 0x567:

        return 7;

      case 0x56d:

        return 10;

      case 0x56e:

        return 0xb;

      }

    }

  }

  else if (param_1 < 0x6c0) {

    if (param_1 == 0x6bf) {

      return 0x24;

    }

    if (param_1 < 0x5b9) {

      if (param_1 == 0x5b8) {

        return 0x2e;

      }

      switch(param_1) {

      case 0x589:

        return 0xc;

      case 0x591:

        return 8;

      case 0x5b6:

        return 0x2c;

      case 0x5b7:

        return 0x2d;

      }

    }

    else if (param_1 < 0x6be) {

      if (param_1 == 0x6bd) {

        return 5;

      }

      if (param_1 == 0x5b9) {

        return 0x2f;

      }

      if (param_1 == 0x5c3) {

        return 0x2b;

      }

    }

    else if (param_1 == 0x6be) {

      return 0x22;

    }

  }

  else if (param_1 < 0x762) {

    if (param_1 == 0x761) {

      return 0x1f;

    }

    switch(param_1) {

    case 0x6c0:

      return 0x26;

    case 0x6c9:

      return 9;

    case 0x6cc:

      return 4;

    case 0x6d1:

      return 6;

    }

  }

  else {

    if (param_1 == 0x7bf) {

      return 0x27;

    }

    if (param_1 == 0x814) {

      return 0x16;

    }

    if (param_1 == 0x815) {

      return 0x15;

    }

  }

  return 0xffffffff;

}
