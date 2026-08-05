# Review B (skeptical / adversarial): `aa_00541e70` CloneBase_Load

| Field | Value |
|---|---|
| **Stable ID** | `aa_00541e70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W24-N) |
| **Counterpart** | `reviews/A_aa_00541e70_CloneBase_Load.md` |
| **Scratch** | `tmp/a_00541e70.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Is only “after CVOGRegionMissions” mission helper | **Falsified** — full start→end CloneBase; RegionMissions is one phase |
| 2 | Free function / no this | **Falsified** — `mov esi,ecx`; host field writes; `ret 0xC` |
| 3 | Always runs LoadSkillsFX | **Falsified** — gated `DAT_00b03e64==0` && `DAT_00b035fc!=0` |
| 4 | Always builds RegionMissions | **Falsified** — needs flagA && `host+0xF18==0` |
| 5 | First-time globals every call | **Falsified** — only when `DAT_00b04690` becomes 1 |
| 6 | param_4 “skip” skips WAD | **Falsified** — WAD always; flagC skips heavy post (loot/map/typedef) |
| 7 | Multiple independent callers | **Falsified** — sole xref `FUN_00542aa0` |
| 8 | Scaffold invents CF | **Attack fails** — live ≡ raw 2026-07-23 body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CloneBase orchestrator role | **High** | Wrong content-load model |
| thiscall + ret 0xC | **High** | Stack corruption |
| Hash field map | **High** | LoadSkillsFX wrong target |
| Flag product names | **Medium/Open** | Wrong ctor arg docs |
| Nested callee contracts | **Open** | Partial port bugs |
| Runtime flag matrix | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
// entry
push ebp; mov ebp,esp; push -1; push LAB_009a40ca; ...
mov esi, ecx          // host
log "CloneBase: start"
...
// exit success
log "CloneBase: end"
mov fs:[0], ...
mov esp,ebp; pop ebp
ret 0x0C
```

Caller:
```
if (param_5 == 0)
  FUN_00541e70(this=host, param_2, param_3, param_4);
```

Phase gates surviving attack:

```
firstTime = (++DAT_00b04690 == 1)
LoadWad always (throw if fail)
loot catalog in array: flagB && !flagC
post-array helper: flagA && !flagC
map modules: !flagC && count>0
RegionMissions: flagA && host.f18==null
TypeDef reload: !flagC
LoadSkillsFX: !DAT_00b03e64 && DAT_00b035fc
```

---

## 4. Surviving contract for AutoCore

```
// Client content host construction path
CloneBase_Load(host, flagA, flagB, flagC):
  ensure host hashes @ F10/F14/F0C/EF0
  if process first load: configs + removed objects
  LoadWad or throw
  materialize clones (0x114) + maps (0x154)
  optional RegionMissions @ F18, TypeDef @ F1C
  optional LoadSkillsFX + SpecialFXMaster

// Do NOT:
//  - call without host this (hashes)
//  - treat as mission-only helper
//  - assume LoadSkillsFX always runs
//  - conflate flagC with skipping WAD
//  - invent extra callers beyond host ctor
```

---

## 5. CF challenge of Review A

Agree CF and ABI. Residual dispute is only product English for flags (Medium/Open) — does not overturn phase gates.

**Verdict:** **accept-with-gaps**
