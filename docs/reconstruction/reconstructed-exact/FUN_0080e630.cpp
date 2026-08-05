// =============================================================================
// FUN_0080e630
// -----------------------------------------------------------------------------
// Stable ID: aa_0080e630
// Address:   0x0080e630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080e630 @ 0x0080e630
// Stable ID: aa_0080e630
// Embedded strings (evidence for future rename):
//   - "rank to"
//   - "has set"
//   - "%s %s %s\'s %s %s."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×5, for×1, return×1.
//  - Notable callees: FUN_004c22a0×2, FUN_007a6de0×2, FUN_004c21e0, FUN_004c2380, FUN_007a69d0, FUN_0080e630, FUN_008f8200, sprintf.
//  - Strings: "rank to"; "has set"; "%s %s %s\'s %s %s.".
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

void FUN_0080e630(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int unaff_EBX;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar6;

  char local_108 [2];

  uint32_t /* width from decompiler */ local_106 [64];

  

  FUN_007a69d0();

  if (*(int *)(unaff_EBX + 0x31f0) != 0) {

    local_108[0] = '\0';

    local_108[1] = '\0';

    puVar6 = local_106;

    for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar6 = 0;

      puVar6 = puVar6 + 1;

    }

    uVar2 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10);

    *(uint16_t *)puVar6 = 0;

    iVar5 = FUN_004c22a0(uVar2,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14));

    iVar1 = FUN_004c22a0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc));

    if ((iVar5 != 0) && (iVar1 != 0)) {

      uVar2 = FUN_004c21e0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18));

      uVar3 = FUN_007a6de0("rank to",0xffffffff);

      iVar5 = iVar5 + 8;

      uVar4 = FUN_007a6de0("has set",0xffffffff);

      sprintf(local_108,"%s %s %s\'s %s %s.",iVar1 + 8,uVar4,iVar5,uVar3,uVar2);

      if (DAT_00d1b8dc != 0) {

        FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_108,0);

      }

    }

    FUN_004c2380(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18),1);

    if (*(int *)(unaff_EBX + 0x1090) != 0) {

      (**(code **)(**(int **)(unaff_EBX + 0x1090) + 0x448))();

    }

    if (*(int *)(unaff_EBX + 0x1038) != 0) {

      (**(code **)(**(int **)(unaff_EBX + 0x1038) + 0x448))();

    }

  }

  return;

}
