# Review A (reconstruction fidelity): `aa_004e4130` StdTree_EraseAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e4130` |
| **VA** | `0x004e4130` |
| **Body** | `0x004e4130`–`0x004e43e6` exclusive (**694** B) |
| **Canonical name** | `StdTree_EraseAndRebalance_Val12` (inferred) |
| **Ghidra symbol** | `FUN_004e4130` |
| **Prior / alias** | `Named_CalleeOf_…_Named_VOG_DEBUG_ST_004e4130` (narrow) |
| **Review date** | `2026-07-29` (W27-Q OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004e4130_StdTree_EraseAndRebalance_Val12.md` |
| **System** | std map/set tree erase + RB rebalance |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Erase one Val12 red-black tree node: throw on nil iterator, unlink + extremity fix, rebalance if erased black, delete node, size--, write `*outIt`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e4130_FUN_004e4130.md` (+ W27-Q append) |
| Annotated | `docs/reconstruction/raw/aa_004e4130_FUN_004e4130.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val12.cpp` |
| Scaffold | `reconstructed-exact/FUN_004e4130.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e4130_StdTree_EraseAndRebalance_Val12.md` |
| Live decompile | ≡ raw CF; epilogue from bytes |
| Live body bytes | `read_memory` entry + epilogue through `ret 8` |
| Rotate duals | `aa_00573170` / `aa_00418c10` (W26-Q accept) |
| Peer erase | `aa_004baa30` StdMap_EraseIterator_Inferred (isnil@+0x15) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | SEH `LAB_009a1e62`; `cmp byte [node+0x19], 0` |
| String | `"invalid map/set<T> iterator"` @ `0x00a152f0` (`68 f0 52 a1 00`) |
| ThrowInfo | `DAT_00acc34c` |
| Epilogue | `call operator_delete` → size-- → `add esp,0x54; ret 8` |
| Body end | exclusive `0x004e43e6` (pad `cc` after) |
| Color / isnil | +0x18 / +0x19 (Val12) |

Entry hex (64 B):

```
64a1000000006aff68621e9a00508b4424146489250000000083ec4880781900558be9745968f052a1008d4c240cff15f8629c008d4c2424c744245400000000
```

Epilogue tail:

```
8b44241050e86b54faff8b450883c40485c05f5e5b760683c0ff8945088b4c24608b44245c89088b4c244c5d64890d0000000083c454c20800
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body exclusive end incl. epilogue | **pass** (`004e43e6`) |
| `ret 8` / 2 stack args | **pass** |
| thiscall ECX=map | **pass** |
| isnil throw string | **pass** |
| size-- after delete | **pass** (bytes; decomp miss) |
| RB uses Val12 L/R rotate | **pass** |
| Clean has no bare `undefined4` | **pass** |
| Product demangle of map | **gap** |
| `FUN_005ae0b0` product name | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 8 sealed |
| Val12 node layout | **High** | color/isnil match rotates+buynode |
| Sole caller `FUN_004e5120` | **High** | 1 xref |
| Name `StdTree_EraseAndRebalance_Val12` | **Inferred** | structural; not plate |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product demangle for map type of `FUN_004e5120`.  
2. Product names for `FUN_005ae0b0` / min-max helpers.  
3. Full bit-exact rebalance path golden.  
4. Runtime / differential — open.

**Verdict:** **accept-with-gaps**
