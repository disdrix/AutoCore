// =============================================================================
// Named_CalleeOf_Client_RecvLoginFail_00729940
// -----------------------------------------------------------------------------
// Stable ID: aa_00729940
// Callee of Client_RecvLoginFail
// Address:   0x00729940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvLoginFail: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: Client_EncryptAndPrepareAuthRequest, FUN_00729940.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvLoginFail
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

uint32_t /* width from decompiler */ __fastcall

Named_CalleeOf_Client_RecvLoginFail_00729940(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  

  if (*(int *)(in_EAX + 4) == 0) {

    return 0xffffffff;

  }

  uVar1 = Client_EncryptAndPrepareAuthRequest(*(int *)(in_EAX + 4),param_3,param_4,param_2,param_1);

  return uVar1;

}
