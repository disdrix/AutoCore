# Function record: StdMap_Find_Tfid_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cba00` |
| **Canonical name** | `StdMap_Find_Tfid_Isnil29_Inferred` |
| **Ghidra name** | `FUN_004cba00` |
| **Address** | `0x004cba00`–`0x004cba51` (**82 B** / `0x52`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (STL map find residual; TFID key family) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_004cba00_StdMap_Find_Tfid_Isnil29_Inferred.md`, `B_aa_004cba00_StdMap_Find_Tfid_Isnil29_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9G-G OWN-ONLY) |

## Alias

- `FUN_004cba00`
- `Named_CalleeOf_Named_VOG_DEBUG_STOP_004cba00` (scaffold; reject)

## Purpose

Exact-match find over dualed `StdMap_LowerBound_Tfid_Isnil29`: if lower_bound node is not end and `node.key <= key`, write node to `*outIt`; else write head (end). Does not insert or erase.

## Signature (sealed)

```c
void __fastcall StdMap_Find_Tfid_Isnil29_Inferred(
    void* map, void** outIt, const void* pKey);
// ECX=map head@+4; RET 8
```

## Algorithm

1. `lb = StdMap_LowerBound_Tfid_Isnil29(map, pKey)`.
2. If `lb == head` → miss.
3. Else if `node.key <= *pKey` (hi@+0x14 signed, lo@+0x10) → hit `*outIt = lb`.
4. Else miss `*outIt = head`.

## Related

- `aa_004cb4b0` `StdMap_LowerBound_Tfid_Isnil29` (sole callee; W31-N)
- `aa_004c8970` Object TFID map lookup (peer consumer of lower_bound)
- `0x004cc400` insert-or-find residual (not OWN; may follow find at `0x005dd84d`)
- W31-N residual “find shell FUN_004cba00” — **closed**

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report `task-dual-ab-004cba00-00406c00-wq9gg-report.md`
