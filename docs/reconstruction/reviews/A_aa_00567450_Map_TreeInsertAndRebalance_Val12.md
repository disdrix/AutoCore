# Review A (reconstruction fidelity): `aa_00567450` Map_TreeInsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00567450` |
| **VA** | `0x00567450` |
| **Body** | `0x00567450`–`0x0056763a` exclusive (**490** B) |
| **Canonical name** | `Map_TreeInsertAndRebalance_Val12` (inferred; clone of `aa_0051c1c0`) |
| **Ghidra symbol** | `FUN_00567450` |
| **Review date** | `2026-07-29` (W27-R OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00567450_Map_TreeInsertAndRebalance_Val12.md` |
| **System** | std map/set tree insert + RB rebalance (Val12) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Always-insert a Val12 red-black tree node (buy via `StdTree_Buynode_Val12`), link under `where`, rebalance while parent is red, paint root black, write `*outIt`. Throw on size overflow.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00567450_FUN_00567450.md` (+ W27-R append) |
| Annotated | `docs/reconstruction/raw/aa_00567450_FUN_00567450.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_TreeInsertAndRebalance_Val12_00567450.cpp` |
| Scaffold | `reconstructed-exact/FUN_00567450.cpp` |
| Function record | `docs/reconstruction/functions/aa_00567450_Map_TreeInsertAndRebalance_Val12.md` |
| Live decompile | ≡ raw |
| Twin dual | `aa_0051c1c0` Map_TreeInsertAndRebalance_Val12 (W25-G) |
| Buynode dual | `aa_005ae220` StdTree_Buynode_Val12 (W24-I accept) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `mov edi,ecx`; size cmp vs `0x15555553` |
| Epilogue | `add esp,0x50; ret 0x10` |
| Body end | exclusive `0x0056763a` (pad `cc`) |
| String | `"map/set<T> too long"` @ `0x00a1530c` |
| ThrowInfo | `DAT_00acc388` |
| Buynode | `FUN_005ae220(..., color=0)` |
| Color / isnil | +0x18 / +0x19 |

Entry hex (32 B):

```
64a1000000006aff68124c9a00506489250000000083ec44578bf9817f085455
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
| Body size exclusive end | **pass** (`0056763a`) |
| `ret 0x10` / 4 stack args | **pass** |
| thiscall ECX=map | **pass** (`mov edi,ecx`) |
| Max-size constant `0x15555553` | **pass** |
| Throw string identity | **pass** |
| Buynode = `FUN_005ae220` color 0 | **pass** |
| Link empty / left / right cases | **pass** |
| RB recolor + rotate callouts | **pass** (decomp CF) |
| Clean has no bare `undefined4` | **pass** |
| Distinct from `aa_0051c1c0` | **pass** (separate VA/caller) |
| Product English | **gap** |
| Buynode null-check | **gap** (not in decomp) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 0x10 |
| Val12 node layout | **High** | paired with sealed buynode |
| Sole caller `FUN_00567860` | **High** | 1 xref |
| Name structural Val12 insert | **Inferred** | not plate |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product demangle for map type.  
2. Product names for rotate helpers (sealed as Val12 L/R elsewhere).  
3. OOM path if buynode returns null.  
4. Bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
