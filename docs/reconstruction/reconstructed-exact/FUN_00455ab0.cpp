// =============================================================================
// FUN_00455ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_00455ab0
// Address:   0x00455ab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00455ab0 @ 0x00455ab0
// Stable ID: aa_00455ab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00453030, FUN_00455ab0.
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

void __fastcall

FUN_00455ab0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint8_t param_4)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  *unaff_ESI = param_1;

  unaff_ESI[1] = param_2;

  unaff_ESI[2] = param_3;

  unaff_ESI[3] = *in_EAX;

  unaff_ESI[4] = in_EAX[1];

  unaff_ESI[5] = in_EAX[2];

  unaff_ESI[6] = in_EAX[3];

  unaff_ESI[7] = in_EAX[4];

  unaff_ESI[8] = in_EAX[5];

  FUN_00453030();

  *(uint8_t *)(unaff_ESI + 0x20) = param_4;

  *(uint8_t *)((int)unaff_ESI + 0x81) = 0;

  return;

}
