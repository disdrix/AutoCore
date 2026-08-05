# Review A (reconstruction fidelity): `aa_0053af20` StdTree_OperatorIndex_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053af20` |
| **VA** | `0x0053af20` |
| **Body** | `0x0053af20`–`0x0053af91` exclusive (**113** B) |
| **Canonical name** | `StdTree_OperatorIndex_Val12` (inferred) |
| **Ghidra symbol** | `FUN_0053af20` |
| **Prior / alias** | `Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket_0053af20` (narrow) |
| **Review date** | `2026-07-29` (W29-Q OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0053af20_StdTree_OperatorIndex_Val12.md` |
| **System** | std map operator[] / get-or-insert (Val12) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, callers/callees/xrefs, signature (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unique Val12 map **operator[]-style** get-or-insert: lower_bound on signed key; on equality return mapped@+0x10; else insert `{key,0,0}` via `StdTree_InsertHint_Val12` and return new mapped.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0053af20_FUN_0053af20.md` (+ W29-Q append) |
| Annotated | `docs/reconstruction/raw/aa_0053af20_FUN_0053af20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_OperatorIndex_Val12.cpp` |
| Twin | `reconstructed-exact/FUN_0053af20.cpp` |
| Function record | `docs/reconstruction/functions/aa_0053af20_StdTree_OperatorIndex_Val12.md` |
| Live decompile | ≡ raw 2026-07-23 |
| Live body bytes | full 113 B via `read_memory` |
| InsertHint dual | `aa_0053a8e0` StdTree_InsertHint_Val12 (W28-Q) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `mov edx,[ecx+4]; mov eax,[edx+4]; sub esp,0xc` |
| isnil | `cmp byte ptr [reg+0x19], 0` |
| Key | signed compare `node[3]` / `[reg+0xc]` vs `*key` |
| Insert call | `call FUN_0053a8e0` (rel32 to `0053a8e0`) |
| Hit return | `lea eax,[edx+0x10]; …; ret 4` |
| Miss return | `mov eax,[eax]; add eax,0x10; …; ret 4` |
| Body end | exclusive `0x0053af91` (pad `cc` after) |

Full body hex (113 B):

```
8b51048b420483ec0c8078190056578b7c241875168b3739700c7d058b4008eb048bd08b008078190074ec3b510474078b073b420c7d2f8b3f33c08944240c8d44240850528d54242033f652897c24148974241ce867f9ffff8b005f83c0105e83c40cc204005f8d42105e83c40cc20400
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size exclusive end | **pass** (`0053af91`, 113 B) |
| `ret 0x04` / 1 stack arg | **pass** |
| thiscall ECX=map | **pass** (`mov edx,[ecx+4]`) |
| lower_bound + equality hit | **pass** |
| Miss → InsertHint Val12 zeros | **pass** |
| Return mapped @ +0x10 | **pass** (both paths) |
| Val12 isnil@+0x19 | **pass** |
| Clean has typed Val12 path | **pass** |
| Product English | **gap** |
| Nested InsertHint dual | **pass** (W28-Q sealed, not residual) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 0x04; full body hex |
| operator[] get-or-insert | **High** | hit/miss both return mapped |
| Sole InsertHint consumer role | **High** | 3 callers; W28-Q noted sole consumer |
| Name `StdTree_OperatorIndex_Val12` | **Inferred** | MSVC + Val12 family |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product demangle for map element type / owner fields (create-from-pack vs mission counters).  
2. Bit-exact / differential — open.  
3. Whether any caller depends on insert-vs-hit distinction (none visible; both return mapped*).

**Verdict:** **accept-with-gaps**
