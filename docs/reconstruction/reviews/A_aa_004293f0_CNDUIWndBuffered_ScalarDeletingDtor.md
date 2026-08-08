# Review A (reconstruction fidelity): `aa_004293f0` CNDUIWndBuffered_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004293f0` |
| **VA** | `0x004293f0`–`0x0042940d` exclusive (**29 B**) |
| **Canonical name** | `CNDUIWndBuffered_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004293f0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY R10-009) |
| **Counterpart** | `reviews/B_aa_004293f0_CNDUIWndBuffered_ScalarDeletingDtor.md` |
| **System** | skills-abilities / CNDUIWndBuffered / MSVC scalar-deleting destructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex + vtbl dword) + xrefs. **No** `disassemble_bytes`. |
| **Parent dual** | `0x0078ca80` `CNDUIWndBuffered_CompleteDtor` (WQ9K-F) |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC scalar-deleting destructor (vtbl[0] of `PTR_FUN_00a99f74`): always run complete dtor `CNDUIWndBuffered_CompleteDtor` / `FUN_0078ca80`; if `(flags & 1)` free the host with `operator_delete`; return `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R10-009 append) | `docs/reconstruction/raw/aa_004293f0_FUN_004293f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004293f0_FUN_004293f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWndBuffered_ScalarDeletingDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004293f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004293f0_CNDUIWndBuffered_ScalarDeletingDtor.md` |
| Parent complete | `CNDUIWndBuffered_CompleteDtor` @ `0x0078ca80` (dual A/B WQ9K-F) |
| Live | decompile ≡ bytes; vtbl dword @ `0x00a99f74` = `0x004293f0` |

---

## 3. Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this*
void* __thiscall CNDUIWndBuffered_ScalarDeletingDtor(void* self, uint8_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`56 8B F1`) | **High** |
| flags | stack (`F6 44 24 08 01`) | **High** |
| return | EAX = ESI = this | **High** |
| cleanup | `C2 04 00` | **High** |

---

## 4. Control flow (bytes authority)

```
ESI = this
call FUN_0078ca80              // CNDUIWndBuffered_CompleteDtor
if (flags & 1):
  operator_delete(this)        // 0x00489822
return this                    // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete-then-optional-free | decompile ≡ 29 B hex | **High** |
| bit0 gate only (not vector) | `test …,1` / `je` | **High** |
| False noreturn ignored | epilogue present after delete | **High** |
| vtbl[0] | DATA `00a99f74` → `004293f0` | **High** |
| Product class | parent RTTI `.?AVCNDUIWndBuffered@@` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (29 B):

```
568bf1e888363600f644240801740956e81d04060083c4048bc65ec20400
```

Pad `CC CC` then next sibling scalar-dtor pattern @ `0x00429410`.

Relative call targets sealed:

| Site | Rel32 | Target |
|---|---|---|
| after `56 8B F1` | `+0x00363688` | `0x0078ca80` complete |
| free path | `+0x0006041d` | `0x00489822` `operator_delete` |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | DATA vtbl[0] only (no code CALL sites in bulk xrefs) |
| Callees | `FUN_0078ca80` / `CNDUIWndBuffered_CompleteDtor`, `operator_delete` |

---

## 7. Gaps

1. Complete dtor body / member map not owned here (`FUN_0078ca80` — parent dual).  
2. Runtime / bit-exact / differential — open (Terminal false).  
3. Partition system tag is skills-abilities residual of parent dual; host is UI class (naming not product-open).

---

## 8. Verdict

ABI, CF, vtbl slot, scalar-vs-complete separation, and product class name (via parent RTTI) are sealed with high confidence. Residual gaps are ownership/runtime only → **accept**.
