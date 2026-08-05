// =============================================================================
// FUN_00531570
// -----------------------------------------------------------------------------
// Stable ID: aa_00531570
// Address:   0x00531570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00531570 @ 0x00531570
// Stable ID: aa_00531570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×7, return×5.
//  - Notable callees: CVOGReaction_RemoveInventoryItem×2, FUN_005711c0×2, FUN_005310a0, FUN_00531570, FUN_005713a0.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ __thiscall FUN_00531570(int param_1,int param_2,int param_3)



{

  int iVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  uint8_t local_e;

  uint8_t local_d;

  int local_c;

  int local_8;

  int local_4;

  

  if (param_2 == 0) {

    return 0;

  }

  if (((*(int *)(param_1 + 0x250) != 0) && (*(int *)(*(int *)(param_1 + 0x250) + 0x2b0) != 0)) &&

     (local_c = *(int *)(param_1 + 0xcbc), local_c != 0)) {

    if ((*(int *)(param_2 + 0x38) == 0x1a) && (iVar1 = *(int *)(param_2 + 0x3c), iVar1 != 0)) {

      local_4 = param_1;

      iVar3 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x4c0),0);

      iVar4 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x4c0),0);

      if (param_3 <= iVar4 + iVar3) {

        iVar3 = (uint)*(byte *)(iVar1 + 0x4c9) * param_3;

        local_8 = *(int *)(param_2 + 0x34);

        if ((0 < iVar3) && (local_8 != -1)) {

          local_d = 0;

          local_e = 0;

          cVar2 = FUN_005713a0(*(uint8_t *)(*(int *)(param_2 + 0x3c) + 0x406),

                               *(uint8_t *)(*(int *)(param_2 + 0x3c) + 0x407),&local_d,&local_e,

                               0xffffffff);

          if (cVar2 != '\0') {

            iVar4 = CVOGReaction_RemoveInventoryItem(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x4c0),param_3);

            if (0 < param_3 - iVar4) {

              CVOGReaction_RemoveInventoryItem(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x4c0),param_3 - iVar4);

            }

            FUN_005310a0(local_8,iVar3);

            return 1;

          }

        }

      }

      return 0;

    }

    return 0;

  }

  return 0;

}
