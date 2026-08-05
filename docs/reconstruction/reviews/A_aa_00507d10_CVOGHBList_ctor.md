# Review A (reconstruction fidelity): `aa_00507d10` CVOGHBList_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00507d10` |
| **VA** | `0x00507d10` |
| **Canonical name** | `CVOGHBList_ctor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00507d10_CVOGHBList_ctor.md` |
| **System** | `heartbeat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct map-owned heartbeat list: install vtbl `PTR_FUN_009cda94`; init active buffer (`param_1[7..9]`) capacity flag `0x80000000` then grow to min **1000** slots via `FUN_005b3300`; pending (`param_1[10..0xc]`) grow to min **100**; bump global list-count `_DAT_00b041c0`; seed `g_dwClientTickMs=GetTickCount()`; `InitializeCriticalSectionAndSpinCount(this+1, 4000)`; optional one-shot global `DAT_00b041c8` helper object (`FUN_00507ee0(4)`) when flag `DAT_00b041c4` set. Seeds Enqueue/Tick.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00507d10_CVOGHBList_ctor.md` |
| Annotated | `docs/reconstruction/raw/aa_00507d10_CVOGHBList_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBList_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_00507d10_CVOGHBList_ctor.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vtbl PTR_FUN_009cda94` | **High** | Store |
| `Active capacity sentinel 0x80000000 then ensure ≥1000` | **High** | Grow path |
| `Pending ensure ≥100` | **High** | Grow path |
| `FUN_005b3300 buffer alloc helper` | **High** | Calls |
| `CS at param_1+1 spin 4000` | **High** | InitializeCriticalSectionAndSpinCount |
| `g_dwClientTickMs = GetTickCount()` | **High** | Global seed |
| `_DAT_00b041c0++ instance counter` | **High** | Body |
| `Optional DAT_00b041c8 singleton` | **High** | Gated new |
| `Layout: +0x04 CS; +0x1c active; +0x28 pending (plate)` | **Probable** | Index map |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Vtbl + buffers + CS + tick seed | **Yes** |
| Optional global helper branch | **Yes** |
| No invented Tick logic | **Yes** |

---

## 5. Gaps / open

1. Exact byte offsets for active/pending vs decomp index.
2. FUN_00507ee0 / DAT_00b041c8 purpose.
3. Whether multiple HBList instances share g_dwClientTickMs safely.

**Verdict:** **accept-with-gaps**
