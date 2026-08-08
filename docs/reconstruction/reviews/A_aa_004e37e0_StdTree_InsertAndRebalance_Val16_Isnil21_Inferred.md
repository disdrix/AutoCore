# Review A (reconstruction fidelity): `aa_004e37e0` StdTree_InsertAndRebalance_Val16_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e37e0` |
| **VA** | `0x004e37e0` |
| **Body** | `0x004e37e0`–`0x004e39ca` inclusive (**491 B** / `0x1EB`) |
| **Canonical name** | `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_004e37e0` |
| **Prior / alias** | `Named_CalleeOf_Named_CalleeOf_CVOGReaction_UpdateRepairStationP_004e37e0` (narrow) |
| **Review date** | `2026-08-05` (R12-012 OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004e37e0_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set tree insert + RB rebalance |
| **Parent dual** | `0x005a27f0` `StdTree_Rrotate_Isnil21_Inferred` |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `get_function_callers` / `get_function_xrefs` / `get_xrefs_to`, `read_memory` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Always-insert a Val16 red-black tree node (buy via residual `FUN_004e2b80`), link under `where` / `addLeft`, rebalance while parent is red (L/R rotates + recolor + one inlined Lrotate), paint root black, write `*out`. Throw on size overflow (`"map/set<T> too long"`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-012 append) | `docs/reconstruction/raw/aa_004e37e0_FUN_004e37e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e37e0_FUN_004e37e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_004e37e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e37e0_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | `read_memory` entry 64 B + epilogue @ `0x004e39b0` |
| String | `"map/set<T> too long"` @ `0x00a1530c` |
| Buynode | residual `FUN_004e2b80` (`operator_new(0x28)`) |
| Rotates | dualed `005a27f0` R; dualed `0050e9f0` L |
| Peer insert | dualed `00407200` `StdTree_InsertAndRebalance_Isnil21_Inferred` |
| Sole caller | residual `FUN_004e48b0` (2 sites) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | SEH; `mov edi,ecx` (thiscall) |
| Size gate | `cmp [edi+8], 0x0FFFFFFE` (`81 7f 08 fe ff ff 0f`); `jb` continue |
| Epilogue | `add esp,0x50; ret 0x10` (`83 c4 50 c2 10 00`) @ `0x004e39c5` |
| Body end | inclusive last byte `0x004e39ca`; exclusive `0x004e39cb` (`cc` pad) |
| String | `"map/set<T> too long"` @ `0x00a1530c` (`push 0x00a1530c`) |
| ThrowInfo | `DAT_00acc388` |
| Buynode call | `FUN_004e2b80(..., color=0)` |
| Color / isnil | +0x20 / +0x21 |

Entry hex (64 B):

```
64a1000000006aff68621e9a00506489250000000083ec44578bf9817f08feffff0f7259680c53a1008d4c2408ff15f8629c008d4c2420c744245000000000ff
```

Epilogue tail (@ `0x004e39b0`):

```
208b4424605e89088b4c244c5b5f64890d0000000083c450c21000cccccccccc
; ... add esp,0x50; ret 0x10; int3 pad
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size exclusive end | **pass** (`004e39cb`) |
| `ret 0x10` / 4 stack args | **pass** |
| thiscall ECX=map | **pass** (`mov edi,ecx`) |
| Max-size constant `0x0FFFFFFE` | **pass** (bytes) |
| Throw string identity | **pass** |
| Buynode = `FUN_004e2b80` color 0 | **pass** |
| Link empty / left / right cases | **pass** |
| RB recolor + rotate callouts + inlined Lrotate | **pass** |
| Root black @+0x20 before `*out` | **pass** |
| Always-insert (no key compare) | **pass** |
| Product English | **gap** |
| Buynode null-check | **gap** (not in decomp) |
| Runtime / differential | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 0x10; entry/epilogue bytes |
| Val16 / isnil21 node layout | **High** | buynode `0x28` + color@+0x20 + isnil@+0x21 |
| Sole-caller shared with parent shell | **High** | 2 xrefs / 1 caller `004e48b0` |
| Name `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` | **Inferred** | structural; distinguishes peer `00407200` name |
| Runtime / differential | Open | never Runtime Confirmed |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| STL throw string | **Yes** |
| RB insert structure | **Yes** |
| Family rotates dualed isnil21 | **Yes** (`005a27f0`, `0050e9f0`) |
| Peer CF always-insert isnil21 | **Yes** (`00407200`) |
| Buynode Val16 size 0x28 | **Yes** (`004e2b80`) |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_InsertAndRebalance_Val16_Isnil21_Inferred`** (structural High; English unproven → `_Inferred`). Reject freelist / CNDHash / InsertHint-merge / isnil29 family / Runtime Confirmed.

---

## 7. Gaps

1. Product/PDB demangle for the map type behind `FUN_004e48b0` / repair-station path.  
2. OOM path if buynode returns null.  
3. Full dual of residual buynode `004e2b80` and parent shell `004e48b0` (not OWN).  
4. Bit-exact / differential / runtime — open.

**Verdict:** **accept-with-gaps**
