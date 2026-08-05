# Review A (reconstruction fidelity): `aa_0050843d` CVOGHBBase_EndOrDestroy_HardListUnlink

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050843d` |
| **VA** | `0x0050843d` |
| **Body** | `0x0050843d`–`0x00508463` (**39** bytes Ghidra fragment) |
| **Canonical name** | `CVOGHBBase_EndOrDestroy_HardListUnlink` (inferred) |
| **Ghidra symbol** | `FUN_0050843d` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B — W20-R) |
| **Counterpart** | `reviews/B_aa_0050843d_CVOGHBBase_EndOrDestroy_HardListUnlink.md` |
| **System** | heartbeat / CVOGHBBase |
| **Live tools** | `decompile_function`, `read_memory`, `get_function_by_address`, callers (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Hard-flag list-unlink branch** of parent `CVOGHBBase_EndOrDestroy` (`0x005083f0`, vtbl slot **`+0x18`** on many HB types):

1. Advance SEH state to **3**.
2. If **`flag_hard` (`[ebp+0xc]`)** and HB **`this+0x18`** owner link and **`*(owner+0xb0)`** list manager are all non-zero → **`FUN_005085b0(listMgr, this)`** (thread-safe remove-by-key; dual sealed).
3. **Always** enter **`FUN_0050846f`**: soft-mark `this+0x20 = 1`, clear `this+0x18`, restore ExceptionList / complete parent **`ret 8`**.

This is a **carved SEH continuation**, not a free-standing API with a prologue.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `raw/aa_0050843d_FUN_0050843d.md` | W20-R append + byte CF |
| Annotated | `raw/aa_0050843d_FUN_0050843d.annotated.md` | Updated (decomp gaps noted) |
| Clean | `reconstructed-exact/CVOGHBBase_EndOrDestroy_HardListUnlink.cpp` | New sealed |
| Alias | `reconstructed-exact/FUN_0050843d.cpp` | Fixed 005085b0 ABI |
| Function record | `functions/aa_0050843d_FUN_0050843d.md` | Updated |
| Live decompile | Ghidra `0x0050843d` | unaff residual shape |
| Live `read_memory` | 64 B from entry | Hard gate + call sealed |
| Body range | `get_function_by_address` | ends `00508463` |
| Parent dual | `A_aa_005083f0_CVOGHBBase_EndOrDestroy` | frame/flags |
| List dual | `A_aa_005085b0_FUN_005085b0` | remove-by-key |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Sole structural caller = `FUN_005083f0` | **High** | Ghidra callers |
| ESI=this, EBX=0, EBP=parent | **High** | parent dual + bytes |
| `flag_hard` at `[ebp+0xc]` | **High** | `cmp [ebp+0xc], bl` |
| Owner link `this+0x18` | **High** | |
| List manager `*(owner+0xb0)` → ECX for remove | **High** | bytes `mov ecx,eax` |
| Stack key = HB (push esi) | **High** | |
| Soft mark always via `FUN_0050846f` | **High** | all jz/jmp land there |
| Soft stores not inside 39 B range | **High** | Ghidra body end |
| Decomp `FUN_005085b0(esi)` under-models thiscall | **High** | corrected in clean |
| Product fragment name | **Probable** | inferred from parent |
| Runtime | Open | |

---

## 4. Control flow seal (`read_memory`)

```text
cmp  [ebp+0xc], bl          ; flag_hard
mov  [ebp-4], ebx
mov  byte [ebp-4], 3
jz   FUN_0050846f           ; soft
mov  eax, [esi+0x18]        ; owner
cmp  eax, ebx
jz   FUN_0050846f
mov  eax, [eax+0xb0]        ; listMgr
cmp  eax, ebx
jz   FUN_0050846f
push esi
mov  ecx, eax
call FUN_005085b0
jmp  FUN_0050846f
```

Parent contract (for port completeness):

```text
// FUN_005083f0 outline (prior dual)
if flag_onEnd==0: this+0x18=0 else OnEnd(vtbl+0x14)
→ enter 0050843d hard/soft tail
```

---

## 5. Callers / callees

| Direction | Target | Role |
|---|---|---|
| In | `FUN_005083f0` | EndOrDestroy only |
| Out | `FUN_005085b0` | list remove-by-key |
| Out | `FUN_0050846f` | soft mark + SEH epilogue |

---

## 6. Gaps / open

1. Soft-tail unit `FUN_0050846f` dual not owned this wave (CF sealed via parent/sibling + bytes).
2. Owner object product type at `+0x18` / list field `+0xb0`.
3. SEH state machine levels (state 1 parent → state 3 here).
4. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps** — hard-path CF and correct `FUN_005085b0` ABI sealed; fragment naming + soft-tail dual residual.
