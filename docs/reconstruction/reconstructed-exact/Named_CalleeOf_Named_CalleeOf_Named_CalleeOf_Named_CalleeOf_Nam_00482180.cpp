// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00482180
// -----------------------------------------------------------------------------
// Stable ID: aa_00482180
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
// Address:   0x00482180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: if×17, goto×6, return×3, while×2.
//  - Notable callees: FUN_004820a0×2, FUN_00482180.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint8_t Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00482180(void)



{

  int *piVar1;

  byte bVar2;

  uint uVar3;

  int *in_EAX;

  uint uVar4;

  uint8_t local_1;

  

  local_1 = 0;

  if (in_EAX[1] == 2) {

    if (in_EAX[0x11] < in_EAX[0x12]) {

      while (((uint32_t /* width from decompiler */ *)*in_EAX)[1] != 0) {

        uVar4 = (uint)**(byte **)*in_EAX;

        uVar3 = in_EAX[0xd];

        if (uVar4 == uVar3) {

LAB_0048220f:

          if (in_EAX[0xe] == 0xff) {

LAB_00482222:

            if (uVar3 < 0x100) {

              in_EAX = (int *)FUN_004820a0();

            }

            in_EAX[0xe] = 1;

            goto LAB_00482232;

          }

          in_EAX[0xe] = in_EAX[0xe] + 1;

        }

        else {

          if (in_EAX[0xe] != 1) {

            if (uVar4 == uVar3) goto LAB_0048220f;

            goto LAB_00482222;

          }

          bVar2 = *(byte *)(in_EAX + 0xd);

          in_EAX[0x98] = in_EAX[0x98] << 8 ^

                         *(uint *)(&DAT_00afd5e8 + ((uint)in_EAX[0x98] >> 0x18 ^ (uint)bVar2) * 4);

          *(uint8_t *)(uVar3 + 0x58 + (int)in_EAX) = 1;

          *(byte *)(in_EAX[9] + in_EAX[0x11]) = bVar2;

          in_EAX[0x11] = in_EAX[0x11] + 1;

LAB_00482232:

          in_EAX[0xd] = uVar4;

        }

        *(int *)*in_EAX = *(int *)*in_EAX + 1;

        *(int *)(*in_EAX + 4) = *(int *)(*in_EAX + 4) + -1;

        *(int *)(*in_EAX + 8) = *(int *)(*in_EAX + 8) + 1;

        if (*(int *)(*in_EAX + 8) == 0) {

          piVar1 = (int *)(*in_EAX + 0xc);

          *piVar1 = *piVar1 + 1;

        }

        local_1 = 1;

        if (in_EAX[0x12] <= in_EAX[0x11]) {

          return 1;

        }

      }

    }

  }

  else if (in_EAX[0x11] < in_EAX[0x12]) {

    while ((((uint32_t /* width from decompiler */ *)*in_EAX)[1] != 0 && (in_EAX[3] != 0))) {

      uVar4 = (uint)**(byte **)*in_EAX;

      uVar3 = in_EAX[0xd];

      if (uVar4 == uVar3) {

LAB_004822ec:

        if (in_EAX[0xe] == 0xff) {

LAB_004822ff:

          if (uVar3 < 0x100) {

            in_EAX = (int *)FUN_004820a0();

          }

          in_EAX[0xe] = 1;

          goto LAB_0048230f;

        }

        in_EAX[0xe] = in_EAX[0xe] + 1;

      }

      else {

        if (in_EAX[0xe] != 1) {

          if (uVar4 == uVar3) goto LAB_004822ec;

          goto LAB_004822ff;

        }

        bVar2 = *(byte *)(in_EAX + 0xd);

        in_EAX[0x98] = in_EAX[0x98] << 8 ^

                       *(uint *)(&DAT_00afd5e8 + ((uint)in_EAX[0x98] >> 0x18 ^ (uint)bVar2) * 4);

        *(uint8_t *)(uVar3 + 0x58 + (int)in_EAX) = 1;

        *(byte *)(in_EAX[9] + in_EAX[0x11]) = bVar2;

        in_EAX[0x11] = in_EAX[0x11] + 1;

LAB_0048230f:

        in_EAX[0xd] = uVar4;

      }

      *(int *)*in_EAX = *(int *)*in_EAX + 1;

      *(int *)(*in_EAX + 4) = *(int *)(*in_EAX + 4) + -1;

      *(int *)(*in_EAX + 8) = *(int *)(*in_EAX + 8) + 1;

      if (*(int *)(*in_EAX + 8) == 0) {

        piVar1 = (int *)(*in_EAX + 0xc);

        *piVar1 = *piVar1 + 1;

      }

      in_EAX[3] = in_EAX[3] + -1;

      local_1 = 1;

      if (in_EAX[0x12] <= in_EAX[0x11]) {

        return 1;

      }

    }

  }

  return local_1;

}
