// =============================================================================
// FUN_00746d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00746d40
// Address:   0x00746d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00746d40 @ 0x00746d40
// Stable ID: aa_00746d40
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effVertexDecl.cpp"
//   - "Unhandled type VDECL encounted while building chunk block"
//   - "c:\\VOGCRASH.txt"
//   - ");

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: while×5, if×4, return×3, do×1, switch×1, goto×1.
//  - Notable callees: FUN_0044cb20×9, block×2, vog_LogMessage×2, ExitProcess, FUN_00436ef0, FUN_0044a380, FUN_00463e30, FUN_00746d40.
//  - Strings: "

                             ,0x49f,"; ");

        if (iVar1 == 3) {

          _File = fopen("; "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n"; ",

                    0x49f,3,".
//  - Return sites: 3.

          if (_File != (FILE *)0x0) {

            fprintf(_File,"
//   - ",

                    "
//   - ",

                    0x49f,3,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

void FUN_00746d40(int param_1)



{

  int in_EAX;

  int iVar1;

  FILE *_File;

  int iVar2;

  

  FUN_0044a380(0);

  iVar2 = *(int *)(param_1 + 4);

  if (iVar2 != *(int *)(param_1 + 8)) {

    do {

      switch(*(uint8_t *)(iVar2 + 4)) {

      case 3:

        FUN_0044cb20();

      case 2:

        FUN_0044cb20();

      case 1:

        FUN_0044cb20();

      case 0:

        FUN_0044cb20();

        break;

      case 4:

      case 5:

      case 8:

        FUN_0044cb20();

        break;

      case 6:

      case 9:

      case 0xb:

        goto LAB_00746e00;

      case 7:

      case 10:

      case 0xc:

        FUN_0044cb20();

        FUN_0044cb20();

LAB_00746e00:

        FUN_0044cb20();

        FUN_0044cb20();

        break;

      default:

        iVar1 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effVertexDecl.cpp"

                             ,0x49f,"Unhandled type VDECL encounted while building chunk block");

        if (iVar1 == 3) {

          _File = fopen("c:\\VOGCRASH.txt","w");

          if (_File != (FILE *)0x0) {

            fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

                    "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effVertexDecl.cpp",

                    0x49f,3,"Unhandled type VDECL encounted while building chunk block");

            fclose(_File);

          }

          raise(0x16);

                    /* WARNING: Subroutine does not return */

          ExitProcess(3);

        }

        break;

      case 0xf:

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effVertexDecl.cpp",

                       0x491,3,

                       "Unhandled type VDECL encounted while building chunk block (need to add 16-bit float support)"

                      );

        break;

      case 0x10:

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effVertexDecl.cpp",

                       0x494,3,

                       "Unhandled type VDECL encounted while building chunk block (need to add 16-bit float support)"

                      );

        break;

      case 0x11:

        break;

      }

      iVar2 = iVar2 + 8;

    } while (iVar2 != *(int *)(param_1 + 8));

  }

  iVar2 = *(int *)(in_EAX + 4);

  param_1 = 0;

  if ((iVar2 != 0) &&

     ((uint)(*(int *)(in_EAX + 8) - iVar2 >> 2) < (uint)(*(int *)(in_EAX + 0xc) - iVar2 >> 2))) {

    iVar2 = *(int *)(in_EAX + 8);

    FUN_00436ef0(0);

    *(int *)(in_EAX + 8) = iVar2 + 4;

    return;

  }

  FUN_00463e30(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),1,&param_1);

  return;

}
