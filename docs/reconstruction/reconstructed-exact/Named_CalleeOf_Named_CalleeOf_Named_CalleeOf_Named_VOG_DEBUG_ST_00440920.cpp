// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00440920
// -----------------------------------------------------------------------------
// Stable ID: aa_00440920
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00440920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×10, return×8.
//  - Notable callees: FUN_00441480×7, FUN_00440b20×6, FUN_00440920, FUN_004412b0, FUN_00441a20, FUN_00441a80.
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00440920(int param_1,int *param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint8_t local_8 [8];

  

  if (*(int *)(param_1 + 8) == 0) {

    FUN_00441480(unaff_ESI,1,unaff_EBX);

    return;

  }

  if (param_2 == (int *)**(int **)(param_1 + 4)) {

    cVar1 = FUN_00440b20();

    if (cVar1 != '\0') {

      FUN_00441480(unaff_ESI,1,unaff_EBX);

      return;

    }

  }

  else if (param_2 == *(int **)(param_1 + 4)) {

    cVar1 = FUN_00440b20();

    if (cVar1 != '\0') {

      FUN_00441480(unaff_ESI,0,unaff_EBX);

      return;

    }

  }

  else {

    cVar1 = FUN_00440b20();

    if (cVar1 != '\0') {

      FUN_00441a20();

      cVar1 = FUN_00440b20();

      if (cVar1 != '\0') {

        if (*(char *)(param_2[2] + 0x3d) == '\0') {

          FUN_00441480(unaff_ESI,1,unaff_EBX);

          return;

        }

        FUN_00441480(unaff_ESI,0,unaff_EBX);

        return;

      }

    }

    cVar1 = FUN_00440b20();

    if ((cVar1 != '\0') &&

       ((FUN_00441a80(), param_2 == *(int **)(param_1 + 4) ||

        (cVar1 = FUN_00440b20(), cVar1 != '\0')))) {

      if (*(char *)(param_2[2] + 0x3d) == '\0') {

        FUN_00441480(unaff_ESI,1,unaff_EBX);

        return;

      }

      FUN_00441480(unaff_ESI,0,unaff_EBX);

      return;

    }

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_004412b0(param_1,local_8);

  *unaff_ESI = *puVar2;

  return;

}
