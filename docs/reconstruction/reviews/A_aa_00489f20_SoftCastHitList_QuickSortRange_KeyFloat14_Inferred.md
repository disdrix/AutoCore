# Review A (reconstruction fidelity): `aa_00489f20` SoftCastHitList_QuickSortRange_KeyFloat14_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489f20` |
| **VA** | `0x00489f20`–`0x0048a05d` inclusive (**318 B** / `0x13E`) |
| **Canonical name** | `SoftCastHitList_QuickSortRange_KeyFloat14_Inferred` |
| **Ghidra name** | `FUN_00489f20` |
| **Prior scaffold** | `FUN_00489f20` (2026-07-23 trio) |
| **Rejected misname** | no `Named_CalleeOf_*` present; reject "full memcpy 0x30 swap", "thiscall", "descending sort", "STL std::sort" |
| **Review date** | `2026-08-05` (MEGA-115 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00489f20_SoftCastHitList_QuickSortRange_KeyFloat14_Inferred.md` |
| **System** | interaction-activation (soft-cast hit list) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_function_xrefs` / `get_function_callees` + `get_function_signature` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Hoare-partition quicksort** of soft-cast hit array range `[lo, hi]`:

```text
SoftCastHitList_QuickSortRange_KeyFloat14_Inferred(base, lo, hi, cookie)
  pivot = base[(lo+hi)>>1].float_at_+0x14
  i=lo, j=hi
  scan i while base[i].key < pivot
  scan j while pivot < base[j].key
  if i<=j and i!=j: partial_swap(base[i], base[j])  // 7 fields
  recurse left if lo < j; set lo=i; continue if lo < hi
```

Sole external caller: dualed **`SoftCastHitList_SortIfCountGt1_Inferred`** (`0x0048a060`) after soft-cast fill under **`Client_InteractWorldClickHub`** (`0x00925820`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-115 append) | `docs/reconstruction/raw/aa_00489f20_FUN_00489f20.md` |
| Annotated | `docs/reconstruction/raw/aa_00489f20_FUN_00489f20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_QuickSortRange_KeyFloat14_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00489f20.cpp` |
| Function record | `docs/reconstruction/functions/aa_00489f20_FUN_00489f20.md` |
| Named record | `docs/reconstruction/functions/aa_00489f20_SoftCastHitList_QuickSortRange_KeyFloat14_Inferred.md` |
| Live | decompile ≡ scaffold CF; body hex 318 B; 2 CALL xrefs; cdecl `ADD ESP,0x10` |
| Parent gate | dualed MEGA-116 `SoftCastHitList_SortIfCountGt1_Inferred` |

---

## 3. Signature (sealed)

```c
// cdecl; 4 stack args; void; bare RET (C3); caller ADD ESP,0x10
void __cdecl SoftCastHitList_QuickSortRange_KeyFloat14_Inferred(
    SoftCastHitElem0x30 *base, int lo, int hi, uint32_t cookie /* unused */);
```

| Slot | Source | Conf |
|---|---|---|
| base | stack `[EBP+8]` (`MOV EBX,[EBP+8]`) | **High** |
| lo | stack `[EBP+0xC]` | **High** |
| hi | stack `[EBP+0x10]` | **High** |
| cookie | stack `[EBP+0x14]` — re-pushed only | **High** (unused) |
| cleanup | bare **`RET`** + caller **`ADD ESP,0x10`** | **High** |
| elem stride | **`0x30`** (`LEA; SHL 4` = ×3×16) | **High** |
| sort key | **float @ +0x14** ascending strict `<` | **High** |

**Note:** Ghidra signature meta reports `param_count:0` / `undefined FUN…(void)` — locals storage + decompile + assembly seal four stack args.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Mid pivot `((lo+hi)>>1)` | **Yes** | **High** |
| Left scan while key < pivot | **Yes** (`TEST AH,0x5` / `JP`) | **High** |
| Right scan while pivot < key | **Yes** | **High** |
| Break when j < i | **Yes** | **High** |
| Partial swap 7 fields | **Yes** (asm 0x00489fa1–0x0048a028) | **High** |
| Recurse left if lo < j | **Yes** | **High** |
| Tail right `lo=i` | **Yes** | **High** |
| cookie unused in body | **Yes** | **High** |
| Product key English | open | **Inferred** |

### Swap field set (sealed)

| Offset | Swapped? |
|---|---|
| +0x00, +0x04, +0x08, +0x0C, +0x10, +0x14, +0x20 | **Yes** |
| +0x18, +0x1C, +0x24, +0x28, +0x2C | **No** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (self-recursive sort core) |
| External callers | `FUN_0048a060` / `SoftCastHitList_SortIfCountGt1_Inferred` @ `0x0048a079` |
| Self | recurse @ `0x0048a040` |
| Xrefs | **2** UNCONDITIONAL_CALL |
| Callees | self only |
| Parent chain | hub `0x00925820` → sort gate `0x0048a060` → **this** |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Soft-cast hit-list parent dualed MEGA-116 | **Yes** |
| Qsort CF + stride 0x30 + key float +0x14 | **Yes** |
| Distinct from gate wrapper `0048a060` | **Yes** |
| Product English for key (distance/score) | **No** |

**Decision:** promote **`SoftCastHitList_QuickSortRange_KeyFloat14_Inferred`**. Reject full-element memcpy; reject thiscall; reject descending; reject STL `std::sort` wrapper claim. No `Named_CalleeOf_*` scaffold to retire.

---

## 7. Gaps / open

1. Product English for float@+0x14 (distance vs other score).
2. Why partial swap omits +0x18..+0x1C / +0x24..+0x2C.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
