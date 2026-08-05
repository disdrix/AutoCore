# Review A (reconstruction fidelity): `aa_00467820` Phy_BoundingVolumeFactory_CreateFromTag

| Field | Value |
|---|---|
| **Stable ID** | `aa_00467820` |
| **VA** | `0x00467820` |
| **Canonical name** | `Phy_BoundingVolumeFactory_CreateFromTag` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00467820_Phy_BoundingVolumeFactory_CreateFromTag.md` |
| **System** | `physics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Factory: **create bounding volume by type tag** (phyBoundingVolumeFactory). `__fastcall(tag)`. Switch tags **1..5**: 1→ new 0x18 sphere-like (`PTR_FUN_00aa5c54` + DAT dims); 2→ new 0x20 `FUN_00467440`; 3→ new 0x28 `FUN_004674e0`; 4→ new 8 `PTR_FUN_00aa5c6c`; 5→ new 0x100 `FUN_00467600`. Default logs `Invalid type [ %c ] for phyBoundingVolume` and returns null.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00467820_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00467820_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phy_BoundingVolumeFactory_CreateFromTag.cpp` |
| Function record | `docs/reconstruction/functions/aa_00467820_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Tags 1..5 allocate distinct BV types | High | Switch body |
| Default logs + null | High | Body |
| Tag 1 uses DAT_00d1a6c0..c8 defaults | High | Body |
| Human type names per tag | Medium | Inferred sphere/box/… |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| switch tag → new+init → return; default log null | Yes |

---

## 5. Gaps / open

1. Map tag→type names from headers/strings.
2. Size 0x100 tag5 identity.

**Verdict:** **accept-with-gaps**
