# Review A (reconstruction fidelity): `aa_00799900` XmlContainer_GetItem_OrDebugStop

| Field | Value |
|---|---|
| **Stable ID** | `aa_00799900` |
| **VA** | `0x00799900` |
| **Canonical name** | `XmlContainer_GetItem_OrDebugStop` (structural) |
| **Ghidra name** | `FUN_00799900` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00799900_XmlContainer_GetItem_OrDebugStop.md` |
| **System** | XML / mission-def / NDSpecialFX load |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Validate / resolve a child item through the container at `this+0x8`**, logging a hard debug stop on failure.

```c
// __thiscall  (ret 4)
// this+0x8 → COM/XML collection object
// vtbl[+0x1c](collection, itemInOut, &itemSlot)  — status in EAX
undefined4 __thiscall FUN_00799900(int this, undefined4 item)
{
  status = (**(this+8)->vtbl + 0x1c)(*(this+8), item, &item /* stack slot */);
  if (status == 0)
    return item_slot;          // live: [esp+4] after call (may be rewritten)
  FUN_007a4480(0, "VOG_DEBUG_STOP");  // NDError_Log — level/flag 0 ⇒ no-op log body
  return 0;
}
```

String evidence: **`"VOG_DEBUG_STOP"`** at `0x00a15844` (ASCII). Log helper is dualled as `NDError_Log` (`aa_007a4480`): with first arg `0`, the formatted log path is skipped — so this is a **debug-stop marker** call shape more than a guaranteed printed message.

Used by MissionDef XML root iteration (`FUN_00547920`), NDSpecialFX load, and related script/XML walkers: null return aborts the load loop.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00799900_*`, `reconstructed-exact/FUN_00799900.cpp` |
| Named alias | `Named_VOG_DEBUG_STOP_00799900.cpp` |
| Function record | `functions/aa_00799900_FUN_00799900.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00799900` (2026-07-29) |
| Bytes | `read_memory` 96 B — `mov eax,[ecx+8]`; `call [vtbl+0x1c]`; `test eax / jnz fail`; `ret 4` |
| String | `read_memory` `0x00a15844` = `VOG_DEBUG_STOP` |
| Log dual | `A/B_aa_007a4480_NDError_Log.md` |
| Callers | `FUN_00547920`, `NDSpecialFX_LoadFromScriptName`, `FUN_004a6390`, `FUN_004a6670`, `FUN_005abba0` |
| Parent dual | `A_aa_00547920_MissionDef_EnsureXmlLoaded.md` |

**Not performed:** identify exact COM interface of `*(this+8)`, Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall`; collection at **`this+0x8`** | **Confirmed** | bytes |
| Call **vtbl+0x1c** with (collection, item, &slot) | **Confirmed** | |
| status **== 0** success | **Confirmed** | `test eax / jnz fail` |
| Failure → `FUN_007a4480(0,"VOG_DEBUG_STOP")` + return 0 | **Confirmed** | |
| Success returns item pointer (stack slot) | **High** | bytes return `[esp+4]`; decompiler saved copy is slightly softer |
| `__stdcall` stack cleanup `ret 4` | **Confirmed** | |
| Log with flag 0 may not print | **High** | NDError_Log dual: only `param_1==1` formats |
| Product interface name of collection | **Open** | |
| Whether method rewrites item out-param | **Probable** | `&item` passed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load *(this+8), vcall +0x1c | Yes |
| status==0 → return item | Yes (live returns post-call slot) |
| else log + return 0 | Yes |

### Recovered CF

```c
void* XmlContainer_GetItem_OrDebugStop(Container* this, void* item) {
  void* slot = item;
  int st = this->inner /*+8*/ ->vtbl[0x1c/4](this->inner, item, &slot);
  if (st == 0) return slot; // or item if unrewritten
  NDError_Log(0, "VOG_DEBUG_STOP");
  return nullptr;
}
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `MissionDef_EnsureXmlLoaded` `0x00547920` | per-entry root resolve |
| Caller | `NDSpecialFX_LoadFromScriptName` | FX script nodes |
| Callee | `*(vtbl+0x1c)` on `*(this+8)` | item get/validate |
| Callee | `FUN_007a4480` NDError_Log | debug stop marker |

---

## 6. Gaps / open

1. COM/XML type of `this` and `*(this+8)`.
2. Precise meaning of vtbl+0x1c (GetItem vs QI vs Ensure).
3. Whether success returns rewritten out-object always.
4. Runtime deferred.

**Verdict:** **accept-with-gaps** — CF High; interface names Open. Note: prior `Named_VOG_DEBUG_STOP` is the **failure path string**, not the whole function’s primary job.
