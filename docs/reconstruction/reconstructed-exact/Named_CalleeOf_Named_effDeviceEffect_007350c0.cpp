// =============================================================================
// Named_CalleeOf_Named_effDeviceEffect_007350c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007350c0
// Callee of Named_effDeviceEffect
// Address:   0x007350c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00466680×3, FUN_00445620×2, FUN_00466980×2, FUN_004406e0, FUN_00466780, FUN_00466880, FUN_00466a80, FUN_00466b80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_effDeviceEffect
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

undefined * Named_CalleeOf_Named_effDeviceEffect_007350c0(void)



{

  char *_Dest;

  

  if ((DAT_00d1eeec == 0) || (DAT_00d1eef0 - DAT_00d1eeec >> 2 == 0)) {

    FUN_00734b30(&DAT_00d1eee8);

    FUN_00466680(&DAT_00d1eef8,&DAT_00afa44c);

    FUN_00466680(&DAT_00d1eef8,&DAT_00afa474);

    FUN_00466780(&DAT_00d1eef8,&DAT_00afa49c);

    FUN_00466880(&DAT_00d1eef8,&DAT_00afa4ac);

    FUN_00466980(&DAT_00d1eef8,&DAT_00afa4e4);

    FUN_00466680(&DAT_00d1eef8,&DAT_00afa4fc);

    FUN_00466a80(&DAT_00d1eef8,&DAT_00afa524);

    FUN_00466980(&DAT_00d1eef8,&DAT_00afa544);

    FUN_00466b80(&DAT_00d1eef8,&DAT_00afa560);

    FUN_00466c80(&DAT_00d1eef8,&DAT_00afa5d0);

    _Dest = malloc(0x20);

    _ltoa(*(long *)(DAT_00d1f044 + 0x78c),_Dest,10);

    FUN_00445620();

    FUN_004406e0();

    FUN_00445620();

  }

  return &DAT_00d1eef8;

}
