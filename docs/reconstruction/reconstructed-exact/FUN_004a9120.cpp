// =============================================================================
// FUN_004a9120
// -----------------------------------------------------------------------------
// Stable ID: aa_004a9120
// Address:   0x004a9120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a9120 @ 0x004a9120
// Stable ID: aa_004a9120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, while×1, for×1.
//  - Notable callees: FUN_004a9120, FUN_005be770, FUN_005be7f0, FUN_005be840, FUN_0076c3c0, FUN_0076c4a0, FUN_0076c4d0, FUN_0076c500.
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

void __thiscall

FUN_004a9120(int param_1,int *param_2,uint param_3,uint param_4,uint param_5,uint param_6)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  char cVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  int local_44;

  void *local_40;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1220;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076c500(10000);

  if (param_3 <= param_4) {

    while (uVar3 = param_5, param_3 < *(uint *)(param_1 + 900)) {

      for (; (uVar3 <= param_6 && (uVar3 < *(uint *)(param_1 + 0x388))); uVar3 = uVar3 + 1) {

        uVar6 = 0;

        if (*(int *)(*(int *)(param_1 + 0x38c) + (*(int *)(param_1 + 900) * uVar3 + param_3) * 4) ==

            0) {

          FUN_0076c4d0();

          local_40 = operator_new(0x180d8);

          local_4 = 0;

          if (local_40 != (void *)0x0) {

            uVar6 = FUN_005be7f0();

          }

          local_4 = 0xffffffff;

          cVar4 = FUN_005be770(&local_44);

          if (cVar4 != '\0') {

            piVar1 = (int *)(*(int *)(param_1 + 0x38c) +

                            (*(int *)(local_44 + 0xd4) * *(int *)(param_1 + 900) +

                            *(int *)(local_44 + 0xd0)) * 4);

            puVar2 = (uint32_t /* width from decompiler */ *)*piVar1;

            if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

              (**(code **)*puVar2)(1);

            }

            *piVar1 = 0;

          }

          FUN_005be840(param_3,uVar3,param_1);

          *(uint32_t /* width from decompiler */ *)

           (*(int *)(param_1 + 0x38c) + (*(int *)(param_1 + 900) * uVar3 + param_3) * 4) = uVar6;

          FUN_0076c4a0();

          iVar5 = FUN_0076c3c0();

          *param_2 = *param_2 - iVar5;

          if (*param_2 < 0) {

            ExceptionList = local_c;

            return;

          }

        }

      }

      param_3 = param_3 + 1;

      if (param_4 < param_3) {

        ExceptionList = local_c;

        return;

      }

    }

  }

  ExceptionList = local_c;

  return;

}
