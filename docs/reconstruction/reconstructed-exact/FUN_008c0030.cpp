// =============================================================================
// FUN_008c0030
// -----------------------------------------------------------------------------
// Stable ID: aa_008c0030
// Address:   0x008c0030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c0030 @ 0x008c0030
// Stable ID: aa_008c0030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: return×9, if×3, switch×1.
//  - Notable callees: FUN_008c0030, FUN_0092fb30.
//  - Return sites: 9.

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

uint8_t FUN_008c0030(void)



{

  int in_EAX;

  int iVar1;

  int unaff_EDI;

  

  if (in_EAX == 0) {

    return 0;

  }

  *(uint8_t *)(unaff_EDI + 0x51a) = 1;

  if (((*(char *)(unaff_EDI + 0x513) != '\0') && (DAT_00d1b6d8 != 0)) &&

     (iVar1 = FUN_0092fb30(), iVar1 == 2)) {

    return 0;

  }

  switch(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0xa8) + 0x38)) {

  case 6:

    break;

  default:

    *(uint8_t *)(unaff_EDI + 0x519) = 1;

    (**(code **)(**(int **)(unaff_EDI + 0x5b4) + 0xd4))(1);

    return *(uint8_t *)(unaff_EDI + 0x512);

  case 10:

    *(uint8_t *)(unaff_EDI + 0x516) = 1;

    (**(code **)(**(int **)(unaff_EDI + 0x5a8) + 0xd4))(1);

    return *(uint8_t *)(unaff_EDI + 0x50f);

  case 0xc:

    (**(code **)(**(int **)(unaff_EDI + 0x5a0) + 0xd4))(1);

    *(uint8_t *)(unaff_EDI + 0x514) = 1;

    return *(uint8_t *)(unaff_EDI + 0x50d);

  case 0x10:

    *(uint8_t *)(unaff_EDI + 0x517) = 1;

    (**(code **)(**(int **)(unaff_EDI + 0x5ac) + 0xd4))(1);

    return *(uint8_t *)(unaff_EDI + 0x510);

  case 0x1c:

    *(uint8_t *)(unaff_EDI + 0x515) = 1;

    (**(code **)(**(int **)(unaff_EDI + 0x5a4) + 0xd4))(1);

    return *(uint8_t *)(unaff_EDI + 0x50e);

  }

  if ((*(byte *)(*(int *)(*(int *)(in_EAX + 0xa8) + 0x3c) + 0x3f2) & 0x80) != 0) {

    *(uint8_t *)(unaff_EDI + 0x518) = 1;

    (**(code **)(**(int **)(unaff_EDI + 0x5b0) + 0xd4))();

    return *(uint8_t *)(unaff_EDI + 0x511);

  }

  *(uint8_t *)(unaff_EDI + 0x519) = 1;

  (**(code **)(**(int **)(unaff_EDI + 0x5b4) + 0xd4))(1);

  return *(uint8_t *)(unaff_EDI + 0x512);

}
