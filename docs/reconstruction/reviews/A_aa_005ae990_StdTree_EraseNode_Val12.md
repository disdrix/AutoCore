# Review A (reconstruction fidelity): `aa_005ae990` StdTree_EraseNode_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae990` |
| **VA** | `0x005ae990` |
| **Body** | `0x005ae990`–`0x005aec44` exclusive (**692** B); Ghidra end `005aec16` truncated |
| **Canonical name** | `StdTree_EraseNode_Val12` (inferred) |
| **Ghidra symbol** | `FUN_005ae990` |
| **Review date** | `2026-07-29` (W27-T OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005ae990_StdTree_EraseNode_Val12.md` |
| **System** | std map/set tree single-node erase |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Erase one non-nil Val12 RB tree node; rebalance if black; free node; publish size and successor iterator.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005ae990_FUN_005ae990.md` (+ W27-T append) |
| Annotated | `docs/reconstruction/raw/aa_005ae990_FUN_005ae990.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseNode_Val12.cpp` |
| Function record | `docs/reconstruction/functions/aa_005ae990_StdTree_EraseNode_Val12.md` |
| Live decompile | CF for unlink/rebalance; truncated before size-- |
| Live body bytes | entry nil gate + full epilogue through `ret 8` |
| Sibling insert | `aa_005ae4e0` StdTree_InsertAndRebalance_Val12 |
| Peer erase patterns | Map_EraseNode / StdMap_EraseIterator (other node sizes) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | SEH `LAB_009a65a2`; `sub esp,0x48`; early `cmp byte [node+0x19],0` |
| Throw | `"invalid map/set<T> iterator"`; ThrowInfo `DAT_00acc34c` |
| Delete call | present; decomp falsely marks noreturn |
| size-- | `test eax; jbe; add eax,-1; store size` after delete |
| *outIt | store successor pointer after size update |
| Epilogue | `add esp,0x54; ret 8` (`83c454c20800`) |
| True end | exclusive `0x005aec44` (`cc` pad) |

Entry hex (32 B):

```
64a1000000006aff68a2659a00508b4424146489250000000083ec4880781900
```

Epilogue tail:

```
83c454c20800  ; add esp,0x54; ret 8
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile CF for main body | **pass** |
| False noreturn acknowledged | **pass** (bytes restore tail) |
| `ret 8` / 2 stack args | **pass** |
| thiscall ECX=map | **pass** |
| isnil@+0x19 gate | **pass** |
| Throw string identity | **pass** |
| size-- if >0 | **pass** (bytes) |
| RB rotates callouts | **pass** (decomp) |
| Clean has no bare `undefined4` | **pass** |
| Product demangle | **gap** |
| Full two-child splice detail in clean | **gap** (summarized; raw is authority) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| STL erase role | **High** | throw string + RB |
| ABI ret 8 | **High** | epilogue bytes |
| Val12 layout | **High** | isnil@+0x19 |
| size-- epilogue | **High** | classic trap fixed |
| Sole caller range erase | **High** | 1 xref |
| Name structural | **Inferred** | |
| Runtime / differential | Open | |

---

## 6. Verdict

**accept-with-gaps** — role, ABI, Val12, throw, size--/outIt sealed. Gaps: product demangle, full clean case expansion, runtime.
