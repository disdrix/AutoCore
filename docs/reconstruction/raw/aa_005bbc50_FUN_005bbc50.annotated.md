# Annotated low-level: ObjectMotion_HostTeardown_Inferred (`FUN_005bbc50`)

| Field | Value |
|---|---|
| Stable ID | `aa_005bbc50` |
| VA | `0x005bbc50` (Ghidra end `0x005bbd96`; true `c3` ≈ `0x005bbdc0`) |
| System | client object motion / reaction host teardown |
| Date | 2026-07-29 (W30-S live re-pull) |

## Machine-level notes

- Source: raw capture + live `decompile_function` / `read_memory`.
- Ghidra marks `operator_delete` **noreturn** → decompiler truncates after last delete; bytes continue with list free loop (`75 eb`), null `+0xa24`, SEH epilog, **`c3`**.
- Slot release call site forces freelist ECX = `DAT_00b036c0` (not host).
- Reject scaffold human name `Named_CalleeOf_Named_CalleeOf_Named_missileExplosion_005bbc50` as product claim.

## Pseudocode (annotated)

```c
// __thiscall/__fastcall  ECX = motion/FX host object
// stack: none  ·  ret (c3)  ·  void
// SEH frame (LAB_009a6bad)

void ObjectMotion_HostTeardown_Inferred(Host *host /* ECX */)
{
  // 1) Primary buffer at +0x308: list-clear helper then free if heap (≠ inline +0x14)
  FUN_005b8340(/* buffer ctrl near +0x14 family */);
  void *p = *(void **)(host + 0x308);
  if (p != (void *)(host + 0x14)) {
    FUN_005b8340(/* … */);
    operator_delete(p);   // NOT truly noreturn
  }
  FUN_005b8340(/* … */);

  // 2) Optional secondary buffer when flag +0x7fc
  if (*(char *)(host + 0x7fc) != 0) {
    p = *(void **)(host + 0x6ec);
    if (p != (void *)(host + 0x3f8)) {
      FUN_005b8340(/* … */);
      operator_delete(p);
    }
    FUN_005b8340(/* … */);
  }

  // 3) Walk intrusive list at +0xa24; release each slot payload @ node[+0x8]
  //    Call: push node[2]; mov ecx, DAT_00b036c0; call ObjectMotion_SlotReleaseToFreelist
  ListNode *sent = *(ListNode **)(host + 0xa24);
  ListNode *it = sent->next;   // **(int**)(host+0xa24)
  if (it != sent) {
    do {
      ObjectMotion_SlotReleaseToFreelist_Inferred(
          /* ECX */ (SlotNode **)0x00B036C0,
          /* stack */ (SlotNode *)it->payload_at_plus8 /* it[2] */);
      it = it->next;
    } while (it != *(ListNode **)(host + 0xa24));
  }

  // 4) Empty list nodes (bytes: compare + jnz loop; decompile shows single delete)
  //    Reset sentinel links; count +0xa28 = 0; free nodes; free sentinel; host+0xa24 = 0

  // 5) SEH epilog → ret
}
```

## Offsets (host)

| Off | Role (inferred) |
|---|---|
| `+0x14` / `+0x308` | inline vs heap primary buffer pair |
| `+0x3f8` / `+0x6ec` | inline vs heap secondary buffer (gated by `+0x7fc`) |
| `+0x7fc` | char flag — secondary buffer live |
| `+0xa24` | list sentinel* (slot wrappers) |
| `+0xa28` | list count (cleared to 0) |

## Related

| VA | Name / role |
|---|---|
| `0x005be310` | caller wrapper (W30-R): teardown + optional freelist push |
| `0x005be2b0` | `ObjectMotion_SlotReleaseToFreelist_Inferred` (W28-I) |
| `0x005b8340` | list/buffer clear helper (not OWN) |
| `0x00b036c0` | global slot freelist head |
