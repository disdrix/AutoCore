// =============================================================================
// FUN_00890960
// -----------------------------------------------------------------------------
// Stable ID: aa_00890960
// Address:   0x00890960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00890960 @ 0x00890960
// Stable ID: aa_00890960
// Embedded strings (evidence for future rename):
//   - "Minimize"
//   - "Maximize"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_008908c0×2, FUN_00890960.
//  - Strings: "Minimize"; "Maximize".
//  - Return sites: 2.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00890960(char param_1)



{

  char in_AL;

  uint32_t /* width from decompiler */ *puVar1;

  int *unaff_ESI;

  uint8_t local_8 [8];

  

  if ((param_1 != '\0') || (DAT_00d1790c != in_AL)) {

    DAT_00d1790c = in_AL;

    if (in_AL == '\0') {

      *(uint8_t *)((int)unaff_ESI + 0xc5) = 1;

      (**(code **)(*unaff_ESI + 0x114))(&DAT_00d178fc);

      if ((int *)unaff_ESI[0x14e] != (int *)0x0) {

        (**(code **)(*(int *)unaff_ESI[0x14e] + 0x308))("Minimize");

      }

    }

    else {

      *(uint8_t *)((int)unaff_ESI + 0xc5) = 0;

      puVar1 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_ESI + 0x120))(local_8,1,0);

      _DAT_00d178fc = *puVar1;

      _DAT_00d17900 = puVar1[1];

      (**(code **)(*unaff_ESI + 0x114))(&DAT_00d17904);

      if ((int *)unaff_ESI[0x14e] != (int *)0x0) {

        (**(code **)(*(int *)unaff_ESI[0x14e] + 0x308))("Maximize");

        FUN_008908c0(unaff_ESI);

        return;

      }

    }

    FUN_008908c0(unaff_ESI);

  }

  return;

}
