// =============================================================================
// FUN_00713bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00713bd0
// Address:   0x00713bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713bd0 @ 0x00713bd0
// Stable ID: aa_00713bd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: while×2, if×1, return×1.
//  - Notable callees: FUN_00713bd0, FUN_00713d50, FUN_00713e60, FUN_00713ec0, FUN_00713f30, FUN_00713f50, FUN_00714520, FUN_00714590.
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

float10 FUN_00713bd0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  float10 fVar4;

  int local_260;

  float local_25c;

  float local_258;

  int local_254;

  uint32_t /* width from decompiler */ local_250;

  float local_24c [6];

  float local_234 [3];

  float local_228 [92];

  uint8_t local_b8 [184];

  

  FUN_00714520(param_1,param_2,0x5c,local_24c + 9);

  FUN_00714590(local_24c + 9,0x5c,&local_260,&local_25c);

  iVar1 = FUN_00713e60(local_24c + 9,0x56);

  FUN_00713f50(local_24c + 9,iVar1,local_b8,&local_250,local_25c);

  iVar2 = iVar1;

  if (g_flZero < local_25c) {

    local_25c = g_flOne / local_25c;

  }

  while (local_260 = iVar2 + -1, -1 < local_260) {

    local_258 = local_25c * local_24c[iVar2 + 8];

    local_24c[iVar2 + 8] = local_258;

    fVar4 = (float10)FUN_00713d50(local_258);

    local_24c[local_260 + 9] = (float)fVar4;

    iVar2 = local_260;

  }

  iVar2 = FUN_007168f0(local_24c + 9,iVar1,local_b8,local_250,local_24c,local_24c + 3,*param_3,

                       param_3[1],&local_254);

  uVar3 = FUN_007168c0(iVar1,local_24c[iVar2 + -1]);

  local_260 = iVar2;

  while (local_260 = local_260 + -1, -1 < local_260) {

    fVar4 = (float10)FUN_00716710(local_24c[local_260],param_1,param_2,uVar3);

    local_24c[local_260 + 6] = (float)fVar4;

  }

  local_254 = FUN_00713ec0(local_24c + 6,iVar2,local_254);

  local_258 = local_24c[local_254];

  FUN_00713f30(param_3,local_258,local_24c[local_254 + 3]);

  return (float10)local_258;

}
