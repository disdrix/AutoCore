// =============================================================================
// FUN_0075b6a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075b6a0
// Address:   0x0075b6a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075b6a0 @ 0x0075b6a0
// Stable ID: aa_0075b6a0
// Embedded strings (evidence for future rename):
//   - "Failed to set viewport"
//   - "%s - %s\r\n%s"
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006a5dac, FUN_006b7a5a, FUN_0075b6a0, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Failed to set viewport"; "%s - %s\r\n%s"; "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp".
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

uint32_t /* width from decompiler */ FUN_0075b6a0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *unaff_retaddr;

  uint8_t local_18 [8];

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ *puStack_4;

  

  iVar1 = (**(code **)(*(int *)*DAT_00d1f044 + 0xc0))((int *)*DAT_00d1f044,local_18);

  if (iVar1 < 0) {

    uVar2 = FUN_006b7a5a(iVar1,"Failed to set viewport");

    uVar2 = FUN_006a5dac(iVar1,uVar2);

    uVar2 = FUN_0076cec0(&puStack_4,"%s - %s\r\n%s",uVar2);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp",0x1d1,3,uVar2);

  }

  *puStack_4 = uStack_10;

  *unaff_retaddr = uStack_c;

  return 0;

}
