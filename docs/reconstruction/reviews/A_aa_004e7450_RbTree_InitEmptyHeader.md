# Review A (reconstruction fidelity): `aa_004e7450` RbTree_InitEmptyHeader

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e7450` |
| **VA** | `0x004e7450` |
| **Body** | `0x004e7450`–`0x004e747a` (43 bytes) |
| **Canonical name** | `RbTree_InitEmptyHeader` |
| **Prior scaffold** | `FUN_004e7450` |
| **Review date** | `2026-07-29` (W22-R dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004e7450_RbTree_InitEmptyHeader.md` |
| **System** | containers / RB-tree |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Initialize an **empty map/tree header** in place: allocate a 0x18 sentinel via sealed `RbTree_AllocEmptyNode_Inferred`, mark head (`+0x15=1`), self-link left/parent/right, set size 0, return `this`.

Called repeatedly from large object construction (`FUN_004d8a10` — Client init chain) for embedded tree members.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004e7450` |
| Bytes | `read_memory` 48 B — thiscall, call AllocEmptyNode, stores, ret |
| Bounds | `get_function_by_address` body `004e7450`–`004e747a` |
| Callees | `get_function_callees` → `00439770` only |
| Callers | `FUN_004d8a10` ×4 + additional xrefs |
| Nested | sealed W18-S `RbTree_AllocEmptyNode_Inferred` |
| Sibling note | `FUN_004e7420` different factory / `+0x19` |
| Raw / clean | `aa_004e7450_*`, `RbTree_InitEmptyHeader.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` ECX=header | **Confirmed** | `56 8B F1` |
| Callee `FUN_00439770` | **Confirmed** | rel32 + W18-S seal |
| `header+4 = node` | **Confirmed** | `89 46 04` |
| `node+0x15 = 1` | **Confirmed** | `C6 40 15 01` |
| Self-link parent/left/right | **Confirmed** | stores to `+4`, `+0`, `+8` |
| `header+8 = 0` size | **Confirmed** | `C7 46 08 00 00 00 00` |
| Return this in EAX | **Confirmed** | `8B C6 5E C3` |
| Empty-tree role | **Confirmed** | matches MSVC empty `_Tree` head pattern |
| Product typedef name | **Inferred** | role-sealed |
| Null-node OOM path | **Confirmed residual** | no null check (retail) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Save this / call alloc | Yes |
| Store head | Yes |
| Head flag +0x15 | Yes |
| Self-links | Yes (order parent→left→right in bytes) |
| Size 0 | Yes |
| Return this | Yes |

---

## 5. Gaps / open

1. Product C++ type name of header / key payload in 0x18 node.
2. Whether `header+0` is a separate field (untouched).
3. Runtime OOM behavior / bit-exact / differential.
4. Relationship of data xrefs at `0x009c0b05` (not expanded; ownership is this VA body only).

**Verdict:** **accept**
