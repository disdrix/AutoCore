# Review A (reconstruction fidelity): `aa_008a3510` Mission_Client_BuildMissionDetailPanel

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a3510` |
| **VA** | `0x008a3510` |
| **Canonical name** | `Mission_Client_BuildMissionDetailPanel` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008a3510_Mission_Client_BuildMissionDetailPanel.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Build mission detail UI panel (`__thiscall`). Populates status/description/rewards strings (`Status:`, `(in progress)`, `[Complete]`, `Description:`, `Rewards:`), actions `Set Active` / `Set Active For Entire Convoy`. Looks up mission/object data via hash + TFID helpers. Large ~widget/string CF — client journal detail only.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008a3510_Mission_Client_BuildMissionDetailPanel.md` (or `aa_008a3510_FUN_008a3510.md`) |
| Annotated | `docs/reconstruction/raw/aa_008a3510_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_Client_BuildMissionDetailPanel.cpp` |
| Function record | `docs/reconstruction/functions/aa_008a3510_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Status/Description/Rewards labels` | High | Strings |
| `Set Active / convoy set-active` | High | Strings |
| `[Complete] / (in progress) states` | High | Strings |
| `Hash + TFID lookup callees` | High | Callees |
| `Client UI only` | High | No server complete |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Lookup mission → format widgets/strings | Yes |
| No invented grant | Yes |

---

## 5. Gaps / open

1. Widget object offsets.
2. Whether Set Active sends packet here or via child handler.

**Verdict:** **accept-with-gaps**
