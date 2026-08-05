# Annotated low-level: FUN_005cc7c0 / EntityHost_ApplyNestedLocalPosition_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005cc7c0` |
| VA | `0x005cc7c0`–`0x005cc7e7` (**40 B**) |
| System | `input-drive-control` / object pose (host→nested apply) |
| Date | 2026-07-23 scaffold; **2026-07-29 W23-J dual** |
| Proposed name | `EntityHost_ApplyNestedLocalPosition_Inferred` (**Probable**) |

## Machine-level notes (W23-J)

- **ABI:** `__thiscall` — host in **ECX**, stack **arg1** = `float* vec4`, stack **arg2** present (`ret 8`) but **unread** in body.
- **Nested object:** `object = *(host + 0x64)` used for all three steps.
- **Order sealed:**
  1. `FUN_0053d970(object, 0)` — phys/body prep when body path needs update (stack formal forced **0** → callee rewrites to **1** before `FUN_005d4440` tail when taken).
  2. `*(uint8_t*)(object + 0x304) = 1` — dirty / recompute byte (same offset DriveControlTick sets after gated set-pos).
  3. `FUN_004c3a40(object, vec)` — `CVOGObject_SetLocalPosition4_Gated_Inferred` (NaN xyz trap + `0xC7` gate + store `+0x240..+0x24c`).
- **Dispatch:** five **DATA** vtable slots hold this VA; no direct CALL xrefs recovered.
- Prefer bytes when decompiler drops the second stack formal or free-call typing of callees.

## Pseudocode (annotated)

```c
// __thiscall  ECX=host
// stack: float *vec /* used */, undefined4 arg2 /* cleaned, unread */
// ret 8
void EntityHost_ApplyNestedLocalPosition_Inferred(void *host, float *vec, /*unused*/ void *arg2)
{
    void *object = *(void **)((char *)host + 0x64);

    FUN_0053d970(object, 0);                    // thiscall + stack 0; ret 4
    *(uint8_t *)((char *)object + 0x304) = 1;   // dirty byte
    FUN_004c3a40(object, vec);                  // gated local position float4
}
```

## Open questions

1. Product / RTTI name for host class and vtable slot index English.
2. Semantic payload of unread **arg2** (interface width only).
3. Full consumers of nested `+0x304` beyond DCT / this path.
4. Runtime / differential under null `*(host+0x64)` (body does not null-check).
