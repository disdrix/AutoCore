# Review A (reconstruction fidelity): `aa_004b0f80` ObjectMotion_AdvanceStage_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b0f80` |
| **VA** | `0x004b0f80`–`0x004b10fe` (383 B / `0x17F`) |
| **Canonical name** | `ObjectMotion_AdvanceStage_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004b0f80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W27-E) |
| **Counterpart** | `reviews/B_aa_004b0f80_ObjectMotion_AdvanceStage_Inferred.md` |
| **System** | client object motion / reaction stage chain |
| **Verdict** | **accept-with-gaps** — CF + ABI + stage-advance contract sealed; product name + nested free helpers open |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Advance a motion/reaction **stage node** and reload primary duration:

- Side effects on *outgoing* stage (audio **or** FX + multi-hit flush).
- `slot[1] = *(stage+0x2f4)`.
- mode-1 + next==`host+0x14` + `host+0x7fb==0` → **AL=0**.
- Else load `*next` → `slot[0x5c]`, optional RNG jitter, mirror `slot[0x5d]`, **AL=1**.

Evidence: sole caller `ObjectMotion_SlotTick_Inferred` uses mode 0 after radius rebind and mode 1 on duration expiry (W26-H dual).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x004b0f80` |
| Bounds | `get_function_by_address` → `004b0f80`–`004b10fe` |
| Entry/exit bytes | `read_memory` @ `0x004b0f80`, `0x004b10f0` |
| Constant | `DAT_00aaa638` = `80 00 80 37` ≈ 1/65535 |
| Callers | `FUN_004b4620` only (2 sites) |
| Peer duals | SlotTick (W26-H), mission-complete SFX (W18-R), multi-hit flush |
| Raw / annotated / clean | W27-E updated |

**Not performed:** Launcher, runtime golden, bit-exact, dual of `FUN_004e9530` / `FUN_004b7e50`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `004b0f80`–`004b10fe` (383 B) | **Confirmed** | `get_function_by_address` |
| ECX this + **`ret 4`** (`C2 04 00`) | **Confirmed** | epilogue `read_memory` |
| Return AL 0 / 1 | **Confirmed** | early mask / `B0 01` |
| Sole SlotTick caller | **Confirmed** | xrefs |
| Stage advance via `+0x2f4` | **Confirmed** | decompile |
| Duration reload + optional RNG | **Confirmed** | |
| Audio path only when `host+4==0` | **Confirmed** | |
| Product method name | **Inferred** | `_Inferred` |
| Nested free helper English | **Open** | |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| host+4 == 0 → name scan → audio key + queue SFX | Yes |
| host+4 != 0 → one-shot FUN_004b7e50 + flag +0x2ee | Yes |
| host+4 != 0 → optional FUN_004b6980 on +0x2ef bit0 | Yes |
| Advance slot[1] via +0x2f4 | Yes |
| mode!=0 + sentinel host+0x14 + !0x7fb → AL=0 | Yes |
| Load *next → slot[0x5c] | Yes |
| +0x1e4 bit2 RNG jitter with DAT_00aaa638 | Yes |
| slot[0x5d]=slot[0x5c]; AL=1; ret 4 | Yes |

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| `FUN_004b4620` | `0x004b4854` | mode 0 after radius rebind |
| `FUN_004b4620` | `0x004b488d` | mode 1 on duration ≤0; fail → SlotTick returns 0 |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Product class of stage node schema.
3. Dual of `FUN_004e9530` / `FUN_004b7e50`.
4. Runtime golden for RNG jitter path.

**Verdict:** **accept-with-gaps** — sealed stage-advance CF, ABI, and SlotTick contract; product name open.
