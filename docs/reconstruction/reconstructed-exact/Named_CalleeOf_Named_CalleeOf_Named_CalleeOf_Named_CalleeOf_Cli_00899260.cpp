// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00899260
// -----------------------------------------------------------------------------
// Stable ID: aa_00899260
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC
// Address:   0x00899260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00899030, FUN_00899260.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00899260(void)



{

  int iVar1;

  int in_EAX;

  float in_XMM0_Da;

  float in_XMM1_Da;

  float fVar2;

  

  iVar1 = *(int *)(in_EAX + 0x534);

  if (iVar1 != 0) {

    fVar2 = in_XMM0_Da;

    if (in_XMM0_Da <= in_XMM1_Da) {

      fVar2 = in_XMM1_Da;

    }

    DAT_00af9328 = in_XMM0_Da;

    DAT_00af932c = in_XMM1_Da;

    *(float *)(iVar1 + 0x500) = fVar2;

    if (in_XMM1_Da <= in_XMM0_Da) {

      in_XMM0_Da = in_XMM1_Da;

    }

    _DAT_00af9330 = (in_XMM0_Da * DAT_00a0f298) / *(float *)(iVar1 + 0x504);

    if (_DAT_00af9330 < g_flOne) {

      _DAT_00af9330 = g_flOne;

    }

    FUN_00899030();

  }

  return;

}
