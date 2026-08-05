// =============================================================================
// FUN_00711550
// -----------------------------------------------------------------------------
// Stable ID: aa_00711550
// Address:   0x00711550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00711550 @ 0x00711550
// Stable ID: aa_00711550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: return×9, if×8.
//  - Notable callees: FUN_00711550, FUN_00713740, FUN_00713ad0, FUN_00713b20, FUN_00713e10, FUN_00714310.
//  - Return sites: 9.

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

uint32_t /* width from decompiler */ FUN_00711550(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  short sVar1;

  int iVar2;

  int iVar3;

  

  if (param_1 == (int *)0x0) {

    return 1;

  }

  *param_1 = 0;

  iVar2 = (*(code *)PTR_calloc_00af8a48)(1,0x58);

  if (iVar2 == 0) {

    return 1;

  }

  *param_1 = iVar2;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x40) = param_2;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x44) = 1;

  iVar3 = (*(code *)PTR_calloc_00af8a48)(1,0x2c);

  *(int *)(iVar2 + 0x48) = iVar3;

  if (iVar3 == 0) {

    return 1;

  }

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10) = 0;

  *(uint16_t *)(iVar3 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x18) = 0x3f800000;

  *(uint16_t *)(iVar3 + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28) = 0x3f800000;

  iVar3 = FUN_00713740(0x173,iVar2);

  if (iVar3 != 0) {

    return 1;

  }

  sVar1 = FUN_00714310(iVar2 + 4,0x3f7d70a4);

  if (sVar1 != 0) {

    return 1;

  }

  *(uint32_t /* width from decompiler */ *)(iVar2 + 8) = 0;

  sVar1 = FUN_00713e10(iVar2 + 0x10);

  if (sVar1 != 0) {

    return 1;

  }

  sVar1 = FUN_00713b20(iVar2 + 0x14);

  if (sVar1 != 0) {

    return 1;

  }

  sVar1 = FUN_00713ad0(iVar2 + 0x18);

  if (sVar1 != 0) {

    return 1;

  }

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x20) = 1;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x28) = 1;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x34) = 0x42c80000;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x3c) = 0x42c80000;

  return 0;

}
