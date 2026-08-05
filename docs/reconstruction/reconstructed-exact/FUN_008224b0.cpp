// =============================================================================
// FUN_008224b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008224b0
// Address:   0x008224b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008224b0 @ 0x008224b0
// Stable ID: aa_008224b0
// Embedded strings (evidence for future rename):
//   - "RecvServerListEx\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: block×4, FUN_00417190, FUN_00417720, FUN_004433a0, FUN_007fc360, FUN_008224b0, FUN_008cb130, FUN_009133a0.
//  - Strings: "RecvServerListEx\n".
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

/* WARNING: Removing unreachable block (ram,0x008225dc) */

/* WARNING: Removing unreachable block (ram,0x008225ea) */

/* WARNING: Removing unreachable block (ram,0x0082259c) */

/* WARNING: Removing unreachable block (ram,0x00822686) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_008224b0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1d11;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  OutputDebugStringA("RecvServerListEx\n");

  *(uint8_t *)(param_1 + 0x4a) = 3;

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

  if (*(int *)(param_1 + 0x5c) != *(int *)(param_1 + 0x60)) {

    uVar3 = FUN_004433a0(param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = uVar3;

  }

  FUN_00417720(*(uint32_t /* width from decompiler */ *)(param_1 + 0x5c),uVar2,uVar1,param_2);

  local_4 = 0;

  iVar4 = 0;

  for (uVar5 = 0;

      (*(int *)(param_1 + 0x5c) != 0 &&

      (uVar5 < (uint)((*(int *)(param_1 + 0x60) - *(int *)(param_1 + 0x5c)) / 0x14)));

      uVar5 = uVar5 + 1) {

    if (*(short *)(*(int *)(param_1 + 0x5c) + 0x10 + iVar4) != 0) {

      FUN_00417190();

    }

    iVar4 = iVar4 + 0x14;

  }

  FUN_00937560(&DAT_00d1a840);

  DAT_00d1a980 = 0;

  FUN_007fc360();

  FUN_009133a0(1);

  FUN_008cb130(*(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0xa78),param_1 + 0x58);

  ExceptionList = local_c;

  return;

}
