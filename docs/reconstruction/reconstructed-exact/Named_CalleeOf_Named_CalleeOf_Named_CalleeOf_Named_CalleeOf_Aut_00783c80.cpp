// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut_00783c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00783c80
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_No_authentica
// Address:   0x00783c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_No_authentica: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: return×5, if×2, switch×1.
//  - Notable callees: htonl×3, FUN_00783c80.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_No_authentica
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

short * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut_00783c80(short *param_1,short param_2,uint32_t /* width from decompiler */ param_3,short param_4)



{

  u_long uVar1;

  

  param_1[1] = param_4;

  *param_1 = param_2;

  if ((param_2 == 0) || (param_2 == 1)) {

    param_1[8] = 0;

    param_1[9] = 0;

    param_1[6] = 0;

    param_1[7] = 0;

    param_1[4] = 0;

    param_1[5] = 0;

    switch(param_3) {

    case 0:

      param_1[2] = 0;

      param_1[3] = 0;

      return param_1;

    case 1:

      uVar1 = htonl(0x7f000001);

      *(u_long *)(param_1 + 2) = uVar1;

      return param_1;

    case 2:

      uVar1 = htonl(0xffffffff);

      *(u_long *)(param_1 + 2) = uVar1;

      return param_1;

    case 3:

      uVar1 = htonl(0);

      *(u_long *)(param_1 + 2) = uVar1;

    }

  }

  else if (param_2 == 2) {

    param_1[4] = -1;

    param_1[5] = -1;

    param_1[6] = -1;

    param_1[7] = -1;

    param_1[8] = -1;

    param_1[9] = -1;

    param_1[2] = -1;

    param_1[3] = -1;

    return param_1;

  }

  return param_1;

}
