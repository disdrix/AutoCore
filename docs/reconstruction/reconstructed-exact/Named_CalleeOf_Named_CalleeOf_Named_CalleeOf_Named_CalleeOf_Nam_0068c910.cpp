// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068c910
// -----------------------------------------------------------------------------
// Stable ID: aa_0068c910
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068c910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×9, goto×1, return×1.
//  - Notable callees: FUN_00449000×2, FUN_00445bc0, FUN_00685ec0, FUN_0068c910.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068c910(char *param_1,uint32_t /* width from decompiler */ *param_2,short param_3)



{

  float fVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  

  if (*(int *)(param_1 + 0xb4) == 0) {

    uVar3 = 0;

  }

  else {

    uVar3 = *(int *)(param_1 + 0xb8) - *(int *)(param_1 + 0xb4) >> 2;

  }

  if ((uint)*(ushort *)(param_1 + 0x1a) == uVar3 >> 1) {

    if (*(int *)(param_1 + 0xb4) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(param_1 + 0xb8) - *(int *)(param_1 + 0xb4) >> 2;

    }

    FUN_00449000(iVar4 + 2,0);

    if (param_3 < 0) goto LAB_0068c9f8;

    if (*param_1 != '\0') {

      if (*(int *)(param_1 + 0xd4) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(param_1 + 0xd8) - *(int *)(param_1 + 0xd4);

      }

      FUN_00445bc0(iVar4 + 1,0);

      if (*(int *)(param_1 + 0xc4) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(param_1 + 200) - *(int *)(param_1 + 0xc4) >> 2;

      }

      FUN_00449000(iVar4 + 2,0);

    }

  }

  if ((-1 < param_3) && (*param_1 != '\0')) {

    *(char *)((uint)*(ushort *)(param_1 + 0x1a) + *(int *)(param_1 + 0xd4)) = (char)param_3;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc4) + (uint)*(ushort *)(param_1 + 0x1a) * 8) = *param_2;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc4) + 4 + (uint)*(ushort *)(param_1 + 0x1a) * 8) =

         param_2[1];

  }

LAB_0068c9f8:

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + (uint)*(ushort *)(param_1 + 0x1a) * 8) = *param_2;

  cVar2 = FUN_00685ec0();

  fVar1 = (float)param_2[1];

  if (cVar2 != '\0') {

    fVar1 = -fVar1;

  }

  *(float *)(*(int *)(param_1 + 0xb4) + 4 + (uint)*(ushort *)(param_1 + 0x1a) * 8) = fVar1;

  return;

}
