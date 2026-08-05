# Function record: CNDHash_Insert_009ce0a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e3d0` |
| **Canonical name** | `CNDHash_Insert_009ce0a0` |
| **Ghidra name** | `FUN_0051e3d0` |
| **Address** | `0x0051e3d0` |
| **Body range** | `0x0051e3d0`–`0x0051e4c7` exclusive (**247** B / `0xF7`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash insert family |
| **Completion status** | **partial** — dual A/B **accept**; CF + HRESULTs + vtbl sealed; product specialty open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0051e3d0_CNDHash_Insert_009ce0a0.md`, `reviews/B_aa_0051e3d0_CNDHash_Insert_009ce0a0.md` (2026-07-29 W21-D) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_0051e3d0`
- `Named_VOG_DEBUG_STOP_0051e3d0` (auto string-seed — **misleading**; lock-warn only)
- Node vtbl stamp distinguishes this unit from twins

## Purpose

**CNDHash insert(key, value)** with node vtbl **`0x009ce0a0`**. Null value → `E_POINTER` (`0x80004003`). Soft flag + existing key → return **1** without insert. Hard duplicate → log + `E_FAIL` (`0x80004005`). Else allocate 0x1c node, head-insert into bucket (`key & mask`), append global list, `count++`, return **0**. Traversal lock at `this+0x1d` logs only (does not abort).

Immediate next twin: `CNDHash_Insert_009ce0a8` @ `0x0051e4d0` (same CF, vtbl `009ce0a8`). Generic sealed twin: `CNDHash_Insert` @ `0x0053c560` (vtbl `009cefd4`).

## Signature

```c
uint32_t __thiscall CNDHash_Insert_009ce0a0(
    void *self, uint32_t key, void *value, char softIfExists);
// ret 0xC
// 0 success; 1 soft-hit; 0x80004003 null; 0x80004005 hard dup
```

## Layout (partial)

**Hash:** `+0x08` mask, `+0x0c` count, `+0x10` buckets*, `+0x14` listHead, `+0x18` listTail, `+0x1d` lockedForTraversal, `+0x20` freelist.

**Node (0x1c):** `+0` vtbl `009ce0a0`, `+4` touch, `+8` value*, `+0xc` bucketNext, `+0x10` key, `+0x14` listNext, `+0x18` listPrev.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051e3d0_FUN_0051e3d0.md`
- Annotated: `docs/reconstruction/raw/aa_0051e3d0_FUN_0051e3d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDHash_Insert_009ce0a0.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0051e3d0.cpp`
- Legacy alias: `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_0051e3d0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00508c50-0051e3d0-w21d-report.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| **Caller** | `FUN_00519a30` | 3 sites; softIfExists=0 |
| **Callee** | `CNDHash_LookupByKey` | existence check (×2) |
| **Callee** | `FUN_0053ada0` | freelist node alloc (`this+0x20`) |
| **Callee** | `FUN_00537d30` | bucket chain integrity |
| **Callee** | `FUN_007a4480` | debug log |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| HRESULTs / soft return 1 | **High** |
| `__thiscall` + `ret 0xC` | **High** |
| Node vtbl `009ce0a0` | **High** |
| Freelist at `this+0x20` | **High** |
| Distinct from 0051e4d0 / 0053c560 | **High** |
| Product specialty / value type | Open |
| Runtime / differential | Open |

## Related

- `aa_0051e4d0` `CNDHash_Insert_009ce0a8` — next-VA twin
- `aa_0053c560` `CNDHash_Insert` — generic sealed twin
- `aa_005b0920` `CNDHash_LookupByKey`
