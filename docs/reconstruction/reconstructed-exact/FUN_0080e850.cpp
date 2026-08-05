// =============================================================================
// FUN_0080e850
// -----------------------------------------------------------------------------
// Stable ID: aa_0080e850
// Address:   0x0080e850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080e850 @ 0x0080e850
// Stable ID: aa_0080e850
// Embedded strings (evidence for future rename):
//   - "has gone offline"
//   - "Clanmate"
//   - "has come online"
//   - "%s %s %s."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×7, for×1, return×1.
//  - Notable callees: FUN_007a6de0×4, FUN_004c22a0, FUN_007a69d0, FUN_0080e850, FUN_008f8200, sprintf.
//  - Strings: "has gone offline"; "Clanmate"; "has come online"; "%s %s %s.".
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

void FUN_0080e850(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char local_108 [2];

  uint32_t /* width from decompiler */ local_106 [64];

  

  FUN_007a69d0();

  if (((*(int **)(param_1 + 0x31f0) != (int *)0x0) && (**(int **)(param_1 + 0x31f0) != -1)) &&

     (iVar2 = FUN_004c22a0(*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_2 + 0xc)), iVar2 != 0)

     ) {

    cVar1 = *(char *)(param_2 + 0x10);

    if (*(char *)(iVar2 + 0x34) != cVar1) {

      local_108[0] = '\0';

      local_108[1] = '\0';

      puVar6 = local_106;

      for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar6 = 0;

        puVar6 = puVar6 + 1;

      }

      *(uint16_t *)puVar6 = 0;

      if (cVar1 == '\0') {

        uVar3 = FUN_007a6de0("has gone offline",0xffffffff);

        iVar5 = iVar2 + 8;

        uVar4 = FUN_007a6de0("Clanmate",0xffffffff);

      }

      else {

        uVar3 = FUN_007a6de0("has come online",0xffffffff);

        iVar5 = iVar2 + 8;

        uVar4 = FUN_007a6de0("Clanmate",0xffffffff);

      }

      sprintf(local_108,"%s %s %s.",uVar4,iVar5,uVar3);

      if (DAT_00d1b8dc != 0) {

        FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_108,0);

      }

    }

    *(uint8_t *)(iVar2 + 0x34) = *(uint8_t *)(param_2 + 0x10);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x18);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x14);

    if (*(int *)(param_1 + 0x1090) != 0) {

      (**(code **)(**(int **)(param_1 + 0x1090) + 0x448))();

    }

    if (*(int *)(param_1 + 0x106c) != 0) {

      (**(code **)(**(int **)(param_1 + 0x106c) + 0x448))();

    }

    if (*(int *)(param_1 + 0x1038) != 0) {

      (**(code **)(**(int **)(param_1 + 0x1038) + 0x448))();

    }

  }

  return;

}
