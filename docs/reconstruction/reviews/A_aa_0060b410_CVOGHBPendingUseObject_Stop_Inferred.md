# Review A (reconstruction fidelity): `aa_0060b410` CVOGHBPendingUseObject_Stop_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060b410` |
| **VA** | `0x0060b410`–`0x0060b438` |
| **Canonical name (proposed)** | `CVOGHBPendingUseObject_Stop_Inferred` |
| **Ghidra name** | `FUN_0060b410` |
| **Prior aliases** | `Named_CalleeOf_CVOGReaction_RecordFirstTimeEvent_0060b410` (scaffold only) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-T) |
| **Counterpart** | `reviews/B_aa_0060b410_CVOGHBPendingUseObject_Stop_Inferred.md` |
| **System** | heartbeat / missions-progression |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` |
| **Verdict** | **accept** on CF/ABI/this-adjust/EndOrDestroy; **accept-with-gaps** on product English |

**Tools:** Ghidra `decompile_function` + `read_memory` (+ function meta/xrefs/callees). **No** `disassemble_bytes`. No Launcher. No parent ledger edits.

---

## 1. Purpose

Stop/destroy the pending-use-object heartbeat aux (`char+0xca0`):

1. If `flag≠0` and `HB+0x18` owner non-null → `ResolveUseObjectPending(character=+0x28, commit=0)`.
2. Always `vtbl+0x18` EndOrDestroy`(flag_onEnd=1, flag_hard=1)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0060b410_FUN_0060b410.md` (+ W26-T append) |
| Annotated | `docs/reconstruction/raw/aa_0060b410_FUN_0060b410.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBPendingUseObject_Stop_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0060b410.cpp` |
| Function | `docs/reconstruction/functions/aa_0060b410_FUN_0060b410.md` |
| Named | `docs/reconstruction/functions/aa_0060b410_CVOGHBPendingUseObject_Stop_Inferred.md` |
| Live | decompile ≡ raw; body 41 B; `C2 04 00` |
| Related dual | `aa_00535ed0` ResolveUseObjectPending; `aa_005083f0` EndOrDestroy |

---

## 3. Signature (sealed)

```c
void __thiscall FUN_0060b410(CVOGHBPendingUseObject* self, char flag_cancel_pending);
// ret 4
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX | **High** |
| flag | Stack[0x4] byte | **High** |
| cleanup | `RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if flag && pOwnerObject(+0x18):
  ResolveUseObjectPending(pCharacter(+0x28), commit=0)
EndOrDestroy(self, 1, 1)
```

| Stage | Match | Conf |
|---|---|---|
| Flag gate | **Yes** | **High** |
| Owner gate `+0x18` | **Yes** | **High** |
| Character this-adjust `+0x28` | **Yes** | **High** (`mov ecx,[esi+0x28]`) |
| EndOrDestroy two pushes 1,1 | **Yes** | **High** |
| Live ≡ raw CF | **Yes** | **High** |

---

## 5. Callers (4 CODE xrefs)

| Caller | Flag | Role |
|---|---|---|
| `CVOGReaction_RecordFirstTimeEvent` | 1 | replace prior aux |
| `FUN_0052f260` | 1 | character dtor |
| `FUN_00535ed0` ×2 | 0 | clear after resolve (no re-cancel) |

---

## 6. Gaps / open

1. Product English for HB class (no string in body).
2. Runtime/bit-diff open.
3. Whether empty OnEnd (`vtbl+0x14` = `0x005081f0`) is intentional for this subclass.

**Verdict:** CF spine **accept High**. Product name **accept-with-gaps** (`_Inferred`).
