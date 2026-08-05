// =============================================================================
// FUN_0074ff30
// -----------------------------------------------------------------------------
// Stable ID: aa_0074ff30
// Address:   0x0074ff30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074ff30 @ 0x0074ff30
// Stable ID: aa_0074ff30
// Embedded strings (evidence for future rename):
//   - "Failed to load the file %s"
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: block×8, stoChunkWriter_BeginChunk×2, stoChunkWriter_EndChunk×2, CONCAT11, CONCAT31, D3DXCreateEffectCompiler, FUN_00439810, FUN_0043b9e0.
//  - Strings: "Failed to load the file %s".
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

/* WARNING: Removing unreachable block (ram,0x007501a0) */

/* WARNING: Removing unreachable block (ram,0x007501be) */

/* WARNING: Removing unreachable block (ram,0x007501b9) */

/* WARNING: Removing unreachable block (ram,0x007501c1) */

/* WARNING: Removing unreachable block (ram,0x00750207) */

/* WARNING: Removing unreachable block (ram,0x0075020d) */

/* WARNING: Removing unreachable block (ram,0x00750215) */

/* WARNING: Removing unreachable block (ram,0x0075021e) */



uint32_t /* width from decompiler */ __thiscall FUN_0074ff30(int *param_1,int *param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint16_t uVar4;

  void *pvVar5;

  int *unaff_retaddr;

  int *piStack_58;

  undefined **ppuStack_54;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbStack_50;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbStack_4c;

  void *pvStack_44;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_38 [4];

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  void *pvStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b128c;

  pvStack_c = ExceptionList;

  uVar4 = CONCAT11(1,-(*(char *)(DAT_00d1f044 + 0x778) != '\x01') & 5);

  ExceptionList = &pvStack_c;

  uVar2 = (**(code **)(*param_1 + 0x1c))();

  piStack_58 = (int *)((uint)piStack_58 & 0xffffff);

  FUN_00445b80();

  uStack_4 = 0;

  iVar3 = (**(code **)(*param_1 + 0x14))();

  if (iVar3 < 0) {

    FUN_0096a630();

    pvStack_c._0_1_ = 1;

    uVar2 = FUN_0076cec0(&uStack_4,"Failed to load the file %s");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp",

                   0x37d,2,uVar2);

    pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(abStack_38);

    FUN_00691630();

    ExceptionList = pvStack_14;

    return 0xffffffff;

  }

  pbStack_50 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &stack0xffffff8c;

  piStack_58 = (int *)0x0;

  FUN_00445ae0();

  pvVar5 = pvStack_44;

  piVar1 = param_2;

  ppuStack_54 = &PTR_LAB_00a9fa84;

  iVar3 = D3DXCreateEffectCompiler(pvStack_44,uVar2,param_2[1],&ppuStack_54,uVar4,&piStack_58);

  if (-1 < iVar3) {

    param_2 = (int *)0x0;

    iVar3 = (**(code **)(*piStack_58 + 0xec))(piStack_58,uVar4,&param_2);

    if (-1 < iVar3) {

      uStack_34 = 0;

      uStack_2c = 0;

      uStack_28 = 0;

      uStack_24 = 0;

      uStack_20 = 0;

      pvStack_c._0_1_ = 2;

      uStack_1c = 0;

      uStack_18 = 0;

      FUN_007670a0();

      pbStack_50 = abStack_38;

      pvStack_c._0_1_ = 3;

      stoChunkWriter_BeginChunk(0x43504658);

      pvStack_c._0_1_ = 4;

      FUN_0043b9e0();

      FUN_0073e130(DAT_00d1f61c,abStack_38,piVar1);

      pbStack_4c = abStack_38;

      stoChunkWriter_BeginChunk(0x42494658);

      pvStack_c._0_1_ = 5;

      uStack_4 = (**(code **)(*param_2 + 0x10))();

      FUN_00439810();

      (**(code **)(*unaff_retaddr + 0xc))(unaff_retaddr);

      FUN_00447bb0();

      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);

      stoChunkWriter_EndChunk();

      if (param_2 != (int *)0x0) {

        (**(code **)(*param_2 + 8))();

      }

      param_2 = (int *)0x0;

      pvStack_c._0_1_ = 3;

      stoChunkWriter_EndChunk();

      pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);

      FUN_005b2ba0();

      pvVar5 = pvStack_44;

    }

    if (piStack_58 != (int *)0x0) {

      (**(code **)(*piStack_58 + 8))();

    }

    piStack_58 = (int *)0x0;

  }

  if (pvVar5 == (void *)0x0) {

    ExceptionList = pvStack_14;

    return 0;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar5);

}
