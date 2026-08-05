# Review B (skeptical / adversarial): `aa_005c74e0` CLoadNode__initSpecialFX

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c74e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W23-G) |
| **Counterpart** | `reviews/A_aa_005c74e0_CLoadNode__initSpecialFX.md` |
| **Scratch** | `tmp/a_005c74e0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Primary name is VOG_DEBUG_STOP | **Falsified** — plate string `_initSpecialFX`; VOG_DEBUG_STOP is hash-error side path only |
| 2 | No this/flags host (stack-only) | **Falsified** — prologue `mov [esp+0x18],ecx`; end writes `+0x62`; caller `mov ecx,esi` |
| 3 | Always returns 1 | **Falsified** — offline LoadMaster path returns 0 |
| 4 | Always loads XML | **Falsified** — live path uses `FUN_00542790` when `DAT_00d1f050+0x6c != 0` |
| 5 | Multiple independent callers | **Falsified** — sole xref `FUN_005c7cd0` |
| 6 | Hash lock optional | **Falsified** — sets `+0x1d`, logs if wrong |
| 7 | local_410 random | **Falsified** — matches entry ECX / caller stage object |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Name / string | **High** | Misfiled load stage |
| RET 0x4 + ECX/stack split | **High** | Wrong stage bit clear |
| Return 1/0 | **High** | Stage pipeline abort |
| Live vs offline branch | **High** | Missing FX on load |
| Hash lock discipline | **High** | Traversal corruption |
| Mode flag English | **Medium** | Wrong path in tools |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
flagHost = ECX; node = stack0
scope("CLoadNode::_initSpecialFX")
adj = MI(node)
if feature enabled && hash:
  lock; foreach entry:
    if offline: maybe LoadMasterFromXML → return 0
    else FxCache_ApplyWithNfxEnsure(id,4,1,0…)
  unlock
flagHost+0x62 = 0
return 1
RET 0x4
```

Caller requires `+0x62 && +0x51` before call; treats `eax!=1` as stage failure.

---

## 4. Surviving contract for AutoCore

```
// Client object load stage — special FX
ok = CLoadNode__initSpecialFX(stageFlags, node)
// ok==1 → stage bit 0x62 cleared; continue pipeline
// ok==0 → offline master XML load occurred; caller aborts/propagates
// Live worlds: FUN_00542790 path (no return 0 from that branch)
```

Server may skip; client load parity needs stage bit + live FX apply semantics.
