// =============================================================================
// FUN_009423b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009423b0
// Address:   0x009423b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009423b0 @ 0x009423b0
// Stable ID: aa_009423b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×11, for×1, return×1.
//  - Notable callees: FUN_007fb990, FUN_007fea50, FUN_007feb20, FUN_00914140, FUN_009142f0, FUN_0091ebe0, FUN_0092d730, FUN_0093e120.
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

void __thiscall FUN_009423b0(char param_1,int param_2,char param_3,char param_4)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ local_18 [2];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  

  if (*(int *)(param_2 + 0xe98) != 0) {

    if ((*(int *)(param_2 + 0xf38) != 0) && (param_1 != -1)) {

      *(char *)(*(int *)(param_2 + 0xf38) + 0xa81) = param_1;

    }

    iVar2 = *(int *)(param_2 + 0xe98);

    if (param_3 == '\0') {

      if (*(char *)(iVar2 + 0x4f1) != '\0') {

        if (iVar2 != 0) {

          *(uint8_t *)(iVar2 + 0x4f1) = 0;

        }

        (**(code **)(**(int **)(param_2 + 0x1168) + 4))(1);

        if (*(int *)(param_2 + 0xf38) == 0) {

          FUN_007fea50();

        }

        else {

          FUN_009142f0();

          FUN_00914140();

        }

      }

    }

    else if (*(char *)(iVar2 + 0x4f1) == '\0') {

      puVar3 = &DAT_00d2188c;

      for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      *(uint16_t *)puVar3 = 0;

      FUN_0092d730();

      FUN_0093e120(0);

      *(uint8_t *)(*(int *)(param_2 + 0xe98) + 0x4f1) = 1;

      FUN_007fb990();

      if (DAT_00d1b9a8 != (int *)0x0) {

        (**(code **)(*DAT_00d1b9a8 + 4))(1);

      }

      if (*(int *)(param_2 + 0xf38) == 0) {

        FUN_007feb20();

      }

      else {

        iVar2 = *(int *)(param_2 + 0xf38);

        DAT_00afe0fc = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xcc4);

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xcc4) = 8;

        *(uint8_t *)(iVar2 + 0xa82) = 0;

        FUN_0091ebe0();

      }

    }

    if (param_4 == '\0') {

      iVar2 = *(int *)(param_2 + 0xe98);

      local_18[0] = 0x2075;

      iVar1 = *(int *)(*(int *)(iVar2 + 4) + 4);

      local_10 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + iVar2);

      local_c = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + iVar2);

      if (*(int *)(param_2 + 0xc78) != 0) {

        (**(code **)(**(int **)(param_2 + 0xc78) + 0x18))(0xffffffff,local_18,0x18,0);

      }

    }

    *(uint8_t *)(*(int *)(param_2 + 0x4d0) + 4) = 1;

  }

  return;

}
