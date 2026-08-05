// =============================================================================
// FUN_008fe4e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008fe4e0
// Address:   0x008fe4e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008fe4e0 @ 0x008fe4e0
// Stable ID: aa_008fe4e0
// Embedded strings (evidence for future rename):
//   - "i_d_body_2d_btn_uninstall"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_008fc650, FUN_008fdb60, FUN_008fe4e0.
//  - Strings: "i_d_body_2d_btn_uninstall".
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

void FUN_008fe4e0(void)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  char *pcVar4;

  

  if ((((DAT_00d1b6d8 != 0) && (*(int *)(in_EAX + 0x72c) != 0)) && (*(int *)(in_EAX + 0x73c) != 0))

     && (*(int *)(in_EAX + 0x600) != 0)) {

    iVar3 = 0;

    if (0 < *(int *)(in_EAX + 0x51c)) {

      do {

        iVar1 = *(int *)(in_EAX + 0x524) + iVar3;

        if (iVar1 < *(int *)(in_EAX + 0x514)) {

          if (*(int *)(*(int *)(in_EAX + 0x600) + iVar1 * 4) != 0) {

            iVar1 = **(int **)(*(int *)(in_EAX + 0x72c) + iVar3 * 4);

            uVar2 = (**(code **)(**(int **)(*(int *)(in_EAX + 0x72c) + iVar3 * 4) + 0x2c8))(0);

            (**(code **)(iVar1 + 0x50))

                      (*(uint32_t /* width from decompiler */ *)

                        (*(int *)(in_EAX + 0x600) + (*(int *)(in_EAX + 0x524) + iVar3) * 4),uVar2);

            (**(code **)(**(int **)(*(int *)(in_EAX + 0x72c) + iVar3 * 4) + 0xfc))(1,0x3f000000);

            if (*(int *)(in_EAX + 0x52c) + -1 == *(int *)(in_EAX + 0x524) + iVar3) {

              pcVar4 = "i_d_body_2d_btn_uninstall";

            }

            else {

              pcVar4 = (char *)(in_EAX + 0x604);

            }

            (**(code **)(**(int **)(*(int *)(in_EAX + 0x73c) + iVar3 * 4) + 0x3ac))(pcVar4);

            (**(code **)(**(int **)(*(int *)(in_EAX + 0x73c) + iVar3 * 4) + 0xfc))(1,0x3f000000);

          }

        }

        else {

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x72c) + iVar3 * 4) + 0x58))();

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x72c) + iVar3 * 4) + 0xcc))(0);

          (**(code **)(**(int **)(*(int *)(in_EAX + 0x73c) + iVar3 * 4) + 0xcc))(0);

        }

        iVar3 = iVar3 + 1;

      } while (iVar3 < *(int *)(in_EAX + 0x51c));

    }

    FUN_008fc650();

    FUN_008fdb60(in_EAX);

  }

  return;

}
