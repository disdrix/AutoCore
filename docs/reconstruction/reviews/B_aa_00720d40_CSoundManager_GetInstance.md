# Review B (skeptical / adversarial): `aa_00720d40` CSoundManager_GetInstance

| Field | Value |
|---|---|
| **Stable ID** | `aa_00720d40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00720d40_CSoundManager_GetInstance.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same singleton as `Client_GetMissionCompleteAudioTable` (`0x00723820`) | Confuse `DAT_00d20210` vs `DAT_00d20070` | **Falsified** — this unit returns **`&DAT_00d20070`**; mission-complete table is **`DAT_00d20210`** / flag `DAT_00d20630` |
| 2 | Always re-inits manager | | **Falsified** — gated by `DAT_00d20200` bit0 |
| 3 | Returns null when uninit | | **Falsified** — always returns static address |
| 4 | Thiscall method | | **Falsified** — free function, no ECX object |
| 5 | Name is PDB-proven `GetInstance` | | **Not sealed** — Probable only |
| 6 | Family is audio | Sibling string | **Sealed** — `CSoundManager::_stopSound` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Once-bit + atexit | **High** | Double-init / leak |
| Storage `DAT_00d20070` | **High** | Wrong manager |
| Distinct from mission-complete audio table | **High** | Cross-wire play cues |
| English name | **Medium** | Doc only |

---

## 3. Cross-check against raw

```text
// raw ≡ live
if ((DAT_00d20200 & 1) == 0) {
  DAT_00d20200 |= 1;
  FUN_00720a40(&DAT_00d20070);
  _atexit(LAB_009c3720);
}
return &DAT_00d20070;
```

---

## 4. Surviving contract for AutoCore

```
CSoundManager* GetInstance():
  once-init static manager at DAT_00d20070
  return &DAT_00d20070
```

**Port tests:**

* Second call must not re-run ctor.
* Must not alias mission-complete table at `DAT_00d20210`.

---

## 5. Open questions

1. Exact size/layout of object at `DAT_00d20070`.
2. Whether any code path zeros the once-bit (hot-reload).

**Verdict:** **accept**
