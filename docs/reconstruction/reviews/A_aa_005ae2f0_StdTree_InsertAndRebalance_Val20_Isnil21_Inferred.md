# Review A (reconstruction fidelity): `aa_005ae2f0` StdTree_InsertAndRebalance_Val20_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae2f0` |
| **VA** | `0x005ae2f0` |
| **Body** | `0x005ae2f0`–`0x005ae4da` inclusive (**491** B / `0x1EB`) |
| **Canonical name** | `StdTree_InsertAndRebalance_Val20_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_005ae2f0` |
| **Prior / alias** | `Named_CalleeOf_Named_CalleeOf_Mission_MissionStopLimit_005ae2f0` (narrow) |
| **Review date** | `2026-08-05` (R12-034 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_005ae2f0_StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.md` |
| **System** | skills-abilities / MSVC std `_Tree` always-insert + RB rebalance (Val20 / isnil@+0x21) |
| **Partition** | `WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-034** |
| **Parent dual** | `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (this unit is a **caller** residual) |
| **Dual start** | 2646 |
| **Terminal** | **false** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Always-insert a Val20 red-black tree node (buy via `FUN_005ae1c0` node 0x24), link under `where`, rebalance while parent is red (shared isnil21 L/R rotates + one inlined L), paint root black, write `*outIt`. Throw on size overflow. Parent `FUN_005aec50` owns key walk / uniqueness.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-034 re-verify) | `docs/reconstruction/raw/aa_005ae2f0_FUN_005ae2f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005ae2f0_FUN_005ae2f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_005ae2f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005ae2f0_StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | `read_memory` @ `0x005ae2f0` length 512 (491 B body + pad + next prologue) |
| Buynode (evidence) | `FUN_005ae1c0` live decompile — `operator_new(0x24)`, 5 dwords, color@+0x20, isnil@+0x21 |
| Sole caller (evidence) | `FUN_005aec50` live decompile — insert-or-find composite int key |
| L/R rotates | dualed `0050e9f0` / `005a27f0` isnil21 |
| Peer inserts | Val16 `00407200` (same rotates); Val12 `005ae4e0` (adjacent; different family) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, parent ledgers / COVERAGE_LEDGER / NAMING_REGISTRY.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body inclusive end | `0x005ae4da` (`C2 10 00` ends at `0x005ae4da`; 5×`CC` then `FUN_005ae4e0`) |
| Size | **491** B / `0x1EB` |
| Epilogue | `83 C4 50` / `C2 10 00` (`add esp,0x50; ret 0x10`) |
| Size gate | `81 7F 08 CB CC CC 0C` = `cmp [edi+8], 0x0CCCCCCB`; `jb` continue |
| Throw string | `"map/set<T> too long"`; ThrowInfo `DAT_00acc388` |
| SEH | `LAB_009a65a2`; `mov edi,ecx` thiscall |
| Buynode call | `CALL 0x005ae1c0` with color imm `0` |
| Color tests | `80 ?? 20 00` (parent red check) |
| isnil (inline L) | `80 7A 21 00` |
| Lrotate call | `CALL 0x0050e9f0` @ `0x005ae41b` |
| Rrotate calls | `CALL 0x005a27f0` @ `0x005ae439`, `0x005ae44f` |
| Callers | 1 (`FUN_005aec50`); 1 UNCONDITIONAL_CALL xref |

Entry hex (36 B):

```
64a1000000006aff68a2659a00506489250000000083ec44578bf9817f08cbcccc0c
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
| Body size inclusive end | **pass** (`005ae4da` / 491 B) |
| `RET 0x10` / 4 stack args | **pass** |
| thiscall ECX=map | **pass** (`mov edi,ecx`) |
| Max-size constant `0xCCCCCCB` | **pass** |
| Throw string identity | **pass** |
| Buynode = `FUN_005ae1c0` color 0 / node 0x24 | **pass** |
| Link empty / left / right cases | **pass** |
| RB recolor + rotate callouts | **pass** (decomp CF + CALL sites) |
| color@+0x20 / isnil@+0x21 | **pass** |
| Val20 (5 dwords) via buynode | **pass** |
| Sole caller FUN_005aec50 | **pass** |
| Shared (not MissionStopLimit-only) | **pass** (STL helper; old alias narrow) |
| Clean has no bare `undefined4` | **pass** (`uint32_t` / named structs) |
| Product demangle | **gap** |
| Buynode null OOM path | **gap** (no check in decomp) |
| Runtime / differential | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 0x10 |
| Val20 / node 0x24 layout | **High** | paired with live buynode decompile |
| isnil@+0x21 family rotates | **High** | CALL sites + dualed leaves |
| Sole caller FUN_005aec50 | **High** | 1 xref only |
| Name `…Val20_Isnil21_Inferred` | **Inferred** | structural; not plate |
| Distinct from Val12 `005ae4e0` / Val16 `00407200` | **High** | max/buynode/node size |
| Runtime / differential | Open | Terminal false |

---

## 6. Verdict

**accept-with-gaps** — CF, ABI, Val20/isnil21 layout, size gate, throw string, buynode, rotates, and sole caller sealed. Gaps: product demangle, OOM path, runtime. **Never Runtime Confirmed.**
