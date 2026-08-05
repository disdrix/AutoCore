# Review A (reconstruction fidelity): `aa_006264e0` CVOGHBActivatePlayer_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006264e0` |
| **VA** | `0x006264e0`–`0x0062652a` (75 B / `0x4B`; pad `CC` after) |
| **Canonical name** | `CVOGHBActivatePlayer_ctor_Inferred` (Ghidra `FUN_006264e0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W28-G) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_006264e0_CVOGHBActivatePlayer_ctor_Inferred.md` |
| **System** | heartbeat / timed-actions / player activate |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Parent dual W27-F for sole caller / `operator_new(0x2c)` context.

---

## 1. Purpose

**Activate-player HB subclass constructor.** After heap alloc of **0x2c** by the sole caller:

1. `CVOGHBBase_ctor`
2. Install vtbl **`0x009e3168`**
3. `CVOGHBBase_AttachOwnerObject(pOwner)` → owner at `+0x18`
4. Clear subclass flag `+0x28`
5. Copy `*(periodSrc+0x1c)` → `this+0x08`
6. Period from `*(periodSrc+0x18)` with **0→1** clamp; `SetPeriodAndCounter(..., true)`
7. Store host `pHost` at `this+0x24`
8. Return `this`

Does **not** Enqueue, Start, or write `host+0x6c4` — parent owns those.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_006264e0_FUN_006264e0.md` | Append re-verify |
| Annotated | `docs/reconstruction/raw/aa_006264e0_FUN_006264e0.annotated.md` | Refined |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBActivatePlayer_ctor_Inferred.cpp` | New |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_006264e0.cpp` | Refined |
| Function record | `docs/reconstruction/functions/aa_006264e0_CVOGHBActivatePlayer_ctor_Inferred.md` | New |
| Scaffold record | `docs/reconstruction/functions/aa_006264e0_FUN_006264e0.md` | Updated |
| Live decompile | Ghidra @ `0x006264e0` | ≡ raw CF |
| Live bytes | `read_memory` 80 B | body + pad |
| Xrefs / callers / callees | `analyze_function_complete` | sole caller + 3 callees |
| Vtbl head | `read_memory` @ `0x009e3168` | slot addresses |
| Parent dual | W27-F `Object_ActivatePlayerEnqueueHB_Inferred` | call-site args |

**Not performed:** Launcher, runtime golden, dual of vtbl methods `0x00626210` / `0x006261e0`, RTTI name recovery.

---

## 3. Signature (image-sealed)

```c
// __thiscall  ECX = this (fresh 0x2c allocation)
// stack: void *periodSrc, void *pOwner, void *pHost
// ret 0xC
// returns this*
void *CVOGHBActivatePlayer_ctor_Inferred(
    void *this, void *periodSrc, void *pOwner, void *pHost);
```

| Item | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX = this | `mov esi,ecx`; ops via `[esi]` | **High** |
| Three stack args / `ret 0xC` | `C2 0C 00`; stack offsets | **High** |
| Returns this | `mov eax,esi` | **High** |
| Vtbl `0x009e3168` | `C7 06 68 31 9E 00` | **High** |
| Flag `+0x28 = 0` | `C6 46 28 00` | **High** |
| Host `+0x24 = param_4` | `89 56 24` | **High** |
| Period clamp 0→1 | `test/jnz` + `mov eax,1` | **High** |
| Callee targets | relative-call math | **High** |
| Sole caller ActivatePlayer | xref_count 1 | **High** |
| Size `0x2c` | parent `operator_new` | **High** (caller) |
| Product class name | structural from parent role | **Inferred** |

---

## 4. Byte seal (relative calls)

| next-IP | Target | Callee |
|---|---|---|
| `0x006264e8` | `0x00508200` | `CVOGHBBase_ctor` |
| `0x006264fa` | `0x005083b0` | `CVOGHBBase_AttachOwnerObject` |
| `0x0062651e` | `0x005081a0` | `CVOGHBBase_SetPeriodAndCounter` |

Sole call site binding (parent decompile ≡ W27-F):

```
FUN_006264e0(host+0x24, player_obj, host)
// this = operator_new(0x2c)
```

---

## 5. Control flow: clean ≡ raw ≡ live decompile ≡ bytes

| Stage | Match |
|---|---|
| Base ctor → vtbl → AttachOwner | **Yes** |
| `+0x28=0` then field copies | **Yes** |
| Period clamp → SetPeriod(true) | **Yes** |
| Host store → return this / ret 0xC | **Yes** |
| No Enqueue / Start in leaf | **Yes** |

---

## 6. Gaps / open

1. Product/PDB class name for vtbl `0x009e3168`.
2. Semantic merge of `periodSrc+0x1c` dword vs SetPeriod dual period fields.
3. Virtual method English for subclass slots (`FUN_00626210` writes `host+0x6c8`, etc.) — not OWN.
4. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps** — CF/ABI/fields/sole-caller sealed; product class English open.
