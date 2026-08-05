# Review B (skeptical / adversarial): `aa_00542790` `FxCache_ApplyWithNfxEnsure`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00542790` |
| **VA** | `0x00542790` |
| **Canonical name** | `FxCache_ApplyWithNfxEnsure` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00542790_FxCache_ApplyWithNfxEnsure.md` |
| **System** | `client-fx` / skills-abilities |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as 005408f0 | SEH, 7 args, vtbl apply, `_nfx` append, transform fallback | **Falsified** equivalence |
| 2 | Always applies to entity | Needs open success + non-null param_7 + non-null fx | **Falsified** always-apply |
| 3 | No SEH | Prologue push -1 / LAB_009a40df / fs:[0] | **Falsified** no-SEH |
| 4 | `ret 4` / small ABI | Dual `C2 1C 00` (early+late) | **Falsified** |
| 5 | Runs without resource subsystem | Gate returns 0 when `DAT_00d1f050+0x6c==0` | **Falsified** always-on |
| 6 | Default pose is identity float 1 | Bytes `ff*8 + 00*8` at `009d00a8` | **Falsified** float-identity claim |
| 7 | Product name proven | `_nfx` evidence only | **Agree Open** |
| 8 | Scaffold invents CF | Live ≡ raw | **Attack fails** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate + SEH + `ret 0x1c` | **Confirmed** | Wrong stack / silent no-op |
| Hash + master path + `_nfx.xml` | **Confirmed** | Wrong script load |
| vtbl apply vs fallback | **High** | Missing entity attach in port |
| Transform `+0x160` meaning | **Probable** | layout residual |
| English names | **Open** | docs only |

---

## 3. Cross-check against raw / live / bytes

Complementary use with `005408f0` in `FUN_00512d10`:

```
if (live_subsystem && outFx==null) → FUN_00542790(...)  // full apply
else if (outFx==null)             → FUN_005408f0(...)  // ensure+resolve only
```

`FUN_005c74e0` (`CLoadNode::_initSpecialFX`) calls this with sparse args when subsystem live — confirms role in special-FX init, not combat-only.

Decompiler `FUN_0054b480(pi,pu)` args remain **fake** (GetGlobal leaf) — same trap as sibling dual.

---

## 4. Surviving contract for AutoCore

```
FxCache_ApplyWithNfxEnsure(host, key, event, a, b, source, target, c):
  if !resource_subsystem: return 0
  snap transforms from source/target +0x160 or g_defaultXform (009d00a8)
  value = CNDHash_LookupByKey(*(host+0xf0c), key)
  if !value: return 0
  if !value.masterLoaded:
      def = SkillDefMap.find(key); if !def: return 0
      path = name(def) + "_nfx.xml"
      if open(path):
          strip "_nfx.xml"; LoadMasterFromXML(base)
      else: cleanup; fall through
  if open/resource path ok:
      fx = ResolveFx(event, 1, -1)
      if !fx || !target: return 0
      target->vtbl[+0x238](event,key,a,b,source,c,1,fx)
      return 1
  else:
      TransformFallback(snap); return 1   // decompiler success path via 00545d70

AutoCore must NOT:
  - skip DAT_00d1f050+0x6c gate
  - treat as 005408f0 (no attach)
  - assume float identity default pose
  - omit SEH/lifetime if rehosting retail ABI hooks
  - invent product vtbl name without evidence
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Full apply + nfx ensure | **Agree High** |
| 764 B / ret 0x1c / SEH / gate | **Agree Confirmed** |
| accept-with-gaps | **Agree** |
| structural name | **Agree** INFERRED; product **Open** |
| transform fallback always “success 1” | **Agree** per decompile (after 00545d70) |

---

## 6. Gaps (B list)

1. Product English.
2. Semantic meaning of `FUN_00545d70` fallback (not OWN).
3. Whether fail paths always restore SEH (decompile shows `FUN_005b2ba0` on fail — **High**).
4. Runtime golden.

**Verdict:** **accept-with-gaps** — adversarial probes do not break sealed ABI/CF; residuals are naming/runtime/callees.
