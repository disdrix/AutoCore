// =============================================================================
// FUN_00772ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00772ff0
// Address:   0x00772ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00772ff0 @ 0x00772ff0
// Stable ID: aa_00772ff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~111 non-empty decompiler lines.
//  - Control keywords: if×13, do×3, while×3, return×1.
//  - Notable callees: FUN_007703d0×7, FUN_007707d0×7, FUN_007716f0×3, FUN_00772390×3, FUN_00774e60×3, FUN_00770820×2, FUN_00771c00×2, FUN_00772ff0.
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

uint32_t /* width from decompiler */ FUN_00772ff0(int *param_1)



{

  int *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint32_t /* width from decompiler */ local_78;

  int local_74;

  uint8_t local_70 [16];

  int local_60 [3];

  uint32_t /* width from decompiler */ *local_54;

  int local_50;

  uint32_t /* width from decompiler */ *local_44;

  uint8_t local_40 [16];

  int local_30 [3];

  uint32_t /* width from decompiler */ *local_24;

  int local_20 [3];

  uint32_t /* width from decompiler */ *local_14;

  uint8_t local_10 [16];

  

  local_78 = 0xfffffffe;

  iVar5 = *param_1;

  if (*in_EAX < *param_1) {

    iVar5 = *in_EAX;

  }

  iVar5 = iVar5 >> 1;

  iVar1 = FUN_007703d0();

  if (iVar1 == 0) {

    iVar1 = FUN_007703d0();

    if (iVar1 == 0) {

      iVar1 = FUN_007703d0();

      if (iVar1 == 0) {

        iVar1 = FUN_007703d0();

        if (iVar1 == 0) {

          iVar1 = FUN_007703d0();

          if (iVar1 == 0) {

            iVar1 = FUN_007703d0();

            if (iVar1 == 0) {

              iVar1 = FUN_007703d0();

              if (iVar1 == 0) {

                local_30[0] = *param_1 - iVar5;

                local_20[0] = *in_EAX - iVar5;

                puVar4 = (uint32_t /* width from decompiler */ *)param_1[3];

                puVar2 = (uint32_t /* width from decompiler */ *)in_EAX[3];

                local_74 = iVar5;

                if (0 < iVar5) {

                  do {

                    *local_54 = *puVar2;

                    *local_44 = *puVar4;

                    local_54 = local_54 + 1;

                    puVar2 = puVar2 + 1;

                    local_44 = local_44 + 1;

                    puVar4 = puVar4 + 1;

                    local_74 = local_74 + -1;

                  } while (local_74 != 0);

                }

                iVar1 = iVar5;

                if (iVar5 < *in_EAX) {

                  do {

                    *local_14 = *puVar2;

                    iVar1 = iVar1 + 1;

                    local_14 = local_14 + 1;

                    puVar2 = puVar2 + 1;

                  } while (iVar1 < *in_EAX);

                }

                iVar1 = iVar5;

                if (iVar5 < *param_1) {

                  do {

                    *local_24 = *puVar4;

                    iVar1 = iVar1 + 1;

                    local_24 = local_24 + 1;

                    puVar4 = puVar4 + 1;

                  } while (iVar1 < *param_1);

                }

                local_60[0] = iVar5;

                local_50 = iVar5;

                FUN_00770820();

                uVar3 = FUN_00770820();

                iVar5 = FUN_00774e60(local_60,uVar3,local_10);

                if ((iVar5 == 0) && (iVar5 = FUN_00774e60(local_20,local_30,local_40), iVar5 == 0))

                {

                  iVar5 = FUN_007716f0(local_20);

                  if ((((iVar5 == 0) &&

                       ((((iVar5 = FUN_007716f0(local_30), iVar5 == 0 &&

                          (iVar5 = FUN_00774e60(local_70,local_60,local_70), iVar5 == 0)) &&

                         (iVar5 = FUN_00772390(), iVar5 == 0)) &&

                        ((iVar5 = FUN_007716f0(local_60), iVar5 == 0 &&

                         (iVar5 = FUN_00771c00(), iVar5 == 0)))))) &&

                      (iVar5 = FUN_00771c00(), iVar5 == 0)) &&

                     ((iVar5 = FUN_00772390(), iVar5 == 0 && (iVar5 = FUN_00772390(), iVar5 == 0))))

                  {

                    local_78 = 0;

                  }

                }

                FUN_007707d0();

              }

              FUN_007707d0();

            }

            FUN_007707d0();

          }

          FUN_007707d0();

        }

        FUN_007707d0();

      }

      FUN_007707d0();

    }

    FUN_007707d0();

  }

  return local_78;

}
