# Review A (reconstruction fidelity): `aa_005d6c60` Client_LocalDiscoveryTick

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6c60` |
| **VA** | `0x005d6c60` |
| **Canonical name** | `Client_LocalDiscoveryTick` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d6c60_Client_LocalDiscoveryTick.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Heartbeat / HB-style **client discovery tick** (~5s reschedule):

1. If `FUN_005cc630() != 0`: delegate `CVOGHBAICreatureBase_OnHeartBeat` and return (alt mode).
2. Else, when object chain flag `+0x7e != 0` and vehicle/entity present and UI flag `+0x4f1 == 0`:
   - Sample player XZ via vtbl `+0x1a0`.
   - `continentId` from object blob `+0xfc`.
   - `areaId = CVOGTerrain_SampleExploredAreaId(terrain@+0xe4f8, x, z)`.
   - If `!CVOGCharacter_IsAreaExplored`: `CVOGCharacter_SetAreaExploredBit(..., 1)`.
3. Always set next delay `this+8 = 5000` ms, store mode flag at object `+0x307`, `CVOGHBBase_RescheduleAfterFire`.

Server remains authoritative for persistence (UnlockRegion / create extended). This is **local fog-of-war exploration** while driving.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d6c60_Client_LocalDiscoveryTick.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_LocalDiscoveryTick.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d6c60_Client_LocalDiscoveryTick.md` |
| Related | RecvUnlockRegion / SetAreaExploredBit |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 5000 ms reschedule | **High** | Explicit store |
| Sample XZ + SetAreaExploredBit path | **High** | Named callees |
| Alt OnHeartBeat when FUN_005cc630 | **High** | Early branch |
| Gate `+0x7e` / `+0x4f1` | **High** | Raw |
| Continent at `+0xfc`, terrain at `+0xe4f8` | **High** | Raw loads |
| `pOutNextDelayMs` formal | **Tentative** | Unaff in decomp |
| HB object layout (`this+100`) | **Probable** | Standard HB base |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Alt heartbeat branch | **Yes** |
| Explore sample path | **Yes** |
| Delay 5000 + reschedule | **Yes** |
| Scaffold fidelity | **Yes** |

---

## 5. Gaps

1. FUN_005cc630 meaning (mode / paused / offline).
2. Whether local bits sync to server each tick (not in this body).
3. System still `unknown` on record.
4. Runtime period measurement open.

**Verdict:** Discovery tick CF sealed. **accept-with-gaps.**
