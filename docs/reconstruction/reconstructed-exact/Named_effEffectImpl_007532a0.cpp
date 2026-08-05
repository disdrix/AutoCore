// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×11, return×7, goto×2, while×2, do×1.
//  - Notable callees: FUN_00445050×2, FUN_007532a0, vog_LogMessage.
//  - Strings: ",

                     0x21c,2,".
//  - Return sites: 7.

// =============================================================================
// Named_effEffectImpl_007532a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007532a0
// Address:   0x007532a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effEffectImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_effEffectImpl_007532a0(int param_1)



{

  uint uVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  char cVar5;

  int in_EAX;

  int iVar6;

  uint uVar7;

  int *piVar8;

  

  if (((param_1 == 0) || (*(float *)(param_1 + 0x104) <= 0.0)) ||

     (iVar3 = *(int *)(in_EAX + 8), iVar3 == 0)) {

    return *(uint32_t /* width from decompiler */ *)(in_EAX + 0x14);

  }

  iVar4 = *(int *)(in_EAX + 0x20);

  iVar6 = (iVar4 + *(int *)(param_1 + 0x108) * 4 + *(int *)(param_1 + 0x108)) * 0x10 + 0x3c + iVar3;

  cVar5 = FUN_00445050();

  if (cVar5 != '\0') {

    cVar5 = FUN_00445050();

    if (cVar5 != '\0') {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffectImpl.cpp",

                     0x21c,2,"Normal Render Mode has no Techniques.");

      return 0;

    }

    return *(uint32_t /* width from decompiler */ *)(*(int *)(iVar4 * 0x10 + iVar3 + 0x44) + -4);

  }

  iVar3 = *(int *)(iVar6 + 4);

  fVar2 = *(float *)(param_1 + 0x104);

  if (iVar3 == 0) {

    iVar6 = 0;

  }

  else {

    iVar6 = *(int *)(iVar6 + 8) - iVar3 >> 2;

  }

  uVar1 = iVar6 - 1;

  uVar7 = 0;

  if (3 < (int)uVar1) {

    piVar8 = (int *)(iVar3 + 8);

    do {

      if (*(float *)(piVar8[-2] + 0xc) <= fVar2 && fVar2 != *(float *)(piVar8[-2] + 0xc))

      goto LAB_007533c9;

      if (*(float *)(piVar8[-1] + 0xc) <= fVar2 && fVar2 != *(float *)(piVar8[-1] + 0xc)) {

        return *(uint32_t /* width from decompiler */ *)(iVar3 + (uVar7 + 1) * 4);

      }

      if (*(float *)(*piVar8 + 0xc) <= fVar2 && fVar2 != *(float *)(*piVar8 + 0xc)) {

        return *(uint32_t /* width from decompiler */ *)(iVar3 + (uVar7 + 2) * 4);

      }

      if (*(float *)(piVar8[1] + 0xc) <= fVar2 && fVar2 != *(float *)(piVar8[1] + 0xc)) {

        uVar7 = uVar7 + 3;

        goto LAB_007533c9;

      }

      uVar7 = uVar7 + 4;

      piVar8 = piVar8 + 4;

    } while (uVar7 < iVar6 - 4U);

  }

  if (uVar7 < uVar1) {

    piVar8 = (int *)(iVar3 + uVar7 * 4);

    while (fVar2 < *(float *)(*piVar8 + 0xc) || fVar2 == *(float *)(*piVar8 + 0xc)) {

      uVar7 = uVar7 + 1;

      piVar8 = piVar8 + 1;

      if (uVar1 <= uVar7) {

        return *(uint32_t /* width from decompiler */ *)(iVar3 + uVar7 * 4);

      }

    }

  }

LAB_007533c9:

  return *(uint32_t /* width from decompiler */ *)(iVar3 + uVar7 * 4);

}
