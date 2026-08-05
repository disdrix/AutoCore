// =============================================================================
// FUN_00547050
// -----------------------------------------------------------------------------
// Stable ID: aa_00547050
// Address:   0x00547050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00547050 @ 0x00547050
// Stable ID: aa_00547050
// Embedded strings (evidence for future rename):
//   - "Mission - Sequence too big.. (%d >= %d) %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: block×71, FUN_007a4480×2, FUN_00547050, FUN_00799820.
//  - Strings: "Mission - Sequence too big.. (%d >= %d) %s".
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

/* WARNING: Removing unreachable block (ram,0x00547104) */

/* WARNING: Removing unreachable block (ram,0x00547145) */

/* WARNING: Removing unreachable block (ram,0x00547173) */

/* WARNING: Removing unreachable block (ram,0x005471ab) */

/* WARNING: Removing unreachable block (ram,0x005471cf) */

/* WARNING: Removing unreachable block (ram,0x005471e0) */

/* WARNING: Removing unreachable block (ram,0x005476da) */

/* WARNING: Removing unreachable block (ram,0x0054775e) */

/* WARNING: Removing unreachable block (ram,0x005477e2) */

/* WARNING: Removing unreachable block (ram,0x0054785f) */

/* WARNING: Removing unreachable block (ram,0x00547872) */

/* WARNING: Removing unreachable block (ram,0x005477f5) */

/* WARNING: Removing unreachable block (ram,0x00547857) */

/* WARNING: Removing unreachable block (ram,0x00547771) */

/* WARNING: Removing unreachable block (ram,0x005477d7) */

/* WARNING: Removing unreachable block (ram,0x005476ed) */

/* WARNING: Removing unreachable block (ram,0x00547753) */

/* WARNING: Removing unreachable block (ram,0x00547229) */

/* WARNING: Removing unreachable block (ram,0x00547257) */

/* WARNING: Removing unreachable block (ram,0x005472a5) */

/* WARNING: Removing unreachable block (ram,0x005472f3) */

/* WARNING: Removing unreachable block (ram,0x00547341) */

/* WARNING: Removing unreachable block (ram,0x0054738f) */

/* WARNING: Removing unreachable block (ram,0x005473dd) */

/* WARNING: Removing unreachable block (ram,0x0054742b) */

/* WARNING: Removing unreachable block (ram,0x00547479) */

/* WARNING: Removing unreachable block (ram,0x005474c7) */

/* WARNING: Removing unreachable block (ram,0x00547515) */

/* WARNING: Removing unreachable block (ram,0x00547566) */

/* WARNING: Removing unreachable block (ram,0x005475b4) */

/* WARNING: Removing unreachable block (ram,0x00547602) */

/* WARNING: Removing unreachable block (ram,0x00547649) */

/* WARNING: Removing unreachable block (ram,0x0054765c) */

/* WARNING: Removing unreachable block (ram,0x00547679) */

/* WARNING: Removing unreachable block (ram,0x00547615) */

/* WARNING: Removing unreachable block (ram,0x0054762f) */

/* WARNING: Removing unreachable block (ram,0x005475c7) */

/* WARNING: Removing unreachable block (ram,0x005475e5) */

/* WARNING: Removing unreachable block (ram,0x00547579) */

/* WARNING: Removing unreachable block (ram,0x00547597) */

/* WARNING: Removing unreachable block (ram,0x00547528) */

/* WARNING: Removing unreachable block (ram,0x00547549) */

/* WARNING: Removing unreachable block (ram,0x005474da) */

/* WARNING: Removing unreachable block (ram,0x005474f8) */

/* WARNING: Removing unreachable block (ram,0x0054748c) */

/* WARNING: Removing unreachable block (ram,0x005474aa) */

/* WARNING: Removing unreachable block (ram,0x0054743e) */

/* WARNING: Removing unreachable block (ram,0x0054745c) */

/* WARNING: Removing unreachable block (ram,0x005473f0) */

/* WARNING: Removing unreachable block (ram,0x0054740e) */

/* WARNING: Removing unreachable block (ram,0x005473a2) */

/* WARNING: Removing unreachable block (ram,0x005473c0) */

/* WARNING: Removing unreachable block (ram,0x00547354) */

/* WARNING: Removing unreachable block (ram,0x00547372) */

/* WARNING: Removing unreachable block (ram,0x00547306) */

/* WARNING: Removing unreachable block (ram,0x00547324) */

/* WARNING: Removing unreachable block (ram,0x005472b8) */

/* WARNING: Removing unreachable block (ram,0x005472d6) */

/* WARNING: Removing unreachable block (ram,0x0054726a) */

/* WARNING: Removing unreachable block (ram,0x00547693) */

/* WARNING: Removing unreachable block (ram,0x00547288) */

/* WARNING: Removing unreachable block (ram,0x00547695) */

/* WARNING: Removing unreachable block (ram,0x005476a2) */

/* WARNING: Removing unreachable block (ram,0x005476c5) */

/* WARNING: Removing unreachable block (ram,0x005476cb) */

/* WARNING: Removing unreachable block (ram,0x005478ae) */

/* WARNING: Removing unreachable block (ram,0x005478cd) */

/* WARNING: Removing unreachable block (ram,0x005478ce) */

/* WARNING: Removing unreachable block (ram,0x0054718a) */

/* WARNING: Removing unreachable block (ram,0x00547161) */

/* WARNING: Removing unreachable block (ram,0x00547130) */



void FUN_00547050(int *param_1)



{

  char cVar1;

  int iVar2;

  int *piStack_2b8;

  void *pvStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a4322;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  iVar2 = (**(code **)(*param_1 + 0x44))();

  if ((iVar2 == 0) && (piStack_2b8 != (int *)0x0)) {

    cVar1 = FUN_00799820(piStack_2b8);

    if (cVar1 != '\0') {

      FUN_007a4480(1,"Mission - Sequence too big.. (%d >= %d) %s");

      ExceptionList = pvStack_14;

      return;

    }

    (**(code **)(*piStack_2b8 + 8))();

  }

  FUN_007a4480();

  ExceptionList = pvStack_14;

  return;

}
