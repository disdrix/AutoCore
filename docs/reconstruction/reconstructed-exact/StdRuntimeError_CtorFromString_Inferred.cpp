// =============================================================================
// StdRuntimeError_CtorFromString_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00685b40
// Address:   0x00685b40–0x00685b93  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00685b40
// System:    MSVC exception hierarchy (runtime_error-layout base)
// Dual:      W37-B 2026-08-04
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: __thiscall; ECX=this; stack const basic_string*; RET 0x4; returns this.
// 1) exception::exception(this)
// 2) *this = PTR_FUN_009ea778  (vtbl[0]=scalar dtor 00685c00, vtbl[1]=what 004018e0)
// 3) basic_string copy-ctor at this+0x0c from arg
// Sole caller: IdvFileError_Ctor_MsgBracketErrno (006874b0, W34-B) before final vtbl.
// Name Inferred: catchable chain IdvFileError→runtime_error→exception + layout;
//   COL not independently sealed on 009ea778 this pass.
// Reject scaffold Named_CalleeOf_* plate.
// =============================================================================

#include <cstdint>

// IAT / CRT
extern "C" void* __thiscall exception_ctor(void* self /*ECX*/);
extern "C" void* __thiscall basic_string_copy_ctor(void* self /*ECX*/, const void* other /*stack*/);
extern void* ExceptionList;
extern uint8_t LAB_009a9fd9;
// Intermediate vtbl: { FUN_00685c00, 0x004018e0 }
extern void* PTR_FUN_009ea778;

// Object layout (runtime_error-like intermediate; full IdvFileError size 0x28):
//   +0x00 void** vtbl
//   +0x04..+0x0b exception subobject tail
//   +0x0c basic_string message (MSVC SSO shell)

extern "C" void* __thiscall StdRuntimeError_CtorFromString_Inferred(
    void* self /*ECX*/,
    const void* msg /*stack basic_string**/)
{
  void* local_c;
  uint8_t* puStack_8;
  uint32_t local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9fd9;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  exception_ctor(self);
  local_4 = 0;
  *reinterpret_cast<void***>(self) = &PTR_FUN_009ea778;
  basic_string_copy_ctor(reinterpret_cast<uint8_t*>(self) + 0x0c, msg);

  ExceptionList = local_c;
  return self;  // ret 4
}

extern "C" void* __thiscall FUN_00685b40(
    void* self /*ECX*/,
    const void* msg /*stack*/)
{
  return StdRuntimeError_CtorFromString_Inferred(self, msg);
}
