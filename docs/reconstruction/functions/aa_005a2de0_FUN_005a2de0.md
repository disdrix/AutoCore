# Function record: FUN_005a2de0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2de0` |
| **Canonical name** | `FUN_005a2de0` (Ghidra) → **`StdTree_Buynode_Isnil29_Val24_Inferred`** |
| **Address** | `0x005a2de0`–`0x005a2e3a` (**91 B** / `0x5B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std tree / map containers |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_005a2de0_StdTree_Buynode_Isnil29_Val24_Inferred.md`, `B_aa_005a2de0_StdTree_Buynode_Isnil29_Val24_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9F-A OWN-ONLY) |

## Alias

- `FUN_005a2de0`
- Prior scaffold: `Named_CalleeOf_…_Skill_GatherTarget_005a2de0` (**narrow**)
- Named: `StdTree_Buynode_Isnil29_Val24_Inferred`

## Purpose

MSVC `_Tree` **buynode** for isnil@+0x29 maps: `operator_new(0x30)`, wire L/P/R, copy **Val24** (6 dwords) @+0x10, color@+0x28, isnil=0@+0x29. Used by insert `0x004cbb60` and two insert twins.

## Signature (sealed)

```c
void * __stdcall StdTree_Buynode_Isnil29_Val24_Inferred(
    void *left, void *parent, void *right,
    const uint32_t *value6, uint8_t color);
// ret 0x14; EAX = node* (0 on OOM)
```

## Related

- Insert: `aa_004cbb60` `StdTree_InsertAndRebalance_Isnil29_Inferred`
- Peer Val12: `aa_005ae220` `StdTree_Buynode_Val12`
- Extra callers (not dualled here): `FUN_0058da40`, `FUN_005a3310`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005a2de0_FUN_005a2de0.md`
- Annotated: `docs/reconstruction/raw/aa_005a2de0_FUN_005a2de0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Isnil29_Val24_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005a2de0.cpp`
- Named record: `docs/reconstruction/functions/aa_005a2de0_StdTree_Buynode_Isnil29_Val24_Inferred.md`

## Callers / callees

| Direction | Symbol | Note |
|---|---|---|
| Caller | `FUN_004cbb60` @ `004cbbf2` | isnil29 insert |
| Caller | `FUN_0058da40` @ `0058dad2` | insert twin |
| Caller | `FUN_005a3310` @ `005a33a2` | insert twin |
| Callee | `operator_new` | size 0x30 |

## Confidence

| Claim | Level |
|---|---|
| Control flow / buynode role | High |
| RET 0x14 / layout | High |
| Product English | Open (`_Inferred`) |
