// READABILITY (auto CF):
//  - Body size: ~136 non-empty decompiler lines.
//  - Control keywords: if×17, return×9.
//  - Notable callees: vog_LogMessage×3, FUN_0096be60×2, FUN_0040ead0, FUN_0040ec00, FUN_0096c450, FUN_0099b010, FUN_0099b230.
//  - Strings: "

                           ,0x515,2,"; ",

                     0x532,3,"; ",

                   0x521,3,".
//  - Return sites: 9.

// =============================================================================
// Named_effTextureImpl_0096c450
// -----------------------------------------------------------------------------
// Stable ID: aa_0096c450
// Address:   0x0096c450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effTextureImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint Named_effTextureImpl_0096c450(uint32_t /* width from decompiler */ *param_1)



{

  int *in_EAX;

  int iVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int unaff_ESI;

  uint8_t local_14 [4];

  int local_10;

  int local_c;

  int local_8;

  int local_4;

  

  iVar2 = *in_EAX;

  if ((((iVar2 < 0) || (in_EAX[1] < 0)) || (*(int *)(unaff_ESI + 0x1c) <= iVar2)) ||

     (*(int *)(unaff_ESI + 0x20) <= in_EAX[1])) {

    uVar3 = vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp"

                           ,0x515,2,"Requesting color of pixel outside of texture!");

    return uVar3 & 0xffffff00;

  }

  iVar1 = FUN_0040ead0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x24));

  if (iVar1 == 0) {

    uVar3 = FUN_0040ec00();

    if ((char)uVar3 != '\0') {

      iVar2 = FUN_0096be60(0,0,0,4);

      if (iVar2 != 0) {

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_0099b230(local_14,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x24));

        *param_1 = *puVar4;

        uVar3 = *(uint *)(unaff_ESI + 0x2c) & 0xf;

        if (uVar3 == 1) {

          (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x50))(*(int **)(unaff_ESI + 0x10),0);

        }

        else if (uVar3 == 2) {

          (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x50))

                    (*(int **)(unaff_ESI + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c),0);

        }

        else if (uVar3 == 4) {

          (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x50))(*(int **)(unaff_ESI + 0x10),0);

        }

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40) = 0;

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44) = 0;

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38) = 0xffffffff;

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c) = 0xffffffff;

        return 0xffffff01;

      }

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",

                     0x532,3,"Unable to lock texture!");

      uVar3 = *(uint *)(unaff_ESI + 0x2c) & 0xf;

      if (uVar3 == 1) {

        (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x50))(*(int **)(unaff_ESI + 0x10),0);

      }

      else {

        if (uVar3 == 2) {

          (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x50))

                    (*(int **)(unaff_ESI + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c),0);

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40) = 0;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44) = 0;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38) = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c) = 0xffffffff;

          return 0xffffff00;

        }

        if (uVar3 == 4) {

          (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x50))(*(int **)(unaff_ESI + 0x10),0);

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40) = 0;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44) = 0;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38) = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c) = 0xffffffff;

          return 0xffffff00;

        }

      }

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40) = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44) = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c) = 0xffffffff;

      return 0xffffff00;

    }

  }

  else {

    local_c = in_EAX[1];

    local_4 = local_c + 1;

    local_8 = iVar2 + 1;

    local_10 = iVar2;

    iVar2 = FUN_0096be60(0,&local_10,0,4);

    if (iVar2 != 0) {

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_0099b010();

      *param_1 = *puVar4;

      uVar3 = *(uint *)(unaff_ESI + 0x2c) & 0xf;

      if (uVar3 == 1) {

        (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x50))(*(int **)(unaff_ESI + 0x10),0);

      }

      else {

        if (uVar3 == 2) {

          (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x50))

                    (*(int **)(unaff_ESI + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c),0);

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40) = 0;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44) = 0;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38) = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c) = 0xffffffff;

          return 0xffffff01;

        }

        if (uVar3 == 4) {

          (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x50))(*(int **)(unaff_ESI + 0x10),0);

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40) = 0;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44) = 0;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38) = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c) = 0xffffffff;

          return 0xffffff01;

        }

      }

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40) = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44) = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c) = 0xffffffff;

      return 0xffffff01;

    }

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",

                   0x521,3,"Unable to lock texture!");

    uVar3 = *(uint *)(unaff_ESI + 0x2c) & 0xf;

    if (uVar3 == 1) {

      (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x50))(*(int **)(unaff_ESI + 0x10),0);

    }

    else if (uVar3 == 2) {

      (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x50))

                (*(int **)(unaff_ESI + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c),0);

    }

    else if (uVar3 == 4) {

      (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x50))(*(int **)(unaff_ESI + 0x10),0);

    }

    uVar3 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44) = 0;

  }

  return uVar3 & 0xffffff00;

}
