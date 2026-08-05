// =============================================================================
// Object_EnqueueDeferredOnce
// -----------------------------------------------------------------------------
// Stable ID: aa_004d0e90
// Address:   0x004d0e90  (autoassault.exe, image base 0x400000)
// System:    client world / reaction lifecycle
// Generated: 2026-07-29 dual W17-J (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF corrected by bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Idempotent deferred-work enqueue for a world object.
//   Host queue lives at this+0xe5fc (CS-protected linked list).
//   Sticky ObjectFlag_DeferredQueued = object+0x17c bit 0 (mask 0x1).
//
// ABI (bytes sealed):
//   __thiscall  ECX = host*, stack arg0 = Object*
//   ret 4
//
// CALLEES:
//   FUN_004e15a0(queue, obj) — list contains? returns 0/1 in AL
//   FUN_004024d0(queue, obj) — append 0xC node with node[1]=obj
//
// NOTE: Ghidra surface drops ECX and types as void FUN_004d0e90(int). Prefer this.
// =============================================================================

#include <cstdint>

// Forward decls of callees (not owned by this dual).
extern "C" std::uint8_t __thiscall FUN_004e15a0(void* queue, void* obj);
extern "C" void         __thiscall FUN_004024d0(void* queue, void* obj);

// ObjectFlag_DeferredQueued at object+0x17c bit 0.
static constexpr std::uint32_t kObjectFlag_DeferredQueued = 0x1u;
static constexpr std::uint32_t kHostQueueOffset           = 0xe5fcu;
static constexpr std::uint32_t kObjectFlagsOffset         = 0x17cu;

void __thiscall Object_EnqueueDeferredOnce(void* host /*ECX*/, void* obj /*stack*/)
{
  auto* flags = reinterpret_cast<std::uint32_t*>(
      reinterpret_cast<std::uint8_t*>(obj) + kObjectFlagsOffset);

  // Early out if sticky bit already set.
  if ((*flags & kObjectFlag_DeferredQueued) != 0) {
    return;
  }

  void* queue = *reinterpret_cast<void**>(
      reinterpret_cast<std::uint8_t*>(host) + kHostQueueOffset);

  // Already present on list → skip (bit may lag behind list state).
  if (FUN_004e15a0(queue, obj) != 0) {
    return;
  }

  FUN_004024d0(queue, obj);
  *flags |= kObjectFlag_DeferredQueued;
}
