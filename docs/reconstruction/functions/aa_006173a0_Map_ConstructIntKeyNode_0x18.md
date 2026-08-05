# Function record: Map_ConstructIntKeyNode_0x18

| Field | Value |
|---|---|
| **Stable ID** | `aa_006173a0` |
| **Canonical name** | `Map_ConstructIntKeyNode_0x18` |
| **Ghidra name** | `FUN_006173a0` |
| **Address** | `0x006173a0`–`0x006173de` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std map/set node construction (int-key 0x18 family; cross-cutting) |
| **Classification** | leaf allocator / node ctor |
| **Completion status** | **Sealed** — dual A/B 2026-07-29 W18-L; size/layout/ABI sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Purpose

`operator_new(0x18)` then fill MSVC-style RB tree node: left / parent / right, int key + int mapped from a value pair pointer, color byte, **isnil = 0**. Used by int-key map insert cores (e.g. `Map_InsertNodeAndRebalance_IntKey`).

## Signature (sealed)

```c
// __stdcall; RET 0x14; node* in EAX (0 if operator_new fails)
MapNode18 *Map_ConstructIntKeyNode_0x18(
    MapNode18 *left,
    MapNode18 *parent,
    MapNode18 *right,
    const IntPair *value,
    uint8_t color);
```

| Param | Stack | Meaning |
|---|---|---|
| left | `[esp+4]` | stored at `node+0x00` |
| parent | `[esp+8]` | stored at `node+0x04` |
| right | `[esp+0xC]` | stored at `node+0x08` |
| value | `[esp+0x10]` | `*value` → `+0x0C` key; `value[1]` → `+0x10` mapped |
| color | `[esp+0x14]` byte | `node+0x14`; isnil `+0x15` forced 0 |
| return | `EAX` | new node or null |

## Node layout

| Offset | Width | Field |
|---|---|---|
| `+0x00` | ptr | left |
| `+0x04` | ptr | parent |
| `+0x08` | ptr | right |
| `+0x0C` | i32 | key |
| `+0x10` | i32 | mapped |
| `+0x14` | u8 | color |
| `+0x15` | u8 | isnil (0) |
| size | `0x18` | |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006173a0_FUN_006173a0.md`
- Annotated: `docs/reconstruction/raw/aa_006173a0_FUN_006173a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_ConstructIntKeyNode_0x18.cpp`
- Scaffold alias: `docs/reconstruction/reconstructed-exact/FUN_006173a0.cpp`
- Scaffold alias record: `docs/reconstruction/functions/aa_006173a0_FUN_006173a0.md`
- Review A: `docs/reconstruction/reviews/A_aa_006173a0_Map_ConstructIntKeyNode_0x18.md`
- Review B: `docs/reconstruction/reviews/B_aa_006173a0_Map_ConstructIntKeyNode_0x18.md`
- Report: `docs/agents/task-dual-ab-009210e0-006173a0-w18l-report.md`

## Callers / callees

**Callees:** `operator_new` (`0x00489892`).

**Callers (14):** `Map_InsertNodeAndRebalance_IntKey` (`0x005d20b0`), `FUN_0041cd70`, `FUN_004a6d80`, `FUN_004af140`, `FUN_004e3420`, `FUN_0050f710`, `FUN_0051c510`, `FUN_00539620`, `FUN_0054de50`, `FUN_005c5d40`, `FUN_00617420`, `FUN_00627930`, `FUN_00676540`, `FUN_00680490`.

## Confidence

| Claim | Level |
|---|---|
| Control flow / stores from decompiler + bytes | **High** |
| `operator_new(0x18)` size | **High** |
| `RET 0x14` + EAX return | **High** |
| Int key/mapped pair layout | **High** (sibling insert dual + stores) |
| Product / mangled C++ name | **Tentative** (`_0x18` size tag) |
