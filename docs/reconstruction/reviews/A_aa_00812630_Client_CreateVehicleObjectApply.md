# Review A (reconstruction fidelity): `aa_00812630` Client_CreateVehicleObjectApply

| Field | Value |
|---|---|
| **Stable ID** | `aa_00812630` |
| **VA** | `0x00812630` |
| **Canonical name** | `Client_CreateVehicleObjectApply` |
| **System** | network-sector |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00812630_Client_CreateVehicleObjectApply.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00812630_Client_CreateVehicleObjectApply.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00812630_Client_CreateVehicleObjectApply.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_CreateVehicleObjectApply.cpp` |


---

## 2. Purpose (from unit)

Apply create-vehicle object from S2C: resolve template by CBID; vtable init; optional possession path.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CBID at packet+4 | **High** |  |
| GiveItemByCbid creates entity shell | **High** |  |
| Possession flag packet+0xa1 | **High** |  |
| Client context param_2 +0xe04 parent/world | **Medium** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| FUN_004bb010(pkt+0x90) early alternate | **Yes** (clean ≡ raw scaffold) |
| CVOGReaction_GiveItemByCbid(*(pkt+4)) | **Yes** (clean ≡ raw scaffold) |
| vt+0x1d4 checks; vt+8 construct; flag at pkt+0xa1 possession | **Yes** (clean ≡ raw scaffold) |
| clear ids +0xd8/+0xdc when possessed | **Yes** (clean ≡ raw scaffold) |
| nested vt+0xc4 apply; optional FUN_009972a0 / FUN_008024d0 | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Full create-vehicle packet layout
2. vt slot semantic names
3. Non-vehicle create siblings not reviewed

**Verdict:** **accept-with-gaps**
