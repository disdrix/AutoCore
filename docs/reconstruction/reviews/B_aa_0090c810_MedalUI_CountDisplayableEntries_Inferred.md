# Review B (skeptical / adversarial): `aa_0090c810` MedalUI_CountDisplayableEntries_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090c810` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-103) |
| **Counterpart** | `reviews/A_aa_0090c810_MedalUI_CountDisplayableEntries_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a debug-stop / VOG halt helper | **Falsified** — `"VOG_DEBUG_STOP"` only on hash-lock warn; returns count; no infinite wait |
| 2 | This allocates / creates medal UI buttons | **Falsified** — no `operator_new`, no XML load, no slot stores; alloc is residual `FUN_0090c9a0` |
| 3 | This awards / grants medals | **Falsified** — lookup-only via `MedalDef_LookupById`; no award path |
| 4 | ECX-thiscall | **Falsified** — body uses **EBX**; callers `MOV EBX,[DAT_00d1b6d8]`; no `MOV ECX,...` for self |
| 5 | `unaff_EBX` is phantom garbage | **Falsified** — first insn `TEST EBX`; storage `register:EBX` in analyze; all callers seed EBX |
| 6 | Stack args / `RET 4` | **Falsified** — bare `C3`; no formals |
| 7 | Vector phase also filters via lookup | **Falsified** — vector is raw `(end-begin)>>2`; only hash phase calls `0051a0e0` |
| 8 | Hash phase counts every chain node | **Falsified** — only when `MedalDef_LookupById` returns non-null |
| 9 | Lock violation aborts / throws | **Falsified** — warn logs only; force lock=1 / continue |
| 10 | Same as prep clear `0090c700` | **Falsified** — prep clears host slots; this counts character medals |
| 11 | Same as parent rebuild `0090cbc0` | **Falsified** — parent is multi-phase rebuild; this is leaf count |
| 12 | Sole caller | **Falsified** — 3 UNCONDITIONAL_CALL sites (cbc0, c920, gap twin) |
| 13 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI EBX-character / bare RET / EAX count | **High** | Wrong call convention → crash / wrong count |
| Vector `+0x574/+0x578` size | **High** | Wrong pagination seed |
| Hash `+0x540` walk + lock `+0x1d` | **High** | Infinite walk / missed entries |
| Id at payload `+0x100` + LookupById | **High** | Wrong def class |
| Medal UI query role | **High** | Mis-system |
| Product character class English | **Low** | Naming only |
| Vector pre-validated assumption | **Open** | Overcount vs display |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

| Check | Result |
|---|---|
| Live decompile 2026-08-05 ≡ raw 2026-07-23 CF | **Match** |
| Body size 186 B to RET | **Match** (`0x0090c810`–`0x0090c8c9`) |
| Hex vs disasm mnemonics | **Match** |
| Callers seed EBX from `DAT_00d1b6d8` | **Match** (all 3 sites) |
| Parent uses EAX for page math after CALL | **Match** (`MOV ECX,EAX` @ `0x0090cbff`) |
| Gate peers compare EAX to `0x18` | **Match** (`CMP EAX,0x18` @ `0x0090c94f` / `0x0090c904`) |
| Callee `0051a0e0` dualed MedalDef_LookupById | **Match** prior dual |
| Sibling XML `i_d_a_2d_btn_achievement.xml` | **Medal/achievement UI** context sealed without inventing product class name |

---

## 4. Surviving contract for AutoCore

```
// After prep-clear of medal button slots:
//   EBX = *DAT_00d1b6d8;  // character / medal-state
//   int n = MedalUI_CountDisplayableEntries_Inferred();
// Use n for pagination (retail threshold 24 / 25) and visibility gates.
// Do NOT treat as medal grant, button alloc, ECX-thiscall, or debug halt.
// Note: vector contribution is raw size; hash contribution is lookup-filtered.
```

---

## 5. Verdict

Adversarial attacks on VOG-halt / alloc / grant / ECX / phantom-EBX / sole-caller / vector-filter claims **fail**. Residual product English + vector-vs-display asymmetry → **accept-with-gaps**. Terminal **false**.
