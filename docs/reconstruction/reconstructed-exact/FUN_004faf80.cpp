// =============================================================================
// FUN_004faf80
// -----------------------------------------------------------------------------
// Stable ID: aa_004faf80
// Address:   0x004faf80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004faf80 @ 0x004faf80
// Stable ID: aa_004faf80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004cd220, FUN_004faf80, SQRT.
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

void __fastcall FUN_004faf80(int param_1)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  if (*(int *)(param_1 + 0x118) == 1) {

    iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x3c);

    iVar2 = *(int *)(param_1 + 0x1a4);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x40) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb0);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb4);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x48) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb8);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x4c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc);

    iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x3c);

    iVar2 = *(int *)(param_1 + 0x1a4);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x60) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x30);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 100) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x68) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x38);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x6c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x3c);

    iVar1 = *(int *)(param_1 + 0x1a4);

    fVar3 = (float10)FUN_004cd220(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x40),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x48));

    *(float *)(*(int *)(param_1 + 0x1a4) + 0x50) =

         (float)((float10)*(float *)(iVar1 + 0x44) - fVar3);

    iVar1 = *(int *)(param_1 + 0x1a4);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x40) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x40);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x44) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x48) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x48);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4c) = 0;

    iVar1 = *(int *)(param_1 + 0x1a4);

    fVar6 = *(float *)(iVar1 + 0x48) - *(float *)(iVar1 + 0x18);

    fVar5 = *(float *)(iVar1 + 0x44) - *(float *)(iVar1 + 0x14);

    fVar4 = *(float *)(iVar1 + 0x40) - *(float *)(iVar1 + 0x10);

    *(float *)(iVar1 + 0x7c) = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar6 * fVar6);

    iVar1 = *(int *)(param_1 + 0x1a4);

    if (*(float *)(iVar1 + 0x90) <= *(float *)(iVar1 + 0x7c) &&

        *(float *)(iVar1 + 0x7c) != *(float *)(iVar1 + 0x90)) {

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x7c);

      **(uint8_t **)(param_1 + 0x1a4) = 1;

    }

    iVar1 = *(int *)(param_1 + 0x1a4);

    if (*(float *)(iVar1 + 0x98) <= *(float *)(iVar1 + 0x84) &&

        *(float *)(iVar1 + 0x84) != *(float *)(iVar1 + 0x98)) {

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x98) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x84);

      **(uint8_t **)(param_1 + 0x1a4) = 1;

    }

    iVar1 = *(int *)(param_1 + 0x1a4);

    if (*(float *)(iVar1 + 0x94) <= *(float *)(iVar1 + 0x80) &&

        *(float *)(iVar1 + 0x80) != *(float *)(iVar1 + 0x94)) {

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x94) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x80);

      **(uint8_t **)(param_1 + 0x1a4) = 1;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = 2;

  }

  return;

}
