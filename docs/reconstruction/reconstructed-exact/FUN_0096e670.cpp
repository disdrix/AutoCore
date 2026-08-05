// =============================================================================
// FUN_0096e670
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e670
// Address:   0x0096e670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096e670 @ 0x0096e670
// Stable ID: aa_0096e670
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureFactory.cpp"
//   - "The following Textures are currently alive:"
//   - "Texture still allocated \t%d instances (%dx%d)\tF=\'%s\'\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0076c130, FUN_0096a630, FUN_0096e670, OutputDebugStringA, instances, vog_LogMessage.
//  - Strings: ",

                   0x16b,1,"; "Texture still allocated \t%d instances (%dx%d)\tF=\'%s\'\n".
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

void FUN_0096e670(void)



{

  int iVar1;

  int iVar2;

  int unaff_EBX;

  int *piVar3;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_1c [28];

  

  if (*(int *)(unaff_EBX + 0xc) != 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureFactory.cpp",

                   0x16b,1,"The following Textures are currently alive:");

    piVar3 = (int *)**(int **)(unaff_EBX + 8);

    if (piVar3 != *(int **)(unaff_EBX + 8)) {

      do {

        iVar1 = piVar3[2];

        iVar2 = FUN_0096a630(local_1c);

        if (*(uint *)(iVar2 + 0x18) < 0x10) {

          iVar2 = iVar2 + 4;

        }

        else {

          iVar2 = *(int *)(iVar2 + 4);

        }

        FUN_0076c130("Texture still allocated \t%d instances (%dx%d)\tF=\'%s\'\n",

                     *(uint32_t /* width from decompiler */ *)(iVar1 + 8),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c),

                     *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20),iVar2);

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_1c);

        piVar3 = (int *)*piVar3;

      } while (piVar3 != (int *)*(int *)(unaff_EBX + 8));

    }

    OutputDebugStringA("\n");

  }

  return;

}
