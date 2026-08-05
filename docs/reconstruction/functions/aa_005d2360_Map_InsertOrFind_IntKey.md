# Function record: Map_InsertOrFind_IntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d2360` |
| **Canonical name** | `Map_InsertOrFind_IntKey` |
| **Address** | `0x005d2360` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (NPC AI post-cast timer map) |
| **Completion status** | **Dual sealed 2026-07-29** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC `std::map`-style **insert-or-find** for int key → int mapped value (RB tree, node size **0x18**, isnil **`+0x15`**). On miss inserts and rebalances; on equal key returns existing iterator with `inserted=0` and **does not** update the mapped field.

Sole static caller: `NPC_TryCastSkillFromSet` arms post-cast deadline on AI controller map shell **`+0x98`**.

## Signature (sealed)

```c
// RET 0x8 — two stack args; this = map in ECX
// Ghidra may still show a phantom unused third stack param — ignore it.
void __thiscall Map_InsertOrFind_IntKey(
    void *this,              // MapShell*
    void *pOutPair,          // InsertPair* { node* it; uint8_t inserted; }
    const void *pValue);     // IntPair* { int32 key; int32 mapped; }
```

## Node layout (sealed via `FUN_006173a0`)

| Offset | Field |
|---|---|
| `+0x00` | left |
| `+0x04` | parent |
| `+0x08` | right |
| `+0x0C` | key (int) |
| `+0x10` | mapped (int) |
| `+0x14` | color |
| `+0x15` | isnil |
| size | **0x18** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005d2360_Map_InsertOrFind_IntKey.md`
- Annotated: `docs/reconstruction/raw/aa_005d2360_Map_InsertOrFind_IntKey.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_InsertOrFind_IntKey.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005d2360_Map_InsertOrFind_IntKey.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005d2360_Map_InsertOrFind_IntKey.md`

## Callers / callees

| Direction | Symbol | VA | Role |
|---|---|---|---|
| Caller | `NPC_TryCastSkillFromSet` | `0x005d1280` site `0x005d18f7` | insert post-cast timer |
| Callee | `FUN_005d20b0` | `0x005d20b0` | insert + rebalance |
| Callee | `FUN_005a2850` | `0x005a2850` | predecessor |
| (via insert) | `FUN_006173a0` | `0x006173a0` | node `new(0x18)` |

## Confidence

| Claim | Level |
|---|---|
| Control flow insert-or-find | **Confirmed** |
| ABI `RET 0x8` / out-pair layout | **Confirmed** |
| Node 0x18 / key+0xC / val+0x10 / isnil+0x15 | **Confirmed** |
| Equal key does not rewrite mapped | **Confirmed** |
| Parameter names in Ghidra prototype | **Noise** (body sealed) |
| Product / RTTI name | **Open** |
| Runtime / bit-exact | **Open** |
