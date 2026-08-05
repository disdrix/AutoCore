# Review A (reconstruction fidelity): `aa_0071ffc0` CSoundManager_EraseNamedRecordByName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071ffc0` |
| **VA** | `0x0071ffc0` |
| **Canonical name** | `CSoundManager_EraseNamedRecordByName_Inferred` |
| **Ghidra symbol** | `FUN_0071ffc0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-L) |
| **Counterpart** | `reviews/B_aa_0071ffc0_CSoundManager_EraseNamedRecordByName_Inferred.md` |
| **System** | client audio / `CSoundManager` |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Erase one named 200-byte record** from either of two dense manager tables, under **`manager+0x170`** critical section:

1. `EnterCriticalSection(manager+0x170)`.
2. Scan range **A** `[*(+0x44), *(+0x48))` with stride **200**; `_stricmp(record, name)==0` → `FUN_00480970(record+200, end, record)` (shift tail), `end(+0x48) -= 200`, Leave, **return**.
3. Else scan range **B** `[*(+0x54), *(+0x58))` same stride; match → erase + `end(+0x58)-=200`.
4. Leave CS (no-match or after B erase).

**Not** channel-slot stop marking (`FUN_007203b0` sets `slot+0x38` / clears `+0x1b0` under CS **`+0x158`**). This unit mutates **queue/record pointer ranges** at `+0x44` / `+0x54`.

```text
// name on stack; ret 4; manager in ESI
EraseNamedRecordByName(mgr/*ESI*/, name):
  lock(mgr+0x170)
  for rec in [mgr.beginA, mgr.endA) step 200:
    if stricmp(rec, name)==0:
      erase rec; endA -= 200; unlock; return
  for rec in [mgr.beginB, mgr.endB) step 200:
    if stricmp(rec, name)==0:
      erase rec; endB -= 200; unlock; return
  unlock
```

**Callers:**

- `FUN_007203b0` (`CSoundManager_MarkStopByName`) when `doExtra != 0` — “extra” teardown by name.
- `FUN_00721a80` after streaming-music create fail — drop pending record by path name.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw / annotated / clean | `aa_0071ffc0_*` | ≡ live |
| Function record | `functions/aa_0071ffc0_FUN_0071ffc0.md` | dual sealed |
| Fresh decompile | Ghidra `decompile_function` @ `0x0071ffc0` | sealed |
| Bytes | `read_memory` — `lea ebx,[esi+0x170]`; stride `add edi,0xC8`; `ret 4` | |
| Erase helper | `FUN_00480970` — 0x32 dword (=200 B) block move | decompile |
| Parent dual | `A_aa_007203b0_CSoundManager_MarkStopByName_Inferred` | optional call |

**Not performed:** full 200-byte record field map, Launcher, runtime.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Stack name; **ret 4** | **Confirmed** | bytes |
| Manager in **ESI** | **Confirmed** | `lea ebx,[esi+0x170]` no ESI setup |
| CS at **`+0x170`** | **Confirmed** | Enter/Leave |
| Ranges `+0x44/+0x48`, `+0x54/+0x58` | **Confirmed** | |
| Stride **200** (`0xC8`) | **Confirmed** | |
| Name at record start; `_stricmp` | **Confirmed** | |
| Erase via `FUN_00480970` + end-=200 | **Confirmed** | |
| First match only; A before B | **Confirmed** | early return on A hit |
| Same as MarkStopByName channel walk | **Falsified** | different CS + tables |
| Product English name of tables | **Open** | inferred queue/record |
| Full record schema | **Open** | name@+0 only sealed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Enter CS +0x170 | Yes |
| Range A scan / erase / early leave | Yes |
| Range B scan / erase | Yes |
| Unlock all paths | Yes |

```c
// faithful skeleton
void FUN_0071ffc0(char *name) // ESI = manager
{
  EnterCriticalSection((LPCRITICAL_SECTION)(esi + 0x170));
  // range A then B; _stricmp; FUN_00480970; end -= 200
  LeaveCriticalSection(...);
}
```

---

## 5. Callers / callees

**Callees:** `EnterCriticalSection`, `LeaveCriticalSection`, `_stricmp`, `FUN_00480970`.

**Callers (2 xrefs):**

| Caller | Site | Role |
|---|---|---|
| `FUN_007203b0` | `0x007203de` | MarkStopByName extra path |
| `FUN_00721a80` | `0x00721cf3` | music create-fail cleanup |

---

## 6. Gaps / open

1. Semantic labels for range A vs B (music pending vs other?).
2. 200-byte record field layout beyond name@0.
3. Whether capacity/base pointers live at adjacent offsets (vector triple residual).
4. Runtime not run.

**Verdict:** **accept-with-gaps** — erase CF, CS, and stride sealed; table product names residual.
