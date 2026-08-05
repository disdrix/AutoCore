// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGCharacter_ApplyCreateFromPack_005c9be0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c9be0
// Callee of Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket
// Address:   0x005c9be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005c9be0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_CVOGCharacter_ApplyCreateFromPack_005c9be0(int param_1)



{

  void *pvVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a6f6b;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0xd0) == 0) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(0x10);

    if (pvVar1 == (void *)0x0) {

      pvVar1 = (void *)0x0;

    }

    else {

      *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0xc) = 0;

    }

    *(void **)(param_1 + 0xd0) = pvVar1;

  }

  ExceptionList = local_c;

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0xd0);

}
