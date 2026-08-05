// =============================================================================
// Named_scopemonresults_txt
// -----------------------------------------------------------------------------
// Stable ID: aa_00785f50
// Address:   0x00785f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_scopemonresults_txt @ 0x00785f50
// Stable ID: aa_00785f50
// Embedded strings (evidence for future rename):
//   - "../logs/scopemonresults.txt"
//   - "%s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, do×1, while×1.
//  - Notable callees: EnterCriticalSection, FUN_00785e40, Named_scopemonresults_txt, LeaveCriticalSection, OutputDebugStringA, fclose, fopen, fprintf.
//  - Strings: "a+t"; "../logs/scopemonresults.txt"; "%s\n".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "../logs/scopemonresults.txt"
 * Domain alias of FUN_00785f50 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void Named_scopemonresults_txt(int param_1)



{

  int iVar1;

  int *piVar2;

  FILE *_File;

  int iVar3;

  int unaff_EDI;

  char *_Filename;

  char *_Mode;

  uint32_t /* width from decompiler */ local_8004;

  CHAR local_8000 [32764];

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x785f5a;

  if (*(char *)(unaff_EDI + 0x175) != '\0') {

    local_8004 = 0;

    local_8000[0] = '\0';

    EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x58));

    iVar3 = *(int *)(unaff_EDI + 0x4c);

    if (iVar3 != *(int *)(unaff_EDI + 0x50)) {

      do {

        iVar1 = *(int *)(iVar3 + 4);

        piVar2 = *(int **)(iVar1 + 0x10);

        if (((piVar2 == (int *)0x0) || (*(int *)(iVar1 + 0x14) - (int)piVar2 >> 2 != 1)) ||

           (*(int *)(*piVar2 + 0x38) != 0)) {

          FUN_00785e40(local_8000,&local_8004,iVar1);

        }

        iVar3 = iVar3 + 0xc;

      } while (iVar3 != *(int *)(unaff_EDI + 0x50));

    }

    LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x58));

    if (param_1 == 0) {

      OutputDebugStringA(local_8000);

      return;

    }

    if (param_1 == 1) {

      _Filename = (char *)(unaff_EDI + 0x71);

      if (*(char *)(unaff_EDI + 0x71) == '\0') {

        _Mode = "a+t";

        _Filename = "../logs/scopemonresults.txt";

      }

      else {

        _Mode = "at";

      }

      _File = fopen(_Filename,_Mode);

      if (_File != (FILE *)0x0) {

        fprintf(_File,"%s\n",local_8000);

        fclose(_File);

      }

    }

  }

  return;

}
