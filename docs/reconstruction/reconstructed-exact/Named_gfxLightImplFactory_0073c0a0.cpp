// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0073bea0, FUN_0073c0a0, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Unknown Light Type Name: \'%s\'".
//  - Return sites: 2.

// =============================================================================
// Named_gfxLightImplFactory_0073c0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073c0a0
// Address:   0x0073c0a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxLightImplFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_gfxLightImplFactory_0073c0a0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  uint8_t local_4 [4];

  

  iVar1 = FUN_0073bea0(unaff_EDI);

  if (-1 < iVar1) {

    uVar2 = (**(code **)(unaff_ESI + 0x20 + iVar1 * 0x2c))(iVar1);

    return uVar2;

  }

  uVar2 = FUN_0076cec0(local_4,"Unknown Light Type Name: \'%s\'");

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightImplFactory.cpp",0x4f,3,

                 uVar2);

  return 0;

}
