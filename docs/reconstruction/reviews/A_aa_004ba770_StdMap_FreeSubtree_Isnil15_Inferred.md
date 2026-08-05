# Review A (reconstruction fidelity): `aa_004ba770` StdMap_FreeSubtree_Isnil15_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ba770` |
| **VA** | `0x004ba770`–`0x004ba7a4` |
| **Canonical name** | `StdMap_FreeSubtree_Isnil15_Inferred` |
| **Prior scaffold** | `FUN_004ba770` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004ba770_StdMap_FreeSubtree_Isnil15_Inferred.md` |
| **System** | STL map/set (isnil `+0x15`) |
| **Agent** | W20-N OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Free a red-black map/set subtree** of nodes with isnil at `+0x15`:

1. If isnil → return.
2. Else recurse free **right @ +8**, `operator_delete` current, advance via **left @ +0**, loop until isnil.

Used by `StdMap_EraseRange_Inferred` full-clear path (`FUN_004ba770(head->parent)`) and NDSpecialFX map teardown.

**Not** a single-node erase (that is `FUN_004baa30` with throw string), not list unlink.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ba770_FUN_004ba770.md` (+ v2026-07-29) |
| Annotated | `docs/reconstruction/raw/aa_004ba770_FUN_004ba770.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_FreeSubtree_Isnil15_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004ba770.cpp` |
| Function record | `docs/reconstruction/functions/aa_004ba770_FUN_004ba770.md` |
| Live decompile | Ghidra `0x004ba770` (2026-07-29) — **collapsed** (misses left-walk) |
| Machine | `read_memory` full body; ends `C2 04 00` |
| Parent duals | `A\|B_aa_004bacf0_StdMap_EraseRange_Inferred`; `A_aa_004b85d0_*` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, ledgers.

---

## 3. Signature / layout

```c
// stack node*; ret 4; ECX threaded unused
void __stdcall StdMap_FreeSubtree_Isnil15_Inferred(void *node);
```

| Offset | Role |
|---|---|
| `+0` | left* (walk after free) |
| `+4` | parent* (unused here) |
| `+8` | right* (recurse free) |
| `+0x15` | isnil byte |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Subtree free role | **Confirmed** | callers + CF |
| ABI stack + `ret 4` | **Confirmed** | epilogue bytes |
| isnil `+0x15` | **Confirmed** | `80 7F 15 00` |
| Right recurse + left walk | **Confirmed** | bytes; decompiler incomplete |
| `operator_delete` returns | **Confirmed** | left-walk after call |
| Clean ≡ bytes CF | **Confirmed** | left-walk restored |
| Product STL name | **Open** | `_Inferred` |
| Runtime / bit-exact | **Open** | |

---

## 5. Control flow: clean ≡ bytes (overrides raw decompiler)

| Stage | Match |
|---|---|
| isnil early return | **Yes** |
| Recurse right `+8` | **Yes** |
| delete self | **Yes** |
| Walk left `+0` until isnil | **Yes** (bytes/clean; **not** raw decompiler) |
| No invent of value dtor | **Yes** |

---

## 6. Gaps

- Product mangled `_Tree` name.
- Whether value payloads are always pre-destroyed by callers (erase path yes; plain free assumes node-only).
- Runtime golden.
