# Review A (reconstruction fidelity): `aa_00810280` Client_RecvInventoryUseItemResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810280` |
| **VA** | `0x00810280` |
| **Canonical name** | `Client_RecvInventoryUseItemResponse` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00810280_Client_RecvInventoryUseItemResponse.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C use-item response: require local char `+0xe98` and `+0x250`. If remaining count `@+0x10 < 1`: consume/remove via `FUN_00571d80(TFID)` then fail UI `FUN_007fee30` + `FUN_00933310`. Else: find item `FUN_00571010`, set qty vtbl `+0x260`, write short `@item+0x180` from packet `@+0x14`. Always refresh mission windows; optional craft/use UI hosts at `+0x309c` / `+0x10b0`. Packet base in ESI.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / clean | `raw/aa_00810280_…`, `reconstructed-exact/Client_RecvInventoryUseItemResponse.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Char/vehicle gates | **High** | |
| Consume path when count < 1 | **High** CF |
| Qty update path when count ≥ 1 | **High** CF |
| Mission UI refresh always | **High** | |
| Metadata short `@+0x14` → item `+0x180` | **High** CF |
| Clean vcall stubs complete | **Tentative** | Some vcalls commented stubs |
| Packet ESI framing | **Probable** | |

---

## 4. Control flow: clean ≡ raw

Branch structure matches; some success-path vcalls left as comments (width recovery incomplete) — fidelity note, not invented logic.

---

## 5. Gaps / open

Opcode; full UI host contracts; restore commented vcalls from raw; runtime use-item.

**Verdict:** **accept-with-gaps.**
