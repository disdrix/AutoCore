// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Sending_Challenge_Response_007803f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007803f0
// Callee of Named_CalleeOf_Named_Sending_Challenge_Response_8x
// Address:   0x007803f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Sending_Challenge_Response_8x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, do×2, goto×2, while×2, for×1.
//  - Notable callees: FUN_0042b2a0, FUN_007803f0, free, qsort.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Sending_Challenge_Response_8x
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_Sending_Challenge_Response_007803f0(int param_1)



{

  int *piVar1;

  byte bVar2;

  byte *pbVar3;

  int iVar4;

  size_t _NumOfElements;

  byte *pbVar5;

  int iVar6;

  bool bVar7;

  int local_14;

  byte *local_10;

  

  if (DAT_00d17a04 != '\0') {

    return *(uint32_t /* width from decompiler */ *)(param_1 + 4);

  }

  _NumOfElements = 0;

  DAT_00d17a04 = '\x01';

  for (iVar6 = DAT_00d17a00; iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {

    FUN_0042b2a0();

    _NumOfElements = _NumOfElements + 1;

    piVar1 = (int *)(_NumOfElements * 4 + -4);

    if (piVar1 != (int *)0x0) {

      *piVar1 = iVar6;

    }

  }

  qsort((void *)0x0,_NumOfElements,4,(_PtFuncCompare *)&LAB_00780150);

  iVar6 = 0;

  local_14 = 0;

  local_10 = &DAT_00a1419b;

  if (0 < (int)_NumOfElements) {

    do {

      pbVar3 = (byte *)**(uint32_t /* width from decompiler */ **)(iVar6 * 4);

      pbVar5 = local_10;

      do {

        bVar2 = *pbVar3;

        bVar7 = bVar2 < *pbVar5;

        if (bVar2 != *pbVar5) {

LAB_007804b4:

          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);

          goto LAB_007804b9;

        }

        if (bVar2 == 0) break;

        bVar2 = pbVar3[1];

        bVar7 = bVar2 < pbVar5[1];

        if (bVar2 != pbVar5[1]) goto LAB_007804b4;

        pbVar3 = pbVar3 + 2;

        pbVar5 = pbVar5 + 2;

      } while (bVar2 != 0);

      iVar4 = 0;

LAB_007804b9:

      if (iVar4 == 0) {

        *(int *)(*(int *)(iVar6 * 4) + 4) = local_14;

      }

      else {

        local_14 = local_14 + 1;

        *(int *)(*(int *)(iVar6 * 4) + 4) = local_14;

        local_10 = (byte *)**(uint32_t /* width from decompiler */ **)(iVar6 * 4);

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < (int)_NumOfElements);

  }

  free((void *)0x0);

  return *(uint32_t /* width from decompiler */ *)(param_1 + 4);

}
