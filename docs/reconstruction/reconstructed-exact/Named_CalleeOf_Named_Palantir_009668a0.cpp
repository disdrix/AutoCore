// =============================================================================
// Named_CalleeOf_Named_Palantir_009668a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009668a0
// Callee of Named_Palantir
// Address:   0x009668a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Palantir: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~167 non-empty decompiler lines.
//  - Control keywords: if×22, while×3, for×2, do×1, return×1.
//  - Notable callees: FUN_0043c830×2, FUN_0076c3c0×2, FUN_009668a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Palantir
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_Palantir_009668a0(int param_1)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  iVar1 = param_1;

  *(int *)(param_1 + 0x3d0) = *(int *)(param_1 + 0x3d0) + 1;

  if (*(char *)(param_1 + 200) == '\0') {

    iVar2 = FUN_0076c3c0();

    piVar5 = (int *)(iVar1 + 0x34 + *(int *)(iVar1 + 0xc4) * 4);

    *piVar5 = *piVar5 + (iVar2 - *(int *)(iVar1 + 0x30));

    *(int *)(iVar1 + 0x30) = iVar2;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc4) = 3;

  }

  iVar2 = 0;

  piVar5 = (int *)(iVar1 + 0x34);

  param_1 = 4;

  do {

    FUN_0043c830(piVar5);

    piVar5[4] = piVar5[4] + *piVar5;

    iVar2 = iVar2 + *piVar5;

    piVar5 = piVar5 + 1;

    param_1 = param_1 + -1;

  } while (param_1 != 0);

  *(int *)(iVar1 + 0x54) = *(int *)(iVar1 + 0x54) + iVar2;

  *(int *)(iVar1 + 0xc0) = *(int *)(iVar1 + 0xc0) + iVar2;

  param_1 = iVar2;

  FUN_0043c830(&param_1);

  *(int *)(iVar1 + 0x58) = *(int *)(iVar1 + 0x58) + 1;

  iVar2 = *(int *)(iVar1 + 0x54);

  while (500 < iVar2) {

    uVar4 = *(int *)(iVar1 + 0x68) + (*(int *)(iVar1 + 0x6c) - *(int *)(iVar1 + 0x58));

    uVar3 = uVar4 >> 2;

    iVar2 = uVar3 * -4;

    if (*(uint *)(iVar1 + 100) <= uVar3) {

      uVar3 = uVar3 - *(uint *)(iVar1 + 100);

    }

    iVar2 = *(int *)(*(int *)(*(int *)(iVar1 + 0x60) + uVar3 * 4) + (uVar4 + iVar2) * 4);

    *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) - iVar2;

    *(int *)(iVar1 + 0x54) = *(int *)(iVar1 + 0x54) - iVar2;

    uVar4 = *(int *)(iVar1 + 0x7c) + (*(int *)(iVar1 + 0x80) - *(int *)(iVar1 + 0x58));

    uVar3 = uVar4 >> 2;

    iVar2 = uVar3 * -4;

    if (*(uint *)(iVar1 + 0x78) <= uVar3) {

      uVar3 = uVar3 - *(uint *)(iVar1 + 0x78);

    }

    iVar2 = *(int *)(*(int *)(*(int *)(iVar1 + 0x74) + uVar3 * 4) + (uVar4 + iVar2) * 4);

    *(int *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x48) - iVar2;

    *(int *)(iVar1 + 0x54) = *(int *)(iVar1 + 0x54) - iVar2;

    uVar4 = *(int *)(iVar1 + 0x90) + (*(int *)(iVar1 + 0x94) - *(int *)(iVar1 + 0x58));

    uVar3 = uVar4 >> 2;

    iVar2 = uVar3 * -4;

    if (*(uint *)(iVar1 + 0x8c) <= uVar3) {

      uVar3 = uVar3 - *(uint *)(iVar1 + 0x8c);

    }

    iVar2 = *(int *)(*(int *)(*(int *)(iVar1 + 0x88) + uVar3 * 4) + (uVar4 + iVar2) * 4);

    *(int *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) - iVar2;

    *(int *)(iVar1 + 0x54) = *(int *)(iVar1 + 0x54) - iVar2;

    uVar4 = *(int *)(iVar1 + 0xa4) + (*(int *)(iVar1 + 0xa8) - *(int *)(iVar1 + 0x58));

    uVar3 = uVar4 >> 2;

    iVar2 = uVar3 * -4;

    if (*(uint *)(iVar1 + 0xa0) <= uVar3) {

      uVar3 = uVar3 - *(uint *)(iVar1 + 0xa0);

    }

    iVar2 = *(int *)(*(int *)(*(int *)(iVar1 + 0x9c) + uVar3 * 4) + (uVar4 + iVar2) * 4);

    *(int *)(iVar1 + 0x50) = *(int *)(iVar1 + 0x50) - iVar2;

    *(int *)(iVar1 + 0x54) = *(int *)(iVar1 + 0x54) - iVar2;

    *(int *)(iVar1 + 0x58) = *(int *)(iVar1 + 0x58) + -1;

    iVar2 = *(int *)(iVar1 + 0x54);

  }

  iVar2 = *(int *)(iVar1 + 0xc0);

  while (3000 < iVar2) {

    if (*(int *)(iVar1 + 0x6c) != 0) {

      *(int *)(iVar1 + 0x68) = *(int *)(iVar1 + 0x68) + 1;

      if ((uint)(*(int *)(iVar1 + 100) * 4) <= *(uint *)(iVar1 + 0x68)) {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x68) = 0;

      }

      iVar2 = *(int *)(iVar1 + 0x6c) + -1;

      *(int *)(iVar1 + 0x6c) = iVar2;

      if (iVar2 == 0) {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x68) = 0;

      }

    }

    if (*(int *)(iVar1 + 0x80) != 0) {

      *(int *)(iVar1 + 0x7c) = *(int *)(iVar1 + 0x7c) + 1;

      if ((uint)(*(int *)(iVar1 + 0x78) * 4) <= *(uint *)(iVar1 + 0x7c)) {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x7c) = 0;

      }

      iVar2 = *(int *)(iVar1 + 0x80) + -1;

      *(int *)(iVar1 + 0x80) = iVar2;

      if (iVar2 == 0) {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x7c) = 0;

      }

    }

    if (*(int *)(iVar1 + 0x94) != 0) {

      *(int *)(iVar1 + 0x90) = *(int *)(iVar1 + 0x90) + 1;

      if ((uint)(*(int *)(iVar1 + 0x8c) * 4) <= *(uint *)(iVar1 + 0x90)) {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90) = 0;

      }

      iVar2 = *(int *)(iVar1 + 0x94) + -1;

      *(int *)(iVar1 + 0x94) = iVar2;

      if (iVar2 == 0) {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90) = 0;

      }

    }

    if (*(int *)(iVar1 + 0xa8) != 0) {

      *(int *)(iVar1 + 0xa4) = *(int *)(iVar1 + 0xa4) + 1;

      if ((uint)(*(int *)(iVar1 + 0xa0) * 4) <= *(uint *)(iVar1 + 0xa4)) {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0xa4) = 0;

      }

      iVar2 = *(int *)(iVar1 + 0xa8) + -1;

      *(int *)(iVar1 + 0xa8) = iVar2;

      if (iVar2 == 0) {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0xa4) = 0;

      }

    }

    uVar3 = *(uint *)(iVar1 + 0xb8) >> 2;

    iVar2 = uVar3 * -4;

    if (*(uint *)(iVar1 + 0xb4) <= uVar3) {

      uVar3 = uVar3 - *(uint *)(iVar1 + 0xb4);

    }

    *(int *)(iVar1 + 0xc0) =

         *(int *)(iVar1 + 0xc0) -

         *(int *)(*(int *)(*(int *)(iVar1 + 0xb0) + uVar3 * 4) +

                 (*(uint *)(iVar1 + 0xb8) + iVar2) * 4);

    if (*(int *)(iVar1 + 0xbc) != 0) {

      *(int *)(iVar1 + 0xb8) = *(int *)(iVar1 + 0xb8) + 1;

      if ((uint)(*(int *)(iVar1 + 0xb4) * 4) <= *(uint *)(iVar1 + 0xb8)) {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb8) = 0;

      }

      iVar2 = *(int *)(iVar1 + 0xbc) + -1;

      *(int *)(iVar1 + 0xbc) = iVar2;

      if (iVar2 == 0) {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb8) = 0;

      }

    }

    iVar2 = *(int *)(iVar1 + 0xc0);

  }

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x40) = 0;

  puVar6 = (uint32_t /* width from decompiler */ *)(iVar1 + 0xcc);

  puVar7 = (uint32_t /* width from decompiler */ *)(iVar1 + 0x1fc);

  for (iVar2 = 0x4c; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar7 = *puVar6;

    puVar6 = puVar6 + 1;

    puVar7 = puVar7 + 1;

  }

  puVar6 = (uint32_t /* width from decompiler */ *)(iVar1 + 0xcc);

  for (iVar2 = 0x4c; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  if (*(char *)(iVar1 + 200) == '\0') {

    iVar2 = FUN_0076c3c0();

    piVar5 = (int *)(iVar1 + 0x34 + *(int *)(iVar1 + 0xc4) * 4);

    *piVar5 = *piVar5 + (iVar2 - *(int *)(iVar1 + 0x30));

    *(int *)(iVar1 + 0x30) = iVar2;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc4) = 0;

  }

  return;

}
