// =============================================================================
// FUN_006f0a40
// -----------------------------------------------------------------------------
// Stable ID: aa_006f0a40
// Address:   0x006f0a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f0a40 @ 0x006f0a40
// Stable ID: aa_006f0a40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: ABS×3, FUN_006f0a40.
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

void __thiscall FUN_006f0a40(int param_1,float *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  float local_1c;

  

  fVar1 = (*param_2 * *(float *)(param_1 + 0x10) +

           *(float *)(param_1 + 0x14) * param_2[1] + *(float *)(param_1 + 0x18) * param_2[2] +

          *(float *)(param_1 + 0x1c)) - param_2[0xc];

  fVar2 = (param_2[4] * *(float *)(param_1 + 0x10) +

           param_2[5] * *(float *)(param_1 + 0x14) + param_2[6] * *(float *)(param_1 + 0x18) +

          *(float *)(param_1 + 0x1c)) - param_2[0xc];

  if ((fVar2 < g_flZero) && (fVar2 = fVar1 - fVar2, param_2[0xd] <= fVar2)) {

    local_1c = g_flZero;

    if (fVar1 < g_flZero == (fVar1 == g_flZero)) {

      local_1c = fVar1 / fVar2;

    }

    fVar2 = g_flOne - local_1c;

    fVar3 = ABS((fVar2 * *param_2 + local_1c * param_2[4]) - *(float *)(param_1 + 0x20));

    fVar1 = ABS((fVar2 * param_2[1] + local_1c * param_2[5]) - *(float *)(param_1 + 0x24));

    fVar2 = ABS((fVar2 * param_2[2] + local_1c * param_2[6]) - *(float *)(param_1 + 0x28));

    if ((byte)((fVar2 < *(float *)(param_1 + 0x38) != (fVar2 == *(float *)(param_1 + 0x38))) << 1 |

               (fVar1 < *(float *)(param_1 + 0x34) != (fVar1 == *(float *)(param_1 + 0x34))) << 2 |

              (fVar3 < *(float *)(param_1 + 0x30) != (fVar3 == *(float *)(param_1 + 0x30))) * -8 &

              0xeU) == 0xe) {

      local_30 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

      local_2c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

      local_28 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

      local_24 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

      local_20 = 0xffffffff;

      (**(code **)*param_4)(param_3,&local_30);

      return;

    }

  }

  return;

}
