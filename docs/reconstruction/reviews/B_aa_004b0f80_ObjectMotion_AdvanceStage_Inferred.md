# Review B (skeptical / adversarial): `ObjectMotion_AdvanceStage_Inferred` / `FUN_004b0f80` @ `0x004b0f80`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b0f80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-E) |
| **Counterpart** | `reviews/A_aa_004b0f80_ObjectMotion_AdvanceStage_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/role; **needs-more-evidence** on product name |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This **is** only mission-complete audio | **Falsified** — audio is one branch when `host+4==0`; primary role is stage advance + duration reload for SlotTick |
| 2 | plain `ret` / cdecl | **Falsified** — epilogue **`C2 04 00`** (ret 4) |
| 3 | Void / unused return | **Falsified** — AL 0\|1; SlotTick treats mode-1 fail as remove |
| 4 | Always returns 1 | **Falsified** — mode-1 + end sentinel + !0x7fb → 0 |
| 5 | Advances stage after loading duration | **Falsified** — advance first, then load from *next |
| 6 | Product name sealed | **Open** |
| 7 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 4 thiscall + AL bool | **Confirmed** | stack imbalance / never-remove on end |
| Stage-chain role (not pure audio) | **High** | miss SlotTick remove contract |
| mode 0 vs 1 polarity | **High** | wrong remove on radius rebind |
| DAT_00aaa638 scale | **Confirmed** | wrong duration jitter |
| Product C++ name | **Open** | docs only |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + bytes

```
if host+4 == 0:
  if name non-empty: audio key + mission-complete SFX
else:
  if name non-empty and !once: FUN_004b7e50; once=1
  if stage+0x2ef & 1: FUN_004b6980()
slot[1] = *(stage+0x2f4)
if mode && next==host+0x14 && !host+0x7fb: AL=0; ret 4
slot[0x5c] = *next
if next+0x1e4 & 4: slot[0x5c] += u16 * *(float)(next+4) * (1/65535)
slot[0x5d] = slot[0x5c]
AL=1; ret 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Epilogue: `B0 01 5E 8B E5 5D C2 04 00`.

---

## 4. Surviving contract for AutoCore

```
// thiscall, ret 4
int ObjectMotion_AdvanceStage(void* slot, char mode):
  // side effects on current stage (audio or FX/flush)
  // slot.stage = slot.stage->next (+0x2f4)
  // if mode!=0 and next is end-sentinel and no secondary timer: return 0
  // reload duration remaining+total; optional RNG jitter
  // return 1
```

Do **not** treat as pure mission-audio helper. Do **not** invert mode-1 end-of-chain return 0 (SlotTick depends on it).

---

## 5. Falsification notes

### 5.1 “Is mission-complete audio”

Coverage keyword rename is a partial hit. Sole caller is SlotTick; audio only when `*(host+4)==0` and name string non-empty. Hosted path uses FX spawn instead.

### 5.2 “cdecl void”

`ret 4` + non-void AL. Ports must clean 4 bytes and honor 0/1 for chain end.

### 5.3 “mode 0 also fails on sentinel”

Only when `param_2 != 0`. Soft advance (mode 0) after radius pull does **not** take the AL=0 early path even if next is sentinel (still loads duration).

---

## 6. Open questions

1. Retail name / product class of stage.
2. Exact English of `FUN_004b7e50` / `FUN_004e9530`.
3. Whether `host+4==0` means “client local” vs another host mode.
4. Bit-exact / runtime — open.

**Verdict:** **accept-with-gaps** on sealed CF, ABI, stage-advance contract. Reject “is only mission audio” and “plain void ret” overclaims.
