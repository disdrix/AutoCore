# Review B (skeptical / adversarial): `aa_005725a0` InventoryGrid_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005725a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-061) |
| **Counterpart** | `reviews/A_aa_005725a0_InventoryGrid_CompleteDtor.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the scalar-deleting dtor (vtbl[0]) | **Falsified** — no flags arg, bare `RET`, no `operator_delete(this)`; scalar is `00573910` which **calls** this |
| 2 | This only clears cells / FreeCellArray | **Falsified** — also map erase, list dual drain, DeleteCS; clear is nested `00570f70` |
| 3 | Ghidra body end `0057260b` is correct | **Falsified** — bytes continue through list dtor + DeleteCS + `C3` @ `0057264d` (174 B) |
| 4 | `operator_delete` of sentinel never returns | **Falsified** — false-noreturn; epilogue reached; `[ESI+4]/[ESI+8]` zeroed after call |
| 5 | cdecl / stack this | **Falsified** — `MOV EDI,ECX` |
| 6 | RET 4 (thiscall with stack arg) | **Falsified** — bare `C3` |
| 7 | Frees the InventoryGrid host | **Falsified** — host free only in scalar path when flags&1 |
| 8 | Not InventoryGrid family | **Falsified** — installs `PTR_FUN_009d3390`; ctor `00572650` same vtbl; dualed scalar twin |
| 9 | List dual `004bc950` is double-free hazard | **Resisted** — first drain empties; second base step is empty walk (safe MSVC inheritance step); CS left each time |
| 10 | Name should stay `Named_CalleeOf_*` scaffold | **Falsified** — structural CompleteDtor sealed; scaffolds retired |
| 11 | Same as ctor | **Falsified** — reverse teardown only; no allocate/init |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar separation | **High** | Double-free / leak host / wrong RET |
| Full body 174 B (not Ghidra 0x6C-ish) | **High** | Miss list/CS teardown → CS leak / UAF |
| ECX this / bare RET | **High** | Stack corruption |
| Cell `delete[]` @ +0x28 | **High** | Wrong free / leak grid cells |
| Map @ +0x5c teardown | **High** | Leak tree nodes |
| List @ +0x2c + DeleteCS @ +0x30 | **High** | CS leak |
| InventoryGrid family label | **High** | Wrong system map only |
| Product MSVC demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + dualed twins

```
// FUN_005725a0 — complete body (bytes; not truncated decompile)
EDI = this
[EDI] = 0x009d3390
call 00570f70                          ; clear items + re-empty cells
if ([EDI+0x28]) delete[] ; [EDI+0x28]=0
ESI = EDI+0x5c
call 00573700(map, *head, head)        ; erase all
delete head; [ESI+4]=0; [ESI+8]=0
ESI = EDI+0x2c
[ESI]=0x009d3384; call 004bc950
[ESI]=0x009cb334; call 004bc950
DeleteCriticalSection(EDI+0x30)
RET
```

| Twin / parent | Check |
|---|---|
| Scalar `00573910` | Always `call 005725a0` then optional `delete this` — dualed **accept** |
| Ctor `00572650` | InitCS + tree sentinel + Allocate reverse of this order |
| Clear `00570f70` | First stage; dualed MEGA-090; does not free cells permanently (re-allocates) — complete dtor then `delete[]` |

Live decompile 2026-08-05 ≡ raw 2026-07-23 **through truncated tail only**. Full CF sealed by `read_memory` hex, not decompiler.

---

## 4. Surviving contract for AutoCore

```cpp
// Port complete dtor only (not scalar wrapper):
void InventoryGrid_CompleteDtor(InventoryGrid* self) {
  self->vtbl = &InventoryGrid_vtbl;           // PTR_FUN_009d3390
  InventoryGrid_ClearItemsAndReEmptyCells(self);
  operator_delete[](self->cellArray); self->cellArray = nullptr;
  // destroy map @ +0x5c (erase + free sentinel + zero)
  // destroy list @ +0x2c (inheritance step + drain helper)
  DeleteCriticalSection(&self->cs);           // +0x30
}
// ECX=this; bare RET; do NOT free host here.
// ScalarDeletingDtor: CompleteDtor(this); if (flags&1) delete this; ret 4;
```

Port risks if incomplete:
- Stopping at Ghidra's truncated decompile **leaks** list CS and skips list member dtor.
- Inlining host free into this VA **breaks** stack/in-place destroy paths that call complete without bit0.

---

## 5. Verdict

All adversarial attacks on ABI, role, body extent, and family fail. Bytes override truncated decompile. Residual product demangle is naming-only. **accept**.
