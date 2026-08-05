// =============================================================================
// FUN_004d20c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d20c0
// Address:   0x004d20c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d20c0 @ 0x004d20c0
// Stable ID: aa_004d20c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: fwrite×5, ftell×4, FUN_004d2050, FUN_004d20c0.
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

void __thiscall FUN_004d20c0(int param_1,FILE *param_2,FILE *param_3)



{

  int iVar1;

  long lVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_retaddr;

  int local_c [2];

  int local_4;

  

  local_4 = param_1;

  FUN_004d2050();

  iVar1 = *(int *)(param_1 + 0xe894);

  if (*(int *)(iVar1 + 0x144) == 0) {

    local_c[0] = 0;

  }

  else {

    local_c[0] = *(int *)(iVar1 + 0x148) - *(int *)(iVar1 + 0x144) >> 2;

  }

  if (*(int *)(iVar1 + 0x154) == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(iVar1 + 0x158) - *(int *)(iVar1 + 0x154) >> 2;

  }

  local_c[0] = local_c[0] + iVar1;

  fwrite(local_c,4,1,param_2);

  puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xe894) + 0x144);

  if (puVar3 != *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xe894) + 0x148)) {

    do {

      ftell(param_3);

      (**(code **)(*(int *)*puVar3 + 4))(param_3);

      lVar2 = ftell(param_3);

      local_c[0] = lVar2 - unaff_retaddr;

      fwrite(local_c,4,1,param_2);

      (**(code **)(*(int *)*puVar3 + 0x28))();

      fwrite(&stack0xffffffef,1,1,param_2);

      (**(code **)(*(int *)*puVar3 + 4))(param_2);

      puVar3 = puVar3 + 1;

    } while (puVar3 != *(uint32_t /* width from decompiler */ **)(*(int *)(local_4 + 0xe894) + 0x148));

  }

  puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(local_4 + 0xe894) + 0x154);

  if (puVar3 != *(uint32_t /* width from decompiler */ **)(*(int *)(local_4 + 0xe894) + 0x158)) {

    do {

      ftell(param_3);

      (**(code **)(*(int *)*puVar3 + 4))(param_3);

      lVar2 = ftell(param_3);

      local_c[0] = lVar2 - unaff_retaddr;

      fwrite(local_c,4,1,param_2);

      (**(code **)(*(int *)*puVar3 + 0x28))();

      fwrite(&stack0xffffffef,1,1,param_2);

      (**(code **)(*(int *)*puVar3 + 4))(param_2);

      puVar3 = puVar3 + 1;

    } while (puVar3 != *(uint32_t /* width from decompiler */ **)(*(int *)(local_4 + 0xe894) + 0x158));

  }

  return;

}
