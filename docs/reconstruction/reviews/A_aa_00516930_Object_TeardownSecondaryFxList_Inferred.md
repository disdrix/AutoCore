# Review A (reconstruction fidelity): `aa_00516930` Object_TeardownSecondaryFxList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00516930` |
| **VA** | `0x00516930`–`0x005169a8` (**121 B / `0x79`**) |
| **Canonical name** | `Object_TeardownSecondaryFxList_Inferred` |
| **Ghidra name** | `FUN_00516930` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W29-N) |
| **Reviewer role** | Reconstruction fidelity (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_00516930_Object_TeardownSecondaryFxList_Inferred.md` |
| **System** | client-fx / object secondary NDSpecialFX ptr-vector teardown |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Tear down the object **secondary** SpecialFX pointer container at `+0x138` family:

1. Walk begin/end triad `+0x138`..`+0x13c` (stride 4).
2. For each entry: sealed `NDSpecialFX_DeactivateClear_Inferred` (`FUN_004b7150`, ECX=fx); if non-null → `NDSpecialFX_TeardownCore_Inferred` + `operator_delete`.
3. Clear host flag bit 2: `*(this+0x184) &= ~4`.
4. Free vector begin buffer if non-null; **always** zero `+0x138/+0x13c/+0x140`.

Closes residual nested dual from W28-H `Object_TeardownOwnedFxLists_Inferred`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00516930_FUN_00516930.md` (+ W29-N append) |
| Annotated | `docs/reconstruction/raw/aa_00516930_FUN_00516930.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00516930.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Object_TeardownSecondaryFxList_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_00516930_*` |
| Live | decompile ≡ raw outer CF; `read_memory` full body; bounds `00516930`–`005169a8` |
| Nested seals | W23-H DeactivateClear `004b7150`; TeardownCore `004b99c0`; parent W28-H |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 121 B | **Confirmed** | `get_function_by_address` + pad `CC` |
| thiscall `mov esi,ecx` | **Confirmed** | entry bytes |
| **`ret 4`** (`C2 04 00`) | **Confirmed** | epilogue; decomp missed |
| Stack formal unread in body | **Confirmed** | no `[esp+…]` load |
| Callers push 0 / 1 | **Confirmed** | `005179e7`, `005183cd` |
| DeactivateClear ECX = fx | **Confirmed** | `mov ecx,ebx` before call |
| Always zero triad after free | **Confirmed** | bytes after delete; decomp gap |
| Flag `+0x184 &= ~4` | **Confirmed** | `and dword [esi+0x184], 0xFFFFFFFB` |
| Product English | **Inferred** | `_Inferred` |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Secondary walk + DeactivateClear | **Yes** |
| Conditional TeardownCore + delete | **Yes** |
| Clear bit2 `+0x184` | **Yes** |
| Buffer free | **Yes** |
| Always zero `+0x138/13c/140` | **Yes** (bytes; decomp incomplete) |

### 4.1 Sealed contract

```
// thiscall; 1 unused stack dword cleaned by callee
void Object_TeardownSecondaryFxList_Inferred(void *self, int unused);

// for fx in [+0x138, +0x13c):
//   DeactivateClear(fx); if fx: TeardownCore(fx); delete fx
// *(self+0x184) &= ~4
// if begin: delete begin
// begin=end=cap=0
```

---

## 5. Callers / callees (live)

**CODE callers:** `FUN_005179e0` (push 0), `FUN_00518370` (push 1).  
**Callees:** `FUN_004b7150`, `FUN_004b99c0`, `operator_delete`.

---

## 6. Gaps

1. Product C++ class / member names.  
2. Semantic meaning of unread stack 0 vs 1.  
3. Runtime / bit-exact / differential.

**Verdict:** **accept** — CF, ABI (`ret 4`), always-zero triad, flag clear, and caller push sites sealed; product name inferred only.
