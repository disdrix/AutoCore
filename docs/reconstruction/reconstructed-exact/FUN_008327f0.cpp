// Twin plate — Ghidra name. See CMenuChatlog_CompleteDtor.cpp for authoritative clean.
// aa_008327f0 / 0x008327f0 / WQ9J-C 2026-08-05

#include <cstdint>

extern "C" void __fastcall FUN_0082d540(void* self);
extern "C" void* PTR_FUN_00a70524;

extern "C" void __fastcall FUN_008327f0(void* self)
{
  *reinterpret_cast<void**>(self) = &PTR_FUN_00a70524;
  FUN_0082d540(self);
}
