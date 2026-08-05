// =============================================================================
// FUN_00761100
// -----------------------------------------------------------------------------
// Stable ID: aa_00761100
// Address:   0x00761100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00761100 @ 0x00761100
// Stable ID: aa_00761100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, for×1, while×1.
//  - Notable callees: FUN_00760830, FUN_00761100.
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

uint __thiscall FUN_00761100(int param_1,float param_2)



{

  float fVar1;

  float fVar2;

  uint in_EAX;

  uint uVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  iVar7 = *(int *)(param_1 + 0xc);

  if (in_EAX == 0xffffffff) {

    if (iVar7 == 0) {

      in_EAX = 0xffffffff;

      uVar3 = 0;

    }

    else {

      iVar7 = *(int *)(param_1 + 0x10) - iVar7;

      uVar3 = iVar7 * 0x66666667;

      in_EAX = iVar7 / 0x28 - 1;

    }

  }

  else if ((iVar7 == 0) || (uVar3 = (*(int *)(param_1 + 0x10) - iVar7) / 0x28, uVar3 <= in_EAX)) {

    uVar3 = FUN_00760830(in_EAX + 1);

  }

  iVar7 = in_EAX * 0x28;

  iVar6 = *(int *)(param_1 + 0xc) + iVar7;

  *(float *)(iVar6 + 0x20) = param_2;

  iVar5 = iVar7;

  for (uVar4 = in_EAX; uVar4 != 0; uVar4 = uVar4 - 1) {

    fVar1 = *(float *)(*(int *)(param_1 + 0xc) + 0x20 + iVar5);

    uVar3 = *(int *)(param_1 + 0xc) + iVar5;

    fVar2 = *(float *)(uVar3 - 8);

    *(float *)(uVar3 - 4) = fVar1;

    if (fVar2 <= fVar1) break;

    iVar5 = iVar5 + -0x28;

    *(float *)(uVar3 - 8) = fVar1;

  }

  if (*(float *)(iVar6 + 0x24) <= param_2 && param_2 != *(float *)(iVar6 + 0x24)) {

    *(float *)(iVar6 + 0x24) = param_2;

    while( true ) {

      iVar5 = 0;

      if (*(int *)(param_1 + 0xc) != 0) {

        iVar5 = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28;

      }

      uVar3 = iVar5 - 1;

      if (uVar3 <= in_EAX) break;

      iVar5 = *(int *)(param_1 + 0xc);

      fVar1 = *(float *)(iVar5 + 0x24 + iVar7);

      fVar2 = *(float *)(iVar5 + 0x4c + iVar7);

      uVar3 = iVar5 + iVar7;

      *(float *)(uVar3 + 0x48) = fVar1;

      if (fVar1 <= fVar2) {

        return uVar3;

      }

      in_EAX = in_EAX + 1;

      *(float *)(uVar3 + 0x4c) = fVar1;

      iVar7 = iVar7 + 0x28;

    }

  }

  return uVar3;

}
