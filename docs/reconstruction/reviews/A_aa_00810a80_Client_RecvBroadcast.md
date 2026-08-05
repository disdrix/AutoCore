# Review A (reconstruction fidelity): `aa_00810a80` Client_RecvBroadcast

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810a80` |
| **VA** | `0x00810a80` |
| **Canonical name** | `Client_RecvBroadcast` |
| **System** | network-sector |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00810a80_Client_RecvBroadcast.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00810a80_Client_RecvBroadcast.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_00810a80_Client_RecvBroadcast.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvBroadcast.cpp` |


---

## 2. Purpose (from unit)

S2C broadcast/chat-like handler: large stack buffer; type switch on packet+4; UI/log side effects.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Type discriminator at packet+4 | **High** |  |
| Large ~1K stack workspace | **High** |  |
| Optional global chat sink DAT_00d1d8c8 | **Medium** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| gate on param_2+0x109c | **Yes** (clean ≡ raw scaffold) |
| optional FUN_0079d560 chat hook | **Yes** (clean ≡ raw scaffold) |
| type = *(int*)(pkt+4); case branches | **Yes** (clean ≡ raw scaffold) |
| format/display paths with large local buffers | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Full type enum table
2. Message string offsets in packet
3. Many FUN_* UI callees

**Verdict:** **accept-with-gaps**
