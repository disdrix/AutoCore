# Review B (skeptical / adversarial): `aa_00578b30` Skill_HB_FireTail_FxTargetAndPeriodStamp

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578b30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-C) |
| **Counterpart** | `reviews/A_aa_00578b30_Skill_HB_FireTail_FxTargetAndPeriodStamp.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role). No `disassemble_bytes`. Own VA `0x00578b30` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is only a log/assert about frequency | Full FX + target + Stop/Stamp body | **Falsified** — multi-stage fire tail |
| 2 | Period floor is 3000/5000 combat default | Bytes `cmp eax,0x12C` + store 300 | **Falsified** — floor is **300** |
| 3 | −1000 lives only in `nPeriodMs` | One-shot compares **`[esi+0x0C]`** to −1000 and **`[esi+0x08]`** to 0 | **Falsified** simple model — dual-field gate |
| 4 | Host for FxCache is `this` | Live `mov ecx,[DAT_00b041fc]` before call | **Falsified** — global host |
| 5 | CVOGHBBase* array overlay is real layout | sizeof base 0x28; offsets to `+0x6ac` | **Confirmed mis-type** — use absolute offs |
| 6 | Always clamps frequency | Gate `sentinel!=1` skips clamp when sentinel==1 | **Falsified always-clamp** |
| 7 | Three-rep diverges | live ≡ raw ≡ period/FX bytes | **Falsified** |
| 8 | Clean invents proven PDB name | structural only | **Open English** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this + void + Stamp exits | **High** | broken HB reschedule |
| Period −1000/0 Stop; floor 300 | **High** | spam / stuck one-shots |
| FX event 0x16 + key +0x620 | **High** | wrong VFX bind |
| Nested attach arg packing | **Medium** | FX attach miss |
| Product name | **Probable structural** | doc only |
| Runtime | **Open** | shipping drift |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  empty hook; ResolveObjectTarget; owner FX 0x16; target applies;
  if sentinel==-1000 && period==0: Stop; Stamp; ret
  if sentinel!=1 && period<300: log; period=300
  Stamp; ret

bytes:
  8B F1 / call [00af31e4]
  6A 01 6A 16 50 E8 …005408f0
  8B 46 0C  3D 18 FC FF FF
  83 7E 08 00
  83 F8 01 / 3D 2C 01 00 00 / C7 46 08 2C 01 00 00
  5F 5E 5D 5B 59 C3
```

**No conflict** on owned CF. Auto string alias rejected as primary name.

---

## 4. Surviving contract for AutoCore

```csharp
// Skill_HB_FireTail_FxTargetAndPeriodStamp @ 0x00578b30
// after skill fire side-effects:
if (hb.sentinel == -1000 && hb.periodMs == 0) {
  Stop(hb); StampLastFire(hb); return;
}
if (hb.sentinel != 1 && (uint)hb.periodMs < 300) {
  Log("Skill %d has invalid frequency %d", skillId, hb.periodMs);
  hb.periodMs = 300;
}
StampLastFire(hb);
```

FX/target arms must still run **before** period finalize.

---

## 5. Residual risks

1. ResolveObjectTarget packing / ECX residue not fully byte-walked for every push order edge.
2. Else-arm vtbl+0xf8 decomp shows `()` — may still pass residual registers; clean documents both arms with args from if-arm pattern (**Probable**).
3. No runtime hit confirmation in this dual.
4. Callee duals (`FUN_00518ca0`, `FUN_0051f880`) assumed only as black boxes.

**Verdict:** **accept-with-gaps**
