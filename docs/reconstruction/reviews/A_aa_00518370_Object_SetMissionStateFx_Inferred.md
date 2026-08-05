# Review A (reconstruction fidelity): `aa_00518370` Object_SetMissionStateFx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518370` |
| **VA** | `0x00518370`–`0x00518580` (**529 B / `0x211`**) |
| **Canonical name** | `Object_SetMissionStateFx_Inferred` |
| **Ghidra name** | `FUN_00518370` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W30-H) |
| **Reviewer role** | Reconstruction fidelity (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_00518370_Object_SetMissionStateFx_Inferred.md` |
| **System** | client-fx / mission-state SpecialFX |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Set object mission/progress FX **state** and refresh secondary FX:

1. Write `newState` to `+0x154` (keep old for compare).
2. Gate on clonebase FX master (`[+0xA8]+0x88`) and vtbl+`0x1CC` linked host `+8`.
3. If same state and `+0x184` bit2 already set → no-op.
4. `Object_TeardownSecondaryFxList_Inferred(1)` then `*(+0x184) |= 4`.
5. State **>2**: mission-complete audio only.
6. State **0/1/2**: ensure catalog + `FxMaster_LoadEventVariant` events **9/10/11**; states 1–2 wipe linked `+0x148`; attach via vtbl+`0xF8`; `Vector_PushDword`; audio; `FUN_004b7e50`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00518370_FUN_00518370.md` (+ W30-H append) |
| Annotated | `docs/reconstruction/raw/aa_00518370_FUN_00518370.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_SetMissionStateFx_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00518370.cpp` |
| Function | `docs/reconstruction/functions/aa_00518370_*` |
| Live | decompile ≡ raw CF; body `00518370`–`00518580`; epilogue `C2 04 00` |
| Nested | W29-N TeardownSecondaryFxList; FxMaster_LoadEventVariant dual |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 529 B | **Confirmed** | `get_function_by_address` + pad `CC` |
| thiscall + `ret 4` | **Confirmed** | entry `mov esi,ecx`; epilogue `C2 04 00` |
| State dword `+0x154` | **Confirmed** | entry store / decomp `[0x55]` |
| Flag bit2 `+0x184` | **Confirmed** | matches W29-N secondary FX arm |
| Events 9/10/11 | **Confirmed** | three `FUN_004a16d0` sites |
| Callers push 3 / progress | **Confirmed** | SpawnObject, `005c8580` math |
| Product English | **Inferred** | `_Inferred` |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Save/set state + gates | **Yes** |
| Teardown secondary + arm bit2 | **Yes** |
| state>2 audio-only | **Yes** |
| state 0/1/2 event load + attach | **Yes** |
| Shared epilogue `ret 4` | **Yes** |

### 4.1 Sealed contract

```
// thiscall; ret 4
void Object_SetMissionStateFx_Inferred(void *self, int newState);
// +0x154 = newState; teardown secondary; | =4 on +0x184;
// >2: audio only; 0/1/2: FxMaster events 9/10/11 + attach + audio
```

---

## 5. Callers / callees (live)

**CODE callers:** `CVOGReaction_SpawnObject`, `FUN_005825d0`, `FUN_00582670`, `FUN_005c8270`, `FUN_005c8580` (5 xrefs).  
**Callees:** `FUN_00516930`, `FUN_004eb3b0`, `FUN_004a16d0`, audio pair, `CVOGReaction_FailMissionNotify`/`Vector_PushDword`, `FUN_004b7e50`.

---

## 6. Gaps

1. Product C++ class / state enum names.  
2. Full semantics of `FUN_004b7e50` and audio helper.  
3. Runtime / bit-diff.

---

## 7. Verdict

**accept** — ABI, layout, CF, nested teardown, and event-id mapping sealed for port.
