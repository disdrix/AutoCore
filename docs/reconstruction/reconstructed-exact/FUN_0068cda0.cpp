// =============================================================================
// FUN_0068cda0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068cda0
// Address:   0x0068cda0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068cda0 @ 0x0068cda0
// Stable ID: aa_0068cda0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_00685ec0×2, FUN_00449000, FUN_0068cda0.
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

float * __thiscall FUN_0068cda0(int param_1,char param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  char cVar4;

  float *pfVar5;

  int iVar6;

  uint uVar7;

  float local_4;

  

  uVar7 = (uint)*(ushort *)(param_1 + 0x1a);

  pfVar5 = (float *)(*(int *)(param_1 + 0xd4) + uVar7);

  if (param_2 == *(char *)(*(int *)(param_1 + 0xd4) + uVar7)) {

    pfVar5 = (float *)(*(int *)(param_1 + 0xc4) + uVar7 * 8);

    fVar1 = param_3[2];

    fVar2 = *param_3;

    fVar3 = *pfVar5;

    local_4 = (param_3[1] - param_3[5]) * pfVar5[1] + param_3[5];

    cVar4 = FUN_00685ec0();

    if (cVar4 != '\0') {

      local_4 = -local_4;

    }

    if (*(int *)(param_1 + 0xb4) == 0) {

      uVar7 = 0;

    }

    else {

      uVar7 = *(int *)(param_1 + 0xb8) - *(int *)(param_1 + 0xb4) >> 2;

    }

    if ((uint)*(ushort *)(param_1 + 0x1a) == uVar7 >> 1) {

      if (*(int *)(param_1 + 0xb4) == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_1 + 0xb8) - *(int *)(param_1 + 0xb4) >> 2;

      }

      FUN_00449000(iVar6 + 2,0);

    }

    *(float *)(*(int *)(param_1 + 0xb4) + (uint)*(ushort *)(param_1 + 0x1a) * 8) =

         (fVar2 - fVar1) * fVar3 + fVar1;

    cVar4 = FUN_00685ec0();

    if (cVar4 != '\0') {

      local_4 = -local_4;

    }

    pfVar5 = (float *)(*(int *)(param_1 + 0xb4) + 4 + (uint)*(ushort *)(param_1 + 0x1a) * 8);

    *pfVar5 = local_4;

  }

  return pfVar5;

}
