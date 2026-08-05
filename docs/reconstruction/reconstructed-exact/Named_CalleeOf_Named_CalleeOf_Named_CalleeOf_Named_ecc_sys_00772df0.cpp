// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00772df0
// -----------------------------------------------------------------------------
// Stable ID: aa_00772df0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
// Address:   0x00772df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×10, do×2, while×2, return×1.
//  - Notable callees: FUN_007703d0×6, FUN_007707d0×6, FUN_00774b50×3, FUN_007716f0×2, FUN_00771c00×2, FUN_00772390×2, FUN_00770820, FUN_007714a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00772df0(void)



{

  int *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ local_68;

  uint8_t local_60 [16];

  int local_50;

  uint32_t /* width from decompiler */ *local_44;

  uint8_t local_40 [16];

  int local_30 [3];

  uint32_t /* width from decompiler */ *local_24;

  uint8_t local_20 [16];

  uint8_t local_10 [16];

  

  iVar4 = *in_EAX >> 1;

  uVar3 = 0xfffffffe;

  local_68 = 0xfffffffe;

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

              puVar2 = (uint32_t /* width from decompiler */ *)in_EAX[3];

              iVar1 = iVar4;

              if (0 < iVar4) {

                do {

                  *local_44 = *puVar2;

                  local_44 = local_44 + 1;

                  puVar2 = puVar2 + 1;

                  iVar1 = iVar1 + -1;

                } while (iVar1 != 0);

              }

              iVar1 = iVar4;

              if (iVar4 < *in_EAX) {

                do {

                  *local_24 = *puVar2;

                  iVar1 = iVar1 + 1;

                  local_24 = local_24 + 1;

                  puVar2 = puVar2 + 1;

                } while (iVar1 < *in_EAX);

              }

              local_30[0] = *in_EAX - iVar4;

              local_50 = iVar4;

              uVar3 = FUN_00770820();

              iVar1 = FUN_00774b50(uVar3,local_20);

              if ((iVar1 == 0) && (iVar1 = FUN_00774b50(local_30,local_40), iVar1 == 0)) {

                iVar1 = FUN_007716f0(local_30);

                if ((((iVar1 == 0) &&

                     (((iVar1 = FUN_00774b50(local_60,local_60), iVar1 == 0 &&

                       (iVar1 = FUN_007714a0(local_20), iVar1 == 0)) &&

                      (iVar1 = FUN_007716f0(local_10), iVar1 == 0)))) &&

                    (((iVar1 = FUN_00771c00(), iVar1 == 0 && (iVar1 = FUN_00771c00(), iVar1 == 0))

                     && (iVar1 = FUN_00772390(), iVar1 == 0)))) &&

                   (iVar1 = FUN_00772390(), iVar1 == 0)) {

                  local_68 = 0;

                }

              }

              FUN_007707d0();

              uVar3 = local_68;

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

  return uVar3;

}
