# Review B (skeptical / adversarial): `aa_00541410` CloneBase_LoadWadFile

| Field | Value |
|---|---|
| **Stable ID** | `aa_00541410` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00541410_CloneBase_LoadWadFile.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is VehicleDb_LoadCloneBase | Falsified — different address/role |
| 2 | Runtime ghost unpack | Falsified — load-time I/O |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| WAD path correctness | High | Missing vehicle specs |
| Dispatch completeness | Medium | Silent skip types |

---

## 3. Cross-check against raw

```
LoadWadFile:
  open wad; parse; dispatch type loaders (incl. vehicle clonebase binds).
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
Load-time only; AutoCore already uses DB — useful for client-parity RE.
```

---

## 5. Open questions

1. Map vehicle record loader entry to 0x7efb40.

**Verdict:** accept-with-gaps
