// =============================================================================
// FUN_009832d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009832d0
// Address:   0x009832d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009832d0 @ 0x009832d0
// Stable ID: aa_009832d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00982100, FUN_009832d0.
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

void __fastcall

FUN_009832d0(uint32_t /* width from decompiler */ *param_1,int param_2,float param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *in_EAX;

  float in_XMM0_Da;

  float fVar2;

  float fVar3;

  

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = *param_1;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = param_1[1];

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c) = param_1[2];

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x20) = *in_EAX;

  fVar2 = in_XMM0_Da * DAT_00a0f720;

  fVar3 = in_XMM0_Da * DAT_00a0f71c;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x24) = in_EAX[1];

  uVar1 = in_EAX[2];

  *(float *)(param_2 + 0x38) = fVar2;

  *(float *)(param_2 + 0x34) = fVar3;

  fVar2 = param_3 * DAT_00a0f298;

  *(float *)(param_2 + 0x30) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x28) = uVar1;

  *(float *)(param_2 + 0x2c) = fVar2;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c) = param_5;

  FUN_00982100(param_4);

  return;

}
