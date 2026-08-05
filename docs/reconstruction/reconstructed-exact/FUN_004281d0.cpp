// =============================================================================
// FUN_004281d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004281d0
// Address:   0x004281d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004281d0 @ 0x004281d0
// Stable ID: aa_004281d0
// Embedded strings (evidence for future rename):
//   - "HashError:Recreate, already locked for traversal"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_007a4480×2, FUN_004281d0, FUN_00428d10, FUN_00428db0.
//  - Strings: "HashError:Recreate, already locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 1.

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

void FUN_004281d0(void)



{

  int in_EAX;

  byte unaff_BL;

  

  if (*(char *)(in_EAX + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:Recreate, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  FUN_00428db0();

  *(byte *)(in_EAX + 0x1c) = unaff_BL;

  *(int *)(in_EAX + 8) = 1 << (unaff_BL & 0x1f);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x14) = 0;

  FUN_00428d10();

  return;

}
