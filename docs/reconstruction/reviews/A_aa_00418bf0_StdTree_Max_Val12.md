# Review A (reconstruction fidelity): `aa_00418bf0` StdTree_Max_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418bf0` |
| **VA** | `0x00418bf0` |
| **Body** | `0x00418bf0`–`0x00418c0b` exclusive (**27** B) |
| **Canonical name** | `StdTree_Max_Val12` (inferred) |
| **Ghidra symbol** | `FUN_00418bf0` |
| **Review date** | `2026-07-29` (W28-O OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00418bf0_StdTree_Max_Val12.md` |
| **System** | MSVC std `_Tree` max / rightmost (Val12) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_xrefs` (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Return the rightmost non-nil node in the subtree rooted at `node` (MSVC `_Tree_max`). Leaf walk; no tree mutation.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00418bf0_FUN_00418bf0.md` (+ W28-O append) |
| Annotated | `docs/reconstruction/raw/aa_00418bf0_FUN_00418bf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Max_Val12.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_00418bf0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00418bf0_StdTree_Max_Val12.md` |
| Live decompile | ≡ raw void CF (**defect** — not sealed as CF) |
| Live body bytes | `read_memory` @ `0x00418bf0` length 27 (+ pad) |
| Twin min | `aa_005adfa0` StdTree_Min_Val12 |
| Neighbor | `StdTree_Rrotate_Val12` @ `0x00418c10` |
| Consumer duals | erase units assign EAX to `head->right` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body exclusive end | `0x00418c0b` (`CC` pad; next fn `00418c10`) |
| Size | **27** B |
| Epilogue | single `C3` (`ret`) — cdecl |
| isnil test | `80 79 19 00` / `CMP BYTE PTR [ECX+0x19], 0` |
| Right link | `MOV ECX, [EAX+8]` |
| Leaf | 0 callees |

Full body hex:

```
8b4424048b480880791900750e8d49008bc18b48088079190074f5c3
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** (both defective void) |
| Body size exclusive end | **pass** (`00418c0b`) |
| `RET` / 1 stack arg cdecl | **pass** |
| Return node* in EAX | **pass** (callers; leave EAX) |
| Tree_max CF (bytes) | **pass** |
| Nil test isnil@+0x19 | **pass** |
| Clean follows **bytes** not void decomp | **pass** |
| Shared (not skill-only) | **pass** (6 Val12 erase callers) |
| Product demangle | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI (bytes) | **High** | hex seal; cdecl ret |
| Tree_max identity | **High** | classical right walk |
| Val12 layout | **High** | isnil@+0x19; family match |
| Name `StdTree_Max_Val12` | **Inferred** | structural; not plate |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product / MSVC demangle for each map type that instantiates this helper.  
2. Bit-exact / differential — open.  
3. Scaffold `Named_*RecvSkillStatusEffect*` alias is narrow.

**Verdict:** **accept**
