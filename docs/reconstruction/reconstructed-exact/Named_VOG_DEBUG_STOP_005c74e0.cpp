// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×10, for×2, while×2, goto×2, return×2, do×1.
//  - Notable callees: FUN_007a4480×4, FUN_0076cef0×2, FUN_00411900, FUN_004a6390, FUN_00540090, FUN_00542790, FUN_005c74e0, FUN_0076cf00.
//  - Strings: "CLoadNode::_initSpecialFX"; "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_005c74e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c74e0
// Address:   0x005c74e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_005c74e0(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int local_414;

  int local_410;

  uint8_t local_40c [1024];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6e29;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CLoadNode::_initSpecialFX");

  iVar2 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;

  local_4 = 0;

  local_414 = 0;

  if ((*(char *)(*(int *)(iVar2 + 0xa8) + 0xf5) == '\0') &&

     (iVar2 = *(int *)(iVar2 + 0x74), iVar2 != 0)) {

    if (*(char *)(iVar2 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar2 + 0x1d) = 1;

    iVar1 = FUN_00411900(&local_414);

    iVar2 = local_414;

    while (iVar1 != 0) {

      if (*(int *)(DAT_00d1f050 + 0x6c) == 0) {

        iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf0c) + 0x10) +

                                 (*(uint *)(*(int *)(DAT_00b041fc + 0xf0c) + 8) &

                                 *(uint *)(iVar1 + 0x5fc)) * 4) + 4);

        if (iVar3 == 0) {

LAB_005c7604:

          iVar3 = 0;

        }

        else {

          do {

            if (*(uint *)(iVar1 + 0x5fc) == *(uint *)(iVar3 + 0x10)) {

              if (iVar3 == 0) goto LAB_005c7604;

              iVar3 = *(int *)(iVar3 + 8);

              goto LAB_005c760b;

            }

            iVar3 = *(int *)(iVar3 + 0xc);

          } while (iVar3 != 0);

          iVar3 = 0;

        }

LAB_005c760b:

        if ((iVar3 != 0) && (FUN_00540090(iVar1,local_40c,0x400), *(char *)(iVar3 + 10) == '\0')) {

          FUN_004a6390(local_40c);

          *(uint8_t *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x74 + param_1) + 0x1d) = 0

          ;

          local_4 = 0xffffffff;

          FUN_0076cef0();

          ExceptionList = local_c;

          return 0;

        }

      }

      else {

        FUN_00542790(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x5fc),4,1,0,0,0,0);

      }

      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x74 + param_1);

      if (*(char *)(iVar1 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar2 == 0) {

        iVar2 = *(int *)(iVar1 + 0x14);

      }

      else {

        iVar2 = *(int *)(iVar2 + 0x14);

      }

      if (iVar2 == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = *(int *)(iVar2 + 8);

      }

    }

    *(uint8_t *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x74 + param_1) + 0x1d) = 0;

  }

  *(uint8_t *)(local_410 + 0x62) = 0;

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return 1;

}
