# Review A (reconstruction fidelity): `aa_009717a0` AssPreloader_EnqueueKeyAndDeps_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009717a0` |
| **VA** | `0x009717a0`–`0x0097181c` (**124 B**) |
| **Canonical name** | `AssPreloader_EnqueueKeyAndDeps_Inferred` |
| **Ghidra name** | `FUN_009717a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-J) |
| **Counterpart** | `reviews/B_aa_009717a0_AssPreloader_EnqueueKeyAndDeps_Inferred.md` |
| **System** | assPreloader / asset preload pipeline |
| **Evidence pass** | Live Ghidra `decompile_function` / `batch_decompile` + `read_memory` (full 124 B) + `analyze_function_complete` + callers `004ed310` / `007b69e0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Single-key AssPreloader path: seed temp ring with key, expand dependency keys, run eligible enqueue (W31-K), clear temp, return 0.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009717a0_FUN_009717a0.md` (+ W32-J hex append) |
| Annotated | `docs/reconstruction/raw/aa_009717a0_FUN_009717a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_EnqueueKeyAndDeps_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009717a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_009717a0_FUN_009717a0.md` |
| Named record | `docs/reconstruction/functions/aa_009717a0_AssPreloader_EnqueueKeyAndDeps_Inferred.md` |
| Live | decompile CF + full body hex; `MOV ESI,ECX`; `RET 4`; return 0 |

---

## 3. Signature (sealed)

```c
// ECX=this; stack key*; RET 4; returns 0
uint32_t AssPreloader_EnqueueKeyAndDeps_Inferred(
    void* self /*ECX*/,
    const int* key /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ECX** (`MOV ESI,ECX`) | **High** |
| key | Stack (`MOV EDI,[ESP+…]`) | **High** |
| cleanup | **`RET 4`** | **High** |
| return | **0** (`XOR EAX,EAX`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
zero local ring
PushBack_Thiscall(local, key)                 // FUN_0043d670
dep_host = *(*(self+0x110)+0x64)
FUN_00744360(key, &local)                     // ECX=dep_host
EnqueueEligibleFromRing(self, local)          // FUN_00971640; ESI=local
clear local                                   // FUN_005b2ba0
return 0
```

| Stage | Match | Conf |
|---|---|---|
| ECX this + RET 4 + EAX=0 | **Yes** | **High** |
| Seed push then dep expand | **Yes** | **High** |
| ESI ring into `00971640` | **Yes** | **High** |
| `+0x110→+0x64` dep host | **Yes** | **High** |

---

## 5. Gaps (explicit)

- Product/PDB method English (name **Inferred**).
- Nested `FUN_00744360` product dual (W32-L, not owned here).
- Exact key type beyond `int*`.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals thiscall ABI, stage order, dep-host offset, and handoff to W31-K enqueue. Residual nested product + runtime → **accept-with-gaps**.
