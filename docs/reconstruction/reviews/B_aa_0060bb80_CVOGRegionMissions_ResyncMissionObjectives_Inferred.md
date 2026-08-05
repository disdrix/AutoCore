# Review B (skeptical / adversarial): `aa_0060bb80` CVOGRegionMissions_ResyncMissionObjectives_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060bb80` |
| **VA** | `0x0060bb80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0060bb80_CVOGRegionMissions_ResyncMissionObjectives_Inferred.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** (W24-L) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is just `"VOG_DEBUG_STOP"` logger | **Falsified** — full lookup/compare/hash mutate body; string is lock-error path only |
| 2 | Same as ctor `0060b870` (full table rebuild) | **Falsified** — single-id lookup + selective resync; ctor allocates four hashes |
| 3 | `ret` void / no stack arg | **Falsified** — epilogue `ret 4`; AL status; entry loads stack missionId |
| 4 | Always removes objectives | **Falsified** — remove/reinsert gated on mismatch flag `0x100` |
| 5 | Touches staging map `char+0x508` | **Falsified** — CNDHash mission/objective tables on region wrapper |
| 6 | Callers proven via xrefs | **Fail / Open** — Ghidra reports zero CODE xrefs |
| 7 | Bit-exact / runtime proven | **Fail** — static only |
| 8 | Product name sealed High | **Fail** — Inferred only |

---

## 2. Decisive evidence

- Entry bytes: `mov ecx,[ecx]` then `CNDHash_LookupByKey` — this is a **wrapper whose first field is a hash**, matching `CVOGRegionMissions`.
- Immediately follows sealed ctor body end `0x0060bb77` → same TU family.
- Outbound call to `CNDHash_Insert` @ `0060bd87` confirmed by dual `aa_0053c460`.
- Freelist vtbl `009cf02c` first method `0x00537d10` (`read_memory`).

---

## 3. Port risk

| Risk | If wrong |
|---|---|
| Skip mismatch gate | Spurious objective thrash every call |
| Use mission hash for objective remove | Corrupt wrong table |
| Assume static-call-only | Miss dynamic triggers if any |
| Treat as full ctor | Double-free / wrong lifetime |

**Verdict:** Accept as **single-mission objective resync** on `CVOGRegionMissions`. Do not rename after `VOG_DEBUG_STOP`. Callers remain Open.
