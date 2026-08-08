# Review A (reconstruction fidelity): `aa_00607550` Outpost_GetScheduleEntryValueAtCursor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00607550` |
| **VA** | `0x00607550`–`0x006075a8` exclusive (**88 B**) |
| **Canonical name** | `Outpost_GetScheduleEntryValueAtCursor_Inferred` |
| **Ghidra name** | `FUN_00607550` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ8R-E) |
| **Counterpart** | `reviews/B_aa_00607550_Outpost_GetScheduleEntryValueAtCursor_Inferred.md` |
| **System** | outpost / capture schedule |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full body hex) + callers/callees + `get_assembly_context` @ `0x006085cc`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Return the schedule-table entry **dword at +4** for the outpost's current schedule cursor (`+0x23c`), selecting between dual global banks via `+0x220`. Soft-return **0** when the cursor is negative or out of range. Arm site: `Outpost_CaptureOutpost` stores the result into `timerBlob[+8]`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ8R-E append) | `docs/reconstruction/raw/aa_00607550_FUN_00607550.md` |
| Annotated | `docs/reconstruction/raw/aa_00607550_FUN_00607550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Outpost_GetScheduleEntryValueAtCursor_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00607550.cpp` |
| Function record | `docs/reconstruction/functions/aa_00607550_Outpost_GetScheduleEntryValueAtCursor_Inferred.md` |
| Parent dual | `Outpost_CaptureOutpost` A/B (W20-D) |
| Twin float | `Outpost_GetPulseXpPercent` @ `0x006075b0` (entry+8) |
| Throw helper | `FUN_00608620` plate `"invalid vector<T> subscript"` |

---

## 3. Signature (sealed)

```c
// ECX = outpost*; plain RET; returns EAX
uint32_t __thiscall Outpost_GetScheduleEntryValueAtCursor_Inferred(void* self);
```

| Claim | Evidence | Conf |
|---|---|---|
| ECX = this | `8B C1` | **High** |
| No stack formals | epilogue `C3` (no `C2 xx`) | **High** |
| Return EAX dword | `8B 44 16 04` / `33 C0` | **High** |
| Pure (no host write) | no stores to self | **High** |

---

## 4. Control flow (bytes authority)

```
table = (self+0x220 != 0) ? DAT_00d029e0 : DAT_00d029f0
index = *(int32*)(self+0x23c)
if index < 0: return 0
begin = *(table+4)
size  = begin ? ((*(table+8)-begin)>>4) : 0   // stride 16
if index >= size: return 0
// recheck (MSVC operator[] shape):
if begin==0 OR size <= index: FUN_00608620()  // noreturn throw
return *(uint32*)(begin + index*16 + 4)
```

| Stage | Match | Conf |
|---|---|---|
| Dual bank select | decompile ≡ bytes | **High** |
| Soft OOB → 0 | signed jl + unsigned jae → xor/ret | **High** |
| Field +4 / stride 0x10 | `C1 E6 04` / `8B 44 16 04` | **High** |
| Throw only pathological | jmp `FUN_00608620` after recheck | **High** |
| Capture timer arm | asm ctx: result → timer[+8] | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (88 B):

```
8bc180b82002000000b9e029d0007505b9f029d000568bb03c02000085f67c358b510485d2750433c0eb088b41082bc2c1f8043bf0731e85d2740c8b41082bc2c1f8043bc67705e984100000c1e6048b4416045ec333c05ec3
```

Pad `CC`×7; next `Outpost_GetPulseXpPercent` @ `0x006075b0`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker / pure lookup |
| Callers | 1: `Outpost_CaptureOutpost` @ `0x006085cc` |
| Callees | `FUN_00608620` (pathological only) |
| Reject name | `Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00607550` |

### CaptureOutpost call-site order (context)

```
self+0x238 = scheduleCount
self+0x23c = 0
eax = Outpost_GetScheduleEntryValueAtCursor_Inferred(self)
timerBlob = self+0x248
timerBlob[+8] = eax
timerBlob[+0x14] = GetTickCount()
```

---

## 7. Gaps

1. Product English for entry+4 dword (duration vs schedule id vs other) — timer-arm use sealed; semantic label residual.  
2. Writers / population of `DAT_00d029e0` / `DAT_00d029f0` — not owned.  
3. Entry fields +0 / +0xC unknown.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI, bank/cursor/stride/field+4, soft-OOB, sole caller, and twin relation are sealed → **accept-with-gaps** (product English residual only).
