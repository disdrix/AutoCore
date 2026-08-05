// =============================================================================
// FUN_0053dee0
// -----------------------------------------------------------------------------
// Stable ID: aa_0053dee0
// Address:   0x0053dee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053dee0 @ 0x0053dee0
// Stable ID: aa_0053dee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0053dee0.
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

void __fastcall FUN_0053dee0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  *(uint *)(param_1 + 0x30) = g_dwClientTickMs;

  if (*(int *)(param_1 + 8) == 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);

  }

  else {

    puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0);

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x2c);

  *puVar1 = *puVar4;

  puVar1[1] = puVar4[1];

  puVar1[2] = puVar4[2];

  puVar1[3] = puVar4[3];

  if (*(int *)(param_1 + 8) == 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1);

  }

  else {

    puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x30);

  }

  iVar2 = *(int *)(param_1 + 0x2c);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x10) = *puVar4;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x14) = puVar4[1];

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x18) = puVar4[2];

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x1c) = puVar4[3];

  if (*(int *)(param_1 + 8) != 0) {

    iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x3c);

    iVar3 = *(int *)(param_1 + 0x2c);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x40);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x44);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x48);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x4c);

    iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x3c);

    iVar3 = *(int *)(param_1 + 0x2c);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x30) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x50);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x34) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x54);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x38) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x58);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x3c) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x5c);

    return;

  }

  iVar2 = *(int *)(param_1 + 0x2c);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x2c) = 0;

  iVar2 = *(int *)(param_1 + 0x2c);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x3c) = 0;

  return;

}
