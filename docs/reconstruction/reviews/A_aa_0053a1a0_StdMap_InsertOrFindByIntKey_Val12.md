# Review A (reconstruction fidelity): `aa_0053a1a0` StdMap_InsertOrFindByIntKey_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053a1a0` |
| **VA** | `0x0053a1a0` |
| **Canonical name** | `StdMap_InsertOrFindByIntKey_Val12` (**Inferred**) |
| **Ghidra** | `FUN_0053a1a0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W28-P) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053a1a0_StdMap_InsertOrFindByIntKey_Val12.md` |
| **System** | STL map insert-or-find Val12 int key |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **unique insert-or-find**: lower-bound walk comparing signed int key at `value+0` / `node+0x0C`, then either call Val12 always-insert rebalance (`0x00539210`, W27-Q) or return existing iterator with `inserted=0`. Predecessor helper `FUN_005ae050` used when inserting left of a non-leftmost node.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0053a1a0` |
| Body bytes | `read_memory` 200 B (185 B body + pad) |
| Meta / xrefs | `analyze_function_complete` — 1 caller `FUN_0053a8e0` |
| Insert helper | W27-Q sealed `aa_00539210` |
| Predecessor | live `FUN_005ae050` (isnil@+0x19) |

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
| Val12 insert callee | **High** | `00539210` W27-Q |
| Sole caller hint-insert | **High** | `0053a8e0` |
| Product demangle | **Tentative** | open |

---

## 6. Gaps

1. Product map type / English name.
2. Full value payload meaning beyond int key dword0.
3. Runtime / bit-exact / differential — open.

---

## 7. Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0053a1a0_FUN_0053a1a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0053a1a0_FUN_0053a1a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFindByIntKey_Val12.cpp` |
| Function | `docs/reconstruction/functions/aa_0053a1a0_StdMap_InsertOrFindByIntKey_Val12.md` |

**Verdict:** **accept-with-gaps**
