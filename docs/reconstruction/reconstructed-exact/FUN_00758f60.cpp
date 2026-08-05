// =============================================================================
// FUN_00758f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00758f60
// Address:   0x00758f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00758f60 @ 0x00758f60
// Stable ID: aa_00758f60
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp"
//   - "Failed to Create UI Vertex Buffer"
//   - "c:\\VOGCRASH.txt"
//   - ");

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: ExitProcess, FUN_00414b60, FUN_00414bc0, FUN_00414c20, FUN_00440290, FUN_00758f60, FUN_0076d1b0, fclose.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp"; "Failed to Create UI Vertex Buffer"; "c:\\VOGCRASH.txt"; "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n".
//  - Return sites: 2.

      if (_File != (FILE *)0x0) {

        fprintf(_File,"
//   - ",

                "
//   - ",0x58a,3,

                "
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

void FUN_00758f60(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  FILE *_File;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ uVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2487;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00440290();

  puVar1 = operator_new(8);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar1 = &PTR_FUN_00a9f330;

    puVar1[1] = param_1 + 0x38;

  }

  uVar4 = 3;

  if (((DAT_00d1ecac != 0) && (*(int *)(DAT_00d1ecac + 0x14) != 0)) &&

     (*(char *)(*(int *)(DAT_00d1ecac + 0x14) + 0x10) != '\0')) {

    uVar4 = 0x13;

  }

  uVar2 = FUN_00414bc0(0x142);

  local_4 = 0;

  iVar3 = FUN_00414c20(unaff_EBX,uVar2,uVar4,puVar1);

  local_4 = 0xffffffff;

  FUN_00414b60();

  if (iVar3 < 0) {

    iVar3 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp",0x58a,

                         "Failed to Create UI Vertex Buffer");

    if (iVar3 == 3) {

      _File = fopen("c:\\VOGCRASH.txt","w");

      if (_File != (FILE *)0x0) {

        fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

                "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp",0x58a,3,

                "Failed to Create UI Vertex Buffer");

        fclose(_File);

      }

      raise(0x16);

                    /* WARNING: Subroutine does not return */

      ExitProcess(3);

    }

  }

  ExceptionList = local_c;

  return;

}
