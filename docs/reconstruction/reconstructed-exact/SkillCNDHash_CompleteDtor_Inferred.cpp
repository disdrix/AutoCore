// =============================================================================
// SkillCNDHash_CompleteDtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051de80
// Address:   0x0051de80–0x0051deea inclusive (107 B / 0x6B)
//            autoassault.exe, image base 0x400000
// Wave:      2026-08-04 WQ9G-A OWN dual A/B seal
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory. SEH frame + thiscall ABI sealed by bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   MSVC complete object destructor for skill-family CNDHash.
//   Installs vtbl PTR_FUN_009ce1b8, soft-logs if traversal-locked, destroys
//   bucket table, then tears down freelist/slab host at +0x20.
//   Does not free the host object — scalar deleting dtor does that.
//
// ABI
//   __thiscall; ECX=this; no stack args; bare RET; void
//
// Callers
//   SkillCNDHash_ScalarDeletingDtor_Inferred @ 0x0051de60 (sole code CALL)
//
// Peers
//   SkillCNDHash_Ctor_Inferred @ 0x0051dd60 (same vtbl install)
//   SkillCNDHash_Recreate_Inferred @ 0x004cbdc0 (same soft-lock log policy)
//   SkillCNDHash_DestroyBucketTable_Inferred @ 0x004cba60 (nested)
//
// Rejected aliases
//   Named_VOG_DEBUG_STOP_0051de80 (scaffold string path name)
//   Identity merge with scalar deleting dtor 0x0051de60
// =============================================================================

#include <cstdint>

struct SkillCNDHash_Inferred {
  void *vtbl;                 // +0x00  PTR_FUN_009ce1b8
  // ... buckets / counts ...
  // uint8_t log2;            // +0x1c
  // uint8_t lock;            // +0x1d  traversal lock
  // ... freelist head @ +0x20; slab vector @ +0x28..+0x30 ...
  uint8_t _pad_to_0x20[0x20 - sizeof(void *)];
  // freelist / slab host starts at +0x20 (passed to FUN_0059c8a0)
};

// Dualed WQ9E-A
extern "C" void __thiscall SkillCNDHash_DestroyBucketTable_Inferred(void *self); // 0x004cba60

// Freelist/slab vector teardown at host base (not dualled here).
// When called from complete dtor: ECX = self+0x20.
extern "C" void __fastcall FUN_0059c8a0(void *freelist_or_slab_host); // 0x0059c8a0

// log helper (cdecl)
extern "C" void FUN_007a4480(int level, const char *msg);

// MSVC complete object dtor for skill CNDHash.
extern "C" void __thiscall SkillCNDHash_CompleteDtor_Inferred(void *self)
{
  auto *hash = static_cast<SkillCNDHash_Inferred *>(self);

  // SEH: LAB_009a371b (bytes: 6A FF 68 1B 37 9A 00 64 …) — omitted as runtime frame

  // Reinstall vtbl for dtor phase (same as ctor install)
  hash->vtbl = reinterpret_cast<void *>(0x009ce1b8); // PTR_FUN_009ce1b8

  uint8_t lock = *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(self) + 0x1d);
  if (lock != 0) {
    FUN_007a4480(0, "HashError:Destructor, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    // soft-log only — continue teardown
  }

  SkillCNDHash_DestroyBucketTable_Inferred(self);

  // LEA ECX, [ESI+0x20]; CALL FUN_0059c8a0
  FUN_0059c8a0(reinterpret_cast<char *>(self) + 0x20);

  // bare ret (C3)
}

// Scaffold twin entry (Ghidra name).
extern "C" void __thiscall FUN_0051de80(void *self)
{
  SkillCNDHash_CompleteDtor_Inferred(self);
}
