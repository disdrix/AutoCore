# Annotated low-level: FUN_0040afb0 / Host_LookupObjectByKey_PairTable30_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0040afb0` |
| VA | `0x0040afb0`–`0x0040afed` (**62 B**) |
| System | interaction-activation (shared pair-table leaf) |
| Date | 2026-08-05 (MEGA-028 annotated refresh) |
| Proposed name | `Host_LookupObjectByKey_PairTable30_Inferred` |
| Prior scaffold | `Named_CalleeOf_Named_VOG_DEBUG_STOP_0040afb0` (**retired**) |

---

## Machine-level notes

- **Source:** raw capture `aa_0040afb0` + MEGA-028 live re-verify.
- **ABI:** `__thiscall`; **ECX** = host object with pair table; stack `void **outObject`, `int key`; **`RET 8`**; **EAX** returns `outObject` (MSVC out-param idiom — callers do `obj = *FUN_0040afb0(...)`).
- **Layout:**
  - `host+0x30` → `Pair*` base (`struct { int key; void* value; }` × count, stride 8)
  - `host+0x34` → `int count` (signed; `<=0` → miss)
- **Semantics:** linear first-match lookup of `key`; write associated `value` (object*) to `*out`; miss writes `NULL`.
- **Not:** map/set tree, hash, TFID resolve, vtbl dispatch, soft-cast ray itself — pure table read.
- **Consumers (role):** soft-cast hit resolve (`00925820` key=1), `GetObjectsInArea` (`004ea350` key=1 ×3), drive collision material keys 3/4 (`005d9ea0` / `005da0a0`), other physics/UI hosts with key 1/3.
- Prefer assembly when decompiler shows `void` return (EAX is live).

## Pseudocode (annotated)

```c
// Host_LookupObjectByKey_PairTable30_Inferred
// ECX = host; stack: outObject**, key; EAX = outObject; RET 8
void* __thiscall Host_LookupObjectByKey_PairTable30_Inferred(
    void *host,
    void **outObject,
    int key)
{
  int i;
  int *pairCursor;          // walks {key, value} as int[2]
  int count = *(int *)((char *)host + 0x34);
  int *table;               // (int*)*(host+0x30)

  i = 0;
  if (0 < count) {
    table = *(int **)((char *)host + 0x30);
    pairCursor = table;
    do {
      if (*pairCursor == key) {
        /* value is second dword of pair i */
        *outObject = (void *)table[i * 2 + 1];
        return outObject;   /* EAX = outObject */
      }
      i = i + 1;
      pairCursor = pairCursor + 2;   /* +8 bytes */
    } while (i < count);
  }
  *outObject = 0;
  return outObject;
}
```

## Control flow

| Stage | Behavior | Conf |
|---|---|---|
| Load count @+0x34 | miss if `<= 0` | **High** |
| Load base @+0x30 | pair array | **High** |
| Loop stride 8 | cmp key; advance | **High** |
| Hit | `*out = table[i*2+1]`; ret 8 | **High** |
| Miss | `*out = 0`; ret 8 | **High** |
| No callees | leaf | **High** |

## Call-site key inventory (live xrefs)

| Key | Sites (sample) | Role |
|---|---|---|
| 1 | soft-cast `00925c8f`; GetObjectsInArea `004ea582`/`876`/`aee`; `00642bc8`; `00932eef`; `005dd718`/`80d` | primary object* slot on hit/host |
| 3 | contact prep `005d9feb`; contact `005da81a`/`846`; `00593160` | material/FX pair |
| 4 | contact prep `005d9ffb` | material/FX pair |

## Open questions / gaps

- Product/PDB symbol for host type and pair-table English.
- Exact RTTI of host without per-caller cast (often reached via hit payload `+0x20`).
- Whether first-match order is load-order significant when keys duplicate (no dual-key guard in body).
- Runtime / bit-exact / differential open.
