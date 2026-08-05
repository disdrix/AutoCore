// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f2e90
// -----------------------------------------------------------------------------
// Stable ID: aa_005f2e90
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x005f2e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_005f2d70, FUN_005f2e90, atof.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
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

float10 Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f2e90(void)



{

  char cVar1;

  int *in_EAX;

  int iVar2;

  int iVar3;

  double dVar4;

  char acStack_110 [8];

  

  acStack_110[4] = -0x61;

  acStack_110[5] = '.';

  acStack_110[6] = '_';

  acStack_110[7] = '\0';

  FUN_005f2d70();

  acStack_110[4] = -1;

  acStack_110[5] = '\0';

  acStack_110[6] = '\0';

  acStack_110[7] = '\0';

  iVar3 = 0;

  acStack_110[0] = -0x53;

  acStack_110[1] = '.';

  acStack_110[2] = '_';

  acStack_110[3] = '\0';

  (**(code **)(*in_EAX + 0x14))();

  acStack_110[0] = -1;

  acStack_110[1] = '\0';

  acStack_110[2] = '\0';

  acStack_110[3] = '\0';

  iVar2 = (**(code **)(*in_EAX + 8))(&stack0xfffffefc);

  if ((iVar2 != 0) &&

     ((((('/' < acStack_110[4] && (acStack_110[4] < ':')) || (acStack_110[4] == '+')) ||

       (((acStack_110[4] == '-' || (acStack_110[4] == '.')) || (acStack_110[4] == ',')))) &&

      (iVar3 = 1, 1 < iVar2)))) {

    do {

      cVar1 = acStack_110[iVar3 + 4];

      if (((cVar1 < '0') || ('9' < cVar1)) &&

         ((cVar1 != '+' &&

          ((((cVar1 != '-' && (cVar1 != 'E')) && (cVar1 != 'e')) &&

           ((cVar1 != '.' && (cVar1 != ',')))))))) break;

      iVar3 = iVar3 + 1;

    } while (iVar3 < iVar2);

  }

  (**(code **)(*in_EAX + 0x18))();

  (**(code **)(*in_EAX + 0xc))(iVar3);

  acStack_110[iVar3] = '\0';

  if (iVar3 < 1) {

    return (float10)DAT_00aaa668;

  }

  dVar4 = atof(acStack_110);

  return (float10)dVar4;

}
