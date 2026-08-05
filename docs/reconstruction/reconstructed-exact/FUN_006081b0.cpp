// =============================================================================
// FUN_006081b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006081b0
// Address:   0x006081b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006081b0 @ 0x006081b0
// Stable ID: aa_006081b0
// Embedded strings (evidence for future rename):
//   - "Outpost %s has fallen to a rogue faction!"
//   - "%s has captured outpost %s for "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, for×1, return×1.
//  - Notable callees: sprintf×2, FUN_0040c5c0, FUN_006065a0, FUN_006081b0.
//  - Strings: "Outpost %s has fallen to a rogue faction!"; "%s has captured outpost %s for ".
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

void __thiscall FUN_006081b0(int param_1,int param_2)



{

  char *pcVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint16_t *puVar4;

  char acStack_19c [128];

  uint8_t local_11c;

  uint8_t local_11b;

  uint8_t local_11a;

  uint8_t local_119;

  uint32_t /* width from decompiler */ uStack_110;

  uint32_t /* width from decompiler */ uStack_10c;

  uint8_t auStack_108 [4];

  char local_104 [260];

  

  if (*(char *)(param_1 + 0x220) != '\0') {

    if (param_2 == 0) {

      sprintf(local_104,"Outpost %s has fallen to a rogue faction!",param_1 + 0x1d4);

    }

    else {

      uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x160))

                        (param_1 + 0x1d4);

      sprintf(local_104,"%s has captured outpost %s for ",uVar2);

      FUN_006065a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x234),local_104);

      puVar4 = (uint16_t *)(auStack_108 + 3);

      do {

        pcVar1 = (char *)((int)puVar4 + 1);

        puVar4 = (uint16_t *)((int)puVar4 + 1);

      } while (*pcVar1 != '\0');

      *puVar4 = DAT_00a156cc;

    }

    local_11a = 0xff;

    local_11b = 0xff;

    local_11c = 0xff;

    local_119 = 0xff;

    iVar3 = 0;

    do {

      pcVar1 = local_104 + iVar3;

      acStack_19c[iVar3] = *pcVar1;

      iVar3 = iVar3 + 1;

    } while (*pcVar1 != '\0');

    uStack_110 = 1;

    uStack_10c = 0xffffffff;

    auStack_108 = (uint8_t  [4])0xffffffff;

    FUN_0040c5c0(acStack_19c);

  }

  return;

}
