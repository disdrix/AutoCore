// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f2df0
// -----------------------------------------------------------------------------
// Stable ID: aa_005f2df0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x005f2df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper. Evidence string: "\r._". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "\r._"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_005f2d70, FUN_005f2df0, _atoi64, builtin_strncpy.
//  - Strings: "\r._".
//  - Return sites: 1.

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

longlong Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f2df0(void)



{

  int *in_EAX;

  int iVar1;

  int iVar2;

  longlong lVar3;

  char acStack_110 [8];

  

  acStack_110[4] = -1;

  acStack_110[5] = '-';

  acStack_110[6] = '_';

  acStack_110[7] = '\0';

  FUN_005f2d70();

  acStack_110[4] = -1;

  acStack_110[5] = '\0';

  acStack_110[6] = '\0';

  acStack_110[7] = '\0';

  iVar2 = 0;

  builtin_strncpy(acStack_110,"\r._",4);

  (**(code **)(*in_EAX + 0x14))();

  acStack_110[0] = -1;

  acStack_110[1] = '\0';

  acStack_110[2] = '\0';

  acStack_110[3] = '\0';

  iVar1 = (**(code **)(*in_EAX + 8))(&stack0xfffffefc);

  if (((iVar1 != 0) &&

      (((('/' < acStack_110[4] && (acStack_110[4] < ':')) || (acStack_110[4] == '+')) ||

       (acStack_110[4] == '-')))) && (iVar2 = 1, 1 < iVar1)) {

    do {

      if ((acStack_110[iVar2 + 4] < '0') || ('9' < acStack_110[iVar2 + 4])) break;

      iVar2 = iVar2 + 1;

    } while (iVar2 < iVar1);

  }

  (**(code **)(*in_EAX + 0x18))();

  (**(code **)(*in_EAX + 0xc))(iVar2);

  lVar3 = -1;

  acStack_110[iVar2] = '\0';

  if (0 < iVar2) {

    lVar3 = _atoi64(acStack_110);

  }

  return lVar3;

}
