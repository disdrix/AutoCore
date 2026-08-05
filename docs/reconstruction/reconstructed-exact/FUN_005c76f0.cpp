// =============================================================================
// FUN_005c76f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c76f0
// Address:   0x005c76f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c76f0 @ 0x005c76f0
// Stable ID: aa_005c76f0
// Embedded strings (evidence for future rename):
//   - "CLoadNode::_initPhysics"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_0076cef0×2, FUN_00404c30, FUN_00404c60, FUN_0053d430, FUN_0053dd40, FUN_0053e0d0, FUN_005c6ad0, FUN_005c7290.
//  - Strings: "CLoadNode::_initPhysics".
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

uint32_t /* width from decompiler */ __thiscall FUN_005c76f0(int param_1,int param_2,char param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6e3b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CLoadNode::_initPhysics");

  local_4 = 0;

  if (param_3 == '\0') {

    iVar1 = FUN_005c6ad0(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x14c);

    if (iVar1 == 3) {

      local_4 = 0xffffffff;

      FUN_0076cef0();

      ExceptionList = local_c;

      return 3;

    }

  }

  else {

    FUN_005c7290(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x14c);

  }

  *(uint8_t *)(param_1 + 0x67) = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)

           (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x1c8))();

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    if (*(char *)(param_1 + 0x69) == '\0') {

      if (puVar2[2] == 0) {

        iVar1 = *(int *)(*(int *)(param_2 + 4) + 4);

        if (*(int *)(*(int *)(iVar1 + 0xac + param_2) + 0x38) == 0xe) {

          FUN_00404c60(param_1 + 0x30);

          FUN_00404c30(param_1 + 0x40);

          FUN_0053e0d0();

        }

        else {

          (**(code **)*puVar2)

                    (*(uint32_t /* width from decompiler */ *)(iVar1 + param_2 + 0xa8),param_1 + 0x30,param_1 + 0x40,0);

        }

      }

      FUN_0053d430();

    }

    else {

      FUN_0053dd40();

    }

    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x38);

    if ((((((iVar1 != 0x12) && (iVar1 != 0xe)) && (iVar1 != 0xc)) &&

         ((iVar1 != 0x14 && (iVar1 != 0x1c)))) &&

        ((iVar1 != 10 && ((iVar1 != 0x10 && (puVar2[2] != 0)))))) &&

       (*(char *)(puVar2[2] + 0x40) != '\0')) {

      *(uint8_t *)(param_1 + 0x52) = 1;

    }

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return 0;

}
