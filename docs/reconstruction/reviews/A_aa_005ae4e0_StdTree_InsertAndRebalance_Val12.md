# Review A (reconstruction fidelity): `aa_005ae4e0` StdTree_InsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae4e0` |
| **VA** | `0x005ae4e0` |
| **Body** | `0x005ae4e0`–`0x005ae6ca` exclusive (**490** B) |
| **Canonical name** | `StdTree_InsertAndRebalance_Val12` (inferred) |
| **Ghidra symbol** | `FUN_005ae4e0` |
| **Prior / alias** | `Named_CalleeOf_Named_CalleeOf_Mission_MissionStopLimit_005ae4e0` (narrow) |
| **Review date** | `2026-07-29` (W27-T OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005ae4e0_StdTree_InsertAndRebalance_Val12.md` |
| **System** | std map/set tree insert + RB rebalance |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Always-insert a Val12 red-black tree node (buy via `StdTree_Buynode_Val12`), link under `where`, rebalance while parent is red, paint root black, write `*outIt`. Throw on size overflow.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005ae4e0_FUN_005ae4e0.md` (+ W27-T append) |
| Annotated | `docs/reconstruction/raw/aa_005ae4e0_FUN_005ae4e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val12.cpp` |
| Scaffold | `reconstructed-exact/FUN_005ae4e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005ae4e0_StdTree_InsertAndRebalance_Val12.md` |
| Live decompile | equiv raw |
| Live body bytes | `read_memory` entry + epilogue |
| Buynode dual | `aa_005ae220` StdTree_Buynode_Val12 (W24-I accept) |
| Peer insert | `aa_0051c1c0` Map_TreeInsertAndRebalance_Val12 (W25-G) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | SEH `LAB_009a65a2`; `sub esp,0x44`; `mov edi,ecx` |
| Size gate | `cmp [edi+8], 0x15555553` in first 32 B |
| Epilogue | `add esp,0x50; ret 0x10` |
| Body end | exclusive `0x005ae6ca` (pad `cc` after) |
| Throw string | `"map/set<T> too long"`; ThrowInfo `DAT_00acc388` |
| Buynode call | `FUN_005ae220(..., color=0)` |
| Color / isnil | +0x18 / +0x19 (Val12) |

Entry hex (32 B):

```
64a1000000006aff68a2659a00506489250000000083ec44578bf9817f085455
```

Epilogue tail:

```
83c450c21000  ; add esp,0x50; ret 0x10
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile equiv raw | **pass** |
| Body size exclusive end | **pass** (`005ae6ca`) |
| `ret 0x10` / 4 stack args | **pass** |
| thiscall ECX=map | **pass** (`mov edi,ecx`) |
| Max-size constant `0x15555553` | **pass** |
| Throw string identity | **pass** |
| Buynode = `FUN_005ae220` color 0 | **pass** |
| Link empty / left / right cases | **pass** |
| RB recolor + rotate callouts | **pass** (decomp CF) |
| Clean has no bare `undefined4` | **pass** (`uint32_t` / `int32_t`) |
| Product demangle | **gap** |
| Buynode null-check | **gap** (not in decomp) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live equiv raw; ret 0x10 |
| Val12 node layout | **High** | paired with sealed buynode |
| Sole caller FUN_005aed20 | **High** | 2 xrefs only |
| Name `StdTree_InsertAndRebalance_Val12` | **Inferred** | structural; not plate |
| Distinct from `0x0051c1c0` peer | **High** | different VA/SEH/caller |
| Runtime / differential | Open | |

---

## 6. Verdict

**accept-with-gaps** — CF, ABI, Val12 layout, throw constant, buynode, and sole caller sealed. Gaps: product demangle, OOM path, runtime.
