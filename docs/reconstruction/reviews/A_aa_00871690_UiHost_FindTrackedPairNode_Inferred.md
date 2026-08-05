# Review A (reconstruction fidelity): `aa_00871690` UiHost_FindTrackedPairNode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00871690` |
| **VA** | `0x00871690` |
| **Canonical name** | `UiHost_FindTrackedPairNode_Inferred` |
| **Ghidra name** | `FUN_00871690` |
| **Review date** | `2026-07-29` (W21-R OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw CF) |
| **Counterpart** | `reviews/B_aa_00871690_UiHost_FindTrackedPairNode_Inferred.md` |
| **System** | client UI / vehicle-garage host residual |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept** |

---

## 1. Purpose

Tiny **locked-list find-by-key-pair** helper:

```c
// thiscall ECX=host; stack keyA, keyB; RET 8
int* node = UiHost_FindTrackedPairNode(this, keyA, keyB);
// match: node+8 == keyA && node+0xc == keyB
// unlock list CS this+0x62c if flag this+0x650
```

Used by `UiHost_ClearTrackedPairAndRefresh_Inferred` (`0x008718a0`) and two sibling callers. **Not** a network path; **not** a free/destroy.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw + W21-R append | `raw/aa_00871690_FUN_00871690.md` |
| Annotated | `raw/aa_00871690_FUN_00871690.annotated.md` |
| Clean named | `reconstructed-exact/UiHost_FindTrackedPairNode_Inferred.cpp` |
| Clean scaffold | `reconstructed-exact/FUN_00871690.cpp` |
| Function record | `functions/aa_00871690_UiHost_FindTrackedPairNode_Inferred.md` |
| Live decompile | Ghidra `decompile_function(0x00871690)` — **≡** 2026-07-23 raw |
| Bytes | `read_memory` entry 128 B + exit @ `0x00871720` → `ret 8` |
| Xrefs | `get_function_xrefs` → 3 sites (`008718a0`, `008718d0`, `008719d0`) |
| Sibling | `A_aa_008718a0_UiHost_ClearTrackedPairAndRefresh_Inferred.md` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Zero locals; TraversalLock list `+0x628` | **Yes** |
| Iterate via `FUN_004113b0` | **Yes** |
| End/error → unlock-if → return 0 | **Yes** |
| Match `+8`/`+0xc` → break | **Yes** |
| Success unlock-if → return node | **Yes** |
| `ret 8` | **Yes** (bytes `c2 08 00`) |

---

## 4. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| ABI thiscall + 2 stack + ret 8 | **High** | entry `mov esi,ecx`; exit `ret 8` |
| List / CS / flag offsets | **High** | bytes `add esi,0x628`; leave path |
| Key pair match | **High** | decompile |
| Returns node* or 0 | **High** | |
| Product host/node names | **Tentative** | `_Inferred` family with 008718a0 |
| keyA/keyB domain | **Tentative** | TFID/slot residual |
| Runtime golden | **Open** | |

---

## 5. Gaps (do not block accept)

1. Product C++ symbol.
2. Semantic type of keys.
3. Full `FUN_004113b0` ECX iterator residual (CF of this unit still sealed).
4. Runtime / bit-exact.

### **accept**

CF fully sealed by decompile + `read_memory`. Residual is naming/domain only.
