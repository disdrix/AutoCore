// =============================================================================
// FUN_008fd1e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008fd1e0
// Address:   0x008fd1e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008fd1e0 @ 0x008fd1e0
// Stable ID: aa_008fd1e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×7, for×4, do×2, while×2, return×2.
//  - Notable callees: CONCAT31, FUN_008fd1e0.
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

uint FUN_008fd1e0(void)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar7;

  int local_128;

  uint local_124;

  int local_120;

  uint32_t /* width from decompiler */ local_118 [2];

  byte local_110;

  byte local_10f;

  

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x50c) = 0;

  if (*(void **)(unaff_EBX + 0x5fc) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_EBX + 0x5fc));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x5fc) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x530) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x534) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x538) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x53c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x540) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x544) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x548) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x54c) = 0xffffffff;

  if ((DAT_00d1b6d8 != 0) && (iVar1 = *(int *)(DAT_00d1b6d8 + 0x250), iVar1 != 0)) {

    uVar2 = (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) +

                                    0x3c) + 0x716);

    *(uint *)(unaff_EBX + 0x50c) = uVar2;

    puVar3 = operator_new__(uVar2 * 0x110);

    *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x5fc) = puVar3;

    for (uVar2 = (uint)(*(int *)(unaff_EBX + 0x50c) * 0x110) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {

      *(uint8_t *)puVar3 = 0;

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x550) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x28c);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x530) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x28c);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x554) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x290);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x534) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x290);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x558) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x294);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x538) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x294);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x55c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x298);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x53c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x298);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x560) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x29c);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x540) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x29c);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x564) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x2a0);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x544) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x2a0);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x568) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x2a4);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x548) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x2a4);

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x56c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x2a8);

    iVar5 = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x54c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x2a8);

    local_128 = 0;

    local_124 = 0;

    do {

      iVar6 = 0;

      local_120 = 0;

      if (0 < *(int *)(unaff_EBX + 0x50c)) {

        iVar4 = iVar5 * 0x110;

        do {

          puVar3 = (uint32_t /* width from decompiler */ *)

                   (iVar6 + *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac +

                                                      iVar1) + 0x3c) + 0x720));

          puVar7 = local_118;

          for (iVar5 = 0x44; iVar5 != 0; iVar5 = iVar5 + -1) {

            *puVar7 = *puVar3;

            puVar3 = puVar3 + 1;

            puVar7 = puVar7 + 1;

          }

          if (local_110 == local_124) {

            if (local_10f < 0x24) {

              if (local_110 == local_124) {

                local_128 = local_128 + 1;

                puVar3 = local_118;

                puVar7 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_EBX + 0x5fc) + iVar4);

                for (iVar5 = 0x44; iVar5 != 0; iVar5 = iVar5 + -1) {

                  *puVar7 = *puVar3;

                  puVar3 = puVar3 + 1;

                  puVar7 = puVar7 + 1;

                }

                iVar4 = iVar4 + 0x110;

              }

            }

            else {

              *(int *)(unaff_EBX + 0x50c) = *(int *)(unaff_EBX + 0x50c) + -1;

            }

          }

          local_120 = local_120 + 1;

          iVar6 = iVar6 + 0x110;

          iVar5 = local_128;

        } while (local_120 < *(int *)(unaff_EBX + 0x50c));

      }

      local_124 = local_124 + 1;

    } while ((int)local_124 < 8);

    if (iVar5 < *(int *)(unaff_EBX + 0x50c)) {

      *(int *)(unaff_EBX + 0x50c) = iVar5;

    }

    return CONCAT31((int3)(local_124 >> 8),*(uint8_t *)(unaff_EBX + 0x50c));

  }

  return DAT_00d1b6d8 & 0xffffff00;

}
