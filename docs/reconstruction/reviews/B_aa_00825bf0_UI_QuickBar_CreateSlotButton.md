# Review B (skeptical / adversarial): `aa_00825bf0` UI_QuickBar_CreateSlotButton

| Field | Value |
|---|---|
| **Stable ID** | `aa_00825bf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00825bf0_UI_QuickBar_CreateSlotButton.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Sends QuickBarUpdate `0x2062` | Body has no packet / no `Client_Send*` | **Falsified** — pure UI ctor |
| 2 | Activates / casts a skill | No cast path; no payload write of skill id | **Falsified** |
| 3 | `g_flMultiKillCountBlend` means multi-kill UI | Shared float pool @ `0x00a0f730` = **0.1f**; used as default at `+0x514` | **Falsified product meaning** — value sealed, name is pool reuse |
| 4 | Creates all 10 page columns | Only **2** xrefs, both in `FUN_008a16b0` (indices 0/1 hazard-style buttons) | **Do not overclaim** — class may be reused elsewhere via other factories, but **this VA** is only called twice |
| 5 | Object larger than `0x554` | Both sites `operator_new(0x554)` | **Falsified** for known callers |
| 6 | `+0x550/+0x554` empty COID pair init | Ctor zeros through `+0x550` only; size ends at `0x554` (last byte `0x553`) | **Do not seal** full empty dual as written by **this** unit — only `[0x150..0x154]` zero |
| 7 | Name invents gameplay server logic | Name is UI + XML string only | **Survives** as client UI factory |

---

## 2. Cross-check: live decompile ≡ raw body

Live `decompile_function(0x00825bf0)` (2026-07-29) matches raw capture:

- `FUN_00792d20(param_1)`
- `param_1[0x142]=DAT_00aaabc4`; `[0x143]=0`; `[0x144]=0`
- `*param_1=&PTR_FUN_00a75004`
- bytes `+0x4fd/+0x4fe`, dwords `[0x150..0x154]`, flags, `[0x140]=-1`, `[0x145]=0.1f pool`
- `NDUIWindow_ReloadInterface("i_d_qb_2d_btn_quickbar.xml")`
- `return param_1`

No material drift. Clean scaffold must not invent sends or activate logic.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor role + XML skin | **High** | Wrong system ownership |
| Size `0x554` | **High** | Allocator mismatch |
| `+0x500` sentinel / caller stamp | **High** | Slot index bugs in UI only |
| `+0x508` = 0.88 DOWN_SIZE default | **High** | Layout scale wrong on first paint |
| Multi-kill float name | **High value / Low name** | Doc confusion only |
| “Creates entire quickbar” | **Reject** | Scope creep |
| Server impact | **None** | N/A |

---

## 4. Surviving contract for AutoCore

```
// Client-only UI widget factory — no wire protocol.
// Allocate 0x554, call UI_QuickBar_CreateSlotButton(this):
//   base NDUI ctor → derived vtbl PTR_FUN_00a75004
//   +0x508 = 0.88f; +0x514 = 0.1f; +0x500 = -1; flags/child slots cleared
//   load "i_d_qb_2d_btn_quickbar.xml"
// return this
//
// Known host wiring (FUN_008a16b0 only):
//   host+0x66c / +0x670 each get one instance; +0x500 stamped 0 then 1;
//   child at +0x548 used for numeric label "1"/"2".
//
// QuickBarUpdate 0x2062 / cast / page-select live in other units.
```

---

## 5. Open questions (residual)

1. RTTI / product class name for `PTR_FUN_00a75004`.
2. Whether other code paths construct the same class without calling this VA (placement-new / different ctor).
3. Full meaning of `+0x50c/+0x510/+0x514` after init.
4. Runtime: confirm XML children bind to `+0x548` label and any icon slot at `+0x54x`.

**Verdict:** Adversarial checks clear send/cast overclaim; ctor contract holds. **accept-with-gaps.**
