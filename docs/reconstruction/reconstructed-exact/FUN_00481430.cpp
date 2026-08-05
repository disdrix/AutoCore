// =============================================================================
// FUN_00481430
// -----------------------------------------------------------------------------
// Stable ID: aa_00481430
// Address:   0x00481430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00481430 @ 0x00481430
// Stable ID: aa_00481430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×10, return×7, goto×1.
//  - Notable callees: FUN_00481290×6, FUN_00481750×6, FUN_0044dc00, FUN_0044f480, FUN_00481430, FUN_004815a0.
//  - Return sites: 7.

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

void __thiscall FUN_00481430(int param_1,int *param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  if (*(int *)(param_1 + 8) == 0) {

    FUN_00481750(unaff_ESI,1,in_EAX);

    return;

  }

  if (param_2 == (int *)**(int **)(param_1 + 4)) {

    cVar1 = FUN_00481290();

    if (cVar1 != '\0') {

LAB_00481474:

      FUN_00481750(unaff_ESI,1,in_EAX);

      return;

    }

  }

  else if (param_2 == *(int **)(param_1 + 4)) {

    cVar1 = FUN_00481290();

    if (cVar1 != '\0') {

      FUN_00481750(unaff_ESI,0,in_EAX);

      return;

    }

  }

  else {

    cVar1 = FUN_00481290();

    if (cVar1 != '\0') {

      FUN_0044f480();

      cVar1 = FUN_00481290();

      if (cVar1 != '\0') {

        if (*(char *)(param_2[2] + 0x25) != '\0') {

          FUN_00481750(unaff_ESI,0,in_EAX);

          return;

        }

        goto LAB_00481474;

      }

    }

    cVar1 = FUN_00481290();

    if ((cVar1 != '\0') &&

       ((FUN_0044dc00(), param_2 == *(int **)(param_1 + 4) ||

        (cVar1 = FUN_00481290(), cVar1 != '\0')))) {

      if (*(char *)(param_2[2] + 0x25) == '\0') {

        FUN_00481750(unaff_ESI,1,in_EAX);

        return;

      }

      FUN_00481750(unaff_ESI,0,in_EAX);

      return;

    }

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_004815a0(param_1);

  *unaff_ESI = *puVar2;

  return;

}
