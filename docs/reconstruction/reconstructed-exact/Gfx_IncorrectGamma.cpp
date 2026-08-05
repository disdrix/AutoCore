// =============================================================================
// Gfx_IncorrectGamma
// -----------------------------------------------------------------------------
// Stable ID: aa_0047b510
// Address:   0x0047b510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias Gfx_IncorrectGamma for FUN_0047b510 @ 0x0047b510
// Stable ID: aa_0047b510
// Embedded strings (evidence for future rename):
//   - "incorrect gamma=(%d/100000)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×9, return×6.
//  - Notable callees: FUN_00476d60×7, FUN_0047a480×4, FUN_00470570, FUN_00476cc0, FUN_0047a420, Gfx_IncorrectGamma, fprintf.
//  - Strings: "incorrect gamma=(%d/100000)\n".
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "incorrect gamma=(%d/100000)
"
 * Domain alias of FUN_0047b510 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Gfx_IncorrectGamma(int param_1,int param_2)



{

  uint uVar1;

  int in_EAX;

  int iVar2;

  byte local_1;

  

  uVar1 = *(uint *)(param_1 + 0x68);

  if ((uVar1 & 1) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0(param_1);

  }

  if ((uVar1 & 4) != 0) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if ((uVar1 & 2) != 0) {

    FUN_00476d60();

  }

  if ((param_2 != 0) && ((*(byte *)(param_2 + 9) & 8) != 0)) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if (in_EAX != 1) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  FUN_0047a420();

  iVar2 = FUN_0047a480();

  if (iVar2 == 0) {

    if (3 < local_1) {

      FUN_00476d60();

      return;

    }

    if (((*(byte *)(param_2 + 8) & 1) != 0) &&

       ((*(int *)(param_2 + 0xfc) < 45000 || (46000 < *(int *)(param_2 + 0xfc))))) {

      FUN_00476d60();

      fprintf((FILE *)(_iob_exref + 0x40),"incorrect gamma=(%d/100000)\n",

              *(uint32_t /* width from decompiler */ *)(param_1 + 0x234));

    }

    if (((*(byte *)(param_2 + 8) & 4) != 0) &&

       (((((*(int *)(param_2 + 0x100) < 0x763e || (0x7e0e < *(int *)(param_2 + 0x100))) ||

          (*(int *)(param_2 + 0x104) < 0x7c9c)) ||

         ((((0x846c < *(int *)(param_2 + 0x104) || (*(int *)(param_2 + 0x108) < 63000)) ||

           ((65000 < *(int *)(param_2 + 0x108) ||

            ((*(int *)(param_2 + 0x10c) < 32000 || (34000 < *(int *)(param_2 + 0x10c))))))) ||

          (*(int *)(param_2 + 0x110) < 29000)))) ||

        (((((31000 < *(int *)(param_2 + 0x110) || (*(int *)(param_2 + 0x114) < 59000)) ||

           (61000 < *(int *)(param_2 + 0x114))) ||

          ((*(int *)(param_2 + 0x118) < 14000 || (16000 < *(int *)(param_2 + 0x118))))) ||

         ((*(int *)(param_2 + 0x11c) < 5000 || (7000 < *(int *)(param_2 + 0x11c))))))))) {

      FUN_00476d60();

    }

    FUN_00470570(local_1);

  }

  return;

}
