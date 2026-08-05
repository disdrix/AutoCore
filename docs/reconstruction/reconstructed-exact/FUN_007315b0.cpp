// =============================================================================
// FUN_007315b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007315b0
// Address:   0x007315b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007315b0 @ 0x007315b0
// Stable ID: aa_007315b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×8, for×1, return×1.
//  - Notable callees: FUN_00447ea0×2, FUN_00416160, FUN_007315b0, FUN_00748430.
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

void FUN_007315b0(int param_1)



{

  int *piVar1;

  int *piVar2;

  int in_EAX;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  FUN_00748430(param_1);

  FUN_00416160(param_1 + 0xd0);

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 400);

  puVar6 = (uint32_t /* width from decompiler */ *)(in_EAX + 400);

  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar6 = puVar6 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1c0) = 0;

  FUN_00447ea0();

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1d4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1d4);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1d8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1d8);

  FUN_00447ea0();

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1ec) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ec);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1f0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1f0);

  if (param_1 == -500) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)(param_1 + 0x1f8);

  }

  piVar3 = (int *)*piVar3;

  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

    (**(code **)(*piVar3 + 4))();

  }

  piVar2 = *(int **)(in_EAX + 0x1f8);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int **)(in_EAX + 0x1f8) = piVar3;

  if (param_1 == -0x1fc) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)(param_1 + 0x200);

  }

  piVar3 = (int *)*piVar3;

  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

    (**(code **)(*piVar3 + 4))();

  }

  piVar2 = *(int **)(in_EAX + 0x200);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int **)(in_EAX + 0x200) = piVar3;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x204) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x204);

  return;

}
