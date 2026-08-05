// =============================================================================
// FUN_00807490
// -----------------------------------------------------------------------------
// Stable ID: aa_00807490
// Address:   0x00807490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00807490 @ 0x00807490
// Stable ID: aa_00807490
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005a1f50, FUN_00807490, FUN_0092dcc0.
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

uint32_t /* width from decompiler */ __thiscall FUN_00807490(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_ESI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ac486;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xc7c) != (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = &pvStack_c;

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xc7c))(1,param_1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc7c) = 0;

  pvVar1 = operator_new(200);

  uStack_4 = 0;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_005a1f50(unaff_ESI + 0xcc8,param_2,param_3,0,1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x508),

                         *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x50c),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x134),0xaf,

                         0);

  }

  uStack_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc7c) = uVar2;

  FUN_0092dcc0(&DAT_00d1a840);

  ExceptionList = pvStack_c;

  return 0;

}
