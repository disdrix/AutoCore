# Review A (reconstruction fidelity): `aa_00522bc0` CVOGReaction_RecordFirstTimeEvent

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522bc0` |
| **VA** | `0x00522bc0` |
| **Canonical name** | `CVOGReaction_RecordFirstTimeEvent` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00522bc0_CVOGReaction_RecordFirstTimeEvent.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **first-time / tutorial event heartbeat** start on character (not the account tip bitfield alone):

1. Resolve related object via dual-base `+0xa8` chain into `uVar1`.
2. Gates: related `+0x7e != 0` **and** char flag `+0xc7c == 0` (not already recording).
3. If existing action at `+0xca0`: `FUN_0060b410(1)` then clear.
4. Set `+0xc7d = (param_2+0x260 float != 0)`.
5. Alloc `0x2c` action via `FUN_0060b380(param_2, char, *(param_2+0x25c))`; store `+0xca0`.
6. Enqueue on related list `related+0xe4ec` (`CVOGHBList_Enqueue`), `CVOGHBBase_Start`.
7. Snapshot `+0xc98 = char+0x6c0`, `+0xc9c = param_2`, set `+0xc7c = 1`.
8. Return success low-byte `1`; else clear low byte (`uVar1 & 0xffffff00`).

**Related but distinct** from account FirstTimeFlags (`Documentation/FIRST_TIME_FLAGS.md` / `0x20B1`) — this unit starts a **heartbeat action** tied to a reaction/event object (`param_2`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00522bc0_CVOGReaction_RecordFirstTimeEvent.md` |
| Annotated | `docs/reconstruction/raw/aa_00522bc0_CVOGReaction_RecordFirstTimeEvent.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_RecordFirstTimeEvent.cpp` |
| Function record | `docs/reconstruction/functions/aa_00522bc0_CVOGReaction_RecordFirstTimeEvent.md` |
| Account tips | `Documentation/FIRST_TIME_FLAGS.md` (related domain, different path) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(char*, eventObj*) → uint (bool-ish)` | **High** | Raw |
| Dual gate +0x7e / +0xc7c | **High** | Explicit |
| Replace prior action at +0xca0 | **High** | Clear then new |
| HB alloc 0x2c + enqueue + start | **High** | Named helpers |
| Flags +0xc7c/+0xc7d snapshots +0xc98/+0xc9c | **High** | Stores |
| Account FirstFlags dword write here | **Low / no** | Not in body |
| param_2 is reaction def / tip def | **Probable** | Fields +0x25c/+0x260 |
| FUN_0060b380 exact class | **Tentative** | CVOGHBBase-ish |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH frame scaffold | **Yes** |
| Gates | **Yes** |
| Replace / construct / enqueue / start | **Yes** |
| Success vs fail return packing | **Yes** |

---

## 5. Gaps

1. Full meaning of char first-time state block +0xc7c..+0xca0.
2. Link to FirstTimeFlags bit set / 0x20B1 (likely sibling units).
3. Event object layout +0x25c/+0x260.
4. Runtime tip reaction capture.
5. Function record system still `unknown`.

**Verdict:** HB start CF faithful; do not conflate with account tip bitmap alone. **accept-with-gaps.**
