# Review A (reconstruction fidelity): `aa_00402b30` StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402b30` |
| **VA** | `0x00402b30`–`0x00402be6` inclusive (**183 B** / `0xB7`) |
| **Canonical name** | `StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred` |
| **Ghidra name** | `FUN_00402b30` |
| **Rejected scaffold** | `Named_CalleeOf_Client_NotifyActiveMissionChanged_00402b30` |
| **Review date** | `2026-08-05` (MEGA-040 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00402b30_StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.md` |
| **System** | MSVC std map insert-or-find (isnil@+0x31 / uint key / EAX+EBX ABI) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Insert-or-find a unique map entry by **unsigned** 32-bit key under **isnil@+0x31** (node size **0x38**) tree layout, using register ABI (**EAX** map, **EBX** value*). Write `{iterator, inserted}`; on equal key do **not** rewrite mapped payload.

Host context (not product name of this helper): `Client_NotifyActiveMissionChanged` (`0x00944770`) uses it against map at **client+0xf14** while rebuilding mission debug queues.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00402b30_FUN_00402b30.md` (+ MEGA-040 append) |
| Annotated | `docs/reconstruction/raw/aa_00402b30_FUN_00402b30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00402b30.cpp` |
| Function record | `docs/reconstruction/functions/aa_00402b30_FUN_00402b30.md` |
| Named record | `docs/reconstruction/functions/aa_00402b30_StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.md` |
| Live | decompile ≡ CF; body hex 183 B; isnil `+0x31`; key `+0x10`; SETC/JNC; 3 CALL xrefs; call-site EAX/EBX/PUSH |

---

## 3. Signature (sealed)

```c
// EAX = map; EBX = value* (key dword0); stack out pair*; RET 4; returns out
InsertPair *StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred(
    MapShell *map, InsertPair *out, const Val *value);
```

| Slot | Source | Conf |
|---|---|---|
| map | **EAX** (`MOV EDI,EAX`) | **High** |
| value* | **EBX** (`MOV EDX,[EBX]` key load) | **High** |
| out | stack → `EBP` (`MOV EBP,[ESP+0xC]`) | **High** |
| cleanup | **`RET 4`** ×3 exits | **High** |
| return | **EAX** = out (`MOV EAX,EBP`) | **High** |
| isnil | **`+0x31`** | **High** |
| key | **`+0x10`**, unsigned | **High** |

**Note:** Decompiler shows `in_EAX` / `unaff_EBX` phantoms — assembly + call sites (`LEA EAX,[EDI+0xf14]`, `LEA EBX,[ESP+…]`, `PUSH out`) seal register ABI.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| root = head->parent; goLeft=true | **Yes** | **High** |
| walk while !isnil; left/right by unsigned key | **Yes** | **High** |
| goLeft && node==head->left → insert addLeft=1 | **Yes** | **High** |
| goLeft else → predecessor `FUN_00404290` | **Yes** | **High** |
| node.key < key → insert with goLeft flag | **Yes** | **High** |
| else equal → inserted=0, no rewrite | **Yes** | **High** |
| Callees insert `00403250` + pred `00404290` only | **Yes** | **High** |
| Product map English | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `FUN_00944770` NotifyActiveMissionChanged (2); `FUN_00933310` wrapper (1); **xref_count=3** |
| Site roles | insert mission-queue entries into client+`0xf14` map; thin shared wrapper |
| Callees | `FUN_00403250`, `FUN_00404290` |
| Family peers | isnil15 EaxEbx `00458510`; isnil29 IntKey thiscall `004cbe20`; Lrotate/Rrotate/erase isnil31 |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Classic insert-or-find CF + isnil@+0x31 | **Yes** |
| Unsigned key (`SETC`/`JNC`) @ +0x10 | **Yes** |
| EAX map + EBX value* ABI | **Yes** |
| Distinct from isnil15/21/29 InsertOrFind peers | **Yes** |
| Product/PDB English for map T | **No** |

**Decision:** promote **`StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred`**. Reject mission-seed `Named_CalleeOf_*` plate; reject thiscall/signed-key mislabel; reject isnil29 merge.

---

## 7. Gaps / open

1. Product / English host map type at client+`0xf14` (mission debug queue).
2. Full dual of insert `FUN_00403250` and predecessor `FUN_00404290` (unOWN).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
