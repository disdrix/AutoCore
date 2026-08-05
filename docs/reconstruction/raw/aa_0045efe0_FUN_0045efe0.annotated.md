# Annotated low-level: FUN_0045efe0 → Pod28_FillAssign_Forward

| Field | Value |
|---|---|
| Stable ID | `aa_0045efe0` |
| VA | `0x0045efe0`–`0x0045effb` exclusive (**27 B**) |
| System | MSVC POD fill-assign, elem **0x1c** |
| Date | 2026-07-23 scaffold; W35-M seal 2026-07-29 |
| Canonical name | `Pod28_FillAssign_Forward` (**Inferred**) |

## Machine-level notes

- **Bytes win** on ABI: **EAX=dst_begin**, **EDX=dst_end**, **EBX=value\***. No stack. **`RET 0`** (`C3`).
- Decompiler invents unused `param_1` and labels EBX as `unaff_EBX` — both are live register formals fixed by callers (InsertN mid-hole fill).
- Body is pure leaf: outer half-open loop + inner `rep movsd` of **7 dwords** (`ECX=7`, `ESI=EBX`, `EDI=cursor`).
- Stride sealed: `ADD EAX, 0x1C` between slots.
- Sibling after pad (`0x0045effb+`) is a different helper (8-dword reverse path) — **not** this VA.
- Reject scaffold `Named_CalleeOf_*anmTrackMast*`.

## Signature (sealed)

```c
// EAX=dst_begin, EDX=dst_end, EBX=value*; RET 0; void; leaf
void Pod28_FillAssign_Forward(
    Pod28* dst_begin,      /* EAX — also cursor */
    Pod28* dst_end,        /* EDX */
    const Pod28* value);   /* EBX */
```

## Control flow (annotated)

1. If `EAX == EDX` → return (empty range).
2. Save ESI/EDI.
3. Loop while cursor range non-empty:
   - `EDI = EAX`; `EAX += 0x1c`; compare `EAX` vs `EDX` (flags for loop).
   - `ECX = 7`; `ESI = EBX`; `rep movsd` → assign `*cursor = *value` (7×uint32).
   - Continue if `EAX != EDX`.
4. Restore ESI/EDI; `RET`.

## Full hex

```
3bc2741656578bf883c01c3bc2b9070000008bf3f3a575ee5f5ec3
```

## Callers

- `FUN_0045cd30` @ `0x0045d004` (Pod28 InsertN in-place mid)
- `FUN_00466ea0` @ `0x0046715d`
- `FUN_00469f50` @ `0x0046a1ec`
