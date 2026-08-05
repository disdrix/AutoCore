# Review B (skeptical / adversarial): `aa_004d1d00` ContinentUnlock_RefreshWorldMarkers

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d1d00` |
| **VA** | `0x004d1d00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d1d00_ContinentUnlock_RefreshWorldMarkers.md` |
| **System** | `missions-progression` / exploration |
| **Dual status** | **Written this pass** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This **is** UnlockContinent hash insert | **Falsified** — hash insert is `UnlockContinentObject`; this is post-insert visual refresh |
| 2 | Grants mission / calls GiveMission | **Falsified** — no GiveMission call; only `GiveItemByCbid` for marker props |
| 3 | Always runs on every UnlockContinent | **Falsified** — requires primary entity equality on `+0xe8a0` |
| 4 | Static CBIDs are meaningful constants | **Undermined** — image `DAT_00af1b60/64` = `0xFFFFFFFF`; treat as runtime globals |
| 5 | Distance gate uses world units meters sealed | **Open** — float ~0.01 sealed; unit English not sealed |
| 6 | `+0x38 == 0xFF` means permanent lock forever | **Overclaim risk** — used as skip/veto sentinel in this body only |
| 7 | Nested only from mission complete | **Partial** — also Relock + `FUN_004d9f00` + RecvUnlockRegion via UnlockContinent |
| 8 | Runtime / bit-exact | **Fail** |

---

## 2. Competing interpretations

| Interpretation | Status |
|---|---|
| Continent unlock/relock marker prop refresh | **Wins** |
| Generic inventory give-item spawner | Loses — table walk + TFID cache + unlock parents |
| Fog-of-war packet handler | Loses — no bitstream; pure world mutation |

---

## 3. Port risks

| Risk | Impact |
|---|---|
| Server reimplementing client markers | Unnecessary / wrong layer |
| Ignoring primary-entity gate | Spawns for non-local characters |
| Hardcoding CBIDs as −1 | No markers / spam log |
| Skipping proximity veto | Overlapping marker objects |

---

## 4. Independence

Attacked plate alias `Named_AllocateNewObjectFromCbidFailed_*` (string-only name) — that string is failure path only, not purpose. Purpose from Unlock/Relock call graph + body.

**Verdict:** Accept visual-refresh role. Reject treating this as the continent unlock authority or as a mission grant path. Gaps on CBID globals remain.
