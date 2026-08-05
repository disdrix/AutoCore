// =============================================================================
// FUN_00671aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00671aa0
// Address:   0x00671aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00671aa0 @ 0x00671aa0
// Stable ID: aa_00671aa0
// Embedded strings (evidence for future rename):
//   - "Couldnt get capture interface\n"
//   - "Couldnt set notifications\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×4, if×3, do×1, while×1.
//  - Notable callees: FUN_0076c130×2, FUN_00671aa0.
//  - Strings: "Couldnt get capture interface\n"; "Couldnt set notifications\n".
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __fastcall FUN_00671aa0(int param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (*(int *)(param_1 + 0x98) == 0) {

    return 0xffffffff;

  }

  iVar2 = (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x98))

                    (*(uint32_t /* width from decompiler */ **)(param_1 + 0x98),&DAT_00a0d024,(uint32_t /* width from decompiler */ *)(param_1 + 0x9c));

  if (iVar2 < 0) {

    FUN_0076c130("Couldnt get capture interface\n");

    return 0xffffffff;

  }

  iVar2 = 0;

  puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0xd8);

  do {

    iVar2 = iVar2 + 1;

    puVar3[-1] = *(int *)(param_1 + 0xcc) * iVar2 + -1;

    *puVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xd0);

    puVar3 = puVar3 + 2;

  } while (iVar2 < 0x10);

  piVar1 = *(int **)(param_1 + 0x9c);

  iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,0x10,param_1 + 0xd4);

  if (iVar2 < 0) {

    FUN_0076c130("Couldnt set notifications\n");

    return 0xffffffff;

  }

  return 0;

}
