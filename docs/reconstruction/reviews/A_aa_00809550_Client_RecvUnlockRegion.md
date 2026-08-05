# Review A (reconstruction fidelity): `aa_00809550` Client_RecvUnlockRegion

| Field | Value |
|---|---|
| **Stable ID** | `aa_00809550` |
| **VA** | `0x00809550` |
| **Canonical name** | `Client_RecvUnlockRegion` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00809550_Client_RecvUnlockRegion.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C **`EMSG_Sector_UnlockRegion` (`0x205B`)** handler:

**Packet (plate):** opcode, ContinentId (int @+4), UnlockFlag (byte @+8), ExploredBits (uint @+0xc).

On local character (`client+0xe98`):

1. If `UnlockFlag == 0`: `CVOGReaction_RelockContinentObject(continentId)` and return.
2. Else lookup `USContinentUnlocked` in hash `char+0x534` by continentId.
3. **No entry:** `CVOGReaction_UnlockContinentObject(char, continentId)` only — **packet ExploredBits ignored** (bootstrap empty unlock).
4. **Entry exists and bits differ:** for area indices `0..31`, if bit differs vs local `entry+8`, call `CVOGCharacter_SetAreaExploredBit(char, continentId, areaId=i+1, bitOn)`.

AutoCore note (plate): send twice after login — bootstrap then apply bits.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00809550_Client_RecvUnlockRegion.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvUnlockRegion.cpp` |
| Function record | `docs/reconstruction/functions/aa_00809550_Client_RecvUnlockRegion.md` |
| Related | UnlockContinentObject / RelockContinentObject / LocalDiscoveryTick |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Opcode 0x205B plate | **High** | Plate + naming |
| UnlockFlag==0 → Relock | **High** | Raw |
| No entry → Unlock only, ignore bits | **High** | Explicit plate + CF |
| Bit-diff loop areas 1..32 | **High** | `i+1`, 0x20 iterations |
| Local char at `+0xe98` | **High** | Client pattern |
| Hash at char `+0x534` | **High** | Lookup |
| Decomp `pPacket` register recovery | **Probable** | Unaff/stack framing messy |
| `__fastcall` vs real convention | **Tentative** | Decomp artifact |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null character bail | **Yes** |
| Relock arm | **Yes** |
| Lookup / unlock / bit loop | **Yes** |
| No invented bit apply on first unlock | **Yes** |

---

## 5. Gaps

1. Decompiler packet pointer framing (`pPacket` / `in_stack`) not cleanly typed.
2. Relock / UnlockContinentObject internals open.
3. Runtime double-send login bootstrap not observed this review.
4. System field still `unknown` on function record.

**Verdict:** UnlockRegion apply CF sealed. **accept-with-gaps.**
