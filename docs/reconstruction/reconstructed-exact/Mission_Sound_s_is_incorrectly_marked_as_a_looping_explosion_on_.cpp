// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable×2, FUN_0071f8a0×2, FUN_007227e0×2, CONCAT31, FUN_004bb3a0, FUN_0071f760, FUN_007a4480, ROUND.
//  - Return sites: 1.

// =============================================================================
// Mission_Sound_s_is_incorrectly_marked_as_a_looping_explosion_on_
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "Sound %s is incorrectly marked as a looping explosion on object %d (EXPECT INFINITE SOUND LOOP)."
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004bb3a0 clean capture (not modernized).
//
// Address:  0x004bb3a0  (autoassault.exe, image base 0x400000)
// Stable:   aa_004bb3a0
// Stable ID: aa_004bb3a0
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004bb3a0_*.md
//           Original Ghidra symbol: FUN_004bb3a0
//
// Exactness: Body mirrors reconstructed-exact/FUN_004bb3a0*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_Sound_s_is_incorrectly_marked_as_a_looping_explosion_on_
// -----------------------------------------------------------------------------
// Stable ID: aa_004bb3a0
// Address:   0x004bb3a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "Sound %s is incorrectly marked as a looping explosion on object %d (EXPECT INFIN"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Mission_Sound_s_is_incorrectly_marked_as_a_looping_explosion_on_(int param_1,float param_2,float *param_3)



{

  uint uVar1;

  int *piVar2;

  int iVar3;

  float10 fVar4;

  float fVar5;

  float fVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  fVar6 = param_3[2] - *(float *)(param_1 + 0x158);

  fVar5 = *param_3 - *(float *)(param_1 + 0x150);

  uVar1 = *(uint *)(param_1 + 0x40);

  fVar5 = SQRT(fVar6 * fVar6 + fVar5 * fVar5);

  *(float *)(param_1 + 0x194) = fVar5;

  if ((uVar1 & *(uint *)(param_1 + 0x44)) != 0xffffffff) {

    piVar2 = (int *)CVOGReaction_ResolveObjectTarget

                              (CONCAT31((int3)(uVar1 >> 8),*(uint8_t *)(param_1 + 0x35)),uVar1,

                               *(uint *)(param_1 + 0x44));

    if (piVar2 != (int *)0x0) {

      (**(code **)(*piVar2 + 0x144))();

      if ((*(int *)(param_1 + 0x2c) == 0x32) && (*(char *)(param_1 + 0x36) != '\0')) {

        FUN_007a4480(0,

                     "Sound %s is incorrectly marked as a looping explosion on object %d (EXPECT INFINITE SOUND LOOP)."

                     ,param_1 + 0x48,*(uint32_t /* width from decompiler */ *)(piVar2[0x2a] + 0x34));

      }

      if ((*(float *)(param_1 + 0x184) <= fVar5 && fVar5 != *(float *)(param_1 + 0x184)) &&

         (*(char *)(param_1 + 0x36) != '\0')) {

        uVar7 = 0;

        *(uint8_t *)(param_1 + 0x38) = 1;

        Client_GetMissionCompleteAudioTable(0);

        fVar4 = (float10)FUN_007227e0(uVar7);

        *(float *)(param_1 + 0x1b0) = (float)fVar4;

      }

      *(int *)(param_1 + 0x150) = piVar2[0x20];

      *(int *)(param_1 + 0x154) = piVar2[0x21];

      *(int *)(param_1 + 0x158) = piVar2[0x22];

      *(int *)(param_1 + 0x15c) = piVar2[0x23];

    }

  }

  iVar3 = FUN_0071f760(0);

  if (((iVar3 != 0) || (*(char *)(param_1 + 0x3a) != '\0')) && (*(char *)(param_1 + 0x38) == '\0'))

  {

    param_2 = *(float *)(param_1 + 400) * param_2;

    Client_GetMissionCompleteAudioTable(param_2);

    fVar4 = (float10)FUN_007227e0(param_2);

    fVar5 = (float)fVar4;

    if (fVar5 != *(float *)(param_1 + 0x1a4)) {

      if (fVar5 <= g_flOne) {

        *(float *)(param_1 + 0x1a4) = fVar5;

      }

      else {

        *(float *)(param_1 + 0x1a4) = g_flOne;

      }

      *(float *)(param_1 + 0x1b0) = fVar5;

      iVar3 = FUN_0071f8a0(0);

      if (iVar3 != 0) {

        piVar2 = (int *)FUN_0071f8a0(0);

        (**(code **)(*piVar2 + 0x3c))(piVar2,(int)ROUND(fVar5));

      }

    }

  }

  (**(code **)(**(int **)(param_1 + 0x1c8) + 0x4c))

            (*(int **)(param_1 + 0x1c8),*(uint32_t /* width from decompiler */ *)(param_1 + 0x150),

             *(uint32_t /* width from decompiler */ *)(param_1 + 0x154),*(uint32_t /* width from decompiler */ *)(param_1 + 0x158),1);

  return;

}
