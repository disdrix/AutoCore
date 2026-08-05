// =============================================================================
// FUN_0040a380
// -----------------------------------------------------------------------------
// Stable ID: aa_0040a380
// Address:   0x0040a380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040a380 @ 0x0040a380
// Stable ID: aa_0040a380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0040a380, FUN_0040a8f0.
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

void FUN_0040a380(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  for (param_2 = param_2 - (int)param_1; 1 < param_2 >> 4; param_2 = param_2 + -0x10) {

    puVar1 = (uint32_t /* width from decompiler */ *)((int)param_1 + param_2 + -0x10);

    uVar2 = *puVar1;

    uVar3 = puVar1[1];

    uVar4 = puVar1[2];

    uVar5 = puVar1[3];

    *puVar1 = *param_1;

    puVar1[1] = param_1[1];

    puVar1[2] = param_1[2];

    puVar1[3] = param_1[3];

    FUN_0040a8f0(param_1,param_2 + -0x10 >> 4,uVar2,uVar3,uVar4,uVar5,param_3);

  }

  return;

}
