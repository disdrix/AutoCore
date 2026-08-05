// =============================================================================
// BasicString_UninitializedFillN
// -----------------------------------------------------------------------------
// Stable ID: aa_00431700
// Address:   0x00431700–0x0043178c exclusive  (140 B / 0x8C; autoassault.exe base 0x400000)
// System:    MSVC-style uninit_fill_n / construct-n for basic_string (stride 0x1c)
// Generated: 2026-07-23 scaffold as FUN_00431700; dual A/B seal 2026-07-29 (W34-H)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes/IAT.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Construct `count` copies of a basic_string value into uninitialized storage
//   starting at `dest`, advancing by 0x1c each element. SEH-protected: on throw,
//   destroy the already-constructed prefix and rethrow.
//
// ABI (bytes + call-site):
//   cdecl (bare C3). Call sites push five dwords and ADD ESP,0x14:
//     dest*, count, value*, alloc*, value* (echo).
//   Body only consumes dest/count/value; 4th/5th unused.
//
// CALLERS:
//   StringVec_PushBack (FUN_004301f0) — fast path construct-1.
//   StdUninitFillN_BasicString (FUN_00430390) — thiscall wrapper rebind.
//
// REJECT: scaffold Named_CalleeOf_*VOG_DEBUG*; invent demangle English as sealed.
//

#include <cstdint>

struct BasicString_0x1c {
  uint8_t storage[0x1c];
};

static constexpr uint32_t kElemSize = 0x1c;

// IAT [0x009c62ec] → 0x006ead80
extern "C" void __thiscall basic_string_copy_ctor(BasicString_0x1c* self,
                                                  const BasicString_0x1c* other);
// IAT [0x009c62f4] → 0x006eace6 (EH only)
extern "C" void __thiscall basic_string_dtor(BasicString_0x1c* self);
// 0x006a3d60 — EH rethrow path
extern "C" void __stdcall _CxxThrowException(void* exceptionObject, void* throwInfo);

// Retail cdecl; callers may pass 5 stack args; body uses first 3.
extern "C" void BasicString_UninitializedFillN(
    BasicString_0x1c* dest,
    int count,
    const BasicString_0x1c* value
    /* optional unused: void* alloc, const BasicString_0x1c* value_echo */)
{
  // SEH frame LAB_009bc2c1
  // Happy path (matches decompile):
  for (; count != 0; --count) {
    if (dest != nullptr) {
      basic_string_copy_ctor(dest, value);
    }
    dest = reinterpret_cast<BasicString_0x1c*>(
        reinterpret_cast<char*>(dest) + kElemSize);
  }
  // EH residual (bytes; not on normal return):
  //   for (p = start; p != cur; p += 0x1c) basic_string_dtor(p);
  //   _CxxThrowException(nullptr, nullptr);
}

// Ghidra twin symbol
extern "C" void FUN_00431700(BasicString_0x1c* dest, int count,
                             const BasicString_0x1c* value, void* /*alloc*/,
                             const BasicString_0x1c* /*value_echo*/)
{
  BasicString_UninitializedFillN(dest, count, value);
}
