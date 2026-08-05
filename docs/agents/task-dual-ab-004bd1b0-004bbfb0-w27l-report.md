# Dual A/B report — W27-L OWN `aa_004bd1b0` + `aa_004bbfb0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-L  
**Scope:** VAs `0x004bd1b0`, `0x004bbfb0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callers / callees / xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004bd1b0` COList_ScalarDeletingDestructor | **accept** — full-body bytes + body-dtor twin + vtbl[0] scalar pattern sealed |
| `aa_004bbfb0` COList_Constructor | **accept-with-gaps** — host ABI/layout/sizeof/InitInstance args sealed; nested helper English open |

---

## VA `0x004bd1b0` — sealed facts

1. **Body:** `0x004bd1b0`–`0x004bd1cd` (**30 B / `0x1E`**); pad `CC` after last instruction.
2. **ABI:** **`__thiscall`**; ECX=`this`; stack flags; epilogue **`ret 4`** (`C2 04 00`); **EAX** = `this`.
3. **Role:** MSVC **scalar-deleting destructor** — always `FUN_004bbc70` (`COList_Destructor`); if `(flags & 1)` then `operator_delete(this)`.
4. **Vtbl:** `PTR_FUN_009cb448[0]` = this body (`read_memory` `@0x009cb448` = `B0 D1 4B 00`).
5. **Product class:** **COList** (rdata `"Threw error in COList::Insert"` adjacent; body twin W26-J).
6. **Xrefs:** DATA from vtbl only (virtual dispatch; no direct CALL).
7. **Name:** `COList_ScalarDeletingDestructor` (Ghidra `FUN_004bd1b0`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Runtime / bit-exact.  
- Field English owned by ctor/body records.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bd1b0_COList_ScalarDeletingDestructor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004bd1b0_COList_ScalarDeletingDestructor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bd1b0_FUN_004bd1b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bd1b0_FUN_004bd1b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/COList_ScalarDeletingDestructor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bd1b0.cpp` |
| Function | `docs/reconstruction/functions/aa_004bd1b0_FUN_004bd1b0.md` |
| Function named | `docs/reconstruction/functions/aa_004bd1b0_COList_ScalarDeletingDestructor.md` |

---

## VA `0x004bbfb0` — sealed facts

1. **Body:** `0x004bbfb0`–`0x004bc17f` (**464 B / `0x1D0`**). SEH frame `LAB_009a1742`.
2. **ABI:** **`__thiscall`**; ECX=`this`; stack `(int capA, int capB)`; epilogue **`ret 8`** (`C2 08 00`); **EAX** = `this`.
3. **Vtbl:** `*this = PTR_FUN_009cb448` (`C7 06 48 B4 9C 00`).
4. **sizeof(COList):** **`0x58`** — InitInstance `operator_new(0x58)`.
5. **Production call:** `FUN_0094a6a0` / `Client_InitInstance` @ `0x0094a7eb` — after log `"before CVOGClonedObjectList"`, ctor **`(5, 10)`** → **`DAT_00b04830`** and **`client+0xD34`**.
6. **CF stages:** zero buffer triples → clamp caps ≥0 → flags +0x0C/+0x0D → optional `FUN_004bcf90` hashes at +0x04/+0x08 → always `FUN_004bce90(5)` at +0x18 → three `0x2C` CS-lists (final vtbl `009cb378`) at +0x1C/+0x20/+0x24 → +0x0E=0 → return this.
7. **Callees:** `operator_new`, `FUN_004bcf90`×2, `FUN_004bce90`×1, `InitializeCriticalSection`×3.
8. **Name:** `COList_Constructor` (Ghidra `FUN_004bbfb0`).
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English for nested `FUN_004bcf90` vs `FUN_004bce90` tables.  
- Product name for 0x2C single-CS list (`009cb378`) — **not** dual-CS `ThreadSafeObjectList` (`009cb368` used on dtor stack).  
- SEH unwind tables / runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bbfb0_COList_Constructor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bbfb0_COList_Constructor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bbfb0_FUN_004bbfb0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bbfb0_FUN_004bbfb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/COList_Constructor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bbfb0.cpp` |
| Function | `docs/reconstruction/functions/aa_004bbfb0_FUN_004bbfb0.md` |
| Function named | `docs/reconstruction/functions/aa_004bbfb0_COList_Constructor.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004bd1b0` | vtbl[0] must call body dtor **always**, then free only when **bit0** set. Preserve **ret 4** + return `this`. Do not treat decompiler delete-noreturn WARNING as both-path noreturn. |
| `004bbfb0` | Host **0x58**; production caps **(5,10)**; third table always **`FUN_004bce90(5)`** (not `bcf90`). Member lists at +0x1C/+0x20/+0x24 are **0x2C single-CS** (`009cb378`) — do **not** reuse dual-CS stack-list layout from dtor. Preserve **ret 8**. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004bbc70` | `COList_Destructor` body (W26-J **accept**) |
| `0x004bcf90` / `0x004bce90` | nested hash-family ctors |
| `0x0094a6a0` | `Client_InitInstance` sole ctor caller |
| `0x0040b020` / `0x004bcbf0` / `0x004024d0` | dual-CS ThreadSafeObjectList primitives (dtor stack path) |
| `DAT_00b04830` | global COList host pointer |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ callers/callees/xrefs). No `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names: **COList** from vtbl rdata; InitInstance log `"before CVOGClonedObjectList"` recorded as adjacency only.
