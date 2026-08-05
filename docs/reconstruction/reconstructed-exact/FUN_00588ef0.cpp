// =============================================================================
// FUN_00588ef0
// -----------------------------------------------------------------------------
// Stable ID: aa_00588ef0
// Address:   0x00588ef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00588ef0 @ 0x00588ef0
// Stable ID: aa_00588ef0
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
//   - "Duplicate hash insert %u, failing out"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~150 non-empty decompiler lines.
//  - Control keywords: if×14, return×4, do×1, while×1.
//  - Notable callees: FUN_004e23d0×3, FUN_007a4480×3, FUN_004e2360, FUN_00588ef0, FUN_00589890.
//  - Strings: "VOG_DEBUG_STOP"; "Duplicate hash insert %u, failing out".
//  - Return sites: 4.

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

/* WARNING: Type propagation algorithm not settling */



uint32_t /* width from decompiler */ __thiscall FUN_00588ef0(int param_1,float *param_2)



{

  float *pfVar1;

  int *piVar2;

  uint uVar3;

  int iVar4;

  void *pvVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ unaff_EBP;

  uint32_t /* width from decompiler */ unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  int *piStack_44;

  int iStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  int aiStack_38 [2];

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  int iStack_c;

  int aiStack_8 [2];

  

  if (param_2 == (float *)0x0) {

    return 0;

  }

  aiStack_38[0] = *(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x47c + param_1;

  aiStack_38[1] = 0x10;

  uStack_3c = 0x588f25;

  (**(code **)((int)*param_2 + 0x14))();

  iVar4 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

  pfVar1 = (float *)(iVar4 + -0x47c + param_1);

  *pfVar1 = *param_2 + *(float *)(iVar4 + -0x47c + param_1);

  pfVar1[1] = param_2[1] + pfVar1[1];

  pfVar1[2] = param_2[2] + pfVar1[2];

  pfVar1[3] = param_2[3] + pfVar1[3];

  iStack_40 = *(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x46c + param_1;

  uStack_3c = 0x10;

  piStack_44 = (int *)0x588f91;

  (**(code **)((int)*param_2 + 0x14))();

  iVar4 = ((aiStack_8[0] < 0x33) - 1 & 0x14) + 10;

  if (iVar4 != 0) {

    puVar7 = (uint32_t /* width from decompiler */ *)(param_1 + -0x3f8);

    do {

      piStack_44 = (int *)0x1;

      (**(code **)((int)*param_2 + 0x14))(&iStack_c);

      (**(code **)((int)*param_2 + 0x14))(aiStack_38 + 1,4);

      (**(code **)((int)*param_2 + 0x14))(aiStack_38,4);

      (**(code **)((int)*param_2 + 0x14))(&stack0xffffffbb,1);

      (**(code **)((int)*param_2 + 0x14))(&piStack_44,4);

      *(uint8_t *)(puVar7 + -1) = (uint8_t)iStack_c;

      *puVar7 = unaff_EBX;

      puVar7[1] = unaff_EDI;

      *(char *)(puVar7 + 2) = (char)((uint)unaff_EBP >> 0x18);

      puVar7[3] = unaff_ESI;

      puVar7 = puVar7 + 5;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  if (0x27 < aiStack_8[0]) {

    piStack_44 = (int *)0x4;

    aiStack_8[1] = 0;

    (**(code **)((int)*param_2 + 0x14))(aiStack_8 + 1);

    if (iStack_c < 1) {

      *(uint32_t /* width from decompiler */ *)(param_1 + -0x28) = 0;

    }

    else {

      pvVar5 = operator_new__(iStack_c + 1);

      *(void **)(param_1 + -0x28) = pvVar5;

      (**(code **)((int)*param_2 + 0x14))(pvVar5,iStack_c);

      *(uint8_t *)(iStack_c + *(int *)(param_1 + -0x28)) = 0;

    }

    (**(code **)((int)*param_2 + 0x14))(&stack0xffffffd8,4);

    (**(code **)((int)*param_2 + 0x14))(&stack0xffffffd4,4);

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x24) = uStack_20;

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x20) = uStack_1c;

  }

  if (0x28 < aiStack_8[0]) {

    piStack_44 = (int *)0x1;

    (**(code **)((int)*param_2 + 0x14))(param_1 + -0x1c);

  }

  if (0x31 < aiStack_8[0]) {

    piStack_44 = (int *)0x1;

    (**(code **)((int)*param_2 + 0x14))(param_1 + -0x1b);

  }

  if (0x3c < aiStack_8[0]) {

    piStack_44 = (int *)0x1;

    (**(code **)((int)*param_2 + 0x14))(param_1 + -0x1a);

  }

  iVar4 = *(int *)(param_1 + -0x4fc);

  iVar6 = *(int *)(iVar4 + 4);

  if (*(int *)(param_1 + -0x458 + iVar6) != 0) {

    piStack_44 = aiStack_8;

    iVar6 = FUN_004e23d0(*(uint32_t /* width from decompiler */ *)(param_1 + -0x39c + iVar6),

                         *(uint32_t /* width from decompiler */ *)(param_1 + iVar6 + -0x398));

    if ((iVar6 == 0) || (*(int *)(iVar6 + 0xc) == 0)) {

      iVar4 = *(int *)(iVar4 + 4);

      piVar2 = *(int **)(param_1 + -0x398 + iVar4);

      uVar3 = *(uint *)(param_1 + -0x39c + iVar4);

      iVar4 = *(int *)(*(int *)(param_1 + -0x458 + iVar4) + 0xe524);

      aiStack_8[0] = param_1 + -0x500;

      if (aiStack_8[0] != 0) {

        if (*(char *)(iVar4 + 0x1d) != '\0') {

          piStack_44 = (int *)0xa64c18;

          FUN_007a4480(0);

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        piStack_44 = aiStack_8 + 1;

        iVar6 = FUN_004e23d0(uVar3,piVar2);

        if ((iVar6 == 0) || (*(int *)(iVar6 + 0xc) == 0)) {

          piStack_44 = aiStack_8 + 1;

          iVar6 = FUN_004e23d0(uVar3,piVar2);

          if ((iVar6 != 0) && (*(int *)(iVar6 + 0xc) != 0)) {

            piStack_44 = piVar2;

            FUN_007a4480(0,"Duplicate hash insert %u, failing out",uVar3);

            return 1;

          }

          piStack_44 = (int *)0x5891ed;

          puVar7 = (uint32_t /* width from decompiler */ *)FUN_00589890();

          puVar7[4] = 0;

          *puVar7 = &PTR_LAB_009cc6e4;

          puVar7[8] = 0;

          puVar7[9] = 0;

          *(uint8_t *)(puVar7 + 2) = 0;

          puVar7[3] = aiStack_8[0];

          puVar7[6] = uVar3;

          puVar7[7] = piVar2;

          iVar6 = *(int *)(*(int *)(iVar4 + 0x10) + (*(uint *)(iVar4 + 8) & uVar3) * 4);

          puVar7[4] = *(uint32_t /* width from decompiler */ *)(iVar6 + 4);

          *(uint32_t /* width from decompiler */ **)(iVar6 + 4) = puVar7;

          piStack_44 = (int *)0x58922c;

          FUN_004e2360();

          if (*(int *)(iVar4 + 0x18) != 0) {

            *(uint32_t /* width from decompiler */ **)(*(int *)(iVar4 + 0x18) + 0x20) = puVar7;

            puVar7[8] = 0;

            puVar7[9] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x18);

            *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

            *(uint32_t /* width from decompiler */ **)(iVar4 + 0x18) = puVar7;

            return 1;

          }

          *(uint32_t /* width from decompiler */ **)(iVar4 + 0x18) = puVar7;

          *(uint32_t /* width from decompiler */ **)(iVar4 + 0x14) = puVar7;

          puVar7[9] = 0;

          puVar7[8] = 0;

          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

        }

      }

    }

  }

  return 1;

}
