// =============================================================================
// FUN_0058be30
// -----------------------------------------------------------------------------
// Stable ID: aa_0058be30
// Address:   0x0058be30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058be30 @ 0x0058be30
// Stable ID: aa_0058be30
// Embedded strings (evidence for future rename):
//   - "allocatenewobjectfromcbid failed %d"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×8, return×3.
//  - Notable callees: FUN_007a4480×2, CVOGReaction_GiveItemByCbid, FUN_0058be30, __RTDynamicCast.
//  - Strings: "allocatenewobjectfromcbid failed %d"; "VOG_DEBUG_STOP".
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

int FUN_0058be30(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int unaff_ESI;

  short sRank;

  

  piVar1 = (int *)CVOGReaction_GiveItemByCbid(param_1);

  if (piVar1 == (int *)0x0) {

    FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",param_1);

    return 0;

  }

  (**(code **)(*piVar1 + 8))(param_1,*(uint32_t /* width from decompiler */ *)(param_3 + 0xa4),1);

  iVar2 = __RTDynamicCast(piVar1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                          &CVOGCreature::RTTI_Type_Descriptor,0);

  if (iVar2 == 0) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    return 0;

  }

  if (*(float *)(unaff_ESI + 0x164) == g_flZero) {

    *(uint8_t *)(iVar2 + 0x309) = 0;

  }

  sRank = 1;

  if (0 < *(short *)(unaff_ESI + 0xdc)) {

    sRank = *(short *)(unaff_ESI + 0xdc);

  }

  if (0 < *(int *)(unaff_ESI + 0x150)) {

    Skill_EnsureLoadedInTree

              ((void *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2),*(int *)(unaff_ESI + 0x150),

               sRank);

  }

  if (0 < *(int *)(unaff_ESI + 0x154)) {

    Skill_EnsureLoadedInTree

              ((void *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2),*(int *)(unaff_ESI + 0x154),

               sRank);

  }

  if (0 < *(int *)(unaff_ESI + 0x158)) {

    Skill_EnsureLoadedInTree

              ((void *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2),*(int *)(unaff_ESI + 0x158),

               sRank);

  }

  if (0 < *(int *)(unaff_ESI + 0x15c)) {

    Skill_EnsureLoadedInTree

              ((void *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2),*(int *)(unaff_ESI + 0x15c),

               sRank);

  }

  return *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2;

}
