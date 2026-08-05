// =============================================================================
// NDXml_GetLoaderSingleton  (was FUN_007b6a20)
// -----------------------------------------------------------------------------
// Stable ID: aa_007b6a20
// Address:   0x007b6a20–0x007b6a82  (autoassault.exe, image base 0x400000)
// System:    client-xml / NDXml path-loader singleton
// Generated: 2026-07-29 W17-I dual A/B seal (decompile + read_memory + callers)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual: reviews/A|B_aa_007b6a20_NDXml_GetLoaderSingleton.md
// =============================================================================
//
// PURPOSE:
//   Meyers singleton getter for the process-static NDXml path-loader object at
//   DAT_00d20c38. First call constructs: vtable PTR_FUN_00a95b88, flags=1
//   (search-path bit for NDXml_LoadDocumentFromPath), +8/+c zero, atexit dtor.
//   Always returns &DAT_00d20c38.
//
// NAME: NDXml_GetLoaderSingleton — sealed from primary consumer chain
//   NDXml_OpenTaggedDocument → this unit → NDXml_LoadDocumentFromPath(this,...).
// =============================================================================

// External
// void _atexit(void (*fn)(void));
// void LAB_009c3040(void);                 // static dtor thunk @ 0x009c3040
// void * const PTR_FUN_00a95b88;           // vtable @ 0x00a95b88
// uint32_t DAT_00d20c48;                   // once-init guard (bit 0)
// // static object storage:
// //   DAT_00d20c38 vtbl, DAT_00d20c3c flags, DAT_00d20c40, DAT_00d20c44

void *NDXml_GetLoaderSingleton(void)
{
  // SEH locals elided for readability; retail installs FS:[0] frame before once-test.

  if ((DAT_00d20c48 & 1) == 0) {
    DAT_00d20c48 = DAT_00d20c48 | 1;
    DAT_00d20c3c = 1;                          // this+0x04 flags
    DAT_00d20c38 = (void *)&PTR_FUN_00a95b88;   // this+0x00 vtbl
    DAT_00d20c40 = 0;                          // this+0x08
    DAT_00d20c44 = 0;                          // this+0x0c
    _atexit((void (*)(void))&LAB_009c3040);
  }

  return (void *)&DAT_00d20c38;
}
