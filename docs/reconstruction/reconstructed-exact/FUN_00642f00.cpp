// =============================================================================
// FUN_00642f00
// -----------------------------------------------------------------------------
// Stable ID: aa_00642f00
// Address:   0x00642f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00642f00 @ 0x00642f00
// Stable ID: aa_00642f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00642f00.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00642f00(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  byte unaff_retaddr;

  

  puVar1 = (uint32_t /* width from decompiler */ *)param_1[2];

  *param_1 = &PTR_FUN_009e443c;

  if ((puVar1 != (uint32_t /* width from decompiler */ *)0x0) &&

     (*(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1,

     *(short *)((int)puVar1 + 6) == 0)) {

    (**(code **)*puVar1)(1);

  }

  (**(code **)(*DAT_00b05060 + 0xc))(param_1[3]);

  *param_1 = &PTR_LAB_009cc290;

  if ((unaff_retaddr & 1) != 0) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1,*(uint16_t *)(param_1 + 1),0x15);

  }

  return param_1;

}
