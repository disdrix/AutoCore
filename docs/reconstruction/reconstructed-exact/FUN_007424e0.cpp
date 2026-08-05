// =============================================================================
// FUN_007424e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007424e0
// Address:   0x007424e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007424e0 @ 0x007424e0
// Stable ID: aa_007424e0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxPerfStatsPanel.cpp"
//   - "Failed to create font"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_007424e0, FUN_0099ed40, vog_LogMessage.
//  - Strings: ",0x1d,3,

                   ".
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

uint32_t /* width from decompiler */ * FUN_007424e0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b19da;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00aa2468;

  param_1[1] = 0;

  *(uint8_t *)(param_1 + 2) = 0;

  param_1[0x1f] = 0;

  local_4 = 2;

  *(uint8_t *)((int)param_1 + 0x82) = 0xff;

  *(uint8_t *)((int)param_1 + 0x81) = 0xff;

  *(uint8_t *)(param_1 + 0x20) = 0xff;

  *(uint8_t *)((int)param_1 + 0x83) = 0xff;

  *(uint8_t *)((int)param_1 + 0x86) = 0xff;

  *(uint8_t *)((int)param_1 + 0x85) = 0xff;

  *(uint8_t *)(param_1 + 0x21) = 0xff;

  *(uint8_t *)((int)param_1 + 0x87) = 0xff;

  *(uint8_t *)((int)param_1 + 0x8a) = 0xff;

  *(uint8_t *)((int)param_1 + 0x89) = 0xff;

  *(uint8_t *)(param_1 + 0x22) = 0xff;

  *(uint8_t *)((int)param_1 + 0x8b) = 0xff;

  *(uint8_t *)((int)param_1 + 0x8e) = 0xff;

  *(uint8_t *)((int)param_1 + 0x8d) = 0xff;

  *(uint8_t *)(param_1 + 0x23) = 0xff;

  *(uint8_t *)((int)param_1 + 0x8f) = 0xff;

  iVar1 = FUN_0099ed40(0xe);

  if (iVar1 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxPerfStatsPanel.cpp",0x1d,3,

                   "Failed to create font");

  }

  puVar2 = param_1 + 5;

  iVar1 = 4;

  do {

    puVar2[1] = 0;

    *puVar2 = 0;

    puVar2[-1] = 0;

    puVar2[-2] = 0;

    *(uint8_t *)(puVar2 + 2) = 1;

    *(uint8_t *)((int)puVar2 + 9) = 0;

    puVar2[3] = 0;

    puVar2[4] = 0;

    puVar2 = puVar2 + 7;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  *(uint8_t *)(param_1 + 0x1c) = 0;

  *(uint8_t *)(param_1 + 0xe) = 0;

  *(uint8_t *)((int)param_1 + 0x81) = 0;

  *(uint8_t *)(param_1 + 0x20) = 0;

  *(uint8_t *)((int)param_1 + 0x83) = 0xff;

  *(uint8_t *)((int)param_1 + 0x82) = 0xc0;

  *(uint8_t *)((int)param_1 + 0x86) = 0;

  *(uint8_t *)(param_1 + 0x21) = 0;

  *(uint8_t *)((int)param_1 + 0x87) = 0xff;

  *(uint8_t *)((int)param_1 + 0x85) = 0xc0;

  *(uint8_t *)((int)param_1 + 0x8a) = 0;

  *(uint8_t *)((int)param_1 + 0x8b) = 0xff;

  *(uint8_t *)((int)param_1 + 0x89) = 0x28;

  *(uint8_t *)(param_1 + 0x22) = 0x96;

  *(uint8_t *)((int)param_1 + 0x8d) = 0;

  *(uint8_t *)((int)param_1 + 0x8f) = 0xff;

  *(uint8_t *)((int)param_1 + 0x8e) = 0x78;

  *(uint8_t *)(param_1 + 0x23) = 0xc0;

  ExceptionList = local_c;

  return param_1;

}
