# Dual A/B report — W25-C OWN `aa_004bcbf0` + `aa_00421240`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x004bcbf0`, `0x00421240`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callees / callers / xrefs). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).  
**Image base:** `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004bcbf0` ThreadSafeObjectList_Dtor | **accept** — 66 B dtor; PopFront drain + payload delete + dual DeleteCS sealed |
| `aa_00421240` OleDb_EnsureColumnInfoAndEnterBindings_Inferred | **accept-with-gaps** — QI IAccessor / optional GetColumnInfo / `*0x34` DBBINDING temp / jmp `00421362` sealed; 0 Ghidra callers residual |

---

## VA `0x004bcbf0` — ThreadSafeObjectList_Dtor

### Sealed facts

1. **Body:** `0x004bcbf0`–`0x004bcc31` (66 B). Hex  
   `568bf157c70668b39c00e821e4f4ff85c074138b106a018bc8ff128bcee80ee4f4ff85c075ed8b3df0619c008d461050c7460c00000000ffd783c62856ffd75f5ec3`.
2. **ABI:** `__thiscall`/`__fastcall` — ECX = list*; **`ret`**.
3. **Vtbl:** `*this = PTR_FUN_009cb368` (slot0 = scalar-deleting `FUN_004bcc40` → this body).
4. **Drain:** loop `PopFront` (`aa_0040b020`) until NULL; each **payload** gets `(*vtbl)(1)` delete. Nodes freed inside PopFront.
5. **Teardown:** `count(+0x0C)=0`; `DeleteCriticalSection(+0x10)` then `(+0x28)`.
6. **Layout twin** of sealed PopFront (head/tail/count/dual CS).
7. **Callers:** `FUN_004bcc40`, `FUN_004d64d0`, `FUN_004bbc70`, `FUN_0058c850`×2, `Unwind@009a5750`.
8. **Three-rep:** raw CF + live decompile + full body bytes.

### Gaps

1. Product English class name.  
2. Payload type per list instance.  
3. Runtime / bit-exact image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004bcbf0_ThreadSafeObjectList_Dtor.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004bcbf0_ThreadSafeObjectList_Dtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004bcbf0_ThreadSafeObjectList_Dtor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004bcbf0_ThreadSafeObjectList_Dtor.md` |
| Function record | `docs/reconstruction/functions/aa_004bcbf0_ThreadSafeObjectList_Dtor.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004bcbf0_FUN_004bcbf0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ThreadSafeObjectList_Dtor.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004bcbf0.cpp` |
| Raw (+ W25-C append) | `docs/reconstruction/raw/aa_004bcbf0_FUN_004bcbf0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bcbf0_FUN_004bcbf0.annotated.md` |

Sibling context (not owned): PopFront `0x0040b020`, push `0x004024d0`, scalar dtor `0x004bcc40`.

---

## VA `0x00421240` — OleDb_EnsureColumnInfoAndEnterBindings_Inferred

### Sealed facts

1. **Body:** `0x00421240`–`0x00421358`; success ends **`jmp 0x00421362`** (not call+ret).
2. **ABI:** `__thiscall` — ECX = source `IUnknown*`; stack **ctx\***; fail **`ret 4`** HRESULT.
3. **IID_IAccessor** `DAT_00a860ac` = `{0C733A8C-2A1C-11CE-ADE5-00AA0044773D}` (shared with create/release seals).
4. **IID_IColumnsInfo** `DAT_00a85ffc` = `{0C733A11-2A1C-11CE-ADE5-00AA0044773D}`.
5. **Column ensure:** if `ctx+0x14` set → `ctx+0x1c=1`; else QI IColumnsInfo + **vtbl+0x0C GetColumnInfo** → outs `+0x0C/+0x14/+0x18`, `ctx+0x1c=0`.
6. **Temp alloc:** `operator_new__(colCount * 0x34)` → `[ebp-0x1C]` (**DBBINDING** stride 52); SEH level 2; enter child.
7. **Child chain:** `aa_00421362` → `aa_0042139b` → `aa_00421677` (already dual-sealed siblings).
8. **Three-rep:** raw CF + live decompile + IID/tail bytes.

### Gaps

1. **0 Ghidra direct callers** (indirect/data residual).  
2. Product/PDB English for ctx / owner.  
3. Free policy for GetColumnInfo buffers when flag==0.  
4. Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00421240_OleDb_EnsureColumnInfoAndEnterBindings_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00421240_OleDb_EnsureColumnInfoAndEnterBindings_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00421240_OleDb_EnsureColumnInfoAndEnterBindings_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00421240_OleDb_EnsureColumnInfoAndEnterBindings_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00421240_OleDb_EnsureColumnInfoAndEnterBindings_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00421240_FUN_00421240.md` |
| Clean | `docs/reconstruction/reconstructed-exact/OleDb_EnsureColumnInfoAndEnterBindings_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00421240.cpp` |
| Raw (+ W25-C append) | `docs/reconstruction/raw/aa_00421240_FUN_00421240.md` |
| Annotated | `docs/reconstruction/raw/aa_00421240_FUN_00421240.annotated.md` |

Sibling context (not owned): `OleDb_AllocBindingsBuf_EnterBuild_Inferred` `0x00421362`, build/finalize `0x0042139b` / `0x00421677`.

---

## This report

`docs/agents/task-dual-ab-004bcbf0-00421240-w25c-report.md`

---

## AutoCore impact

- **ThreadSafeObjectList_Dtor:** ports must drain with PopFront semantics (free nodes in pop; delete **payloads** in dtor), then tear down **both** critical sections. Do not double-free nodes.
- **OleDb setup parent:** DB load path needs IAccessor + column metadata before binding build; temp buffer is **`colCount * 0x34`** DBBINDING records; success continues into shared SEH child frame (do not model as isolated call returning early without child state).
- Neither unit requires Launcher or server protocol changes for seal completeness.
