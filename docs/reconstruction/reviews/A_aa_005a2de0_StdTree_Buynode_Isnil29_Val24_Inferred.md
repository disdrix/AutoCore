# Review A (reconstruction fidelity): `aa_005a2de0` StdTree_Buynode_Isnil29_Val24_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2de0` |
| **VA** | `0x005a2de0` |
| **Canonical name** | `StdTree_Buynode_Isnil29_Val24_Inferred` |
| **Prior alias** | `FUN_005a2de0`; scaffold `Named_CalleeOf_…_Skill_GatherTarget_005a2de0` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9F-A) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_005a2de0_StdTree_Buynode_Isnil29_Val24_Inferred.md` |
| **System** | std containers / tree node buy (isnil@+0x29) |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, callers/xrefs |
| **Partition** | `WAVE_2026-08-04_wq009_depth3_partition_map.md` → WQ9F-A |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Allocate and initialize one **0x30-byte** red-black tree node for the **isnil@+0x29 / Val24** family:

```text
// __stdcall; RET 0x14; EAX = node* (0 on OOM)
node = operator_new(0x30)
if node:
  left/parent/right = args
  copy 6 dwords from value* → node+0x10
  color @ +0x28 = arg
  isnil @ +0x29 = 0
return node
```

Primary consumer: `StdTree_InsertAndRebalance_Isnil29_Inferred` (`0x004cbb60`). Two additional insert-shell twins share this buynode.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile(0x005a2de0)` ≡ 2026-07-23 raw CF |
| Entry / body bytes | `read_memory` — `6A 30 E8…` … `C6 40 29 00 5E C2 14 00` + `CC` |
| Body range | `0x005a2de0`–`0x005a2e3a` (**91 B** / `0x5B`) |
| Callers | `004cbb60` @ `004cbbf2`; `0058da40` @ `0058dad2`; `005a3310` @ `005a33a2` |
| Callees | `operator_new` only |
| Parent dual | WQ9E-E insert (`aa_004cbb60`) — buynode residual closed here |
| Val12 peer | `StdTree_Buynode_Val12` (`0x005ae220`) — layout contrast |
| Clean | `reconstructed-exact/StdTree_Buynode_Isnil29_Val24_Inferred.cpp` |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| stack+4 | left* | `mov ecx,[esp+4]; mov [eax],ecx` |
| stack+8 | parent* | `mov edx,[esp+8]; mov [eax+4],edx` |
| stack+0xc | right* | `mov [eax+8],…` |
| stack+0x10 | value6* | copy 6 dwords to `eax+0x10` |
| stack+0x14 / [esp+0x18] after pushes | color u8 | `mov [eax+0x28], dl` |
| return | node* EAX | null skip path leaves EAX=0 from failed new |
| cleanup | **`ret 0x14`** | bytes `C2 14 00` |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| `operator_new(0x30)` | **Yes** |
| Null short-circuit (no init) | **Yes** |
| L/P/R + 6-dword value + color + isnil0 | **Yes** |
| Does not write `+0x0c` | **Yes** |
| RET 0x14 | **Yes** (bytes; decomp omits) |
| Insert callers pass color=0 | **Yes** (004cbb60 family) |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = tree buynode isnil29 / Val24 | **High** (size+layout+insert callers) |
| stdcall RET 0x14 / EAX return | **High** (exit bytes + uses) |
| Node 0x30 / color+0x28 / isnil+0x29 | **High** |
| Not Val12 buynode | **High** (size 0x30 vs 0x1c; isnil offset) |
| Product value_type English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**
