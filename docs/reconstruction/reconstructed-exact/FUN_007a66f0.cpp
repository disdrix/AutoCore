// =============================================================================
// FUN_007a66f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a66f0
// Address:   0x007a66f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a66f0 @ 0x007a66f0
// Stable ID: aa_007a66f0
// Embedded strings (evidence for future rename):
//   - ");

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, do×2, while×2, goto×1.
//  - Notable callees: sprintf×4, fopen×2, fread×2, FUN_007a66f0, fclose.
//  - Strings: "languageFR%d.pak"; "languageDE%d.pak"; "languageUK%d.pak".
//  - Return sites: 3.

      iVar1 = *(int *)(unaff_ESI + 0x2c);

      if (iVar1 == 1) {

        sprintf(lo"
//   - ",iVar4);

LAB_007a67ce:

        _File = fopen(local_40,"
//   - "languageDE%d.pak"
//   - "languageUK%d.pak"
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

void FUN_007a66f0(void)



{

  int iVar1;

  int *piVar2;

  int in_EAX;

  FILE *_File;

  void *pvVar3;

  int unaff_ESI;

  int iVar4;

  size_t local_44;

  char local_40 [64];

  

  *(uint8_t *)(unaff_ESI + 0xc4) = 0x2c;

  if ((-1 < in_EAX) && (in_EAX < 5)) {

    *(int *)(unaff_ESI + 0x2c) = in_EAX;

    iVar4 = 0;

    do {

      pvVar3 = *(void **)(unaff_ESI + (iVar4 + 0xc + *(int *)(unaff_ESI + 0x2c) * 2) * 4);

      if (pvVar3 != (void *)0x0) {

        operator_delete__(pvVar3);

      }

      iVar1 = iVar4 + 0xc;

      iVar4 = iVar4 + 1;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + (iVar1 + *(int *)(unaff_ESI + 0x2c) * 2) * 4) = 0;

    } while (iVar4 < 2);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x58 + *(int *)(unaff_ESI + 0x2c) * 4) = 0;

    iVar4 = 0;

    do {

      sprintf(local_40,"");

      iVar1 = *(int *)(unaff_ESI + 0x2c);

      if (iVar1 == 1) {

        sprintf(local_40,"languageFR%d.pak",iVar4);

LAB_007a67ce:

        _File = fopen(local_40,"rb");

        *(uint8_t *)(unaff_ESI + 0xc4) = 0x20;

      }

      else {

        if (iVar1 == 2) {

          sprintf(local_40,"languageDE%d.pak",iVar4);

          goto LAB_007a67ce;

        }

        if (iVar1 != 3) {

          return;

        }

        sprintf(local_40,"languageUK%d.pak",iVar4);

        _File = fopen(local_40,"rb");

        *(uint8_t *)(unaff_ESI + 0xc4) = 0x2c;

      }

      if (_File == (FILE *)0x0) {

        return;

      }

      fread(&local_44,4,1,_File);

      if (0 < (int)local_44) {

        pvVar3 = operator_new__(local_44 * 0x14);

        *(void **)(unaff_ESI + (iVar4 + 0xc + *(int *)(unaff_ESI + 0x2c) * 2) * 4) = pvVar3;

        fread(*(void **)(unaff_ESI + (iVar4 + 0xc + *(int *)(unaff_ESI + 0x2c) * 2) * 4),local_44,

              0x14,_File);

        *(size_t *)(unaff_ESI + 0x94 + (iVar4 + *(int *)(unaff_ESI + 0x2c) * 2) * 4) =

             local_44 * 0x14 + 4;

      }

      fclose(_File);

      piVar2 = (int *)(unaff_ESI + 0x58 + *(int *)(unaff_ESI + 0x2c) * 4);

      *piVar2 = *piVar2 + 1;

      iVar4 = iVar4 + 1;

    } while (iVar4 < 2);

  }

  return;

}
