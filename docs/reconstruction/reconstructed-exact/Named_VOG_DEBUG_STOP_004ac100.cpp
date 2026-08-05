// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, for×2.
//  - Notable callees: FUN_004930b0, FUN_004941b0, FUN_004aa300, FUN_004abd00, FUN_004ac100, FUN_005bf720, FUN_005c0f40, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 3.

// =============================================================================
// Named_VOG_DEBUG_STOP_004ac100
// -----------------------------------------------------------------------------
// Stable ID: aa_004ac100
// Address:   0x004ac100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_VOG_DEBUG_STOP_004ac100(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  int iVar3;

  

  if (*(int *)(param_1 + 0x3d8) == 0) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    return 0;

  }

  FUN_004941b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x340));

  *(int *)(param_1 + 900) =

       (int)(*(int *)(param_1 + 0x10) + (*(int *)(param_1 + 0x10) >> 0x1f & 0xfU)) >> 4;

  *(int *)(param_1 + 0x388) =

       (int)(*(int *)(param_1 + 0x14) + (*(int *)(param_1 + 0x14) >> 0x1f & 0xfU)) >> 4;

  if (*(void **)(param_1 + 0x38c) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x38c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38c) = 0;

  puVar1 = operator_new__(*(int *)(param_1 + 900) * *(int *)(param_1 + 0x388) * 4);

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x38c) = puVar1;

  for (uVar2 = *(int *)(param_1 + 900) * *(int *)(param_1 + 0x388) & 0x3fffffff; uVar2 != 0;

      uVar2 = uVar2 - 1) {

    *puVar1 = 0;

    puVar1 = puVar1 + 1;

  }

  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {

    *(uint8_t *)puVar1 = 0;

    puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

  }

  FUN_004abd00();

  FUN_004aa300();

  FUN_004930b0();

  if (DAT_00b03631 != '\0') {

    FUN_005c0f40(param_1);

    DAT_00b03632 = DAT_00b03631;

    return 1;

  }

  FUN_005bf720();

  DAT_00b03632 = DAT_00b03631;

  return 1;

}
