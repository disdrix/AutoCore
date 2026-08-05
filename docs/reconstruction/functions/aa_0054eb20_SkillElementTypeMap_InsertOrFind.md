# Function record: SkillElementTypeMap_InsertOrFind

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054eb20` |
| **Canonical name** | `SkillElementTypeMap_InsertOrFind` (Ghidra `FUN_0054eb20`; **Inferred**) |
| **Address** | `0x0054eb20` |
| **Body** | `0x0054eb20`–`0x0054ebd7` (three `ret 8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (skill-element type factory catalog) |
| **Completion status** | **Dual sealed 2026-07-29 W19-L** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC `std::map`-style **insert-or-find** for **int type-id** keys → **pointer** mapped factory instances (RB tree, node size **0x18**, isnil **`+0x15`**). On miss inserts and rebalances via `FUN_0054de50`; on equal key returns existing iterator with `inserted=0` and **does not** update the mapped field.

Sole static caller: `SkillElementFactory_RegisterCatalog` (`0x0054a640`) — **39** registration sites.

## Signature (sealed)

```c
// RET 0x8 — two stack args; this = map in ECX
void __thiscall SkillElementTypeMap_InsertOrFind(
    void *this,              // MapShell*
    void *pOutPair,          // InsertPair* { node* it; uint8_t inserted; }
    const void *pValue);     // { int32 typeId; void* factory; }
```

## Node layout (sealed via insert path `FUN_0054de50` → `FUN_006173a0`)

| Offset | Field |
|---|---|
| `+0x00` | left |
| `+0x04` | parent |
| `+0x08` | right |
| `+0x0C` | key (int type id) |
| `+0x10` | mapped (factory*) |
| `+0x14` | color |
| `+0x15` | isnil |
| size | **0x18** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0054eb20_FUN_0054eb20.md`
- Annotated: `docs/reconstruction/raw/aa_0054eb20_FUN_0054eb20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/SkillElementTypeMap_InsertOrFind.cpp`
- Clean (FUN alias): `docs/reconstruction/reconstructed-exact/FUN_0054eb20.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0054eb20_SkillElementTypeMap_InsertOrFind.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0054eb20_SkillElementTypeMap_InsertOrFind.md`

## Callers / callees

| Direction | Symbol | VA | Role |
|---|---|---|---|
| Caller | `SkillElementFactory_RegisterCatalog` | `0x0054a640` ×39 | catalog bootstrap inserts |
| Callee | `FUN_0054de50` | `0x0054de50` | insert + rebalance |
| Callee | `FUN_005a2850` | `0x005a2850` | predecessor |
| (via insert) | `FUN_006173a0` | `0x006173a0` | node `new(0x18)` |

## Confidence

| Claim | Level |
|---|---|
| Control flow insert-or-find | **Confirmed** |
| ABI `RET 0x8` / out-pair layout | **Confirmed** |
| Node 0x18 / key+0xC / isnil+0x15 | **Confirmed** |
| Equal key does not rewrite mapped | **Confirmed** |
| Sole static caller catalog register | **Confirmed** |
| Product / RTTI map name | **Open** |
| Runtime / bit-exact | **Open** |
