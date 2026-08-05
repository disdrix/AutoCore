// =============================================================================
// Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window_00935fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00935fe0
// Callee of Named_Could_not_get_Palantir_desktop_window
// Address:   0x00935fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Could_not_get_Palantir_desktop_window: callee helper. Evidence string: "Had %u system mem and %u video mem". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Had %u system mem and %u video mem"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×14, return×1.
//  - Notable callees: FUN_0092f190×2, Client_GetMissionCompleteAudioTable, FUN_007a4480, FUN_00935fe0, FUN_0095c5a0, GlobalMemoryStatus.
//  - Strings: "Had %u system mem and %u video mem".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Could_not_get_Palantir_desktop_window
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

void Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window_00935fe0(void)



{

  char cVar1;

  int *piVar2;

  char cVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  int unaff_ESI;

  uint uVar7;

  _MEMORYSTATUS local_20;

  

  GlobalMemoryStatus(&local_20);

  uVar6 = 2;

  if (local_20.dwTotalPhys < 0x40000001) {

    uVar6 = 1;

  }

  else if (local_20.dwTotalPhys < 0x20000001) {

    uVar6 = 0;

  }

  piVar2 = (int *)**(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0xde8) + 0x28);

  uVar7 = 2;

  uVar4 = (**(code **)(*piVar2 + 0x10))(piVar2);

  uVar4 = uVar4 >> 1;

  if (uVar4 < 0xc800000) {

    uVar7 = 1;

  }

  else if (uVar4 < 0x6400000) {

    uVar7 = 0;

  }

  FUN_007a4480(0,"Had %u system mem and %u video mem",local_20.dwMemoryLoad,uVar4);

  if ((uVar6 < 2) || (*(char *)(unaff_ESI + 0x11) != '\0')) {

    DAT_00d1b229 = 1;

    iVar5 = Client_GetMissionCompleteAudioTable();

    *(uint8_t *)(iVar5 + 0x308) = 1;

  }

  cVar3 = '\0';

  if ((uVar6 == 0) || (uVar7 < 2)) {

    cVar3 = '\x01';

  }

  if (uVar7 == 0) {

    cVar3 = '\0';

  }

  cVar1 = *(char *)(unaff_ESI + 0x11);

  if (cVar1 != '\0') {

    if (cVar3 == '\0') {

      cVar3 = '\x01';

    }

    if ((cVar1 != '\0') && (cVar3 == '\0')) {

      cVar3 = '\x01';

    }

  }

  *(char *)(unaff_ESI + 0xa0d) = cVar3;

  if ((*(int **)(unaff_ESI + 0xf40) == (int *)0x0) ||

     (**(int **)(unaff_ESI + 0xf40) != *(int *)(unaff_ESI + 0xf38))) {

    *(bool *)(unaff_ESI + 0xb5) = cVar1 != '\0';

  }

  else {

    *(char *)(unaff_ESI + 0xb5) = cVar3;

  }

  if (uVar7 == 0) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xa18) = 800;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xa1c) = 600;

    *(uint8_t *)(*(int *)(DAT_00d1b644 + 0xe894) + 0x78) = 0;

    DAT_00afa2dc = 0;

    DAT_00aefa54 = 0;

    DAT_00d1b20e = 0;

    FUN_0092f190(0);

    DAT_00d1b210 = 0;

    *(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b644 + 0xe890) + 0x104) = DAT_00aaa7ac;

  }

  if (*(byte *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0xe04) + 0xe89c) + 0x28) + 0x799) < 2) {

    *(uint8_t *)(*(int *)(DAT_00d1b644 + 0xe894) + 0x78) = 0;

    DAT_00afa2dc = 0;

    DAT_00aefa54 = 0;

    DAT_00d1b20e = 0;

    FUN_0092f190(0);

    DAT_00d1b210 = 0;

    *(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b644 + 0xe890) + 0x104) = DAT_00aaa7ac;

  }

  if (uVar6 == 0) {

    DAT_00d1793d = 1;

  }

  FUN_0095c5a0();

  return;

}
