// =============================================================================
// Net_Ghosted_Stealthed
// -----------------------------------------------------------------------------
// Stable ID: aa_00582350
// Address:   0x00582350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Net_Ghosted_Stealthed @ 0x00582350
// Stable ID: aa_00582350
// Embedded strings (evidence for future rename):
//   - "Ghosted = %d  Stealthed = %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_005134e0×2, Net_Ghosted_Stealthed, FUN_007a4480.
//  - Strings: "Ghosted = %d  Stealthed = %d".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Ghosted = %d  Stealthed = %d"
 * Domain alias of FUN_00582350 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Net_Ghosted_Stealthed(int *param_1)



{

  uint uVar1;

  char cVar2;

  uint8_t uVar3;

  

  if ((*(uint *)(*(int *)(param_1[1] + 4) + 0x180 + (int)param_1) >> 3 & 1) == 0) {

    cVar2 = FUN_005134e0();

    if (cVar2 == '\0') {

      (**(code **)(*param_1 + 0x18))(0);

      (**(code **)(*param_1 + 0x18))(1);

      return;

    }

  }

  uVar1 = *(uint *)(*(int *)(param_1[1] + 4) + 0x180 + (int)param_1);

  uVar3 = FUN_005134e0();

  FUN_007a4480(0xffffffff,"Ghosted = %d  Stealthed = %d",(byte)(uVar1 >> 3) & 1,uVar3);

  return;

}
