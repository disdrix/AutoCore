# Review A (reconstruction fidelity): `aa_00632c10` CVOGTacArc_UpdateMesh

| Field | Value |
|---|---|
| **Stable ID** | `aa_00632c10` |
| **VA** | `0x00632c10` |
| **Canonical name** | `CVOGTacArc_UpdateMesh` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00632c10_CVOGTacArc_UpdateMesh.md` |
| **System** | `client-ui` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Per-frame/refresh TacArc geometry from owner weapon state. Early **-1** if mesh `+0x18` or mat `+0x1c` null. Reads owner at `+0x20` for angles/ranges (`+0xdc`, `+0xd8`, `+0xe8`, flag `+0xcb`) or falls back to cached fields `+0x40..+0x50`; may call `FUN_0056a680` and vehicle vtbl **+0x19c** to extend range via accessory float `+0x34`. Rebuilds sector vertices (param float is dt/angle seed). Large math body — geometry only.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00632c10_CVOGTacArc_UpdateMesh.md` |
| Annotated | `docs/reconstruction/raw/aa_00632c10_CVOGTacArc_UpdateMesh.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTacArc_UpdateMesh.cpp` |
| Function record | `docs/reconstruction/functions/aa_00632c10_CVOGTacArc_UpdateMesh.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Null mesh/mat → 0xffffffff` | **High** | Entry |
| `Owner +0x20 preferred over cache +0x40..` | **High** | Branch |
| `Reads owner +0xdc/+0xd8/+0xe8/+0xcb` | **High** | Angles/range |
| `FUN_0056a680(0) on owner path` | **High** | Call |
| `Optional +0x19c accessory adds to range` | **High** | if non-null |
| `Writes mesh geometry (many floats)` | **High** | Body size |
| `param_2 float influences update` | **High** | Arg |
| `Not damage / not server` | **High** | No combat award |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null gates + owner/cache sample + mesh rebuild | **Yes** |
| No invented network | **Yes** |

---

## 5. Gaps / open

1. Full vertex formula (segment count vs angles).
2. Semantic names for owner+0xdc/+0xd8/+0xcb.
3. FUN_0056a680 identity.
4. When Initialize passes 0 vs per-frame callers.

**Verdict:** **accept-with-gaps**
