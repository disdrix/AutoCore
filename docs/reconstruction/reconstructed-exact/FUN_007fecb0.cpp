// =============================================================================
// FUN_007fecb0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fecb0
// Address:   0x007fecb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fecb0 @ 0x007fecb0
// Stable ID: aa_007fecb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007fecb0, FUN_0083dae0, FUN_0092f000.
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

void FUN_007fecb0(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int in_EAX;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uStack_18;

  uint8_t local_8 [8];

  

  iVar1 = *(int *)(unaff_EDI + 0x113c);

  if ((iVar1 != 0) && (in_EAX != 0)) {

    *(int *)(iVar1 + 0x500) = in_EAX;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4fc) = 0;

    uStack_18 = 0x7fecdf;

    FUN_0083dae0();

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x113c) + 0x508) = param_1;

    uStack_18 = 1;

    (**(code **)(**(int **)(unaff_EDI + 0x113c) + 0x140))(local_8);

    (**(code **)(**(int **)(unaff_EDI + 0x113c) + 0x11c))(&uStack_18);

    iVar1 = *(int *)(unaff_EDI + 0x113c);

    if (*(int *)(iVar1 + 0x2b0) == 0) {

      *(uint32_t /* width from decompiler */ *)(**(int **)(unaff_EDI + 0xf40) + 0x514) =

           *(uint32_t /* width from decompiler */ *)(**(int **)(unaff_EDI + 0xf40) + 0x498);

      *(uint32_t /* width from decompiler */ *)(**(int **)(unaff_EDI + 0xf40) + 0x518) =

           *(uint32_t /* width from decompiler */ *)(**(int **)(unaff_EDI + 0xf40) + 0x49c);

      *(uint32_t /* width from decompiler */ *)(**(int **)(unaff_EDI + 0xf40) + 0x498) = 0x4e62;

      *(uint32_t /* width from decompiler */ *)(**(int **)(unaff_EDI + 0xf40) + 0x49c) = 0x4e63;

    }

    else {

      (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

    }

    (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_EDI + 0xf40) + 0x3ec))();

    (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_EDI + 0xf40) + 0x3f4))(1);

    (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_EDI + 0xf40) + 0xa8))

              (*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x113c));

    (**(code **)(**(int **)(unaff_EDI + 0x113c) + 4))(1);

    (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_EDI + 0xf40) + 0x1c8))(1);

    FUN_0092f000();

    (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_EDI + 0xf40) + 0x3bc))

              (*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x113c));

    (**(code **)(**(int **)(unaff_EDI + 0x113c) + 0x334))(1);

    (**(code **)(**(int **)(unaff_EDI + 0x113c) + 0x94))();

  }

  return;

}
