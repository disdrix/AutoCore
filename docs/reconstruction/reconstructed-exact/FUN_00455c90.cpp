// =============================================================================
// FUN_00455c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00455c90
// Address:   0x00455c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00455c90 @ 0x00455c90
// Stable ID: aa_00455c90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×11, return×9.
//  - Notable callees: FUN_00442a50×2, FUN_0046be60×2, SkillSet_GetEntryCount×2, FUN_00452e90, FUN_00455c90.
//  - Return sites: 9.

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

void * __fastcall FUN_00455c90(void *param_1)



{

  void *pvVar1;

  int iVar2;

  char cVar3;

  void *in_EAX;

  uint uVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint uVar7;

  

  if (param_1 == in_EAX) {

    return param_1;

  }

  if (*(int *)((int)in_EAX + 4) != 0) {

    iVar6 = *(int *)((int)in_EAX + 8) - *(int *)((int)in_EAX + 4);

    iVar2 = iVar6 >> 0x1f;

    iVar6 = iVar6 / 0x18 + iVar2;

    uVar7 = iVar6 - iVar2;

    if (iVar6 != iVar2) {

      pvVar1 = *(void **)((int)param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = (*(int *)((int)param_1 + 8) - (int)pvVar1) / 0x18;

      }

      if (uVar7 <= uVar4) {

        FUN_00442a50(param_1);

        if (*(int *)((int)in_EAX + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)((int)param_1 + 8) = *(uint32_t /* width from decompiler */ *)((int)param_1 + 4);

          return param_1;

        }

        *(int *)((int)param_1 + 8) =

             *(int *)((int)param_1 + 4) +

             ((*(int *)((int)in_EAX + 8) - *(int *)((int)in_EAX + 4)) / 0x18) * 0x18;

        return param_1;

      }

      if (pvVar1 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = (*(int *)((int)param_1 + 0xc) - (int)pvVar1) / 0x18;

      }

      if (uVar4 < uVar7) {

        if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        SkillSet_GetEntryCount(in_EAX);

        cVar3 = FUN_00452e90();

        if (cVar3 == '\0') {

          return param_1;

        }

        uVar5 = FUN_0046be60(param_1);

        *(uint32_t /* width from decompiler */ *)((int)param_1 + 8) = uVar5;

        return param_1;

      }

      SkillSet_GetEntryCount(param_1);

      FUN_00442a50(param_1);

      uVar5 = FUN_0046be60(param_1);

      *(uint32_t /* width from decompiler */ *)((int)param_1 + 8) = uVar5;

      return param_1;

    }

  }

  if (*(void **)((int)param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)((int)param_1 + 4));

  }

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0xc) = 0;

  return param_1;

}
