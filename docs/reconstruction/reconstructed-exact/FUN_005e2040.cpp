// =============================================================================
// FUN_005e2040
// -----------------------------------------------------------------------------
// Stable ID: aa_005e2040
// Address:   0x005e2040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e2040 @ 0x005e2040
// Stable ID: aa_005e2040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_009733d0×2, FUN_005e2040, thunk_FUN_005a6840.
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

void __thiscall FUN_005e2040(int param_1,int *param_2,int param_3)



{

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ auStack_c [2];

  uint32_t /* width from decompiler */ uStack_4;

  

  thunk_FUN_005a6840(param_2,param_3);

  (**(code **)(*param_2 + 0x14))(param_1 + 0x170,4);

  uStack_4 = 0xffffffff;

  if (0xb < param_3) {

    (**(code **)(*param_2 + 0x14))(&stack0x00000000,4);

    (**(code **)(*param_2 + 0x14))(auStack_c,4);

  }

  FUN_009733d0(&stack0xffffffe4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x174) = unaff_EBX;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = uStack_14;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) = uStack_10;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = auStack_c[0];

  FUN_009733d0(&stack0xffffffe4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x184) = unaff_EBX;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x188) = uStack_14;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18c) = uStack_10;

  *(uint32_t /* width from decompiler */ *)(param_1 + 400) = auStack_c[0];

  return;

}
