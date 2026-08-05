// =============================================================================
// FUN_00785510
// -----------------------------------------------------------------------------
// Stable ID: aa_00785510
// Address:   0x00785510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00785510 @ 0x00785510
// Stable ID: aa_00785510
// Embedded strings (evidence for future rename):
//   - "Socket::Socket"
//   - "LogUDP"
//   - "Attempted to create a socket bound to an invalid transport."
//   - "%s socket created."
//   - "%s socket bound to address: %s"
//   - "%s socket error: unable to bind the socket to the specified address."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~257 non-empty decompiler lines.
//  - Control keywords: if×42, return×4, goto×3.
//  - Notable callees: FUN_00783aa0×12, FUN_00783b60×12, setsockopt×3, socket×3, FUN_007803f0×2, FUN_00783ee0×2, swi×2, BitStream_readBits.
//  - Strings: "Socket::Socket"; "LogUDP"; "Attempted to create a socket bound to an invalid transport."; "%s socket created.".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



SOCKET * TNL_Socket_Constructor

                   (SOCKET *param_1,ushort *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                   SOCKET param_5,byte param_6)



{

  ushort uVar1;

  code *pcVar2;

  SOCKET *pSVar3;

  SOCKET SVar4;

  void *pvVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  undefined *puVar8;

  bool bVar9;

  int local_28;

  sockaddr local_24;

  uint16_t local_14;

  uint16_t local_12;

  u_long local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  pSVar3 = param_1;

  bVar9 = DAT_00d179e4 == 2;

  param_1[2] = 0;

  param_1[3] = 0;

  if ((bVar9) && (DAT_00d179e0 != '\0')) {

    if ((_DAT_00d208a4 & 1) == 0) {

      _DAT_00d208a4 = _DAT_00d208a4 | 1;

      _DAT_00d20898 = "Socket::Socket";

      _DAT_00d2089c = 0xffffffff;

      _DAT_00d208a0 = DAT_00d17a00;

      DAT_00d17a00 = &DAT_00d20898;

    }

    FUN_007803f0(&DAT_00d20898);

    DAT_00d179fc = DAT_00d179fc + 1;

    if ((DAT_00d179f8 != 0) && (DAT_00d179f8 <= DAT_00d179fc)) {

      pcVar2 = (code *)swi(3);

      pSVar3 = (SOCKET *)(*pcVar2)();

      return pSVar3;

    }

    BitStream_readBits(0x20,&param_5);

    *param_1 = param_5;

    if ((DAT_00afddd4 == '\0') && (DAT_00afddd0 < DAT_00d179e8)) {

      return param_1;

    }

    pcVar2 = (code *)swi(3);

    pSVar3 = (SOCKET *)(*pcVar2)();

    return pSVar3;

  }

  FUN_00784560();

  *param_1 = 0xffffffff;

  param_1[1] = (uint)*param_2;

  uVar1 = *param_2;

  puVar8 = &DAT_00a9b188;

  param_1 = (SOCKET *)&DAT_00a9b188;

  if (uVar1 == 0) {

    SVar4 = socket(2,2,0);

    *pSVar3 = SVar4;

  }

  else if (uVar1 == 1) {

    puVar8 = &DAT_00a9b184;

    param_1 = (SOCKET *)&DAT_00a9b184;

    SVar4 = socket(2,1,0);

    *pSVar3 = SVar4;

    pvVar5 = operator_new(0x18);

    if (pvVar5 == (void *)0x0) {

      SVar4 = 0;

    }

    else {

      SVar4 = FUN_00783ee0();

    }

    pSVar3[2] = SVar4;

    pvVar5 = operator_new(0x18);

    if (pvVar5 == (void *)0x0) {

      pSVar3[3] = 0;

    }

    else {

      SVar4 = FUN_00783ee0();

      pSVar3[3] = SVar4;

    }

  }

  else if (uVar1 == 2) {

    puVar8 = &DAT_00a9b180;

    param_1 = (SOCKET *)&DAT_00a9b180;

    SVar4 = socket(6,2,1000);

    *pSVar3 = SVar4;

  }

  else {

    if ((_DAT_00d208a4 & 2) == 0) {

      _DAT_00d208a4 = _DAT_00d208a4 | 2;

      DAT_00d20894 = FUN_00783b60("LogUDP");

    }

    if (*(char *)(DAT_00d20894 + 4) != '\0') {

      DAT_00d179a0 = DAT_00d20894;

      FUN_00783aa0("Attempted to create a socket bound to an invalid transport.");

      DAT_00d179a0 = 0;

    }

  }

  if (*pSVar3 == 0xffffffff) goto LAB_00785b8e;

  if ((_DAT_00d208a4 & 4) == 0) {

    _DAT_00d208a4 = _DAT_00d208a4 | 4;

    DAT_00d20890 = FUN_00783b60("LogUDP");

  }

  if (*(char *)(DAT_00d20890 + 4) != '\0') {

    DAT_00d179a0 = DAT_00d20890;

    FUN_00783aa0("%s socket created.",puVar8);

    DAT_00d179a0 = 0;

  }

  local_28 = 0x10;

  FUN_00784490();

  iVar6 = bind(*pSVar3,&local_24,local_28);

  local_14 = 0;

  local_12 = 0;

  local_4 = 0;

  local_8 = 0;

  local_c = 0;

  local_10 = htonl(0);

  if (iVar6 == 0) {

    local_28 = 0x10;

    getsockname(*pSVar3,&local_24,&local_28);

    FUN_007843e0();

    if ((_DAT_00d208a4 & 8) == 0) {

      _DAT_00d208a4 = _DAT_00d208a4 | 8;

      DAT_00d2088c = FUN_00783b60("LogUDP");

    }

    if (*(char *)(DAT_00d2088c + 4) != '\0') {

      DAT_00d179a0 = DAT_00d2088c;

      uVar7 = FUN_007845c0();

      FUN_00783aa0("%s socket bound to address: %s",param_1,uVar7);

      DAT_00d179a0 = 0;

    }

    iVar6 = setsockopt(*pSVar3,0xffff,0x1002,(char *)&param_4,4);

  }

  else {

    if ((_DAT_00d208a4 & 0x10) == 0) {

      _DAT_00d208a4 = _DAT_00d208a4 | 0x10;

      DAT_00d20884 = FUN_00783b60("LogUDP");

    }

    if (*(char *)(DAT_00d20884 + 4) != '\0') {

      DAT_00d179a0 = DAT_00d20884;

      FUN_00783aa0("%s socket error: unable to bind the socket to the specified address.",param_1);

      DAT_00d179a0 = 0;

    }

  }

  if (iVar6 == 0) {

    if ((_DAT_00d208a4 & 0x20) == 0) {

      _DAT_00d208a4 = _DAT_00d208a4 | 0x20;

      DAT_00d20888 = FUN_00783b60("LogUDP");

    }

    if (*(char *)(DAT_00d20888 + 4) != '\0') {

      DAT_00d179a0 = DAT_00d20888;

      FUN_00783aa0("%s socket receive buffer size set to %d.",param_1,param_4);

      DAT_00d179a0 = 0;

    }

    iVar6 = setsockopt(*pSVar3,0xffff,0x1001,(char *)&param_3,4);

  }

  else {

    if ((_DAT_00d208a4 & 0x40) == 0) {

      _DAT_00d208a4 = _DAT_00d208a4 | 0x40;

      DAT_00d20880 = FUN_00783b60("LogUDP");

    }

    if (*(char *)(DAT_00d20880 + 4) != '\0') {

      DAT_00d179a0 = DAT_00d20880;

      FUN_00783aa0("%s socket error: unable to set the receive buffer size on socket.",param_1);

      DAT_00d179a0 = 0;

    }

  }

  if (iVar6 == 0) {

    if ((_DAT_00d208a4 & 0x80) == 0) {

      _DAT_00d208a4 = _DAT_00d208a4 | 0x80;

      DAT_00d2087c = FUN_00783b60("LogUDP");

    }

    if (*(char *)(DAT_00d2087c + 4) != '\0') {

      DAT_00d179a0 = DAT_00d2087c;

      FUN_00783aa0("%s socket send buffer size set to %d.",param_1,param_4);

      DAT_00d179a0 = 0;

    }

    if (pSVar3[1] != 1) {

      param_5 = param_5 & 0xff;

      iVar6 = setsockopt(*pSVar3,0xffff,0x20,(char *)&param_5,4);

      goto LAB_007859f8;

    }

  }

  else {

    if ((_DAT_00d208a4 & 0x100) == 0) {

      _DAT_00d208a4 = _DAT_00d208a4 | 0x100;

      DAT_00d20878 = FUN_00783b60("LogUDP");

    }

    if (*(char *)(DAT_00d20878 + 4) != '\0') {

      DAT_00d179a0 = DAT_00d20878;

      FUN_00783aa0("%s socket error: unable to set the send buffer size on socket.",param_1);

      DAT_00d179a0 = 0;

    }

LAB_007859f8:

    if (iVar6 != 0) {

      if ((_DAT_00d208a4 & 0x200) == 0) {

        _DAT_00d208a4 = _DAT_00d208a4 | 0x200;

        DAT_00d20870 = FUN_00783b60("LogUDP");

      }

      if (*(char *)(DAT_00d20870 + 4) != '\0') {

        DAT_00d179a0 = DAT_00d20870;

        FUN_00783aa0("%s socket error: unable to set broadcast mode on socket.",param_1);

        DAT_00d179a0 = 0;

      }

      if ((_DAT_00d208a4 & 0x800) == 0) {

        _DAT_00d208a4 = _DAT_00d208a4 | 0x800;

        DAT_00d2086c = FUN_00783b60("LogUDP");

      }

      if (*(char *)(DAT_00d2086c + 4) != '\0') {

        DAT_00d179a0 = DAT_00d2086c;

        FUN_00783aa0("Error prevented successful initialization of %s socket.",param_1);

        DAT_00d179a0 = 0;

      }

      closesocket(*pSVar3);

      *pSVar3 = 0xffffffff;

      goto LAB_00785b8e;

    }

  }

  param_5 = (SOCKET)param_6;

  ioctlsocket(*pSVar3,-0x7ffb9982,&param_5);

  if ((_DAT_00d208a4 & 0x400) == 0) {

    _DAT_00d208a4 = _DAT_00d208a4 | 0x400;

    DAT_00d20874 = FUN_00783b60("LogUDP");

  }

  if (*(char *)(DAT_00d20874 + 4) != '\0') {

    DAT_00d179a0 = DAT_00d20874;

    FUN_00783aa0("%s socket non-blocking IO set.  Socket initialized.",param_1);

    DAT_00d179a0 = 0;

  }

  if (((pSVar3[1] == 1) && (param_2[1] != 0)) && (iVar6 = listen(*pSVar3,5), iVar6 != 0)) {

    if ((_DAT_00d208a4 & 0x1000) == 0) {

      _DAT_00d208a4 = _DAT_00d208a4 | 0x1000;

      DAT_00d20868 = FUN_00783b60("LogUDP");

    }

    if (*(char *)(DAT_00d20868 + 4) != '\0') {

      DAT_00d179a0 = DAT_00d20868;

      FUN_00783aa0("TCP Socket could not start listening: %s, %d.",param_1,iVar6);

      DAT_00d179a0 = 0;

    }

  }

LAB_00785b8e:

  if ((DAT_00d179e4 == 1) && (DAT_00d179e0 != '\0')) {

    if ((_DAT_00d208a4 & 0x2000) == 0) {

      _DAT_00d208a4 = _DAT_00d208a4 | 0x2000;

      _DAT_00d2085c = "Socket::Socket";

      _DAT_00d20860 = 0xffffffff;

      _DAT_00d20864 = DAT_00d17a00;

      DAT_00d17a00 = &DAT_00d2085c;

    }

    FUN_007803f0(&DAT_00d2085c);

    param_5 = *pSVar3;

    BitStream_writeBits(0x20,&param_5);

    FUN_00780060();

  }

  return pSVar3;

}
