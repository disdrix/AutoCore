// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0073ba70, FUN_0076cec0, vog_LogMessage.
//  - Strings: "gfxFontFactory: %i references to font %s not released"; "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontFactory.cpp".
//  - Return sites: 1.

// =============================================================================
// Named_gfxFontFactory_0073ba70
// -----------------------------------------------------------------------------
// Stable ID: aa_0073ba70
// Address:   0x0073ba70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxFontFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_gfxFontFactory_0073ba70(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  int unaff_EDI;

  uint32_t /* width from decompiler */ local_4;

  

  piVar4 = (int *)**(int **)(unaff_EDI + 8);

  local_4 = param_1;

  if (piVar4 != *(int **)(unaff_EDI + 8)) {

    do {

      iVar1 = piVar4[0xb];

      if (1 < *(int *)(iVar1 + 4)) {

        if (*(uint *)(iVar1 + 0x30) < 0x10) {

          iVar2 = iVar1 + 0x1c;

        }

        else {

          iVar2 = *(int *)(iVar1 + 0x1c);

        }

        uVar3 = FUN_0076cec0(&local_4,"gfxFontFactory: %i references to font %s not released",

                             *(int *)(iVar1 + 4) + -1,iVar2);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontFactory.cpp",0x43,2,

                       uVar3);

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)*(int *)(unaff_EDI + 8));

  }

  return;

}
