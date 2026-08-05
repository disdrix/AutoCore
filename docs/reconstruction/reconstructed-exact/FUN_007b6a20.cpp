// =============================================================================
// FUN_007b6a20  →  NDXml_GetLoaderSingleton
// -----------------------------------------------------------------------------
// Stable ID: aa_007b6a20
// Address:   0x007b6a20–0x007b6a82  (autoassault.exe, image base 0x400000)
// System:    client-xml
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W17-I dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean plate: reconstructed-exact/NDXml_GetLoaderSingleton.cpp
// Dual: reviews/A|B_aa_007b6a20_NDXml_GetLoaderSingleton.md
// =============================================================================

// PURPOSE:
//   Meyers singleton getter — returns process-static NDXml path-loader @ DAT_00d20c38.
//   Init once: vtbl=PTR_FUN_00a95b88, flags(+4)=1, +8/+c=0, atexit(LAB_009c3040).

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_007b6a20(void)
{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b00cb;
  local_c = ExceptionList;
  if ((DAT_00d20c48 & 1) == 0) {
    DAT_00d20c48 = DAT_00d20c48 | 1;
    _DAT_00d20c3c = 1;
    _DAT_00d20c38 = &PTR_FUN_00a95b88;
    _DAT_00d20c40 = 0;
    _DAT_00d20c44 = 0;
    ExceptionList = &local_c;
    _atexit((_func_4879 *)&LAB_009c3040);
  }
  ExceptionList = local_c;
  return &DAT_00d20c38;
}
