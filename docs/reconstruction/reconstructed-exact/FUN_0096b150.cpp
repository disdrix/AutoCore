// =============================================================================
// FUN_0096b150
// -----------------------------------------------------------------------------
// Stable ID: aa_0096b150
// Address:   0x0096b150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096b150 @ 0x0096b150
// Stable ID: aa_0096b150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, while×2, return×2, do×1.
//  - Notable callees: FUN_00456780×2, FUN_0044b540, FUN_0096b150, FUN_0096e1f0, _aligned_free.
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

void FUN_0096b150(int param_1,uint param_2)



{

  int iVar1;

  int *_Memory;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  

  if (*(int *)(param_1 + 0xc) == 0) {

    uVar3 = 0;

  }

  else {

    uVar3 = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc) >> 2;

  }

  if (param_2 <= uVar3) {

    if (param_2 < uVar3) {

      while (uVar3 = uVar3 - 1, param_2 <= uVar3) {

        _Memory = *(int **)(*(int *)(param_1 + 0xc) + uVar3 * 4);

        (**(code **)(*_Memory + 0x10))(0);

        _aligned_free(_Memory);

      }

      FUN_00456780(0);

      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;

      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 3;

    }

    return;

  }

  FUN_00456780(0);

  do {

    iVar1 = *(int *)(param_1 + 0xc);

    uVar2 = FUN_0044b540(0x10);

    *(uint32_t /* width from decompiler */ *)(iVar1 + uVar3 * 4) = uVar2;

    FUN_0096e1f0(uVar3,0xffffffff);

    uVar3 = uVar3 + 1;

  } while (uVar3 < param_2);

  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;

  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 3;

  return;

}
