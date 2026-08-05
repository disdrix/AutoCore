# Review A (reconstruction fidelity): `aa_006261e0` CVOGHBActivatePlayer_EndOrDestroy_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006261e0` |
| **VA** | `0x006261e0`–`0x00626202` (35 B / `0x23`; pad `CC` after) |
| **Canonical name** | `CVOGHBActivatePlayer_EndOrDestroy_Inferred` (Ghidra `FUN_006261e0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W29-P) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_006261e0_CVOGHBActivatePlayer_EndOrDestroy_Inferred.md` |
| **System** | heartbeat / timed-actions / player activate |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` / `get_function_by_address` / xrefs. **No** `disassemble_bytes`. Sibling: base `CVOGHBBase_EndOrDestroy` dual; twin OnEnd `0x00626210`.

---

## 1. Purpose

**Activate-player HB EndOrDestroy** virtual installed at `vtbl 0x009e3168 + 0x18` (overrides shared base helper usually at this slot):

1. if `(char)flag_onEnd == 0`: call own **OnEnd** (`(*this)->vtbl+0x14`)
2. always `CVOGHBBase_EndOrDestroy(this, flag_onEnd, flag_hard)` (`FUN_005083f0`)
3. **`ret 8`**

Rationale vs base: base **skips** OnEnd when flag0==0. Subclass still needs host notify on soft/abort → pre-call OnEnd, then base with flag0=0 (no double OnEnd). When flag0≠0, base alone runs OnEnd.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_006261e0_FUN_006261e0.md` | Append re-verify |
| Annotated | `docs/reconstruction/raw/aa_006261e0_FUN_006261e0.annotated.md` | Refined |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBActivatePlayer_EndOrDestroy_Inferred.cpp` | New |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_006261e0.cpp` | Refined |
| Function record | `docs/reconstruction/functions/aa_006261e0_CVOGHBActivatePlayer_EndOrDestroy_Inferred.md` | New |
| Scaffold record | `docs/reconstruction/functions/aa_006261e0_FUN_006261e0.md` | Updated |
| Live decompile | Ghidra @ `0x006261e0` | ≡ raw CF |
| Live bytes | `read_memory` 64 B | body + `C2 08 00` + pad into `00626210` |
| Vtbl | `read_memory` @ `0x009e3168` | slot `+0x18` = this VA |
| Base dual | `A_aa_005083f0_CVOGHBBase_EndOrDestroy.md` | two-flag contract |

**Not performed:** Launcher, runtime golden, exhaustive virtual caller matrix, RTTI name recovery.

---

## 3. Signature (image-sealed)

```c
// __thiscall  ECX = this
// stack: uint32_t flag_onEnd, uint32_t flag_hard
// ret 8; void
void CVOGHBActivatePlayer_EndOrDestroy_Inferred(
    void *this, uint32_t flag_onEnd, uint32_t flag_hard);
```

| Item | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX = this | `8B F1` | **High** |
| Two stack args / `ret 8` | `C2 08 00`; pushes before call | **High** |
| Pre-OnEnd iff flag0==0 | `test bl,bl` / `jnz` / `call [eax+0x14]` | **High** |
| Always base EndOrDestroy | relative call → `0x005083f0` | **High** |
| Body 35 B | `get_function_by_address` end `00626202` | **High** |
| DATA only xref | `0x009e3180` | **High** |
| Slot = EndOrDestroy | matches base dual “many vtbls +0x18” | **High** |
| Product method name | structural from class + slot | **Inferred** |

---

## 4. Control flow: clean ≡ raw ≡ live decompile ≡ bytes

| Stage | Match |
|---|---|
| flag0==0 → OnEnd vcall | **Yes** |
| Always FUN_005083f0(flag0,flag1) | **Yes** |
| ret 8 | **Yes** |
| No local hard/soft SEH | **Yes** (base owns) |

---

## 5. Gaps / open

1. Product/PDB EndOrDestroy spelling for this subclass.
2. Exhaustive site catalog of `(flag0,flag1)` pairs into this vfunc.
3. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps** — CF/ABI/vtbl slot/pre-OnEnd policy sealed; product English open.
