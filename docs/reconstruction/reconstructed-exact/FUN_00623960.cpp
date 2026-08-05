// =============================================================================
// FUN_00623960
// -----------------------------------------------------------------------------
// Stable ID: aa_00623960
// Address:   0x00623960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00623960 @ 0x00623960
// Stable ID: aa_00623960
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_005304a0×3, CONCAT22, FUN_00618270, FUN_00623960.
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

void __fastcall FUN_00623960(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  if (*(void **)(param_1 + 0x174) != (void *)0x0) {

    puVar1 = CVOGReaction_ResolveSkillTargets

                       (*(void **)(param_1 + 0x174),

                        CONCAT22((short)((uint)param_1 >> 0x10),*(uint16_t *)(param_1 + 0x100)));

    CVOGReaction_CastSkillOnTarget

              (puVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),0,0,0,&DAT_00d02b50,0,0xffffffff,0,0);

                    /* WARNING: Subroutine does not return */

    operator_delete(puVar1);

  }

  iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x210))(0);

  if (iVar2 != 0) {

    if (*(int *)(param_1 + 0x178) != 0) {

      FUN_005304a0(*(int *)(param_1 + 0x178),(int)*(short *)(param_1 + 0x100),0);

    }

    if (*(int *)(param_1 + 0x17c) != 0) {

      FUN_005304a0(*(int *)(param_1 + 0x17c),(int)*(short *)(param_1 + 0x100),0);

    }

    if (*(int *)(param_1 + 0x180) != 0) {

      FUN_005304a0(*(int *)(param_1 + 0x180),(int)*(short *)(param_1 + 0x100),0);

    }

  }

  FUN_00618270();

  return;

}
