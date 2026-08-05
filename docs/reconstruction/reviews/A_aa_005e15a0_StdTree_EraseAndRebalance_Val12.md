# Review A (reconstruction fidelity): `aa_005e15a0` StdTree_EraseAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e15a0` |
| **VA** | `0x005e15a0`–`0x005e1856` (694 B / `0x2B6`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Val12` (inferred) |
| **Ghidra symbol** | `FUN_005e15a0` |
| **Review date** | `2026-07-29` (W30-L OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005e15a0_StdTree_EraseAndRebalance_Val12.md` |
| **System** | std map/set tree erase + RB rebalance |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Erase one Val12 red-black tree node: throw on nil iterator, unlink + extremity fix, rebalance if erased black, delete node, size--, write `*outIt`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005e15a0_FUN_005e15a0.md` (+ W30-L append) |
| Annotated | `docs/reconstruction/raw/aa_005e15a0_FUN_005e15a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val12_005e15a0.cpp` |
| Scaffold | `reconstructed-exact/FUN_005e15a0.cpp` |
| Function record | `functions/aa_005e15a0_StdTree_EraseAndRebalance_Val12.md` |
| Live decompile | ≡ raw CF; epilogue from bytes |
| Live body bytes | `read_memory` entry + epilogue through `ret 8` |
| Rotate duals | `aa_00573170` / `aa_00418c10` (W26-Q accept) |
| Peer erase | `aa_004e4130` (W27-Q), `aa_00573250` (W27-S) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | SEH `LAB_009a7402`; `cmp byte [node+0x19], 0` |
| String | `"invalid map/set<T> iterator"` @ `0x00a152f0` (`68 f0 52 a1 00`) |
| ThrowInfo | `DAT_00acc34c` |
| Epilogue | `call operator_delete` → size-- → `add esp,0x54; ret 8` |
| Body end | exclusive `0x005e1856` (pad `cc` after) |
| Color / isnil | +0x18 / +0x19 (Val12) |

Entry hex (48 B):

```
64a1000000006aff6802749a00508b4424146489250000000083ec4880781900558be9745968f052a1008d4c240cff15
```

Epilogue tail:

```
8b44241050e8fb7feaff8b450883c40485c05f5e5b760683c0ff8945088b4c24608b44245c89088b4c244c5d64890d0000000083c454c20800
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body exclusive end incl. epilogue | **pass** (`005e1856`) |
| `ret 8` / 2 stack args | **pass** |
| thiscall ECX=map | **pass** |
| isnil throw string | **pass** |
| size-- after delete | **pass** (bytes; decomp miss) |
| RB uses Val12 L/R rotate | **pass** |
| Product demangle of map | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 8 sealed |
| Val12 node layout | **High** | color/isnil match rotates+buynode |
| Sole caller `FUN_005e1990` | **High** | 1 xref |
| Name `StdTree_EraseAndRebalance_Val12` | **Inferred** | structural; not plate |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product demangle for map type of `FUN_005e1990` / mission shell.  
2. Ghidra “unreachable” two-child transplant blocks (medium fidelity).  
3. Full bit-exact rebalance path golden.  
4. Runtime / differential — open.

**Verdict:** **accept-with-gaps**
