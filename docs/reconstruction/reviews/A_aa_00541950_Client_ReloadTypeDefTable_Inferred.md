# Review A (reconstruction fidelity): `aa_00541950` Client_ReloadTypeDefTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00541950` |
| **VA** | `0x00541950` |
| **Canonical name** | `Client_ReloadTypeDefTable_Inferred` |
| **Ghidra name** | `FUN_00541950` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00541950_Client_ReloadTypeDefTable_Inferred.md` |
| **System** | client type-def / SpecialFX suppress hash host |
| **Live tools** | `batch_decompile` 0x00541950; ensure sibling `00541a80` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Reload / rebuild type-def record buffer** on host object (`__fastcall` ECX = host):

1. If `host+0xF20` non-null → `operator_delete__` old buffer; store **0**.
2. Vcall `**(host+0xF1C)+4` — clear/reset table object at `+0xF1C` (CNDHash-like).
3. Init temp buffer triple; `hr = FUN_007dbce0(&tempBegin)` loads records.
4. On `hr < 0`: log `"VOG_DEBUG_STOP"` (no throw).
5. Else:
   - `count = (tempEnd - tempBegin) / 0x154` (record stride **0x154**).
   - `host+0xF20 = operator_new__(count * 0x154)`; dword-copy from temp.
   - For each record `i`: `FUN_00545a90(*(buf+i*0x154), buf+i*0x154, 0)` — per-record setup.
6. Free temp buffer if non-null (`operator_delete` noreturn-path style SEH).

**Sole known ensure caller:** `FUN_00541a80` / `Client_EnsureTypeDefHashReady_Inferred` when hash count `@(+0xF1C)+0xC < 1`. Also `FUN_00541e70`. Downstream SpecialFX play (`004b7e50`) uses ensure → `CNDHash_LookupByKey` for suppress gating.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / annotated / clean | `raw/aa_00541950_*`, `reconstructed-exact/FUN_00541950.cpp` |
| Function record | `functions/aa_00541950_FUN_00541950.md` |
| Ensure sibling dual | `A_aa_00541a80_Client_EnsureTypeDefHashReady_Inferred` |
| Callees | `FUN_007dbce0` (load), `FUN_00545a90` (per-record), log `007a4480` |
| Live | stride 0x154; buffer at +0xF20; table at +0xF1C |

**Three-rep:** present.

---

## 3. Recovered CF

```c
// __fastcall
void Client_ReloadTypeDefTable(Host *host)
{
  if (host->buf_F20) operator_delete__(host->buf_F20);
  host->buf_F20 = 0;
  vcall_clear(host->table_F1C);           // vtbl+4
  hr = LoadRecords(&temp);                // FUN_007dbce0
  if (hr < 0) { log("VOG_DEBUG_STOP"); }
  else {
    n = (temp.end - temp.begin) / 0x154;
    host->buf_F20 = new char[n * 0x154];
    memcpy(host->buf_F20, temp.begin, n * 0x154);
    for (i = 0; i < n; i++)
      SetupRec(*(Rec*)(buf + i*0x154), buf + i*0x154, 0); // FUN_00545a90
  }
  free temp if allocated;
}
```

---

## 4. Confidence

| Claim | Level |
|---|---|
| Free old `+0xF20` then null | **Confirmed** |
| Vcall clear on `+0xF1C` | **Confirmed** |
| Load via `007dbce0` | **Confirmed** |
| Stride **0x154** | **Confirmed** |
| Per-record `00545a90` | **Confirmed** |
| Error path logs `VOG_DEBUG_STOP` | **Confirmed** |
| Role = type-def table reload | **High** (ensure sibling) |
| Product host type name | **Probable** |
| Exact payload of 0x154 records | **Open** |

---

## 5. Gaps

1. Dual of `FUN_007dbce0` data source / file format.
2. Dual of `FUN_00545a90` record wire-up.
3. Whether failed load leaves hash empty (yes — still cleared).
4. Runtime open.

**Verdict:** **accept-with-gaps**
