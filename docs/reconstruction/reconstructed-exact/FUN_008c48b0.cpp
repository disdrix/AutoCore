// =============================================================================
// FUN_008c48b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008c48b0
// Address:   0x008c48b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c48b0 @ 0x008c48b0
// Stable ID: aa_008c48b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: CONCAT11×2, CONCAT22, FUN_008c48b0, fsin.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_008c48b0(uint param_1,float param_2)



{

  uint8_t uVar1;

  uint8_t uVar2;

  uint8_t uVar3;

  uint32_t /* width from decompiler */ *unaff_ESI;

  float10 fVar4;

  float fVar5;

  float fVar6;

  

  fVar4 = (float10)fsin((float10)param_2 * (float10)_DAT_00aaa938);

  fVar6 = (float)(fVar4 * (float10)_DAT_00aaa934 + (float10)g_flOne);

  fVar5 = (float)(param_1 & 0xff) * fVar6;

  uVar1 = (uint8_t)(int)fVar5;

  if (DAT_00aaa6f8 <= fVar5) {

    uVar1 = 0xff;

  }

  fVar5 = (float)(param_1 >> 8 & 0xff) * fVar6;

  uVar3 = (uint8_t)(int)fVar5;

  if (DAT_00aaa6f8 <= fVar5) {

    uVar3 = 0xff;

  }

  fVar6 = (float)(param_1 >> 0x10 & 0xff) * fVar6;

  uVar2 = (uint8_t)(int)fVar6;

  if (DAT_00aaa6f8 <= fVar6) {

    uVar2 = 0xff;

  }

  param_2 = (float)CONCAT22(CONCAT11((char)(param_1 >> 0x18),uVar2),CONCAT11(uVar3,uVar1));

  *unaff_ESI = param_2;

  return;

}
