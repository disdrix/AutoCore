// =============================================================================
// Elem0x28_DefaultCtor
// -----------------------------------------------------------------------------
// Stable ID: aa_005b7db0
// Address:   0x005b7db0–0x005b7dee exclusive (62 B / 0x3E, autoassault.exe base 0x400000)
// System:    class / cookie-vector element default ctor (stride 0x28)
// Generated: 2026-07-29 W31-L dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + body bytes seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_005b7db0
// =============================================================================
//
// PURPOSE:
//   Element default constructor for 0x28-byte cookie-vector elements. Registered
//   as the per-element ctor for _eh_vector_constructor_iterator_ from
//   Host_RebuildElem0x28ArrayFromMap_Inferred (FUN_004941b0 @ 0x004942db):
//     eh_vector_ctor_iter(storage, 0x28, count, FUN_005b7db0, FUN_005b8000)
//
//   Zeros the same fields Elem0x28_CompleteDtor (0x005b8000, W29-F) later frees:
//     buffer triple @ +0x4/+0x8/+0xc
//     list-ptr vector triple @ +0x14/+0x18/+0x1c
//     owned pointer @ +0x24
//   Does NOT write +0, +0x10, or +0x20.
//
// ABI:
//   __thiscall; ECX=element; no stack formals; bare RET; void.
//   SEH: LAB_009a6ad8 (install/teardown only; no throw in body).
//
// NOTE:
//   Reject scaffold Named_CalleeOf_Named_VOG_DEBUG_STOP_005b7db0 — sole xref is
//   DATA registration from host rebuild, not VOG_DEBUG_STOP semantics.
// =============================================================================

#include <cstdint>

// Machine: void __thiscall FUN_005b7db0(void* elem)
extern "C" void __thiscall Elem0x28_DefaultCtor(void* elem)
{
  auto* e = reinterpret_cast<uint8_t*>(elem);

  *reinterpret_cast<uint32_t*>(e + 0x04) = 0;
  *reinterpret_cast<uint32_t*>(e + 0x08) = 0;
  *reinterpret_cast<uint32_t*>(e + 0x0c) = 0;
  *reinterpret_cast<uint32_t*>(e + 0x14) = 0;
  *reinterpret_cast<uint32_t*>(e + 0x18) = 0;
  *reinterpret_cast<uint32_t*>(e + 0x1c) = 0;
  *reinterpret_cast<uint32_t*>(e + 0x24) = 0;
}
