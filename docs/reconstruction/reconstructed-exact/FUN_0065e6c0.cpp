// =============================================================================
// FUN_0065e6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0065e6c0
// Address:   0x0065e6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065e6c0 @ 0x0065e6c0
// Stable ID: aa_0065e6c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~167 non-empty decompiler lines.
//  - Control keywords: return×5, goto×4, switch×1.
//  - Notable callees: FUN_0065e6c0.
//  - Return sites: 5.

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

void __thiscall FUN_0065e6c0(int param_1,uint8_t *param_2)



{

  float fVar1;

  float fVar2;

  

  *(uint8_t *)(param_1 + 8) = *param_2;

  fVar1 = DAT_00aaa668;

  fVar2 = g_flOne;

  switch(*param_2) {

  case 0:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(float *)(param_1 + 0x28) = fVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(float *)(param_1 + 0x30) = fVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(float *)(param_1 + 0x14) = fVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

    return;

  case 1:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    *(float *)(param_1 + 0x24) = fVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

    *(float *)(param_1 + 0x38) = fVar2;

    goto LAB_0065ea2b;

  case 2:

    *(float *)(param_1 + 0x20) = g_flOne;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

    *(float *)(param_1 + 0x34) = fVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(float *)(param_1 + 0x18) = fVar2;

    break;

  case 3:

    *(float *)(param_1 + 0x20) = g_flOne;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

    *(float *)(param_1 + 0x38) = fVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(float *)(param_1 + 0x14) = fVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

    return;

  case 4:

    *(float *)(param_1 + 0x20) = g_flOne;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

    *(float *)(param_1 + 0x34) = fVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(float *)(param_1 + 0x18) = fVar1;

    break;

  case 5:

    *(float *)(param_1 + 0x20) = g_flOne;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(float *)(param_1 + 0x38) = fVar2;

    fVar2 = DAT_00aaa668;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(float *)(param_1 + 0x14) = fVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

    return;

  case 6:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    *(float *)(param_1 + 0x24) = fVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(float *)(param_1 + 0x30) = fVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(float *)(param_1 + 0x18) = fVar2;

    break;

  case 7:

    *(float *)(param_1 + 0x24) = g_flOne;

    fVar2 = DAT_00aaa668;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

    *(float *)(param_1 + 0x38) = fVar2;

    goto LAB_0065ea2b;

  case 8:

    *(float *)(param_1 + 0x24) = g_flOne;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(float *)(param_1 + 0x30) = fVar2;

    fVar2 = DAT_00aaa668;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(float *)(param_1 + 0x18) = fVar2;

    break;

  case 9:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(float *)(param_1 + 0x28) = fVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(float *)(param_1 + 0x34) = fVar1;

    goto LAB_0065ea26;

  case 10:

    *(float *)(param_1 + 0x28) = g_flOne;

    fVar2 = DAT_00aaa668;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(float *)(param_1 + 0x30) = fVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(float *)(param_1 + 0x14) = fVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

    return;

  case 0xb:

    *(float *)(param_1 + 0x28) = g_flOne;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    *(float *)(param_1 + 0x34) = fVar2;

    fVar2 = DAT_00aaa668;

LAB_0065ea26:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

LAB_0065ea2b:

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

    *(float *)(param_1 + 0x10) = fVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

    break;

  default:

    goto switchD_0065e6da_default;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

switchD_0065e6da_default:

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

  return;

}
