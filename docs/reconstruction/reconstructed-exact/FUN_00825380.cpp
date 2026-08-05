// =============================================================================
// FUN_00825380
// -----------------------------------------------------------------------------
// Stable ID: aa_00825380
// Address:   0x00825380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00825380 @ 0x00825380
// Stable ID: aa_00825380
// Embedded strings (evidence for future rename):
//   - "Hazard Mode "
//   - "unassigned"
//   - "Primary Attack"
//   - "Action"
//   - "%s%s"
//   - "Secondary Attack"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×5, for×2, goto×1, return×1.
//  - Notable callees: FUN_007a69d0×6, FUN_007a6de0×6, FUN_007f9160×2, sprintf×2, FUN_00825300, FUN_00825380.
//  - Strings: "Hazard Mode "; "unassigned"; "Primary Attack"; "Action".
//  - Return sites: 1.

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

void __fastcall FUN_00825380(int *param_1)



{

  undefined *puVar1;

  uint16_t *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint16_t local_208;

  uint32_t /* width from decompiler */ local_206 [63];

  char local_108 [2];

  uint32_t /* width from decompiler */ local_106 [64];

  

  local_108[0] = '\0';

  local_108[1] = '\0';

  puVar4 = local_106;

  for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *(uint16_t *)puVar4 = 0;

  local_208 = 0;

  puVar4 = local_206;

  for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *(uint16_t *)puVar4 = 0;

  if ((DAT_00d1b6d8 == 0) || (*(char *)(DAT_00d1b6d8 + 0x6b8) == '\0')) {

    puVar1 = &DAT_00a860bc;

  }

  else {

    uVar6 = 0xffffffff;

    pcVar5 = "Hazard Mode ";

    FUN_007a69d0("Hazard Mode ",0xffffffff);

    puVar1 = (undefined *)FUN_007a6de0(pcVar5,uVar6);

  }

  if (param_1[0x140] == 0) {

    FUN_007f9160(8,0);

    if ((char)local_208 == '\0') {

      uVar6 = 0xffffffff;

      pcVar5 = "unassigned";

      FUN_007a69d0("unassigned",0xffffffff);

      puVar2 = (uint16_t *)FUN_007a6de0(pcVar5,uVar6);

    }

    else {

      puVar2 = &local_208;

    }

    uVar6 = 0xffffffff;

    pcVar5 = "Primary Attack";

    FUN_007a69d0("Primary Attack",0xffffffff,puVar2);

    uVar6 = FUN_007a6de0(pcVar5,uVar6);

  }

  else {

    if (param_1[0x140] != 1) {

      uVar6 = 0xffffffff;

      pcVar5 = "Action";

      FUN_007a69d0("Action",0xffffffff);

      uVar6 = FUN_007a6de0(pcVar5,uVar6);

      sprintf(local_108,"%s%s",puVar1,uVar6);

      goto LAB_008254ed;

    }

    FUN_007f9160(9,0);

    if ((char)local_208 == '\0') {

      uVar6 = 0xffffffff;

      pcVar5 = "unassigned";

      FUN_007a69d0("unassigned",0xffffffff);

      puVar2 = (uint16_t *)FUN_007a6de0(pcVar5,uVar6);

    }

    else {

      puVar2 = &local_208;

    }

    uVar6 = 0xffffffff;

    pcVar5 = "Secondary Attack";

    FUN_007a69d0("Secondary Attack",0xffffffff,puVar2);

    uVar6 = FUN_007a6de0(pcVar5,uVar6);

  }

  sprintf(local_108,"%s%s  <%s>",puVar1,uVar6);

LAB_008254ed:

  FUN_00825300((char)param_1[0x140]);

  (**(code **)(*param_1 + 0x308))(local_108);

  return;

}
