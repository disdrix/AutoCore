// =============================================================================
// FUN_0092da70
// -----------------------------------------------------------------------------
// Stable ID: aa_0092da70
// Address:   0x0092da70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092da70 @ 0x0092da70
// Stable ID: aa_0092da70
// Embedded strings (evidence for future rename):
//   - "%d: %d,%d;\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: fprintf×3, FUN_0092da70, fclose, fopen.
//  - Strings: "%d: %d,%d;\n".
//  - Return sites: 1.

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

void FUN_0092da70(int param_1)



{

  char *in_EAX;

  FILE *_File;

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if ((in_EAX != (char *)0x0) && (_File = fopen(in_EAX,"w"), _File != (FILE *)0x0)) {

    iVar1 = 0;

    piVar2 = (int *)(param_1 + 0x1030);

    do {

      if (*piVar2 != 0) {

        (**(code **)(*(int *)*piVar2 + 0x128))(&local_8);

        fprintf(_File,"%d: %d,%d;\n",iVar1,local_8,uStack_4);

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 1;

    } while (iVar1 < 0x3a);

    fprintf(_File,"%d: %d,%d;\n",500,0,DAT_00af9214);

    fprintf(_File,"%d: %d,%d;\n",0x1f5,0,DAT_00af9210);

    fclose(_File);

  }

  return;

}
