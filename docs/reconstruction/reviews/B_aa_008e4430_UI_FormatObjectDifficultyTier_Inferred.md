# Review B (skeptical / adversarial): `UI_FormatObjectDifficultyTier_Inferred` / `FUN_008e4430` @ `0x008e4430`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e4430` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-J) |
| **Counterpart** | `reviews/A_aa_008e4430_UI_FormatObjectDifficultyTier_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/tiers; reject decompiler “always *out = -1” and stack-only signature |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Signature is only `void f(uint32_t *out)` | **Incomplete** — **EAX object**, **ESI text buffer**, stack out |
| 2 | Always `*param_1 = 0xffffffff` | **Falsified** on success — epilogue stores **packed tier color**; -1 is default/early |
| 3 | `unaff_ESI` is decompiler noise | **Falsified** — call sites set ESI to buffer or **xor esi,esi**; body `test esi,esi` |
| 4 | Tiers are string-only cosmetics | **Overstated** — each tier selects a **palette** and packs via color helpers |
| 5 | Impossible uses same packer as others | **Nuance** — Impossible → `FUN_00973590` direct; others → `FUN_00973820` |
| 6 | Thresholds unknown / data-driven only | **Falsified** — rdata floats **90/70/50/30** sealed |
| 7 | This computes the numeric score | **Falsified** — score is `FUN_0052b080` (not OWN) |
| 8 | Product name sealed | **Open** |
| 9 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Register+stack ABI | **Confirmed** | wrong call-site port |
| Tier string set | **Confirmed** | UI text mismatch |
| Threshold constants | **Confirmed** | wrong tier boundaries |
| `*out` = packed color | **Confirmed** | UI color stuck at white/-1 |
| Score formula details | **High (sibling)** | not owned; do not invent |
| Palette RGB values | **Open** (BSS) | wrong colors until runtime read |
| Product symbol | **Open** | |

---

## 3. Cross-check against raw + bytes

Early exit store:

```
mov ecx, [esp+4]     ; local color (init 0xFF…)
mov eax, [esp+0x20]  ; out*
mov [eax], ecx
pop ebx
add esp, 0x18
ret
```

Success path (after sprintf):

```
mov edx, [esp+0xc]   ; packed color local
mov eax, [esp+0x28]  ; out*
pop edi / pop ebp
mov [eax], edx
pop ebx
add esp, 0x18
ret
```

Threshold loads (`read_memory`):

| VA | Bytes | Float |
|---|---|---|
| `0x00aaa954` | `00 00 B4 42` | **90.0** |
| `0x00aaa950` | `00 00 8C 42` | **70.0** |
| `0x00a0f524` | `00 00 48 42` | **50.0** |
| `0x00a0f694` | `00 00 F0 41` | **30.0** |
| `0x00aaa6f8` | `00 00 7F 43` | **255.0** (Impossible scale) |

---

## 4. Surviving contract for AutoCore

```
// EAX = object*, ESI = char* textOrNull, stack uint32_t* outColor
// plain ret; void (color via *out)
void UI_FormatObjectDifficultyTier(Object* target, char* textBuf, uint32_t* outColor):
  if !target || !g_character: *outColor = 0xFFFFFFFF; return
  required = clone(target)->levelReq_4b0
  player   = GetResource(g_character, clone->key_4ac)   // FUN_0052ada0
  score    = DifficultyScore(g_character, target)       // FUN_0052b080
  if player < required:
    pack Impossible palette; label = "Impossible"
  else:
    pick tier by score vs {90,70,50,30,0}; pack palette
  if textBuf: sprintf(textBuf, "%s: %d", Localize(label), required)
  *outColor = packed
```

Do **not** implement from decompiler-only `*out = -1` tail. Do **not** drop EAX/ESI. Do **not** invent score math here — call the shared helper. Preserve Impossible’s direct `FUN_00973590` path.

---

## 5. Falsification notes

### 5.1 “Always returns -1 color”

Raw decompile collapses stores. Bytes + call sites that push `*out` into widget color methods require a real packed color on the success path.

### 5.2 “Stack-only cdecl”

Five call sites: `lea esi, buffer` / `xor esi,esi`; object in EAX/EBP; single stack out; `add esp, 4` only — matches one stack arg + register params.

### 5.3 “This is the level-diff formula”

Level-diff / score lives in `FUN_0052b080` (base 100, −6 per overlevel, clamp gap 15 — **context**, not sealed in this dual). This unit is the **UI mapper**.

---

**Verdict:** **accept-with-gaps** — sealed UI tier mapping; reject void/stack-only/-1-only decompiler surface.
