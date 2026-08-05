# Function record: StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043bd40` |
| **Canonical name** | `StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred` |
| **Ghidra name** | `FUN_0043bd40` |
| **Address** | `0x0043bd40` |
| **Body range** | `0x0043bd40`–`0x0043bda5` exclusive (**101** B / `0x65`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black map operator[] / get-or-insert (Val12, u32 key, EAX key*) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + Val12 + unsigned sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0043bd40_StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred.md`, `reviews/B_aa_0043bd40_StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred.md` (2026-08-04 W37-Q) |
| **Last reviewed** | `2026-08-04` |

## Alias

- `FUN_0043bd40`
- Informal: map operator[] / get-or-insert for u32-key Val12 (register key ABI)

## Purpose

MSVC `_Tree` / `std::map` **operator[]-style** get-or-insert for a unique Val12 map with **unsigned** 32-bit keys: lower_bound on key@node+0x0c; on hit return mapped@+0x10; on miss insert `{key,0,0}` via `FUN_0043be60` and return new mapped.

## Signature

```c
int32_t* StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred(
    MapShell_Val12* map,      // ECX; +0x04 head, +0x08 size
    const uint32_t* key);     // EAX (not stack)
// plain RET
// Returns &node->val1 (node+0x10)
```

## Algorithm

1. `candidate = head`; `node = head->left` (root).
2. While `!node->isnil`: if `node->key < *key` (unsigned) go right else `candidate = node` and go left.
3. If `candidate != head && candidate->key <= *key` → return `&candidate->val1`.
4. Else `Val12 v = {*key, 0, 0}`; insert-hint via `FUN_0043be60`; return `&outIt->val1`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0043bd40_FUN_0043bd40.md`
- Annotated: `docs/reconstruction/raw/aa_0043bd40_FUN_0043bd40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0043bd40.cpp`
- Function FUN_*: `docs/reconstruction/functions/aa_0043bd40_FUN_0043bd40.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-009701d0-0043bd40-w37q-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_0043be60` only (unowned insert-hint) |
| **Callers** | `FUN_0073e3a0` @ `0073e43e`; `FUN_0096eec0` @ `0096ef4a`; `FUN_0072a660` @ `0072a974`; `FUN_0098d870` @ `0098d983`; `00733896` (5 xrefs) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ bytes | **High** |
| ECX map + EAX key* + plain ret | **High** |
| Val12 isnil@+0x19 / key@+0x0c / mapped@+0x10 | **High** |
| Unsigned compare | **High** |
| operator[] get-or-insert role | **High** |
| Product English / demangle | **Inferred** |
| Insert helper full ABI | Unowned |
| Runtime / differential | Open |

## Related

- Signed thiscall twin: `aa_0053af20` `StdTree_OperatorIndex_Val12` (W29-Q) — **different ABI + signed key**
- Insert-hint peer family: W28-Q `StdTree_InsertHint_Val12` (`0x0053a8e0`) — different helper
- Consumers: effect manager ctor (`FUN_0073e3a0`), NestedHash host (`FUN_0096eec0` / W35-S), Z-fill (`FUN_0098d870`)
