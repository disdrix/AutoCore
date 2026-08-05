# Review A (reconstruction fidelity): `aa_0058da00` MapFloatTfid_FreeSubtree_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058da00` |
| **VA** | `0x0058da00`–`0x0058da34` |
| **Canonical name** | `MapFloatTfid_FreeSubtree_Isnil29_Inferred` |
| **Ghidra name** | `FUN_0058da00` |
| **Prior scaffold** | `FUN_0058da00` / chain-named PollBound callee alias |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W24-T) |
| **Counterpart** | `reviews/B_aa_0058da00_MapFloatTfid_FreeSubtree_Isnil29_Inferred.md` |
| **System** | shared tree helper / MapFloatTfid |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; parent erase-range |
| **Verdict** | **accept** |

---

## 1. Purpose

**Free a red-black map/set subtree** of MapFloatTfid nodes (isnil at `+0x29`):

1. If isnil → return.
2. Else recurse free **right @ +8**, `operator_delete` current, advance via **left @ +0**, loop until isnil.

Used by `MapFloatTfid_EraseRange_Inferred` full-clear path (`FUN_0058da00(head[1])`).

**Not** a single-node erase (`FUN_0058dc30`), not range iterate.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0058da00_FUN_0058da00.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0058da00_FUN_0058da00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MapFloatTfid_FreeSubtree_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0058da00.cpp` |
| Function record | `docs/reconstruction/functions/aa_0058da00_FUN_0058da00.md` |
| Parent dual | `A/B_aa_0058df60_MapFloatTfid_EraseRange_Inferred` |
| Twin CF | `StdMap_FreeSubtree_Isnil15_Inferred` @ `0x004ba770` |
| Live decompile | **collapsed** (misses left-walk) — same residual as isnil15 twin |
| Machine | `read_memory` 53 B; ends `C2 04 00` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, ledgers.

---

## 3. Signature / layout

```c
// stack node*; ret 4; ECX threaded unused
void MapFloatTfid_FreeSubtree_Isnil29_Inferred(void *node);
```

| Offset | Role |
|---|---|
| `+0` | left* (walk after free) |
| `+4` | parent* (unused here) |
| `+8` | right* (recurse free) |
| `+0x29` | isnil byte |

---

## 4. Control flow: clean ≡ bytes (overrides raw decompiler)

| Stage | Match |
|---|---|
| isnil early return | **Yes** |
| Recurse right `+8` | **Yes** |
| delete self | **Yes** |
| Walk left `+0` until isnil | **Yes** (bytes/clean; **not** raw decompiler) |
| Sole external caller erase-range full clear | **Yes** |
| No invent of value dtor | **Yes** |

---

## 5. Machine bytes (`read_memory`)

Hex body (53 B):
```
5356578b7c2410807f29008bd98bf7751e8b4608508bcbe8e4ffffff8b3657e8febdefff83c404807e29008bfe74e25f5e5bc20400
```

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Subtree free role | **Confirmed** | callers + CF |
| ABI stack + `ret 4` | **Confirmed** | epilogue bytes |
| isnil `+0x29` | **Confirmed** | `80 7F 29 00` |
| Right recurse + left walk | **Confirmed** | bytes; decompiler incomplete |
| `operator_delete` returns | **Confirmed** | left-walk after call |
| Clean ≡ bytes CF | **Confirmed** | left-walk restored |
| Product STL name | **Open** | `_Inferred` |
| Runtime / bit-exact | **Open** | |

---

## 7. Gaps

- Product mangled `_Tree` name.
- Whether value payloads are always pre-destroyed by callers (erase path likely; plain free assumes node-only or POD).
- Runtime golden.

**CF/ABI/isnil sealed; residual is English only.** Verdict **accept**.
