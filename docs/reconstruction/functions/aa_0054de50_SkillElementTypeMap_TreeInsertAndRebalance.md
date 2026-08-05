# Function record: SkillElementTypeMap_TreeInsertAndRebalance

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054de50` |
| **Canonical name** | `SkillElementTypeMap_TreeInsertAndRebalance` |
| **Ghidra name** | `FUN_0054de50` |
| **Address** | `0x0054de50` |
| **Body** | `0x0054de50`–`0x0054e03a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual-sealed 2026-07-29 W20-B** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_0054de50`
- Scaffold chain: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0054de50` (**misleading sole role**)
- Parent dual role name: `TreeInsertAndRebalance` (from `SkillElementTypeMap_InsertOrFind`)

## Purpose

MSVC-style `_Tree` **always-insert + red-black rebalance** for the skill-element type→factory map (node size **0x18**). Throws `"map/set<T> too long"` if `size > 0x1ffffffd`. Parent `SkillElementTypeMap_InsertOrFind` (`0x0054eb20`) performs key walk and only calls this on miss.

## Signature (byte-sealed)

```c
// __thiscall; RET 0x10
void SkillElementTypeMap_TreeInsertAndRebalance(
    MapShell *map,              // ECX — head@+4, size@+8
    MapNode_IntPtr **outIt,    // *outIt = new node
    char addLeft,               // 1 left / 0 right of where
    MapNode_IntPtr *where,
    const IntPtrPair *value);   // key + mapped* → node+0x0C
```

## Node layout (0x18)

| Off | Field |
|---:|---|
| +0x00 | left* |
| +0x04 | parent* |
| +0x08 | right* |
| +0x0C | key (int type id) |
| +0x10 | mapped (factory*) |
| +0x14 | color (0=red, 1=black) |
| +0x15 | isnil |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0054de50_FUN_0054de50.md`
- Annotated: `docs/reconstruction/raw/aa_0054de50_FUN_0054de50.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/SkillElementTypeMap_TreeInsertAndRebalance.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0054de50.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0054de50_SkillElementTypeMap_TreeInsertAndRebalance.md`
- Review B: `docs/reconstruction/reviews/B_aa_0054de50_SkillElementTypeMap_TreeInsertAndRebalance.md`
- Parent dual: `reviews/A|B_aa_0054eb20_SkillElementTypeMap_InsertOrFind.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller (sole static) | `0x0054eb20` | SkillElementTypeMap_InsertOrFind (×2 sites) |
| Callee | `0x006173a0` | Node construct `new(0x18)` + copy 2 dwords |
| Callee | `0x004e22d0` | Tree rotate |
| Callee | `0x006753b0` | Tree rotate |
| Callee | CRT | string / exception / `_CxxThrowException` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ raw ≡ body bounds | **High** |
| `RET 0x10` + always-insert + RB rebalance | **High** |
| Node `0x18`, color `+0x14`, isnil `+0x15`, 0=red/1=black | **High** |
| Size cap `0x1ffffffd` + throw string | **High** |
| Sole static caller `0x0054eb20` | **High** |
| Product English / typedef name | **Open** |
| Runtime / bit-exact | **Open** |
