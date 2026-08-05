// =============================================================================
// Named_CalleeOf_Client_ShowLoginFailureDialog_00912820
// -----------------------------------------------------------------------------
// Stable ID: aa_00912820
// Callee of Client_ShowLoginFailureDialog (+1 other named callers)
// Address:   0x00912820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ShowLoginFailureDialog: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_ShowLoginFailureDialog (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_00912820.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_ShowLoginFailureDialog (+1 other named callers)
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

void __fastcall Named_CalleeOf_Client_ShowLoginFailureDialog_00912820(int param_1)



{

  char cVar1;

  uint8_t *in_EAX;

  char *pcVar2;

  int iVar3;

  

  *(uint8_t *)(param_1 + 0xab4) = *in_EAX;

  *(uint8_t *)(param_1 + 0xab5) = in_EAX[1];

  *(uint8_t *)(param_1 + 0xab6) = in_EAX[2];

  *(uint8_t *)(param_1 + 0xab7) = in_EAX[3];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xab8) = *(uint32_t /* width from decompiler */ *)(in_EAX + 4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xabc) = *(uint32_t /* width from decompiler */ *)(in_EAX + 8);

  *(uint16_t *)(param_1 + 0xac0) = *(uint16_t *)(in_EAX + 0xc);

  pcVar2 = in_EAX + 0x14;

  iVar3 = (param_1 + 0xac8) - (int)pcVar2;

  do {

    cVar1 = *pcVar2;

    pcVar2[iVar3] = cVar1;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  return;

}
