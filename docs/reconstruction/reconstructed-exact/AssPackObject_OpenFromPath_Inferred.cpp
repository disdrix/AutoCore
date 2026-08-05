// =============================================================================
// AssPackObject_OpenFromPath_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0071a9d0
// Address:   0x0071a9d0–0x0071aae4  (277 B / 0x115; autoassault.exe, base 0x400000)
// System:    palantir assets / assPackManager pack open
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-08-04 (W37-X)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Retail ABI: EAX=path, EDI=pack(0x44), stack=AssPackManager* owner, RET 4.
 * - Sole caller FUN_00984ee0 (AssPackManager_OpenPackFile_Inferred) — plate
 *   C:\vog\1_code\palantir\palantir\assets\assPackManager.cpp Opening/FAILED/SUCCESS.
 * - strdup path → pack+0x28; normalize with extension token "glm" @ 0x00aa61bc via FUN_0076b190.
 * - Open mode 1 if pack+0x40 else 3; attributes 0x10000000 into FUN_007669d0 (stoFileOSFile).
 * - If stat ok and st_mode bit15 (MSVC _S_IFREG): dual-open pack and pack+0x14; else mode-6 open.
 * - Size vcall +0x1c; seek +4 to size-4; read 4 @ +0x14; FUN_0071a4a0 parse.
 * - _Inferred structural name; product pack class English open.
 */

#include <cstdint>
#include <cstring>

struct AssPackObject {
  void** vtbl;          // +0
  // file state used by FUN_007669d0 at +4/+8 ...
  uint8_t file_a[0x14]; // primary file-ish span to +0x14
  // secondary file object at +0x14
  uint8_t file_b[0x14];
  // ...
  // +0x28: char* path (strdup)
  // +0x40: char open-mode flag
};

extern "C" char* _strdup(const char* s);
extern "C" int stat(const char* path, void* st);
extern "C" void FUN_0076b190(/* path normalize; ESI ext "glm" */);
extern "C" int __thiscall FUN_007669d0(void* file_obj /*ECX*/, const char* path,
                                       uint32_t mode, uint32_t flags);
extern "C" int FUN_0071a4a0(/* pack, owner/footer, size — unowned */);

// Retail register formals; not a clean cdecl.
extern "C" int AssPackObject_OpenFromPath_Inferred(
    /*EAX*/ const char* path,
    /*EDI*/ AssPackObject* pack,
    /*stack*/ void* owner /*AssPackManager**/)
{
  (void)owner;

  char* owned = _strdup(path);
  *reinterpret_cast<char**>(reinterpret_cast<uint8_t*>(pack) + 0x28) = owned;

  // FUN_0076b190 builds path into local buffer with ext "glm"
  FUN_0076b190();

  uint32_t mode = 3;
  if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(pack) + 0x40) != 0) {
    mode = 1;
  }

  char path_buf[248];
  uint8_t st[32];
  // path_buf filled by FUN_0076b190 in retail
  int rc = stat(path_buf, st);
  // st_mode at +6 as MSVC _stat32; bit15 = _S_IFREG
  uint32_t mode_dword = *reinterpret_cast<uint32_t*>(st + 6);
  if (rc == 0 && ((mode_dword >> 15) & 1) != 0) {
    rc = FUN_007669d0(pack, path_buf, mode, 0x10000000);
    if (rc != 0) {
      return -1;
    }
    rc = FUN_007669d0(reinterpret_cast<uint8_t*>(pack) + 0x14, path_buf, mode, 0x10000000);
  } else {
    rc = FUN_007669d0(pack, path_buf, 6, 0x10000000);
  }

  if (rc != 0) {
    return -1;
  }

  using VFn = int(__thiscall*)(void*, ...);
  void** vt = pack->vtbl;
  int size = reinterpret_cast<int(__thiscall*)(void*)>(vt[0x1c / 4])(pack);
  if (size == 0) {
    return 0;
  }
  if (size == -1) {
    return -1;
  }

  int seek_rc = reinterpret_cast<int(__thiscall*)(void*, int, int)>(vt[1])(pack, size - 4, 0);
  if (seek_rc != 0) {
    return -1;
  }

  uint32_t footer = 0xFFFFFFFF;
  int read_rc =
      reinterpret_cast<int(__thiscall*)(void*, void*, int)>(vt[0x14 / 4])(pack, &footer, 4);
  if (read_rc != 0) {
    return -1;
  }

  return FUN_0071a4a0(/*pack, owner, size — exact arg map unowned*/);
}
