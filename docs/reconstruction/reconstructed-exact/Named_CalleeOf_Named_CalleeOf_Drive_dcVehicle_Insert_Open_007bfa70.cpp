// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Insert_Open_007bfa70
// -----------------------------------------------------------------------------
// Stable ID: aa_007bfa70
// Callee of Named_CalleeOf_Drive_dcVehicle_Insert_Open
// Address:   0x007bfa70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_dcVehicle_Insert_Open: drive/input helper. Evidence string: "DBReader: %u against %s". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "DBReader: %u against %s"
//   - "dcDamage_Insert::MoveFirst"
//   - "dcDamage::Open"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, goto×1.
//  - Notable callees: FUN_00422fb0×7, FUN_00423170×3, FUN_0041a990×2, FUN_007a4480×2, FUN_0041a3e0, FUN_0041a810, FUN_0041a9b0, FUN_004230d0.
//  - Strings: "DBReader: %u against %s"; "dcDamage_Insert::MoveFirst"; "dcDamage::Open".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_dcVehicle_Insert_Open
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Insert_Open_007bfa70(char *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ *local_30;

  uint32_t /* width from decompiler */ local_2c;

  int local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ *local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puVar1 = param_3;

  puStack_8 = &LAB_009ae190;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return 0x80004004;

  }

  if (DAT_00d1793c != '\0') {

    return 0;

  }

  param_3 = (uint32_t /* width from decompiler */ *)*param_3;

  local_38 = 0;

  local_34 = 0;

  local_30 = (uint32_t /* width from decompiler */ *)0x0;

  local_2c = 0;

  local_28 = 0;

  local_24 = 0;

  local_20 = &local_38;

  local_18 = 0;

  local_1c = 0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_004230d0(local_20,&param_3);

  iVar2 = FUN_00422fb0(1,1,4);

  if (((((-1 < iVar2) && (iVar2 = FUN_00422fb0(1,2,2), -1 < iVar2)) &&

       (iVar2 = FUN_00422fb0(1,3,2), -1 < iVar2)) &&

      ((iVar2 = FUN_00422fb0(1,4,2), -1 < iVar2 && (iVar2 = FUN_00422fb0(1,5,2), -1 < iVar2)))) &&

     ((iVar2 = FUN_00422fb0(1,6,2), -1 < iVar2 && (iVar2 = FUN_00422fb0(1,7,2), -1 < iVar2)))) {

    iVar2 = FUN_0041a810(&local_38,param_1 + 0x28,0,0,&DAT_00a140c8,0,0);

  }

  local_30 = &param_2;

  if ((-1 < iVar2) && (iVar2 = FUN_004231d0(&local_38,1,4), -1 < iVar2)) {

    if (local_28 != 0) {

      iVar2 = FUN_0041a9b0();

      if (iVar2 == 0) {

        *puVar1 = param_2;

        FUN_0041a990();

        FUN_00423170();

      }

      else {

        FUN_0041a990();

        FUN_00423170();

        FUN_007a4480(1,"DBReader: %u against %s",iVar2,"dcDamage_Insert::MoveFirst");

      }

      goto LAB_007bfce7;

    }

    iVar2 = -0x7fffbffb;

  }

  FUN_00423170();

  FUN_007a4480(1,"DBReader: %u against %s",iVar2,"dcDamage::Open");

LAB_007bfce7:

  local_4 = 0xffffffff;

  FUN_0041a3e0(&local_38);

  ExceptionList = local_c;

  return 0;

}
