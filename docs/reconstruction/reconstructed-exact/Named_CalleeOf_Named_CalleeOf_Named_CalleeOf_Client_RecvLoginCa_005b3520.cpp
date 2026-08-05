// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_005b3520
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3520
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3
// Address:   0x005b3520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005b3520, FUN_0074e310.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_005b3520(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*(int *)(param_1 + 0x154) == 0) {

    iVar1 = *(int *)(*(int *)(param_1 + 0x15c) + 0xe894);

    if ((*(int *)(iVar1 + 0x108) != 0) && (*(int *)(iVar1 + 0x104) == 0)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x154) = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0x108) + 0x8c);

      uVar2 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(*(int *)(param_1 + 0x15c) + 0xe894) + 0x104) + 0x8c)

      ;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x150) = uVar2;

      FUN_0074e310(uVar2);

    }

  }

  return;

}
