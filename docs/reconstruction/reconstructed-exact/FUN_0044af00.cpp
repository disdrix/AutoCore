// =============================================================================
// FUN_0044af00
// -----------------------------------------------------------------------------
// Stable ID: aa_0044af00
// Address:   0x0044af00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044af00 @ 0x0044af00
// Stable ID: aa_0044af00
// Embedded strings (evidence for future rename):
//   - "..\\palantir/physics/phyCPConnection.h"
//   - "Connection point not found!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×9, return×3.
//  - Notable callees: FUN_0040d4b0, FUN_0044af00, vog_LogMessage.
//  - Strings: "..\\palantir/physics/phyCPConnection.h"; "Connection point not found!".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __fastcall FUN_0044af00(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  int *piVar2;

  int in_EAX;

  int *piVar3;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  if (in_EAX == -1) {

    *unaff_EDI = param_1;

    piVar3 = (int *)*unaff_EBX;

    if (piVar3 != (int *)0x0) {

      piVar2 = piVar3 + 1;

      *piVar2 = *piVar2 + -1;

      if (*piVar2 == 0) {

        (**(code **)(*piVar3 + 8))();

      }

    }

    *unaff_EBX = 0;

    return 0;

  }

  piVar3 = (int *)FUN_0040d4b0(in_EAX);

  if (piVar3 != (int *)0x0) {

    *unaff_EDI = param_1;

    piVar3 = (int *)*piVar3;

    if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

      (**(code **)(*piVar3 + 4))();

    }

    piVar2 = (int *)*unaff_EBX;

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

    *unaff_EBX = (int)piVar3;

    return 0;

  }

  vog_LogMessage("..\\palantir/physics/phyCPConnection.h",0x8f,3,"Connection point not found!");

  *unaff_EDI = 0;

  piVar3 = (int *)*unaff_EBX;

  if (piVar3 != (int *)0x0) {

    piVar2 = piVar3 + 1;

    *piVar2 = *piVar2 + -1;

    if (*piVar2 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

  }

  *unaff_EBX = 0;

  return 0xffffffff;

}
