// =============================================================================
// FUN_0086cea0
// -----------------------------------------------------------------------------
// Stable ID: aa_0086cea0
// Address:   0x0086cea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0086cea0 @ 0x0086cea0
// Stable ID: aa_0086cea0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0086cea0.
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

void __fastcall FUN_0086cea0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  float fVar2;

  

  fVar2 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x504) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x560) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x564) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x568) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x56c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x570) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x574) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x578) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x57c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x580) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x584) = 0;

  uVar1 = DAT_00a0f298;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x510) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x514) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x518) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x51c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x588) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x59c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x590) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x594) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x598) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5ac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x528) = 0xffffffff;

  *(float *)(param_1 + 0x540) = fVar2;

  *(float *)(param_1 + 0x544) = fVar2;

  *(float *)(param_1 + 0x548) = fVar2;

  *(float *)(param_1 + 0x54c) = fVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x530) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x534) = uVar1;

  *(float *)(param_1 + 0x538) = fVar2;

  *(float *)(param_1 + 0x53c) = fVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x550) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x554) = 0;

  *(float *)(param_1 + 0x558) = fVar2;

  *(float *)(param_1 + 0x55c) = fVar2;

  return;

}
