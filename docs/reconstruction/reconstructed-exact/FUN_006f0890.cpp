// =============================================================================
// FUN_006f0890
// -----------------------------------------------------------------------------
// Stable ID: aa_006f0890
// Address:   0x006f0890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f0890 @ 0x006f0890
// Stable ID: aa_006f0890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: ABS×3, FUN_006f0890.
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

void __thiscall FUN_006f0890(int param_1,uint8_t *param_2,float *param_3,uint32_t /* width from decompiler */ *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  fVar3 = *(float *)(param_1 + 0x10) * *param_3 +

          *(float *)(param_1 + 0x14) * param_3[1] + *(float *)(param_1 + 0x18) * param_3[2] +

          *(float *)(param_1 + 0x1c);

  if ((g_flZero <= fVar3) &&

     (fVar1 = param_3[4] * *(float *)(param_1 + 0x10) +

              param_3[5] * *(float *)(param_1 + 0x14) + param_3[6] * *(float *)(param_1 + 0x18) +

              *(float *)(param_1 + 0x1c), fVar1 < g_flZero)) {

    fVar3 = fVar3 / (fVar3 - fVar1);

    fVar2 = g_flOne - fVar3;

    fVar4 = ABS((fVar3 * param_3[4] + fVar2 * *param_3) - *(float *)(param_1 + 0x20));

    fVar1 = ABS((fVar2 * param_3[1] + fVar3 * param_3[5]) - *(float *)(param_1 + 0x24));

    fVar2 = ABS((fVar2 * param_3[2] + fVar3 * param_3[6]) - *(float *)(param_1 + 0x28));

    if ((byte)((fVar2 < *(float *)(param_1 + 0x38) != (fVar2 == *(float *)(param_1 + 0x38))) << 1 |

               (fVar1 < *(float *)(param_1 + 0x34) != (fVar1 == *(float *)(param_1 + 0x34))) << 2 |

              (fVar4 < *(float *)(param_1 + 0x30) != (fVar4 == *(float *)(param_1 + 0x30))) * -8 &

              0xeU) == 0xe) {

      param_4[5] = fVar3;

      *param_4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

      param_4[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

      param_4[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

      param_4[3] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

      param_4[4] = 0xffffffff;

      *param_2 = 1;

      return;

    }

  }

  *param_2 = 0;

  return;

}
