// =============================================================================
// FUN_0048a330
// -----------------------------------------------------------------------------
// Stable ID: aa_0048a330
// Address:   0x0048a330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048a330 @ 0x0048a330
// Stable ID: aa_0048a330
// Embedded strings (evidence for future rename):
//   - "SetNotebookLEDSettings() - Enter"
//   - "ClrZone1 = %d, ClrZone2 = %d, ClrZone3 = %d, ClrZone4 = %d, IntLevel = %d\n"
//   - "SetNotebookLEDSettings() - Exit (Sucess)"
//   - "SetLEDSettings() - Exit(Failure)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×2, for×1, if×1.
//  - Notable callees: FUN_0056f570×4, Exit×2, SetNotebookLEDSettings×2, CONCAT11, CONCAT21, CONCAT31, FUN_0048a330, FUN_0048ab30.
//  - Strings: "SetNotebookLEDSettings() - Enter"; "SetNotebookLEDSettings() - Exit (Sucess)"; "SetLEDSettings() - Exit(Failure)".
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

uint32_t /* width from decompiler */ FUN_0048a330(uint8_t *param_1,uint param_2)



{

  uint8_t uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ local_2c;

  uint local_28;

  uint local_24;

  uint local_20;

  int local_18;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_0056f570("SetNotebookLEDSettings() - Enter");

  uVar1 = param_1[2];

  puVar3 = &local_2c;

  for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  local_4 = 0;

  local_2c._0_2_ = 4;

  local_2c._2_2_ = 6;

  FUN_0056f570("ClrZone1 = %d, ClrZone2 = %d, ClrZone3 = %d, ClrZone4 = %d, IntLevel = %d\n",

               *param_1,param_1[1],uVar1,param_1[3],param_1[4]);

  local_28 = local_28 | CONCAT31(CONCAT21(CONCAT11(param_1[4],param_1[2]),param_1[1]),*param_1);

  local_20 = local_20 | (byte)param_1[3];

  local_24 = param_2 & 1;

  iVar2 = FUN_0048ab30(&local_2c,0,0);

  if ((iVar2 != 0) && (local_18 == 0)) {

    FUN_0056f570("SetNotebookLEDSettings() - Exit (Sucess)");

    return 1;

  }

  FUN_0056f570("SetLEDSettings() - Exit(Failure)");

  return 0;

}
