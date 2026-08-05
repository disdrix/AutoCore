// =============================================================================
// FUN_00937710
// -----------------------------------------------------------------------------
// Stable ID: aa_00937710
// Address:   0x00937710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00937710 @ 0x00937710
// Stable ID: aa_00937710
// Embedded strings (evidence for future rename):
//   - "The server is processing your request.  Please wait..."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×3, do×3, while×3, return×1.
//  - Notable callees: FUN_00540400, FUN_007fdfb0, FUN_00937710.
//  - Strings: "The server is processing your request.  Please wait...".
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

void FUN_00937710(void)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_d0;

  uint32_t /* width from decompiler */ local_cc;

  char local_c8 [33];

  char local_a7 [51];

  uint32_t /* width from decompiler */ local_74;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint8_t local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  char local_24 [36];

  

  local_d0 = 0x1002;

  if (*(int *)(unaff_ESI + 0xe44) < 1) {

    local_cc = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x15c);

  }

  else {

    iVar2 = FUN_00540400(*(uint8_t *)(unaff_ESI + 0xe68),*(uint8_t *)(unaff_ESI + 0xe69),

                         *(uint8_t *)(unaff_ESI + 0xe6a));

    local_cc = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x34);

  }

  pcVar3 = (char *)(unaff_ESI + 0xe10);

  iVar2 = -(int)pcVar3;

  do {

    cVar1 = *pcVar3;

    pcVar3[(int)(local_a7 + iVar2)] = cVar1;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  pcVar3 = (char *)(*(int *)(unaff_ESI + 0xe0c) + 0xc);

  iVar2 = -(int)pcVar3;

  do {

    cVar1 = *pcVar3;

    pcVar3[(int)(local_c8 + iVar2)] = cVar1;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  pcVar3 = (char *)(unaff_ESI + 0xe21);

  iVar2 = -(int)pcVar3;

  do {

    cVar1 = *pcVar3;

    pcVar3[(int)(local_24 + iVar2)] = cVar1;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  local_70 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe44);

  local_58 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe4c);

  local_74 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe48);

  local_2c = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe90);

  local_6c = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe50);

  local_68 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe54);

  local_64 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe58);

  local_60 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe5c);

  local_5c = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe60);

  local_4c = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe78);

  local_48 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe7c);

  local_54 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe6c);

  local_50 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe70);

  local_44 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe74);

  local_40 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe80);

  local_38 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe84);

  local_34 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe88);

  local_30 = *(uint8_t *)(unaff_ESI + 0xe8c);

  local_28 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe94);

  if (*(int *)(unaff_ESI + 0xc7c) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 0x18))(0xffffffff,&local_d0,0xd0,0);

    }

  }

  FUN_007fdfb0(unaff_ESI,"The server is processing your request.  Please wait...",0x9c41,1,0);

  return;

}
