// =============================================================================
// FUN_00411e40
// -----------------------------------------------------------------------------
// Stable ID: aa_00411e40
// Address:   0x00411e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00411e40 @ 0x00411e40
// Stable ID: aa_00411e40
// Embedded strings (evidence for future rename):
//   - "HashError:TraverseToNext, not locked for traversal"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, for×1.
//  - Notable callees: FUN_007a4480×2, FUN_00411e40.
//  - Strings: "HashError:TraverseToNext, not locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ FUN_00411e40(void)



{

  int iVar1;

  int *unaff_ESI;

  int unaff_EDI;

  

  if (*(char *)(unaff_EDI + 0x1d) == '\0') {

    FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  if (*unaff_ESI == 0) {

    *unaff_ESI = *(int *)(unaff_EDI + 0x14);

    iVar1 = *(int *)(unaff_EDI + 0x14);

  }

  else {

    iVar1 = *(int *)(*unaff_ESI + 0x14);

    *unaff_ESI = iVar1;

  }

  if (iVar1 != 0) {

    return *(uint32_t /* width from decompiler */ *)(iVar1 + 8);

  }

  return 0;

}
