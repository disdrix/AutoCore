// =============================================================================
// FUN_0048a940
// -----------------------------------------------------------------------------
// Stable ID: aa_0048a940
// Address:   0x0048a940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048a940 @ 0x0048a940
// Stable ID: aa_0048a940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×2.
//  - Notable callees: FUN_0048a940, memmove.
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

int * __thiscall FUN_0048a940(int *param_1,uint *param_2,uint param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint *puVar2;

  uint uVar3;

  uint *puVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a04c8;

  local_c = ExceptionList;

  uVar3 = *(uint *)(*param_1 + 4);

  if ((uVar3 < param_3) || (param_3 * 3 + 0x18 < uVar3)) {

    puVar2 = &DAT_00b03504;

    local_4 = 0;

    ExceptionList = &local_c;

    if (param_3 != 0) {

      ExceptionList = &local_c;

      puVar2 = operator_new(param_3 + 0xf & 0xfffffffc);

      *puVar2 = param_3;

      *(uint8_t *)((int)puVar2 + param_3 + 8) = 0;

      puVar2[1] = param_3;

    }

    puVar4 = puVar2 + 2;

    for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar4 = *param_2;

      param_2 = param_2 + 1;

      puVar4 = puVar4 + 1;

    }

    for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {

      *(char *)puVar4 = (char)*param_2;

      param_2 = (uint *)((int)param_2 + 1);

      puVar4 = (uint *)((int)puVar4 + 1);

    }

    puVar1 = (uint32_t /* width from decompiler */ *)*param_1;

    *param_1 = (int)puVar2;

    local_4 = 0xffffffff;

    if (puVar1 != &DAT_00b03504) {

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar1);

    }

  }

  else {

    ExceptionList = &local_c;

    memmove((void *)(*param_1 + 8),param_2,param_3);

    *(uint *)*param_1 = param_3;

    *(uint8_t *)(*param_1 + 8 + param_3) = 0;

  }

  ExceptionList = local_c;

  return param_1;

}
