// =============================================================================
// FUN_00951390
// -----------------------------------------------------------------------------
// Stable ID: aa_00951390
// Address:   0x00951390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00951390 @ 0x00951390
// Stable ID: aa_00951390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, while×2, do×1, goto×1.
//  - Notable callees: FUN_004022a0×2, __RTDynamicCast×2, CVOGReaction_TeleportTarget, FUN_004294f0, FUN_004bade0, FUN_004badf0, FUN_00951390, LeaveCriticalSection.
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

uint32_t /* width from decompiler */ __thiscall FUN_00951390(int param_1,int param_2,char *param_3)



{

  int iVar1;

  void *this;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *pTeleportData;

  int local_34;

  int local_30;

  uint32_t /* width from decompiler */ local_2c;

  char *local_28;

  int local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  iVar3 = 0;

  local_30 = 0;

  *(uint8_t *)(param_2 + 0x2e) = 0;

  local_24 = param_1;

  local_28 = strtok((char *)0x0,param_3);

  if (*(int *)(param_1 + 0xe98) == 0) {

    return 0;

  }

  FUN_004bade0();

  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0xe04) + 0xe4e8) + 0x18);

  iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 0x10) + (*(uint *)(iVar2 + 8) & 0x38) * 4) + 4);

  local_2c = 0;

  do {

    if (iVar2 == 0) {

LAB_00951426:

      local_34 = 0;

      iVar2 = 0;

      if (iVar3 != 0) {

        FUN_004294f0();

        FUN_004022a0(&local_2c,&local_34);

        iVar2 = local_34;

        while (local_34 = iVar2, iVar2 != 0) {

          iVar1 = __RTDynamicCast(iVar2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                  &CVOGTrigger::RTTI_Type_Descriptor,0);

          iVar1 = _stricmp((char *)(iVar1 + 0xe3),local_28);

          if (iVar1 == 0) {

            local_30 = __RTDynamicCast(iVar2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                       &CVOGTrigger::RTTI_Type_Descriptor,0);

          }

          FUN_004022a0(&local_2c,&local_34);

          param_1 = local_24;

          iVar2 = local_34;

        }

        iVar2 = local_30;

        if (*(char *)(iVar3 + 0x28) != '\0') {

          *(uint8_t *)(iVar3 + 0x28) = 0;

          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));

          iVar2 = local_30;

        }

      }

      FUN_004badf0();

      if (iVar2 != 0) {

        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);

        local_20 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x84 + iVar2);

        local_1c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x88 + iVar2);

        local_18 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x8c + iVar2);

        local_14 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x90 + iVar2);

        pTeleportData = &local_20;

        this = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) +

                                             4 + *(int *)(param_1 + 0xe98)) + 0x19c))();

        CVOGReaction_TeleportTarget(this,pTeleportData);

      }

      return 1;

    }

    if (*(int *)(iVar2 + 0x10) == 0x38) {

      if (iVar2 != 0) {

        iVar3 = *(int *)(iVar2 + 8);

      }

      goto LAB_00951426;

    }

    iVar2 = *(int *)(iVar2 + 0xc);

  } while( true );

}
