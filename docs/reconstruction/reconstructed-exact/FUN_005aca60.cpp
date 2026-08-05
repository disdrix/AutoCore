// =============================================================================
// FUN_005aca60
// -----------------------------------------------------------------------------
// Stable ID: aa_005aca60
// Address:   0x005aca60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005aca60 @ 0x005aca60
// Stable ID: aa_005aca60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, goto×1, return×1, while×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, FUN_004bb1c0, FUN_005aca60, SQRT.
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

int __thiscall FUN_005aca60(int param_1,int param_2,int param_3)



{

  ushort uVar1;

  int iVar2;

  bool bVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  int local_24;

  

  iVar4 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar4 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

  }

  uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

  *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

  iVar4 = (int)((longlong)(ulonglong)uVar1 % (longlong)*(int *)(param_1 + 0x58));

  bVar3 = false;

  local_24 = 100000;

  do {

    if (iVar4 == param_3) {

      iVar4 = (iVar4 + 1) % *(int *)(param_1 + 0x58);

    }

    iVar5 = FUN_004bb1c0(0,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4c) + iVar4 * 8),

                         *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4c) + 4 + iVar4 * 8));

    if (iVar5 == 0) {

LAB_005acb95:

      iVar4 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar4 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

      iVar4 = (int)((longlong)(ulonglong)uVar1 % (longlong)*(int *)(param_1 + 0x58));

    }

    else {

      iVar2 = *(int *)(*(int *)(iVar5 + 4) + 4);

      fVar7 = *(float *)(iVar2 + 0x84 + iVar5);

      iVar5 = iVar2 + 0x84 + iVar5;

      fVar8 = *(float *)(iVar5 + 4);

      fVar9 = *(float *)(iVar5 + 8);

      pfVar6 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) +

                                    0x1a0))();

      fVar7 = fVar7 - *pfVar6;

      fVar8 = fVar8 - pfVar6[1];

      fVar9 = fVar9 - pfVar6[2];

      if ((float)local_24 <= SQRT(fVar7 * fVar7 + fVar8 * fVar8 + fVar9 * fVar9)) goto LAB_005acb95;

      bVar3 = true;

    }

    local_24 = local_24 + 1000;

    if (bVar3) {

      return iVar4;

    }

  } while( true );

}
