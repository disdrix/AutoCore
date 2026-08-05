# Review A (reconstruction fidelity): `aa_0044e100` RbTree_AllocEmptyNode_0x30

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e100` |
| **VA** | `0x0044e100`–`0x0044e136` |
| **Canonical name** | `RbTree_AllocEmptyNode_0x30` |
| **Prior scaffold** | `FUN_0044e100` |
| **Review date** | `2026-07-29` (W21-O OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction fidelity — Path A |
| **Counterpart** | `reviews/B_aa_0044e100_RbTree_AllocEmptyNode_0x30.md` |
| **System** | containers / RB-tree |
| **Verdict** | **accept** — size, three-link zeros, flag bytes, EAX return, factory-only role sealed |

**Tools:** Ghidra `decompile_function` + `read_memory` (body). No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Factory for a **0x30-byte** empty tree node used as an RB-map **sentinel seed**: allocate, zero three link dwords, seed flag bytes, return pointer. Does **not** install self-links or map size — those are caller-side (`Profiler_Zone_Ctor` / serialize paths).

Primary use: larger-value `std::map`/`_Tree` headers (profiler name→child map, asset string tables, etc.).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0044e100_FUN_0044e100.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0044e100_FUN_0044e100.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RbTree_AllocEmptyNode_0x30.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0044e100.cpp` |
| Function record | `docs/reconstruction/functions/aa_0044e100_RbTree_AllocEmptyNode_0x30.md` |
| Live decompile | `decompile_function` `0x0044e100` — **≡** raw |
| Live bytes | `read_memory` `0x0044e100` length 64 — `6a 30`…`c6 40 2c 01 c6 40 2d 00 c3` |
| Sibling | `aa_00439770` 0x18 twin (flags at +0x14/+0x15) |
| Caller context (not owned) | Profiler_Zone_Ctor `0x00786280` — sets `+0x2d=1` + self-links |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| cdecl, 0 stack args | bare `ret` (`c3`); no `ret n` |
| Body range | Ghidra `0044e100`–`0044e136` |
| Return | **EAX = node\***; decomp `void` is surface |
| Callee | `operator_new` only |

```c
void * __cdecl RbTree_AllocEmptyNode_0x30(void);
```

### 3.2 Node seed layout — **SEALED**

| Rel | Role | Conf |
|---:|---|---|
| `+0x00` | left* ← 0 | **High** |
| `+0x04` | parent* ← 0 | **High** |
| `+0x08` | right* ← 0 | **High** |
| `+0x2c` | flag ← **1** | **High** (English color black **Probable**) |
| `+0x2d` | flag ← **0** | **High** (English isnil; callers set 1 for header **High**) |

### 3.3 Split construction — **SEALED**

This unit ≠ complete empty map. Caller pattern (Profiler_Zone_Ctor):

```
head = Alloc0x30();
head[+0x2d] = 1;
head.L = head.P = head.R = head;
size = 0;
```

### 3.4 Three-rep CF fidelity

| Pass | Match |
|---|---|
| Raw 2026-07-23 | baseline |
| Live re-decompile 2026-07-29 | **≡** raw |
| Bytes | `push 0x30`, flags `2c/2d`, bare `ret` |

---

## 4. Call graph (inventory)

| Direction | Symbol | VA | Note |
|---|---|---|---|
| Callee | `operator_new` | `0x00489892` | size 0x30 |
| Caller | Profiler_Zone_Ctor | `0x00786280` | map head @ zone+0x20 |
| Caller | FUN_005abfa0 / 00744a60 / 00492dd0 / 0055c870 / 0099b8e0 | various | map headers |
| Sibling | RbTree_AllocEmptyNode_Inferred | `0x00439770` | 0x18 size twin |

---

## 5. Gaps / open

1. Product/PDB English / value_type for 0x30 payload.
2. Exhaustive census of which maps use 0x30 vs 0x18 factories.
3. Runtime / bit-exact / differential — open.
4. OOM: null `new` path not crash-proof (same family as 0x18 sibling).

---

## 6. Verdict

**accept** — dual-ready factory: size, flags, zeros, return, and split-construction role sealed. Residual naming/OOM only.
