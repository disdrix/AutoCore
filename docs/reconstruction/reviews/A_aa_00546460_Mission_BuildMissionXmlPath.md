# Review A (reconstruction fidelity): `aa_00546460` Mission_BuildMissionXmlPath

| Field | Value |
|---|---|
| **Stable ID** | `aa_00546460` |
| **VA** | `0x00546460` |
| **Canonical name** | `Mission_BuildMissionXmlPath` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00546460_Mission_BuildMissionXmlPath.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept** |

---

## 1. Purpose

Build filesystem path `..\missions\%s%S.xml` via `_snprintf` into 0x104 buffer from mission name at `param_1+4`, then `_unlink` prior file. Thin FS helper for mission content pipeline/export — not runtime objective logic.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00546460_Mission_BuildMissionXmlPath.md` (or `aa_00546460_FUN_00546460.md`) |
| Annotated | `docs/reconstruction/raw/aa_00546460_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_BuildMissionXmlPath.cpp` |
| Function record | `docs/reconstruction/functions/aa_00546460_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Format ..\\missions\\%s%S.xml` | High | Strings |
| `Name at param_1+4` | High | snprintf arg |
| `Buffer 0x104 zeroed` | High | Body |
| `_unlink after build` | High | Callee |
| `Not objective eval` | High | Scope |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Zero buf → snprintf → unlink | Yes |
| No invented mission state | Yes |

---

## 5. Gaps / open

1. Wide vs narrow %S source encoding.
2. All callers (export vs runtime).

**Verdict:** **accept**
