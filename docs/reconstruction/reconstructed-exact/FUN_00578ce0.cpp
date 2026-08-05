// =============================================================================
// FUN_00578ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_00578ce0
// Address:   0x00578ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00578ce0 @ 0x00578ce0
// Stable ID: aa_00578ce0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CONCAT31, FUN_005081f0, FUN_0051f880, FUN_00578ac0, FUN_00578ce0.
//  - Return sites: 1.

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

void __fastcall FUN_00578ce0(int param_1)



{

  char *pcVar1;

  int *piVar2;

  int iVar3;

  

  (*(code *)PTR_FUN_00af31e0)(param_1,0);

  piVar2 = (int *)CVOGReaction_ResolveObjectTarget

                            (CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(param_1 + 0x65c) >> 8),

                                      *(uint8_t *)(param_1 + 0x660)),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 0x658),*(uint32_t /* width from decompiler */ *)(param_1 + 0x65c));

  FUN_00578ac0();

  if (*(int *)(param_1 + 0x18) != 0) {

    (**(code **)(**(int **)(param_1 + 0x18) + 0x238))

              (1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x620),

               (int)(short)(*(short *)(param_1 + 0x61a) + *(short *)(param_1 + 0x198)),0,piVar2,0,0,

               0);

    if ((*(byte *)(param_1 + 0x639) & 0x10) != 0) {

      pcVar1 = (char *)(*(int *)(param_1 + 0x18) + 0x26);

      *pcVar1 = *pcVar1 + -1;

    }

  }

  if (piVar2 != (int *)0x0) {

    iVar3 = (**(code **)(*piVar2 + 0x214))();

    if ((iVar3 != 0) && ((*(byte *)(param_1 + 0x639) & 2) != 0)) {

      Skill_ClearCastBindingAndMaybeRestartCd

                ((void *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3),*(void **)(param_1 + 0x620)

                 ,*(int *)(param_1 + 0x678),*(int *)(param_1 + 0x67c),*(int *)(param_1 + 0x680),

                 (char)*(uint32_t /* width from decompiler */ *)(param_1 + 0x684));

    }

    if (*(char *)(param_1 + 0x140) != '\0') {

      iVar3 = (**(code **)(*piVar2 + 0x210))(0);

      if (iVar3 != 0) {

        FUN_0051f880(0);

      }

    }

  }

  FUN_005081f0();

  return;

}
