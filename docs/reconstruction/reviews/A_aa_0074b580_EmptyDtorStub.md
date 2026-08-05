# Review A (reconstruction fidelity): `aa_0074b580` EmptyDtorStub

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074b580` |
| **VA** | `0x0074b580`–`0x0074b581` exclusive (**1 B**) |
| **Canonical name** | `EmptyDtorStub` |
| **Ghidra name** | `FUN_0074b580` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-B) |
| **Counterpart** | `reviews/B_aa_0074b580_EmptyDtorStub.md` |
| **System** | shared empty leaf |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Shared empty leaf — single-byte `ret`. Multi-role: trivial member dtor stubs (ListTrackedObj offsets), MSVC EH Unwind targets, and other owner call sites. **Zero side effects.**

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-B append) | `docs/reconstruction/raw/aa_0074b580_FUN_0074b580.md` |
| Annotated | `docs/reconstruction/raw/aa_0074b580_FUN_0074b580.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EmptyDtorStub.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0074b580.cpp` |
| Function record | `docs/reconstruction/functions/aa_0074b580_EmptyDtorStub.md` |
| Live | decompile `return;` ≡ `c3` |

---

## 3. Signature (sealed)

```c
// bare C3; body ignores ECX / stack args
void EmptyDtorStub(void);
```

| Formal | Source | Conf |
|---|---|---|
| args | none used | **High** |
| return | void | **High** |
| body size | 1 B | **High** |

---

## 4. Control flow

```
ret
```

| Stage | Match | Conf |
|---|---|---|
| Empty body | decompile ≡ `c3` | **High** |
| No callees | analyze_function_complete stub | **High** |
| Multi-role xrefs | 20 CALL sites | **High** |
| Distinct from EmptyRet `0x0056f570` | different VA | **High** |

### Callers (sealed sample)

| Caller | Role |
|---|---|
| `ListTrackedObj_CompleteDtor` ×3 | empty member dtor @ +0x474 / +0x444 / +0x414 |
| `Unwind@009a…` | EH no-op dtor |
| `FUN_004921e0` / `00496410` / `00496600` / `00496920` | other owners |

---

## 5. Gaps

1. Original PDB symbol.  
2. Exhaustive product English per thiscall offset.  
3. Runtime vacuous.

**Verdict:** **accept** — 1-byte empty ret **fully sealed**.
