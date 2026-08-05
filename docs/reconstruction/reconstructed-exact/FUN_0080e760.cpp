// =============================================================================
// FUN_0080e760
// -----------------------------------------------------------------------------
// Stable ID: aa_0080e760
// Address:   0x0080e760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080e760 @ 0x0080e760
// Stable ID: aa_0080e760
// Embedded strings (evidence for future rename):
//   - "Clan MOTD"
//   - "%s: %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×5, for×1, do×1, while×1, return×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_0080e760, FUN_008f8200, sprintf.
//  - Strings: "Clan MOTD"; "%s: %s".
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

void FUN_0080e760(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  int unaff_EBX;

  char *pcVar6;

  uint32_t /* width from decompiler */ *puVar7;

  char local_138 [2];

  uint32_t /* width from decompiler */ local_136;

  

  FUN_007a69d0();

  local_138[0] = '\0';

  local_138[1] = '\0';

  puVar7 = &local_136;

  for (iVar3 = 0x4a; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar7 = 0;

    puVar7 = puVar7 + 1;

  }

  *(uint16_t *)puVar7 = 0;

  *(uint8_t *)((int)puVar7 + 2) = 0;

  if (*(int *)(unaff_EBX + 0x31f0) != 0) {

    pcVar6 = (char *)(param_1 + 4);

    pcVar5 = (char *)(*(int *)(unaff_EBX + 0x31f0) + 0x37);

    pcVar4 = pcVar6;

    do {

      cVar1 = *pcVar4;

      *pcVar5 = cVar1;

      pcVar4 = pcVar4 + 1;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    uVar2 = FUN_007a6de0("Clan MOTD",0xffffffff);

    sprintf(local_138,"%s: %s",uVar2,pcVar6);

    if (DAT_00d1b8dc != 0) {

      FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_138,0);

    }

    if (*(int *)(unaff_EBX + 0x1090) != 0) {

      (**(code **)(**(int **)(unaff_EBX + 0x1090) + 0x448))();

    }

    if (*(int *)(unaff_EBX + 0x106c) != 0) {

      (**(code **)(**(int **)(unaff_EBX + 0x106c) + 0x448))();

    }

    if (*(int *)(unaff_EBX + 0x1038) != 0) {

      (**(code **)(**(int **)(unaff_EBX + 0x1038) + 0x448))();

    }

  }

  return;

}
