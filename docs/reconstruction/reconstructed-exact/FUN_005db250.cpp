// =============================================================================
// FUN_005db250
// -----------------------------------------------------------------------------
// Stable ID: aa_005db250
// Address:   0x005db250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005db250 @ 0x005db250
// Stable ID: aa_005db250
// Embedded strings (evidence for future rename):
//   - "TC[%I64d](%d:%f)-%d-(%d:%f)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×8, return×8, switch×1, goto×1.
//  - Notable callees: CVOGMap_LookupVariable×2, FUN_005db250, FUN_007a4480.
//  - Strings: "TC[%I64d](%d:%f)-%d-(%d:%f)\n".
//  - Return sites: 8.

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

uint32_t /* width from decompiler */ __thiscall FUN_005db250(int param_1,uint32_t /* width from decompiler */ *param_2,float param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char cVar4;

  

  puVar3 = param_2;

  cVar4 = CVOGMap_LookupVariable(*param_2,&param_3,param_3);

  if ((cVar4 != '\0') && (cVar4 = CVOGMap_LookupVariable(puVar3[1],&param_2,param_4), cVar4 != '\0')

     ) {

    iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);

    iVar1 = iVar2 + param_1;

    if (*(char *)(*(int *)(*(int *)(iVar2 + 0xa8 + param_1) + 0xe508) + 0x3c) != '\0') {

      FUN_007a4480(0,"TC[%I64d](%d:%f)-%d-(%d:%f)\n",*(uint32_t /* width from decompiler */ *)(iVar1 + 0x164),

                   *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168),*puVar3,(double)param_3,(int)*(char *)(puVar3 + 2)

                   ,puVar3[1],(double)(float)param_2);

    }

    switch(*(uint8_t *)(puVar3 + 2)) {

    case 0:

      if (param_3 < (float)param_2) {

        return 1;

      }

      break;

    case 1:

      if ((float)param_2 < param_3) {

        return 1;

      }

      break;

    case 2:

      if (param_3 <= (float)param_2) {

        return 1;

      }

      break;

    case 3:

      if ((float)param_2 <= param_3) {

        return 1;

      }

      break;

    case 4:

      if (param_3 == (float)param_2) {

        return 1;

      }

      break;

    case 5:

      if (param_3 != (float)param_2) {

        return 1;

      }

      break;

    default:

      goto LAB_005db3af;

    }

    return 0;

  }

LAB_005db3af:

  return 1;

}
