# Annotated low-level: FUN_004bfd10 / TrackMgr_9CircList_UntrackObject_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004bfd10` |
| VA | `0x004bfd10` |
| System | Client track manager (host `+0xE914`) |
| Date | 2026-08-04 (W37-T dual; supersedes 2026-07-23 scaffold notes) |

## Machine-level notes

- Source: raw capture + live `batch_decompile` + `read_memory` (W37-T).
- **Bytes win** over decompiler on post-`operator_delete` path (Ghidra falsely marks noreturn).
- Body **146 B** (`0x004bfd10`–`0x004bfda1`); pad `CC` then sibling `FUN_004bfdb0`.
- ABI: `__thiscall` manager; stack `(object*)`; returns **1/0** in AL; **`ret 4`**.
- 9 buckets at `this+8`, stride `0xC` (`head`, `count`, …).
- Node: `{next, prev, payload*}`; circular sentinel at head.
- Match: `FUN_005c6720(payload, object)` (thiscall on payload).
- On match: unlink; `operator_delete(node)`; count--; `payload->vtbl[0](1)`; return 1.
- Callers load manager from host`+0xE914` (see W31-T UnloadGraphics).

## Pseudocode (annotated; post-delete restored from bytes)

```c
// uint8_t __thiscall TrackMgr_9CircList_UntrackObject_Inferred(
//     manager* this, object* obj);  // ret 4

uint8_t __thiscall FUN_004bfd10(int param_1, void *param_2)
{
  uint i = 0;
  int *bucket = (int *)(param_1 + 8); // head@0, count@1 (dwords)

  do {
    if (bucket[1] != 0) {
      int *head = (int *)*bucket;
      int *node = (int *)*head; // head->next
      if (node != head) {
        do {
          void *payload = (void *)node[2];
          if (FUN_005c6720(payload, param_2)) {
            if (node == (int *)*(int *)(param_1 + 8 + i * 0xC)) {
              // defensive head==node: dtor payload only
              if (payload) ((code *)*(void **)payload)(1);
              return 1;
            }
            // unlink
            *(int *)node[1] = *node;
            *(int *)(*node + 4) = node[1];
            operator_delete(node);          // DOES return
            // count--  (bucket+4)
            *(int *)(param_1 + 8 + i * 0xC + 4) -= 1;
            if (payload) ((code *)*(void **)payload)(1); // scalar deleting dtor
            return 1;
          }
          node = (int *)*node;
        } while (node != head);
      }
    }
    i += 1;
    bucket += 3;
  } while (i < 9);
  return 0;
}
```

## Open questions

- Product manager class name at host`+0xE914`.
- Payload / track-entry type English.
- Bucket index meaning (why 9).
