// =============================================================================
// FUN_0098f2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0098f2b0
// Address:   0x0098f2b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098f2b0 @ 0x0098f2b0
// Stable ID: aa_0098f2b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, while×2, do×1.
//  - Notable callees: FUN_0044f6a0×20, FUN_0046c300×12, FUN_0098f140, FUN_0098f2b0, fpatan.
//  - Return sites: 3.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0098f2b0(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int in_EAX;

  int iVar5;

  float *pfVar6;

  float10 fVar7;

  

  if (*(void **)(in_EAX + 8) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(in_EAX + 8));

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = 0;

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  if (*(void **)(in_EAX + 0x18) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1c) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20) = 0;

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    FUN_0044f6a0();

    while( true ) {

      fVar4 = DAT_00a0f298;

      if (*(int *)(in_EAX + 0x18) == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = (*(int *)(in_EAX + 0x1c) - *(int *)(in_EAX + 0x18)) / 6;

      }

      if (param_1 <= iVar5) break;

      FUN_0098f140();

    }

    pfVar6 = *(float **)(in_EAX + 8);

    if (pfVar6 != *(float **)(in_EAX + 0xc)) {

      do {

        fVar7 = (float10)fpatan((float10)*pfVar6,(float10)pfVar6[2]);

        pfVar6[8] = (g_flOne - pfVar6[1]) * fVar4;

        pfVar6[7] = (float)((fVar7 + (float10)DAT_00a27c3c) * (float10)_DAT_00a27c50);

        fVar1 = *(float *)(in_EAX + 0x40);

        pfVar6[3] = *pfVar6 * fVar1;

        pfVar6[4] = fVar1 * pfVar6[1];

        pfVar6[5] = pfVar6[2] * fVar1;

        fVar1 = *(float *)(in_EAX + 0x3c);

        fVar2 = *(float *)(in_EAX + 0x34);

        fVar3 = *(float *)(in_EAX + 0x38);

        *pfVar6 = *pfVar6 * fVar1 + *(float *)(in_EAX + 0x30);

        pfVar6[1] = fVar2 + fVar1 * pfVar6[1];

        pfVar6[2] = fVar3 + pfVar6[2] * fVar1;

        pfVar6[6] = *(float *)(in_EAX + 0x44);

        pfVar6 = pfVar6 + 9;

      } while (pfVar6 != *(float **)(in_EAX + 0xc));

    }

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(in_EAX + 0x18));

}
