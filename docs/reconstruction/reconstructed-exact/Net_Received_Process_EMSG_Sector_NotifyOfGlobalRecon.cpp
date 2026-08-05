// =============================================================================
// Net_Received_Process_EMSG_Sector_NotifyOfGlobalRecon
// -----------------------------------------------------------------------------
// Stable ID: aa_0080ba20
// Address:   0x0080ba20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Net_Received_Process_EMSG_Sector_NotifyOfGlobalRecon @ 0x0080ba20
// Stable ID: aa_0080ba20
// Embedded strings (evidence for future rename):
//   - "Received Process_EMSG_Sector_NotifyOfGlobalReconnect, Key:%d, IP:%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007a4480, Net_Received_Process_EMSG_Sector_NotifyOfGlobalRecon, FUN_009332b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Received Process_EMSG_Sector_NotifyOfGlobalReconnect, Key:%d, IP:%s"
 * Domain alias of FUN_0080ba20 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Net_Received_Process_EMSG_Sector_NotifyOfGlobalRecon(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int unaff_ESI;

  int unaff_EDI;

  

  if (*(int **)(unaff_ESI + 0xc7c) != (int *)0x0) {

    (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 0xc))();

  }

  FUN_007a4480(0,"Received Process_EMSG_Sector_NotifyOfGlobalReconnect, Key:%d, IP:%s",

               *(uint32_t /* width from decompiler */ *)(unaff_EDI + 4),unaff_ESI + 0x730);

  *(uint8_t *)(unaff_ESI + 0x854) = 1;

  uVar1 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 4);

  *(uint8_t *)(unaff_ESI + 0x113) = 1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x134) = uVar1;

  FUN_009332b0();

  return;

}
