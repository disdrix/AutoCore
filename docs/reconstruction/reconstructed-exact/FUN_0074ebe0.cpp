// =============================================================================
// FUN_0074ebe0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074ebe0
// Address:   0x0074ebe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074ebe0 @ 0x0074ebe0
// Stable ID: aa_0074ebe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: CONCAT11×2, NAN×2, CONCAT31, FUN_0074e800, FUN_0074ebe0, FUN_009873a0.
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

uint16_t FUN_0074ebe0(int param_1)



{

  float fVar1;

  float fVar2;

  uint16_t uVar3;

  byte bVar4;

  int in_EAX;

  float10 extraout_ST0;

  

  *(uint32_t /* width from decompiler */ *)(in_EAX + 100) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x6c);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x60) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x68);

  uVar3 = FUN_0074e800(param_1);

  fVar2 = (float)extraout_ST0;

  *(float *)(in_EAX + 0x6c) = (float)extraout_ST0;

  *(int *)(in_EAX + 0x68) = *(int *)(in_EAX + 0x50);

  if (*(int *)(in_EAX + 0x60) != -1) {

    fVar1 = *(float *)(in_EAX + 100);

    bVar4 = (fVar1 == fVar2) << 6 | (NAN(fVar1) || NAN(fVar2)) << 2 | 2U | fVar1 < fVar2;

    uVar3 = CONCAT11(bVar4,(char)uVar3);

    if (fVar1 != fVar2) {

      param_1._1_3_ = (uint3)((uint)fVar2 >> 8);

      param_1 = CONCAT31(param_1._1_3_,1);

      if (*(float *)(in_EAX + 0x3c) < g_flZero) {

        param_1 = (uint)param_1._1_3_ << 8;

      }

      uVar3 = CONCAT11(bVar4,*(int *)(in_EAX + 0x60) != *(int *)(in_EAX + 0x50));

      if (*(int *)(in_EAX + 0x58) != 0) {

        uVar3 = FUN_009873a0(*(uint32_t /* width from decompiler */ *)(in_EAX + 100),fVar2,param_1);

      }

    }

  }

  return uVar3;

}
