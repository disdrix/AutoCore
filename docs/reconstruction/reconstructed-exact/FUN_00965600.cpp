// =============================================================================
// FUN_00965600  (twin of Path_MakeFxcInterned_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00965600
// Address:   0x00965600  (autoassault.exe, image base 0x400000)
// Wave:      W38-AF (2026-08-04) — refined from scaffold
// =============================================================================

#include <cstdint>
#include <string>

extern "C" void* DAT_00d1ed24;
extern "C" char* PTR_DAT_00afa2bc;
extern "C" void* g_StringMgr_00d1eac8;
extern "C" void __fastcall FUN_00989e00_thunk(void* mgr, int, void** out, const char* c);

struct PathCStrField {
  const char* c_str_or_null;
};

extern "C" void** __cdecl FUN_00965600(void** outHandle, PathCStrField* pathObj) {
  const char* pc = pathObj ? pathObj->c_str_or_null : nullptr;
  const char* scan = pc ? pc : PTR_DAT_00afa2bc;
  const char* p = scan;
  while (*p != '\0') {
    ++p;
  }
  if (static_cast<std::size_t>(p - scan) == 0) {
    *outHandle = DAT_00d1ed24;
    return outHandle;
  }
  if (pc == nullptr) {
    pc = PTR_DAT_00afa2bc;
  }
  std::string s(pc);
  const auto pos = s.rfind('.');
  if (pos == std::string::npos) {
    s += ".fxc";
    FUN_00989e00_thunk(g_StringMgr_00d1eac8, 0, outHandle, s.c_str());
  } else {
    std::string stem = s.substr(0, pos);
    stem += ".fxc";
    FUN_00989e00_thunk(g_StringMgr_00d1eac8, 0, outHandle, stem.c_str());
  }
  return outHandle;
}
