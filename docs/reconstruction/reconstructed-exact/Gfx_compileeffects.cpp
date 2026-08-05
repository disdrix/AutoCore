// =============================================================================
// Gfx_compileeffects
// -----------------------------------------------------------------------------
// Stable ID: aa_0094ba40
// Address:   0x0094ba40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_compileeffects @ 0x0094ba40
// Stable ID: aa_0094ba40
// Embedded strings (evidence for future rename):
//   - "-developer"
//   - "The game is already running. Exiting..."
//   - "Error"
//   - "XetDevilAutoAssaultGame"
//   - "-compileeffects"
//   - "-lowquality"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: if×10, return×4, do×1, while×1.
//  - Notable callees: AddFontResourceExA×13, CloseHandle×4, strstr×4, CONCAT31×2, FUN_004050d0×2, FUN_0076c8a0×2, FUN_0076d250×2, FUN_0094b9c0×2.
//  - Strings: "-developer"; "The game is already running. Exiting..."; "Error"; "XetDevilAutoAssaultGame".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "-compileeffects"
 * Domain alias of FUN_0094ba40 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ Gfx_compileeffects(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  char *pcVar1;

  char cVar2;

  char *pcVar3;

  HANDLE hProcess;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  SIZE_T dwMinimumWorkingSetSize;

  SIZE_T dwMaximumWorkingSetSize;

  int local_25c [140];

  void *local_2c;

  int *local_28;

  HANDLE local_24;

  int local_20;

  uint32_t /* width from decompiler */ local_1c;

  HANDLE local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  int local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bbf5b;

  local_10 = ExceptionList;

  local_14 = &stack0xfffffd98;

  ExceptionList = &local_10;

  pcVar3 = strstr(param_3,"-developer");

  if (pcVar3 == (char *)0x0) {

    ExceptionList = local_10;

    return 0;

  }

  DAT_00d1d9c0 = param_1;

  _DAT_00d1d9bc = param_3;

  FUN_00405080();

  local_8 = 0;

  if ((local_20 == 0) || (local_24 == (HANDLE)0x0)) {

    MessageBoxA((HWND)0x0,"The game is already running. Exiting...","Error",0x10);

    local_8 = 0xffffffff;

    if (local_24 != (HANDLE)0x0) {

      CloseHandle(local_24);

    }

  }

  else {

    local_18 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,0,"XetDevilAutoAssaultGame");

    FUN_0076c8f0(local_25c,2,1);

    local_8._0_1_ = 1;

    local_25c[1] = 2;

    (**(code **)(local_25c[0] + 0x10))();

    FUN_0076d250();

    pcVar3 = strstr(param_3,"-compileeffects");

    if (pcVar3 != (char *)0x0) {

      local_8 = CONCAT31(local_8._1_3_,2);

      FUN_00948bd0();

      local_8 = 1;

      CloseHandle(local_18);

                    /* WARNING: Subroutine does not return */

      _exit(0);

    }

    dwMaximumWorkingSetSize = 0x40000000;

    dwMinimumWorkingSetSize = 0x10000000;

    hProcess = GetCurrentProcess();

    SetProcessWorkingSetSize(hProcess,dwMinimumWorkingSetSize,dwMaximumWorkingSetSize);

    pcVar3 = strstr(param_3,"-lowquality");

    if (pcVar3 != (char *)0x0) {

      DAT_00d1a851 = 1;

    }

    FUN_009365e0(&DAT_00d1a840);

    DAT_00d1da35 = 1;

    pcVar3 = strstr(param_3,"lang=");

    if (pcVar3 != (char *)0x0) {

      pcVar1 = param_3 + 1;

      do {

        cVar2 = *param_3;

        param_3 = param_3 + 1;

      } while (cVar2 != '\0');

      if (5 < (uint)((int)param_3 - (int)pcVar1)) {

        atoi(pcVar3 + 5);

        FUN_007a69d0();

        FUN_007a66f0();

      }

    }

    local_2c = operator_new(0x18);

    local_8._0_1_ = 4;

    if (local_2c == (void *)0x0) {

      piVar4 = (int *)0x0;

    }

    else {

      piVar4 = (int *)FUN_00404e40(local_2c);

    }

    local_8._0_1_ = 1;

    DAT_00d1b640 = piVar4;

    piVar4[1] = 3;

    local_28 = piVar4;

    (**(code **)(*piVar4 + 0x10))();

    FUN_0076d250();

    AddFontResourceExA("../fonts/bullregu.ttf",0x10,(PVOID)0x0);

    AddFontResourceExA("../fonts/bullrgsc.ttf",0x10,(PVOID)0x0);

    AddFontResourceExA("../fonts/bullscal.ttf",0x10,(PVOID)0x0);

    AddFontResourceExA("../fonts/bullscsc.ttf",0x10,(PVOID)0x0);

    AddFontResourceExA("../fonts/bullsmcp.ttf",0x10,(PVOID)0x0);

    AddFontResourceExA("../fonts/bullspcp.ttf",0x10,(PVOID)0x0);

    AddFontResourceExA("../fonts/TCB_____.TTF",0x10,(PVOID)0x0);

    AddFontResourceExA("../fonts/TCBI____.TTF",0x10,(PVOID)0x0);

    AddFontResourceExA("../fonts/TCCB____.TTF",0x10,(PVOID)0x0);

    AddFontResourceExA("../fonts/TCCEB.TTF",0x10,(PVOID)0x0);

    AddFontResourceExA("../fonts/TCCM____.TTF",0x10,(PVOID)0x0);

    AddFontResourceExA("../fonts/TCM_____.TTF",0x10,(PVOID)0x0);

    AddFontResourceExA("../fonts/TCMI____.TTF",0x10,(PVOID)0x0);

    iVar5 = FUN_0094a6a0(&DAT_00d1a840);

    if (iVar5 != 0) {

      if (DAT_00d1b1e5 == '\0') {

        _set_se_translator((_func_void_uint__EXCEPTION_POINTERS_ptr *)&DAT_00794030);

        _set_new_handler((_func_int_uint *)&LAB_0092cc10);

        DAT_00b04800 = 1;

        local_8 = CONCAT31(local_8._1_3_,5);

        uVar6 = FUN_0094b9c0(&DAT_00d1a840);

        local_8._0_1_ = 1;

        local_8._1_3_ = 0;

        local_1c = uVar6;

      }

      else {

        uVar6 = FUN_0094b9c0(&DAT_00d1a840);

      }

      FUN_0076d2a0();

      (**(code **)*piVar4)(1);

      CloseHandle(local_18);

      local_8 = (uint)local_8._1_3_ << 8;

      FUN_0076c8a0();

      local_8 = 0xffffffff;

      FUN_004050d0();

      ExceptionList = local_10;

      return uVar6;

    }

    CloseHandle(local_18);

    local_8 = (uint)local_8._1_3_ << 8;

    FUN_0076c8a0();

    local_8 = 0xffffffff;

    FUN_004050d0();

  }

  ExceptionList = local_10;

  return 1;

}
