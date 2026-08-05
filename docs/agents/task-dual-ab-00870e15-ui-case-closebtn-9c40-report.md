# Dual A/B report — `aa_00870e15` UI_Case_CloseBtn_9c40

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00870e15`. Dual A/B + three-rep refine. Seal UI case handler for close control `0x9c40`.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `decompile_function` + `force_decompile` + `batch_decompile` + `read_memory` (+ xrefs / function meta). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00870e15` UI_Case_CloseBtn_9c40 | **accept-with-gaps** — CF/ABI/gates sealed; class RTTI + `+0x50c` English gapped |

---

## Sealed facts

1. **Role:** Jump-table **case arm** for control id **`0x9c40` (40000 / close)** under parent dispatcher **`0x00870a90`** (`switch (controlId - 0x9c40)`, range 0..11). Body **`0x00870e15`–`0x00870e43`**.

2. **ABI (byte-sealed):** Parent thiscall loads **msg→EAX**, **controlId→EDX**, **this→EDI**. Case tails **`pop edi; ret 8`**. Decompiler `__fastcall` / unused `param_1` / `in_EAX`/`unaff_EDI` phantoms corrected.

3. **CF:**
   - **msg == 8:** if **`this+0x50c == -1`** → **`FUN_007fca10`** (EAX=`this`, EBX=`0x00d1a840`); else skip leave; **always return 1**.
   - **else:** **`FUN_0087b500(this, msg, controlId)`** (`mov ecx,edi; push edx; push eax; call`) and return its result.

4. **Three-rep:** decompile / force_decompile / batch_decompile **identical** to frozen raw CF.

5. **Xrefs:** DATA jumptable entry `0x00870e44` → this VA; COMPUTED_JUMP label `0x00870aaa`.

6. **Name:** `UI_Case_CloseBtn_9c40` (Ghidra `caseD_9c40`). Not mission `FUN_008aec40` close path (shared id constant + leave host only).

7. **Callees (not owned):** leave host `FUN_007fca10` @ `0x007fca10`; forward `FUN_0087b500` @ `0x0087b500`.

---

## Gaps

1. Product/RTTI dialog class for vtable slot → `0x00870a90`.  
2. English type of selection at `+0x50c` (sibling writer `FUN_00870680` treats −1 as clear).  
3. Whether this class’s leave `vtbl+0x440` is Flush vs hide.  
4. Runtime / bit-exact / differential open.

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00870e15_UI_Case_CloseBtn_9c40.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00870e15_UI_Case_CloseBtn_9c40.md` | **accept-with-gaps** |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00870e15_UI_Case_CloseBtn_9c40.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00870e15_UI_Case_CloseBtn_9c40.md` |
| Function record | `docs/reconstruction/functions/aa_00870e15_UI_Case_CloseBtn_9c40.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_Case_CloseBtn_9c40.cpp` |
| Raw (authoritative + v2026-07-29 append) | `docs/reconstruction/raw/aa_00870e15_FUN_00870e15.md` |
| Annotated | `docs/reconstruction/raw/aa_00870e15_FUN_00870e15.annotated.md` |
| This report | `docs/agents/task-dual-ab-00870e15-ui-case-closebtn-9c40-report.md` |

Legacy scaffold retained: `functions/aa_00870e15_FUN_00870e15.md`, `reconstructed-exact/FUN_00870e15.cpp`.

---

## AutoCore impact

- **Client UI case only** — no new server packet.  
- Close click must honor **`+0x50c != -1` → no leave**.  
- Do not merge identity with mission close in `FUN_008aec40`; only shared constants/host.  
- Wrappers must use **thiscall + ret 8**, not decompiler `__fastcall` shape.
