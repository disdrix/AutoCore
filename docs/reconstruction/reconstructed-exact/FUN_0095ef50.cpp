// =============================================================================
// FUN_0095ef50
// -----------------------------------------------------------------------------
// Stable ID: aa_0095ef50
// Address:   0x0095ef50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095ef50 @ 0x0095ef50
// Stable ID: aa_0095ef50
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp"
//   - "Invalid TAG unserializing gfxGeometryPiece"
//   - "Invalid chunk version unserializing gfxGeometryPiece"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~220 non-empty decompiler lines.
//  - Control keywords: if×12, return×3, switch×1, goto×1.
//  - Notable callees: FUN_00439a00×14, FUN_00436900×7, FUN_009a0000×7, FUN_009a00d0×7, effEffect_Unserialize×7, FUN_0074ce60×6, FUN_00769e40×3, CONCAT31×2.
//  - Strings: ",0x5fa,

                   3,"; ",0x6da,

                   3,".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __fastcall FUN_0095ef50(int param_1)



{

  int *piVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ uVar2;

  bool bVar3;

  int local_5c [3];

  char local_50;

  int local_4c;

  uint32_t /* width from decompiler */ local_48;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [4];

  uint32_t /* width from decompiler */ **local_40 [5];

  uint local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [4];

  uint32_t /* width from decompiler */ **local_24 [5];

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3c0f;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_1);

  local_4 = 0;

  if (local_4c != 0x47504345) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",0x5fa,

                   3,"Invalid TAG unserializing gfxGeometryPiece");

    local_4 = 0xffffffff;

    if (local_50 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  switch(local_48) {

  case 1:

    unaff_ESI[0x23] = 0;

    FUN_00439a00();

    unaff_ESI[0x2a] = local_5c[0];

    FUN_00436900();

    piVar1 = unaff_ESI + 8;

    unaff_ESI[0x2b] = local_5c[0];

    unaff_ESI[0x2c] = 0;

    effEffect_Unserialize(piVar1,param_1);

    FUN_009a00d0(unaff_ESI + 2,param_1,piVar1);

    unaff_ESI[0x2f] = unaff_ESI[0x2f] | 1;

    FUN_009a0000(unaff_ESI + 4,param_1,piVar1,unaff_ESI + 2);

    (**(code **)(*unaff_ESI + 0x5c))();

    (**(code **)(*unaff_ESI + 100))();

    uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c);

    bVar3 = local_50 == '\0';

    break;

  case 2:

    unaff_ESI[0x23] = 0;

    FUN_00439a00();

    unaff_ESI[0x2a] = local_5c[0];

    FUN_00436900();

    unaff_ESI[0x2b] = local_5c[0];

    unaff_ESI[0x2c] = 0;

    FUN_0074ce60();

    if ((char)unaff_ESI[0x15] != '\0') {

      unaff_ESI[0x2f] = unaff_ESI[0x2f] | 1;

    }

    piVar1 = unaff_ESI + 8;

    effEffect_Unserialize(piVar1,param_1);

    FUN_009a00d0(unaff_ESI + 2,param_1,piVar1);

    unaff_ESI[0x2f] = unaff_ESI[0x2f] | 1;

    FUN_009a0000(unaff_ESI + 4,param_1,piVar1,unaff_ESI + 2);

    (**(code **)(*unaff_ESI + 100))();

    uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c);

    bVar3 = local_50 == '\0';

    break;

  case 3:

    FUN_00439a00();

    unaff_ESI[0x23] = 0;

    FUN_00439a00();

    unaff_ESI[0x2a] = local_5c[0];

    FUN_00436900();

    unaff_ESI[0x2c] = 0;

    unaff_ESI[0x2b] = local_5c[0];

    FUN_0074ce60();

    if ((char)unaff_ESI[0x15] != '\0') {

      unaff_ESI[0x2f] = unaff_ESI[0x2f] | 1;

    }

    piVar1 = unaff_ESI + 8;

    effEffect_Unserialize(piVar1,param_1);

    FUN_009a00d0(unaff_ESI + 2,param_1,piVar1);

    unaff_ESI[0x2f] = unaff_ESI[0x2f] | 1;

    FUN_009a0000(unaff_ESI + 4,param_1,piVar1,unaff_ESI + 2);

    (**(code **)(*unaff_ESI + 100))();

    uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c);

    bVar3 = local_50 == '\0';

    break;

  case 4:

    FUN_00439a00();

    unaff_ESI[0x23] = local_5c[0];

    FUN_00439a00();

    FUN_00439a00();

    unaff_ESI[0x2a] = local_5c[0];

    FUN_00436900();

    unaff_ESI[0x2c] = 0;

    unaff_ESI[0x2b] = local_5c[0];

    FUN_0074ce60();

    if ((char)unaff_ESI[0x15] != '\0') {

      unaff_ESI[0x2f] = unaff_ESI[0x2f] | 1;

    }

    piVar1 = unaff_ESI + 8;

    effEffect_Unserialize(piVar1,param_1);

    FUN_009a00d0(unaff_ESI + 2,param_1,piVar1);

    unaff_ESI[0x2f] = unaff_ESI[0x2f] | 1;

    FUN_009a0000(unaff_ESI + 4,param_1,piVar1,unaff_ESI + 2);

    (**(code **)(*unaff_ESI + 100))();

    uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c);

    bVar3 = local_50 == '\0';

    break;

  case 5:

    FUN_00439a00();

    unaff_ESI[0x23] = local_5c[0];

    FUN_00439a00();

    unaff_ESI[0x2a] = local_5c[0];

    FUN_00436900();

    unaff_ESI[0x2c] = 0;

    unaff_ESI[0x2b] = local_5c[0];

    FUN_0074ce60();

    if ((char)unaff_ESI[0x15] != '\0') {

      unaff_ESI[0x2f] = unaff_ESI[0x2f] | 1;

    }

    piVar1 = unaff_ESI + 8;

    effEffect_Unserialize(piVar1,param_1);

    FUN_009a00d0(unaff_ESI + 2,param_1,piVar1);

    unaff_ESI[0x2f] = unaff_ESI[0x2f] | 1;

    FUN_009a0000(unaff_ESI + 4,param_1,piVar1,unaff_ESI + 2);

    (**(code **)(*unaff_ESI + 100))();

    uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c);

    bVar3 = local_50 == '\0';

    break;

  case 6:

    FUN_00439a00();

    unaff_ESI[0x23] = local_5c[0];

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

    local_4 = CONCAT31(local_4._1_3_,1);

    FUN_00439a20(param_1);

    if (local_2c < 0x10) {

      local_40[0] = local_40;

    }

    FUN_00989e00(local_5c,local_40[0]);

    unaff_ESI[0x24] = local_5c[0];

    FUN_00439a00();

    unaff_ESI[0x2a] = local_5c[0];

    FUN_00436900();

    unaff_ESI[0x2b] = local_5c[0];

    unaff_ESI[0x2c] = 0;

    FUN_0074ce60();

    if ((char)unaff_ESI[0x15] != '\0') {

      unaff_ESI[0x2f] = unaff_ESI[0x2f] | 1;

    }

    piVar1 = unaff_ESI + 8;

    effEffect_Unserialize(piVar1,param_1);

    FUN_009a00d0(unaff_ESI + 2,param_1,piVar1);

    unaff_ESI[0x2f] = unaff_ESI[0x2f] | 1;

    FUN_009a0000(unaff_ESI + 4,param_1,piVar1,unaff_ESI + 2);

    (**(code **)(*unaff_ESI + 100))();

    this = local_44;

    goto LAB_0095f4cd;

  case 7:

    FUN_00439a00();

    unaff_ESI[0x23] = local_5c[0];

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

    local_4 = CONCAT31(local_4._1_3_,2);

    FUN_00439a20(param_1);

    if (local_10 < 0x10) {

      local_24[0] = local_24;

    }

    FUN_00989e00(local_5c,local_24[0]);

    unaff_ESI[0x24] = local_5c[0];

    FUN_00439a00();

    unaff_ESI[0x2a] = local_5c[0];

    FUN_00436900();

    unaff_ESI[0x2b] = local_5c[0];

    FUN_00439a00();

    unaff_ESI[0x2c] = local_5c[0];

    FUN_0074ce60();

    if ((char)unaff_ESI[0x15] != '\0') {

      unaff_ESI[0x2f] = unaff_ESI[0x2f] | 1;

    }

    piVar1 = unaff_ESI + 8;

    effEffect_Unserialize(piVar1,param_1);

    FUN_009a00d0(unaff_ESI + 2,param_1,piVar1);

    unaff_ESI[0x2f] = unaff_ESI[0x2f] | 1;

    FUN_009a0000(unaff_ESI + 4,param_1,piVar1,unaff_ESI + 2);

    (**(code **)(*unaff_ESI + 100))();

    this = local_28;

LAB_0095f4cd:

    uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c);

    local_4 = local_4 & 0xffffff00;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(this);

    bVar3 = local_50 == '\0';

    break;

  default:

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",0x6da,

                   3,"Invalid chunk version unserializing gfxGeometryPiece");

    local_4 = 0xffffffff;

    if (local_50 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  local_4 = 0xffffffff;

  if (!bVar3) {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return uVar2;

}
