// =============================================================================
// FUN_0080e9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080e9b0
// Address:   0x0080e9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080e9b0 @ 0x0080e9b0
// Stable ID: aa_0080e9b0
// Embedded strings (evidence for future rename):
//   - "You have been removed from your clan."
//   - "has been removed from your clan"
//   - "%s %s."
//   - "Character not found!"
//   - "You do not have permission to do that!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×11, return×4, for×2, do×2.
//  - Notable callees: FUN_007a6de0×3, FUN_008f8200×2, FUN_004c22a0, FUN_004c2500, FUN_004c25b0, FUN_007a69d0, FUN_007fdfb0, FUN_0080e9b0.
//  - Strings: "You have been removed from your clan."; "has been removed from your clan"; "%s %s."; "Character not found!".
//  - Return sites: 4.

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

void FUN_0080e9b0(void)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  int unaff_EBX;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  char local_108 [2];

  uint32_t /* width from decompiler */ local_106 [64];

  

  FUN_007a69d0();

  iVar4 = *(int *)(unaff_ESI + 0x31f0);

  local_108[0] = '\0';

  local_108[1] = '\0';

  puVar5 = local_106;

  for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  if (iVar4 != 0) {

    iVar4 = *(int *)(unaff_EBX + 4);

    if (iVar4 == 0) {

      iVar4 = *(int *)(unaff_ESI + 0xe98);

      iVar3 = *(int *)(*(int *)(iVar4 + 4) + 4);

      if ((*(int *)(unaff_EBX + 0x10) == *(int *)(iVar3 + 0x164 + iVar4)) &&

         (*(int *)(unaff_EBX + 0x14) == *(int *)(iVar3 + 0x168 + iVar4))) {

        FUN_0094c6d0();

        uVar9 = 0;

        uVar8 = 1;

        uVar6 = 0xffffffff;

        uVar2 = FUN_007a6de0("You have been removed from your clan.",0xffffffff);

        FUN_007fdfb0(unaff_ESI,uVar2,uVar6,uVar8,uVar9);

        FUN_004c2500();

        puVar5 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x31f0);

        for (iVar4 = 0x82; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar5 = 0;

          puVar5 = puVar5 + 1;

        }

        **(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x31f0) = 0xffffffff;

        return;

      }

      iVar4 = FUN_004c22a0(*(int *)(unaff_EBX + 0x10),*(int *)(unaff_EBX + 0x14));

      if (iVar4 != 0) {

        uVar2 = FUN_007a6de0("has been removed from your clan",0xffffffff);

        sprintf(local_108,"%s %s.",iVar4 + 8,uVar2);

      }

      cVar1 = FUN_004c25b0(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc),

                           *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14));

      if (cVar1 != '\0') {

        if (DAT_00d1b8dc != 0) {

          FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_108,0);

        }

        if (*(int *)(unaff_ESI + 0x1090) != 0) {

          (**(code **)(**(int **)(unaff_ESI + 0x1090) + 0x448))();

        }

        if (*(int *)(unaff_ESI + 0x1038) != 0) {

          (**(code **)(**(int **)(unaff_ESI + 0x1038) + 0x448))();

        }

      }

    }

    else {

      if (iVar4 == 1) {

        pcVar7 = "Character not found!";

      }

      else {

        if (iVar4 != 2) {

          return;

        }

        pcVar7 = "You do not have permission to do that!";

      }

      uVar2 = FUN_007a6de0(pcVar7,0xffffffff);

      if (DAT_00d1b8dc != 0) {

        FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar2,0);

        return;

      }

    }

  }

  return;

}
