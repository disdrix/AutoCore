// =============================================================================
// FUN_00760c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00760c60
// Address:   0x00760c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00760c60 @ 0x00760c60
// Stable ID: aa_00760c60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00760830, FUN_00760c60, block.
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

/* WARNING: Removing unreachable block (ram,0x00760d37) */



uint32_t /* width from decompiler */ * __thiscall FUN_00760c60(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b0a3d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  puVar3 = operator_new(0x20);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar3[1] = param_2;

    uVar2 = DAT_00aaa688;

    *puVar3 = &PTR_FUN_00a9dcf4;

    puVar3[3] = 0;

    puVar3[4] = 0;

    puVar3[5] = 0;

    puVar3[6] = 0;

    puVar3[7] = uVar2;

  }

  local_4 = 0xffffffff;

  puVar3[7] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

  if (*(int *)(param_1 + 0xc) == 0) {

    iVar4 = 0;

  }

  else {

    iVar4 = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28;

  }

  FUN_00760830(iVar4);

  iVar4 = *(int *)(param_1 + 0xc);

  iVar1 = *(int *)(param_1 + 0x10);

  if (iVar4 != iVar1) {

    puVar5 = (uint32_t /* width from decompiler */ *)(puVar3[3] + 0x24);

    do {

      puVar5[-1] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x20);

      *puVar5 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x24);

      iVar4 = iVar4 + 0x28;

      puVar5 = puVar5 + 10;

    } while (iVar4 != iVar1);

  }

  if (puVar3[3] == 0) {

    iVar4 = 0;

  }

  else {

    iVar4 = (int)(puVar3[4] - puVar3[3]) / 0x28;

  }

  puVar3[6] = iVar4 + -1;

  ExceptionList = local_c;

  return puVar3;

}
