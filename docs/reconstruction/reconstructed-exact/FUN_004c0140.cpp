// =============================================================================
// FUN_004c0140
// -----------------------------------------------------------------------------
// Stable ID: aa_004c0140
// Address:   0x004c0140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c0140 @ 0x004c0140
// Stable ID: aa_004c0140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: CONCAT31, FUN_004bff90, FUN_004c0140, FUN_005c6b40, FUN_005c6c70, FUN_005c7df0, FUN_00797170.
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

uint FUN_004c0140(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

                 uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,char param_8)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  undefined3 uVar4;

  undefined3 extraout_var;

  void *pvVar3;

  void *local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint8_t local_30 [20];

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a1977;

  local_1c = ExceptionList;

  pvVar3 = ExceptionList;

  if ((param_1 != 0) && (*(char *)(param_1 + 0xf) == '\0')) {

    local_38 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x6c);

    local_3c = *(uint32_t /* width from decompiler */ *)(param_2 + 0x68);

    local_40 = *(uint32_t /* width from decompiler */ *)(param_2 + 100);

    local_34 = 0;

    ExceptionList = &local_1c;

    FUN_00797170(local_30);

    if (param_8 == '\0') {

      puVar1 = (uint32_t /* width from decompiler */ *)

               FUN_004bff90(param_1,&local_40,local_30,*(char *)(param_2 + 0xa0) == '\0',param_7,0);

    }

    else {

      local_44 = operator_new(0x80);

      local_14 = 0;

      if (local_44 == (void *)0x0) {

        puVar1 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        puVar1 = (uint32_t /* width from decompiler */ *)

                 FUN_005c6b40(param_1,&local_40,local_30,*(char *)(param_2 + 0xa0) == '\0',param_7,0

                             );

      }

      local_14 = 0xffffffff;

    }

    pvVar3 = (void *)0x0;

    if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      uVar2 = FUN_005c6c70(param_2,param_3,param_4,param_5,param_6);

      *(uint8_t *)((int)puVar1 + 0x66) = 1;

      uVar4 = (undefined3)((uint)uVar2 >> 8);

      *(bool *)((int)puVar1 + 0x6a) = *(char *)(param_2 + 0xa0) == '\0';

      if (param_8 != '\0') {

        local_44 = DAT_00aaaafc;

        FUN_005c7df0(&local_44,1);

        (**(code **)*puVar1)(1);

        uVar4 = extraout_var;

      }

      ExceptionList = local_1c;

      return CONCAT31(uVar4,1);

    }

  }

  ExceptionList = local_1c;

  return (uint)pvVar3 & 0xffffff00;

}
