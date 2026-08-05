// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008778e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008778e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa
// Address:   0x008778e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa: packet/network helper. Evidence string: "Rank for". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Rank for"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: for×5, do×3, while×3, if×1, return×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_008778e0, sprintf.
//  - Strings: "Rank for"; "%s %s: %d\n".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008778e0(int param_1)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ uVar8;

  undefined *local_50c;

  char local_508 [255];

  char acStack_409 [2];

  uint32_t /* width from decompiler */ local_407;

  

  if ((*(int *)(param_1 + 0x570) != 0) && (DAT_00d1b6d8 != 0)) {

    acStack_409[1] = 0;

    puVar6 = &local_407;

    for (iVar3 = 0xff; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar6 = 0;

      puVar6 = puVar6 + 1;

    }

    *(uint16_t *)puVar6 = 0;

    *(uint8_t *)((int)puVar6 + 2) = 0;

    local_50c = &DAT_00a1e4d0;

    iVar3 = 0x6d0;

    do {

      uVar8 = 0xffffffff;

      pcVar7 = "Rank for";

      FUN_007a69d0("Rank for",0xffffffff,local_50c,*(uint32_t /* width from decompiler */ *)(iVar3 + DAT_00d1b6d8));

      uVar8 = FUN_007a6de0(pcVar7,uVar8);

      sprintf(local_508,"%s %s: %d\n",uVar8);

      pcVar7 = local_508;

      do {

        cVar1 = *pcVar7;

        pcVar7 = pcVar7 + 1;

      } while (cVar1 != '\0');

      uVar2 = (int)pcVar7 - (int)local_508;

      pcVar7 = acStack_409;

      do {

        pcVar5 = pcVar7 + 1;

        pcVar7 = pcVar7 + 1;

      } while (*pcVar5 != '\0');

      local_50c = local_50c + 0x10;

      pcVar5 = local_508;

      for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

        pcVar5 = pcVar5 + 4;

        pcVar7 = pcVar7 + 4;

      }

      iVar3 = iVar3 + 4;

      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

        *pcVar7 = *pcVar5;

        pcVar5 = pcVar5 + 1;

        pcVar7 = pcVar7 + 1;

      }

    } while (iVar3 < 0x6ec);

    (**(code **)(**(int **)(param_1 + 0x570) + 0x1d8))(acStack_409 + 1,1,1);

    (**(code **)(**(int **)(param_1 + 0x570) + 0x34c))();

  }

  return;

}
