// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: CONCAT31, Client_GetMissionCompleteAudioTable, FUN_004b6a00, FUN_00727140.
//  - Return sites: 1.

// =============================================================================
// Mission_Uses_Client_GetMissionCompleteAudioTable_004b6a00
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "Client_GetMissionCompleteAudioTable"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004b6a00 clean capture (not modernized).
//
// Address:  0x004b6a00  (autoassault.exe, image base 0x400000)
// Stable:   aa_004b6a00
// Stable ID: aa_004b6a00
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004b6a00_*.md
//           Original Ghidra symbol: FUN_004b6a00
//
// Exactness: Body mirrors reconstructed-exact/FUN_004b6a00*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_Uses_Client_GetMissionCompleteAudioTable_004b6a00
// -----------------------------------------------------------------------------
// Stable ID: aa_004b6a00
// Address:   0x004b6a00  (autoassault.exe, image base 0x400000)
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

void __fastcall Mission_Uses_Client_GetMissionCompleteAudioTable_004b6a00(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  

  piVar3 = (int *)**(int **)(param_1 + 0x1ec);

  if (piVar3 != *(int **)(param_1 + 0x1ec)) {

    do {

      iVar4 = piVar3[2];

      iVar7 = *(int *)(iVar4 + 0x104);

      if (((0x13 < iVar7) && (iVar7 < 0x19)) && (iVar1 = *(int *)(param_1 + 0x10), iVar1 != 0)) {

        uVar10 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x134);

        uVar9 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x118);

        uVar2 = CONCAT31((int3)((uint)uVar9 >> 8),*(uint8_t *)(iVar4 + 0x10b));

        uVar8 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x11c);

        uVar6 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164);

        uVar5 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x160);

        Client_GetMissionCompleteAudioTable(iVar4,uVar5,uVar6,iVar7,uVar8,uVar2,uVar9,uVar10);

        FUN_00727140(iVar4,uVar5,uVar6,iVar7,uVar8,uVar2,uVar9,uVar10);

      }

      piVar3 = (int *)*piVar3;

    } while (piVar3 != (int *)*(int *)(param_1 + 0x1ec));

  }

  return;

}
