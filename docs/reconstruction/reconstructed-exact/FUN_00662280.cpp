// =============================================================================
// FUN_00662280
// -----------------------------------------------------------------------------
// Stable ID: aa_00662280
// Address:   0x00662280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00662280 @ 0x00662280
// Stable ID: aa_00662280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0066e030×6, FUN_00662140×3, FUN_00662280.
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

void __thiscall FUN_00662280(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

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

  

  uVar2 = FUN_00662140(0x3f800000,0x3f800000,0,0x3f800000);

  uVar3 = FUN_00662140(0x3f800000,0x3f000000,0,0x3f800000);

  uVar4 = FUN_00662140(0x3f800000,0,0x3f800000,0x3f800000);

  local_60 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

  local_5c = *(uint32_t /* width from decompiler */ *)(param_1 + 100);

  local_58 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

  local_54 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c);

  local_70 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

  local_6c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

  local_68 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

  local_64 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c);

  local_50 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x80);

  local_4c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x84);

  local_48 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x88);

  local_44 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c);

  local_30 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x90);

  local_2c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x94);

  local_28 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x98);

  local_24 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c);

  local_40 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0);

  local_3c = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4);

  local_38 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8);

  local_34 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xac);

  local_20 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0);

  local_1c = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4);

  local_18 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8);

  local_14 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc);

  FUN_0066e030(param_1 + 0x20,&local_60,&local_70,0xffff0000,*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),param_2)

  ;

  FUN_0066e030(param_1 + 0x20,&local_70,&local_50,0xff00ff00,*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),param_2)

  ;

  FUN_0066e030(param_1 + 0x20,&local_50,&local_60,0xff0000ff,*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),param_2)

  ;

  iVar1 = param_1 + 0x30;

  FUN_0066e030(iVar1,&local_30,&local_40,uVar2,*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),param_2);

  FUN_0066e030(iVar1,&local_40,&local_20,uVar3,*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),param_2);

  FUN_0066e030(iVar1,&local_20,&local_30,uVar4,*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),param_2);

  return;

}
