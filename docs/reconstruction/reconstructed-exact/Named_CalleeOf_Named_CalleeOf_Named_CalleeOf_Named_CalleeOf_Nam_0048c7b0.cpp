// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0048c7b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048c7b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI
// Address:   0x0048c7b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, while×1, if×1.
//  - Notable callees: FUN_0048a940, FUN_0048b890, FUN_0048c7b0, FUN_0048d0a0, fclose, fopen.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI
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

uint8_t __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0048c7b0(int param_1,char *param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  uint8_t uVar2;

  char *pcVar3;

  FILE *_File;

  

  pcVar3 = param_2;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  FUN_0048a940(param_2,(int)pcVar3 - (int)(param_2 + 1));

  _File = fopen((char *)(*(int *)(param_1 + 0x20) + 8),"rb");

  if (_File != (FILE *)0x0) {

    uVar2 = FUN_0048b890(_File,param_3);

    fclose(_File);

    return uVar2;

  }

  FUN_0048d0a0(2,0,0,0);

  return 0;

}
