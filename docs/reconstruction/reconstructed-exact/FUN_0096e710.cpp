// =============================================================================
// FUN_0096e710
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e710
// Address:   0x0096e710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096e710 @ 0x0096e710
// Stable ID: aa_0096e710
// Embedded strings (evidence for future rename):
//   - "TextureFactory has %d unreleased instances"
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureFactory.cpp"
//   - "\tStill allocated: %d instances (%dx%d)\tF=\'%s\'\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: block×2, FUN_00463e30, FUN_0076c130, FUN_0076cec0, FUN_0096a630, FUN_0096e710, instances, vog_LogMessage.
//  - Strings: "TextureFactory has %d unreleased instances"; "\tStill allocated: %d instances (%dx%d)\tF=\'%s\'\n".
//  - Return sites: 2.

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

/* WARNING: Removing unreachable block (ram,0x0096e7ee) */

/* WARNING: Removing unreachable block (ram,0x0096e7f0) */



void FUN_0096e710(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int *piVar6;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_20;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_1c [28];

  

  if (*(int *)(unaff_ESI + 0xc) != 0) {

    uVar4 = FUN_0076cec0(&local_20,"TextureFactory has %d unreleased instances",

                         *(int *)(unaff_ESI + 0xc));

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureFactory.cpp",

                   0xa5,2,uVar4);

    piVar6 = (int *)**(int **)(unaff_ESI + 8);

    if (piVar6 != *(int **)(unaff_ESI + 8)) {

      do {

        iVar1 = piVar6[2];

        iVar5 = FUN_0096a630(local_1c);

        if (*(uint *)(iVar5 + 0x18) < 0x10) {

          iVar5 = iVar5 + 4;

        }

        else {

          iVar5 = *(int *)(iVar5 + 4);

        }

        FUN_0076c130("\tStill allocated: %d instances (%dx%d)\tF=\'%s\'\n",

                     *(uint32_t /* width from decompiler */ *)(iVar1 + 8),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c),

                     *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20),iVar5);

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_1c);

        piVar6 = (int *)*piVar6;

      } while (piVar6 != (int *)*(int *)(unaff_ESI + 8));

    }

    puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8);

    pvVar3 = (void *)*puVar2;

    *puVar2 = puVar2;

    *(int *)(*(int *)(unaff_ESI + 8) + 4) = *(int *)(unaff_ESI + 8);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

    if (pvVar3 != *(void **)(unaff_ESI + 8)) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar3);

    }

    local_20 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8);

    if (*(int *)(unaff_ESI + 0x14) != *(int *)(unaff_ESI + 0x18)) {

      *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x14);

    }

    FUN_00463e30(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14),9,&local_20);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20) = 1;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x24) = 1;

  }

  *(uint8_t *)(unaff_ESI + 0x28) = 0;

  return;

}
