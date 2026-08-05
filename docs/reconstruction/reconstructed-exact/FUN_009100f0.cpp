// =============================================================================
// FUN_009100f0
// -----------------------------------------------------------------------------
// Stable ID: aa_009100f0
// Address:   0x009100f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009100f0 @ 0x009100f0
// Stable ID: aa_009100f0
// Embedded strings (evidence for future rename):
//   - "gWorldFogCenter"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0040d4b0×3, FUN_0090f8e0, FUN_009100f0.
//  - Strings: "gWorldFogCenter".
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

void __fastcall FUN_009100f0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  int in_EAX;

  int *piVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  if (in_EAX != 0) {

    piVar5 = (int *)FUN_0040d4b0(1);

    piVar6 = (int *)FUN_0040d4b0(5);

    uVar7 = FUN_0040d4b0(0x2b);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x59c) = uVar7;

    iVar3 = *piVar5;

    puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5e8);

    *puVar1 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5ec) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5f0) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x600) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x604) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x608) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5f4) = *puVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5f8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5ec);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5fc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5f0);

    iVar3 = *piVar6;

    puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5c4);

    *puVar2 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c8) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5cc) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5b8) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5bc) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c0) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5d0) = *puVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5d4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5d8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5cc);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5dc) = *puVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5e0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5e4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5cc);

    FUN_0090f8e0(*puVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x5ec),*(uint32_t /* width from decompiler */ *)(param_1 + 0x5f0),*puVar2,

                 *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c8),*(uint32_t /* width from decompiler */ *)(param_1 + 0x5cc));

    iVar4 = DAT_00d1f05c;

    iVar3 = *(int *)(*(int *)(param_1 + 0x2a4) + 8);

    if (*(int *)(*(int *)(DAT_00d1f05c + 4) + 0xc) == 0) {

      uVar7 = 0;

    }

    else {

      piVar5 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

      uVar7 = (**(code **)(*piVar5 + 0x24))(piVar5,0,"gWorldFogCenter");

    }

    piVar5 = *(int **)(*(int *)(iVar4 + 4) + 0xc);

    (**(code **)(*piVar5 + 0x50))(piVar5,uVar7,iVar3 + 0x90,0xffffffff);

    iVar3 = *(int *)(*(int *)(param_1 + 0x2a4) + 8);

    iVar4 = *(int *)(DAT_00d1b644 + 0xe898);

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x8c) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x90);

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x90) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x94);

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x94) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x98);

  }

  return;

}
