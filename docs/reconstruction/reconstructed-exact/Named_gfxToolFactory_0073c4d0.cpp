// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, do×2, for×2, while×2.
//  - Notable callees: vog_LogMessage×2, FUN_0040ead0, FUN_0073c4d0, FUN_0096be60, FUN_0099aef0, localBuildMonotoneTexture.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxToolFactory.cpp"; "Unable to lock texture!".
//  - Return sites: 3.

// =============================================================================
// Named_gfxToolFactory_0073c4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073c4d0
// Address:   0x0073c4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxToolFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_gfxToolFactory_0073c4d0(uint32_t /* width from decompiler */ *param_1)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  int iVar5;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int local_1c;

  uint32_t /* width from decompiler */ local_10 [4];

  

  uVar1 = FUN_0040ead0(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x24));

  if (uVar1 == 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxToolFactory.cpp",0x55,3,

                   "localBuildMonotoneTexture() called with unsupported surface format");

    return 0xffffffff;

  }

  FUN_0099aef0(*param_1);

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_0096be60(0,0,0,1);

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    local_1c = 0;

    if (0 < *(int *)(unaff_EBX + 0x20)) {

      do {

        iVar5 = 0;

        puVar3 = puVar2;

        if (0 < *(int *)(unaff_EBX + 0x1c)) {

          do {

            puVar6 = local_10;

            puVar7 = puVar3;

            for (uVar4 = uVar1 >> 5; uVar4 != 0; uVar4 = uVar4 - 1) {

              *puVar7 = *puVar6;

              puVar6 = puVar6 + 1;

              puVar7 = puVar7 + 1;

            }

            for (uVar4 = uVar1 >> 3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

              *(uint8_t *)puVar7 = *(uint8_t *)puVar6;

              puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

              puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

            }

            iVar5 = iVar5 + 1;

            puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + (uVar1 >> 3));

          } while (iVar5 < *(int *)(unaff_EBX + 0x1c));

        }

        puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + *(int *)(unaff_EBX + 0x40));

        local_1c = local_1c + 1;

      } while (local_1c < *(int *)(unaff_EBX + 0x20));

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

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxToolFactory.cpp",0x61,3,

                 "Unable to lock texture!");

  return 0xffffffff;

}
