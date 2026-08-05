// =============================================================================
// FUN_006579b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006579b0
// Address:   0x006579b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006579b0 @ 0x006579b0
// Stable ID: aa_006579b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_006574e0, FUN_006579b0.
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

void __thiscall FUN_006579b0(int param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  int local_c [3];

  

  piVar1 = param_2;

  iVar8 = 0;

  local_c[0] = 0;

  local_c[1] = 0;

  local_c[2] = -0x80000000;

  FUN_006574e0(local_c);

  iVar4 = *(int *)(param_1 + 0x80) * 4;

  if ((int)(param_2[2] & 0x7fffffffU) < iVar4) {

    iVar2 = (param_2[2] & 0x7fffffffU) * 2;

    if (iVar2 <= iVar4) {

      iVar2 = iVar4;

    }

    FUN_005b3300(param_2,iVar2,0x10);

  }

  param_2[1] = iVar4;

  if (0 < *(int *)(param_1 + 0x80)) {

    iVar4 = 0;

    param_2 = (int *)0x0;

    do {

      iVar2 = *piVar1;

      *(uint32_t /* width from decompiler */ *)(iVar2 + iVar4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x60);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 4 + iVar4) = *(uint32_t /* width from decompiler */ *)(param_1 + 100);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 8 + iVar4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x68);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc + iVar4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c);

      iVar6 = (int)param_2 + local_c[0];

      iVar2 = *piVar1;

      iVar5 = iVar4 + 0x10;

      *(uint32_t /* width from decompiler */ *)(iVar2 + iVar5) = *(uint32_t /* width from decompiler */ *)((int)param_2 + local_c[0]);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 4 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar6 + 4);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 8 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar6 + 8);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc);

      iVar5 = (int)param_2 + local_c[0];

      iVar2 = *piVar1;

      *(uint32_t /* width from decompiler */ *)(iVar2 + iVar4 + 0x20) = *(uint32_t /* width from decompiler */ *)((int)param_2 + local_c[0]);

      iVar2 = iVar2 + iVar4 + 0x20;

      *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = *(uint32_t /* width from decompiler */ *)(iVar5 + 4);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 8) = *(uint32_t /* width from decompiler */ *)(iVar5 + 8);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc);

      iVar8 = iVar8 + 1;

      param_2 = (int *)((int)param_2 + 0x10);

      puVar3 = (uint32_t /* width from decompiler */ *)(*piVar1 + iVar4 + 0x30);

      iVar4 = iVar4 + 0x40;

      puVar7 = (uint32_t /* width from decompiler */ *)((iVar8 % *(int *)(param_1 + 0x80)) * 0x10 + local_c[0]);

      *puVar3 = *puVar7;

      puVar3[1] = puVar7[1];

      puVar3[2] = puVar7[2];

      puVar3[3] = puVar7[3];

    } while (iVar8 < *(int *)(param_1 + 0x80));

  }

  if (-1 < local_c[2]) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_c[0],local_c[2] << 4,0x12);

  }

  return;

}
