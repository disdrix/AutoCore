// =============================================================================
// FUN_0053e600
// -----------------------------------------------------------------------------
// Stable ID: aa_0053e600
// Address:   0x0053e600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053e600 @ 0x0053e600
// Stable ID: aa_0053e600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×12, return×4.
//  - Notable callees: FUN_0053e020×8, CVOGPhysics_ApplyImpulseVector, FUN_0040d2a0, FUN_0053e600, FUN_0053fc10, SQRT.
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

void __fastcall FUN_0053e600(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  float *pfVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  char cVar8;

  uint32_t /* width from decompiler */ uVar9;

  

  if (*(int *)(param_1 + -0x48) != 0) {

    cVar8 = FUN_0053fc10();

    if (cVar8 != '\0') {

      if (*(char *)(param_1 + -0x30) == '\0') {

        *(uint8_t *)(param_1 + -0x30) = 1;

        iVar4 = *(int *)(*(int *)(param_1 + -0x48) + 0x3c);

        if (*(int *)(param_1 + -0x2c) == 0) {

          uVar9 = FUN_0053e020();

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c) = uVar9;

        }

        puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + -0x2c);

        *puVar6 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0xb0);

        puVar6[1] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0xb4);

        puVar6[2] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0xb8);

        puVar6[3] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0xbc);

        iVar4 = *(int *)(*(int *)(param_1 + -0x48) + 0x3c);

        if (*(int *)(param_1 + -0x2c) == 0) {

          uVar9 = FUN_0053e020();

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c) = uVar9;

        }

        iVar7 = *(int *)(param_1 + -0x2c);

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x20) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x40);

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x44);

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x28) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x48);

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x4c);

        iVar4 = *(int *)(*(int *)(param_1 + -0x48) + 0x3c);

        if (*(int *)(param_1 + -0x2c) == 0) {

          uVar9 = FUN_0053e020();

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c) = uVar9;

        }

        iVar7 = *(int *)(param_1 + -0x2c);

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x30) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x50);

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x34) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x54);

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x38) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x58);

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x3c) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x5c);

        return;

      }

      iVar4 = *(int *)(*(int *)(param_1 + -0x48) + 0x3c);

      fVar1 = *(float *)(iVar4 + 0xb0);

      fVar2 = *(float *)(iVar4 + 0xb4);

      fVar3 = *(float *)(iVar4 + 0xb8);

      if (*(int *)(param_1 + -0x2c) == 0) {

        uVar9 = FUN_0053e020();

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c) = uVar9;

      }

      pfVar5 = *(float **)(param_1 + -0x2c);

      fVar1 = fVar1 - *pfVar5;

      fVar2 = fVar2 - pfVar5[1];

      fVar3 = fVar3 - pfVar5[2];

      if (DAT_00a0f694 < SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3)) {

        if (pfVar5 == (float *)0x0) {

          uVar9 = FUN_0053e020();

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c) = uVar9;

        }

        FUN_0040d2a0(*(uint32_t /* width from decompiler */ *)(param_1 + -0x2c));

        if (*(int *)(param_1 + -0x2c) == 0) {

          uVar9 = FUN_0053e020();

          *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c) = uVar9;

        }

        CVOGPhysics_ApplyImpulseVector(*(int *)(param_1 + -0x2c) + 0x20);

        return;

      }

      iVar4 = *(int *)(*(int *)(param_1 + -0x48) + 0x3c);

      if (*(int *)(param_1 + -0x2c) == 0) {

        uVar9 = FUN_0053e020();

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c) = uVar9;

      }

      puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + -0x2c);

      *puVar6 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0xb0);

      puVar6[1] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0xb4);

      puVar6[2] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0xb8);

      puVar6[3] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0xbc);

      iVar4 = *(int *)(*(int *)(param_1 + -0x48) + 0x3c);

      if (*(int *)(param_1 + -0x2c) == 0) {

        uVar9 = FUN_0053e020();

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c) = uVar9;

      }

      iVar7 = *(int *)(param_1 + -0x2c);

      *(uint32_t /* width from decompiler */ *)(iVar7 + 0x20) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x40);

      *(uint32_t /* width from decompiler */ *)(iVar7 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x44);

      *(uint32_t /* width from decompiler */ *)(iVar7 + 0x28) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x48);

      *(uint32_t /* width from decompiler */ *)(iVar7 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x4c);

      return;

    }

  }

  *(uint8_t *)(param_1 + -0x30) = 0;

  return;

}
