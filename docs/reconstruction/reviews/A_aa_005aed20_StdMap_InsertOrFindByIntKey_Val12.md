# Review A (reconstruction fidelity): `aa_005aed20` StdMap_InsertOrFindByIntKey_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005aed20` |
| **VA** | `0x005aed20` |
| **Canonical name** | `StdMap_InsertOrFindByIntKey_Val12` (**Inferred**) |
| **Ghidra** | `FUN_005aed20` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W30-M) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005aed20_StdMap_InsertOrFindByIntKey_Val12.md` |
| **System** | STL map insert-or-find Val12 int key |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **unique insert-or-find**: lower-bound walk comparing signed int key at `value+0` / `node+0x0C`, then either call Val12 always-insert rebalance (`0x005ae4e0`, W27-T) or return existing iterator with `inserted=0`. Predecessor helper `FUN_005ae050` / `StdTree_Dec_Val12` used when inserting left of a non-leftmost node.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005aed20` — **≡ raw 2026-07-23** |
| Body bytes | `read_memory` — exclusive end `0x005aedd8` (**184 B**); three `c2 08 00` |
| Meta / xrefs | `get_function_by_address`, `get_xrefs_to`, `analyze_function_complete`, callers/callees |
| Insert helper | W27-T sealed `aa_005ae4e0` |
| Predecessor | W29-E sealed `aa_005ae050` (isnil@+0x19) |

**Not performed:** Launcher, runtime, bit-exact, ledgers, `disassemble_bytes`.

---

## 3. Signature

```c
void __thiscall StdMap_InsertOrFindByIntKey_Val12(
    void *map, InsertPair *out, const Val12 *value);
// InsertPair: it @+0, inserted byte @+4; RET 8
```

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Root walk int key / isnil@+0x19 | Yes |
| Leftmost fast insert `addLeft=1` | Yes |
| Predecessor then insert | Yes |
| Equal-key hit `inserted=0` | Yes |
| `ret 8` all exits | Yes (bytes ×3) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Insert-or-find (not always-insert) | **High** | hit path + pair out |
| Int key @ +0x0C | **High** | `cmp` / `node[3]` |
| Val12 insert callee `005ae4e0` | **High** | sole insert helper; W27-T |
| Call sites (2) | **High** | `005ad0ae`, `005ada8b` |
| Product demangle | **Tentative** | open |
| Peer merge with `0053a1a0` | **Reject** | different insert helper VA |

---

## 6. Gaps

1. Product map type / English name (CrazyTaxi TimeLimit is one consumer, not the type).
2. Full value payload meaning beyond int key dword0 (TimeLimit also stores Percent @ +0x14).
3. Orphan parse body @ `005ad2f0` not dualed (out of OWN).
4. Runtime / bit-exact / differential — open.

---

## 7. Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005aed20_FUN_005aed20.md` |
| Annotated | `docs/reconstruction/raw/aa_005aed20_FUN_005aed20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFindByIntKey_Val12_005aed20.cpp` |
| Function | `docs/reconstruction/functions/aa_005aed20_StdMap_InsertOrFindByIntKey_Val12.md` |

**Verdict:** **accept-with-gaps**
