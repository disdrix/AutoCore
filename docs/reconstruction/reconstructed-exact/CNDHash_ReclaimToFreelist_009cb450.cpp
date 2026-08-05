// =============================================================================
// CNDHash_ReclaimToFreelist_009cb450
// -----------------------------------------------------------------------------
// Stable ID: aa_004bcae0
// Address:   0x004bcae0–0x004bcb3e inclusive (95 B / 0x5F)
// Module:    autoassault.exe (image base 0x400000)
// System:    container / CNDHash tableC family 009cb450
// Generated: 2026-08-04 W37-G dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Owning reclaim for FreeBuckets_009cb450 (0x004bcc60, W31-M):
//   for each bucket i = 0..mask inclusive:
//     walk chain at bucket[i]+4
//     stamp node with PTR_FUN_009cb358
//     if value at node+0x08: (*vtbl)(1) scalar-deleting destroy
//     null value; push node onto freelist at hash+0x20
//     clear bucket head
//
// ABI: ECX=hash*, bare RET, void. No static callees (virtual delete only).
// Twin (not owned; W37-J): FUN_004e2bd0 — value@+0xC next@+0x10 stamp 009cb360.
// Reject scaffold Named_CalleeOf_*VOG_DEBUG_STOP_004bcae0.

#include <cstdint>

struct CNDHashNode_009cb358 {
  void *link_or_stamp; // +0x00
  void *pad_or_key;    // +0x04 (unread here)
  void *value;         // +0x08 owned
  CNDHashNode_009cb358 *next; // +0x0C
};

struct CNDHash_009cb450 {
  // … head fields unused here …
  uint32_t mask;       // +0x08
  // +0x0C count (zeroed by FreeBuckets parent, not this body)
  void **buckets;      // +0x10  → array of bucket*
  // +0x14/+0x18 list ends untouched
  CNDHashNode_009cb358 *freelist; // +0x20
};

// bucket object: chain head at +4 (matches FreeBuckets / Alloc twins)
struct CNDHashBucket {
  void *unused0;
  CNDHashNode_009cb358 *head; // +4
};

extern "C" void *__cdecl PTR_FUN_009cb358; // node stamp (symbol address)

extern "C" void __fastcall CNDHash_ReclaimToFreelist_009cb450(void *hash /*ECX*/)
{
  auto *h = reinterpret_cast<uint8_t *>(hash);
  uint32_t mask = *reinterpret_cast<uint32_t *>(h + 0x08);
  auto **bucket_table = *reinterpret_cast<CNDHashBucket ***>(h + 0x10);

  uint32_t i = 0;
  do {
    CNDHashNode_009cb358 *node = bucket_table[i]->head;
    while (node != nullptr) {
      CNDHashNode_009cb358 *next = node->next;
      node->link_or_stamp = &PTR_FUN_009cb358;
      if (node->value != nullptr) {
        auto **vtbl = *reinterpret_cast<void ***>(node->value);
        auto dtor = reinterpret_cast<void(__thiscall *)(void *, int)>(vtbl[0]);
        dtor(node->value, 1);
      }
      node->value = nullptr;
      node->link_or_stamp = *reinterpret_cast<void **>(h + 0x20);
      *reinterpret_cast<void **>(h + 0x20) = node;
      node = next;
    }
    bucket_table[i]->head = nullptr;
    ++i;
  } while (i <= mask);
}

// Ghidra twin
extern "C" void __fastcall FUN_004bcae0(void *hash /*ECX*/)
{
  CNDHash_ReclaimToFreelist_009cb450(hash);
}
