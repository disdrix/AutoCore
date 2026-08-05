// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004ac520
// -----------------------------------------------------------------------------
// Stable ID: aa_004ac520
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004ac520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×8, do×3, while×3, for×1, return×1.
//  - Notable callees: FUN_004a9a20, FUN_004ac520, FUN_004aefa0, FUN_004afad0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004ac520(int param_1)



{

  char cVar1;

  char cVar2;

  int iVar3;

  uint8_t uVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  int local_c;

  int local_8;

  

  if (*(int *)(param_1 + 4) == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 1;

  }

  if (0 < iVar7) {

    iVar8 = 0;

    local_c = 1;

    iVar5 = local_c;

    local_8 = iVar7;

    do {

      for (; iVar5 < iVar7; iVar5 = iVar5 + 1) {

        iVar3 = *(int *)(param_1 + 4);

        cVar1 = *(char *)(iVar3 + iVar5 * 2);

        cVar2 = *(char *)(iVar8 + iVar3);

        if (cVar2 < cVar1) {

          *(char *)(iVar8 + iVar3) = cVar1;

          *(char *)(*(int *)(param_1 + 4) + iVar5 * 2) = cVar2;

          iVar3 = *(int *)(param_1 + 4);

          uVar4 = *(uint8_t *)(iVar8 + 1 + iVar3);

          *(uint8_t *)(iVar8 + 1 + iVar3) = *(uint8_t *)(iVar3 + 1 + iVar5 * 2);

          *(uint8_t *)(*(int *)(param_1 + 4) + 1 + iVar5 * 2) = uVar4;

        }

      }

      iVar5 = local_c + 1;

      iVar8 = iVar8 + 2;

      local_8 = local_8 + -1;

      local_c = iVar5;

    } while (local_8 != 0);

  }

  iVar5 = *(int *)(param_1 + 4);

  uVar4 = FUN_004a9a20();

  iVar8 = 0;

  *(uint8_t *)(iVar5 + iVar7 * 2 + -1) = uVar4;

  if (0 < iVar7) {

    do {

      cVar1 = *(char *)(*(int *)(param_1 + 4) + 1 + iVar8 * 2);

      if (('\a' < cVar1) && (cVar1 < '\x10')) {

        *(char *)(*(int *)(param_1 + 4) + 1 + iVar8 * 2) = '\x17' - cVar1;

      }

      iVar8 = iVar8 + 1;

    } while (iVar8 < iVar7);

  }

  do {

    iVar5 = *(int *)(param_1 + 4);

    if (iVar5 == 0) {

      uVar6 = 0;

    }

    else {

      uVar6 = *(int *)(param_1 + 8) - iVar5 >> 1;

      if (3 < uVar6) {

        return;

      }

    }

    iVar8 = iVar5 + -2 + uVar6 * 2;

    if ((iVar5 == 0) ||

       ((uint)(*(int *)(param_1 + 0xc) - iVar5 >> 1) <= (uint)(*(int *)(param_1 + 8) - iVar5 >> 1)))

    {

      FUN_004afad0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),1,iVar8);

    }

    else {

      iVar5 = *(int *)(param_1 + 8);

      FUN_004aefa0(iVar5,1,iVar8,param_1,iVar7);

      *(int *)(param_1 + 8) = iVar5 + 2;

    }

  } while( true );

}
