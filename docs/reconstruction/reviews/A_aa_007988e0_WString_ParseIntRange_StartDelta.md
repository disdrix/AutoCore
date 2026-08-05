# Review A (reconstruction fidelity): `aa_007988e0` WString_ParseIntRange_StartDelta

| Field | Value |
|---|---|
| **Stable ID** | `aa_007988e0` |
| **VA** | `0x007988e0` |
| **Canonical name** | `WString_ParseIntRange_StartDelta` (structural) |
| **Ghidra name** | `FUN_007988e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_007988e0_WString_ParseIntRange_StartDelta.md` |
| **System** | missions-progression / XML attribute helpers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Parse a wide string of form **`"%d;%d"`** (start;end) and emit:

1. **start** → `*outStart`
2. **delta** `(end - start)` → `*outEndOrDelta` (in-place rewrite after `swscanf`)
3. optional **success byte** → `*outOk` (`0` initially, `1` only when both ints convert)

`param_1` is a **pointer to a `wchar_t*`** (or compatible short*): body does `swscanf((wchar_t*)*param_1, L"%d;%d", …)`.

```c
// void WString_ParseIntRange_StartDelta(wchar_t **ppWcs, int *outStart, int *outDelta, uint8_t *outOkOpt)
void FUN_007988e0(undefined4 *param_1, int *param_2, int *param_3, undefined1 *param_4)
{
  if (param_4) *param_4 = 0;
  i = swscanf((wchar_t *)*param_1, L"%d;%d", param_2, param_3);
  if (i == 2) {
    *param_3 = *param_3 - *param_2;   // end → delta
    if (param_4) *param_4 = 1;
  }
}
```

**Not** a full mission loader — pure format helper used from map/text range paths and mission CoreMission residual.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_007988e0_*`, `reconstructed-exact/FUN_007988e0.cpp` |
| Named alias plate | `reconstructed-exact/Named_CalleeOf_Mission_Mission_lacking_child_nodes_s_007988e0.cpp` |
| Function record | `functions/aa_007988e0_FUN_007988e0.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x007988e0` (2026-07-29) |
| Bytes | `read_memory` 96 B @ `0x007988e0` — `cmp eax,2`; `sub [esi],[ebx]`; optional `mov byte [edi],1` |
| Format string | `read_memory` `0x00a983a4` → UTF-16 `"%d;%d"` |
| Callers (Ghidra `get_xrefs_to`) | `FUN_00547920` (MissionDef_EnsureXmlLoaded), `FUN_00798e50` ×2 |
| Parent dual | `A_aa_00547920_MissionDef_EnsureXmlLoaded.md` |

**Not performed:** Launcher, runtime parse golden, caller formal retype of every site.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Format `L"%d;%d"` via `swscanf` | **Confirmed** | string + IAT call |
| Optional out-ok cleared to 0 first | **Confirmed** | body |
| Success requires exactly **2** conversions | **Confirmed** | `cmp eax,2` |
| On success: `*param_3 -= *param_2` (end→delta) | **Confirmed** | bytes `29 16` |
| On success + non-null ok: `*ok = 1` | **Confirmed** | |
| Failure leaves start/end writes undefined (scanf partial) + ok stays 0 | **High** | no restore |
| `param_1` is `wchar_t**` / pointer-to-buffer-ptr | **High** | `mov ecx,[eax]` then push |
| void return | **Confirmed** | |
| Product name / field mapping | **Open** | range vs min/max span |
| Some decompiler caller sites show null `param_3` | **Open noise** | stack recovery; body requires valid ints on success |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Optional ok=0 | Yes |
| swscanf `%d;%d` | Yes |
| i==2 → delta rewrite + ok=1 | Yes |
| Single void return | Yes |

### Recovered CF

```c
void WString_ParseIntRange_StartDelta(wchar_t **pp, int *start, int *endIn_deltaOut, uint8_t *okOpt) {
  if (okOpt) *okOpt = 0;
  if (swscanf(*pp, L"%d;%d", start, endIn_deltaOut) == 2) {
    *endIn_deltaOut -= *start;
    if (okOpt) *okOpt = 1;
  }
}
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_00547920` MissionDef_EnsureXmlLoaded | CoreMission text residual |
| Caller | `FUN_00798e50` | map/attr range helper (non-`p`/`P` arm + `;` arm) |
| Callee | `swscanf` (msvcrt IAT) | parse |

---

## 6. Gaps / open

1. Exact product semantics of delta (length vs inclusive span) — arithmetic sealed; English open.
2. Seal every caller’s third/fourth formals (Ghidra stack noise at some MissionDef sites).
3. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — parse/delta CF Confirmed; product field names Open.
