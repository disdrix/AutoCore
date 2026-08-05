// =============================================================================
// Object_009d33c4_CompleteDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00575350
// Address:   0x00575350  (autoassault.exe, image base 0x400000)
// Body:      0x00575350–0x005753ba exclusive (106 B / 0x6A)
// System:    object derived complete dtor (vtbl PTR_FUN_009d33c4)
// Generated: 2026-07-29 W28-M dual seal
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
//            List LEA @ +0x1DC and tail-jmp to FUN_00518ec0 sealed by bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
// Complete-object destructor for derived object family PTR_FUN_009d33c4.
// Ctor twin FUN_00575440 calls Object_SharedBase_Ctor (FUN_00518940) then
// installs this vtbl. This body frees derived members then tail-jumps to
// FUN_00518ec0 (Object shared-base destructor).
//
// Scalar deleting wrapper (vtbl[0]): FUN_00575c00 @ 0x00575c00.
// Vtbl[1]: empty stub FUN_0056f570.

#include <cstdint>

extern "C" void *__cdecl operator_delete(void *p);
extern "C" void __thiscall StdList_Destroy_FreeHead(void *list); // FUN_00497360
extern "C" void __thiscall FUN_00518ec0(void *self); // Object shared-base dtor
extern "C" void *PTR_FUN_009d33c4;

// __thiscall; ECX = this; image ends in JMP FUN_00518ec0 (no local RET)
void __thiscall Object_009d33c4_CompleteDtor(void *self)
{
  auto *base = reinterpret_cast<uint8_t *>(self);

  *reinterpret_cast<void **>(base + 0) = &PTR_FUN_009d33c4;

  void *owned = *reinterpret_cast<void **>(base + 0x1EC);
  if (owned != nullptr) {
    operator_delete(owned);
  }
  *reinterpret_cast<void **>(base + 0x1EC) = nullptr;
  base[0x1F0] = 0;
  base[0x1F1] = 0;

  void *begin = *reinterpret_cast<void **>(base + 0x1F8);
  if (begin != nullptr) {
    operator_delete(begin);
  }
  *reinterpret_cast<void **>(base + 0x1F8) = nullptr;
  *reinterpret_cast<void **>(base + 0x1FC) = nullptr;
  *reinterpret_cast<void **>(base + 0x200) = nullptr;

  // image: lea ecx, [esi+0x1DC]; call StdList_Destroy_FreeHead
  StdList_Destroy_FreeHead(base + 0x1DC);

  // image: mov ecx,esi; jmp FUN_00518ec0  (tail-call)
  FUN_00518ec0(self);
}
