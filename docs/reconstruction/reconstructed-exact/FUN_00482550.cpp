// =============================================================================
// FUN_00482550
// -----------------------------------------------------------------------------
// Stable ID: aa_00482550
// Address:   0x00482550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00482550 @ 0x00482550
// Stable ID: aa_00482550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~232 non-empty decompiler lines.
//  - Control keywords: if×29, goto×5, while×2, return×2.
//  - Notable callees: FUN_00482550.
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

void FUN_00482550(void)



{

  int *piVar1;

  int iVar2;

  int *in_EAX;

  int iVar3;

  uint uVar4;

  byte bVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  int iVar11;

  int iVar12;

  uint local_20;

  uint local_18;

  int local_14;

  byte *local_10;

  

  if ((char)in_EAX[4] == '\0') {

    local_10 = *(byte **)(*in_EAX + 0x10);

    local_18 = in_EAX[0x318];

    iVar11 = in_EAX[3];

    iVar6 = in_EAX[0x110];

    iVar2 = *(int *)(*in_EAX + 0x14);

    iVar3 = in_EAX[0x313];

    iVar7 = in_EAX[0x3e90] + 1;

    uVar4 = in_EAX[0xe];

    uVar8 = local_18;

    bVar5 = *(byte *)(in_EAX + 2);

    uVar9 = in_EAX[0xf];

    local_14 = iVar2;

LAB_00482840:

    local_20 = uVar9;

    iVar12 = iVar6;

    if (iVar11 < 1) goto LAB_00482885;

    while( true ) {

      if (local_14 == 0) goto LAB_004829a9;

      uVar9 = local_20;

      if (iVar11 == 1) break;

      *local_10 = bVar5;

      uVar8 = local_18 << 8 ^ *(uint *)(&DAT_00afd5e8 + (uVar8 >> 0x18 ^ (uint)bVar5) * 4);

      iVar11 = iVar11 + -1;

      local_14 = local_14 + -1;

      local_18 = uVar8;

      local_10 = local_10 + 1;

    }

LAB_004828c3:

    local_20 = uVar9;

    if (local_14 == 0) {

      iVar11 = 1;

      goto LAB_004829a9;

    }

    *local_10 = bVar5;

    uVar8 = uVar8 << 8 ^ *(uint *)(&DAT_00afd5e8 + (uVar8 >> 0x18 ^ (uint)bVar5) * 4);

    local_10 = local_10 + 1;

    local_14 = local_14 + -1;

    iVar12 = iVar6;

    local_18 = uVar8;

LAB_00482885:

    if (iVar12 != iVar7) {

      uVar4 = *(uint *)(iVar3 + uVar4 * 4);

      uVar9 = uVar4 & 0xff;

      uVar4 = uVar4 >> 8;

      iVar6 = iVar12 + 1;

      bVar5 = (byte)local_20;

      if ((uVar9 != local_20) || (uVar9 = local_20, iVar6 == iVar7)) goto LAB_004828c3;

      uVar10 = *(uint *)(iVar3 + uVar4 * 4);

      iVar6 = iVar12 + 2;

      uVar4 = uVar10 >> 8;

      iVar11 = 2;

      if ((iVar6 != iVar7) && (uVar9 = uVar10 & 0xff, uVar8 = local_18, uVar9 == local_20)) {

        uVar4 = *(uint *)(iVar3 + uVar4 * 4);

        uVar10 = uVar4 & 0xff;

        iVar6 = iVar12 + 3;

        uVar4 = uVar4 >> 8;

        iVar11 = 3;

        uVar9 = local_20;

        if ((iVar6 != iVar7) && (uVar9 = uVar10, uVar10 == local_20)) {

          uVar4 = *(uint *)(iVar3 + uVar4 * 4);

          uVar9 = *(uint *)(iVar3 + (uVar4 >> 8) * 4);

          iVar11 = (uVar4 & 0xff) + 4;

          uVar4 = uVar9 >> 8;

          iVar6 = iVar12 + 5;

          uVar9 = uVar9 & 0xff;

        }

      }

      goto LAB_00482840;

    }

    iVar11 = 0;

    iVar6 = iVar12;

LAB_004829a9:

    uVar8 = *(uint *)(*in_EAX + 0x18);

    *(uint *)(*in_EAX + 0x18) = (uVar8 - local_14) + iVar2;

    if (*(uint *)(*in_EAX + 0x18) < uVar8) {

      piVar1 = (int *)(*in_EAX + 0x1c);

      *piVar1 = *piVar1 + 1;

    }

    *(byte *)(in_EAX + 2) = bVar5;

    in_EAX[0xf] = local_20;

    in_EAX[0xe] = uVar4;

    in_EAX[0x313] = iVar3;

    in_EAX[0x318] = local_18;

    in_EAX[3] = iVar11;

    in_EAX[0x110] = iVar6;

    *(byte **)(*in_EAX + 0x10) = local_10;

    *(int *)(*in_EAX + 0x14) = local_14;

  }

  else {

    while (*(int *)(*in_EAX + 0x14) != 0) {

      if (in_EAX[3] == 0) {

        iVar11 = in_EAX[0x110];

        iVar6 = in_EAX[0x3e90] + 1;

        if (iVar11 == iVar6) {

          return;

        }

        iVar2 = in_EAX[0x313];

        *(char *)(in_EAX + 2) = (char)in_EAX[0xf];

        in_EAX[3] = 1;

        uVar4 = *(uint *)(iVar2 + in_EAX[0xe] * 4);

        in_EAX[0xe] = uVar4;

        in_EAX[0xe] = uVar4 >> 8;

        if (in_EAX[5] == 0) {

          iVar3 = in_EAX[6] + 1;

          in_EAX[5] = *(int *)(&DAT_00afcde8 + in_EAX[6] * 4);

          in_EAX[6] = iVar3;

          if (iVar3 == 0x200) {

            in_EAX[6] = 0;

          }

        }

        in_EAX[5] = in_EAX[5] + -1;

        in_EAX[0x110] = iVar11 + 1;

        if (iVar11 + 1 != iVar6) {

          uVar4 = (uint)(byte)((byte)uVar4 ^ in_EAX[5] == 1);

          if (uVar4 == in_EAX[0xf]) {

            in_EAX[3] = 2;

            uVar4 = *(uint *)(iVar2 + in_EAX[0xe] * 4);

            in_EAX[0xe] = uVar4;

            in_EAX[0xe] = uVar4 >> 8;

            if (in_EAX[5] == 0) {

              iVar3 = in_EAX[6] + 1;

              in_EAX[5] = *(int *)(&DAT_00afcde8 + in_EAX[6] * 4);

              in_EAX[6] = iVar3;

              if (iVar3 == 0x200) {

                in_EAX[6] = 0;

              }

            }

            in_EAX[5] = in_EAX[5] + -1;

            in_EAX[0x110] = iVar11 + 2;

            if (iVar11 + 2 != iVar6) {

              uVar4 = (uint)(byte)((byte)uVar4 ^ in_EAX[5] == 1);

              if (uVar4 == in_EAX[0xf]) {

                in_EAX[3] = 3;

                uVar4 = *(uint *)(iVar2 + in_EAX[0xe] * 4);

                in_EAX[0xe] = uVar4;

                in_EAX[0xe] = uVar4 >> 8;

                if (in_EAX[5] == 0) {

                  iVar3 = in_EAX[6] + 1;

                  in_EAX[5] = *(int *)(&DAT_00afcde8 + in_EAX[6] * 4);

                  in_EAX[6] = iVar3;

                  if (iVar3 == 0x200) {

                    in_EAX[6] = 0;

                  }

                }

                in_EAX[5] = in_EAX[5] + -1;

                in_EAX[0x110] = iVar11 + 3;

                if (iVar11 + 3 != iVar6) {

                  uVar4 = (uint)(byte)((byte)uVar4 ^ in_EAX[5] == 1);

                  if (uVar4 == in_EAX[0xf]) {

                    uVar4 = *(uint *)(iVar2 + in_EAX[0xe] * 4);

                    in_EAX[0xe] = uVar4;

                    in_EAX[0xe] = uVar4 >> 8;

                    if (in_EAX[5] == 0) {

                      iVar6 = in_EAX[6] + 1;

                      in_EAX[5] = *(int *)(&DAT_00afcde8 + in_EAX[6] * 4);

                      in_EAX[6] = iVar6;

                      if (iVar6 == 0x200) {

                        in_EAX[6] = 0;

                      }

                    }

                    in_EAX[5] = in_EAX[5] + -1;

                    in_EAX[0x110] = iVar11 + 4;

                    in_EAX[3] = ((uint)(in_EAX[5] == 1) ^ uVar4 & 0xff) + 4;

                    uVar4 = *(uint *)(iVar2 + in_EAX[0xe] * 4);

                    in_EAX[0xe] = uVar4;

                    in_EAX[0xe] = (uint)in_EAX[0xe] >> 8;

                    in_EAX[0xf] = uVar4 & 0xff;

                    if (in_EAX[5] == 0) {

                      iVar6 = in_EAX[6] + 1;

                      in_EAX[5] = *(int *)(&DAT_00afcde8 + in_EAX[6] * 4);

                      in_EAX[6] = iVar6;

                      if (iVar6 == 0x200) {

                        in_EAX[6] = 0;

                      }

                    }

                    in_EAX[5] = in_EAX[5] + -1;

                    in_EAX[0xf] = in_EAX[0xf] ^ (uint)(in_EAX[5] == 1);

                    in_EAX[0x110] = iVar11 + 5;

                  }

                  else {

                    in_EAX[0xf] = uVar4;

                  }

                }

              }

              else {

                in_EAX[0xf] = uVar4;

              }

            }

          }

          else {

            in_EAX[0xf] = uVar4;

          }

        }

      }

      else {

        **(uint8_t **)(*in_EAX + 0x10) = (char)in_EAX[2];

        uVar4 = *(uint *)(&DAT_00afd5e8 +

                         ((uint)in_EAX[0x318] >> 0x18 ^ (uint)*(byte *)(in_EAX + 2)) * 4);

        in_EAX[3] = in_EAX[3] + -1;

        in_EAX[0x318] = in_EAX[0x318] << 8 ^ uVar4;

        *(int *)(*in_EAX + 0x10) = *(int *)(*in_EAX + 0x10) + 1;

        *(int *)(*in_EAX + 0x14) = *(int *)(*in_EAX + 0x14) + -1;

        *(int *)(*in_EAX + 0x18) = *(int *)(*in_EAX + 0x18) + 1;

        if (*(int *)(*in_EAX + 0x18) == 0) {

          piVar1 = (int *)(*in_EAX + 0x1c);

          *piVar1 = *piVar1 + 1;

        }

      }

    }

  }

  return;

}
