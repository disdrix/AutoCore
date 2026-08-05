// =============================================================================
// FUN_004b4eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b4eb0
// Address:   0x004b4eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b4eb0 @ 0x004b4eb0
// Stable ID: aa_004b4eb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00498ad0, FUN_004b4ba0, FUN_004b4eb0, ROUND, floor.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_004b4eb0(int *param_1)



{

  int *piVar1;

  void *pvVar2;

  int iVar3;

  double dVar4;

  uint32_t /* width from decompiler */ local_74;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a1475;

  local_c = ExceptionList;

  if ((int *)*param_1 != (int *)0x0) {

    local_58 = DAT_00aaa9ec;

    local_68 = 0;

    local_60 = 0;

    local_5c = 0;

    local_64 = 0;

    local_54 = 8;

    local_50 = 0;

    local_4c = 0;

    local_48 = 0;

    local_44 = 0;

    local_40 = 0;

    local_3c = 0;

    local_10 = 0;

    local_38 = 0x44;

    local_34 = 0;

    local_30 = 0;

    local_2c = 0;

    local_20 = 0;

    local_1c = 1;

    local_18 = 0;

    local_14 = 1;

    local_28 = 0x55555554;

    local_24 = 0x55555554;

    local_74 = 0;

    local_70 = DAT_009cb240;

    local_6c = 0;

    ExceptionList = &local_c;

    if (DAT_00af0758 != '\0') {

      ExceptionList = &local_c;

      (**(code **)(*(int *)*param_1 + 0x5c))();

    }

    local_44 = 0;

    piVar1 = (int *)(**(code **)(*(int *)*param_1 + 0x10))(&local_74);

    param_1[1] = (int)piVar1;

    if (piVar1 != (int *)0x0) {

      (**(code **)(*piVar1 + 0x5c))(4,4,0);

      (**(code **)(*(int *)param_1[1] + 0x5c))(4,4,0);

      (**(code **)(*(int *)param_1[1] + 0x5c))(0,4,0);

      (**(code **)(*(int *)param_1[1] + 0x5c))(1,4,0);

      (**(code **)(*(int *)param_1[1] + 0x5c))(2,4,0);

      (**(code **)(*(int *)param_1[1] + 0x5c))(3,4,0);

      dVar4 = floor(_DAT_009cb238);

      (**(code **)(*(int *)param_1[1] + 0xe0))(0x3d088889,(int)ROUND(dVar4),0);

      (**(code **)(*(int *)param_1[1] + 0x5c))(0,2,1);

      (**(code **)(*(int *)param_1[1] + 0x5c))(0,3,1);

      (**(code **)(*(int *)param_1[1] + 0x5c))(1,2,1);

      (**(code **)(*(int *)param_1[1] + 0x5c))(1,3,1);

      (**(code **)(*(int *)param_1[1] + 0x5c))(2,3,0);

      (**(code **)(*(int *)param_1[1] + 0x5c))(5,3,0);

      (**(code **)(*(int *)param_1[1] + 0x5c))(5,2,1);

      (**(code **)(*(int *)param_1[1] + 0x5c))(5,4,0);

      FUN_004b4ba0();

      pvVar2 = operator_new(8);

      uStack_4 = 0;

      if (pvVar2 != (void *)0x0) {

        iVar3 = FUN_00498ad0();

        param_1[4] = iVar3;

        ExceptionList = local_c;

        return;

      }

      param_1[4] = 0;

    }

  }

  ExceptionList = local_c;

  return;

}
