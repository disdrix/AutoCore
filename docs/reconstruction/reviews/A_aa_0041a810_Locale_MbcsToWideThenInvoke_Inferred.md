# Review A (reconstruction fidelity): `aa_0041a810` Locale_MbcsToWideThenInvoke_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041a810` |
| **VA** | `0x0041a810` |
| **Canonical name** | `Locale_MbcsToWideThenInvoke_Inferred` (structural) |
| **Ghidra name** | `FUN_0041a810` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0041a810_Locale_MbcsToWideThenInvoke_Inferred.md` |
| **System** | locale / DB / mission string path |
| **Live tools** | `batch_decompile` 0x0041a810; callers DB_ReadPowerPlantSpecific + many `007b*`/`007c*` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**ANSI → UTF-16 conversion bridge** then gated invoke of two helpers:

1. `codePage = (*(PTR_FUN_00af8c9c))()` — current/ANSI code page provider.
2. **If EBX (LPCSTR) is null:**
   - `rc = FUN_00422d10()` (no wide buffer).
   - If `rc >= 0`: `FUN_0041de50(param_3, param_4)` and return.
3. **Else (non-null MBCS string):**
   - `len = lstrlenA(EBX)`; stack-alloc wide buffer `(len+1)*2` aligned (`__chkstk` / alloca).
   - `MultiByteToWideChar(codePage, 0, EBX, -1, wideBuf, len+1)`.
   - Wide ptr = buffer if convert succeeded, else **0**.
   - `rc = FUN_00422d10(…, widePtr, param_5)`.
   - If `rc >= 0`: `FUN_0041de50(param_3, param_4, param_6, param_7)`.

Decompiler stack tracking is noisy (`__chkstk` / spacebase), but **API sequence is High**: code page → optional MB2WC → success-gated `00422d10` → `0041de50`.

Named parent hint: callee-of `Mission_bActiveObjectiveOverride` path; also heavy **DB read** call sites (`DB_ReadPowerPlantSpecific`, many `007c*` loaders) — shared “format / bind wide string then continue” helper.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / annotated / clean | `raw/aa_0041a810_*`, `reconstructed-exact/FUN_0041a810.cpp` |
| Function record | `functions/aa_0041a810_FUN_0041a810.md` |
| Win32 | `lstrlenA`, `MultiByteToWideChar` |
| Callees | `FUN_00422d10`, `FUN_0041de50`, codepage getter `00af8c9c` |
| Live | EBX = LPCSTR; throw-free; dual success gates `rc >= 0` |

**Three-rep:** present (scaffold; stack locals noisy).

---

## 3. Recovered CF (role-level)

```text
MbcsToWideThenInvoke(str=EBX, args...):
  cp = GetCodePage()
  if str == null:
    if FUN_00422d10() >= 0: FUN_0041de50(p3,p4); return
  else:
    wbuf = alloca((strlen(str)+1)*2 aligned)
    ok = MultiByteToWideChar(cp, 0, str, -1, wbuf, len+1)
    wide = ok ? wbuf : null
    if FUN_00422d10(..., wide, p5) >= 0:
      FUN_0041de50(p3,p4,p6,p7)
```

---

## 4. Confidence

| Claim | Level |
|---|---|
| Null vs non-null string branch | **Confirmed** |
| MultiByteToWideChar on non-null | **Confirmed** |
| Code page from `PTR_FUN_00af8c9c` | **High** |
| Success gate `rc >= 0` before `0041de50` | **Confirmed** |
| Stack alloca for wide buffer | **High** |
| Exact formal map of param_1..7 | **Tentative** (decompiler/stack noise) |
| Product name / mission vs pure DB role | **Probable** dual-use helper |

---

## 5. Gaps

1. Precise signatures of `FUN_00422d10` / `FUN_0041de50`.
2. Full param packing (spacebase warning).
3. Whether failed MB2WC still calls `00422d10` with null wide (yes per CF).
4. Runtime open.

**Verdict:** **accept-with-gaps**
