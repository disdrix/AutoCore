# Review B (skeptical / adversarial): `aa_005995a0` Host_ScreenToTerrainHitNotify_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005995a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-P) |
| **Counterpart** | `reviews/A_aa_005995a0_Host_ScreenToTerrainHitNotify_Inferred.md` |
| **Verdict** | **accept-with-gaps** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler surface shows correct callee this | Bytes load `*(map+0xe890)` / `map` into ECX | **Surface incomplete** — bytes win |
| 2 | This is DriveControlTick / InteractClickPick body | Distinct VA; only DATA vtbl xref | **Falsified** |
| 3 | maxSteps is 100 / unlimited / float | imm `0x190` = 400 | **Falsified** |
| 4 | Uses CastTerrainHeight float sampler API | Calls MarchDir `0x004cff70` only | **Falsified** |
| 5 | Writes vehicle drive axes | No axis stores; only notify + bool | **Falsified** |
| 6 | Stack args on this host method | Bare `ret` / no `c2`; only ECX host | **Falsified** if claimed |
| 7 | Notify is free function / global | `mov ecx,[esi+0x24]` + `call [vtbl+0x5c]` | **Falsified** |
| 8 | map lives at host+0xe890 | `+0xe890` is **on map**, not host | **Falsified** if swapped |
| 9 | Has many direct code callers | Only DATA `@0x009d55bc` | **Falsified** if “many CALL” |
| 10 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |
| 11 | Product name sealed | `_Inferred` residual | **Overstated** if claimed product |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pipeline CF | **High** | Wrong pick path |
| Host +0x24/38/3c/40 | **High** | Wrong fields |
| map+0xe890 view | **High** | Null/wrong unproject |
| maxSteps 400 | **High** | Different march budget |
| Product names | **Low–Med** | Naming only |
| Hit payload beyond float4 | **Med** | Notify arg residual |
| Vtbl owning class | **Low–Med** | Type residual |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile surface | **Yes** (with known this-gap) |
| Body hex via `read_memory` | **Yes** — prolog `55 8b ec 83 e4 f0…`, ends dual `c3` |
| maxSteps imm | **Yes** `68 90 01 00 00` |
| Vtbl slot value | **Yes** `@0x009d55bc` LE `a0 95 59 00` |
| Callee duals exist | **Yes** Unproject + MarchDir sealed elsewhere |
| Direct callers | **None** code; virtual dispatch only |

**Attack on “trust decompiler this for callees”:** **Succeeds as attack** — surface omits this; clean/annotated must restore from bytes.

**Attack on “this is the interact pick unit”:** **Fails** — separate VA; shared callees only.

---

## 4. Surviving contract for AutoCore

```
// ECX = host*
// if *(host+0x40)==0 return 0
// screen = (*(host+0x38), *(host+0x3c))
// view = *(*(host+0x40)+0xe890)
// Unproject(view, screen, near, dir)
// origin4 = {near,0}; dir4 = {dir,0}
// if !MarchDir(*(host+0x40), origin4, dir4, hit, 400) return 0
// (*(host+0x24))->vtbl[0x5c/4](hit); return 1
// bare ret
```

**Falsified port mistakes:**

- Calling Unproject/March without correct this (view/map).
- Using host+0xe890 instead of map+0xe890.
- Inventing drive-axis writes or different step budget.
- Treating as stdcall multi-arg without ECX host.

---

## 5. Open questions

1. Host / notify product class names.  
2. Full hit-buffer schema.  
3. Which type owns vtbl including this slot.  
4. Runtime golden (screen → hit → notify).

**Verdict: accept-with-gaps** — CF sealed; product naming + hit layout residual.
