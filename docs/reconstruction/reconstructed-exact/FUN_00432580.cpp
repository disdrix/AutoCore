// =============================================================================
// FUN_00432580  (scaffold — prefer NDAssetImage_TransferFields_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00432580
// Address:   0x00432580–0x00432625  (autoassault.exe, image base 0x400000)
// System:    NDAssetImage buffer ownership move
// Generated: 2026-07-23 scaffold; W23-C dual seal 2026-07-29 (named plate separate)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Canonical: NDAssetImage_TransferFields_Inferred
// =============================================================================

// PURPOSE: Move owned image fields src(EBX)→dest(stack); pre-clear dest; zero src.
// Stable ID: aa_00432580
// Dual A/B: accept-with-gaps (W23-C). See named plate for sealed CF + ABI.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: for×3, return×2, if×1.
//  - Notable callees: FUN_004321b0, FUN_00432580.
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

uint32_t /* width from decompiler */ FUN_00432580(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  uVar1 = FUN_004321b0();

  if ((char)uVar1 == '\0') {

    return uVar1;

  }

  puVar3 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 8);

  puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 8);

  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar4 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar4 = puVar4 + 1;

  }

  puVar3 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x30);

  puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 0x30);

  for (iVar2 = 0x5f; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar4 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar4 = puVar4 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ac) = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1ac);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b0) = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1b0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b4) = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1b4);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x2c) = 0;

  puVar3 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x30);

  for (iVar2 = 0x5f; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1b0) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1ac) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1b4) = 0;

  return 1;

}
