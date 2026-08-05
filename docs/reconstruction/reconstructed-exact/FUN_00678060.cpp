// =============================================================================
// FUN_00678060
// -----------------------------------------------------------------------------
// Stable ID: aa_00678060
// Address:   0x00678060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00678060 @ 0x00678060
// Stable ID: aa_00678060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00702f90×9, FUN_00702880×2, FUN_00702fa0×2, FUN_00678060, FUN_006799a0, FUN_00702930, FUN_00702f30, FUN_00702f40.
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

/* WARNING: Type propagation algorithm not settling */



void __thiscall FUN_00678060(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint param_4)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint local_8 [2];

  

  uVar2 = param_4;

  local_8[0] = param_4 & 0xff;

  param_2 = 0x1900;

  local_c = 1;

  local_8[1] = 1;

  local_10 = 8000;

  FUN_00702880(param_1 + 0x2c);

  FUN_00702880(param_1 + 0x50);

  if (*(int *)(param_1 + 4) == 0) {

    uVar3 = FUN_00702f30(&PTR_DAT_00af5d8c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = uVar3;

    FUN_00702f90(uVar3,0x18,&local_10);

    FUN_00702f90(*(uint32_t /* width from decompiler */ *)(param_1 + 0x74),0x12,&param_2);

    FUN_00702f90(*(uint32_t /* width from decompiler */ *)(param_1 + 0x74),0xc,&local_c);

    FUN_00702f90(*(uint32_t /* width from decompiler */ *)(param_1 + 0x74),0x1e,local_8);

    FUN_00702f90(*(uint32_t /* width from decompiler */ *)(param_1 + 0x74),0x22,local_8 + 1);

    FUN_00702f90(*(uint32_t /* width from decompiler */ *)(param_1 + 0x74),3,param_1 + 0xc);

    param_4 = 0;

    FUN_00702f90(*(uint32_t /* width from decompiler */ *)(param_1 + 0x74),0xf,&param_4);

    param_4 = DAT_00a110d8;

    FUN_00702f90(*(uint32_t /* width from decompiler */ *)(param_1 + 0x74),0xe,&param_4);

    FUN_00702f90(*(uint32_t /* width from decompiler */ *)(param_1 + 0x74),0xf,&param_4);

  }

  else if (*(int *)(param_1 + 4) == 1) {

    uVar3 = FUN_00702f40(&PTR_DAT_00af5d8c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = uVar3;

    FUN_00702fa0(uVar3,0x18,&local_10);

    FUN_00702fa0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x78),3,param_1 + 0xc);

  }

  iVar1 = *(int *)(param_1 + 0xc);

  *(int *)(param_1 + 0xc) = iVar1 * 2;

  pvVar4 = operator_new__(iVar1 * 8);

  *(void **)(param_1 + 0x7c) = pvVar4;

  pvVar4 = operator_new__(*(int *)(param_1 + 0xc) * 4);

  *(void **)(param_1 + 0x80) = pvVar4;

  pvVar4 = operator_new__(*(uint *)(param_1 + 0xc));

  *(void **)(param_1 + 0x84) = pvVar4;

  FUN_00702930(param_1 + 0x2c);

  FUN_006799a0(param_2,1,uVar2,0x3e,8000,0x10,5);

  return;

}
