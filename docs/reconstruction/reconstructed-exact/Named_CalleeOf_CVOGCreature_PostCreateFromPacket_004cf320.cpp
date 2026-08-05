// =============================================================================
// Named_CalleeOf_CVOGCreature_PostCreateFromPacket_004cf320
// -----------------------------------------------------------------------------
// Stable ID: aa_004cf320
// Callee of CVOGCreature_PostCreateFromPacket
// Address:   0x004cf320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGCreature_PostCreateFromPacket: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT31, FUN_004cf320, FUN_00568920.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGCreature_PostCreateFromPacket
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

void __fastcall Named_CalleeOf_CVOGCreature_PostCreateFromPacket_004cf320(int param_1)



{

  void *pvVar1;

  void *local_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1f36;

  local_c = ExceptionList;

  if (DAT_00b037ec == 0) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x2c);

    local_4 = 0;

    if (pvVar1 != (void *)0x0) {

      local_14 = (void *)CONCAT31(local_14._1_3_,*(uint8_t *)(param_1 + 0x7e));

      DAT_00b037ec = FUN_00568920(DAT_00b041fc,local_14);

      ExceptionList = local_14;

      return;

    }

    DAT_00b037ec = 0;

  }

  ExceptionList = local_c;

  return;

}
