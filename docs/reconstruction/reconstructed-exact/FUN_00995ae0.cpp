// =============================================================================
// FUN_00995ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_00995ae0
// Address:   0x00995ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00995ae0 @ 0x00995ae0
// Stable ID: aa_00995ae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~97 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: block×51, FUN_004523f0, FUN_00456780, FUN_00456960, FUN_00995ae0.
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

/* WARNING: Removing unreachable block (ram,0x00995b53) */

/* WARNING: Removing unreachable block (ram,0x00995b71) */

/* WARNING: Removing unreachable block (ram,0x00995bbb) */

/* WARNING: Removing unreachable block (ram,0x00995bc6) */

/* WARNING: Removing unreachable block (ram,0x00995bde) */

/* WARNING: Removing unreachable block (ram,0x00995bc2) */

/* WARNING: Removing unreachable block (ram,0x00995beb) */

/* WARNING: Removing unreachable block (ram,0x00995b79) */

/* WARNING: Removing unreachable block (ram,0x00995b82) */

/* WARNING: Removing unreachable block (ram,0x00995e0a) */

/* WARNING: Removing unreachable block (ram,0x00995b4d) */

/* WARNING: Removing unreachable block (ram,0x00995b40) */

/* WARNING: Removing unreachable block (ram,0x00995b88) */

/* WARNING: Removing unreachable block (ram,0x00995c7c) */

/* WARNING: Removing unreachable block (ram,0x00995c80) */

/* WARNING: Removing unreachable block (ram,0x00995c8c) */

/* WARNING: Removing unreachable block (ram,0x00995d84) */

/* WARNING: Removing unreachable block (ram,0x00995d8b) */

/* WARNING: Removing unreachable block (ram,0x00995d90) */

/* WARNING: Removing unreachable block (ram,0x00995d9c) */

/* WARNING: Removing unreachable block (ram,0x00995dab) */

/* WARNING: Removing unreachable block (ram,0x00995dc3) */

/* WARNING: Removing unreachable block (ram,0x00995da7) */

/* WARNING: Removing unreachable block (ram,0x00995dd0) */

/* WARNING: Removing unreachable block (ram,0x00995de4) */

/* WARNING: Removing unreachable block (ram,0x00995c9c) */

/* WARNING: Removing unreachable block (ram,0x00995d17) */

/* WARNING: Removing unreachable block (ram,0x00995d22) */

/* WARNING: Removing unreachable block (ram,0x00995d32) */

/* WARNING: Removing unreachable block (ram,0x00995d41) */

/* WARNING: Removing unreachable block (ram,0x00995d59) */

/* WARNING: Removing unreachable block (ram,0x00995d3d) */

/* WARNING: Removing unreachable block (ram,0x00995d66) */

/* WARNING: Removing unreachable block (ram,0x00995d7a) */

/* WARNING: Removing unreachable block (ram,0x00995d82) */

/* WARNING: Removing unreachable block (ram,0x00995ca3) */

/* WARNING: Removing unreachable block (ram,0x00995cad) */

/* WARNING: Removing unreachable block (ram,0x00995ca9) */

/* WARNING: Removing unreachable block (ram,0x00995cb5) */

/* WARNING: Removing unreachable block (ram,0x00995ccb) */

/* WARNING: Removing unreachable block (ram,0x00995cd6) */

/* WARNING: Removing unreachable block (ram,0x00995cee) */

/* WARNING: Removing unreachable block (ram,0x00995cd2) */

/* WARNING: Removing unreachable block (ram,0x00995cfe) */

/* WARNING: Removing unreachable block (ram,0x00995dec) */

/* WARNING: Removing unreachable block (ram,0x00995dfc) */

/* WARNING: Removing unreachable block (ram,0x00995e0e) */

/* WARNING: Removing unreachable block (ram,0x00995e11) */

/* WARNING: Removing unreachable block (ram,0x00995e17) */

/* WARNING: Removing unreachable block (ram,0x00995e20) */

/* WARNING: Removing unreachable block (ram,0x00995e32) */



uint32_t /* width from decompiler */ __thiscall FUN_00995ae0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  void **ppvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b3011;

  pvStack_c = ExceptionList;

  local_4 = 0;

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_2 + 4);

  ExceptionList = &pvStack_c;

  ppvVar2 = &pvStack_c;

  if (puVar3 != *(uint32_t /* width from decompiler */ **)(param_2 + 8)) {

    do {

      ExceptionList = ppvVar2;

      uVar1 = *puVar3;

      FUN_004523f0(1);

      if ((iRamfffffff4 == 0) ||

         ((uint)(iRamfffffffc - iRamfffffff4 >> 2) <= (uint)((int)puRamfffffff8 - iRamfffffff4 >> 2)

         )) {

        FUN_00456960();

      }

      else {

        *puRamfffffff8 = uVar1;

        puRamfffffff8 = puRamfffffff8 + 1;

      }

      puVar3 = puVar3 + 1;

      ppvVar2 = ExceptionList;

    } while (puVar3 != *(uint32_t /* width from decompiler */ **)(param_2 + 8));

  }

  piVar4 = *(int **)(param_1 + 4);

  if (piVar4 != *(int **)(param_1 + 8)) {

    do {

      if ((uint32_t /* width from decompiler */ *)*piVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar4)();

      }

      piVar4 = piVar4 + 1;

    } while (piVar4 != *(int **)(param_1 + 8));

  }

  FUN_00456780();

  ExceptionList = pvStack_c;

  return 0;

}
