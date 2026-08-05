# Review A (reconstruction fidelity): `aa_004e7420` RbTree_InitEmptyHeader_Node1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e7420` |
| **VA** | `0x004e7420` |
| **Body** | `0x004e7420`–`0x004e744a` (43 bytes) |
| **Canonical name** | `RbTree_InitEmptyHeader_Node1c` |
| **Prior scaffold** | `FUN_004e7420` |
| **Review date** | `2026-07-29` (W23-M dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004e7420_RbTree_InitEmptyHeader_Node1c.md` |
| **System** | containers / RB-tree |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Initialize an **empty map/tree header** in place for the **0x1c-node** flavor: allocate a 0x1c sentinel via `FUN_005ae2b0`, mark head (`+0x19=1`), self-link left/parent/right, set size 0, return `this`.

Called twice from large object construction (`FUN_004d8a10` — Client init chain) for embedded tree members that use the larger node layout.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004e7420` |
| Bytes | `read_memory` 64 B — thiscall, call factory, stores, ret |
| Bounds | `get_function_by_address` body `004e7420`–`004e744a` |
| Callees | `analyze_function_complete` → `005ae2b0` only |
| Nested factory | `decompile_function` + `read_memory` @ `0x005ae2b0` — `operator_new(0x1c)` |
| Callers | `FUN_004d8a10` ×2 |
| Sibling seal | W22-R `aa_004e7450` RbTree_InitEmptyHeader (0x18 / `+0x15`) |
| Raw / clean | `aa_004e7420_*`, `RbTree_InitEmptyHeader_Node1c.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` ECX=header | **Confirmed** | `56 8B F1` |
| Callee `FUN_005ae2b0` | **Confirmed** | rel32 → `0x005ae2b0` |
| Node size **0x1c** | **Confirmed** | factory `push 0x1c; operator_new` |
| `header+4 = node` | **Confirmed** | `89 46 04` |
| `node+0x19 = 1` | **Confirmed** | `C6 40 19 01` |
| Self-link parent/left/right | **Confirmed** | stores to `+4`, `+0`, `+8` |
| `header+8 = 0` size | **Confirmed** | `C7 46 08 00 00 00 00` |
| Return this in EAX | **Confirmed** | `8B C6 5E C3` |
| Distinct from `004e7450` | **Confirmed** | factory + flag offset differ |
| Product typedef name | **Inferred** | role-sealed |
| Null-node OOM path | **Confirmed residual** | no null check (retail) |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Save this / call alloc | Yes |
| Store head | Yes |
| Head flag +0x19 | Yes |
| Self-links | Yes (order parent→left→right in bytes) |
| Size 0 | Yes |
| Return this | Yes |

---

## 5. Gaps / open

1. Product C++ type name of header / key payload in 0x1c node.
2. Whether `header+0` is a separate field (untouched).
3. Full dual of factory `FUN_005ae2b0` (context only here).
4. Runtime OOM behavior / bit-exact / differential.

**Verdict:** **accept**
