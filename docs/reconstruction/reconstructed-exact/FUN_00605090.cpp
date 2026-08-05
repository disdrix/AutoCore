// =============================================================================
// FUN_00605090
// -----------------------------------------------------------------------------
// Stable ID: aa_00605090
// Address:   0x00605090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00605090 @ 0x00605090
// Stable ID: aa_00605090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00403450×4, block×3, FUN_00604e90, FUN_00604f10, FUN_00604f90, FUN_00605010, FUN_00605090, free.
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

/* WARNING: Removing unreachable block (ram,0x00605160) */

/* WARNING: Removing unreachable block (ram,0x0060510c) */

/* WARNING: Removing unreachable block (ram,0x006051b4) */



uint32_t /* width from decompiler */ __thiscall

FUN_00605090(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

            uint32_t /* width from decompiler */ param_9)



{

  uint32_t /* width from decompiler */ uVar1;

  uint8_t local_110 [128];

  uint8_t *puStack_90;

  uint8_t auStack_8c [128];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a805c;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = param_2;

  uVar1 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(param_3,uVar1);

  uStack_4 = 0;

  FUN_00604e90(local_110);

  uStack_4 = 0xffffffff;

  uVar1 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(param_4,uVar1);

  uStack_4 = 1;

  FUN_00604f10(local_110);

  uStack_4 = 0xffffffff;

  uVar1 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(param_7,uVar1);

  uStack_4 = 2;

  FUN_00604f90(local_110);

  uStack_4 = 0xffffffff;

  puStack_90 = auStack_8c;

  uVar1 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(param_6,uVar1);

  uStack_4 = 3;

  FUN_00605010(puStack_90);

  if (puStack_90 != auStack_8c) {

    free(puStack_90);

  }

  param_1[6] = param_9;

  param_1[5] = param_8;

  ExceptionList = pvStack_c;

  return 1;

}
