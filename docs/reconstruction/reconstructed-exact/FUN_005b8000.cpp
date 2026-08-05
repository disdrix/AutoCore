// =============================================================================
// FUN_005b8000  (Ghidra twin of Elem0x28_CompleteDtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b8000
// Address:   0x005b8000–0x005b810b  (267 B / 0x10B)
// W29-F:     2026-07-29 dual A/B sealed — see Elem0x28_CompleteDtor.cpp
// =============================================================================

#include <cstdint>

extern "C" void __thiscall Elem0x28_CompleteDtor(void* elem);
extern "C" void __thiscall FUN_004be2a0(void* owned);
extern "C" void operator_delete(void* p);

extern "C" void __thiscall FUN_005b8000(void* param_1)
{
  Elem0x28_CompleteDtor(param_1);
}

// Scaffold CF order (authoritative high-level; Ghidra may warn false-noreturn):
//   if (owned@+0x24) { FUN_004be2a0(owned); operator_delete(owned); } zero +0x24
//   for each list ptr in [+0x14,+0x18): free node payloads; empty list; free head
//   free +0x14 vector; zero triple; free +0x4 buffer; zero triple
