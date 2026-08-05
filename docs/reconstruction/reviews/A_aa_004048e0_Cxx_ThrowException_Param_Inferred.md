# Review A (reconstruction fidelity): `aa_004048e0` Cxx_ThrowException_Param_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004048e0` |
| **VA** | `0x004048e0` |
| **Canonical name** | `Cxx_ThrowException_Param_Inferred` |
| **Ghidra name** | `FUN_004048e0` |
| **Prior alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_004048e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity (OWN-ONLY dual; Skill_DbLoadSkillsCharacters nested) |
| **Counterpart** | `reviews/B_aa_004048e0_Cxx_ThrowException_Param_Inferred.md` |
| **System** | `crt-com` / MSVC exception throw helper |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, `get_function_callers` / callees of `0x007e34b0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Non-returning** MSVC C++ exception throw: takes one stack dword `param_1`, materializes it as the exception object on the stack, and calls `_CxxThrowException(&object, &ThrowInfo_DAT_00acc3fc)`.

Used across COM/BSTR failure paths (including `Skill_DbLoadSkillsCharacters` when `SysAllocString` of xpath / column names returns null) as a hard abort — not game-logic recovery.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004048e0_FUN_004048e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004048e0_FUN_004048e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004048e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004048e0_FUN_004048e0.md` |
| Parent skill loader | `reviews/A_aa_007e34b0_Skill_DbLoadSkillsCharacters.md` |
| Live bytes | `read_memory` @ `0x004048e0` length 32; body ends before `CC` pad |
| ThrowInfo | `read_memory` @ `0x00acc3fc` |
| `_CxxThrowException` | rel32 from `0x004048f2` → `0x006a3d60` |

**Not performed:** `disassemble_bytes`, Launcher, runtime throw catch.

---

## 3. Assembly-sealed body (`read_memory` @ `0x004048e0`)

```text
004048e0  8B442404        mov  eax, dword ptr [esp+4]   ; param_1
004048e4  68FCC3AC00      push 0x00acc3fc               ; ThrowInfo*
004048e9  8D4C2408        lea  ecx, [esp+8]             ; &stack_slot(param)
004048ed  51              push ecx                      ; pExceptionObject
004048ee  8944240C        mov  dword ptr [esp+0xC], eax ; ensure object = param_1
004048f2  E869F42900      call _CxxThrowException       ; → 0x006a3d60
004048f7  CC…             int3 pad
```

Hex: `8b44240468fcc3ac008d4c2408518944240ce869f42900`

| Claim | Evidence | Conf |
|---|---|---|
| Body size **23 bytes** (`004048e0`–`004048f6`) | `read_memory` + `CC` pad | **High** |
| One stack formal at `[esp+4]` | `mov eax,[esp+4]` | **High** |
| ThrowInfo fixed `DAT_00acc3fc` | imm `push 0x00acc3fc` | **High** |
| Does not return | `call _CxxThrowException` only; no `ret` | **High** |
| Clean ≡ raw ≡ live | three-rep | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = C++ throw of stack-copied param | **High** | bytes + CRT API |
| Product type of ThrowInfo object | **Medium** | structure at `00acc3fc` present; full RTTI not walked |
| Always HRESULT / always `_com_error` | **Low–Med** | callers pass failure context; type not sealed from this leaf |
| Nested under skill DB load on BSTR OOM | **High** | `get_function_callees` of `0x007e34b0` lists this VA |
| Shared multi-caller leaf (DB/COM) | **High** | many callers: DB loaders, COM helpers |

---

## 5. Call graph (this unit)

**Callees:** `_CxxThrowException` @ `0x006a3d60`

**Callers (sample):** `Skill_DbLoadSkillsCharacters` `0x007e34b0`, `DB_ReadPowerPlantSpecific`, many `004*`/`007*` COM/BSTR sites (shared throw funnel).

---

## 6. Gaps

1. Full ThrowInfo / catchable-type decode for `DAT_00acc3fc` (sibling `DAT_00acc430` used elsewhere for raw HRESULT throws).
2. Exact per-call-site stack value of `param_1` (often elided in decompiler).
3. Whether AutoCore needs a port of this path (client-only COM).

**Verdict:** **accept-with-gaps**
