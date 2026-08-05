# Review A (reconstruction fidelity): `aa_007f9110` Client_ActionMap_Init

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f9110` |
| **VA** | `0x007f9110` |
| **Canonical name** | `Client_ActionMap_Init` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007f9110_Client_ActionMap_Init.md` |
| **System tag** | `input-drive-control` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_ActionMap_Init.cpp` |
| Raw | `docs/reconstruction/raw/aa_007f9110_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** ActionMap ctor/init (register ESI/EAX). Install vtable PTR_LAB_00a84e08; zero-fill table regions +0x06 (0x41 dwords), +0x10a (0x4e dwords), +0x242 (0x618 dwords), +0x1aa2 (0x104 dwords); call InitActionDisplayNames then InitDefaultKeybinds; clear status byte +0x5. Slot stride context 0x34 for later bind tables.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Vtbl PTR_LAB_00a84e08 | High | Store |
| Zero four table regions listed | High | Loops |
| Calls InitActionDisplayNames | High | Call |
| Calls InitDefaultKeybinds | High | Call |
| Clear byte +0x5 | High | Store |
| No DIK numbers written here directly | High | Delegates |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Vtbl → zeros → display names → keybinds → +0x5 | Yes |

---

## 4. Gaps

1. Total ActionMap object size.
2. Exact meaning of +0x5 flag.

**Verdict:** **accept**
