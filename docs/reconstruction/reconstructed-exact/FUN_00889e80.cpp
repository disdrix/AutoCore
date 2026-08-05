// =============================================================================
// FUN_00889e80
// -----------------------------------------------------------------------------
// Stable ID: aa_00889e80
// Address:   0x00889e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00889e80 @ 0x00889e80
// Stable ID: aa_00889e80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_00889e80.
//  - Return sites: 4.

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

uint __fastcall FUN_00889e80(int *param_1)



{

  char cVar1;

  uint uVar2;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    if (param_1[0x143] != 0) {

      cVar1 = (**(code **)(*(int *)param_1[0x143] + 0x3d8))();

      if (cVar1 != '\0') {

                    /* WARNING: Could not recover jumptable at 0x00889eb3. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        uVar2 = (**(code **)(*(int *)param_1[0x143] + 0x39c))();

        return uVar2;

      }

    }

    if (param_1[0x144] != 0) {

      cVar1 = (**(code **)(*(int *)param_1[0x144] + 0x3d8))();

      if (cVar1 != '\0') {

                    /* WARNING: Could not recover jumptable at 0x00889edd. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        uVar2 = (**(code **)(*(int *)param_1[0x144] + 0x39c))();

        return uVar2;

      }

    }

  }

  uVar2 = (**(code **)(*param_1 + 0x3d8))();

  if (((char)uVar2 != '\0') && (param_1[0x12e] != 0)) {

                    /* WARNING: Could not recover jumptable at 0x00889f03. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x39c))();

    return uVar2;

  }

  return uVar2 & 0xffffff00;

}
