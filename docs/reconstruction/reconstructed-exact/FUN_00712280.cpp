// =============================================================================
// FUN_00712280
// -----------------------------------------------------------------------------
// Stable ID: aa_00712280
// Address:   0x00712280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712280 @ 0x00712280
// Stable ID: aa_00712280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: return×10, if×9.
//  - Notable callees: FUN_00712280, FUN_007166a0.
//  - Return sites: 10.

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

uint32_t /* width from decompiler */ FUN_00712280(int *param_1)



{

  int iVar1;

  int iVar2;

  

  if (param_1 == (int *)0x0) {

    return 1;

  }

  *param_1 = 0;

  iVar1 = (*(code *)PTR_calloc_00af8a48)(1,0x6c);

  if (iVar1 == 0) {

    return 1;

  }

  *param_1 = iVar1;

  iVar2 = (*(code *)PTR_calloc_00af8a48)(0x284,4);

  *(int *)(iVar1 + 4) = iVar2;

  if (iVar2 == 0) {

    return 1;

  }

  iVar2 = (*(code *)PTR_calloc_00af8a48)(0x50,4);

  *(int *)(iVar1 + 8) = iVar2;

  if (iVar2 == 0) {

    return 1;

  }

  iVar2 = FUN_007166a0(iVar1);

  if (iVar2 != 0) {

    return 1;

  }

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x24) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x2c) = 0x3f800000;

  *(uint16_t *)(iVar1 + 0x30) = 0;

  *(uint16_t *)(iVar1 + 0x32) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x38) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x3c) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x40) = 0x3f800000;

  *(uint16_t *)(iVar1 + 0x54) = 1;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x44) = 0x42a00000;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x60) = 1;

  *(uint16_t *)(iVar1 + 0x56) = 0;

  *(uint16_t *)(iVar1 + 0x58) = 100;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x5c) = 1;

  iVar2 = (*(code *)PTR_calloc_00af8a48)(0x41,4);

  *(int *)(iVar1 + 0xc) = iVar2;

  if (iVar2 == 0) {

    return 1;

  }

  iVar2 = (*(code *)PTR_calloc_00af8a48)(0x41,4);

  *(int *)(iVar1 + 0x10) = iVar2;

  if (iVar2 == 0) {

    return 1;

  }

  iVar2 = (*(code *)PTR_calloc_00af8a48)(0x66,4);

  *(int *)(iVar1 + 0x14) = iVar2;

  if (iVar2 == 0) {

    return 1;

  }

  iVar2 = (*(code *)PTR_calloc_00af8a48)(0x66,4);

  *(int *)(iVar1 + 0x18) = iVar2;

  if (iVar2 == 0) {

    return 1;

  }

  *(uint32_t /* width from decompiler */ *)(iVar1 + 100) = 0x42c80000;

  return 0;

}
