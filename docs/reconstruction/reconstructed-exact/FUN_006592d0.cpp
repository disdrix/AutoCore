// =============================================================================
// FUN_006592d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006592d0
// Address:   0x006592d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006592d0 @ 0x006592d0
// Stable ID: aa_006592d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~147 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1.
//  - Notable callees: FUN_005b3300×2, FUN_006592d0.
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

void __thiscall FUN_006592d0(int param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  int local_8;

  

  iVar1 = *(int *)(param_1 + 0xc);

  if ((int)(param_2[2] & 0x7fffffffU) < iVar1) {

    iVar7 = (param_2[2] & 0x7fffffffU) * 2;

    if (iVar7 <= iVar1) {

      iVar7 = iVar1;

    }

    FUN_005b3300(param_2,iVar7,0x40);

  }

  param_2[1] = iVar1;

  piVar6 = param_2 + 3;

  if ((int)(param_2[5] & 0x7fffffffU) < iVar1) {

    iVar7 = (param_2[5] & 0x7fffffffU) * 2;

    if (iVar7 <= iVar1) {

      iVar7 = iVar1;

    }

    FUN_005b3300(piVar6,iVar7,4);

  }

  iVar7 = 0;

  param_2[4] = iVar1;

  if (3 < iVar1) {

    iVar4 = 0;

    local_8 = 0;

    do {

      iVar5 = *(int *)(param_1 + 8) + 0x10 + iVar4;

      puVar2 = (uint32_t /* width from decompiler */ *)(*param_2 + local_8);

      *puVar2 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0x10 + iVar4);

      puVar2[1] = *(uint32_t /* width from decompiler */ *)(iVar5 + 4);

      puVar2[2] = *(uint32_t /* width from decompiler */ *)(iVar5 + 8);

      puVar2[3] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc);

      puVar2[4] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10);

      puVar2[5] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x14);

      puVar2[6] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x18);

      puVar2[7] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x1c);

      puVar2[8] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x20);

      puVar2[9] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x24);

      puVar2[10] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x28);

      puVar2[0xb] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x2c);

      puVar2[0xc] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x30);

      puVar2[0xd] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x34);

      puVar2[0xe] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x38);

      puVar2[0xf] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x3c);

      *(uint32_t /* width from decompiler */ *)(*piVar6 + iVar7 * 4) = *(uint32_t /* width from decompiler */ *)(iVar4 + *(int *)(param_1 + 8));

      puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0x60 + iVar4);

      puVar3 = (uint32_t /* width from decompiler */ *)(*param_2 + 0x40 + local_8);

      *puVar3 = *puVar2;

      puVar3[1] = puVar2[1];

      puVar3[2] = puVar2[2];

      puVar3[3] = puVar2[3];

      puVar3[4] = puVar2[4];

      puVar3[5] = puVar2[5];

      puVar3[6] = puVar2[6];

      puVar3[7] = puVar2[7];

      puVar3[8] = puVar2[8];

      puVar3[9] = puVar2[9];

      puVar3[10] = puVar2[10];

      puVar3[0xb] = puVar2[0xb];

      puVar3[0xc] = puVar2[0xc];

      puVar3[0xd] = puVar2[0xd];

      puVar3[0xe] = puVar2[0xe];

      puVar3[0xf] = puVar2[0xf];

      *(uint32_t /* width from decompiler */ *)(*piVar6 + 4 + iVar7 * 4) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0x50 + iVar4);

      puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0xb0 + iVar4);

      puVar2 = (uint32_t /* width from decompiler */ *)(local_8 + 0x80 + *param_2);

      *puVar2 = *puVar3;

      puVar2[1] = puVar3[1];

      puVar2[2] = puVar3[2];

      puVar2[3] = puVar3[3];

      puVar2[4] = puVar3[4];

      puVar2[5] = puVar3[5];

      puVar2[6] = puVar3[6];

      puVar2[7] = puVar3[7];

      puVar2[8] = puVar3[8];

      puVar2[9] = puVar3[9];

      puVar2[10] = puVar3[10];

      puVar2[0xb] = puVar3[0xb];

      puVar2[0xc] = puVar3[0xc];

      puVar2[0xd] = puVar3[0xd];

      puVar2[0xe] = puVar3[0xe];

      puVar2[0xf] = puVar3[0xf];

      *(uint32_t /* width from decompiler */ *)(*piVar6 + 8 + iVar7 * 4) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0xa0 + iVar4);

      puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0x100 + iVar4);

      puVar3 = (uint32_t /* width from decompiler */ *)(*param_2 + local_8 + 0xc0);

      *puVar3 = *puVar2;

      puVar3[1] = puVar2[1];

      puVar3[2] = puVar2[2];

      puVar3[3] = puVar2[3];

      puVar3[4] = puVar2[4];

      puVar3[5] = puVar2[5];

      puVar3[6] = puVar2[6];

      puVar3[7] = puVar2[7];

      puVar3[8] = puVar2[8];

      puVar3[9] = puVar2[9];

      puVar3[10] = puVar2[10];

      puVar3[0xb] = puVar2[0xb];

      puVar3[0xc] = puVar2[0xc];

      puVar3[0xd] = puVar2[0xd];

      local_8 = local_8 + 0x100;

      puVar3[0xe] = puVar2[0xe];

      puVar3[0xf] = puVar2[0xf];

      *(uint32_t /* width from decompiler */ *)(*piVar6 + 0xc + iVar7 * 4) =

           *(uint32_t /* width from decompiler */ *)(iVar4 + 0xf0 + *(int *)(param_1 + 8));

      iVar7 = iVar7 + 4;

      iVar4 = iVar4 + 0x140;

    } while (iVar7 < iVar1 + -3);

  }

  if (iVar7 < iVar1) {

    iVar4 = iVar7 * 0x50;

    iVar5 = iVar7 << 6;

    do {

      puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + 0x10 + iVar4);

      puVar3 = (uint32_t /* width from decompiler */ *)(*param_2 + iVar5);

      *puVar3 = *puVar2;

      puVar3[1] = puVar2[1];

      puVar3[2] = puVar2[2];

      puVar3[3] = puVar2[3];

      puVar3[4] = puVar2[4];

      puVar3[5] = puVar2[5];

      puVar3[6] = puVar2[6];

      puVar3[7] = puVar2[7];

      puVar3[8] = puVar2[8];

      puVar3[9] = puVar2[9];

      puVar3[10] = puVar2[10];

      puVar3[0xb] = puVar2[0xb];

      puVar3[0xc] = puVar2[0xc];

      puVar3[0xd] = puVar2[0xd];

      puVar3[0xe] = puVar2[0xe];

      puVar3[0xf] = puVar2[0xf];

      *(uint32_t /* width from decompiler */ *)(*piVar6 + iVar7 * 4) = *(uint32_t /* width from decompiler */ *)(iVar4 + *(int *)(param_1 + 8));

      iVar7 = iVar7 + 1;

      iVar5 = iVar5 + 0x40;

      iVar4 = iVar4 + 0x50;

    } while (iVar7 < iVar1);

  }

  return;

}
