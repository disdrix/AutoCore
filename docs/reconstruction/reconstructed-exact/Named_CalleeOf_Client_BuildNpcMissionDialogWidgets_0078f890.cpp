// =============================================================================
// Named_CalleeOf_Client_BuildNpcMissionDialogWidgets_0078f890
// -----------------------------------------------------------------------------
// Stable ID: aa_0078f890
// Callee of Client_BuildNpcMissionDialogWidgets (+1 other named callers)
// Address:   0x0078f890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_BuildNpcMissionDialogWidgets: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_BuildNpcMissionDialogWidgets (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0078f890, FUN_00792d20.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_BuildNpcMissionDialogWidgets (+1 other named callers)
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

void Named_CalleeOf_Client_BuildNpcMissionDialogWidgets_0078f890(void)



{

  float fVar1;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  FUN_00792d20(unaff_ESI);

  unaff_ESI[0x140] = 0;

  fVar1 = g_flMultiKillCountBlend;

  unaff_ESI[0x12e] = 0;

  unaff_ESI[0x12f] = 0;

  unaff_ESI[0x12d] = 0;

  unaff_ESI[0x250] = 0;

  unaff_ESI[0x251] = 0;

  unaff_ESI[0x252] = 0;

  unaff_ESI[0x253] = 0;

  unaff_ESI[0x254] = 0;

  *(uint8_t *)(unaff_ESI + 0x124) = 0;

  *(uint8_t *)((int)unaff_ESI + 0xbf) = 0;

  *(uint8_t *)(unaff_ESI + 0x13f) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x4fd) = 0;

  *(uint8_t *)(unaff_ESI + 0x14c) = 0;

  *(uint8_t *)(unaff_ESI + 0x18d) = 0;

  *(uint8_t *)(unaff_ESI + 0x1ce) = 0;

  *(uint8_t *)(unaff_ESI + 0x20f) = 0;

  unaff_ESI[0x146] = 0;

  unaff_ESI[0x147] = 0;

  unaff_ESI[0x148] = 0;

  unaff_ESI[0x149] = 0;

  unaff_ESI[0x14a] = 0;

  unaff_ESI[0x14b] = 0;

  *unaff_ESI = &PTR_FUN_00a9944c;

  unaff_ESI[0x141] = fVar1;

  return;

}
