// =============================================================================
// FUN_00656f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00656f40
// Address:   0x00656f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00656f40 @ 0x00656f40
// Stable ID: aa_00656f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005b3300, FUN_00656c70, FUN_00656f40.
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

void FUN_00656f40(int *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  uVar2 = param_1[2] & 0x7fffffff;

  if (uVar2 < 0xc) {

    iVar3 = uVar2 * 2;

    if (uVar2 == 6 || iVar3 < 0xc) {

      iVar3 = 0xc;

    }

    FUN_005b3300(param_1,iVar3,0x10);

  }

  param_1[1] = 0xc;

  FUN_00656c70(&local_50);

  puVar1 = (uint32_t /* width from decompiler */ *)*param_1;

  *puVar1 = local_50;

  puVar1[1] = local_4c;

  puVar1[2] = local_48;

  puVar1[3] = local_44;

  iVar3 = *param_1;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x1c) = local_34;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10) = local_40;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x14) = local_3c;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x18) = local_38;

  iVar3 = *param_1;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x2c) = local_34;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20) = local_40;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24) = local_3c;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28) = local_38;

  iVar3 = *param_1;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x30) = local_30;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x34) = local_2c;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x38) = local_28;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x3c) = local_24;

  iVar3 = *param_1;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x40) = local_30;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x44) = local_2c;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x48) = local_28;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x4c) = local_24;

  iVar3 = *param_1;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x50) = local_20;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x54) = local_1c;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x58) = local_18;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x5c) = local_14;

  iVar3 = *param_1;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x60) = local_20;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 100) = local_1c;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x68) = local_18;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x6c) = local_14;

  iVar3 = *param_1;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x70) = local_50;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x74) = local_4c;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x78) = local_48;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x7c) = local_44;

  iVar3 = *param_1;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x80) = local_50;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x84) = local_4c;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x88) = local_48;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8c) = local_44;

  iVar3 = *param_1;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x90) = local_30;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x94) = local_2c;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x98) = local_28;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x9c) = local_24;

  iVar3 = *param_1;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xac) = local_34;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xa0) = local_40;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xa4) = local_3c;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xa8) = local_38;

  iVar3 = *param_1;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xb0) = local_20;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xb4) = local_1c;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xb8) = local_18;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc) = local_14;

  return;

}
