// =============================================================================
// FUN_0071eec0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071eec0
// Address:   0x0071eec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071eec0 @ 0x0071eec0
// Stable ID: aa_0071eec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0071eec0, ov_open_callbacks.
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

uint __fastcall FUN_0071eec0(int param_1)



{

  int iVar1;

  void *pvVar2;

  uint uVar3;

  uint8_t *unaff_ESI;

  

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

  iVar1 = *(int *)(param_1 + 0x20);

  *(int *)(unaff_ESI + 0x34) = iVar1 >> 0x1f;

  *(int *)(unaff_ESI + 0x30) = iVar1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  *(uint16_t *)(unaff_ESI + 0x18) = 0;

  *(uint16_t *)(unaff_ESI + 0x18) = 0x12;

  *(uint16_t *)(unaff_ESI + 10) = *(uint16_t *)(param_1 + 10);

  *(uint16_t *)(unaff_ESI + 0x16) = 0x10;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  *(uint *)(unaff_ESI + 0x10) = (uint)*(ushort *)(unaff_ESI + 10) * *(int *)(param_1 + 0xc) * 2;

  *(short *)(unaff_ESI + 0x14) = *(short *)(param_1 + 10) * 2;

  *(uint16_t *)(unaff_ESI + 8) = 1;

  *(uint8_t **)(unaff_ESI + 0x44) = &LAB_0071ee00;

  *(uint8_t **)(unaff_ESI + 0x4c) = &LAB_0071ed30;

  *(uint8_t **)(unaff_ESI + 0x48) = &LAB_0071ed40;

  *(uint8_t **)(unaff_ESI + 0x50) = &LAB_0071ed20;

  unaff_ESI[2] = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

  pvVar2 = operator_new(0x2d0);

  *(void **)(unaff_ESI + 0x40) = pvVar2;

  uVar3 = ov_open_callbacks(unaff_ESI + 0x28,pvVar2,0,0,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44),

                            *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x48),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4c),

                            *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x50));

  if (uVar3 != 0) {

    return uVar3 & 0xffffff00;

  }

  *unaff_ESI = 1;

  return 1;

}
