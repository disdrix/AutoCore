// =============================================================================
// FUN_005eb8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005eb8e0
// Address:   0x005eb8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005eb8e0 @ 0x005eb8e0
// Stable ID: aa_005eb8e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_005eb8e0, FUN_00634450.
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

void __thiscall FUN_005eb8e0(int param_1,int *param_2)



{

  short *psVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int iVar7;

  int local_3c;

  int *piStack_38;

  int iStack_34;

  uint8_t auStack_30 [44];

  

  *(short *)((int)param_2 + 6) = *(short *)((int)param_2 + 6) + 1;

  local_3c = param_1;

  uVar5 = (**(code **)(*param_2 + 0x14))();

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = uVar5;

  psVar1 = (short *)((int)puVar2 + 6);

  *psVar1 = *psVar1 + -1;

  if (*psVar1 == 0) {

    (**(code **)*puVar2)(1);

  }

  *(int **)(param_1 + 0xc) = param_2;

  piStack_38 = *(int **)(*(int *)(param_1 + 8) + 0xcc);

  iVar3 = *(int *)(param_1 + 0xc4);

  while (iVar3 = iVar3 + -1, -1 < iVar3) {

    puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc0) + iVar3 * 8);

    (**(code **)(**(int **)(*(int *)(param_1 + 0xc0) + iVar3 * 8) + 0x14))();

    iStack_34 = *piStack_38;

    puVar4 = (uint32_t /* width from decompiler */ *)puVar2[1];

    iVar6 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();

    iVar7 = (**(code **)(*(int *)*puVar4 + 0x14))();

    uVar5 = (**(code **)(iStack_34 + 0x18c + (iVar6 * 0x20 + iVar7) * 4))

                      (local_3c + 0xc,puVar4,piStack_38,0);

    *puVar2 = uVar5;

    param_1 = local_3c;

  }

  if (*(int *)(param_1 + 8) != 0) {

    (**(code **)(*param_2 + 0x18))

              (param_1 + 0x80,*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 8) + 0xcc) + 8),auStack_30

              );

    FUN_00634450(&local_3c);

  }

  return;

}
