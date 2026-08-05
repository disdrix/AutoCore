// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00498740, FUN_00514320, FUN_007a4480, vog_LogMessage.
//  - Strings: ",0x14ae,2,

                   "; ");

    FUN_007a4480(0,".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00514320
// -----------------------------------------------------------------------------
// Stable ID: aa_00514320
// Address:   0x00514320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_VOG_DEBUG_STOP_00514320(uint param_1,uint32_t /* width from decompiler */ param_2,uint *param_3)



{

  uint *puVar1;

  

  puVar1 = param_3;

  if (((*(char *)(param_1 + 6) != '\0') && (-1 < (int)param_3[1])) &&

     ((0 < (int)param_3[1] || (0x7fffffff < *param_3)))) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGClonedObjectBase.cpp",0x14ae,2,

                   "Trying to write too large COID, bad things are about to happen");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  param_1 = *puVar1;

  FUN_00498740(param_2,&param_1);

  *puVar1 = param_1;

  puVar1[1] = (int)param_1 >> 0x1f;

  return;

}
