# Review A (reconstruction fidelity): `aa_007203b0` CSoundManager_MarkStopByName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007203b0` |
| **VA** | `0x007203b0` |
| **Canonical name** | `CSoundManager_MarkStopByName_Inferred` |
| **Ghidra symbol** | `FUN_007203b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_007203b0_CSoundManager_MarkStopByName_Inferred.md` |
| **System** | client audio / `CSoundManager` |
| **Verdict** | **accept** |

---

## 1. Purpose

**`__thiscall`** on the sound manager: under critical section, **find active channel slots whose name (`slot+0x48`) case-insensitively matches `param_2`**, and mark them **stopped** (`slot+0x38 = 1`, `slot+0x1b0 = 0`). Optionally run a pre-pass **`FUN_0071ffc0(name)`** when `param_3 != 0`.

Authoritative behavior:

1. If **`*(char*)(this+0x10) == 0`** → return (manager/subsys not ready).
2. **`EnterCriticalSection(this+0x158)`**.
3. If **`param_3 != 0`**: **`FUN_0071ffc0(param_2)`** (extra stop/teardown by name — residual unit).
4. Walk **2 iterations** starting at **`this+0x80`**, each iteration examining **two pointers**:
   - `piVar3[2]` and `*piVar3` (paired channel slots).
   - For each non-null slot: if **`_stricmp(slot+0x48, name) == 0`**: set **`slot+0x38 = 1`**, **`slot+0x1b0 = 0`**.
   - Advance `piVar3++` (next pair base).
5. **`LeaveCriticalSection(this+0x158)`**.

Stop-flag `+0x38` matches `CSoundManager::_stopSound` (`FUN_00723ab0`) which sets the same field when stopping a slot.

**Callers:** `FUN_004b7150`, `FUN_004b8dc0` (SpecialFX deactivate / clear path walks payloads then calls `GetInstance` + this helper).

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw / annotated / clean | `aa_007203b0_*` | ≡ live |
| Live decompile | Ghidra `0x007203b0` | **≡ raw** |
| Sibling stop | `FUN_00723ab0` `_stopSound` string + `+0x38` | sealed family |
| Parent dual | `A_aa_004b8dc0` | uses this after `00720d40` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall`; name C-string; bool doExtra | **High** | signature |
| Ready flag `this+0x10` | **High** | outer gate |
| CS at `this+0x158` | **High** | Enter/Leave pair |
| Name at `slot+0x48`; `_stricmp` | **High** | body |
| Stop mark `+0x38=1`, clear `+0x1b0` | **High** | matches `_stopSound` family |
| Walk 2 × dual slots from `+0x80` | **High** | `iVar2=2; piVar3[2]/*piVar3` |
| `param_3` gates `FUN_0071ffc0` | **High** | |
| Exact product name | **Probable** | |
| Full meaning of 4 slots at `+0x80` | **Medium** | channel banks |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Ready gate `+0x10` | Yes |
| Enter CS | Yes |
| Optional `FUN_0071ffc0` | Yes |
| Dual-slot name match mark stop | Yes |
| Leave CS | Yes |

```text
MarkStopByName(this, name, doExtra):
  if !this.ready(+0x10): return
  lock(this+0x158)
  if doExtra: FUN_0071ffc0(name)
  for bank in 2 pairs at this+0x80:
    for slot in {pair.hi, pair.lo}:
      if slot and stricmp(slot.name@+0x48, name)==0:
        slot.stopped(+0x38)=1; slot.field(+0x1b0)=0
  unlock
```

---

## 5. Callers / callees

**Callees:** `EnterCriticalSection`, `LeaveCriticalSection`, `_stricmp`, `FUN_0071ffc0`.

**Callers:** `FUN_004b7150`, `FUN_004b8dc0`.

---

## 6. Gaps / open

1. Dual for `FUN_0071ffc0`.
2. Layout of the four slots at `+0x80..` (primary/secondary banks?).
3. Whether `+0x1b0` is fade time vs play cursor (zeroed on stop).
4. Runtime not run.

**Verdict:** **accept** — CS-protected name stop mark sealed.
