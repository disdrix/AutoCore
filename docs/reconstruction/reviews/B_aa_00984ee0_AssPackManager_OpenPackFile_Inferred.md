# Review B (skeptical / adversarial): `aa_00984ee0` AssPackManager_OpenPackFile_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984ee0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-H) |
| **Counterpart** | `reviews/A_aa_00984ee0_AssPackManager_OpenPackFile_Inferred.md` |
| **Scratch** | `tmp/a_00984ee0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Thiscall ECX=this | **Falsified** — ECX is path (`8B F1`); this is **EBX** (`80 7B 50`) |
| 2 | Callers pass only stack `1` as sole arg meaning path | **Falsified** — stack is flag; path in ECX from literal `.glm` strings |
| 3 | Bare `RET` / no stack cleanup | **Falsified** — `C2 04 00` both epilogues |
| 4 | Always locks | **Falsified** — gate `char +0x50` |
| 5 | Inserts into map/tree | **Falsified** — `LEA EAX,[EBX+0x28]` + vector push helper `FUN_004406e0` |
| 6 | Scaffold name is product method | **Careful** — plate path only; `_Inferred` required |
| 7 | On fail frees pack | **Not shown** — no `operator_delete` on fail path in this body |
| 8 | Same as compact `FUN_00985010` | **Falsified** — this is open unit; compact is separate (calls this) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX/ECX/stack ABI | **High** | Wrong port convention |
| Open then push CF | **High** | Miss registration |
| CS offsets | **High** | Deadlock / race |
| Nested open semantics | **Med** | Wrong file flags |
| Product English name | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Caller pattern (007b75b0 batch):
mov eax, [host]
push 1
lea ebx, [eax+8]      // AssPackManager at host+8
mov ecx, "../effects.glm"
call FUN_00984ee0     // RET 4
// repeated for other .glm paths; extra batch when mode==0
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full 295 B hex seals dual epilogues.

---

## 4. Surviving contract for AutoCore

```
// Port as pack OPEN under optional CS:
//   self in EBX (or explicit this), path, flag
//   new Pack(0x44); open; on success push into self.packs@+0x28
//   return 0 / -1
// Do not invent thiscall-ECX=this.
// Do not treat stack 0/1 as path.
// Pair with AssManager init batch (W30-D) for which packs open at boot.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/layout. Nested open + fail free residual → **accept-with-gaps**.
