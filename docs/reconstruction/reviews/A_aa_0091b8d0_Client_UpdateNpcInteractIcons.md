# Review A (reconstruction fidelity): `aa_0091b8d0` Client_UpdateNpcInteractIcons

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091b8d0` |
| **VA** | `0x0091b8d0` |
| **Canonical name** | `Client_UpdateNpcInteractIcons` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0091b8d0_Client_UpdateNpcInteractIcons.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_UpdateNpcInteractIcons.cpp` |
| Raw | `docs/reconstruction/raw/aa_0091b8d0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Periodic pass over in-scope interactive objects. Updates cached interact state at entry+0x10 and attaches NDSpecialFX when object+0x4c==0. States 0 clear … 8 active_mission_target_complete; 6 vs 7 via CoreMission flag mission def+0x169. Scripts: generic_interact, generic_interact_npc, interact_npc_available_old_mission, interact_npc_active_mission, etc. After mission complete, next core offers flip to 7 — same MSXML crash site risk as dialog build.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| State enum 0..8 at entry+0x10 | High | Plate |
| FX only if object+0x4c==0 | High | Plate |
| State 6 vs 7 CoreMission def+0x169 | High | Plate |
| NDSpecialFX_LoadFromScriptName + SetInteractSpecialFX | High | Callees |
| Script names generic_interact* / mission interact* | High | Strings |
| CNDHash_LookupByKey for mission defs | High | Callees |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| scan interactables → compute state → set FX if none | Yes |

---

## 4. Gaps

1. Full priority matrix vs CVOGObject_Eval*InteractState duals.
2. Call frequency / dirty conditions.

**Verdict:** **accept-with-gaps**
