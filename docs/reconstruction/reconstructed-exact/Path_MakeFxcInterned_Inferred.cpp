// =============================================================================
// Path_MakeFxcInterned_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00965600
// Address:   0x00965600  (autoassault.exe, image base 0x400000)
// System:    Client effects / path → interned .fxc string handle
// Wave:      W38-AF dual A/B (2026-08-04)
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Read c_str from a path object; if empty, store shared empty handle
//   DAT_00d1ed24. Otherwise build a temporary std::string, strip the last
//   '.' extension (or append if none), force extension ".fxc", and intern
//   via FUN_00989e00 on global string manager 0x00d1eac8 into *out.
//
// ABI: __cdecl  (outHandle*, pathObj*) -> outHandle*   // caller ADD ESP,8
//
// Reject: Named_CalleeOf_Named_effDeviceEffect_00965600
// =============================================================================

#include <cstdint>
#include <cstring>
#include <string>

// Unowned / external
extern "C" void* DAT_00d1ed24;                 // empty string handle
extern "C" char* PTR_DAT_00afa2bc;             // points at ""
extern "C" void* g_StringMgr_00d1eac8;         // global at 0x00d1eac8
// thiscall: ECX = mgr, stack (outHandle*, const char* c_str)
extern "C" void __fastcall FUN_00989e00_thunk(void* mgr, int /*edx unused*/,
                                              void** outHandle, const char* c_str);

// Portable stand-in for the thiscall intern helper used by the body.
static inline void StringMgr_Intern(void** outHandle, const char* c_str) {
  // Machine: mov ecx, 0x00d1eac8; push c_str; push out; call FUN_00989e00
  FUN_00989e00_thunk(g_StringMgr_00d1eac8, 0, outHandle, c_str);
}

// pathObj: object whose first pointer-sized field is a C string (or null).
struct PathCStrField {
  const char* c_str_or_null;
};

extern "C" void** __cdecl Path_MakeFxcInterned_Inferred(void** outHandle,
                                                        PathCStrField* pathObj) {
  const char* pc = pathObj ? pathObj->c_str_or_null : nullptr;
  const char* scan = pc ? pc : PTR_DAT_00afa2bc;

  // strlen (decompiler strlen-from-pointer loop)
  const char* p = scan;
  while (*p != '\0') {
    ++p;
  }
  const size_t len = static_cast<size_t>(p - scan);

  if (len == 0) {
    *outHandle = DAT_00d1ed24;
    return outHandle;
  }

  if (pc == nullptr) {
    pc = PTR_DAT_00afa2bc;
  }

  std::string s(pc);
  const size_t pos = s.rfind('.');
  if (pos == std::string::npos) {
    s += ".fxc";
    StringMgr_Intern(outHandle, s.c_str());
  } else {
    std::string stem = s.substr(0, pos);
    stem += ".fxc";
    StringMgr_Intern(outHandle, stem.c_str());
  }
  return outHandle;
}

// Ghidra twin name
extern "C" void** __cdecl FUN_00965600(void** outHandle, PathCStrField* pathObj) {
  return Path_MakeFxcInterned_Inferred(outHandle, pathObj);
}
