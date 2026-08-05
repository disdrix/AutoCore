// =============================================================================
// FUN_008ab0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ab0a0
// Address:   0x008ab0a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ab0a0 @ 0x008ab0a0
// Stable ID: aa_008ab0a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_008ab0a0.
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

void __fastcall FUN_008ab0a0(int param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x504) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x680) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x684) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x688) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x690) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x694) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6d8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6dc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6e0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6e4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6e8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x700) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6ec) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6f0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6f4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6f8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6fc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x644) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x558) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x55c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6a8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x698) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x560) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x564) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6ac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6cc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x69c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x568) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x56c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6b0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6d0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6a0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x570) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x574) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6d4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x510) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x518) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x51c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x708) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x520) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x524) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x528) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x52c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x710) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x530) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x534) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x714) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x538) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x53c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x718) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x540) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x544) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x71c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x548) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x720) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x550) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x554) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x724) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x578) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x57c) = 0xffffffff;

  uVar3 = DAT_00aaa7e8;

  uVar2 = DAT_00a0f71c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x594) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x598) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x59c) = 0;

  fVar1 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a0) = uVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x584) = 0;

  *(float *)(param_1 + 0x588) = fVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x590) = uVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a4) = 0;

  *(float *)(param_1 + 0x5a8) = fVar1;

  uVar2 = DAT_00aaa7e4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5ac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5b0) = uVar2;

  *(uint8_t *)(param_1 + 0x64c) = 0;

  return;

}
