# Review B (skeptical / adversarial): `aa_005b7250` SpeedTreeRT_ComputeTree_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b7250` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-A) |
| **Counterpart** | `reviews/A_aa_005b7250_SpeedTreeRT_ComputeTree_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / bare RET | **Falsified** — epilogue `RET 0x14` (thiscall, 5 stack args) |
| 2 | Always recomputes tree | **Falsified** — `*(asset+0x128) >= 1` → `FUN_005b71a0(1)` only |
| 3 | Null `param_3` still proceeds | **Falsified** — early `XOR AL,AL` when asset null |
| 4 | Always applies size params | **Falsified** — both must be `>= 0` |
| 5 | Texture suffix `".tga"` / no ext | **Falsified** — `DAT_00a2c53c` = `".dds"` |
| 6 | LOD scale is 1.0 or 2.0 | **Falsified** — `DAT_00aaa688` = **5.0f** (`00 00 a0 40`) |
| 7 | Product name beyond SpeedTreeRT family | **Careful** — plates prove SpeedTreeRT; nested methods stay `FUN_*` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 0x14 | **High** | Wrong stack cleanup |
| First-compute vs refresh gate | **High** | Double compute / skip load |
| SpeedTreeRT family (plates + `.spt` caller) | **High** | Wrong subsystem |
| `.dds` / 5.0f constants | **High** | Wrong assets / LOD |
| Nested RT method English | **Low** | Naming only |
| `param_2`/`param_4` types | **Tentative** | Resource API mismatch |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Caller FUN_00582090:
//   sprintf(local, "%s.spt"); lookup/alloc host; this+0x124 = new tree obj
//   FUN_005b7250() when *(host+0x128)==0 path; then refcount++; FUN_005b7250() again
// Prologue: MOV ESI,ECX; MOV [ESI+0x174],EAX (2nd stack after SEH = asset)
// Epilogue: ADD ESP,0xC4; RET 0x14; pad CC
// Body 0x005b7250–0x005b76e5 exclusive = 1173 B
// Live decompile 2026-07-29 ≡ raw 2026-07-23 CF
// read_memory: 0x00a2c53c=".dds"; 0x00aaa688=5.0f
```

---

## 4. Surviving contract for AutoCore

```
// Port as SpeedTreeRT compute/refresh:
uint8_t SpeedTreeRT_ComputeTree(Host* self, ResKey* key, Asset* cfg,
                                void* compute_arg, float a, float b) {
  self->asset = cfg; if (!cfg) return 0;
  ensure self->st (0x9c);
  if (cfg->gate_0x128 >= 1) { refresh(1); return 1; }
  // load resource → ST; configure; compute; bounds; LOD*5; mats; optional .dds
  // on ST error / compute fail: log plate + return 0
}
// thiscall + 5 stack args (RET 0x14). Do not invent SDK method names without plates.
```

---

## 5. Verdict

Adversarial pass confirms A on thiscall ABI, dual-path CF, SpeedTreeRT plates, and constants. Residual nested SDK plates/types → **accept-with-gaps**.
