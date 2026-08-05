// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: atof×2, CVOGRoadNode, CVOGRoadNode_ParseWidthFromTexName, FUN_005a6020, FUN_0076cec0, information, name, strrchr.
//  - Strings: "Road has invalid texture name"; "road_2laneasphalt_20"; "Road has invalid

   texture name - no size information"; "Road has invalid texture name - no size information (%s).".
//  - Return sites: 2.

// =============================================================================
// CVOGRoadNode_ParseWidthFromTexName
// -----------------------------------------------------------------------------
// Stable ID: aa_005e6c40
// Address:   0x005e6c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* CVOGRoadNode (VOGRoadNode.cpp, per the "Road has invalid texture name" log at this call site).

   Parses the road width from the node's texture/profile name (this+0x164): takes the substring

   after the last '_' and atof()s it, e.g. "road_2laneasphalt_20" -> 20.0. Clamped to a minimum

   (DAT_00a0f2a0). Falls back to a default width (DAT_00a110d8 = 10.0) and logs "Road has invalid

   texture name - no size information" when there's no trailing '_NN'. */



void __thiscall CVOGRoadNode_ParseWidthFromTexName(int param_1,char *param_2)



{

  char cVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  double dVar4;

  uint8_t local_108 [4];

  char local_104 [260];

  

  FUN_005a6020(param_2);

  pcVar2 = param_2;

  do {

    cVar1 = *pcVar2;

    pcVar2[(int)(local_104 + -(int)param_2)] = cVar1;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  pcVar2 = strrchr(local_104,0x5f);

  if (pcVar2 == (char *)0x0) {

    uVar3 = FUN_0076cec0(local_108,"Road has invalid texture name - no size information (%s).",

                         param_2);

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGRoadNode.cpp",0x11c,2,uVar3);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x164) = DAT_00a110d8;

  }

  else {

    dVar4 = atof(pcVar2 + 1);

    *(float *)(param_1 + 0x164) = (float)dVar4;

    if (dVar4 < (double)g_flOne) {

      *(float *)(param_1 + 0x164) = g_flOne;

      return;

    }

  }

  return;

}
