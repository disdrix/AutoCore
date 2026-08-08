# Gap-fill report — `aa_0051b850` CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget

**Date:** 2026-08-05  
**Owned VA:** `0x0051b850` only (OWN-ONLY)  
**Scope:** Create missing raw / annotated / clean cpp / function records from live decompile + pre-existing dual A/B.  
**Duals:** **not rewritten** (already accept-with-gaps; CF High).  
**Parent ledgers:** none touched.  
**Terminal:** false  

---

## Pre-existing (kept)

| Artifact | Path |
|---|---|
| Review A | `docs/reconstruction/reviews/A_aa_0051b850_CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051b850_CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget.md` |

Both duals: **accept-with-gaps** — CF High; product virtual English / slot-7 dispatch catalog open.

---

## Live re-verify (this pass)

| Tool | Result |
|---|---|
| `decompile_function` @ `0x0051b850` | Matches dual body exactly |
| `read_memory` length 32 | `8b411885c0740ac780a000000000000000c3` + `cc` pad |
| `get_function_by_address` | `FUN_0051b850` body `0051b850`–`0051b861` |
| `get_xrefs_to` | DATA only from `0x009cdff0` |
| Vtbl slot 7 | `009cdff0` → `0051b850`; base `009cdfcc` → `0056f570` (empty) |

### Authoritative body

```c
void __fastcall FUN_0051b850(int param_1)
{
  if (*(int *)(param_1 + 0x18) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0xa0) = 0;
  }
  return;
}
```

### Sealed facts

| Fact | Conf |
|---|---|
| `this` in ECX; bare `ret` (no stack args) | **High** |
| Null-check `*(this+0x18)` then store 0 at `owner+0xA0` | **High** |
| Body 18 B through `c3` | **High** |
| Derived vtbl slot 7 only (base slot 7 nop) | **High** |
| `+0xA0` = selected target (SetSelectedTarget dual) | **High** |
| Product virtual English name | **Tentative / Inferred** |

---

## Created this pass

| Role | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051b850_FUN_0051b850.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b850_FUN_0051b850.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget.cpp` |
| Clean FUN twin | `docs/reconstruction/reconstructed-exact/FUN_0051b850.cpp` |
| Function record (named) | `docs/reconstruction/functions/aa_0051b850_CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget.md` |
| Function record (FUN) | `docs/reconstruction/functions/aa_0051b850_FUN_0051b850.md` |
| This report | `docs/agents/task-gap-fill-0051b850-report.md` |

---

## Gaps remaining (unchanged from duals)

1. Product virtual method English (OnEnd / OnDetach / partner-clear — inferred only).
2. Exhaustive catalog of who dispatches slot 7.
3. Runtime / bit-exact verification.

---

## Inventory status

| Layer | Status |
|---|---|
| Dual A/B | Present (pre-existing) |
| Raw + annotated | **Filled** |
| Clean cpp (+ FUN twin) | **Filled** |
| Function records | **Filled** |
| Parent ledgers | **Not touched** (per task) |

**Verdict:** gap closed for scaffold artifacts; dual verdict remains **accept-with-gaps**.
