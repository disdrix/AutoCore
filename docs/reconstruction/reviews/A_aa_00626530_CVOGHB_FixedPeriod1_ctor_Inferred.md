# Review A (reconstruction fidelity): `aa_00626530` CVOGHB_FixedPeriod1_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00626530` |
| **VA** | `0x00626530`–`0x00626561` (**50 B** / `0x32`; pad `CC` after) |
| **Canonical name** | `CVOGHB_FixedPeriod1_ctor_Inferred` (Ghidra `FUN_00626530`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W29-O) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00626530_CVOGHB_FixedPeriod1_ctor_Inferred.md` |
| **System** | heartbeat / timed-actions |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_xrefs_to`. **No** `disassemble_bytes`. Sibling dual W28-G for vtbl-family contrast only.

---

## 1. Purpose

**HB subclass constructor** after heap alloc of **0x50** by the sole call site:

1. `CVOGHBBase_ctor`
2. Install vtbl **`0x009e3188`**
3. `CVOGHBBase_AttachOwnerObject(pOwner)` → owner at base `+0x18`
4. `*(this+0x08) = arg5`
5. `CVOGHBBase_SetPeriodAndCounter(this, 1, true)` — period **fixed 1**
6. Return `this`

Does **not** Enqueue, Start, store host@`+0x24`, or clear flag@`+0x28` (contrast `CVOGHBActivatePlayer_ctor_Inferred`).

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00626530_FUN_00626530.md` | Append re-verify |
| Annotated | `docs/reconstruction/raw/aa_00626530_FUN_00626530.annotated.md` | Refined |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHB_FixedPeriod1_ctor_Inferred.cpp` | New |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_00626530.cpp` | Refined |
| Function record | `docs/reconstruction/functions/aa_00626530_CVOGHB_FixedPeriod1_ctor_Inferred.md` | New |
| Scaffold record | `docs/reconstruction/functions/aa_00626530_FUN_00626530.md` | Updated |
| Live decompile | Ghidra @ `0x00626530` | ≡ raw CF |
| Live bytes | `read_memory` 80 B | body + pad |
| Vtbl head | `read_memory` @ `0x009e3188` | slots sealed |
| Sole xref | `0x006267f1` | undelimited parent |

**Not performed:** Launcher, runtime, dual of `0x00626570` / undelimited parent, RTTI name recovery.

---

## 3. Signature (image-sealed)

```c
// __thiscall  ECX = this (fresh 0x50 allocation at sole site)
// stack: void *pOwner, uint32_t arg3, uint32_t arg4, uint32_t arg5
// ret 0x10
// returns this*
void *CVOGHB_FixedPeriod1_ctor_Inferred(
    void *this, void *pOwner, uint32_t arg3, uint32_t arg4, uint32_t arg5);
```

| Item | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX = this | `mov esi,ecx`; ops via `[esi]` | **High** |
| Four stack args / `ret 0x10` | `C2 10 00`; stack offsets | **High** |
| Returns this | `mov eax,esi` | **High** |
| Vtbl `0x009e3188` | `C7 06 88 31 9E 00` | **High** |
| `+0x08 = arg5` | `89 4E 08` after `[esp+0x14]` | **High** |
| Period fixed 1 | dual `push 1` before SetPeriod | **High** |
| arg3/arg4 unused | no body reads | **High** |
| Sole code xref | xref_count 1 @ `006267f1` | **High** |
| Size `0x50` | parent `push 0x50; operator_new` | **High** (caller) |
| Product class name | structural | **Inferred** |

---

## 4. Byte seal (relative calls)

| next-IP | Target | Callee |
|---|---|---|
| `0x00626538` | `0x00508200` | `CVOGHBBase_ctor` |
| `0x0062654A` | `0x005083b0` | `CVOGHBBase_AttachOwnerObject` |
| `0x0062655C` | `0x005081a0` | `CVOGHBBase_SetPeriodAndCounter` |

Sole call-site binding (parent undelimited):

```
new(0x50);
FUN_00626530(owner_MI, host+0x6d0, host+0x6e0, 0x3E8);
// this = allocation; 0x3E8 → +0x08
```

---

## 5. Control flow: clean ≡ raw ≡ live decompile ≡ bytes

| Stage | Match |
|---|---|
| Base ctor → vtbl → AttachOwner | **Yes** |
| `+0x08 = arg5` then SetPeriod(1,true) | **Yes** |
| Return this / ret 0x10 | **Yes** |
| No Enqueue / Start / +0x24 / +0x28 in leaf | **Yes** |

---

## 6. Gaps / open

1. Product/PDB class name for vtbl `0x009e3188`.
2. Semantic meaning of unused arg3/arg4 (`host+0x6d0` / `host+0x6e0` at call site).
3. Nested vtbl method `0x00626570` English (not OWN).
4. Undelimited parent dual — open.
5. Runtime / differential — open.

**Verdict:** **accept-with-gaps** — CF/ABI/fields/sole-xref sealed; product class English open.
