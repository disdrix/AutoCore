// =============================================================================
// FUN_009103d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009103d0
// Address:   0x009103d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009103d0 @ 0x009103d0
// Stable ID: aa_009103d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0074ecf0, FUN_009103d0.
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

void FUN_009103d0(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int in_EAX;

  int iVar3;

  

  iVar3 = in_EAX * 0x10;

  if (*(int *)(&DAT_00d09a54 + iVar3) != 0) {

    (**(code **)(*(int *)(&DAT_00d09a4c)[in_EAX * 4] + 0x10))(*(int *)(&DAT_00d09a54 + iVar3));

    pvVar1 = *(void **)(&DAT_00d09a54 + iVar3);

    if (pvVar1 != (void *)0x0) {

      FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(&DAT_00d09a54 + iVar3) = 0;

    if (*(uint32_t /* width from decompiler */ **)(&DAT_00d09a50 + iVar3) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(&DAT_00d09a50 + iVar3))(1);

    }

    puVar2 = (uint32_t /* width from decompiler */ *)(&DAT_00d09a4c)[in_EAX * 4];

    *(uint32_t /* width from decompiler */ *)(&DAT_00d09a50 + iVar3) = 0;

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar2)(1);

    }

    (&DAT_00d09a4c)[in_EAX * 4] = 0;

    if ((uint32_t /* width from decompiler */ *)(&DAT_00d09a58)[in_EAX * 4] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)(&DAT_00d09a58)[in_EAX * 4])(1);

    }

    (&DAT_00d09a58)[in_EAX * 4] = 0;

  }

  return;

}
