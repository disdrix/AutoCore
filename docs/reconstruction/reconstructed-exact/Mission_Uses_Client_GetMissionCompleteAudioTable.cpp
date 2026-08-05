// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×2.
//  - Notable callees: CONCAT31, CVOGReaction_RandomUnitScalar, Client_GetMissionCompleteAudioTable, FUN_004b0f80, FUN_004b6980, FUN_004b7e50, FUN_004e9530, FUN_00725a70.
//  - Return sites: 2.

// =============================================================================
// Mission_Uses_Client_GetMissionCompleteAudioTable
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "Client_GetMissionCompleteAudioTable"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004b0f80 clean capture (not modernized).
//
// Address:  0x004b0f80  (autoassault.exe, image base 0x400000)
// Stable:   aa_004b0f80
// Stable ID: aa_004b0f80
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004b0f80_*.md
//           Original Ghidra symbol: FUN_004b0f80
//
// Exactness: Body mirrors reconstructed-exact/FUN_004b0f80*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_Uses_Client_GetMissionCompleteAudioTable
// -----------------------------------------------------------------------------
// Stable ID: aa_004b0f80
// Address:   0x004b0f80  (autoassault.exe, image base 0x400000)
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

uint __thiscall Mission_Uses_Client_GetMissionCompleteAudioTable(int *param_1,char param_2)



{

  char cVar1;

  ushort uVar2;

  int *piVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint8_t local_20 [28];

  

  if (*(int *)(*param_1 + 4) == 0) {

    pcVar4 = (char *)(param_1[1] + 0x1ea);

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    if (pcVar4 != (char *)(param_1[1] + 0x1eb)) {

      uVar5 = FUN_004e9530(local_20,param_1 + 0x5e);

      iVar6 = param_1[1] + 0x1ea;

      Client_GetMissionCompleteAudioTable(iVar6,uVar5);

      FUN_00725a70(iVar6,uVar5);

    }

  }

  else {

    iVar6 = param_1[1];

    pcVar4 = (char *)(iVar6 + 0x1ea);

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    if ((pcVar4 != (char *)(iVar6 + 0x1eb)) && (*(char *)(iVar6 + 0x2ee) == '\0')) {

      FUN_004b7e50(0,0,param_1[1] + 0x1ea,param_1[0x5e],param_1[0x5f],param_1[0x60]);

      *(uint8_t *)(param_1[1] + 0x2ee) = 1;

    }

    if ((*(byte *)(param_1[1] + 0x2ef) & 1) != 0) {

      FUN_004b6980();

    }

  }

  piVar3 = *(int **)(param_1[1] + 0x2f4);

  param_1[1] = (int)piVar3;

  if (((param_2 != '\0') && (piVar3 == (int *)(*param_1 + 0x14))) &&

     (*(char *)(*param_1 + 0x7fb) == '\0')) {

    return (uint)piVar3 & 0xffffff00;

  }

  iVar6 = *piVar3;

  param_1[0x5c] = iVar6;

  if ((*(byte *)(param_1[1] + 0x1e4) & 4) != 0) {

    iVar6 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar6 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

    }

    uVar2 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

    *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

    iVar6 = param_1[1];

    param_1[0x5c] =

         (int)((float)uVar2 * *(float *)(iVar6 + 4) * DAT_00aaa638 + (float)param_1[0x5c]);

  }

  param_1[0x5d] = param_1[0x5c];

  return CONCAT31((int3)((uint)iVar6 >> 8),1);

}
