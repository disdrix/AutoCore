// =============================================================================
// FUN_0048a890
// -----------------------------------------------------------------------------
// Stable ID: aa_0048a890
// Address:   0x0048a890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048a890 @ 0x0048a890
// Stable ID: aa_0048a890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×2.
//  - Notable callees: FUN_0048a890.
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

void __thiscall FUN_0048a890(int *param_1,uint param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  uint uVar4;

  uint uVar5;

  uint *puVar6;

  uint *puVar7;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a04a8;

  local_c = ExceptionList;

  if ((uint)((int *)*param_1)[1] < param_2) {

    iVar1 = *(int *)*param_1;

    local_4 = 0;

    if (param_2 == 0) {

      piVar3 = &DAT_00b03504;

      ExceptionList = &local_c;

    }

    else {

      ExceptionList = &local_c;

      piVar3 = operator_new(param_2 + 0xf & 0xfffffffc);

      *piVar3 = iVar1;

      *(uint8_t *)(iVar1 + 8 + (int)piVar3) = 0;

      piVar3[1] = param_2;

    }

    uVar5 = *(uint *)*param_1;

    puVar6 = (uint *)*param_1 + 2;

    puVar7 = (uint *)(piVar3 + 2);

    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *puVar7 = *puVar6;

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

    }

    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(char *)puVar7 = (char)*puVar6;

      puVar6 = (uint *)((int)puVar6 + 1);

      puVar7 = (uint *)((int)puVar7 + 1);

    }

    puVar2 = (uint32_t /* width from decompiler */ *)*param_1;

    *param_1 = (int)piVar3;

    local_4 = 0xffffffff;

    if (puVar2 != &DAT_00b03504) {

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar2);

    }

  }

  ExceptionList = local_c;

  return;

}
