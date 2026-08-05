// =============================================================================
// FUN_00780c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00780c90
// Address:   0x00780c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00780c90 @ 0x00780c90
// Stable ID: aa_00780c90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, while×2, return×2, do×1.
//  - Notable callees: FUN_00780b70, FUN_00780c90.
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

void FUN_00780c90(void)



{

  void *pvVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  

  iVar3 = *(int *)(in_EAX + 0x120);

  while( true ) {

    if (iVar3 == 0) {

      iVar3 = 0;

      do {

        if (*(int *)(iVar3 + 0x34 + *(int *)(in_EAX + 0x220)) < *(int *)(in_EAX + 0x210)) {

          FUN_00780b70();

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10 + *(int *)(in_EAX + 0x220)) = 0;

          iVar2 = *(int *)(in_EAX + 0x220) + iVar3;

          if (*(int *)(*(int *)(in_EAX + 0x220) + 0x34 + iVar3) < *(int *)(in_EAX + 0x20c)) {

            *(uint32_t /* width from decompiler */ *)(iVar2 + 8) = 0;

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

            *(int *)(in_EAX + 0x20c) = *(int *)(in_EAX + 0x20c) + -1;

            if (*(int *)(iVar2 + 0x34) != *(int *)(in_EAX + 0x20c)) {

              *(int *)(*(int *)(*(int *)(in_EAX + 0x208) + *(int *)(in_EAX + 0x20c) * 4) + 0x34) =

                   *(int *)(iVar2 + 0x34);

              *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x208) + *(int *)(iVar2 + 0x34) * 4) =

                   *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x208) + *(int *)(in_EAX + 0x20c) * 4);

              *(int *)(*(int *)(in_EAX + 0x208) + *(int *)(in_EAX + 0x20c) * 4) = iVar2;

              *(uint32_t /* width from decompiler */ *)(iVar2 + 0x34) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20c);

            }

          }

          *(int *)(in_EAX + 0x210) = *(int *)(in_EAX + 0x210) + -1;

          if (*(int *)(iVar2 + 0x34) != *(int *)(in_EAX + 0x210)) {

            *(int *)(*(int *)(*(int *)(in_EAX + 0x208) + *(int *)(in_EAX + 0x210) * 4) + 0x34) =

                 *(int *)(iVar2 + 0x34);

            *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x208) + *(int *)(iVar2 + 0x34) * 4) =

                 *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x208) + *(int *)(in_EAX + 0x210) * 4);

            *(int *)(*(int *)(in_EAX + 0x208) + *(int *)(in_EAX + 0x210) * 4) = iVar2;

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x34) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x210);

          }

        }

        iVar3 = iVar3 + 0x38;

      } while (iVar3 < 0xe000);

      return;

    }

    pvVar1 = *(void **)(iVar3 + 0x18);

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x18) = 0;

    if (pvVar1 != (void *)0x0) break;

    iVar3 = *(int *)(iVar3 + 0x10);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
