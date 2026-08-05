# Function record: CNDHash_InsertAlways

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060c010` |
| **Canonical name** | `CNDHash_InsertAlways` |
| **Address** | `0x0060c010` |
| **Body** | `0x0060c010`–`0x0060c0a5` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared CNDHash container (region-mission secondary indexes) |
| **Completion status** | **accept-with-gaps** — dual A/B W18-K 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_0060c010`
- `Named_CalleeOf_Mission_VOGRegionMissions_0060c010`

## Purpose

Always-insert into a CNDHash: null-value reject, allocate 0x1c node (vtbl `PTR_LAB_009cf024`), head-insert bucket chain, append global list, `count++`. **No** lock check, **no** lookup / uniqueness — multi-key chains allowed.

Sole caller: `CVOGRegionMissions_ctor` secondary tables (`this[2]` / `this[3]`).

## Signature

```c
int __thiscall CNDHash_InsertAlways(void *this, uint32_t key, void *value);
// RET 8; returns 0 or 0x80004003 (E_POINTER)
```

## Return codes

| Value | Meaning |
|---|---|
| `0` | inserted |
| `0x80004003` | null value (`E_POINTER`) |

## Layout (partial)

**Hash:** `+0x08` mask, `+0x0c` count, `+0x10` buckets*, `+0x14` listHead, `+0x18` listTail, `+0x20` freelist shell.

**Node (0x1c):** `+0` vtbl `009cf024`, `+4` touch, `+8` value*, `+0xc` bucketNext, `+0x10` key, `+0x14` listNext, `+0x18` listPrev.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0060c010_FUN_0060c010.md`
- Annotated: `docs/reconstruction/raw/aa_0060c010_CNDHash_InsertAlways.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDHash_InsertAlways.cpp`
- Scaffold (legacy): `docs/reconstruction/reconstructed-exact/FUN_0060c010.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0060c010_CNDHash_InsertAlways.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0060c010_CNDHash_InsertAlways.md`

## Callers / callees

| Direction | Symbol | Address / notes |
|---|---|---|
| Caller | `CVOGRegionMissions_ctor` | `0x0060b870` — sites `0060ba99`, `0060baaa` |
| Callee | `FUN_0053ada0` | freelist node alloc; ECX=`this+0x20` |
| Callee | `FUN_00537d30` | bucket chain integrity; ECX=bucketHdr |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **Confirmed** |
| Always-insert (no uniqueness) | **Confirmed** |
| ABI thiscall + RET 8 | **Confirmed** |
| Hash / node offsets | **High** |
| Freelist at `+0x20` | **Confirmed** |
| Product English name | **Inferred** |
