// =============================================================================
// FUN_00798720
// -----------------------------------------------------------------------------
// Stable ID: aa_00798720
// Address:   0x00798720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00798720 @ 0x00798720
// Stable ID: aa_00798720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00427530, FUN_00798590, FUN_00798720, block.
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

/* WARNING: Removing unreachable block (ram,0x007987ab) */



void FUN_00798720(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6)



{

  uint32_t /* width from decompiler */ uVar1;

  uint8_t local_80c [2048];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b27bb;

  local_c = ExceptionList;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    uVar1 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00427530(uVar1);

    uStack_4 = 0;

    FUN_00798590(param_1,local_80c,param_3,param_4,param_6);

  }

  ExceptionList = local_c;

  return;

}
