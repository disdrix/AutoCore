# Review A (reconstruction fidelity): `aa_00418700` StdList_BuyNode_Dword_Seh

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418700` |
| **VA** | `0x00418700`–`0x00418779` inclusive (**122 B** / `0x7A`) |
| **Canonical name** | `StdList_BuyNode_Dword_Seh` |
| **Ghidra name** | `FUN_00418700` |
| **Prior / alias** | `Named_CalleeOf_Client_DebugListMissionsStatus_00418700` (**retired** — parent-seed) |
| **Review date** | `2026-08-05` (MEGA-081 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00418700_StdList_BuyNode_Dword_Seh.md` |
| **System** | shared MSVC `std::list` dword `_Buynode` (SEH-framed) |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_function_by_address`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Buy (allocate + init) a 12-byte list node** for dword/pointer-sized `std::list` elements, with MSVC SEH around `operator_new`:

1. SEH frame (`LAB_009bc331` / FS:[0])
2. `operator_new(0xC)`
3. If non-null: store `link0` @ +0, `link1` @ +4, `*pValue` @ +8
4. Return node pointer in **EAX** (0 on failure); **`RET 0xC`**

Does **not** size++ or rewire the circular list — insert wrappers (`FUN_00402d10`, `FUN_004040f0`, `FUN_00517db0`, …) call Incsize then link.

Twin without SEH: dualed **`StdList_BuyNode_Dword`** @ `0x006759b0` (W20-M) — identical fill CF, 39 B leaf.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-081 append) | `docs/reconstruction/raw/aa_00418700_FUN_00418700.md` |
| Annotated | `docs/reconstruction/raw/aa_00418700_FUN_00418700.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/StdList_BuyNode_Dword_Seh.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00418700.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_DebugListMissionsStatus_00418700.cpp` |
| Function records | `functions/aa_00418700_FUN_00418700.md`, `functions/aa_00418700_StdList_BuyNode_Dword_Seh.md` |
| Live | decompile ≡ CF; body hex 122 B; `RET 0xC`; 61 CALL xrefs; call-site `MOV reg,EAX` |

---

## 3. Signature (sealed)

```c
// __stdcall; three stack args; RET 0xC; return node* in EAX
void *StdList_BuyNode_Dword_Seh(void *link0, void *link1, uint32_t *pValue);
```

| Slot | Source | Conf |
|---|---|---|
| link0 | stack `[EBP+8]` → `[EAX+0]` | **High** |
| link1 | stack `[EBP+0xC]` → `[EAX+4]` | **High** |
| pValue | stack `[EBP+0x10]`; `*pValue` → `[EAX+8]` | **High** |
| return | **EAX** (decompiler void corrected) | **High** |
| cleanup | **`RET 0xC`** | **High** |
| SEH | `LAB_009bc331` frame | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| SEH setup | **Yes** | **High** |
| `operator_new(0xC)` | **Yes** | **High** |
| Null gate before stores | **Yes** | **High** |
| Three dword writes | **Yes** | **High** |
| Value is **dereferenced** pointer | **Yes** | **High** |
| No size++ / no relink in body | **Yes** | **High** |
| EAX return preserved | **Yes** (call sites) | **High** |
| Product `list<T>` English | open | **Inferred** role only |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker / shared leaf |
| External CALL xrefs | **61** UNCONDITIONAL_CALL |
| Site roles | list insert buy step before Incsize + relink |
| Callees (normal) | `operator_new` only |
| Twin | `StdList_BuyNode_Dword` `0x006759b0` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| `new(0xC)` + 3 dword init + RET 0xC | **Yes** |
| Match dualed BuyNode_Dword twin CF | **Yes** |
| SEH differentiates from `006759b0` | **Yes** |
| 61 multi-domain xrefs (not mission-only) | **Yes** |
| Product demangle string in body | **No** |

**Decision:** promote **`StdList_BuyNode_Dword_Seh`**. Reject `Named_CalleeOf_Client_DebugListMissionsStatus_*`. Reject reward-list-only product name (hint is usage partition, not exclusive role).

---

## 7. Gaps / open

1. Product element type English beyond dword-sized payload.
2. Runtime / bit-exact / differential.
3. Full EH state-table English for `LAB_009bc331` (behaviorally non-success-path).

**Verdict:** **accept**
