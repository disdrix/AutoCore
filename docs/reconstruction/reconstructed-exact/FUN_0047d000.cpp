// =============================================================================
// FUN_0047d000
// -----------------------------------------------------------------------------
// Stable ID: aa_0047d000
// Address:   0x0047d000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047d000 @ 0x0047d000
// Stable ID: aa_0047d000
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~225 non-empty decompiler lines.
//  - Control keywords: if×22, do×8, while×8, for×4, return×2.
//  - Notable callees: FUN_0047d000.
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

void FUN_0047d000(void)



{

  uint *puVar1;

  byte bVar2;

  int iVar3;

  int in_EAX;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint *puVar8;

  uint *puVar9;

  uint uVar10;

  uint *puVar11;

  uint uVar12;

  uint *puVar13;

  byte *pbVar14;

  uint local_1c;

  byte *local_18;

  uint local_14;

  uint local_10;

  uint local_c;

  uint local_8 [2];

  

  iVar4 = *(int *)(in_EAX + 0xec) + 1;

  uVar6 = *(uint *)(in_EAX + 0x70);

  puVar1 = (uint *)(in_EAX + 0x100);

  if ((iVar4 != 0) && (puVar1 != (uint *)0x0)) {

    iVar3 = *(int *)(&DAT_00a2665c + (uint)*(byte *)(in_EAX + 0x124) * 4);

    uVar5 = *puVar1;

    bVar2 = *(byte *)(in_EAX + 0x10b);

    uVar7 = uVar5 * iVar3;

    if (bVar2 == 1) {

      local_18 = (byte *)((uVar5 - 1 >> 3) + iVar4);

      pbVar14 = (byte *)((uVar7 - 1 >> 3) + iVar4);

      if ((uVar6 & 0x10000) == 0) {

        uVar6 = 7 - (uVar5 - 1 & 7);

        uVar12 = 7 - (uVar7 - 1 & 7);

        local_14 = 0;

        uVar10 = 7;

        local_10 = 1;

      }

      else {

        uVar6 = uVar5 - 1 & 7;

        uVar12 = uVar7 - 1 & 7;

        local_14 = 7;

        uVar10 = 0;

        local_10 = -1;

      }

      local_8[0] = 0;

      if (uVar5 != 0) {

        do {

          bVar2 = *local_18;

          local_c = iVar3;

          if (0 < iVar3) {

            do {

              *pbVar14 = (byte)(0x7f7f >> (7 - (byte)uVar12 & 0x1f)) & *pbVar14 |

                         (bVar2 >> ((byte)uVar6 & 0x1f) & 1) << ((byte)uVar12 & 0x1f);

              if (uVar12 == uVar10) {

                pbVar14 = pbVar14 + -1;

                uVar12 = local_14;

              }

              else {

                uVar12 = uVar12 + local_10;

              }

              local_c = local_c + -1;

            } while (local_c != 0);

          }

          if (uVar6 == uVar10) {

            local_18 = local_18 + -1;

            uVar6 = local_14;

          }

          else {

            uVar6 = uVar6 + local_10;

          }

          local_8[0] = local_8[0] + 1;

        } while (local_8[0] < *puVar1);

      }

    }

    else if (bVar2 == 2) {

      local_18 = (byte *)((uVar5 - 1 >> 2) + iVar4);

      pbVar14 = (byte *)((uVar7 - 1 >> 2) + iVar4);

      if ((uVar6 & 0x10000) == 0) {

        uVar6 = (3 - (uVar5 - 1 & 3)) * 2;

        uVar12 = (3 - (uVar7 - 1 & 3)) * 2;

        local_14 = 0;

        uVar10 = 6;

        local_1c = 2;

      }

      else {

        uVar6 = uVar5 * 2 - 1 & 6;

        uVar12 = uVar7 * 2 - 1 & 6;

        local_14 = 6;

        uVar10 = 0;

        local_1c = -2;

      }

      local_10 = 0;

      if (uVar5 != 0) {

        do {

          bVar2 = *local_18;

          local_c = iVar3;

          if (0 < iVar3) {

            do {

              *pbVar14 = (byte)(0x3f3f >> (6 - (byte)uVar12 & 0x1f)) & *pbVar14 |

                         (bVar2 >> ((byte)uVar6 & 0x1f) & 3) << ((byte)uVar12 & 0x1f);

              if (uVar12 == uVar10) {

                pbVar14 = pbVar14 + -1;

                uVar12 = local_14;

              }

              else {

                uVar12 = uVar12 + local_1c;

              }

              local_c = local_c + -1;

            } while (local_c != 0);

          }

          if (uVar6 == uVar10) {

            local_18 = local_18 + -1;

            uVar6 = local_14;

          }

          else {

            uVar6 = uVar6 + local_1c;

          }

          local_10 = local_10 + 1;

        } while (local_10 < *puVar1);

      }

    }

    else if (bVar2 == 4) {

      local_18 = (byte *)((uVar5 - 1 >> 1) + iVar4);

      pbVar14 = (byte *)((uVar7 - 1 >> 1) + iVar4);

      if ((uVar6 & 0x10000) == 0) {

        uVar6 = (uVar5 - 1 & 1) * -4 + 4;

        uVar10 = 4;

        uVar12 = (uVar7 - 1 & 1) * -4 + 4;

        local_1c = 0;

        local_14 = 4;

      }

      else {

        uVar6 = uVar5 * -4 - 1 & 4;

        uVar12 = uVar7 * -4 - 1 & 4;

        local_1c = 4;

        uVar10 = 0;

        local_14 = -4;

      }

      local_c = 0;

      if (uVar5 != 0) {

        do {

          bVar2 = *local_18;

          local_10 = iVar3;

          if (0 < iVar3) {

            do {

              *pbVar14 = (byte)(0xf0f >> (4 - (byte)uVar12 & 0x1f)) & *pbVar14 |

                         (bVar2 >> ((byte)uVar6 & 0x1f) & 0xf) << ((byte)uVar12 & 0x1f);

              if (uVar12 == uVar10) {

                pbVar14 = pbVar14 + -1;

                uVar12 = local_1c;

              }

              else {

                uVar12 = uVar12 + local_14;

              }

              local_10 = local_10 + -1;

            } while (local_10 != 0);

          }

          if (uVar6 == uVar10) {

            local_18 = local_18 + -1;

            uVar6 = local_1c;

          }

          else {

            uVar6 = uVar6 + local_14;

          }

          local_c = local_c + 1;

        } while (local_c < *puVar1);

      }

    }

    else {

      uVar6 = (uint)(bVar2 >> 3);

      puVar9 = (uint *)((uVar5 - 1) * uVar6 + iVar4);

      puVar8 = (uint *)((uVar7 - 1) * uVar6 + iVar4);

      local_14 = 0;

      if (uVar5 != 0) {

        do {

          puVar11 = puVar9;

          puVar13 = local_8;

          for (uVar5 = (uint)(bVar2 >> 5); uVar5 != 0; uVar5 = uVar5 - 1) {

            *puVar13 = *puVar11;

            puVar11 = puVar11 + 1;

            puVar13 = puVar13 + 1;

          }

          for (uVar5 = uVar6 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

            *(char *)puVar13 = (char)*puVar11;

            puVar11 = (uint *)((int)puVar11 + 1);

            puVar13 = (uint *)((int)puVar13 + 1);

          }

          local_10 = iVar3;

          if (0 < iVar3) {

            do {

              puVar11 = local_8;

              puVar13 = puVar8;

              for (uVar5 = (uint)(bVar2 >> 5); uVar5 != 0; uVar5 = uVar5 - 1) {

                *puVar13 = *puVar11;

                puVar11 = puVar11 + 1;

                puVar13 = puVar13 + 1;

              }

              puVar8 = (uint *)((int)puVar8 - uVar6);

              local_10 = local_10 + -1;

              for (uVar5 = uVar6 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

                *(char *)puVar13 = (char)*puVar11;

                puVar11 = (uint *)((int)puVar11 + 1);

                puVar13 = (uint *)((int)puVar13 + 1);

              }

            } while (local_10 != 0);

          }

          local_14 = local_14 + 1;

          puVar9 = (uint *)((int)puVar9 - uVar6);

        } while (local_14 < *puVar1);

      }

    }

    bVar2 = *(byte *)(in_EAX + 0x10b);

    *puVar1 = uVar7;

    if (7 < bVar2) {

      *(uint *)(in_EAX + 0x104) = (bVar2 >> 3) * uVar7;

      return;

    }

    *(uint *)(in_EAX + 0x104) = bVar2 * uVar7 + 7 >> 3;

  }

  return;

}
