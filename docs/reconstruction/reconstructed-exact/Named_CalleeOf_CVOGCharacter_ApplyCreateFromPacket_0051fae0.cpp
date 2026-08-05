// =============================================================================
// Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket_0051fae0
// -----------------------------------------------------------------------------
// Stable ID: aa_0051fae0
// Callee of CVOGCharacter_ApplyCreateFromPacket
// Address:   0x0051fae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGCharacter_ApplyCreateFromPacket: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0051fae0, strncpy.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGCharacter_ApplyCreateFromPacket
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

void __thiscall Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket_0051fae0(int param_1,char *param_2)



{

  char cVar1;

  char *pcVar2;

  char *_Dest;

  

  if (*(void **)(param_1 + 0x64c) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x64c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x64c) = 0;

  pcVar2 = param_2;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  pcVar2 = pcVar2 + (1 - (int)(param_2 + 1));

  if (pcVar2 != (char *)0x0) {

    _Dest = operator_new__((uint)pcVar2);

    *(char **)(param_1 + 0x64c) = _Dest;

    strncpy(_Dest,param_2,(size_t)pcVar2);

  }

  return;

}
