// =============================================================================
// FUN_0040fd60
// -----------------------------------------------------------------------------
// Stable ID: aa_0040fd60
// Address:   0x0040fd60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040fd60 @ 0x0040fd60
// Stable ID: aa_0040fd60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0040fd60, FUN_0040fde0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_0040fd60(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int in_EAX;

  void *pvVar2;

  uint uVar3;

  uint uVar4;

  

  if (((*(int *)(in_EAX + 0xc) + *(int *)(in_EAX + 0x10) & 3U) == 0) &&

     (*(uint *)(in_EAX + 8) <= *(int *)(in_EAX + 0x10) + 4U >> 2)) {

    FUN_0040fde0(1);

  }

  uVar3 = *(int *)(in_EAX + 0xc) + *(int *)(in_EAX + 0x10);

  uVar4 = uVar3 >> 2;

  if (*(uint *)(in_EAX + 8) <= uVar4) {

    uVar4 = uVar4 - *(uint *)(in_EAX + 8);

  }

  if (*(int *)(*(int *)(in_EAX + 4) + uVar4 * 4) == 0) {

    pvVar2 = operator_new(0x10);

    *(void **)(*(int *)(in_EAX + 4) + uVar4 * 4) = pvVar2;

  }

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(in_EAX + 4) + uVar4 * 4) + (uVar3 & 3) * 4);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar1 = *param_1;

  }

  *(int *)(in_EAX + 0x10) = *(int *)(in_EAX + 0x10) + 1;

  return;

}
