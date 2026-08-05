// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvDestroyObject_007a6310
// -----------------------------------------------------------------------------
// Stable ID: aa_007a6310
// Callee of Named_CalleeOf_Client_RecvDestroyObject
// Address:   0x007a6310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvDestroyObject: packet/network helper. Evidence string: "languageFR%d.pak". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "languageFR%d.pak"
//   - "languageDE%d.pak"
//   - "languageUK%d.pak"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: sprintf×3, FUN_007a6260, FUN_007a6310, fclose, fopen, fread, fseek.
//  - Strings: "languageFR%d.pak"; "languageDE%d.pak"; "languageUK%d.pak".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvDestroyObject
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Client_RecvDestroyObject_007a6310(int param_1,int param_2,int param_3)



{

  int iVar1;

  int in_EAX;

  FILE *_File;

  char local_40 [64];

  

  if (param_2 == 1) {

    sprintf(local_40,"languageFR%d.pak",param_3);

  }

  else if (param_2 == 2) {

    sprintf(local_40,"languageDE%d.pak",param_3);

  }

  else {

    if (param_2 != 3) {

      return;

    }

    sprintf(local_40,"languageUK%d.pak",param_3);

  }

  _File = fopen(local_40,"rb");

  if ((_File != (FILE *)0x0) && (in_EAX != -1)) {

    iVar1 = *(int *)(param_1 + (param_3 + 0xc + param_2 * 2) * 4) + in_EAX * 0x14;

    fseek(_File,*(int *)(param_1 + 0x94 + (param_3 + param_2 * 2) * 4) + *(int *)(iVar1 + 4),0);

    FUN_007a6260();

    fread(*(void **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4),*(size_t *)(iVar1 + 8),1,_File);

    fclose(_File);

  }

  return;

}
