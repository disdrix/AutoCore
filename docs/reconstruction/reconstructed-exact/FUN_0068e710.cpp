// =============================================================================
// FUN_0068e710
// -----------------------------------------------------------------------------
// Stable ID: aa_0068e710
// Address:   0x0068e710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068e710 @ 0x0068e710
// Stable ID: aa_0068e710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, return×4, do×1, while×1.
//  - Notable callees: FUN_0068cfe0×2, FUN_00410420, FUN_0068e6b0, FUN_0068e6e0, FUN_0068e710.
//  - Return sites: 4.

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

void __thiscall FUN_0068e710(int param_1,uint param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  

  if (*(int *)(param_1 + 0x34) != 0) {

    FUN_0068cfe0(*(int *)(param_1 + 0x34),*(uint32_t /* width from decompiler */ *)(param_1 + 0x38),param_1 + 0x30,param_2);

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x34));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  if (*(int *)(param_1 + 0x44) != 0) {

    FUN_0068cfe0(*(int *)(param_1 + 0x44),*(uint32_t /* width from decompiler */ *)(param_1 + 0x48),param_1 + 0x40,param_2);

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x44));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  if (*(void **)(param_1 + 0x24) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x24));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  uVar3 = param_2 & 0xffff;

  *(uint16_t *)(param_1 + 0x18) = (uint16_t)param_2;

  FUN_0068e6b0(uVar3);

  FUN_0068e6e0(uVar3);

  FUN_00410420(uVar3,0);

  iVar2 = 0;

  if (uVar3 != 0) {

    do {

      iVar1 = iVar2 * 4;

      iVar2 = iVar2 + 1;

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x24) + iVar1) = 0;

    } while (iVar2 < (int)uVar3);

  }

  return;

}
