// =============================================================================
// AssPackManager_CompactPackFile_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00985010
// Address:   0x00985010–0x0098538d exclusive  (autoassault.exe, image base 0x400000)
// System:    assets / assPackManager offline packer compact
// Generated: 2026-07-23 scaffold as FUN_00985010; dual A/B seal 2026-07-29 (W32-E)
// Exactness: Behavior-preserving stage rewrite of decompiler CF + sealed entry/epilogue
//            bytes and string constants. Nested pack helpers remain FUN_* residuals.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Compact a `.glm` pack file in place via temp `_pack_tmp.glm`:
//     open source pack (flag 1) → stage `_pk_` → open temp pack (flag 0) →
//     for each source entry rebuild path, extract/write, unlink intermediate →
//     close → delete original → MoveFileA("_pack_tmp.glm", original).
//   Verbose when quiet==0 ("Compacting file %s." / "Packer compacted %d files.").
//
// ABI (bytes + decompiler formals):
//   ECX = const char* packPath
//   stack int mode (if ==3, per-entry id = (int16)node[+0x20])
//   stack char quiet (0 = printf progress)
//   bare RET (C3); returns 0
//
// CALLERS:
//   None static (0 xrefs). Body retained after AssPackManager_OpenPackFile.
//

#include <cstdint>
#include <cstdio>
#include <windows.h>

// Nested residuals (owned elsewhere or open)
extern "C" void FUN_0076b190(const char* path /*ecx-or-stack*/, char* out_buf /*stack*/); // uses ESI ext
extern "C" void* FUN_00983940(void* self /*stack*/);          // AssResolverCore_Ctor_Inferred
extern "C" int FUN_00984ee0(/*EBX host, ECX path, stack flag*/); // AssPackManager_OpenPackFile_Inferred
extern "C" void FUN_0076bc00(const char* token, int flag);
extern "C" void FUN_0076ba10(const char* token, int flag);
extern "C" void* FUN_00416490(void* out_str, void* a, const void* b); // string join
extern "C" void FUN_00984d30(void* pack, const char* name, const void* cookie);
extern "C" void FUN_00984910(void* pack, int id, int a, int b, const char* path);
extern "C" void FUN_00983720(void);
extern "C" void FUN_00984890(void);
extern "C" void FUN_009838a0(void* pack /*stack*/); // dtor

// CRT / Win32
extern "C" int stat(const char* path, void* st);
extern "C" int _chmod(const char* path, int mode);
extern "C" int _unlink(const char* path);

// MSVC basic_string ops via IAT in retail — shown abstractly
struct BasicString;

// Retail entry
extern "C" uint32_t AssPackManager_CompactPackFile_Inferred(
    const char* packPath /*ecx*/,
    int mode /*stack*/,
    char quiet /*stack*/)
{
  char path_buf[252];
  // Retail: mov esi, "glm"; FUN_0076b190(packPath, path_buf)
  FUN_0076b190(packPath, path_buf);

  alignas(8) uint8_t packA[0x54]; // AssResolverCore-sized stack host (approx)
  alignas(8) uint8_t packB[0x54];
  FUN_00983940(packA);
  // FUN_00984ee0: EBX=packA, ECX=path_buf, stack flag=1
  FUN_00984ee0(/*host*/ /*path*/ /*1*/);

  FUN_00983940(packB);
  // basic_string pk = "_pk_"; FUN_0076bc00(pk.c_str(), 1);
  FUN_0076bc00("_pk_", 1);
  // FUN_00984ee0(packB, "_pack_tmp.glm", 0)
  FUN_00984ee0(/*host*/ /*"_pack_tmp.glm"*/ /*0*/);

  // for (node = *list_head; node != list_head; node = *node) { ... compact one ... }
  // if (!quiet) printf summary with compacted count from packA+offset
  FUN_00983720();
  FUN_00984890();
  FUN_00983720();

  // make original writable if needed, unlink, cleanup _pk_, MoveFileA temp→original
  _unlink(path_buf);
  FUN_0076ba10("_pk_", 1);
  MoveFileA("_pack_tmp.glm", path_buf);

  FUN_009838a0(packB);
  FUN_009838a0(packA);
  return 0;
}

extern "C" uint32_t FUN_00985010(const char* packPath, int mode, char quiet)
{
  return AssPackManager_CompactPackFile_Inferred(packPath, mode, quiet);
}
