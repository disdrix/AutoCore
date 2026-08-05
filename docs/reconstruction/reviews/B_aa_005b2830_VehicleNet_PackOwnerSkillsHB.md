# Review B (skeptical / adversarial): `aa_005b2830` VehicleNet_PackOwnerSkillsHB

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2830` |
| **VA** | `0x005b2830` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005b2830_VehicleNet_PackOwnerSkillsHB.md` |
| **Evidence** | Live decompile; constant `DAT_00a0f298`; parent PackUpdate |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Same body as initial identity `0x005b1290` | **Falsified** | HB walk + CS + count wire |
| 2 | Packs every HB entry | **Falsified** | flags==1 and timer/sentinel gate |
| 3 | Threshold is 0 or 1 second | **Falsified** | 0.5f constant |
| 4 | `operator_delete` aborts | **Falsified** | decompiler false positive |
| 5 | No concurrency control | **Falsified** | LeaveCriticalSection path |
| 6 | Zero count still packs payloads | **Falsified** | write 0 then skip bulk |
| 7 | Clean invents SEH | **Falsified** | raw has ExceptionList frame |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate CF + 0.5f | **High** | Wrong skills appear/disappear on wire |
| Count / empty path | **High** | Unpack desync |
| Bulk format in `0x005b13f0` | **Open** | Incomplete port of multi-skill |
| Node field English | **Tentative** | Naming only |

---

## 3. Surviving contract

```
PackOwnerSkillsHB(stream, hbRoot):
  collect active HB nodes (flags==1 && (sentinel==-1000 || remaining>0.5f))
  unlock list CS if held
  writeU8(count)
  if count: writeU16(first) + packRecords(...) + free
```

**Do not** merge with `0x005b1290`.

**Verdict:** **accept-with-gaps**
