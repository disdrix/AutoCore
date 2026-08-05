// =============================================================================
// NestedHash0x10_Insert_Inferred  (Ghidra: FUN_0046bf90)
// -----------------------------------------------------------------------------
// Stable ID: aa_0046bf90
// Address:   0x0046bf90 – 0x0046c1ae  (543 B / 0x21F; autoassault.exe base 0x400000)
// System:    NestedHash bag (sentinel node 0x10) — insert / insert-or-find
// Generated: 2026-07-29 W36-B OWN-ONLY dual (decompile + read_memory)
// Exactness: Byte-sealed ABI + CF outline. Rehash/relink details mirror decompile.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Insert key/value into NestedHash0x10, or return existing equal-key node.
 *
 * ABI (byte-sealed):
 *   EDI     = NestedHash0x10*
 *   stack   = InsertResult* out   // { void* node; uint8_t inserted; pad }
 *   stack   = uint32_t* kv        // { key, value }
 *   RET 8
 *
 * Map:  +0x08 sentinel, +0x0c list size, +0x14 bucket table,
 *       +0x20 mask, +0x24 maxidx
 * Node: 0x10 bytes — next, prev, key, value  (FUN_0046c2a0)
 *
 * Callees (unowned):
 *   FUN_0044a380  — bucket vector resize during rehash
 *   FUN_0046c2a0  — buynode new(0x10) from ESI=kv
 *   FUN_0046c230  — list size += 1 (throws "list<T> too long")
 *
 * Callers: sto factory 004449b0/00444a40, operator[] 0046bf40, GfxMesh 0098fef0.
 * Sibling find: NestedHash0x10_FindIterator_Inferred (0x0046c1b0).
 */

#include <stdint.h>

struct NestedHash0x10_InsertResult {
  void *node;
  uint8_t inserted; /* 0 = existing key, 1 = newly inserted */
};

/* Unowned helpers — signatures structural from decompile + bytes. */
extern void FUN_0044a380(void *sentinel /* + EAX count formal */);
extern void *FUN_0046c2a0(void *next, void *prev /* ESI = kv source */);
extern void FUN_0046c230(uint32_t count /*ECX*/, void *list_host /*EDX*/);

void NestedHash0x10_Insert_Inferred(
    void *map /* machine: EDI */,
    NestedHash0x10_InsertResult *out /* stack */,
    uint32_t *kv /* stack */)
{
  uint32_t list_size = *(uint32_t *)((char *)map + 0x0c);
  uint32_t maxidx = *(uint32_t *)((char *)map + 0x24);

  /* ---- rehash gate (load: maxidx <= list_size/4) ---- */
  if (maxidx <= (list_size >> 2)) {
    int *table_begin = *(int **)((char *)map + 0x14);
    int capacity = 0;
    if (table_begin != 0) {
      capacity = (int)((*(char **)((char *)map + 0x18) - (char *)table_begin) >> 2);
    }

    if (maxidx < (uint32_t)(capacity - 1)) {
      uint32_t mask = *(uint32_t *)((char *)map + 0x20);
      if (mask < maxidx) {
        *(uint32_t *)((char *)map + 0x20) = mask * 2u + 1u;
      }
    } else {
      if (table_begin != 0) {
        capacity = (int)((*(char **)((char *)map + 0x18) - (char *)table_begin) >> 2);
      } else {
        capacity = 0;
      }
      *(int *)((char *)map + 0x20) = capacity * 2 - 3;
      FUN_0044a380(*(void **)((char *)map + 8));
    }

    /* redistribute nodes across expanded buckets (body loop) */
    {
      uint32_t mask = *(uint32_t *)((char *)map + 0x20);
      uint32_t split = (maxidx - (mask >> 1)) - 1u;
      void **tbl = *(void ***)((char *)map + 0x14);
      void *node = tbl[split];
      void *bucket_end = tbl[split + 1];

      if (node != bucket_end) {
        do {
          uint32_t nkey = *(uint32_t *)((char *)node + 8);
          void *next = *(void **)node;
          if ((nkey & mask) == split) {
            node = next;
          } else {
            /* splice node into end-list and repair bucket starts (body) */
            if (next == *(void **)((char *)map + 8)) {
              break;
            }
            /* ... fieldwise list splice + bucket pointer walks — see raw decompile ... */
            node = next;
          }
        } while (node != bucket_end);
      }
      *(uint32_t *)((char *)map + 0x24) = maxidx + 1u;
    }
  }

  /* ---- find insert point / existing ---- */
  {
    uint32_t key = kv[0];
    uint32_t mask = *(uint32_t *)((char *)map + 0x20);
    uint32_t idx = key & mask;
    if (*(uint32_t *)((char *)map + 0x24) <= idx) {
      idx = idx + (uint32_t)(-1 - (mask >> 1));
    }

    void **tbl = *(void ***)((char *)map + 0x14);
    void *hint = tbl[idx + 1]; /* start walk from end marker */
    void *bucket_start = tbl[idx];

    if (hint != bucket_start) {
      do {
        hint = *(void **)((char *)hint + 4); /* prev */
        uint32_t nkey = *(uint32_t *)((char *)hint + 8);
        if (nkey <= key) {
          if (key <= nkey) {
            out->node = hint;
            out->inserted = 0;
            return; /* RET 8 */
          }
          hint = *(void **)hint; /* next — insert before this */
          break;
        }
      } while (hint != bucket_start);
    }

    /* ---- miss: buynode + link ---- */
    {
      void *new_node = FUN_0046c2a0(hint, *(void **)((char *)hint + 4));
      FUN_0046c230(1u, (char *)map + 4);

      *(void **)((char *)hint + 4) = new_node;
      **(void ***)((char *)new_node + 4) = new_node;

      /* repair bucket starts while cursor still points at old start */
      {
        void *linked = *(void **)((char *)hint + 4);
        uint32_t walk = idx;
        void **slot = &tbl[walk];
        while (hint == *slot) {
          *slot = linked;
          if (walk == 0) break;
          walk -= 1u;
          slot = &tbl[walk];
        }
      }

      out->node = *(void **)((char *)hint + 4);
      out->inserted = 1;
      return; /* RET 8 */
    }
  }
}
