# Review A (reconstruction fidelity): `aa_00539210` StdTree_InsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539210` |
| **VA** | `0x00539210` |
| **Body** | `0x00539210`–`0x005393fa` exclusive (**490** B) |
| **Canonical name** | `StdTree_InsertAndRebalance_Val12` (inferred) |
| **Ghidra symbol** | `FUN_00539210` |
| **Prior / alias** | `Named_CalleeOf_…_CVOGCharacter_Appl_00539210` (narrow) |
| **Review date** | `2026-07-29` (W27-Q OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00539210_StdTree_InsertAndRebalance_Val12.md` |
| **System** | std map/set tree insert + RB rebalance |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Always-insert a Val12 red-black tree node (buy via `StdTree_Buynode_Val12`), link under `where`, rebalance while parent is red, paint root black, write `*outIt`. Throw on size overflow.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00539210_FUN_00539210.md` (+ W27-Q append) |
| Annotated | `docs/reconstruction/raw/aa_00539210_FUN_00539210.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val12.cpp` |
| Scaffold | `reconstructed-exact/FUN_00539210.cpp` |
| Function record | `docs/reconstruction/functions/aa_00539210_StdTree_InsertAndRebalance_Val12.md` |
| Live decompile | ≡ raw |
| Live body bytes | `read_memory` entry + epilogue |
| Buynode dual | `aa_005ae220` StdTree_Buynode_Val12 (W24-I accept) |
| Peer insert dual | `aa_0051c1c0` Map_TreeInsertAndRebalance_Val12 (W25-G) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `mov edi,ecx`; `cmp [edi+8], 0x15555553` |
| Epilogue | `add esp,0x50; ret 0x10` |
| Body end | exclusive `0x005393fa` (pad `cc` after) |
| String | `"map/set<T> too long"` @ `0x00a1530c` |
| ThrowInfo | `DAT_00acc388` |
| Buynode call | `FUN_005ae220(..., color=0)` |
| Color / isnil | +0x18 / +0x19 |

Entry hex (64 B):

```
64a1000000006aff68a23e9a00506489250000000083ec44578bf9817f08545555157259680c53a1008d4c2408ff15f8629c008d4c2420c744245000000000ff
```

Epilogue tail:

```
83c450c21000  ; add esp,0x50; ret 0x10
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size exclusive end | **pass** (`005393fa`) |
| `ret 0x10` / 4 stack args | **pass** |
| thiscall ECX=map | **pass** (`mov edi,ecx`) |
| Max-size constant `0x15555553` | **pass** |
| Throw string identity | **pass** |
| Buynode = `FUN_005ae220` color 0 | **pass** |
| Link empty / left / right cases | **pass** |
| RB recolor + rotate callouts + inlined Lrotate | **pass** |
| Clean has no bare `undefined4` | **pass** |
| Product English | **gap** |
| Buynode null-check | **gap** (not in decomp) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 0x10 |
| Val12 node layout | **High** | paired with sealed buynode |
| Multi-caller shared | **High** | 9 xrefs / 2 callers |
| Name `StdTree_InsertAndRebalance_Val12` | **Inferred** | structural; distinguishes sole-caller `Map_*` @ `0051c1c0` |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product demangle for maps of `FUN_0053a1a0` / `FUN_0053a8e0`.  
2. OOM path if buynode returns null.  
3. Bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
