# Review A (reconstruction fidelity): `aa_00568200` StdTree_IteratorIncrement_Isnil49

| Field | Value |
|---|---|
| **Stable ID** | `aa_00568200` |
| **VA** | `0x00568200`–`0x0056824a` (74 bytes) |
| **Canonical name** | `StdTree_IteratorIncrement_Isnil49` |
| **Prior scaffold** | `FUN_00568200` |
| **Review date** | `2026-07-29` (W22-B dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00568200_StdTree_IteratorIncrement_Isnil49.md` |
| **System** | shared `client::stdtree` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

In-place **tree/map iterator successor** (`operator++`). Advances the node pointer stored in the iterator object. Nil-at-current is a no-op (already `end()`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00568200` |
| Bytes | `read_memory` 74 B @ entry — `cmp [node+0x49]`, left/right/parent walks, `ret` |
| Bounds | `get_function_by_address` body `00568200`–`0056824a` |
| Callers | `get_function_callers` → journal, two map walkers, insert-with-hint |
| Twin | `aa_004cb270` decompile (same CF, is_nil @ `+0x29`) |
| Raw / clean | `aa_00568200_*`, `StdTree_IteratorIncrement_Isnil49.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__fastcall` ECX=`node**`; `ret` | **Confirmed** | `8b 01` uses `[ecx]`; epilogue `c3` |
| is_nil @ `+0x49` | **Confirmed** | every guard `80 xx 49 00` |
| Links +0 left / +4 parent / +8 right | **Confirmed** | decompile ≡ bytes |
| Right-subtree leftmost path | **Confirmed** | first arm |
| Parent climb while right-child | **Confirmed** | second arm |
| Clean ≡ raw ≡ live | **Confirmed** | re-verify 2026-07-29 |
| Not id-vector fill | **Confirmed** | no vector push; leaf |
| Product template English | **Inferred** | role-sealed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Nil guard early out | Yes |
| Right non-nil → leftmost | Yes |
| Right nil → parent climb | Yes |
| `*it` store | Yes |
| No callees | Yes |

---

## 5. Gaps / open

1. Color bit offset (unused by this unit; sibling node ctor uses `+0x48` on 0x50 nodes).
2. Per-site map key/value product types.
3. Runtime / bit-exact / differential.

**Verdict:** **accept**
