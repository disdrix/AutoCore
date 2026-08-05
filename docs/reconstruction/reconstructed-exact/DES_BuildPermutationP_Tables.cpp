// =============================================================================
// DES_BuildPermutationP_Tables
// -----------------------------------------------------------------------------
// Stable ID: aa_0071b5a0
// Address:   0x0071b5a0  (autoassault.exe, image base 0x400000)
// System:    auth
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W19-Q dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29):
 * - Builds four 256×4 OR-contrib banks for DES P-permutation at DAT_00d11658
 *   (+ k*0x400, k=0..3). Consumed by DES_CalculatePermutationP (0x0071bc40).
 * - Source: FIPS P table DAT_00afcd48 (1-based bit positions) + bit masks
 *   DAT_00afcd68 {0x80,0x40,...,0x01}.
 * - Zero-fills 0x400 dwords first (rep stosd in entry; static BSS reads all-zero).
 * - Sole caller: DES_InitializeCipher @ 0x0071c070 (after FUN_0071bdd0).
 * - Runtime / differential / FIPS known-answer: OPEN (no Launcher this pass).
 *
 * Readability:
 * - Control flow preserved from live Ghidra decompile.
 * - undefined4 → uint32_t for clear pointer only.
 */

#include <stdint.h>

/* External symbols — image VAs (autoassault.exe base 0x400000) */
extern uint32_t DAT_00d11658[];   /* BSS: 0x1000-byte P banks */
extern char     DAT_00afcd48[];   /* FIPS P, 32 signed chars */
extern uint32_t DAT_00afcd68[];   /* 8 bit masks as dwords */

void DES_BuildPermutationP_Tables(void)
{
  uint8_t *pbVar1;
  uint32_t uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t *puVar7;
  uint32_t uVar8;
  int local_c;
  uint32_t local_8;
  int local_4;

  puVar7 = &DAT_00d11658[0];
  for (iVar3 = 0x400; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_4 = 0;
  local_c = 0;
  do {
    uVar4 = 0;
    do {
      local_8 = 0;
      uVar6 = 3;
      uVar8 = 2;
      uVar5 = 1;
      do {
        /* P[local_8] via (uVar5 + 0xafcd47) == afcd48[uVar5-1] */
        uVar2 = (int)*(char *)(uVar5 + 0xafcd47) - 1;
        if (((int)uVar2 >> 3 == local_4) &&
           ((*(uint32_t *)((char *)&DAT_00afcd68 + (uVar2 & 7) * 4) & uVar4) != 0)) {
          pbVar1 = (uint8_t *)((int)&DAT_00d11658 + (local_c + uVar4) * 4 + ((int)local_8 >> 3));
          *pbVar1 = *pbVar1 | (uint8_t)DAT_00afcd68[(local_8 & 7)];
        }
        if (((int)((int)(char)DAT_00afcd48[uVar5] - 1U) >> 3 == local_4) &&
           ((*(uint32_t *)((char *)&DAT_00afcd68 + ((int)(char)DAT_00afcd48[uVar5] - 1U & 7) * 4) & uVar4) !=
            0)) {
          pbVar1 = (uint8_t *)((int)&DAT_00d11658 + (local_c + uVar4) * 4 + ((int)uVar5 >> 3));
          *pbVar1 = *pbVar1 | (uint8_t)DAT_00afcd68[(uVar5 & 7)];
        }
        if (((int)((int)(char)DAT_00afcd48[uVar8] - 1U) >> 3 == local_4) &&
           ((*(uint32_t *)((char *)&DAT_00afcd68 + ((int)(char)DAT_00afcd48[uVar8] - 1U & 7) * 4) & uVar4) !=
            0)) {
          pbVar1 = (uint8_t *)((int)&DAT_00d11658 + (local_c + uVar4) * 4 + ((int)uVar8 >> 3));
          *pbVar1 = *pbVar1 | (uint8_t)DAT_00afcd68[(uVar8 & 7)];
        }
        if (((int)((int)(char)DAT_00afcd48[uVar6] - 1U) >> 3 == local_4) &&
           ((*(uint32_t *)((char *)&DAT_00afcd68 + ((int)(char)DAT_00afcd48[uVar6] - 1U & 7) * 4) & uVar4) !=
            0)) {
          pbVar1 = (uint8_t *)((int)&DAT_00d11658 + (local_c + uVar4) * 4 + ((int)uVar6 >> 3));
          *pbVar1 = *pbVar1 | (uint8_t)DAT_00afcd68[(uVar6 & 7)];
        }
        local_8 = local_8 + 4;
        uVar5 = uVar5 + 4;
        uVar8 = uVar8 + 4;
        uVar6 = uVar6 + 4;
      } while ((int)uVar5 < 0x21);
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 0x100);
    local_c = local_c + 0x100;
    local_4 = local_4 + 1;
  } while (local_c < 0x400);
  return;
}
