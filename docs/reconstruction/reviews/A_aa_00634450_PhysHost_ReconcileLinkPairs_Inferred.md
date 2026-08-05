# Review A (reconstruction fidelity): `aa_00634450` PhysHost_ReconcileLinkPairs_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00634450` |
| **VA** | `0x00634450`–`0x0063453f` |
| **Body** | **240 bytes** (`0xF0`) |
| **Canonical name** | `PhysHost_ReconcileLinkPairs_Inferred` |
| **Ghidra name** | `FUN_00634450` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-R) |
| **Counterpart** | `reviews/B_aa_00634450_PhysHost_ReconcileLinkPairs_Inferred.md` |
| **System** | phys / host link-pair reconcile |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs |
| **Verdict** | **accept** |

---

## 1. Purpose

When `*(host+8)` (manager) is non-null, reconcile the host's link-pair membership:

1. Dual `LocalWorklist` init (`FUN_0062d960`) from `*(mgr+0x238)`.
2. Null-safe link slot at `host+0x1c`; query `*(mgr+0xc4)->vtbl+0x14` with stack param + flag `1`.
3. If either pair list non-empty: CanonAndSort both; SortedDiffWalk (ECX=`*(mgr+0x138)`); compact `host+0x3c`.
4. Dual `LocalWorklist_Release`.

Used by pose/AABB write helpers (`FUN_00580c00`, `FUN_00580dd0`, `FUN_005eb*`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00634450_FUN_00634450.md` (+ 2026-07-29 W29-R append) |
| Annotated | `docs/reconstruction/raw/aa_00634450_FUN_00634450.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysHost_ReconcileLinkPairs_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00634450.cpp` |
| Function record | `docs/reconstruction/functions/aa_00634450_FUN_00634450.md` |
| Named record | `docs/reconstruction/functions/aa_00634450_PhysHost_ReconcileLinkPairs_Inferred.md` |
| Live | decompile ≡ raw CF; prologue `83 EC 2C 56 8B F1` + epilogue `5E 83 C4 2C C2 04 00` |
| Nested duals | W27-N LocalWorklist_Release / SortedDiffWalk; W28-Q CanonAndSort |

---

## 3. Signature (sealed)

```c
// thiscall; ECX = host; stack query_param; ret 4; void
void PhysHost_ReconcileLinkPairs_Inferred(int host /*ECX*/, unsigned query_param);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX (`MOV ESI,ECX`) | **High** |
| query_param | stack after frame (`[esp+…]` / ret 4) | **High** |
| return | void | **High** |
| cleanup | `ret 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
if *(host+8)==0: return
LocalWorklist_Init ×2 (*(mgr+0x238))
slot = null-this(host+0x1c)
mgr[+0xc4]->vtbl+0x14(&slot, query_param, 1, listB, listA)
if either list non-empty:
  CanonAndSort both
  SortedDiffWalk(this=*(mgr+0x138), …, pred=*(mgr+0xd0)?+8:0)
  compact host+0x3c
LocalWorklist_Release ×2
```

| Stage | Match | Conf |
|---|---|---|
| Gate manager+8 | **Yes** | **High** |
| Dual worklist | **Yes** | **High** |
| Query vtbl+0x14 flag 1 | **Yes** | **High** |
| SortedDiffWalk ECX 0x138 | **Yes** (bytes) | **High** |
| thiscall + ret 4 | **Yes** | **High** |

---

## 5. Gaps / open

1. Product English for host / manager classes.
2. Full meaning of query_param and vtbl+0x14 out layout (decompiler residual on second list).
3. Runtime / bit-exact.

**Verdict:** **accept**
