// =============================================================================
// FUN_007a2e50
// -----------------------------------------------------------------------------
// Stable ID: aa_007a2e50
// Address:   0x007a2e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a2e50 @ 0x007a2e50
// Stable ID: aa_007a2e50
// Embedded strings (evidence for future rename):
//   - "gNDTime"
//   - "gWindStrength"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×3, FUN_007a2e50, block.
//  - Strings: "gNDTime"; "gWindStrength".
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

/* WARNING: Removing unreachable block (ram,0x007a2f29) */



void FUN_007a2e50(int param_1)



{

  ushort uVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  float fVar6;

  

  iVar3 = DAT_00d1f05c;

  if (*(int *)(*(int *)(DAT_00d1f05c + 4) + 0xc) == 0) {

    uVar4 = 0;

  }

  else {

    piVar2 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

    uVar4 = (**(code **)(*piVar2 + 0x24))(piVar2,0,"gNDTime");

  }

  piVar2 = *(int **)(*(int *)(iVar3 + 4) + 0xc);

  (**(code **)(*piVar2 + 0x50))(piVar2,uVar4,&stack0x00000008,0xffffffff);

  DAT_00d1f202 = DAT_00d1f202 + '\x01';

  iVar5 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar5 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc) = 0;

  }

  uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + *(int *)(iVar5 + 0xc) * 2);

  *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;

  if ((int)((uint)uVar1 % 0x14 + 0x14) < (int)DAT_00d1f202) {

    DAT_00d1f202 = '\0';

    iVar5 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar5 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc) = 0;

    }

    uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + *(int *)(iVar5 + 0xc) * 2);

    *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;

    if ((uint)uVar1 % 0x32 == 0) {

      iVar5 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar5 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + *(int *)(iVar5 + 0xc) * 2);

      *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;

      DAT_00b00b24 = uVar1 & 1;

    }

  }

  if (DAT_00b00b24 == 0) {

    DAT_00b00b20 = *(float *)(param_1 + 0x15c) + DAT_00b00b20;

  }

  else if (DAT_00b00b24 == 1) {

    DAT_00b00b20 = DAT_00b00b20 - *(float *)(param_1 + 0x15c);

  }

  fVar6 = DAT_00aaa68c;

  if ((DAT_00aaa68c < DAT_00b00b20) || (fVar6 = DAT_00a0f698, DAT_00b00b20 < DAT_00a0f698)) {

    DAT_00b00b20 = fVar6;

  }

  if (*(int *)(*(int *)(iVar3 + 4) + 0xc) == 0) {

    uVar4 = 0;

  }

  else {

    piVar2 = *(int **)(*(int *)(iVar3 + 4) + 0xc);

    uVar4 = (**(code **)(*piVar2 + 0x24))(piVar2,0,"gWindStrength");

  }

  piVar2 = *(int **)(*(int *)(iVar3 + 4) + 0xc);

  (**(code **)(*piVar2 + 0x50))(piVar2,uVar4,&DAT_00b00b20,0xffffffff);

  return;

}
