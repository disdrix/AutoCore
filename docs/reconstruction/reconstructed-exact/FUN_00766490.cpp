// =============================================================================
// FUN_00766490
// -----------------------------------------------------------------------------
// Stable ID: aa_00766490
// Address:   0x00766490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00766490 @ 0x00766490
// Stable ID: aa_00766490
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007663b0, FUN_00766490.
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

void FUN_00766490(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  uVar1 = *in_EAX;

  uVar2 = in_EAX[1];

  uVar3 = in_EAX[2];

  uVar4 = in_EAX[3];

  FUN_007663b0(param_1);

  *unaff_EDI = uVar1;

  unaff_EDI[1] = uVar2;

  unaff_EDI[2] = uVar3;

  unaff_EDI[3] = uVar4;

  return;

}
