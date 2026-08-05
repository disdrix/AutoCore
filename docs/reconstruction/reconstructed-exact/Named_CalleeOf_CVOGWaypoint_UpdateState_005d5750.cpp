// =============================================================================
// Named_CalleeOf_CVOGWaypoint_UpdateState_005d5750
// -----------------------------------------------------------------------------
// Stable ID: aa_005d5750
// Callee of CVOGWaypoint_UpdateState
// Address:   0x005d5750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGWaypoint_UpdateState: AI/path helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×11, return×4.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_005d5750, __RTDynamicCast.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of CVOGWaypoint_UpdateState
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall Named_CalleeOf_CVOGWaypoint_UpdateState_005d5750(int param_1)



{

  uint8_t uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ unaff_ESI;

  float unaff_EDI;

  float fVar6;

  uint32_t /* width from decompiler */ uVar7;

  TypeDescriptor *pTVar8;

  TypeDescriptor *pTVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  int local_2c;

  uint8_t local_24 [4];

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  if ((*(uint *)(param_1 + 0x40) & *(uint *)(param_1 + 0x44)) != 0xffffffff) {

    uVar10 = 0;

    pTVar9 = &CVOGMapPath::RTTI_Type_Descriptor;

    pTVar8 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

    uVar7 = 0;

    uVar2 = CVOGReaction_ResolveObjectTarget(0,*(uint *)(param_1 + 0x40),*(uint *)(param_1 + 0x44));

    piVar3 = (int *)__RTDynamicCast(uVar2,uVar7,pTVar8,pTVar9,uVar10);

    if (piVar3 != (int *)0x0) {

      local_2c = *(int *)(param_1 + 0x10);

      if (*(int *)(local_2c + 8) == 0) {

        puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(local_2c + 4) + 4) + 0x84 + local_2c);

      }

      else {

        puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(local_2c + 8) + 0x3c) + 0xb0);

      }

      local_20 = *puVar4;

      local_1c = puVar4[1];

      local_18 = puVar4[2];

      local_14 = puVar4[3];

      if (local_2c == 0) {

        local_2c = 0;

      }

      else {

        local_2c = *(int *)(*(int *)(local_2c + 4) + 4) + 4 + local_2c;

      }

      iVar5 = param_1 + 0x58;

      uVar1 = (**(code **)(*piVar3 + 0x2cc))

                        (&local_20,(int *)(param_1 + 0x48),param_1 + 0x20,local_2c,param_1 + 0x51,

                         local_24);

      *(uint8_t *)(param_1 + 0x52) = uVar1;

      if (((iVar5 != *(int *)(param_1 + 0x48)) &&

          (iVar5 = (**(code **)(*piVar3 + 0x2c0))(iVar5), iVar5 != 0)) &&

         (*(int *)(iVar5 + 0x18) != 0)) {

        *(uint *)(param_1 + 0x54) = *(int *)(iVar5 + 0x18) + g_dwClientTickMs;

      }

      if (*(uint *)(param_1 + 0x54) != 0) {

        if (*(uint *)(param_1 + 0x54) < g_dwClientTickMs) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

        }

        else {

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = unaff_ESI;

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = unaff_EBX;

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uStack_34;

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = uStack_30;

        }

      }

      if ((DAT_00a0f694 < *(float *)(param_1 + 0x58) || DAT_00a0f694 == *(float *)(param_1 + 0x58))

         || (DAT_00a0f694 <= unaff_EDI)) {

        fVar6 = 0.0;

      }

      else {

        fVar6 = (DAT_00a0f694 - *(float *)(param_1 + 0x58)) * DAT_00a10e78;

        if (g_flOne <= fVar6) {

          fVar6 = g_flOne;

        }

        fVar6 = (DAT_00a0f694 - unaff_EDI) * _DAT_00aaab14 * fVar6;

      }

      *(float *)(param_1 + 0x58) = fVar6;

      if (*(float *)(param_1 + 0x4c) <= unaff_EDI) {

        *(uint8_t *)(param_1 + 0x53) = 0;

        return;

      }

      *(uint8_t *)(param_1 + 0x53) = 1;

      return;

    }

  }

  *(uint8_t *)(param_1 + 0x52) = 0;

  if (*(char *)(param_1 + 0x5c) == '\0') {

    return;

  }

  *(uint8_t *)(param_1 + 0x50) = 2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0xffffffff;

  *(uint8_t *)(param_1 + 0x51) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  return;

}
