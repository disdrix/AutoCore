// =============================================================================
// FUN_00515290
// -----------------------------------------------------------------------------
// Stable ID: aa_00515290
// Address:   0x00515290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00515290 @ 0x00515290
// Stable ID: aa_00515290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: CVOGReaction_CastSkillOnTarget, FUN_00515290.
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

void __thiscall FUN_00515290(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *(int *)(param_1 + 0xa4);

  *(int *)(param_1 + 0xa4) = param_2;

  if ((param_2 != 0) && (param_2 != iVar2)) {

    piVar1 = *(int **)(param_1 + 0x124);

    if (piVar1 != *(int **)(param_1 + 0x128)) {

      do {

        iVar2 = *piVar1;

        piVar1 = piVar1 + 1;

        *(int *)(iVar2 + 0x2c) = param_2;

      } while (piVar1 != *(int **)(param_1 + 0x128));

    }

    iVar2 = *(int *)(*(int *)(param_1 + 0xa4) + 0xe4f0);

    if (iVar2 != 0) {

      iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x234))

                        (*(uint32_t /* width from decompiler */ *)

                          (*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) +

                                   0x3c) + 0x3bc));

      if ((iVar2 != 0) && (*(short *)(iVar2 + 0x5f6) != 0)) {

        iVar3 = *(int *)(*(int *)(param_1 + 0xa4) + 0xe4f0);

        if (iVar3 != 0) {

          iVar3 = *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

        }

        CVOGReaction_CastSkillOnTarget(iVar2,iVar3,param_1,1,0,&DAT_00b04230,0,0xffffffff,0,0);

      }

    }

  }

  return;

}
