// =============================================================================
// FUN_0073c350
// -----------------------------------------------------------------------------
// Stable ID: aa_0073c350
// Address:   0x0073c350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073c350 @ 0x0073c350
// Stable ID: aa_0073c350
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxToolFactory.cpp"
//   - "localBuildCheckerboardTexture() called with unsupported surface format"
//   - "Unable to lock texture!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, for×3, do×2, while×2.
//  - Notable callees: FUN_0099aef0×2, vog_LogMessage×2, FUN_0040ead0, FUN_0073c350, FUN_0096be60, localBuildCheckerboardTexture.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxToolFactory.cpp"; "Unable to lock texture!".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_0073c350(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int local_2c;

  int local_28;

  uint32_t /* width from decompiler */ local_20 [4];

  uint32_t /* width from decompiler */ local_10 [4];

  

  uVar1 = FUN_0040ead0(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x24));

  if (uVar1 == 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxToolFactory.cpp",0x76,3,

                   "localBuildCheckerboardTexture() called with unsupported surface format");

    return 0xffffffff;

  }

  FUN_0099aef0(*param_1);

  FUN_0099aef0(*param_2);

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_0096be60(0,0,0,1);

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    local_2c = 0;

    if (0 < *(int *)(unaff_EBX + 0x20)) {

      do {

        local_28 = 0;

        puVar4 = puVar2;

        if (0 < *(int *)(unaff_EBX + 0x1c)) {

          do {

            puVar6 = puVar4;

            if (*(int *)(unaff_EBX + 0x20) / 2 < local_2c) {

              puVar5 = local_10;

              for (uVar3 = uVar1 >> 5; uVar3 != 0; uVar3 = uVar3 - 1) {

                *puVar6 = *puVar5;

                puVar5 = puVar5 + 1;

                puVar6 = puVar6 + 1;

              }

            }

            else {

              puVar5 = local_20;

              for (uVar3 = uVar1 >> 5; uVar3 != 0; uVar3 = uVar3 - 1) {

                *puVar6 = *puVar5;

                puVar5 = puVar5 + 1;

                puVar6 = puVar6 + 1;

              }

            }

            puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + (uVar1 >> 3));

            local_28 = local_28 + 1;

            for (uVar3 = uVar1 >> 3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

              *(uint8_t *)puVar6 = *(uint8_t *)puVar5;

              puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

              puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

            }

          } while (local_28 < *(int *)(unaff_EBX + 0x1c));

        }

        puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + *(int *)(unaff_EBX + 0x40));

        local_2c = local_2c + 1;

      } while (local_2c < *(int *)(unaff_EBX + 0x20));

    }

    uVar1 = *(uint *)(unaff_EBX + 0x2c) & 0xf;

    if (uVar1 == 1) {

      (**(code **)(**(int **)(unaff_EBX + 0x10) + 0x50))(*(int **)(unaff_EBX + 0x10),0);

    }

    else if (uVar1 == 2) {

      (**(code **)(**(int **)(unaff_EBX + 0x10) + 0x50))

                (*(int **)(unaff_EBX + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x3c),0);

    }

    else if (uVar1 == 4) {

      (**(code **)(**(int **)(unaff_EBX + 0x10) + 0x50))(*(int **)(unaff_EBX + 0x10),0);

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x38) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x3c) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x44) = 0;

    return 0;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxToolFactory.cpp",0x87,3,

                 "Unable to lock texture!");

  return 0xffffffff;

}
