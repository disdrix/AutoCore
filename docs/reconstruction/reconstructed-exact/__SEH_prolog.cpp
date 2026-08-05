// =============================================================================
// __SEH_prolog
// -----------------------------------------------------------------------------
// Stable ID: aa_00489c64
// Address:   0x00489c64  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    __SEH_prolog
   
   Library: Visual Studio */

void __SEH_prolog(uint32_t /* width from decompiler */ param_1,int param_2)

{
  uint32_t /* width from decompiler */ unaff_EBX;
  uint32_t /* width from decompiler */ unaff_ESI;
  uint32_t /* width from decompiler */ unaff_EDI;
  uint32_t /* width from decompiler */ unaff_retaddr;
  uint32_t /* width from decompiler */ auStack_18 [4];
  uint8_t local_8 [8];
  
  param_2 = -param_2;
  *(uint32_t /* width from decompiler */ *)((int)auStack_18 + param_2 + 0xc) = unaff_EBX;
  *(uint32_t /* width from decompiler */ *)((int)auStack_18 + param_2 + 8) = unaff_ESI;
  *(uint32_t /* width from decompiler */ *)((int)auStack_18 + param_2 + 4) = unaff_EDI;
  *(uint32_t /* width from decompiler */ *)((int)auStack_18 + param_2) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}
