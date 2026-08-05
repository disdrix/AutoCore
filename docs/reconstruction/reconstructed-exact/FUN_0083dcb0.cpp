// =============================================================================
// FUN_0083dcb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0083dcb0
// Address:   0x0083dcb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083dcb0 @ 0x0083dcb0
// Stable ID: aa_0083dcb0
// Embedded strings (evidence for future rename):
//   - "%i%i"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_0083dae0×3, FUN_0040ac40, FUN_0083dcb0, atoi, sprintf.
//  - Strings: "%i%i".
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

void __fastcall FUN_0083dcb0(int param_1)



{

  ushort uVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  char local_10 [16];

  

  sprintf(local_10,"%i%i",*(uint32_t /* width from decompiler */ *)(param_1 + 0x4fc));

  iVar2 = atoi(local_10);

  iVar3 = (**(code **)(**(int **)(param_1 + 0x500) + 0x25c))();

  if (iVar3 < iVar2) {

    uVar4 = (**(code **)(**(int **)(param_1 + 0x500) + 0x25c))();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x4fc) = uVar4;

    FUN_0083dae0();

    return;

  }

  iVar3 = (**(code **)(**(int **)(param_1 + 0x500) + 0x25c))();

  if (iVar2 <= iVar3) {

    *(int *)(param_1 + 0x4fc) = iVar2;

    FUN_0083dae0();

    return;

  }

  iVar3 = *(int *)(*(int *)(param_1 + 0x500) + 0xa8);

  if (*(int *)(iVar3 + 0x38) == 4) {

    uVar5 = 999999;

  }

  else {

    uVar1 = *(ushort *)(*(int *)(iVar3 + 0x3c) + 0x4ba);

    uVar5 = (uint)uVar1;

    if (uVar1 == 0) {

      uVar5 = 200;

    }

  }

  if ((int)(uVar5 & 0xffff) < iVar2) {

    uVar5 = FUN_0040ac40();

    *(uint *)(param_1 + 0x4fc) = uVar5 & 0xffff;

  }

  FUN_0083dae0();

  return;

}
