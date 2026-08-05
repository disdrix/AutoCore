# Function record: StdTree_OperatorIndex_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053af20` |
| **Canonical name** | `StdTree_OperatorIndex_Val12` (Inferred) |
| **Ghidra name** | `FUN_0053af20` |
| **Address** | `0x0053af20` |
| **Body range** | `0x0053af20`–`0x0053af91` exclusive (**113** B / `0x71`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black map operator[] / get-or-insert (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + Val12 + callee sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0053af20_StdTree_OperatorIndex_Val12.md`, `reviews/B_aa_0053af20_StdTree_OperatorIndex_Val12.md` (2026-07-29 W29-Q) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_0053af20`
- `Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket_0053af20` (legacy scaffold — **narrow**)

## Purpose

MSVC `_Tree` / `std::map` **operator[]-style** get-or-insert for a unique Val12 map: lower_bound on signed key@node+0x0c; on hit return mapped@+0x10; on miss insert `{key,0,0}` via `StdTree_InsertHint_Val12` and return new mapped.

## Signature

```c
int32_t* __thiscall StdTree_OperatorIndex_Val12(
    MapShell_Val12* map,   // ECX; +0x04 head, +0x08 size
    const int32_t* key);   // stack
// RET 0x04
// Returns &node->val1 (node+0x10)
```

## Algorithm

1. `candidate = head`; `node = head->left` (root).
2. While `!node->isnil`: if `node->key < *key` go right else `candidate = node` and go left.
3. If `candidate != head && candidate->key <= *key` → return `&candidate->val1`.
4. Else `Val12 v = {*key, 0, 0}`; `InsertHint(map, &outIt, candidate, &v)`; return `&outIt->val1`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0053af20_FUN_0053af20.md`
- Annotated: `docs/reconstruction/raw/aa_0053af20_FUN_0053af20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_OperatorIndex_Val12.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0053af20.cpp`
- Function FUN_*: `docs/reconstruction/functions/aa_0053af20_FUN_0053af20.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0053af20-006cac60-w29q-report.md`
- Scratch: `docs/reconstruction/tmp/a_0053af20.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_0053a8e0` StdTree_InsertHint_Val12 (W28-Q) |
| **Callers** | `FUN_005305b0` @ `005305e6`; `FUN_00530610` @ `00530646`; `CVOGCharacter_ApplyCreateFromPacket` @ `005352ee` (3 xrefs) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 0x04` + thiscall ECX=map | **High** |
| Val12 isnil@+0x19 / key@+0x0c / mapped@+0x10 | **High** |
| operator[] get-or-insert role | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Insert hint: `aa_0053a8e0` StdTree_InsertHint_Val12 (W28-Q)
- Insert rebalance: `aa_00539210` StdTree_InsertAndRebalance_Val12 (W27-Q)
- Mission counter consumers: `FUN_005305b0` / `FUN_00530610`
