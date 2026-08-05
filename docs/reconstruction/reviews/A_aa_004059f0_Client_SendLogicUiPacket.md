# Review A (reconstruction fidelity): `aa_004059f0` Client_SendLogicUiPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_004059f0` |
| **VA** | `0x004059f0` |
| **Canonical name** | `Client_SendLogicUiPacket` |
| **System** | network-ui |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004059f0_Client_SendLogicUiPacket.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_004059f0_Client_SendLogicUiPacket.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_004059f0_Client_SendLogicUiPacket.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendLogicUiPacket.cpp` |


---

## 2. Purpose (from unit)

Push a Logic-UI event into a fixed-size (0x138) ring/vector on the this object; overflow path calls grow helper FUN_004068f0.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Element stride is 0x138 | **High** | Division by 0x138 |
| In-bounds construct at this+8 | **High** |  |
| Overflow uses FUN_004068f0 | **High** |  |
| param_2 is UI event payload | **Medium** |  |
| this is LogicUi queue | **Medium** | +4 begin +8 write +0xc cap |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Read begin this+4; capacity via (end-begin)/0x138 vs (cap-begin)/0x138 | **Yes** (clean ≡ raw scaffold) |
| In-capacity: FUN_00409cc0 then advance this+8 by 0x138 | **Yes** (clean ≡ raw scaffold) |
| Overflow: FUN_004068f0 grow path | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. FUN_00409cc0 / FUN_004068f0 not fully typed
2. param_2 payload layout unknown
3. Callers not mapped in this unit

**Verdict:** **accept-with-gaps**
