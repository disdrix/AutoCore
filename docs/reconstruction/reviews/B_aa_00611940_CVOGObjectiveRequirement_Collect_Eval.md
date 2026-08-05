# Review B (skeptical / adversarial): `CVOGObjectiveRequirement_Collect_Eval` @ `0x00611940`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen; CountItems bridge) |
| **Counterpart** | `reviews/A_aa_00611940_CVOGObjectiveRequirement_Collect_Eval.md` |
| **Verdict** | **accept** on formula + bridge + ABI; runtime open |
| **Scratch** | `reviews/a_00611940.md` |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Collect_Eval is the only Collect progress source | **Falsified as exclusive** — also server absolute `0x2071` ObjectiveState; this body is inventory-derived Eval only. Dual-path **sealed**. |
| 2 | Progress comes from objective slot floats like UseItem/Kill | **Falsified** — no load of stack1/state; cargo recount only. |
| 3 | Decompiler single stack formal is the real ABI | **Falsified** — three `RET 8` exits; shared two-dword Eval family. |
| 4 | Character is unused (like Kill param_2) | **Falsified** — stack0 is cargo host; Kill/UseItem use stack1 state instead. |
| 5 | Second Count call is a decompiler CSE glitch | **Falsified** — two image CALL sites; sibling SlotAction double-counts the same way. |
| 6 | Complete requires ratio **strictly &gt;** 1.0 | **Falsified** — `COMISS` + `JBE` when 1.0 ≤ ratio; equality completes. |
| 7 | Broken cargo of target CBID counts toward progress | **Falsified** — both sites `includeBroken=0`; Count bit19=Broken sealed. |
| 8 | Locker / bank inventory advances Collect_Eval | **Falsified** — hardcoded `char+0x250→+0x2b0` cargo only. |
| 9 | `0x00611290` is Collect type-4 Count consumer | **Rejected** — Deliver type 3 / event type 4 (UF-014 / chain). Not this unit. |
| 10 | float10 means 80-bit domain math | **Falsified** — SSE f32 ratio; x87 `FLD` is return convention only. |
| 11 | NumToCollect==0 is failure / zero | **Falsified** — returns **1.0** (vacuously complete). |
| 12 | Count thiscall ECX is the requirement object | **Falsified** — ECX loaded from cargo grid before CALL; decomp omits explicit this. |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Formula min(1, count/Num) + offsets | **High / Confirmed** (body) | Wrong journal complete % |
| CountItems bridge framing | **High / Confirmed** | Broken items / wrong grid inflate progress |
| RET 8 / stack0=character | **High / Confirmed** | Wrong thiscall port / crash |
| Inventory vs 0x2071 dual authority | **High** (static roles) | Treat client Eval as server truth |
| Double Count behavioral equivalence | **High** if cargo stable | Rare race if grid mutates mid-Eval |
| Runtime observation | Open | Policy |

---

## 3. Surviving contract for AutoCore

```
Collect_Eval(req, character, objState /*unread*/):
  need = *(i32*)(req + 0x14)          // NumToCollect
  if need == 0: return 1.0f
  vehicle = *(ptr*)(character + 0x250)
  if !vehicle: return 0.0f
  cargo = *(ptr*)(vehicle + 0x2b0)    // InventoryGrid*
  if !cargo: return 0.0f
  cbid = *(i32*)(req + 0x10)
  count = CountItemsByCbid(cargo, cbid, includeBroken=0)
  if count >= need: return 1.0f        // image: float ratio ≥ 1.0
  count = CountItemsByCbid(cargo, cbid, includeBroken=0)  // real 2nd walk
  return (float)count / (float)need
```

Port rules:

- Do **not** implement Collect progress as slot-float ≥ N (that is UseItem/Kill).
- Do **not** count Broken stacks unless product policy changes includeBroken.
- Do **not** treat client Eval as exclusive authority — server `0x2071` / turn-in still own absolute progress.
- Do **not** conflate Deliver Count callers (`0x00611290` / `0x00610f20`) with Collect_Eval.

---

## 4. Residual disposition

| Prior gap | Disposition |
|-----------|-------------|
| ABI / RET 8 | **Sealed High** (bytes re-read) |
| Double Count | **Sealed High** (CALL @ `0x00611972`, `0x006119a3`) |
| float10 | **Sealed** as x87 return of f32 ratio |
| Progress authority vs 0x2071 | **Sealed** dual-path model |
| Count ECX + includeBroken=0 | **Sealed High** |
| COMISS equality completes | **Sealed High** |
| Runtime / differential | Still open |

---

## 5. Open questions (after residual)

1. Runtime Grab/Drop → journal Eval timing (still open).
2. Bit-exact / image diff (policy).
3. Original PDB name (open).
4. Whether any non-virtual CODE path ever calls Eval body directly (none found; virtual only).

**Verdict:** **accept** on formula + CountItems bridge + ABI. Runtime/diff remain open policy.
