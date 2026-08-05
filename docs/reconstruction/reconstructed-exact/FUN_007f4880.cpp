// =============================================================================
// FUN_007f4880
// -----------------------------------------------------------------------------
// Stable ID: aa_007f4880
// Address:   0x007f4880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007f4880 @ 0x007f4880
// Stable ID: aa_007f4880
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "dcVehicle::Open"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_004231d0×11, block×4, FUN_0041a3e0, FUN_0041a810, FUN_00422fb0, FUN_004230d0, FUN_00423170, FUN_007a4480.
//  - Strings: "DBReader: %u against %s"; "dcVehicle::Open".
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

/* WARNING: Removing unreachable block (ram,0x007f4b69) */

/* WARNING: Removing unreachable block (ram,0x007f4ba1) */

/* WARNING: Removing unreachable block (ram,0x007f4b78) */

/* WARNING: Removing unreachable block (ram,0x007f4c1e) */



int __thiscall

FUN_007f4880(char *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  uint8_t auStack_5c [8];

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b0f3c;

  local_c = ExceptionList;

  if (DAT_00d1793c != '\0') {

    return -0x7fffbfff;

  }

  local_54 = *param_2;

  if (*param_1 != '\0') {

    ExceptionList = &local_c;

    *param_4 = 0;

    param_4[1] = 0;

    param_4[2] = 0;

    param_4[3] = 0;

    param_4[4] = 0;

    param_4[5] = 0;

    param_4[6] = 0;

    param_4[7] = 0;

    param_4[8] = 0;

    iVar1 = FUN_007e59d0(param_2,param_3);

    if (-1 < iVar1) {

      uStack_40 = 0;

      uStack_3c = 0;

      local_c = (void *)0x0;

      FUN_004230d0(&uStack_40,auStack_5c);

      iVar1 = FUN_00422fb0(1,1,4);

      if (-1 < iVar1) {

        iVar1 = FUN_0041a810(&uStack_40,param_1 + 0x28,0,0,&DAT_00a140c8,0,0);

      }

      if (((((-1 < iVar1) && (iVar1 = FUN_004231d0(&uStack_40,1,2), -1 < iVar1)) &&

           (iVar1 = FUN_004231d0(&uStack_40,2,1), -1 < iVar1)) &&

          ((((iVar1 = FUN_004231d0(&uStack_40,3,1), -1 < iVar1 &&

             (iVar1 = FUN_004231d0(&uStack_40,4,2), -1 < iVar1)) &&

            ((iVar1 = FUN_004231d0(&uStack_40,5,4), -1 < iVar1 &&

             ((iVar1 = FUN_004231d0(&uStack_40,6,4), -1 < iVar1 &&

              (iVar1 = FUN_004231d0(&uStack_40,7,4), -1 < iVar1)))))) &&

           (iVar1 = FUN_004231d0(&uStack_40,8,4), -1 < iVar1)))) &&

         (((iVar1 = FUN_004231d0(&uStack_40,9,4), -1 < iVar1 &&

           (iVar1 = FUN_004231d0(&uStack_40,10,2), -1 < iVar1)) &&

          (iVar1 = FUN_004231d0(&uStack_40,0xb,4), -1 < iVar1)))) {

        iVar1 = -0x7fffbffb;

      }

      FUN_00423170();

      FUN_007a4480(1,"DBReader: %u against %s",iVar1,"dcVehicle::Open");

      local_c = (void *)0xffffffff;

      FUN_0041a3e0(&uStack_40);

      iVar1 = 0;

    }

    ExceptionList = pvStack_14;

    return iVar1;

  }

  return -0x7fffbffc;

}
