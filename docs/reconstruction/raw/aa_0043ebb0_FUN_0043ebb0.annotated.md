# Annotated low-level: FUN_0043ebb0 / GuardedVector_RingAssignBackwardChecked

| Field | Value |
|---|---|
| Stable ID | `aa_0043ebb0` |
| VA | `0x0043ebb0`–`0x0043ec43` (**148 B**) |
| Canonical | `GuardedVector_RingAssignBackwardChecked` (**Inferred**) |
| Ghidra | `FUN_0043ebb0` |
| System | STL / guarded ring-vector container |
| Date | 2026-07-29 (W33-K dual seal) |

## Machine-level notes

- **ABI:** 7 stack formals `(out, stop_c, stop_i, src_c, src_i, dst_c, dst_i)`; plain `RET` (caller cleans `0x1c`); saves EBX/EBP/ESI/EDI.
- **Return:** out pair pointer in **EAX** (bytes load out before store; decompiler void is incomplete).
- **Leaf:** no callees.
- **Ring map addressing** same as family: `page = idx>>2`, wrap if `page >= capacity`, lane via `idx + page*-4`.
- **Direction:** reverse (both indices decremented each step) until src cursor equals stop pair — `std::copy_backward` shape on ring pages.
- **Self-guard:** skip when `dst_elem == src_elem` (address equality).
- **Callers (4):** `FUN_0043e080` InsertN_Thiscall (back-biased mid-insert arm), `FUN_0043df90`, `FUN_0044e1c0` InsertRange, `FUN_005441d0`.
- **Twin:** sealed `GuardedVector_RingAssignBackward` (`0x0043d300`) — same reverse walk, **no** self-guard, slightly different out-pair store order.

## Pseudocode (annotated)

```c
// 7 stack args; plain RET; returns out in EAX
GuardedVectorIteratorPair* GuardedVector_RingAssignBackwardChecked(
    GuardedVectorIteratorPair* out,
    GuardedVectorHeader* stop_c, uint32_t stop_i,
    GuardedVectorHeader* src_c,  uint32_t src_i,
    GuardedVectorHeader* dst_c,  uint32_t dst_i)
{
  while (stop_c != src_c || stop_i != src_i) {
    --src_i;
    uint32_t sb = src_i >> 2;
    int s_lane = static_cast<int>(sb) * -4;
    if (src_c->capacity <= sb) sb -= src_c->capacity;

    --dst_i;
    uint32_t db = dst_i >> 2;
    int d_lane = static_cast<int>(db) * -4;
    if (dst_c->capacity <= db) db -= dst_c->capacity;

    uint32_t* src = reinterpret_cast<uint32_t*>(
        reinterpret_cast<int*>(src_c->slots)[sb]
        + (static_cast<int>(src_i) + s_lane) * 4);
    uint32_t* dst = reinterpret_cast<uint32_t*>(
        reinterpret_cast<int*>(dst_c->slots)[db]
        + (static_cast<int>(dst_i) + d_lane) * 4);
    if (dst != src)
      *dst = *src;
  }
  out->container = dst_c;
  out->index = dst_i;
  return out;
}
```

## Open residual

- Product English for element type / container class name.
- Why this twin keeps self-guard vs `0043d300` (MSVC template instantiation residual — not behavioral for non-overlapping ranges).
