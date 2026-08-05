# Review B (skeptical / adversarial): `aa_00984d30` AssPackManager_ExtractPackEntryToFile_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984d30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-Q) |
| **Counterpart** | `reviews/A_aa_00984d30_AssPackManager_ExtractPackEntryToFile_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Thiscall ECX=this (host) | **Falsified** — ECX is **outPath** (`8B D9`); host is **stack0** (`8B 6C …` / `80 7D 50`) |
| 2 | Bare `RET` / 2 stack args only | **Falsified** — both epilogues `C2 0C 00` (3 stack dwords) |
| 3 | Always locks | **Falsified** — gate `char +0x50` |
| 4 | Compact decompile formal order is authority | **Falsified** — compact shows `FUN_00984d30(local_1f8, name, empty)` as thiscall-first=host; **call-site bytes** set ECX to joined path string |
| 5 | Deletes pack entry | **Falsified** — read+write out; no remove |
| 6 | Scaffold `Named_assPackManager_*` is product method | **Careful** — plate path only; `_Inferred` required |
| 7 | Same as add `FUN_00984910` | **Falsified** — extract/write vs add/replace |
| 8 | stack[2] is a required name formal | **Weak** — sole caller always pushes empty; slot reused as fmt buf on fail |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX outPath + host stack + RET 0x0C | **High** | Wrong port convention |
| Lookup → stream → write CF | **High** | Miss extract stage |
| CS offsets | **High** | Deadlock / race |
| Nested stream/read semantics | **Med** | Wrong buffer size/flags |
| stack[2] product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Sole caller FUN_00985010 compact loop @ 0x00985169:
//   ECX = c_str of joined "_pk_" + "/" + name
//   push &DAT_00a1419b   // empty
//   push name
//   push host (packA)
//   call FUN_00984d30    // RET 0x0C
// then FUN_00984910 adds stage file into packB
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full 421 B hex seals dual epilogues.

---

## 4. Surviving contract for AutoCore

```
// Port as pack EXTRACT-to-file under optional CS:
//   outPath in ECX (nullable → entry default path → ""), host + entryName on stack
//   lookup; stream read size@+8; open write mode 6; WriteFile; free; return 0/-1
// Do not invent thiscall-ECX=host.
// Do not treat as add/replace (that's 00984910).
// Pair with CompactPackFile (sole caller) and AddOrReplaceFileInPack.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/path fallback. Nested stream + spill residual → **accept-with-gaps**.
