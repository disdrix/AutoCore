// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0047dc00
// -----------------------------------------------------------------------------
// Stable ID: aa_0047dc00
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
// Address:   0x0047dc00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, return×1.
//  - Notable callees: FUN_0047dc00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0047dc00(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint16_t *puVar1;

  int iVar2;

  

  *(int *)(param_2 + 0xb10) = param_2 + 0x8c;

  *(int *)(param_2 + 0xb28) = param_2 + 0xa74;

  *(undefined ***)(param_2 + 0xb18) = &PTR_DAT_00afa968;

  *(int *)(param_2 + 0xb1c) = param_2 + 0x980;

  *(undefined ***)(param_2 + 0xb24) = &PTR_DAT_00afa97c;

  *(undefined **)(param_2 + 0xb30) = &DAT_00afa990;

  *(uint16_t *)(param_2 + 0x16b0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x16b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x16ac) = 8;

  puVar1 = (uint16_t *)(param_2 + 0x8c);

  iVar2 = 0x11e;

  do {

    *puVar1 = 0;

    puVar1 = puVar1 + 2;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  puVar1 = (uint16_t *)(param_2 + 0x980);

  iVar2 = 0x1e;

  do {

    *puVar1 = 0;

    puVar1 = puVar1 + 2;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  puVar1 = (uint16_t *)(param_2 + 0xa74);

  iVar2 = 0x13;

  do {

    *puVar1 = 0;

    puVar1 = puVar1 + 2;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x16a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x16a0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x16a8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x1698) = 0;

  *(uint16_t *)(param_2 + 0x48c) = 1;

  return;

}
