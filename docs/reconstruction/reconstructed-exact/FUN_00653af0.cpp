// =============================================================================
// FUN_00653af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00653af0
// Address:   0x00653af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00653af0 @ 0x00653af0
// Stable ID: aa_00653af0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0063f620, FUN_006523b0, FUN_00653af0, FUN_00654e60, FUN_006644e0.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00653af0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  ulonglong uVar3;

  

  FUN_006523b0();

  param_1[5] = &PTR_LAB_009db1e0;

  *param_1 = &PTR_FUN_009e5cd4;

  param_1[2] = &PTR_LAB_009e5ccc;

  param_1[5] = &PTR_LAB_009e5cc4;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x28,0x16);

  if (iVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_006644e0(1000000);

  }

  param_1[6] = uVar2;

  uVar3 = FUN_0063f620();

  *(float *)(param_1[6] + 0x18) =

       (float)((float10)g_flOne /

              (-(float10)(longlong)((uVar3 >> 0x20 & 0x80000000) << 0x20) +

              (float10)(uVar3 & 0x7fffffffffffffff)));

  *(uint32_t /* width from decompiler */ *)(param_1[6] + 0x1c) = 0;

  FUN_00654e60(param_1 + 5);

  return param_1;

}
