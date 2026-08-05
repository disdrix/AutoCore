// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007e1d80
// -----------------------------------------------------------------------------
// Stable ID: aa_007e1d80
// Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
// Address:   0x007e1d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper. Evidence string: "Cnxn Str: %S\n". Supports parent flow (not a free-standing entry point). Named_VOG_DEBUG_STOP (+3 other named callers).
// Embedded strings (evidence):
//   - "Cnxn Str: %S\n"
//   - "After OpenFromInitializationString\n"
//   - "PrepareDataConnection:  Unable to connect to RM."
//   - "DBReader: %u against %s"
//   - "PrepareDataConnection:  Unable to open RM."
//   - "PrepareDataConnection:  Unable to verify version."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×11, return×4, goto×4.
//  - Notable callees: FUN_0041a3e0×3, FUN_007a4480×3, FUN_00423170×2, OutputDebugStringA×2, FUN_0041a3b0, FUN_0041a810, FUN_0041a990, FUN_0041a9b0.
//  - Strings: "Cnxn Str: %S\n"; "After OpenFromInitializationString\n"; "PrepareDataConnection:  Unable to connect to RM."; "DBReader: %u against %s".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_007e1d80(uint8_t *param_1)



{

  int iVar1;

  char *pcVar2;

  int *local_240;

  int *piStack_23c;

  uint8_t auStack_238 [8];

  int **ppiStack_230;

  int iStack_228;

  char local_20c [512];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009af050;

  local_c = ExceptionList;

  if ((*(int *)(param_1 + 0x20) != 0) || (DAT_00d1793c != '\0')) {

LAB_007e1f8e:

    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;

    ExceptionList = local_c;

    return 0;

  }

  ExceptionList = &local_c;

  sprintf(local_20c,"Cnxn Str: %S\n",param_1 + 0x2c);

  OutputDebugStringA(local_20c);

  iVar1 = FUN_00423370(param_1 + 0x2c,0);

  OutputDebugStringA("After OpenFromInitializationString\n");

  if (iVar1 < 0) {

    pcVar2 = "PrepareDataConnection:  Unable to connect to RM.";

LAB_007e1e4b:

    FUN_007a4480(1,"DBReader: %u against %s",iVar1,pcVar2);

    ExceptionList = local_c;

    return 0;

  }

  local_240 = (int *)0x0;

  iVar1 = (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x24))

                    (*(uint32_t /* width from decompiler */ **)(param_1 + 0x24),&DAT_00a8603c,&local_240);

  if (-1 < iVar1) {

    iVar1 = (**(code **)(*local_240 + 0xc))(local_240,0,&DAT_00a8602c,param_1 + 0x28);

  }

  if (local_240 != (int *)0x0) {

    (**(code **)(*local_240 + 8))(local_240);

  }

  if (iVar1 < 0) {

    pcVar2 = "PrepareDataConnection:  Unable to open RM.";

    goto LAB_007e1e4b;

  }

  *param_1 = 1;

  if (param_1[1] != '\0') goto LAB_007e1f8e;

  local_240 = (int *)0x0;

  FUN_0041a3b0();

  uStack_4 = 0;

  iVar1 = FUN_0041a810(auStack_238,param_1 + 0x28,0,0,&DAT_00a140c8,0,0);

  ppiStack_230 = &piStack_23c;

  if ((-1 < iVar1) && (iVar1 = FUN_004231d0(auStack_238,1,4), -1 < iVar1)) {

    if (iStack_228 != 0) {

      iVar1 = FUN_0041a9b0();

      if (iVar1 == 0) {

        local_240 = piStack_23c;

      }

      FUN_0041a990();

      FUN_00423170();

      if (iVar1 != 0) {

        FUN_007a4480(1,"DBReader: %u against %s",iVar1,

                     "PrepareDataConnection:  Unable to verify version.");

        uStack_4 = 0xffffffff;

        FUN_0041a3e0(auStack_238);

        ExceptionList = local_c;

        return 0;

      }

      if (local_240 == (int *)0x9) {

        param_1[1] = 1;

        uStack_4 = 0xffffffff;

        FUN_0041a3e0(auStack_238);

        goto LAB_007e1f8e;

      }

      pcVar2 = "PrepareDataConnection:  Invalid version.";

      iVar1 = -0x7ffbf1fd;

      goto LAB_007e1f4f;

    }

    iVar1 = -0x7fffbffb;

  }

  FUN_00423170();

  pcVar2 = "PrepareDataConnection::dcver::Open";

LAB_007e1f4f:

  FUN_007a4480(1,"DBReader: %u against %s",iVar1,pcVar2);

  uStack_4 = 0xffffffff;

  FUN_0041a3e0(auStack_238);

  ExceptionList = local_c;

  return 0;

}
