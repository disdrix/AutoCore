# Review B (skeptical / adversarial): `aa_00979310` ClientSpecialEvent_Respawn_SetupAirlift

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979310` |
| **VA** | `0x00979310` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00979310_ClientSpecialEvent_Respawn_SetupAirlift.md` |
| **Evidence** | Live decompile; Respawn ctor/Update duals; strings |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Pure cancel/teardown only | **Falsified** | Allocates airlift, loads anims, places object on success |
| 2 | Never sets cancel flag | **Falsified** | Resolve fail → `this+0x08=1` |
| 3 | Free-standing with no `this` | **Falsified** | EDI event object throughout |
| 4 | Arbitrary CBID | **Falsified** | Hardcoded **0xadc** |
| 5 | No anim work (ctor residual) | **Falsified** | Three `.anm` + blend select |
| 6 | Many callers | **Falsified** | Only Respawn ctor + Update |
| 7 | Clean invents strings | **Falsified** | Present in raw |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fail → cancel flag | **High** | Respawn hangs / wrong phase |
| Setup vs teardown label | **High** (body is setup) | Port deletes objects it should create |
| Anim/CBID literals | **High** | Missing airlift VFX |
| Camera globals | **Tentative** | Local-player only path wrong |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
Respawn_SetupAirlift(event):
  obj = resolve(event.tfid@+0x28)
  if !obj || !obj.alive: event.cancel=1; return
  event.cancel=0
  ship = GiveItemByCbid(0xADC)
  ... place + airlift anims + mode force ...
```

Parent duals may say “cancel helper” — **body evidence overrides**: shared **setup** that can **arm cancel**.

**Verdict:** **accept-with-gaps**
