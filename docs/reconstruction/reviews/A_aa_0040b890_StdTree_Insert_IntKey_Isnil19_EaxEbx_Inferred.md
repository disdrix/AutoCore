# Review A (reconstruction fidelity): `aa_0040b890` StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b890` |
| **VA** | `0x0040b890`–`0x0040b8eb` inclusive (**92 B** / `0x5C`) |
| **Canonical name** | `StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred` |
| **Ghidra name** | `FUN_0040b890` |
| **Review date** | `2026-08-05` (R13-019 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0040b890_StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred.md` |
| **System** | MSVC tree always-insert (isnil@+0x19 / signed int key / EAX+EBX ABI) |
| **Partition** | R13-019 / inventory-transfer residual (parent `0x0092b2a0`) |
| **Dual start** | 2686 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Always-insert a unique-position tree entry by **signed** 32-bit key under **isnil@+0x19** (node size **0x1C**), using register ABI (**EAX** map, **EBX** value*). Write `{iterator, inserted=true}`. **No** equal-key find path — not InsertOrFind.

Host context (not product name of this helper): `MissionTracker_FillTrackedTargetSlots_Inferred` (`0x0092b2a0`) uses it against a **stack temp map** while ranking secondary multi-target slots.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040b890_FUN_0040b890.md` (+ R13-019 append) |
| Annotated | `docs/reconstruction/raw/aa_0040b890_FUN_0040b890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040b890.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040b890_FUN_0040b890.md` |
| Named record | `docs/reconstruction/functions/aa_0040b890_StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred.md` |
| Live | decompile ≡ CF; body hex 92 B; isnil `+0x19`; key `+0x0C`; SETL; 1 CALL xref; call-site EAX/EBX/PUSH |
| Insert helper | `decompile_function` `0x0040bcd0` — `map/set<T> too long`; buy `0x1C`; color@+0x18 |
| Buynode | `decompile_function` `0x0040c060` — `operator_new(0x1c)` |

---

## 3. Signature (sealed)

```c
// EAX = map; EBX = value* (key dword0); stack out pair*; RET 4; returns out
InsertPair *StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred(
    MapShell *map, InsertPair *out, const Val *value);
```

| Slot | Source | Conf |
|---|---|---|
| map | **EAX** (`MOV EDI,EAX`) | **High** |
| value* | **EBX** (`MOV ESI,[EBX]` key load) | **High** |
| out | stack → `EBP` (`MOV EBP,[ESP+0x8]` after PUSH EBP) | **High** |
| cleanup | **`RET 4`** (`C2 04 00` @ `0x0040b8eb`) | **High** |
| return | **EAX** = out (`MOV EAX,EBP`) | **High** |
| isnil | **`+0x19`** | **High** |
| key | **`+0x0C`**, **signed** (`SETL`) | **High** |
| inserted | **always 1** (`MOV BYTE PTR [EBP+4],1`) | **High** |

**Note:** Decompiler shows `in_EAX` / `unaff_EBX` phantoms — assembly + sole call site (`LEA EAX, map`, `LEA EBX, value`, `PUSH out`) seal register ABI.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| root = head->parent; goLeft=true | **Yes** | **High** |
| walk while !isnil@+0x19; left/right by signed key | **Yes** | **High** |
| ECX tracks where-parent before descend | **Yes** | **High** |
| empty tree: ECX stays head, skip walk | **Yes** | **High** |
| always CALL `0040bcd0` (insert+RB) | **Yes** | **High** |
| out.it = *tmp; out.inserted = 1 | **Yes** | **High** |
| no equal-key / inserted=0 arm | **Yes** | **High** |
| Product map English | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `FUN_0092b2a0` MissionTracker_FillTrackedTargetSlots_Inferred (**1**); **xref_count=1** |
| Site role | insert into stack temp ranking map during secondary multi-target fill |
| Callee | `FUN_0040bcd0` only |
| Family peers (parent) | construct empty `0040b3b0`; erase `0040b440`; erase-range `0040bc10` |
| Distinct from | InsertOrFind isnil31 EaxEbx `00402b30`; isnil29 thiscall InsertOrFind peers |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Always-insert CF + isnil@+0x19 | **Yes** |
| Signed key (`SETL`) @ +0x0C | **Yes** |
| EAX map + EBX value* ABI | **Yes** |
| Node 0x1C / color@+0x18 | **Yes** (callee + buy) |
| Distinct from InsertOrFind / isnil31 | **Yes** |
| Product/PDB English for map T | **No** |

**Decision:** promote **`StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred`**. Reject inventory-transfer product name for the leaf; reject InsertOrFind / thiscall / unsigned-key mislabel; reject isnil29/31 merge.

---

## 7. Gaps / open

1. Product / English host temp-map type in MissionTracker ranking arm.
2. Full dual of insert `FUN_0040bcd0`, buynode `FUN_0040c060`, ctor `FUN_0040c210` (unOWN).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
