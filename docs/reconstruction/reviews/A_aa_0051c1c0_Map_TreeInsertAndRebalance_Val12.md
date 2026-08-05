# Review A (reconstruction fidelity): `aa_0051c1c0` Map_TreeInsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051c1c0` |
| **VA** | `0x0051c1c0` |
| **Body** | `0x0051c1c0`–`0x0051c3aa` exclusive (**490** B) |
| **Canonical name** | `Map_TreeInsertAndRebalance_Val12` (inferred) |
| **Ghidra symbol** | `FUN_0051c1c0` |
| **Prior / alias** | `Named_CalleeOf_Skill_CategoryCooldownMap_Insert_0051c1c0` (narrow) |
| **Review date** | `2026-07-29` (W25-G OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0051c1c0_Map_TreeInsertAndRebalance_Val12.md` |
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
| Raw | `docs/reconstruction/raw/aa_0051c1c0_FUN_0051c1c0.md` (+ W25-G append) |
| Annotated | `docs/reconstruction/raw/aa_0051c1c0_FUN_0051c1c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_TreeInsertAndRebalance_Val12.cpp` |
| Scaffold | `reconstructed-exact/FUN_0051c1c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051c1c0_Map_TreeInsertAndRebalance_Val12.md` |
| Live decompile | ≡ raw |
| Live body bytes | `read_memory` entry + epilogue + string |
| Buynode dual | `aa_005ae220` StdTree_Buynode_Val12 (W24-I accept) |
| Parent dual | `aa_0051d2f0` Skill_CategoryCooldownMap_Insert |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `mov edi,ecx`; `cmp [edi+8], 0x15555553` |
| Epilogue | `add esp,0x50; ret 0x10` @ end of body |
| Body end | exclusive `0x0051c3aa` (pad `cc` after) |
| String | `"map/set<T> too long"` @ `0x00a1530c` |
| ThrowInfo | `DAT_00acc388` |
| Buynode call | `FUN_005ae220(..., color=0)` |
| Color / isnil | +0x18 / +0x19 (matches Val12 node) |

Entry hex (32 B):

```
64a1000000006aff6802359a00506489250000000083ec44578bf9817f085455
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
| Body size exclusive end | **pass** (`0051c3aa`) |
| `ret 0x10` / 4 stack args | **pass** |
| thiscall ECX=map | **pass** (`mov edi,ecx`) |
| Max-size constant `0x15555553` | **pass** |
| Throw string identity | **pass** |
| Buynode = `FUN_005ae220` color 0 | **pass** |
| Link empty / left / right cases | **pass** |
| RB recolor + rotate callouts | **pass** (decomp CF) |
| Clean has no `undefined4` | **pass** (uint32/int32) |
| Rotate product English | **gap** (out of ownership) |
| Buynode null-check | **gap** (not in decomp) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 0x10 |
| Val12 node layout | **High** | paired with sealed buynode |
| Sole caller category-cooldown | **High** | 2 xrefs only |
| Name `Map_TreeInsertAndRebalance_Val12` | **Inferred** | structural; not plate |
| Domain-only (not shared clone) | **High** for this VA | only one caller |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product demangle for map type.  
2. Product names for `FUN_00573170` / `FUN_00418c10`.  
3. OOM path if buynode returns null.  
4. Bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
