// =============================================================================
// FUN_0056bce0
// -----------------------------------------------------------------------------
// Stable ID: aa_0056bce0
// Address:   0x0056bce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056bce0 @ 0x0056bce0
// Stable ID: aa_0056bce0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_004b7550×4, FUN_004b8dc0, FUN_004b99c0, FUN_004ec010, FUN_0056a770, FUN_0056bce0, FUN_0056edf0.
//  - Return sites: 3.

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

void __thiscall FUN_0056bce0(int param_1,char param_2)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ auStack_c [3];

  

  iVar2 = *(int *)(*(int *)(param_1 + -0x14c) + 4);

  if (param_2 == '\0') {

    (**(code **)(*(int *)(iVar2 + -0x14c + param_1) + 0xfc))();

    pvVar1 = *(void **)(param_1 + -0x94);

    if (pvVar1 != (void *)0x0) {

      FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x94) = 0;

    *(uint8_t *)(param_1 + -0x9e) = 0;

    FUN_0056edf0();

  }

  else {

    iVar2 = *(int *)(iVar2 + -0xa8 + param_1);

    if ((iVar2 != 0) && (*(char *)(iVar2 + 0xf5) == '\0')) {

      FUN_0056a770();

      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x14c + param_1) + 0x100))()

      ;

      iVar2 = *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + param_1 + -0xa4);

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = *(int *)(iVar2 + 0x3c);

      }

      if ((*(byte *)(iVar2 + 0x536) & 0x80) != 0) {

        iVar2 = FUN_004ec010(4);

        if (iVar2 != 0) {

          auStack_c[0] = 0;

          FUN_004b7550(auStack_c,1);

          auStack_c[0] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x68);

          FUN_004b7550(auStack_c,2);

          auStack_c[0] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x74);

          FUN_004b7550(auStack_c,3);

          auStack_c[0] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x70);

          FUN_004b7550(auStack_c,4);

          FUN_004b8dc0(0,0);

          (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x14c + param_1) + 0xf8)

          )(iVar2,1,0);

          return;

        }

      }

    }

  }

  return;

}
