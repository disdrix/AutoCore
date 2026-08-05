# Review B (skeptical / adversarial): `aa_007a4400` Perf_QpcBeginNamed_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a4400` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-D) |
| **Counterpart** | `reviews/A_aa_007a4400_Perf_QpcBeginNamed_Inferred.md` |
| **Scratch** | `tmp/a_007a4400.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the debug logger (`FUN_007a4480` / VOG_DEBUG_STOP) | **Falsified** — body is QPF/QPC + strcpy; logger is `0x007a4480` with `vog_LogMessage` |
| 2 | cdecl / no this | **Falsified** — ECX saved as ESI; `ret 4`; param_1 storage register ECX |
| 3 | Always measures frequency | **Falsified** — QPF only when `DAT_00b00a74 != 0`; flag cleared after first success |
| 4 | Label overwrites QPC storage | **Falsified** — copy targets `this+8`; QPC writes `this` (8-byte LARGE_INTEGER) |
| 5 | Returns void / frequency | **Falsified** — `MOV EAX,ESI` before ret |
| 6 | Product name is retail string | **Overstated** — no symbol string for the helper; name inferred from role |
| 7 | `DAT_00afa254` already valid before first call | **Image note** — static image shows `1.0f` before first run; first live begin still recomputes via QPF when flag is 1 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF once-init + strcpy + QPC | **High** | Wrong port of stage timing |
| thiscall ret 4 EAX=this | **High** | ABI break / stack imbalance |
| Slot +0/+8 layout | **High** | Corrupt label or counter |
| Win32-only callees | **High** | Missed side effects |
| Product English | **Medium** | Naming only |
| Runtime bit-exact | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
SUB ESP,8
if [DAT_00b00a74]: clear; QPF; fstp DAT_00afa254
strcpy(this+8, label)   // edx=this+8 - label; mov [edx+eax],cl loop
push this; QPC
EAX=this; ADD ESP,8; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Callers pass stage label C-strings (`@@...`).

---

## 4. Surviving contract for AutoCore

```
// Stage marker begin (not a log line):
slot = Perf_QpcBeginNamed_Inferred(slot, "@@stage name");
// slot+0 = QPC start; slot+8 = label; DAT_00afa254 = 1/freq after first call
// Do not confuse with FUN_007a4480 (NDError logger)
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/slot layout sealed; logger confusion and product English residual only → **accept**.
