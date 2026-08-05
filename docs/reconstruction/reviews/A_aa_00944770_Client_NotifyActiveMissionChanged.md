# Review A (reconstruction fidelity): `aa_00944770` Client_NotifyActiveMissionChanged

| Field | Value |
|---|---|
| **Stable ID** | `aa_00944770` |
| **VA** | `0x00944770` |
| **Canonical name** | `Client_NotifyActiveMissionChanged` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00944770_Client_NotifyActiveMissionChanged.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_NotifyActiveMissionChanged.cpp` |
| Raw | `docs/reconstruction/raw/aa_00944770_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Chat/toast when convoy leader changes active mission. Strings: 'has changed your active mission to', 'Your Convoy Leader', debug KQDI/DQDI formats. Walks related object list via FUN_0040b020; filters type field ==3 with non-null +0x14-ish; builds message and emits chat. Client presentation; does not itself change active mission hash.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| String evidence convoy leader active mission | High | Literals |
| FUN_0040b020 list/context walk | High | Call |
| Filter *(+0x2a)+0x38 == 3 && field non-null | High | Body |
| Debug KQDI/DQDI format strings | Medium | Strings |
| Chat emit path (not state mutate) | Medium | Purpose plate |
| in_EAX / register params decomp soft | Medium | ABI |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Get context → filter entities → format → notify | Yes |

---

## 4. Gaps

1. Exact chat channel / toast API callee.
2. Whether local player also gets non-convoy path.
3. Packet that triggers this notify.

**Verdict:** **accept-with-gaps**
