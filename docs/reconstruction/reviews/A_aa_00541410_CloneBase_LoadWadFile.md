# Review A (reconstruction fidelity): `aa_00541410` CloneBase_LoadWadFile

| Field | Value |
|---|---|
| **Stable ID** | `aa_00541410` |
| **VA** | `0x00541410` |
| **Canonical name** | `CloneBase_LoadWadFile` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00541410_CloneBase_LoadWadFile.md` |
| **System** | `inventory-transfer` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

WAD open/read path for clonebase (and related) data files (~487-line clean). Opens FILE, reads headers into stack buffers, dispatches record loaders — upstream of per-type loaders including the vehicle clonebase path that hosts `VehicleDb_LoadCloneBase` binds. Not vehicle-tick. Residual path string / record-type switch.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00541410_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00541410_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CloneBase_LoadWadFile.cpp` |
| Function record | `docs/reconstruction/functions/aa_00541410_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `FILE WAD load orchestration` | High | Body |
| `Feeds clonebase ecosystem` | High | Name + call graph |
| `Not VehicleDb_LoadCloneBase body` | High | Different VA |
| `Full record-type dispatch table` | Medium | Switch residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| open → read header → dispatch loaders → close | Yes |
| No invent physics tick | Yes |

---

## 5. Gaps / open

1. List dispatched loader VAs including vehicle.

**Verdict:** accept-with-gaps
