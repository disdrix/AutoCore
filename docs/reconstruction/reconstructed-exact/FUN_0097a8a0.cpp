// Twin plate — Ghidra name. See CWndTutorial_CompleteDtor.cpp for authoritative clean.
// aa_0097a8a0 / 0x0097a8a0 / WQ9J-C 2026-08-05

#include <cstdint>

extern "C" void __fastcall FUN_00792c20(void* self);
extern "C" void* PTR_FUN_00a6f61c;

extern "C" void __fastcall FUN_0097a8a0(void* self)
{
  *reinterpret_cast<void**>(self) = &PTR_FUN_00a6f61c;
  FUN_00792c20(self);
}
