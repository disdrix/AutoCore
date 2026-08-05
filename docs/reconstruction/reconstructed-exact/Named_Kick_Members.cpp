// =============================================================================
// Named_Kick_Members
// -----------------------------------------------------------------------------
// Stable ID: aa_008f46c0
// Address:   0x008f46c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Kick_Members @ 0x008f46c0
// Stable ID: aa_008f46c0
// Embedded strings (evidence for future rename):
//   - "You are not in a clan!"
//   - "To Promote/Demote/Kick Members:"
//   - "To Access Member Details:"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~182 non-empty decompiler lines.
//  - Control keywords: if×18, return×3.
//  - Notable callees: FUN_008f4480×3, sprintf×2, Named_Kick_Members.
//  - Strings: "You are not in a clan!"; "To Promote/Demote/Kick Members:"; "To Access Member Details:".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "To Promote/Demote/Kick Members:"
 * Domain alias of FUN_008f46c0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_Kick_Members(int param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  float unaff_EDI;

  uint8_t *puVar5;

  char *pcStack_1bc;

  float fStack_1b8;

  uint8_t *puStack_1b4;

  uint32_t /* width from decompiler */ uStack_1a4;

  int iStack_1a0;

  uint32_t /* width from decompiler */ uStack_194;

  int iStack_190;

  uint32_t /* width from decompiler */ uStack_18c;

  int aiStack_188 [2];

  uint8_t auStack_180 [12];

  char acStack_174 [28];

  uint8_t auStack_158 [8];

  uint8_t auStack_150 [4];

  uint8_t auStack_14c [12];

  uint8_t auStack_140 [24];

  uint8_t auStack_128 [4];

  char acStack_124 [8];

  char acStack_11c [4];

  char acStack_118 [12];

  uint8_t auStack_10c [264];

  

  *(int *)(param_1 + 0x50c) = in_EAX;

  if (in_EAX == 0) {

    if (*(int **)(param_1 + 0x518) != (int *)0x0) {

      puStack_1b4 = (uint8_t *)0x1;

      fStack_1b8 = 1.3159419e-38;

      (**(code **)(**(int **)(param_1 + 0x518) + 4))();

    }

    if (*(int **)(param_1 + 0x51c) != (int *)0x0) {

      puStack_1b4 = (uint8_t *)0x1;

      fStack_1b8 = 1.3159443e-38;

      (**(code **)(**(int **)(param_1 + 0x51c) + 4))();

    }

    puStack_1b4 = (uint8_t *)0x0;

    fStack_1b8 = 1.3159452e-38;

    FUN_008f4480();

    if (*(int **)(param_1 + 0x514) != (int *)0x0) {

      puStack_1b4 = auStack_128;

      fStack_1b8 = 1.3159494e-38;

      (**(code **)(**(int **)(param_1 + 0x514) + 0x134))();

      fStack_1b8 = 1.4013e-45;

      pcStack_1bc = acStack_11c;

      puVar1 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(param_1 + 0x514) + 0x140))();

      uStack_18c = *puVar1;

      aiStack_188[0] = (int)unaff_EDI;

      (**(code **)(**(int **)(param_1 + 0x514) + 300))(&uStack_18c);

      (**(code **)(**(int **)(param_1 + 0x514) + 0x34c))();

      (**(code **)(**(int **)(param_1 + 0x514) + 0x1b0))(10);

      (**(code **)(**(int **)(param_1 + 0x514) + 0x1d8))("You are not in a clan!",1,1);

    }

  }

  else if (in_EAX == 1) {

    if (*(int **)(param_1 + 0x518) != (int *)0x0) {

      puStack_1b4 = (uint8_t *)0x0;

      fStack_1b8 = 1.3158715e-38;

      (**(code **)(**(int **)(param_1 + 0x518) + 4))();

    }

    if (*(int **)(param_1 + 0x51c) != (int *)0x0) {

      puStack_1b4 = (uint8_t *)0x0;

      fStack_1b8 = 1.3158739e-38;

      (**(code **)(**(int **)(param_1 + 0x51c) + 4))();

    }

    puStack_1b4 = (uint8_t *)0x1;

    fStack_1b8 = 1.3158749e-38;

    FUN_008f4480();

    if (*(int **)(param_1 + 0x514) != (int *)0x0) {

      puStack_1b4 = auStack_140;

      fStack_1b8 = 1.3158787e-38;

      (**(code **)(**(int **)(param_1 + 0x514) + 0x134))();

      fStack_1b8 = 1.4013e-45;

      pcStack_1bc = acStack_174;

      puVar1 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(param_1 + 0x514) + 0x140))();

      uStack_1a4 = *puVar1;

      iStack_1a0 = (int)unaff_EDI;

      (**(code **)(**(int **)(param_1 + 0x514) + 300))(&uStack_1a4);

      sprintf(acStack_118,"%s",DAT_00d1da30 + 4);

      (**(code **)(**(int **)(param_1 + 0x514) + 0x34c))();

      (**(code **)(**(int **)(param_1 + 0x514) + 0x1b0))(10);

      (**(code **)(**(int **)(param_1 + 0x514) + 0x1d8))(acStack_11c,1,0);

      piVar4 = *(int **)(param_1 + 0x514);

      iVar2 = (**(code **)(*piVar4 + 0x140))(aiStack_188,1);

      iVar3 = (**(code **)(*piVar4 + 0x204))(auStack_180);

      if (*(int *)(iVar2 + 4) < *(int *)(iVar3 + 4)) {

        puStack_1b4 = (uint8_t *)0x2;

        fStack_1b8 = 1.3159126e-38;

        (**(code **)(**(int **)(param_1 + 0x514) + 0x1b0))();

        fStack_1b8 = 0.0;

        pcStack_1bc = (char *)0x1;

        (**(code **)(**(int **)(param_1 + 0x514) + 0x1d8))(auStack_10c);

        iVar2 = (**(code **)(**(int **)(param_1 + 0x514) + 0x134))(auStack_158);

        fStack_1b8 = (float)DAT_00d1e81c * (*(float *)(iVar2 + 4) + (float)g_nInferredThreatDefault)

                     * DAT_00aaa678;

        (**(code **)(**(int **)(param_1 + 0x514) + 0x140))(auStack_14c,1);

        (**(code **)(**(int **)(param_1 + 0x514) + 300))(&stack0xfffffe54);

      }

    }

    if (*(int **)(param_1 + 0x548) != (int *)0x0) {

      puStack_1b4 = (uint8_t *)0x1;

      fStack_1b8 = 1.4013e-45;

      pcStack_1bc = "To Promote/Demote/Kick Members:";

      (**(code **)(**(int **)(param_1 + 0x548) + 0x1d8))();

      (**(code **)(**(int **)(param_1 + 0x548) + 0x34c))();

      return;

    }

  }

  else if (in_EAX == 2) {

    if (*(int **)(param_1 + 0x518) != (int *)0x0) {

      puStack_1b4 = (uint8_t *)0x0;

      fStack_1b8 = 1.315795e-38;

      (**(code **)(**(int **)(param_1 + 0x518) + 4))();

    }

    if (*(int **)(param_1 + 0x51c) != (int *)0x0) {

      puStack_1b4 = (uint8_t *)0x0;

      fStack_1b8 = 1.3157974e-38;

      (**(code **)(**(int **)(param_1 + 0x51c) + 4))();

    }

    puStack_1b4 = (uint8_t *)0x1;

    fStack_1b8 = 1.3157984e-38;

    FUN_008f4480();

    if (*(int **)(param_1 + 0x514) != (int *)0x0) {

      puStack_1b4 = auStack_150;

      fStack_1b8 = 1.3158022e-38;

      (**(code **)(**(int **)(param_1 + 0x514) + 0x134))();

      fStack_1b8 = 1.4013e-45;

      pcStack_1bc = acStack_124;

      puVar1 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(param_1 + 0x514) + 0x140))();

      uStack_194 = *puVar1;

      iStack_190 = (int)unaff_EDI;

      (**(code **)(**(int **)(param_1 + 0x514) + 300))(&uStack_194);

      sprintf(acStack_118,"%s",DAT_00d1da30 + 4);

      (**(code **)(**(int **)(param_1 + 0x514) + 0x34c))();

      (**(code **)(**(int **)(param_1 + 0x514) + 0x1b0))(10);

      (**(code **)(**(int **)(param_1 + 0x514) + 0x1d8))(acStack_11c,1,0);

      piVar4 = *(int **)(param_1 + 0x514);

      iVar2 = (**(code **)(*piVar4 + 0x140))(auStack_180,1);

      iVar3 = (**(code **)(*piVar4 + 0x204))(auStack_158);

      if (*(int *)(iVar2 + 4) < *(int *)(iVar3 + 4)) {

        puStack_1b4 = (uint8_t *)0x2;

        fStack_1b8 = 1.315837e-38;

        (**(code **)(**(int **)(param_1 + 0x514) + 0x1b0))();

        fStack_1b8 = 0.0;

        pcStack_1bc = (char *)0x1;

        puVar5 = auStack_10c;

        (**(code **)(**(int **)(param_1 + 0x514) + 0x1d8))(puVar5);

        iVar2 = (**(code **)(**(int **)(param_1 + 0x514) + 0x134))(aiStack_188);

        fStack_1b8 = (float)DAT_00d1e81c * (*(float *)(iVar2 + 4) + (float)g_nInferredThreatDefault)

                     * DAT_00aaa678;

        piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x514) + 0x140))(acStack_124,1);

        pcStack_1bc = (char *)*piVar4;

        fStack_1b8 = (float)(int)(float)puVar5;

        (**(code **)(**(int **)(param_1 + 0x514) + 300))(&pcStack_1bc);

      }

    }

    if (*(int **)(param_1 + 0x548) != (int *)0x0) {

      puStack_1b4 = (uint8_t *)0x1;

      fStack_1b8 = 1.4013e-45;

      pcStack_1bc = "To Access Member Details:";

      (**(code **)(**(int **)(param_1 + 0x548) + 0x1d8))();

      (**(code **)(**(int **)(param_1 + 0x548) + 0x34c))();

    }

    if (*(int **)(param_1 + 0x550) != (int *)0x0) {

      puStack_1b4 = (uint8_t *)0x0;

      fStack_1b8 = 1.3158652e-38;

      (**(code **)(**(int **)(param_1 + 0x550) + 4))();

    }

    if (*(int **)(param_1 + 0x554) != (int *)0x0) {

      puStack_1b4 = (uint8_t *)0x0;

      fStack_1b8 = 1.3158682e-38;

      (**(code **)(**(int **)(param_1 + 0x554) + 4))();

      return;

    }

  }

  return;

}
