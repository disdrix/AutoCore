# Function record: StdMap_InsertWithHint_IntKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00569560` |
| **Canonical name** | `StdMap_InsertWithHint_IntKey_Inferred` |
| **Ghidra name** | `FUN_00569560` |
| **Address** | `0x00569560` |
| **Body range** | `0x00569560`–`0x005696c3` (356 bytes; `ret 0x0C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / MSVC ordered map insert-with-hint |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + node key/isnil sealed; value payload size open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00569560_StdMap_InsertWithHint_IntKey_Inferred.md`, `reviews/B_aa_00569560_StdMap_InsertWithHint_IntKey_Inferred.md` (2026-07-29 W21-G) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00569560`
- Prior scaffold chain name `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00569560` — **do not use** (xref-seed only)

## Purpose

MSVC-style **`std::map`/`set` insert-with-hint by int key**: validate hint (empty / leftmost / end / neighbor via pred-succ); RB-insert when valid; else full insert-or-find. Returns iterator via out param.

## Signature

```c
uint32_t * __thiscall StdMap_InsertWithHint_IntKey_Inferred(
    MapShell *map /*ECX*/,
    uint32_t *outIt,   // written node*
    int *hintNode,     // hint iterator
    int *pKey);        // int key (+ node factory payload)
// ret 0x0C
```

## Object layout

| Off | Field |
|---|---|
| map `+0x04` | head / end header* |
| map `+0x08` | size |
| node `+0x00/04/08` | left / parent / right |
| node `+0x0C` | int key |
| node `+0x49` | isnil |

## Algorithm

1. `size==0` → insert left of head.
2. `hint==*head` (leftmost): if `*key < hint.key` insert left of hint.
3. `hint==head` (end): if `rightmost.key < *key` insert right of rightmost.
4. Else: if `*key < hint.key` → predecessor; insert between when order allows (isnil right decides addLeft).
5. Else if `key > hint.key` (SBORROW-aware) → successor; insert when order allows.
6. Else → `FUN_00569320` insert-or-find; `*outIt = pair.it`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00569560_FUN_00569560.md`
- Annotated: `docs/reconstruction/raw/aa_00569560_FUN_00569560.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertWithHint_IntKey_Inferred.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00569560.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00569560_FUN_00569560.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00569560-00799820-w21g-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callers** | `FUN_005697d0` only (1 xref) |
| **Callees** | `FUN_005690a0` (RB insert), `FUN_00537770` (predecessor), `FUN_00568200` (successor), `FUN_00569320` (insert-or-find) |

## Confidence

| Claim | Level |
|---|---|
| Hinted-insert int key CF | **High** |
| `ret 0x0C` thiscall | **High** |
| isnil `+0x49`, key `+0x0C` | **High** |
| map/set family (throw string in insert callee) | **High** |
| Value payload size / domain map | **Open** |
| Runtime / differential | Open |

## Related

| VA | Name | Relation |
|---|---|---|
| `0x00569320` | `StdMap_InsertOrFindByIntKey_Inferred` | fallback when hint invalid |
| `0x00537770` | `Map_Predecessor` | left-neighbor walk |
| `0x00568200` | Map_Successor (not dualed here) | right-neighbor walk |
| `0x005690a0` | RB insert + `"map/set<T> too long"` | physical insert |
