// =============================================================================
// Named_Socket_Sendto
// -----------------------------------------------------------------------------
// Stable ID: aa_00784d20
// Address:   0x00784d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Socket_Sendto @ 0x00784d20
// Stable ID: aa_00784d20
// Embedded strings (evidence for future rename):
//   - "Socket::sendto"
//   - "LogUDP"
//   - "Internal buffer filled up."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×14, return×8.
//  - Notable callees: FUN_007803f0×2, swi×2, FUN_00780060, FUN_00783aa0, FUN_00783b60, FUN_00783f10, FUN_00784340, FUN_00784490.
//  - Strings: "Socket::sendto"; "LogUDP"; "Internal buffer filled up.".
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Socket::sendto"
 * Domain alias of FUN_00784d20 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ Named_Socket_Sendto(SOCKET *param_1,char *param_2,int param_3)



{

  code *pcVar1;

  char cVar2;

  ushort *in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  sockaddr local_10;

  

  if (DAT_00d179e4 == 2) {

    if (DAT_00d179e0 != '\0') {

      if ((_DAT_00d2068c & 1) == 0) {

        _DAT_00d2068c = _DAT_00d2068c | 1;

        _DAT_00d20680 = "Socket::sendto";

        _DAT_00d20684 = 0xffffffff;

        _DAT_00d20688 = DAT_00d17a00;

        DAT_00d17a00 = &DAT_00d20680;

      }

      FUN_007803f0(&DAT_00d20680);

      DAT_00d179fc = DAT_00d179fc + 1;

      if ((DAT_00d179f8 != 0) && (DAT_00d179f8 <= DAT_00d179fc)) {

        pcVar1 = (code *)swi(3);

        uVar3 = (*pcVar1)();

        return uVar3;

      }

      if ((DAT_00afddd4 == '\0') && (DAT_00afddd0 < DAT_00d179e8)) {

        return 0;

      }

      pcVar1 = (code *)swi(3);

      uVar3 = (*pcVar1)();

      return uVar3;

    }

  }

  else if ((DAT_00d179e4 == 1) && (DAT_00d179e0 != '\0')) {

    if ((_DAT_00d2068c & 2) == 0) {

      _DAT_00d2068c = _DAT_00d2068c | 2;

      _DAT_00d20674 = "Socket::sendto";

      _DAT_00d20678 = 0xffffffff;

      _DAT_00d2067c = DAT_00d17a00;

      DAT_00d17a00 = &DAT_00d20674;

    }

    FUN_007803f0(&DAT_00d20674);

    FUN_00780060();

  }

  if ((uint)*in_EAX != param_1[1]) {

    return 1;

  }

  if (param_1[2] == 0) {

    FUN_00784490();

    iVar4 = sendto(*param_1,param_2,param_3,0,&local_10,(int)param_1);

    if (iVar4 != -1) {

      return 0;

    }

    uVar3 = FUN_00783f10();

    return uVar3;

  }

  cVar2 = FUN_00784340(param_2,param_3,1);

  if (cVar2 == '\0') {

    if (*param_1 != 0xffffffff) {

      shutdown(*param_1,2);

      closesocket(*param_1);

    }

    if ((_DAT_00d2068c & 4) == 0) {

      _DAT_00d2068c = _DAT_00d2068c | 4;

      DAT_00d20670 = FUN_00783b60("LogUDP");

    }

    if (*(char *)(DAT_00d20670 + 4) != '\0') {

      DAT_00d179a0 = DAT_00d20670;

      FUN_00783aa0("Internal buffer filled up.");

      DAT_00d179a0 = 0;

    }

    return 2;

  }

  uVar3 = FUN_00784bd0();

  return uVar3;

}
