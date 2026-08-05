// =============================================================================
// FUN_0063f210
// -----------------------------------------------------------------------------
// Stable ID: aa_0063f210
// Address:   0x0063f210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063f210 @ 0x0063f210
// Stable ID: aa_0063f210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0063f210.
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

void __thiscall FUN_0063f210(int param_1,uint8_t *param_2,int param_3)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  

  iVar1 = *(int *)(param_3 + 0x3c);

  fVar4 = *(float *)(param_1 + 0x38) - *(float *)(iVar1 + 0xb8);

  fVar3 = *(float *)(param_1 + 0x34) - *(float *)(iVar1 + 0xb4);

  fVar2 = *(float *)(param_1 + 0x30) - *(float *)(iVar1 + 0xb0);

  fVar5 = *(float *)(param_1 + 0x40) - *(float *)(iVar1 + 0x30);

  fVar6 = *(float *)(param_1 + 0x44) - *(float *)(iVar1 + 0x34);

  fVar7 = *(float *)(param_1 + 0x48) - *(float *)(iVar1 + 0x38);

  fVar8 = *(float *)(param_1 + 0x4c) - *(float *)(iVar1 + 0x3c);

  if ((fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2 <

       *(float *)(param_1 + 0x58) * *(float *)(param_1 + 0x58)) &&

     ((fVar8 * fVar8 + fVar7 * fVar7 + fVar6 * fVar6 + fVar5 * fVar5) * *(float *)(param_1 + 8) <

      *(float *)(param_1 + 0x5c) * *(float *)(param_1 + 0x5c))) {

    *param_2 = 1;

    return;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x30);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x38);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x3c);

  iVar1 = *(int *)(param_3 + 0x3c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc);

  *param_2 = 0;

  return;

}
