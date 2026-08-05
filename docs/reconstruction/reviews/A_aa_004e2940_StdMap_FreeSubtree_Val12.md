# Review A (reconstruction fidelity): `aa_004e2940` StdMap_FreeSubtree_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2940` |
| **VA** | `0x004e2940`–`0x004e2975` |
| **Canonical name** | `StdMap_FreeSubtree_Val12` |
| **Ghidra** | `FUN_004e2940` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W29-L) |
| **Reviewer role** | Independent reconstruction review (clean ≡ bytes; raw decompile residual noted) |
| **Counterpart** | `reviews/B_aa_004e2940_StdMap_FreeSubtree_Val12.md` |
| **System** | STL map/set Val12 subtree free |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

Free an MSVC red-black **subtree** of Val12 nodes (**isnil@+0x19**): recurse right, delete current, walk left until isnil. Used by `StdMap_EraseRange_Val12` full-clear path. Peer family: isnil@+0x15 `StdMap_FreeSubtree_Isnil15_Inferred` (`0x004ba770`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004e2940` |
| Body bytes | `read_memory` 52–64 B @ entry (full `ret 4` + pad `CC`) |
| Meta | `get_function_by_address` / xrefs |
| Peer | `aa_004ba770` FreeSubtree isnil15 |
| Caller dual | W28-P `StdMap_EraseRange_Val12` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, `disassemble_bytes`.

---

## 3. Signature

```c
void StdMap_FreeSubtree_Val12(void *node);
// stack formal; RET 4; ECX threaded unused
```

---

## 4. Control flow: clean ≡ bytes (overrides raw decompiler)

| Stage | Match |
|---|---|
| isnil early return (`+0x19`) | Yes |
| Recurse right `+8` | Yes |
| `operator_delete` returns | Yes (bytes; decompiler false-noreturn) |
| Walk left `+0` until isnil | Yes (bytes/clean; **not** raw decompiler) |
| `ret 4` | Yes |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Subtree free role | **High** | caller + CF |
| Val12 isnil@+0x19 | **High** | `80 7F/7E 19 00` |
| ABI stack + ret 4 | **High** | epilogue |
| Left-walk CF | **High** | bytes seal |
| Product demangle | Open | `_Inferred` not required — Val12 family name matches peers |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product mangled `_Tree` name.
2. Named functions for xrefs `004d968e` / `004d96de`.
3. Runtime / bit-exact.

---

## 7. Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e2940_FUN_004e2940.md` |
| Annotated | `docs/reconstruction/raw/aa_004e2940_FUN_004e2940.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_FreeSubtree_Val12.cpp` |
| Function | `docs/reconstruction/functions/aa_004e2940_StdMap_FreeSubtree_Val12.md` |

**Verdict:** **accept**
