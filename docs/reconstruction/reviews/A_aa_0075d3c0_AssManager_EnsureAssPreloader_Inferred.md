# Review A (reconstruction fidelity): `aa_0075d3c0` AssManager_EnsureAssPreloader_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075d3c0` |
| **VA** | `0x0075d3c0`–`0x0075d466` (**166 B**) |
| **Canonical name** | `AssManager_EnsureAssPreloader_Inferred` |
| **Ghidra name** | `FUN_0075d3c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-O) |
| **Counterpart** | `reviews/B_aa_0075d3c0_AssManager_EnsureAssPreloader_Inferred.md` |
| **System** | assets / assManager + assPreloader |
| **Evidence pass** | Live Ghidra `batch_decompile` / `analyze_function_complete` + `read_memory` (full 166 B) + callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Idempotent ensure of AssPreloader at AssManager host `+0x6c`; on create, seed preloader ring `+0xAC` from host tracked-asset list keys at `host+8`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0075d3c0_FUN_0075d3c0.md` (+ W33-O hex append) |
| Annotated | `docs/reconstruction/raw/aa_0075d3c0_FUN_0075d3c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssManager_EnsureAssPreloader_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075d3c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0075d3c0_FUN_0075d3c0.md` |
| Named record | `docs/reconstruction/functions/aa_0075d3c0_AssManager_EnsureAssPreloader_Inferred.md` |
| Live | decompile CF + full body hex; `RET 4`; callers ctor + preload enable |

---

## 3. Signature (sealed)

```c
// stack host*; RET 4; void
void AssManager_EnsureAssPreloader_Inferred(void* host /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| host | Stack; `MOV EBP,[ESP+…]`; `CMP [EBP+0x6c],0` | **High** |
| cleanup | **`RET 4`** (`C2 04 00`) | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if *(host+0x6c) != 0: return
mem = operator_new(0x114)
pre = mem ? FUN_00970cf0(mem) : 0
*(host+0x6c) = pre
for node in circular list host+8:
  pack PodU32U8 { *(node+8), 1 }
  EDI = pre+0xAC; GuardedVector_PushBackLocked_Stride2_U32U8
```

| Stage | Match | Conf |
|---|---|---|
| Idempotent +0x6c gate | **Yes** | **High** |
| new(0x114) + AssPreloader ctor | **Yes** | **High** |
| List walk host+8 | **Yes** | **High** |
| Push locked to pre+0xAC | **Yes** | **High** |

---

## 5. Gaps (explicit)

- Product/PDB method English (name **Inferred**).
- Nested `FUN_00970cf0` full layout dual residual.
- Exact list node type beyond key@+8 (shared with AssManager_SweepTrackedAssets).
- OOM path (null pre + still walks) retail residual.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ABI, CF, host/preloader offsets, and seed polarity. Nested ctor product + runtime → **accept-with-gaps**.
