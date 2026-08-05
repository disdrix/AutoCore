# Review A (reconstruction fidelity): `aa_00723b20` CSoundManager_StopMatchingSounds_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00723b20` |
| **VA** | `0x00723b20` |
| **Canonical name** | `CSoundManager_StopMatchingSounds_Inferred` |
| **Ghidra symbol** | `FUN_00723b20` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_00723b20_CSoundManager_StopMatchingSounds_Inferred.md` |
| **System** | client audio / `CSoundManager` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**`__thiscall`** on `CSoundManager`: scan the **active sound slot pointer table** at **`this+0x31c`** (count **`this+0x210`**), and for matches call **`FUN_00723ab0`** — sealed as **`CSoundManager::_stopSound`** by log string.

Signature (decompiler):

```c
undefined4 __thiscall FUN_00723b20(
    int this,
    uint idLo,      // param_2
    uint idHi,      // param_3
    char flagA,     // param_4  compared to slot+0x35
    byte *nameOpt,  // param_5  optional C-string
    char forceFlag  // param_6  wildcard name branch
);
```

Always returns **0** in observed paths (status unused / always false).

### Branch A — wildcard IDs: `(idLo & idHi) == 0xFFFFFFFF`

If `nameOpt != null` and count > 0, for each slot pointer:

- Require slot non-null, **`slot+0x1c5 != 0`** (active?), and (`slot+0x36 != 0` **OR** `forceFlag != 0`).
- **Bytewise strcmp-style** of `slot+0x48` vs `nameOpt` (2-byte steps; returns 0 on equal).
- On name match → **`FUN_00723ab0()`** (`_stopSound` for that index).

### Branch B — concrete ID match

For each slot:

- Require non-null and (`slot+0x1c5 != 0` **OR** `slot+0x3a != 0`), and **`slot+0x40 == idLo`**, **`slot+0x44 == idHi`**, **`slot+0x35 == flagA`**.
- If `nameOpt == null`: if `slot+0x36 != 0` and `slot+0x2c != 0x46` → stop.
- Else name-compare to `slot+0x48`; on match → stop.
- Extra path when **`slot+0x37 != 0`**: may rewrite local name buffer (`local_104`), optionally append short suffix from **`DAT_00aa9268`** when **`this+0x25a == 0`**, then secondary compares before `_stopSound`.

**Enable gate:** entire body skipped if **`this+600 == 0`** (disabled manager).

**Callers:** `FUN_004b6e00`, `FUN_004b85d0`, `FUN_004b8dc0`, `FUN_004ba0a0`, `FUN_00518370`, `FUN_007242c0`, `FUN_007243a0`, `FUN_007252d0`.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw / annotated / clean | `aa_00723b20_*` | ≡ live CF |
| Live decompile | Ghidra `0x00723b20` | **≡ raw** |
| `_stopSound` | `FUN_00723ab0` string + mark `+0x38` | **High** |
| Parent dual | `A_aa_004b8dc0` | stop path |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Enable `this+0x258` | **High** | same family |
| Slot table `+0x31c`, count `+0x210` | **High** | |
| Wildcard when `(idLo&idHi)==~0` | **High** | |
| ID fields `slot+0x40/+0x44`, flag `+0x35` | **High** | |
| Name at `slot+0x48` | **High** | |
| Stop via `FUN_00723ab0` = `_stopSound` | **High** | string seal |
| Return always 0 | **High** | both exits |
| Suffix rewrite / `+0x37` path semantics | **Medium** | complex; residual |
| Product English name | **Probable** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Enable gate | Yes |
| Wildcard name walk → stop | Yes |
| Concrete ID(+name) walk → stop | Yes |
| Optional name suffix path | Yes (present; deep residual) |
| return 0 | Yes |

```text
StopMatching(this, idLo, idHi, flagA, nameOpt, force):
  if !enabled(+0x258): return 0
  if (idLo & idHi) == 0xFFFFFFFF:
    // name-only scan of +0x31c[0..count)
    // active(+0x1c5) && (flag+0x36 || force) && name== → _stopSound
  else:
    // idLo/idHi/flagA match (+ optional name / +0x37 rewrite)
    // → _stopSound
  return 0
```

---

## 5. Callers / callees

**Callees:** `FUN_00723ab0` (`_stopSound`) primarily; local strcmp-style loops; optional `DAT_00aa9268` suffix bytes.

**Callers:** SpecialFX / mission / UI stop sites listed above.

---

## 6. Gaps / open

1. Full dual of `_stopSound` (`00723ab0`) residual (index-in-EAX recovery).
2. Meaning of `slot+0x2c == 0x46` exception.
3. Exact purpose of `+0x37` rename/suffix path and `this+0x25a`.
4. Why return is always 0 (API leftover?).
5. Runtime not run.

**Verdict:** **accept-with-gaps** — enable, dual ID/name branches, and `_stopSound` dispatch sealed; suffix rewrite residual.
