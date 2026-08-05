// =============================================================================
// FUN_008a8040
// -----------------------------------------------------------------------------
// Stable ID: aa_008a8040
// Address:   0x008a8040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a8040 @ 0x008a8040
// Stable ID: aa_008a8040
// Embedded strings (evidence for future rename):
//   - "Return to"
//   - "%s %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007a6de0×2, FUN_00403450, FUN_007a69d0, FUN_008a8040, _snprintf, block.
//  - Strings: "Return to"; "%s %s".
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

/* WARNING: Removing unreachable block (ram,0x008a80df) */



void FUN_008a8040(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_EDI;

  uint8_t local_18c [128];

  char acStack_10c [256];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009abca4;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_007a69d0();

  uVar1 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(param_1,uVar1);

  uStack_4 = 0;

  uVar1 = FUN_007a6de0(local_18c,0xffffffff);

  uVar2 = FUN_007a6de0("Return to",0xffffffff);

  _snprintf(acStack_10c,0x100,"%s %s",uVar2,uVar1);

  uStack_4 = 0xffffffff;

  if (*(int *)(unaff_EDI + 0x688) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x688) + 0x1d8))(acStack_10c,1,1);

    (**(code **)(**(int **)(unaff_EDI + 0x688) + 0x34c))();

  }

  ExceptionList = pvStack_c;

  return;

}
