# Review A (reconstruction fidelity): `aa_00439770` RbTree_AllocEmptyNode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00439770` |
| **VA** | `0x00439770` |
| **Canonical name** | `FUN_00439770` |
| **Inferred name** | `RbTree_AllocEmptyNode_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00439770_RbTree_AllocEmptyNode_Inferred.md` |
| **System** | containers / RB-tree |
| **Verdict** | **accept** |

---

## 1. Purpose

Factory for a **0x18-byte** empty tree node used as an RB-map **sentinel seed**: allocate, zero three link dwords, seed flag bytes, return pointer. Does **not** install self-links or map size — those are caller-side (`FUN_004e7450` pattern).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra MCP `decompile_function` @ `0x00439770` |
| Entry bytes | Ghidra MCP `read_memory` length 64 |
| Function meta | `get_function_by_address` body `00439770`–`004397a6` |
| Caller CF | `decompile_function` @ `0x004e7450` |
| Raw | `docs/reconstruction/raw/aa_00439770_FUN_00439770.md` |
| Annotated | `docs/reconstruction/raw/aa_00439770_FUN_00439770.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RbTree_AllocEmptyNode_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00439770_FUN_00439770.md` |

---

## 3. Authoritative CF (bytes + decompile)

```
push 0x18
call operator_new
add  esp, 4
test eax, eax / jz
mov  dword [eax], 0
lea  ecx, [eax+4] / test / mov dword [ecx], 0
lea  ecx, [eax+8] / test / mov dword [ecx], 0
mov  byte [eax+0x14], 1
mov  byte [eax+0x15], 0
ret
```

Body range: **`0x00439770`–`0x004397a6`**. Convention: **cdecl**, **no stack args**, return in **EAX**.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Alloc size `0x18` | **High** | `push 0x18` |
| Zeros at `+0`, `+4`, `+8` | **High** | three `mov dword` |
| `+0x14 = 1`, `+0x15 = 0` | **High** | `c6 40 14 01` / `c6 40 15 00` |
| Returns node* in EAX | **High** | callers assign; analyze warns void is wrong |
| No self-link in this unit | **High** | no stores of `eax` into `[eax+*]` |
| Role = empty RB sentinel seed | **High** | `FUN_004e7450` sets `+0x15=1` + self-links + size 0 |
| Product class name | **Tentative** | `_Inferred` only |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `operator_new(0x18)` | **Yes** |
| Conditional zero `+0` | **Yes** |
| Zero `+4`, `+8` | **Yes** |
| Flag bytes | **Yes** |
| Return pointer (clean/annotated explicit; raw decompiler `void`) | **Yes** (corrected) |

---

## 6. Call graph (this unit)

**Callees:** `operator_new`

**Callers:** ~25 sites including map-header inits (`FUN_004e7450`/`FUN_004e7540`), FxMaster catalog (`FUN_004a1620`), LootManager (`FUN_0050c1b0`), character ctor trees, skill/UI maps.

---

## 7. Gaps / residual

1. Exact MSVC/product node type name.
2. Semantics of `+0x0C`..`+0x13` for non-header nodes of size `0x18`.
3. Runtime / bit-exact not run.

**Verdict:** **accept** — size, flags, return, and sentinel-factory role sealed.
