// =============================================================================
// FUN_00808bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00808bc0
// Address:   0x00808bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00808bc0 @ 0x00808bc0
// Stable ID: aa_00808bc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_005740f0, FUN_00808bc0, __RTDynamicCast.
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

void FUN_00808bc0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int *piVar6;

  char *pcVar7;

  int iVar8;

  char *pcVar9;

  

  iVar8 = 0;

  if (0 < (int)param_2[1]) {

    pcVar9 = (char *)(param_2 + 0x2a);

    puVar4 = param_2;

    do {

      puVar5 = operator_new(0x28);

      iVar2 = *(int *)(param_1 + 0xe98);

      iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);

      *puVar5 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + iVar2);

      puVar5[1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168 + iVar2);

      puVar5[2] = puVar4[2];

      puVar5[3] = puVar4[3];

      pcVar7 = pcVar9;

      do {

        cVar1 = *pcVar7;

        pcVar7[(iVar8 - (int)pcVar9) + 0x10 + (int)puVar5] = cVar1;

        pcVar7 = pcVar7 + 1;

      } while (cVar1 != '\0');

      FUN_005740f0(puVar5);

      iVar8 = iVar8 + 1;

      pcVar9 = pcVar9 + 1;

      puVar4 = puVar4 + 2;

    } while (iVar8 < (int)param_2[1]);

  }

  if (*(int *)(param_1 + 0x1038) != 0) {

    piVar6 = (int *)__RTDynamicCast(*(int *)(param_1 + 0x1038),0,&CVOGDialog::RTTI_Type_Descriptor,

                                    &CDlgTabsSocial::RTTI_Type_Descriptor,0);

    (**(code **)(*piVar6 + 0x448))();

  }

  return;

}
