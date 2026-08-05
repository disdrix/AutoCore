// =============================================================================
// FUN_006231a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006231a0
// Address:   0x006231a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006231a0 @ 0x006231a0
// Stable ID: aa_006231a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, goto×2.
//  - Notable callees: CONCAT22, CVOGReaction_CastSkillOnTarget, FUN_00578270, FUN_006186c0, FUN_006231a0, __RTDynamicCast.
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

void __fastcall FUN_006231a0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint16_t extraout_var;

  uint16_t uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  if (*(char *)(param_1 + 0x6a4) != '\0') {

    FUN_006186c0();

    return;

  }

  local_20 = DAT_00d02b40;

  local_1c = DAT_00d02b44;

  local_18 = DAT_00d02b48;

  local_14 = DAT_00d02b4c;

  iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

  if (iVar1 == 0) {

LAB_0062326c:

    iVar1 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),0,

                            &CVOGClonedObjectBase::RTTI_Type_Descriptor,

                            &CVOGPhysicsBase::RTTI_Type_Descriptor,0);

    uVar5 = extraout_var;

    if (iVar1 == 0) goto LAB_006232d3;

    puVar4 = *(uint32_t /* width from decompiler */ **)(iVar1 + 8);

    if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar4 = *(uint32_t /* width from decompiler */ **)(iVar1 + 4);

      puVar2 = (uint32_t /* width from decompiler */ *)(puVar4[1] + 0x84 + iVar1);

    }

    else {

      puVar2 = (uint32_t /* width from decompiler */ *)(puVar4[0xf] + 0xb0);

    }

    local_20 = *puVar2;

    local_1c = puVar2[1];

    local_18 = puVar2[2];

    local_14 = puVar2[3];

  }

  else {

    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

    if (*(int *)(iVar1 + 0x250) == 0) goto LAB_0062326c;

    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

    iVar1 = *(int *)(iVar1 + 0x250);

    if (*(int *)(iVar1 + 8) == 0) {

      puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x84 + iVar1);

    }

    else {

      puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar1 + 8) + 0x3c) + 0xb0);

    }

    local_20 = *puVar4;

    local_1c = puVar4[1];

    local_18 = puVar4[2];

    local_14 = puVar4[3];

  }

  uVar5 = (uint16_t)((uint)puVar4 >> 0x10);

LAB_006232d3:

  puVar2 = CVOGReaction_ResolveSkillTargets

                     (*(void **)(param_1 + 0x174),

                      CONCAT22(uVar5,*(short *)(param_1 + 0x61a) + *(short *)(param_1 + 0x198)));

  uVar12 = 0;

  uVar11 = 1;

  uVar10 = 0xffffffff;

  uVar9 = 0;

  puVar4 = &local_20;

  uVar8 = 0;

  uVar7 = 0;

  uVar6 = 0;

  uVar3 = FUN_00578270(0,0,0,puVar4,0,0xffffffff,1,0);

  CVOGReaction_CastSkillOnTarget(puVar2,uVar3,uVar6,uVar7,uVar8,puVar4,uVar9,uVar10,uVar11,uVar12);

                    /* WARNING: Subroutine does not return */

  operator_delete(puVar2);

}
