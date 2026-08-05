// =============================================================================
// FUN_004237e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004237e0
// Address:   0x004237e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004237e0 @ 0x004237e0
// Stable ID: aa_004237e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×1.
//  - Notable callees: FUN_004237e0, FUN_00423860, LOCK, UNLOCK.
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

void __thiscall FUN_004237e0(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int *piVar1;

  int iVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  param_2 = (uint32_t /* width from decompiler */ *)*param_2;

  iVar2 = param_2[-3];

  puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_2[-4] + 0x10))();

  iVar4 = (**(code **)*puVar3)();

  if (iVar4 == 0) {

    iVar4 = FUN_00423860();

  }

  if (iVar2 < in_EAX) {

    in_EAX = iVar2;

  }

  uVar6 = in_EAX * 2 + 2;

  puVar7 = (uint32_t /* width from decompiler */ *)(iVar4 + 0x10);

  puVar3 = param_2;

  for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

    *puVar7 = *puVar3;

    puVar7 = puVar7 + 1;

    puVar3 = puVar3 + 1;

  }

  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

    *(uint8_t *)puVar7 = *(uint8_t *)puVar3;

    puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

    puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

  }

  *(int *)(iVar4 + 4) = iVar2;

  piVar1 = param_2 + -1;

  LOCK();

  iVar2 = *piVar1;

  *piVar1 = *piVar1 + -1;

  UNLOCK();

  if (iVar2 == 1 || iVar2 + -1 < 0) {

    (**(code **)(*(int *)param_2[-4] + 4))(param_2 + -4);

  }

  *param_1 = iVar4 + 0x10;

  return;

}
