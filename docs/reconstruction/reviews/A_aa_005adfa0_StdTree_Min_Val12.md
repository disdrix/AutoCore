# Review A (reconstruction fidelity): `aa_005adfa0` StdTree_Min_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005adfa0` |
| **VA** | `0x005adfa0` |
| **Body** | `0x005adfa0`–`0x005adfba` exclusive (**26** B) |
| **Canonical name** | `StdTree_Min_Val12` (inferred) |
| **Ghidra symbol** | `FUN_005adfa0` |
| **Review date** | `2026-07-29` (W28-O OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005adfa0_StdTree_Min_Val12.md` |
| **System** | MSVC std `_Tree` min / leftmost (Val12) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_xrefs` (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Return the leftmost non-nil node in the subtree rooted at `node` (MSVC `_Tree_min`). Leaf walk; no tree mutation.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005adfa0_FUN_005adfa0.md` (+ W28-O append) |
| Annotated | `docs/reconstruction/raw/aa_005adfa0_FUN_005adfa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Min_Val12.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_005adfa0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005adfa0_StdTree_Min_Val12.md` |
| Live decompile | ≡ raw void CF (**defect** — not sealed as CF) |
| Live body bytes | `read_memory` @ `0x005adfa0` length 26 (+ pad) |
| Twin max | `aa_00418bf0` StdTree_Max_Val12 |
| Consumer duals | erase units (`aa_005ae990`, `aa_004e4130`, …) call site assigns EAX |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body exclusive end | `0x005adfba` (`CC` pad after last `C3`) |
| Size | **26** B |
| Epilogue | single `C3` (`ret`) — cdecl |
| isnil test | `80 79 19 00` / `CMP BYTE PTR [ECX+0x19], 0` |
| Left link | `MOV ECX, [EAX]` / `MOV ECX, [EAX]` in loop |
| Leaf | 0 callees |

Full body hex:

```
8b4424048b0880791900750e8d6424008bc18b088079190074f6c3
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** (both defective void) |
| Body size exclusive end | **pass** (`005adfba`) |
| `RET` / 1 stack arg cdecl | **pass** |
| Return node* in EAX | **pass** (callers; leave EAX) |
| Tree_min CF (bytes) | **pass** |
| Nil test isnil@+0x19 | **pass** |
| Clean follows **bytes** not void decomp | **pass** |
| Shared (not skill-only) | **pass** (6 Val12 erase callers) |
| Product demangle | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI (bytes) | **High** | hex seal; cdecl ret |
| Tree_min identity | **High** | classical left walk |
| Val12 layout | **High** | isnil@+0x19; family match |
| Name `StdTree_Min_Val12` | **Inferred** | structural; not plate |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product / MSVC demangle for each map type that instantiates this helper.  
2. Bit-exact / differential — open.  
3. Scaffold `Named_*RecvSkillStatusEffect*` alias is narrow.

**Verdict:** **accept**
