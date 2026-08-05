// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, goto×1.
//  - Notable callees: FUN_00754680×2, FUN_007a4480×2, block×2, FUN_007a3e90, FUN_009701d0, FUN_00989e00, InitializeCriticalSection.
//  - Strings: "PalShadowProjection.fx".
//  - Return sites: 3.

// =============================================================================
// Drive_failed_to_init_with_hardware_driver_trying_again
// -----------------------------------------------------------------------------
// Stable ID: aa_007a3e90
// Address:   0x007a3e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "failed to init with hardware driver, trying again with Reference drivers"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007a403b) */

/* WARNING: Removing unreachable block (ram,0x007a4040) */



uint32_t /* width from decompiler */ __thiscall

Drive_failed_to_init_with_hardware_driver_trying_again(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3,uint8_t param_4,uint8_t param_5,

            uint32_t /* width from decompiler */ param_6)



{

  int *piVar1;

  int iVar2;

  int *unaff_EBX;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  piVar1 = param_3;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b40f2;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8) = param_2;

  iVar2 = *param_3;

  *(int *)(param_1 + 0x108) = *unaff_EBX;

  *(int *)(param_1 + 0x104) = iVar2;

  iVar2 = *param_3;

  *(int *)(param_1 + 0x110) = *unaff_EBX;

  *(int *)(param_1 + 0x10c) = iVar2;

  *(uint8_t *)(param_1 + 0xe2) = param_4;

  *(uint8_t *)(param_1 + 0xe3) = param_5;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf8) = 4;

  *(uint8_t *)(param_1 + 0xe1) = 1;

  iVar2 = FUN_00754680(param_1,param_1 + 0xd8,&param_3,param_6);

  if (-1 < iVar2) {

    if ((param_3[1] != *piVar1) || (param_3[2] != *unaff_EBX)) {

      *piVar1 = param_3[1];

      *unaff_EBX = param_3[2];

      ExceptionList = local_c;

      return 2;

    }

LAB_007a3fc7:

    *(uint8_t *)(DAT_00d1f048 + 0xe) = 0;

    *(uint8_t *)(DAT_00d1f048 + 0xf) = 1;

    *(uint8_t *)(DAT_00d1f048 + 0x2d) = 1;

    InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2b8));

    local_4 = 0;

    FUN_00989e00(&param_5,"PalShadowProjection.fx");

    FUN_009701d0(&param_5);

    ExceptionList = local_c;

    return 1;

  }

  if (*(char *)(param_1 + 0xe0) == '\0') {

    FUN_007a4480(0xffffffff,

                 "failed to init with hardware driver, trying again with Reference drivers");

    *(bool *)(param_1 + 0xe0) = *(char *)(param_1 + 0xe0) == '\0';

    iVar2 = FUN_00754680(param_1,param_1 + 0xd8,&param_3,param_6);

    if (-1 < iVar2) goto LAB_007a3fc7;

  }

  FUN_007a4480(1,

               "ERROR: Unable to init palantir to fullscreen=%d, antialiased=%d, %dx%d, hWnd=0x%08X... prepare to crash...\n"

               ,param_4,param_5,*piVar1,*unaff_EBX,param_2);

  ExceptionList = local_c;

  return 0;

}
