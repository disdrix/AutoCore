// =============================================================================
// Object_009d33c4_Ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00575440
// Address:   0x00575440  (autoassault.exe, image base 0x400000)
// Body:      0x00575440–0x00575528 exclusive (232 B / 0xE8)
// System:    object derived complete ctor (vtbl PTR_FUN_009d33c4)
// Generated: 2026-07-29 W29-H dual seal
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
//            List LEA @ +0x1DC and field offsets sealed by bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
// Complete-object constructor for derived object family PTR_FUN_009d33c4.
// Chains Object_SharedBase_Ctor (FUN_00518940), installs derived vtbl, builds
// StdList sentinel at this+0x1DC (+4 head / +8 size), and zero/inits derived
// fields that Object_009d33c4_CompleteDtor (FUN_00575350) tears down.
//
// Scalar deleting wrapper (vtbl[0]): Object_009d33c4_ScalarDeletingDtor @ 0x00575c00.
// Vtbl[1]: empty stub FUN_0056f570.
//
// Callers: CVOGReaction_GiveItemByCbid; FUN_0094bed0 (factory-style).

#include <cstdint>

extern "C" void __thiscall Object_SharedBase_Ctor(void *self); // FUN_00518940
extern "C" void *FUN_00457c60(void); // alloc 0x18 circular list sentinel
extern "C" void *PTR_FUN_009d33c4;

// __thiscall; ECX = this; returns this; bare RET
void *__thiscall Object_009d33c4_Ctor(void *self)
{
  auto *base = reinterpret_cast<uint8_t *>(self);

  // SEH: LAB_009a5096; state -1 → 0 after base
  Object_SharedBase_Ctor(self);

  *reinterpret_cast<void **>(base + 0) = &PTR_FUN_009d33c4;

  // image: lea edi, [esi+0x1DC]; call FUN_00457c60; mov [edi+4], eax; mov [edi+8], 0
  void *sentinel = FUN_00457c60();
  *reinterpret_cast<void **>(base + 0x1E0) = sentinel; // list+4 head
  *reinterpret_cast<uint32_t *>(base + 0x1E4) = 0;     // list+8 size

  *reinterpret_cast<uint32_t *>(base + 0x1F8) = 0;
  *reinterpret_cast<uint32_t *>(base + 0x1FC) = 0;
  *reinterpret_cast<uint32_t *>(base + 0x200) = 0;
  base[0x1F0] = 0;
  base[0x1F1] = 0;
  base[0x1D8] = 0;
  *reinterpret_cast<uint32_t *>(base + 0x194) = 0;
  *reinterpret_cast<void **>(base + 0x1EC) = nullptr;
  base[0x1F2] = 0;
  *reinterpret_cast<uint32_t *>(base + 0x190) = 1;
  *reinterpret_cast<uint32_t *>(base + 0x1E8) = 0xFFFFFFFFu;

  // four 0x10-stride slots @ +0x198, +0x1A8, +0x1B8, +0x1C8
  *reinterpret_cast<uint32_t *>(base + 0x198) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x19C) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1A8) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1AC) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1B8) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1BC) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1C8) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1CC) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t *>(base + 0x1A0) = 0;
  *reinterpret_cast<uint32_t *>(base + 0x1B0) = 0;
  *reinterpret_cast<uint32_t *>(base + 0x1C0) = 0;
  *reinterpret_cast<uint32_t *>(base + 0x1D0) = 0;

  return self;
}
