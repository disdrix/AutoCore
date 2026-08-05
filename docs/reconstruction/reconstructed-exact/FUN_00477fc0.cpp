// =============================================================================
// FUN_00477fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00477fc0
// Address:   0x00477fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00477fc0 @ 0x00477fc0
// Stable ID: aa_00477fc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_00477fc0.
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

void __fastcall FUN_00477fc0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  *(int *)(param_2 + 0x34) = *(int *)(param_2 + 0x24) * 2;

  *(uint16_t *)(*(int *)(param_2 + 0x3c) + -2 + *(int *)(param_2 + 0x44) * 2) = 0;

  uVar3 = *(int *)(param_2 + 0x44) * 2 - 2;

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_2 + 0x3c);

  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(uint8_t *)puVar4 = 0;

    puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

  }

  iVar1 = *(int *)(param_2 + 0x7c) * 0xc;

  *(uint *)(param_2 + 0x78) = (uint)*(ushort *)(&DAT_00a26762 + *(int *)(param_2 + 0x7c) * 0xc);

  *(uint *)(param_2 + 0x84) = (uint)*(ushort *)(&DAT_00a26760 + iVar1);

  *(uint *)(param_2 + 0x88) = (uint)*(ushort *)(&DAT_00a26764 + iVar1);

  *(uint *)(param_2 + 0x74) = (uint)*(ushort *)(&DAT_00a26766 + iVar1);

  *(uint32_t /* width from decompiler */ *)(param_2 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x6c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x60) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x70) = 2;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x58) = 2;

  return;

}
