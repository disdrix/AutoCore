// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0076cec0, FUN_00966fe0, vog_LogMessage.
//  - Strings: "VertexDexlFactory has %d decls still active.".
//  - Return sites: 1.

// =============================================================================
// Named_effVertexDeclFactory_00966fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00966fe0
// Address:   0x00966fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effVertexDeclFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_effVertexDeclFactory_00966fe0(void)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t local_4 [4];

  

  if ((*(int *)(in_EAX + 4) != 0) &&

     (iVar1 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2, iVar1 != 0)) {

    uVar2 = FUN_0076cec0(local_4,"VertexDexlFactory has %d decls still active.",iVar1);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effVertexDeclFactory.cpp"

                   ,0xec,2,uVar2);

  }

  return;

}
