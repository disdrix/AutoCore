// =============================================================================
// FUN_00987a90
// -----------------------------------------------------------------------------
// Stable ID: aa_00987a90
// Address:   0x00987a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00987a90 @ 0x00987a90
// Stable ID: aa_00987a90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: FUN_0046c300×24, FUN_0044f6a0×12, FUN_00987a90.
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

void __fastcall FUN_00987a90(int param_1)



{

  float fVar1;

  float *pfVar2;

  float *pfVar3;

  

  if (*(void **)(param_1 + 8) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 8));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  if (*(void **)(param_1 + 0x18) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x18));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0044f6a0();

  FUN_0044f6a0();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0044f6a0();

  FUN_0044f6a0();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0044f6a0();

  FUN_0044f6a0();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0044f6a0();

  FUN_0044f6a0();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0044f6a0();

  FUN_0044f6a0();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0046c300();

  FUN_0044f6a0();

  FUN_0044f6a0();

  pfVar2 = *(float **)(param_1 + 8);

  if (pfVar2 != *(float **)(param_1 + 0xc)) {

    pfVar3 = pfVar2 + 5;

    do {

      fVar1 = *(float *)(param_1 + 0x3c);

      pfVar3[-2] = pfVar3[-2] * fVar1;

      pfVar3[-1] = fVar1 * pfVar3[-1];

      *pfVar3 = fVar1 * *pfVar3;

      *pfVar2 = *(float *)(param_1 + 0x30) * *pfVar2;

      pfVar3[-4] = *(float *)(param_1 + 0x34) * pfVar3[-4];

      pfVar3[-3] = pfVar3[-3] * *(float *)(param_1 + 0x38);

      *pfVar2 = *pfVar2 + *(float *)(param_1 + 0x24);

      pfVar3[-4] = *(float *)(param_1 + 0x28) + pfVar3[-4];

      pfVar3[-3] = pfVar3[-3] + *(float *)(param_1 + 0x2c);

      pfVar2 = pfVar2 + 9;

      pfVar3 = pfVar3 + 9;

    } while (pfVar2 != *(float **)(param_1 + 0xc));

  }

  return;

}
