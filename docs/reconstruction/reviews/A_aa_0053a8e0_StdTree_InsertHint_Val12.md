# Review A (reconstruction fidelity): `aa_0053a8e0` StdTree_InsertHint_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053a8e0` |
| **VA** | `0x0053a8e0` |
| **Body** | `0x0053a8e0`–`0x0053aa43` exclusive (**355** B) |
| **Canonical name** | `StdTree_InsertHint_Val12` (inferred) |
| **Ghidra symbol** | `FUN_0053a8e0` |
| **Prior / alias** | `Named_CalleeOf_…_CVOGCharacter_ApplyCreateFromPack_0053a8e0` (narrow) |
| **Review date** | `2026-07-29` (W28-Q OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0053a8e0_StdTree_InsertHint_Val12.md` |
| **System** | std map/set tree insert-with-hint (Val12) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, callers/callees/xrefs, signature (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Unique Val12 map insert using a hint iterator: empty/leftmost/end/neighbor fast paths call `StdTree_InsertAndRebalance_Val12`; otherwise full insert-or-find (`FUN_0053a1a0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0053a8e0_FUN_0053a8e0.md` (+ W28-Q append) |
| Annotated | `docs/reconstruction/raw/aa_0053a8e0_FUN_0053a8e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertHint_Val12.cpp` |
| Twin | `reconstructed-exact/FUN_0053a8e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0053a8e0_StdTree_InsertHint_Val12.md` |
| Live decompile | ≡ raw |
| Live body bytes | `read_memory` entry + epilogue |
| Insert dual | `aa_00539210` StdTree_InsertAndRebalance_Val12 (W27-Q) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `sub esp,8; push esi; push edi; mov edi,ecx` |
| Epilogue | `add esp,8; ret 0x0c` |
| Body end | exclusive `0x0053aa43` (pad `cc` after) |
| isnil | `cmp byte ptr [reg+0x19], 0` in neighbor paths |
| Key | node dword @ +0x0c (`param_3[3]`) |

Entry hex (64 B):

```
83ec0856578bf9837f080075218b44241c8b4f048b74241450516a01568bcfe80ce9ffff5f8bc65e83c408c20c008b47048b74241c538b5c241c3b185575278b
```

Epilogue tail:

```
83c408c20c00  ; add esp,8; ret 0x0c
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size exclusive end | **pass** (`0053aa43`) |
| `ret 0x0c` / 3 stack args | **pass** |
| thiscall ECX=map | **pass** (`mov edi,ecx`) |
| Empty / leftmost / end fast paths | **pass** |
| Prevnode / Nextnode callees | **pass** (`FUN_005ae050` / `FUN_005ae0b0`) |
| Fallthrough InsertOrFind | **pass** (`FUN_0053a1a0`) |
| Val12 isnil@+0x19 | **pass** |
| Clean has no bare `undefined4` in typed path | **pass** |
| Product English | **gap** |
| Nested pred/succ dual seal | **gap** (not OWN) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 0x0c |
| Hint-insert (not always-insert) | **High** | contrast sealed `00539210` |
| Sole caller `FUN_0053af20` | **High** | 1 xref |
| Name `StdTree_InsertHint_Val12` | **Inferred** | MSVC + Val12 family |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product demangle for map of `FUN_0053af20` / create-from-pack path.  
2. Dual seal of `FUN_005ae050` / `FUN_005ae0b0` / `FUN_0053a1a0` (not OWN).  
3. Bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
