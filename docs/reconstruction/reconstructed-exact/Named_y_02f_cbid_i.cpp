// =============================================================================
// Named_y_02f_cbid_i
// -----------------------------------------------------------------------------
// Stable ID: aa_00954dc0
// Address:   0x00954dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_y_02f_cbid_i @ 0x00954dc0
// Stable ID: aa_00954dc0
// Embedded strings (evidence for future rename):
//   - "%s found at x:%.02f / y:%.02f (cbid:%i)"
//   - "OBJECT AT:"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, do×1, goto×1, return×1.
//  - Notable callees: strstr×3, FUN_004bae00×2, _snprintf×2, CNDHash_LookupByKey, CONCAT44, FUN_008f8200, Named_y_02f_cbid_i, __RTDynamicCast.
//  - Strings: "%s found at x:%.02f / y:%.02f (cbid:%i)"; "OBJECT AT:".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "%s found at x:%.02f / y:%.02f (cbid:%i)"
 * Domain alias of FUN_00954dc0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_y_02f_cbid_i(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  int iVar1;

  char *pcVar2;

  int *piVar3;

  int iVar4;

  void *pvVar5;

  char *_Str;

  uint32_t /* width from decompiler */ uVar6;

  uint *puVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint64_t uVar9;

  uint32_t /* width from decompiler */ uVar10;

  int iStack_510;

  char local_508 [256];

  char acStack_408 [1028];

  

  pcVar2 = strtok((char *)0x0,param_3);

  if ((pcVar2 != (char *)0x0) && (strncpy(local_508,pcVar2,0x100), *(int *)(param_1 + 0xe98) != 0))

  {

    piVar3 = (int *)FUN_004bae00();

    while (piVar3 != (int *)0x0) {

      if (*(int *)(piVar3[0x2a] + 0x38) == 0x36) {

        iVar4 = (**(code **)(*piVar3 + 0x1ec))();

        puVar7 = (uint *)(iVar4 + 0xf0);

        iStack_510 = 0;

        do {

          if ((((*puVar7 != 0xffffffff) && (*(char *)((int)puVar7 + 5) == '\0')) &&

              (pvVar5 = CNDHash_LookupByKey(*(void **)(*(int *)(param_1 + 0xd30) + 0xf10),*puVar7),

              pvVar5 != (void *)0x0)) &&

             ((pcVar2 = strstr((char *)((int)pvVar5 + 0x40),local_508), pcVar2 != (char *)0x0 ||

              (pcVar2 = strstr((char *)((int)pvVar5 + 0x188),local_508), pcVar2 != (char *)0x0)))) {

            iVar1 = *(int *)(*(int *)(iVar4 + 4) + 4);

            _snprintf(acStack_408,0x400,"%s found at x:%.02f / y:%.02f (cbid:%i)",(int)pvVar5 + 0x40

                      ,(double)*(float *)(iVar1 + iVar4 + 0x84),

                      (double)*(float *)(iVar1 + 0x8c + iVar4),*(uint32_t /* width from decompiler */ *)((int)pvVar5 + 0x34));

            uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x109c);

            goto LAB_00954fc9;

          }

          iStack_510 = iStack_510 + 1;

          puVar7 = puVar7 + 3;

        } while (iStack_510 < 0xc);

      }

      else {

        pcVar2 = local_508;

        _Str = (char *)(**(code **)(*piVar3 + 0x160))();

        pcVar2 = strstr(_Str,pcVar2);

        if (pcVar2 != (char *)0x0) {

          uVar6 = (**(code **)(*piVar3 + 0x160))

                            ((double)(float)piVar3[0x20],(double)(float)piVar3[0x22],

                             *(uint32_t /* width from decompiler */ *)(piVar3[0x2a] + 0x34));

          _snprintf(acStack_408,0x400,"%s found at x:%.02f / y:%.02f (cbid:%i)",uVar6);

          uVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x109c);

LAB_00954fc9:

          uVar10 = 0;

          uVar9 = CONCAT44(acStack_408,"OBJECT AT:");

          uVar8 = 6;

          uVar6 = __RTDynamicCast(uVar6,0,&CVOGDialog::RTTI_Type_Descriptor,

                                  &CDlgChatLog::RTTI_Type_Descriptor,0x600000000,uVar9,0);

          FUN_008f8200(uVar6,uVar8,uVar9,uVar10);

        }

      }

      piVar3 = (int *)FUN_004bae00();

    }

  }

  return 1;

}
