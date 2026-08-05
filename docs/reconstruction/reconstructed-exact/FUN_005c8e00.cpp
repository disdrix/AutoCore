// =============================================================================
// FUN_005c8e00
// -----------------------------------------------------------------------------
// Stable ID: aa_005c8e00
// Address:   0x005c8e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c8e00 @ 0x005c8e00
// Stable ID: aa_005c8e00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_005c8e00, Object_GetRootRaceId.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_005c8e00(int param_1,int *param_2)



{

  RACE_ID_INFERRED RVar1;

  int iVar2;

  int iVar3;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009a6f40;

  local_10 = ExceptionList;

  local_8 = 0;

  if (param_2 != (int *)0x0) {

    ExceptionList = &local_10;

    RVar1 = Object_GetRootRaceId(param_2);

    if ((RVar1 != ~RACE_HUMAN_INFERRED) || (*(int *)(param_2[0x2a] + 0x38) == 3)) {

      iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) +

                          0x28c))();

      iVar3 = (**(code **)(*param_2 + 0x28c))();

      if (iVar2 != iVar3) {

        ExceptionList = local_10;

        return 1;

      }

    }

  }

  ExceptionList = local_10;

  return 0;

}
