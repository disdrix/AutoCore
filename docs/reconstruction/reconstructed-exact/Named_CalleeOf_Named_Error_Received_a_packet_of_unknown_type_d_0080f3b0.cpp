// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080f3b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080f3b0
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x0080f3b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper. Evidence string: "Your enemy". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Your enemy"
//   - "Your friend"
//   - "gone offline."
//   - "come online."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×7, do×4, while×4, for×3, return×3.
//  - Notable callees: FUN_007a6de0×6, FUN_005739d0, FUN_00573b50, FUN_007a69d0, FUN_0080f3b0, FUN_008f8200, sprintf.
//  - Strings: "Your enemy"; "Your friend"; "%s %s %s "; "gone offline.".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080f3b0(int param_1)



{

  char *pcVar1;

  char cVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  char *pcVar6;

  uint uVar7;

  int iVar8;

  uint uVar9;

  uint32_t /* width from decompiler */ *puVar10;

  char cStack_109;

  char local_108 [2];

  uint32_t /* width from decompiler */ local_106 [64];

  

  FUN_007a69d0();

  cVar2 = *(char *)(in_EAX + 4);

  local_108[0] = '\0';

  local_108[1] = '\0';

  puVar10 = local_106;

  for (iVar8 = 0x3f; iVar8 != 0; iVar8 = iVar8 + -1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  *(uint16_t *)puVar10 = 0;

  if (cVar2 == '\0') {

    iVar8 = FUN_00573b50(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc));

    if (iVar8 == 0) {

      return;

    }

    uVar3 = FUN_007a6de0(&DAT_00a7e5d4,0xffffffff);

    iVar8 = iVar8 + 0x23;

    uVar4 = FUN_007a6de0("Your enemy",0xffffffff);

  }

  else {

    iVar8 = FUN_005739d0(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc));

    if (iVar8 == 0) {

      return;

    }

    uVar3 = FUN_007a6de0(&DAT_00a7e5d4,0xffffffff);

    iVar8 = iVar8 + 0x1a;

    uVar4 = FUN_007a6de0("Your friend",0xffffffff);

  }

  sprintf(local_108,"%s %s %s ",uVar4,iVar8,uVar3);

  if (*(int **)(param_1 + 0x1038) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x1038) + 0x448))();

  }

  if ((*(int **)(param_1 + 0xf40) != (int *)0x0) && (**(int **)(param_1 + 0xf40) != 0)) {

    if (*(char *)(in_EAX + 0x21) == '\0') {

      pcVar5 = (char *)FUN_007a6de0("gone offline.",0xffffffff);

      pcVar6 = pcVar5;

      do {

        cVar2 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar2 != '\0');

      uVar7 = (int)pcVar6 - (int)pcVar5;

      pcVar6 = &cStack_109;

      do {

        pcVar1 = pcVar6 + 1;

        pcVar6 = pcVar6 + 1;

      } while (*pcVar1 != '\0');

    }

    else {

      pcVar5 = (char *)FUN_007a6de0("come online.",0xffffffff);

      pcVar6 = pcVar5;

      do {

        cVar2 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar2 != '\0');

      uVar7 = (int)pcVar6 - (int)pcVar5;

      pcVar6 = &cStack_109;

      do {

        pcVar1 = pcVar6 + 1;

        pcVar6 = pcVar6 + 1;

      } while (*pcVar1 != '\0');

    }

    for (uVar9 = uVar7 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar6 = pcVar6 + 4;

    }

    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

      *pcVar6 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar6 = pcVar6 + 1;

    }

    if (DAT_00d1b8dc != 0) {

      FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_108,0);

    }

  }

  return;

}
