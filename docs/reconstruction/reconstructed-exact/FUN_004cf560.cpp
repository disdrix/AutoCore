// =============================================================================
// FUN_004cf560
// -----------------------------------------------------------------------------
// Stable ID: aa_004cf560
// Address:   0x004cf560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cf560 @ 0x004cf560
// Stable ID: aa_004cf560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×12, while×1, return×1.
//  - Notable callees: FUN_005a58c0×4, CONCAT31×2, FUN_004bae00×2, FUN_004cf560, FUN_005070b0, FUN_005070d0.
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

void __fastcall FUN_004cf560(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  char *pcVar4;

  float10 fVar5;

  float fVar6;

  uint8_t uStack_51;

  float fStack_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  float fStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  float fStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  float fStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_18;

  

  local_4c = CONCAT31(local_4c._1_3_,*(uint8_t *)(param_1 + 0x7d));

  local_48 = 0;

  piVar2 = (int *)FUN_004bae00(local_4c,&local_48);

  while (piVar2 != (int *)0x0) {

    iVar3 = (**(code **)(*piVar2 + 0x1c8))();

    if (((iVar3 != 0) && (iVar1 = *(int *)(iVar3 + 8), iVar1 != 0)) &&

       (*(char *)(iVar1 + 0x40) == '\0')) {

      (**(code **)(**(int **)(iVar1 + 0xc) + 0x18))

                (*(int *)(iVar1 + 0x3c) + 0x80,0x3c23d70a,&uStack_30);

      uStack_40 = uStack_30;

      fStack_3c = fStack_2c;

      fStack_50 = 0.0;

      uStack_38 = uStack_28;

      uStack_34 = 0;

      if (*(int *)(param_1 + 0xe4e0) == 0) {

        fVar6 = 0.0;

      }

      else {

        fVar5 = (float10)FUN_005a58c0(uStack_30,uStack_28);

        fVar6 = (float)fVar5;

        fStack_44 = fVar6;

      }

      if (0.0 <= fVar6 - fStack_3c) {

        fStack_50 = fVar6 - fStack_3c;

      }

      uStack_40 = uStack_30;

      fStack_3c = fStack_2c;

      uStack_38 = uStack_18;

      uStack_34 = 0;

      if (*(int *)(param_1 + 0xe4e0) == 0) {

        fVar6 = 0.0;

      }

      else {

        fVar5 = (float10)FUN_005a58c0(uStack_30,uStack_18);

        fVar6 = (float)fVar5;

        fStack_44 = fVar6;

      }

      if (fStack_50 <= fVar6 - fStack_3c) {

        fStack_50 = fVar6 - fStack_3c;

      }

      uStack_40 = uStack_20;

      fStack_3c = fStack_2c;

      uStack_38 = uStack_28;

      uStack_34 = 0;

      if (*(int *)(param_1 + 0xe4e0) == 0) {

        fVar6 = 0.0;

      }

      else {

        fVar5 = (float10)FUN_005a58c0(uStack_20,uStack_28);

        fVar6 = (float)fVar5;

        fStack_44 = fVar6;

      }

      if (fStack_50 <= fVar6 - fStack_3c) {

        fStack_50 = fVar6 - fStack_3c;

      }

      uStack_40 = uStack_20;

      fStack_3c = fStack_2c;

      uStack_38 = uStack_18;

      uStack_34 = 0;

      if (*(int *)(param_1 + 0xe4e0) == 0) {

        fVar6 = 0.0;

      }

      else {

        fVar5 = (float10)FUN_005a58c0(uStack_20,uStack_18);

        fVar6 = (float)fVar5;

        fStack_44 = fVar6;

      }

      if (fStack_50 <= fVar6 - fStack_3c) {

        fStack_50 = fVar6 - fStack_3c;

      }

      if (0.0 < fStack_50) {

        iVar1 = *(int *)(*(int *)(iVar3 + 8) + 0x3c);

        uStack_40 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb0);

        uStack_38 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb8);

        uStack_34 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc);

        fStack_3c = *(float *)(iVar1 + 0xb4) + fStack_50 + DAT_00a0f718;

        iVar3 = *(int *)(iVar3 + 8);

        pcVar4 = (char *)FUN_005070b0(&uStack_51);

        if ((*pcVar4 == '\0') && (*(int *)(iVar3 + 0x44) != 0)) {

          FUN_005070d0();

        }

        if ((*(char *)(iVar3 + 0x40) == '\0') || (*(int *)(iVar3 + 8) == 0)) {

          (**(code **)(**(int **)(iVar3 + 0x3c) + 0x40))(&uStack_40);

        }

      }

    }

    local_4c = CONCAT31(local_4c._1_3_,*(uint8_t *)(param_1 + 0x7d));

    piVar2 = (int *)FUN_004bae00(local_4c,&local_48);

  }

  return;

}
