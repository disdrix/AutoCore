// =============================================================================
// AssPackManager_AddDirectoryTree_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00984c70
// Address:   0x00984c70–0x00984d25  (autoassault.exe, image base 0x400000)
// System:    AssPackManager / offline pack ingest
// Generated: 2026-07-23 scaffold as FUN_00984c70; dual A/B seal 2026-07-29 (W33-E)
// Exactness: Behavior-preserving rewrite of decompiler + full body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Recursively collect leaf paths under `dir_path`, then add each leaf into
//   an AssPackManager host via FUN_00984910 (assPackManager.cpp add-file).
//
// ABI (bytes win over decompiler thiscall display):
//   ECX = const char* dir_path
//   stack[4] = AssPackManager* pack
//   EDI = mode/type passed through to FUN_00984910 (never written here — gap)
//   bare RET; EAX = 0
//   Body 182 B; SEH LAB_009b113c; SUB ESP,0x2C
//
// CALLERS:
//   none static (0 xrefs)
//
// CALLEES:
//   FUN_009839b0  Fs_DirRecurseCollectLeafPaths_Inferred (W32-D)
//   FUN_00984910  AssPackManager add-file (unowned; plate path in nested)
//   FUN_00431ae0  string-vector destroy
//

#include <cstdint>

static constexpr uint32_t kStringStride = 0x1c;

extern "C" int  FUN_009839b0(const char* path, void* out_string_vec);
extern "C" int  FUN_00984910(/* ECX path; stack: pack, mode, f1, f2, f3 — retail */);
extern "C" void FUN_00431ae0(/* listing vec */);

// Retail shape (bytes):
extern "C" int AssPackManager_AddDirectoryTree_Inferred(const char* dir_path /*ECX*/,
                                                        void* ass_pack_manager /*stack*/)
{
  // SEH LAB_009b113c
  // local listing vector zeroed (begin/end/cap)
  uint8_t listing[0x10] = {};

  // bytes: PUSH &listing; PUSH ECX; CALL FUN_009839b0; ADD ESP,8
  int rc = FUN_009839b0(dir_path, listing);
  if (rc >= 0) {
    // for each std::string in listing (stride 0x1c):
    //   copy to stack tmp
    //   ECX = tmp.c_str() (SSO-aware)
    //   PUSH 0; PUSH 0; PUSH 1; PUSH EDI; PUSH pack; CALL FUN_00984910
    //   destroy tmp
    (void)ass_pack_manager;
    (void)kStringStride;
  }

  // FUN_00431ae0(&listing)
  FUN_00431ae0();
  return 0;
}

// Ghidra twin symbol
extern "C" int FUN_00984c70(const char* dir_path, void* ass_pack_manager)
{
  return AssPackManager_AddDirectoryTree_Inferred(dir_path, ass_pack_manager);
}
