// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00546460, _snprintf, _unlink.
//  - Strings: "%s%S.xml"; "..\\missions\\".
//  - Return sites: 1.

// =============================================================================
// Mission_missions_00546460
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "..\\missions\\"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_00546460 clean capture (not modernized).
//
// Address:  0x00546460  (autoassault.exe, image base 0x400000)
// Stable:   aa_00546460
// Stable ID: aa_00546460
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_00546460_*.md
//           Original Ghidra symbol: FUN_00546460
//
// Exactness: Body mirrors reconstructed-exact/FUN_00546460*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_missions_00546460
// -----------------------------------------------------------------------------
// Stable ID: aa_00546460
// Address:   0x00546460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "..\missions\"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Mission_missions_00546460(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char local_110 [2];

  uint32_t /* width from decompiler */ local_10e [66];

  

  local_110[0] = '\0';

  local_110[1] = '\0';

  puVar2 = local_10e;

  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  *(uint16_t *)puVar2 = 0;

  _snprintf(local_110,0x104,"%s%S.xml","..\\missions\\",param_1 + 4);

  _unlink(local_110);

  return;

}
