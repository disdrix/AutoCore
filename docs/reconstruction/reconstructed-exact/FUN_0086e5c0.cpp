// =============================================================================
// FUN_0086e5c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0086e5c0
// Address:   0x0086e5c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0086e5c0 @ 0x0086e5c0
// Stable ID: aa_0086e5c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_0086e5c0.
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

void __fastcall FUN_0086e5c0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  *(uint8_t *)((int)param_2 + 0x25) = *(uint8_t *)((int)in_EAX + 0x25);

  param_2[0xb] = in_EAX[0xb];

  param_2[10] = in_EAX[10];

  *(uint16_t *)(param_2 + 0xc) = *(uint16_t *)(in_EAX + 0xc);

  param_2[0x12] = in_EAX[0x12];

  param_2[0x13] = in_EAX[0x13];

  *(uint8_t *)(param_2 + 0x11) = *(uint8_t *)(in_EAX + 0x11);

  param_2[0x10] = in_EAX[0x10];

  param_2[0xe] = in_EAX[0xe];

  param_2[0xf] = in_EAX[0xf];

  param_2[0x14] = in_EAX[0x14];

  *(uint16_t *)((int)param_2 + 0x32) = *(uint16_t *)((int)in_EAX + 0x32);

  *param_2 = *in_EAX;

  *(uint8_t *)((int)param_2 + 0x26) = *(uint8_t *)((int)in_EAX + 0x26);

  *(uint8_t *)(param_2 + 0x15) = *(uint8_t *)(in_EAX + 0x15);

  puVar3 = in_EAX + 0x16;

  puVar4 = param_2 + 0x16;

  for (uVar1 = (uint)(in_EAX[0x14] * 0x78) >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {

    *puVar4 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar4 = puVar4 + 1;

  }

  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {

    *(uint8_t *)puVar4 = *(uint8_t *)puVar3;

    puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

    puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

  }

  return;

}
