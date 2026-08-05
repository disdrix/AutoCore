# Review A (reconstruction fidelity): `aa_0050846f` CVOGHBBase_EndOrDestroy_SoftMarkEpilogue

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050846f` |
| **VA** | `0x0050846f` |
| **Body** | `0x0050846f`–`0x00508488` |
| **Canonical name** | `CVOGHBBase_EndOrDestroy_SoftMarkEpilogue` |
| **Ghidra symbol** | `FUN_0050846f` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B — W21-B) |
| **Counterpart** | `reviews/B_aa_0050846f_CVOGHBBase_EndOrDestroy_SoftMarkEpilogue.md` |
| **System** | heartbeat / CVOGHBBase |
| **Live tools** | `decompile_function`, `read_memory`, `get_function_by_address`, xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Soft-mark + SEH epilogue** of parent `CVOGHBBase_EndOrDestroy` (`0x005083f0`, via hard fragment `0x0050843d`):

1. `this+0x20 = 1` (soft-ended).
2. `this+0x18 = ebx` (clear owner link; parent holds EBX = 0).
3. Restore `ExceptionList` from `[ebp-0xc]`.
4. Full epilogue including **`ret 8`**.

Carved continuation — **not** a free-standing API with a prologue.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `raw/aa_0050846f_FUN_0050846f.md` | W21-B append + full body hex |
| Annotated | `raw/aa_0050846f_FUN_0050846f.annotated.md` | Sealed |
| Clean named | `reconstructed-exact/CVOGHBBase_EndOrDestroy_SoftMarkEpilogue.cpp` | New sealed |
| Clean scaffold | `reconstructed-exact/FUN_0050846f.cpp` | Replaced scaffold |
| Function record | `functions/aa_0050846f_*` | Updated |
| Live decompile | Ghidra `0x0050846f` | ≡ 2026-07-23 raw |
| Live `read_memory` | 32 B from entry | Complete body sealed |
| Body range | `get_function_by_address` | ends `00508488` |
| Parent dual | `A_aa_0050843d_…HardListUnlink` | always falls here |
| Parent dual | `A_aa_005083f0_CVOGHBBase_EndOrDestroy` | frame / flags |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Sole structural caller = `FUN_0050843d` | **High** | 4 xrefs, all jumps |
| ESI=this, EBX=0, EBP=parent | **High** | parent dual + stores |
| Soft mark `+0x20=1` | **High** | `C6 46 20 01` |
| Clear `+0x18` | **High** | `89 5E 18` |
| ExceptionList restore + `ret 8` | **High** | complete epilogue hex |
| Leaf (no callees) | **High** | analyze_function_complete |
| Product fragment name | **Probable** | inferred from parent family |
| Runtime | Open | |

---

## 4. Control flow seal (`read_memory`)

```text
mov  byte ptr [esi+0x20], 1
mov  [esi+0x18], ebx
mov  ecx, [ebp-0xc]
pop  edi
pop  esi
mov  fs:[0], ecx
pop  ebx
mov  esp, ebp
pop  ebp
ret  8
```

No branches. Single straight-line fragment.

---

## 5. Callers / callees

| Direction | Target | Role |
|---|---|---|
| In | `FUN_0050843d` | Hard/soft tail only |
| Out | — | leaf |

---

## 6. Gaps / open

1. Product C++ symbol (may be inlined end of `EndOrDestroy` in source).
2. English name of `+0x20` flag beyond soft-ended.
3. Runtime / bit-exact open.

**Verdict:** **accept** — complete body byte-sealed; role fixed by parent dual; no CF ambiguity.
