// =============================================================================
// FUN_00808670
// -----------------------------------------------------------------------------
// Stable ID: aa_00808670
// Address:   0x00808670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00808670 @ 0x00808670
// Stable ID: aa_00808670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, for×1, while×1, return×1.
//  - Notable callees: __RTDynamicCast×2, FUN_00573e20, FUN_00574020, FUN_00808670.
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

void FUN_00808670(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  FUN_00573e20();

  iVar5 = 0;

  if (0 < *(int *)(param_2 + 4)) {

    puVar4 = (uint32_t /* width from decompiler */ *)(param_2 + 8);

    do {

      puVar1 = operator_new(0x30);

      puVar6 = puVar4;

      puVar7 = puVar1;

      for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

      FUN_00574020(puVar1);

      iVar5 = iVar5 + 1;

      puVar4 = puVar4 + 0xc;

    } while (iVar5 < *(int *)(param_2 + 4));

  }

  if (*(int *)(param_1 + 0x1038) != 0) {

    piVar2 = (int *)__RTDynamicCast(*(int *)(param_1 + 0x1038),0,&CVOGDialog::RTTI_Type_Descriptor,

                                    &CDlgTabsSocial::RTTI_Type_Descriptor,0);

    (**(code **)(*piVar2 + 0x448))();

  }

  if (*(int *)(param_1 + 0x108c) != 0) {

    piVar2 = (int *)__RTDynamicCast(*(int *)(param_1 + 0x108c),0,&CVOGDialog::RTTI_Type_Descriptor,

                                    &CDlgFriendsDetails::RTTI_Type_Descriptor,0);

    (**(code **)(*piVar2 + 0x448))();

  }

  *(uint8_t *)(param_1 + 0x31e8) = 0;

  return;

}
