// =============================================================================
// FUN_004d7230
// -----------------------------------------------------------------------------
// Stable ID: aa_004d7230
// Address:   0x004d7230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d7230 @ 0x004d7230
// Stable ID: aa_004d7230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, return×1.
//  - Notable callees: FUN_004eb010×4, FUN_004f1e20×4, FUN_004f26e0×4, FUN_00404d70×3, FUN_0040b330, FUN_004d7230.
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

void FUN_004d7230(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int *in_EAX;

  int iVar2;

  int iVar3;

  char *pcVar4;

  int iStack_18;

  int iStack_14;

  uint32_t /* width from decompiler */ auStack_10 [4];

  

  if ((in_EAX != (int *)0x0) && (in_EAX[0x2a] != 0)) {

    uVar1 = *(uint32_t /* width from decompiler */ *)(DAT_00d1f050 + 100);

    if (((uint)in_EAX[0x5f] >> 6 & 1) != 0) {

      FUN_004f1e20(1,1);

      FUN_004f26e0(uVar1);

      FUN_004eb010();

    }

    iVar2 = (**(code **)(*in_EAX + 0x1ec))();

    if (iVar2 != 0) {

      pcVar4 = (char *)(iVar2 + 0xf5);

      iStack_18 = 0xc;

      do {

        iVar2 = *(int *)(pcVar4 + -5);

        if (iVar2 != -1) {

          if (*pcVar4 == '\0') {

            iVar2 = FUN_00404d70(iVar2);

            if (iVar2 != 0) {

              FUN_004f1e20(1,1);

              FUN_004f26e0(uVar1);

              FUN_004eb010();

            }

          }

          else {

            iStack_14 = iVar2;

            iVar2 = FUN_0040b330(&iStack_14);

            iVar3 = FUN_00404d70(*(uint32_t /* width from decompiler */ *)(iVar2 + 4));

            if (iVar3 != 0) {

              FUN_004f1e20(1,1);

              FUN_004f26e0(uVar1);

              auStack_10[0] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc);

              auStack_10[1] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x10);

              auStack_10[2] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x14);

              auStack_10[3] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x18);

              iVar2 = 3;

              do {

                iVar3 = FUN_00404d70(auStack_10[iVar2]);

                if (iVar3 != 0) {

                  FUN_004f1e20(1,1);

                  FUN_004f26e0(uVar1);

                  FUN_004eb010();

                }

                iVar2 = iVar2 + -1;

              } while (-1 < iVar2);

              FUN_004eb010();

            }

          }

        }

        pcVar4 = pcVar4 + 0xc;

        iStack_18 = iStack_18 + -1;

      } while (iStack_18 != 0);

    }

  }

  return;

}
