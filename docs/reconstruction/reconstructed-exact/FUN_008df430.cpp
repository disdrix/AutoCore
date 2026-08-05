// =============================================================================
// FUN_008df430
// -----------------------------------------------------------------------------
// Stable ID: aa_008df430
// Address:   0x008df430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008df430 @ 0x008df430
// Stable ID: aa_008df430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×7, return×7.
//  - Notable callees: FUN_0052ada0×5, FUN_0052b040, FUN_008df430.
//  - Return sites: 7.

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

uint32_t /* width from decompiler */ FUN_008df430(void)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  int unaff_ESI;

  int local_1f4;

  int local_1f0;

  int local_1ec;

  int local_1e8;

  int local_1e4;

  short local_1e0;

  short local_1de;

  short local_1dc;

  short local_1da;

  short local_1d8;

  

  if (((DAT_00d1b6d8 != 0) && (in_EAX != -1)) && (unaff_ESI != -1)) {

    cVar1 = FUN_0052b040();

    if (cVar1 == '\0') {

      return 0;

    }

    if ((unaff_ESI == local_1f4) && (iVar2 = FUN_0052ada0(unaff_ESI), local_1e0 <= iVar2)) {

      return 1;

    }

    if ((unaff_ESI == local_1f0) && (iVar2 = FUN_0052ada0(unaff_ESI), local_1de <= iVar2)) {

      return 1;

    }

    if ((unaff_ESI == local_1ec) && (iVar2 = FUN_0052ada0(unaff_ESI), local_1dc <= iVar2)) {

      return 1;

    }

    if ((unaff_ESI == local_1e8) && (iVar2 = FUN_0052ada0(unaff_ESI), local_1da <= iVar2)) {

      return 1;

    }

    if ((unaff_ESI == local_1e4) && (iVar2 = FUN_0052ada0(unaff_ESI), local_1d8 <= iVar2)) {

      return 1;

    }

  }

  return 0;

}
