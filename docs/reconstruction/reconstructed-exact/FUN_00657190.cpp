// =============================================================================
// FUN_00657190
// -----------------------------------------------------------------------------
// Stable ID: aa_00657190
// Address:   0x00657190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00657190 @ 0x00657190
// Stable ID: aa_00657190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×11, return×1.
//  - Notable callees: FUN_005b3300×5, FUN_00656c70, FUN_00657190.
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

void __fastcall FUN_00657190(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  puVar3 = operator_new(0x18);

  puVar7 = (uint32_t /* width from decompiler */ *)0x0;

  if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar3 = 0;

    puVar3[1] = 0;

    puVar3[2] = 0x80000000;

    puVar3[3] = 0;

    puVar3[4] = 0;

    puVar3[5] = 0x80000000;

    puVar7 = puVar3;

  }

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x50) = puVar7;

  if ((puVar7[2] & 0x7fffffff) < 5) {

    iVar4 = (puVar7[2] & 0x7fffffff) * 2;

    if (iVar4 < 6) {

      iVar4 = 5;

    }

    FUN_005b3300(puVar7,iVar4,0x10);

  }

  puVar7[1] = 5;

  iVar4 = **(int **)(param_1 + 0x50);

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0x40) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0x44) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0x48) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0x4c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c);

  FUN_00656c70(**(uint32_t /* width from decompiler */ **)(param_1 + 0x50));

  iVar1 = *(int *)(param_1 + 0x50);

  iVar2 = *(int *)(iVar1 + 0x10);

  iVar4 = iVar2 + 1;

  uVar5 = *(uint *)(iVar1 + 0x14) & 0x7fffffff;

  if ((int)uVar5 < iVar4) {

    iVar6 = uVar5 * 2;

    if (iVar6 <= iVar4) {

      iVar6 = iVar4;

    }

    FUN_005b3300((int *)(iVar1 + 0xc),iVar6,0xc);

  }

  *(int *)(iVar1 + 0x10) = iVar4;

  puVar7 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0xc) + iVar2 * 0xc);

  *puVar7 = 2;

  puVar7[1] = 4;

  puVar7[2] = 3;

  iVar1 = *(int *)(param_1 + 0x50);

  iVar2 = *(int *)(iVar1 + 0x10);

  iVar4 = iVar2 + 1;

  uVar5 = *(uint *)(iVar1 + 0x14) & 0x7fffffff;

  if ((int)uVar5 < iVar4) {

    iVar6 = uVar5 * 2;

    if (iVar6 <= iVar4) {

      iVar6 = iVar4;

    }

    FUN_005b3300((int *)(iVar1 + 0xc),iVar6,0xc);

  }

  *(int *)(iVar1 + 0x10) = iVar4;

  puVar7 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0xc) + iVar2 * 0xc);

  *puVar7 = 0;

  puVar7[1] = 4;

  puVar7[2] = 2;

  iVar1 = *(int *)(param_1 + 0x50);

  iVar2 = *(int *)(iVar1 + 0x10);

  iVar4 = iVar2 + 1;

  uVar5 = *(uint *)(iVar1 + 0x14) & 0x7fffffff;

  if ((int)uVar5 < iVar4) {

    iVar6 = uVar5 * 2;

    if (iVar6 <= iVar4) {

      iVar6 = iVar4;

    }

    FUN_005b3300((int *)(iVar1 + 0xc),iVar6,0xc);

  }

  *(int *)(iVar1 + 0x10) = iVar4;

  puVar7 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0xc) + iVar2 * 0xc);

  *puVar7 = 1;

  puVar7[1] = 4;

  puVar7[2] = 0;

  iVar1 = *(int *)(param_1 + 0x50);

  iVar2 = *(int *)(iVar1 + 0x10);

  iVar4 = iVar2 + 1;

  uVar5 = *(uint *)(iVar1 + 0x14) & 0x7fffffff;

  if ((int)uVar5 < iVar4) {

    iVar6 = uVar5 * 2;

    if (iVar6 <= iVar4) {

      iVar6 = iVar4;

    }

    FUN_005b3300((int *)(iVar1 + 0xc),iVar6,0xc);

  }

  *(int *)(iVar1 + 0x10) = iVar4;

  puVar7 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0xc) + iVar2 * 0xc);

  *puVar7 = 3;

  puVar7[1] = 4;

  puVar7[2] = 1;

  return;

}
