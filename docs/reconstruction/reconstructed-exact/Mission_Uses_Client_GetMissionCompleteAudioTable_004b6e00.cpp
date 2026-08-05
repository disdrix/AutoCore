// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable, FUN_004b6e00, FUN_00723b20.
//  - Return sites: 1.

// =============================================================================
// Mission_Uses_Client_GetMissionCompleteAudioTable_004b6e00
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "Client_GetMissionCompleteAudioTable"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004b6e00 clean capture (not modernized).
//
// Address:  0x004b6e00  (autoassault.exe, image base 0x400000)
// Stable:   aa_004b6e00
// Stable ID: aa_004b6e00
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004b6e00_*.md
//           Original Ghidra symbol: FUN_004b6e00
//
// Exactness: Body mirrors reconstructed-exact/FUN_004b6e00*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_Uses_Client_GetMissionCompleteAudioTable_004b6e00
// -----------------------------------------------------------------------------
// Stable ID: aa_004b6e00
// Address:   0x004b6e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "Client_GetMissionCompleteAudioTable"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Mission_Uses_Client_GetMissionCompleteAudioTable_004b6e00(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  if ((*(int *)(param_1 + 0x1f0) != 0) &&

     (piVar1 = (int *)**(int **)(param_1 + 0x1ec), piVar1 != *(int **)(param_1 + 0x1ec))) {

    do {

      iVar5 = piVar1[2];

      uVar4 = 0;

      uVar3 = 0xffffffff;

      uVar2 = 0xffffffff;

      uVar6 = param_2;

      Client_GetMissionCompleteAudioTable(0xffffffff,0xffffffff,0,iVar5,param_2);

      FUN_00723b20(uVar2,uVar3,uVar4,iVar5,uVar6);

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(param_1 + 0x1ec));

  }

  return;

}
