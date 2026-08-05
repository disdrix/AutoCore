// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_004bb970
// -----------------------------------------------------------------------------
// Stable ID: aa_004bb970
// Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
// Address:   0x004bb970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper. Evidence string: "Null return value in clonedobjectlist %I64d, %d". Supports parent flow (not a free-standing entry point). Named_VOG_DEBUG_STOP (+2 other named callers).
// Embedded strings (evidence):
//   - "Null return value in clonedobjectlist %I64d, %d"
//   - "Null typelist in clonedobjectlist %I64d, %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×18, return×7, while×3, do×2.
//  - Notable callees: FUN_004bca50×4, FUN_007a4480×2, memmove×2, CNDHash_LookupByKey, FUN_004024b0, FUN_004109e0, FUN_004bb970, FUN_004bcda0.
//  - Strings: "Null return value in clonedobjectlist %I64d, %d"; "Null typelist in clonedobjectlist %I64d, %d".
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_004bb970(int param_1,uint param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  void *pvVar6;

  int iVar7;

  int *piVar8;

  int local_4;

  

  uVar3 = param_4;

  uVar2 = param_3;

  local_4 = 0;

  if (*(char *)(param_1 + 0xe) != '\0') {

    return 0;

  }

  if ((char)param_2 == '\0') {

    cVar1 = *(char *)(param_1 + 0xd);

  }

  else {

    cVar1 = *(char *)(param_1 + 0xc);

  }

  if ((cVar1 == '\0') ||

     (iVar5 = FUN_004bcda0(param_3,param_4,&local_4), iVar4 = local_4, iVar5 < 0)) {

    return 0;

  }

  if (local_4 == 0) {

    FUN_007a4480(0,"Null return value in clonedobjectlist %I64d, %d",uVar2,uVar3,param_2 & 0xff);

    return 0;

  }

  pvVar6 = CNDHash_LookupByKey(*(void **)(param_1 + 0x18),*(uint *)(*(int *)(local_4 + 0xa8) + 0x38)

                              );

  if (pvVar6 == (void *)0x0) {

    FUN_007a4480(0,"Null typelist in clonedobjectlist %I64d, %d",uVar2,uVar3,param_2 & 0xff);

    return 0;

  }

  param_2 = *(int *)(iVar4 + 0xdc);

  if (param_2 != 0) {

    FUN_004bca50(&param_2);

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xdc) = 0;

  }

  param_2 = *(int *)(iVar4 + 0xd4);

  if (param_2 != 0) {

    FUN_004bca50(&param_2);

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xd4) = 0;

  }

  param_2 = *(int *)(iVar4 + 0xd0);

  if (param_2 != 0) {

    FUN_004bca50(&param_2);

    iVar5 = FUN_004024b0();

    iVar7 = 0;

    if (0 < iVar5) {

      piVar8 = *(int **)(param_1 + 0x2c);

      do {

        if (*piVar8 == iVar4) {

          FUN_004109e0(&param_2,*(int **)(param_1 + 0x2c) + iVar7);

          break;

        }

        iVar7 = iVar7 + 1;

        piVar8 = piVar8 + 1;

      } while (iVar7 < iVar5);

    }

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xd0) = 0;

  }

  param_2 = *(int *)(iVar4 + 0xd8);

  if (param_2 != 0) {

    FUN_004bca50(&param_2);

    if (*(int *)(param_1 + 0x3c) == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x3c) >> 2;

    }

    iVar7 = 0;

    if (0 < iVar5) {

      piVar8 = *(int **)(param_1 + 0x3c);

      do {

        if (*piVar8 == iVar4) {

          piVar8 = *(int **)(param_1 + 0x3c) + iVar7;

          memmove(piVar8,piVar8 + 1,(*(int *)(param_1 + 0x40) - (int)(piVar8 + 1) >> 2) * 4);

          *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + -4;

          break;

        }

        iVar7 = iVar7 + 1;

        piVar8 = piVar8 + 1;

      } while (iVar7 < iVar5);

    }

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xd8) = 0;

  }

  if (*(int *)(*(int *)(iVar4 + 0xa8) + 0x38) == 0x14) {

    if (*(int *)(param_1 + 0x4c) == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c) >> 2;

    }

    iVar7 = 0;

    if (0 < iVar5) {

      piVar8 = *(int **)(param_1 + 0x4c);

      while (*piVar8 != iVar4) {

        iVar7 = iVar7 + 1;

        piVar8 = piVar8 + 1;

        if (iVar5 <= iVar7) {

          return iVar4;

        }

      }

      piVar8 = *(int **)(param_1 + 0x4c) + iVar7;

      memmove(piVar8,piVar8 + 1,(*(int *)(param_1 + 0x50) - (int)(piVar8 + 1) >> 2) * 4);

      *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + -4;

    }

  }

  return iVar4;

}
