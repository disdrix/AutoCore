// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_008572f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008572f0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x008572f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: return×2, goto×2, if×1, switch×1.
//  - Notable callees: FUN_008572f0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

uint Named_CalleeOf_Named_VOG_DEBUG_STOP_008572f0(uint8_t param_1,int *param_2)



{

  uint in_EAX;

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  if (param_2 == (int *)0x0) {

switchD_00857315_caseD_6:

    return in_EAX & 0xffffff00;

  }

  in_EAX = 0;

  switch(param_1) {

  case 3:

    iVar1 = 6;

    iVar2 = 1;

    break;

  case 4:

    iVar1 = 7;

    iVar2 = 0;

    break;

  case 5:

    iVar1 = 3;

    iVar2 = 0;

    break;

  default:

    goto switchD_00857315_caseD_6;

  case 8:

    iVar2 = 0;

    goto LAB_0085738e;

  case 10:

    iVar1 = 4;

    iVar2 = 0;

    break;

  case 0xb:

    iVar1 = 5;

    iVar2 = 1;

    break;

  case 0xc:

    iVar1 = 5;

    iVar2 = 0;

    break;

  case 0xd:

    iVar1 = 7;

    iVar2 = 1;

    break;

  case 0xe:

    iVar1 = 6;

    iVar2 = 0;

    break;

  case 0xf:

    iVar1 = 0;

    iVar2 = 1;

    break;

  case 0x10:

    iVar2 = 1;

LAB_0085738e:

    iVar1 = 1;

    break;

  case 0x11:

    iVar1 = 0;

    iVar2 = 0;

    break;

  case 100:

    iVar1 = 2;

    iVar2 = 0;

  }

  iVar4 = (iVar2 + 1) * DAT_00afdb20;

  iVar2 = DAT_00afdb20 * iVar2;

  iVar3 = (iVar1 + 1) * DAT_00afdb1c;

  *param_2 = DAT_00afdb1c * iVar1;

  param_2[3] = iVar4;

  param_2[2] = iVar3;

  param_2[1] = iVar2;

  return 1;

}
