# Function record: Map_InsertNodeAndRebalance_IntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d20b0` |
| **Canonical name** | `Map_InsertNodeAndRebalance_IntKey` |
| **Prior / Ghidra** | `FUN_005d20b0` |
| **Address** | `0x005d20b0` |
| **Body** | `0x005d20b0`–`0x005d229a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (NPC AI post-cast timer map) |
| **Completion status** | **Dual sealed 2026-07-29 (W17-Q)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC-style **`std::map`/`set` node insert + red-black rebalance** for the **int-key / int-value** node family (node **0x18**, color **`+0x14`**, isnil **`+0x15`**). Always allocates and rebalances; does **not** walk or compare keys.

Sole static consumer: `Map_InsertOrFind_IntKey` @ `0x005d2360` (two call sites after miss detection).

Throws `"map/set<T> too long"` when `map->size > 0x1FFFFFFD` (`cmp [edi+8], 0x1FFFFFFE` / `jb` past throw).

## Signature (sealed)

```c
// RET 0x10 — four stack args; this = map in ECX
void __thiscall Map_InsertNodeAndRebalance_IntKey(
    void *map,           // MapShell*  +4 head, +8 size
    void **outNode,      // Node**
    char insertLeft,     // 1=left, 0=right
    void *parent,        // Node* attach point (or head)
    const void *value);  // IntPair* { int32 key; int32 mapped; }
```

## Node layout (via `FUN_006173a0`)

| Offset | Field |
|---|---|
| `+0x00` | left |
| `+0x04` | parent |
| `+0x08` | right |
| `+0x0C` | key (int) |
| `+0x10` | mapped (int) |
| `+0x14` | color (0 red / 1 black) |
| `+0x15` | isnil |
| size | **0x18** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005d20b0_FUN_005d20b0.md` (+ 2026-07-29 residual)
- Annotated: `docs/reconstruction/raw/aa_005d20b0_FUN_005d20b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_InsertNodeAndRebalance_IntKey.cpp`
- Legacy scaffold: `reconstructed-exact/FUN_005d20b0.cpp`, `functions/aa_005d20b0_FUN_005d20b0.md`
- Dual A: `docs/reconstruction/reviews/A_aa_005d20b0_Map_InsertNodeAndRebalance_IntKey.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005d20b0_Map_InsertNodeAndRebalance_IntKey.md`
- Front dual: `A|B_aa_005d2360_Map_InsertOrFind_IntKey.md`

## Callers / callees

| Direction | Symbol | VA | Role |
|---|---|---|---|
| Caller | `Map_InsertOrFind_IntKey` | `0x005d2360` | sole static (×2 sites) |
| Callee | `FUN_006173a0` | `0x006173a0` | node `new(0x18)` |
| Callee | `FUN_004e22d0` | `0x004e22d0` | left-rotate |
| Callee | `FUN_006753b0` | `0x006753b0` | right-rotate |
| Callee | `_CxxThrowException` | `0x006a3d60` | size overflow |

## Confidence

| Claim | Level |
|---|---|
| map/set insert + RB rebalance | **Confirmed** (string + loop) |
| Size throw `"map/set<T> too long"` | **Confirmed** |
| Node 0x18 / color+0x14 / isnil+0x15 | **Confirmed** |
| ABI thiscall `RET 0x10` | **Confirmed** |
| Sole caller `005d2360` | **Confirmed** |
| Not insert-or-find / no key compare | **Confirmed** |
| Product STL / RTTI name | **Open** |
| Runtime / bit-exact | **Open** |
