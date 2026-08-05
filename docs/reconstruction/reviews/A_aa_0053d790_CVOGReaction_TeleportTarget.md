# Review A (reconstruction fidelity): `aa_0053d790` CVOGReaction_TeleportTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053d790` |
| **VA** | `0x0053d790` |
| **Canonical name** | `CVOGReaction_TeleportTarget` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053d790_CVOGReaction_TeleportTarget.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Apply **teleport pose** from a 4-dword payload (xyz + orientation):

1. Vtable `+0x40` pre-callback on `this`.
2. If `this+0x8` (target) is null: copy 4 dwords into dual-base pose at `this` dual +0x84.
3. Else: validate via `FUN_005070b0`; on pass and target+0x44 set call `FUN_005070d0`; if flag +0x40 clear or +0x8==0, vtable +0x40 on target+0x3c with teleport data.

Client-side reaction apply; not a map transfer (see TransferMap).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0053d790_CVOGReaction_TeleportTarget.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_TeleportTarget.cpp` |
| System map | `docs/reconstruction/systems/missions-progression.md` (when present) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(ctx, float4*)` | **High** | Raw |
| Pre-callback vtable +0x40 | **High** | First call |
| Null target → pose copy +0x84 | **High** | Branch |
| Non-null validation helpers | **High** | FUN_005070b0/d0 |
| Secondary vcall on +0x3c | **High** | End branch |
| Payload is xyz+ori | **Probable** | Plate; 4 dwords |
| Field names target/source | **Tentative** | Offset labels |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Pre-callback | **Yes** |
| Null vs non-null target | **Yes** |
| Validate / secondary vcall | **Yes** |
| No map load call | **Yes** |

---

## 5. Gaps

1. FUN_005070b0 validation meaning.
2. Exact layout of pTeleportData.
3. When target+0x40 blocks secondary apply.
4. Runtime mission teleport.

**Verdict:** accept-with-gaps.
