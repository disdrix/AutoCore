// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_00923c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00923c50
// Callee of Named_CalleeOf_Client_RecvCreateCharacter
// Address:   0x00923c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvCreateCharacter: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007f9cc0, FUN_00917610, FUN_0091aa30, FUN_00923770, FUN_00923c50, FUN_00973590.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvCreateCharacter
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

void Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_00923c50(void)



{

  int iVar1;

  int *in_EAX;

  uint32_t /* width from decompiler */ local_14;

  

  *(uint8_t *)(in_EAX + 0x2a2) = 0xff;

  in_EAX[0x1d6] = 0;

  if (DAT_00d1a858 == '\0') {

    iVar1 = *(int *)(DAT_00d1b644 + 0xe894);

    FUN_00973590(*(float *)(iVar1 + 0x60) * DAT_00aaa6f8,*(float *)(iVar1 + 100) * DAT_00aaa6f8,

                 *(float *)(iVar1 + 0x68) * DAT_00aaa6f8,*(float *)(iVar1 + 0x6c) * DAT_00aaa6f8);

    *(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b628 + 0x2c) + 0xc4) = local_14;

  }

  else {

    *(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b628 + 0x2c) + 0xc4) = 0xff20a0dc;

  }

  in_EAX[0x126] = 0x4e2a;

  in_EAX[0x145] = 0x4e2a;

  in_EAX[0x127] = 0x4e2b;

  in_EAX[0x146] = 0x4e2b;

  *(uint8_t *)(*(int *)(DAT_00d1b644 + 0xe894) + 0x8c) = 1;

  in_EAX[0x294] = 0;

  (**(code **)(*in_EAX + 0x438))(DAT_00d1d86c,DAT_00d1d870);

  *(uint8_t *)(DAT_00d1f048 + 0xf) = 1;

  *(uint8_t *)(DAT_00d1f048 + 0x2d) = 1;

  FUN_0091aa30();

  FUN_00917610();

  FUN_00923770(in_EAX);

  (**(code **)(*in_EAX + 0x34c))();

  if (DAT_00d1b9a8 != 0) {

    FUN_007f9cc0();

  }

  return;

}
